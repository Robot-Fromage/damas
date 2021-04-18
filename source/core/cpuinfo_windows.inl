/*
*   kaze
*__________________
* @file         cpu_info_windows.inl
* @author       Clement Berthaud
* @brief        This file provides the internals for the cpu_metrics tools.
* @copyright    Copyright 2021 Clement Berthaud.
* @license      Please refer to LICENSE.md
*/
#pragma once
#include "core/core.hpp"
#include "core/cpuinfo_helpers.hpp"

#include <Windows.h>
#include <intrin.h>
#include <stdint.h>
#include <string>
#include <stdlib.h>
#include <thread>

DAMAS_NAMESPACE_BEGIN
namespace detail {
void
cpuid(int32_t out[4], int32_t x)
{
    __cpuidex(out, x, 0);
}

__int64
xgetbv( unsigned int x )
{
    return  _xgetbv(x);
}

typedef BOOL (WINAPI *LPFN_ISWOW64PROCESS) (HANDLE, PBOOL);
BOOL IsWow64()
{
    BOOL bIsWow64 = FALSE;

    LPFN_ISWOW64PROCESS fnIsWow64Process = (LPFN_ISWOW64PROCESS) GetProcAddress(
        GetModuleHandle(TEXT("kernel32")), "IsWow64Process");

    if( NULL != fnIsWow64Process )
    {
        if( !fnIsWow64Process( GetCurrentProcess(), &bIsWow64 ) )
        {
            printf( "Error Detecting Operating System.\n" );
            printf( "Defaulting to 32-bit OS.\n\n" );
            bIsWow64 = FALSE;
        }
    }
    return  bIsWow64;
}

bool
detect_OS_x64() {
#ifdef _M_X64
    return  true;
#else
    return  IsWow64() != 0;
#endif
}

bool
detect_OS_AVX() {
    //  Copied from: http://stackoverflow.com/a/22521619/922184
    bool avxSupported = false;

    int cpuInfo[4];
    cpuid(cpuInfo, 1);

    bool osUsesXSAVE_XRSTORE = (cpuInfo[2] & (1 << 27)) != 0;
    bool cpuAVXSuport = (cpuInfo[2] & (1 << 28)) != 0;

    if (osUsesXSAVE_XRSTORE && cpuAVXSuport)
    {
        uint64_t xcrFeatureMask = xgetbv( _XCR_XFEATURE_ENABLED_MASK );
        avxSupported = ( xcrFeatureMask & 0x6 ) == 0x6;
    }

    return  avxSupported;
}

bool
detect_OS_AVX512() {
    if (!detect_OS_AVX())
        return  false;

    uint64_t xcrFeatureMask = xgetbv( _XCR_XFEATURE_ENABLED_MASK );
    return  ( xcrFeatureMask & 0xe6 ) == 0xe6;
}

std::string
get_vendor_string() {
    int32_t CPUInfo[4];
    char name[13];

    cpuid(CPUInfo, 0);
    memcpy(name + 0, &CPUInfo[1], 4);
    memcpy(name + 4, &CPUInfo[3], 4);
    memcpy(name + 8, &CPUInfo[2], 4);
    name[12] = '\0';

    return  name;
}

void cache_info( uint8 iLevel, uint32 *oCacheSize, uint32* oLineSize ) {
    DWORD buffer_size = 0;
    DWORD i = 0;
    SYSTEM_LOGICAL_PROCESSOR_INFORMATION * buffer = 0;

    GetLogicalProcessorInformation(0, &buffer_size);
    buffer = (SYSTEM_LOGICAL_PROCESSOR_INFORMATION *)malloc(buffer_size);
    GetLogicalProcessorInformation(&buffer[0], &buffer_size);

    for (i = 0; i != buffer_size / sizeof(SYSTEM_LOGICAL_PROCESSOR_INFORMATION); ++i) {
        if( buffer[i].Relationship == RelationCache && buffer[i].Cache.Level == iLevel ) {
            *oLineSize  = static_cast< uint32 >( buffer[i].Cache.LineSize );
            *oCacheSize = static_cast< uint32 >( buffer[i].Cache.Size );
            break;
        }
    }

    free( buffer );
}

uint32 num_workers() {
    return  std::thread::hardware_concurrency();
}

} // namespace detail

DAMAS_NAMESPACE_END

