/*
*   Damas
*__________________
* @file         cpuinfo.cpp
* @author       Clement Berthaud
* @brief        This file contains the definition of the cpuinfo tools.
* @copyright    Copyright 2021 Clément Berthaud
* @license      Please refer to LICENSE.md
*/
#include "core/cpuinfo.hpp"
#include "core/cpuinfo_helpers.hpp"
#include "core/cpuinfo_p.hpp"

DAMAS_NAMESPACE_BEGIN
namespace detail {
static const DCPUInfo_Private sgCPUInfo;
} // namespace detail

//static
bool
DCPUInfo::IsHardwareAmd()
{
    return  DAMAS_R_HW_AMD( detail::sgCPUInfo.features_bitfield );
}

//static
bool
DCPUInfo::IsHardwareIntel()
{
    return  DAMAS_R_HW_INTEL( detail::sgCPUInfo.features_bitfield );
}

//static
bool
DCPUInfo::IsOSx64() {
    return  DAMAS_R_OS_X64( detail::sgCPUInfo.features_bitfield );
}

//static
bool
DCPUInfo::HasOsAvx()
{
    return  DAMAS_R_OS_AVX( detail::sgCPUInfo.features_bitfield );
}

//static
bool
DCPUInfo::HasOsAvx512()
{
    return  DAMAS_R_OS_AVX512( detail::sgCPUInfo.features_bitfield );
}

//static
bool DCPUInfo::HasHardwarex64()
{
    return  DAMAS_R_HW_X64( detail::sgCPUInfo.features_bitfield );
}

//static
bool
DCPUInfo::HasHardwareMMX()
{
    return  DAMAS_R_HW_MMX( detail::sgCPUInfo.features_bitfield );
}

//static
bool
DCPUInfo::HasHardwareABM()
{
    return  DAMAS_R_HW_ABM( detail::sgCPUInfo.features_bitfield );
}

//static
bool
DCPUInfo::HasHardwareRDRAND()
{
    return  DAMAS_R_HW_RDRAND( detail::sgCPUInfo.features_bitfield );
}

//static
bool
DCPUInfo::HasHardwareBMI1()
{
    return  DAMAS_R_HW_BMI1( detail::sgCPUInfo.features_bitfield );
}

//static
bool
DCPUInfo::HasHardwareBMI2()
{
    return  DAMAS_R_HW_BMI2( detail::sgCPUInfo.features_bitfield );
}

//static
bool
DCPUInfo::HasHardwareADX()
{
    return  DAMAS_R_HW_ADX( detail::sgCPUInfo.features_bitfield );
}

//static
bool
DCPUInfo::HasHardwarePREFETCHWT1()
{
    return  DAMAS_R_HW_PREFETCHWT1( detail::sgCPUInfo.features_bitfield );
}

//static
bool
DCPUInfo::HasHardwareMPX()
{
    return  DAMAS_R_HW_MPX( detail::sgCPUInfo.features_bitfield );
}

//static
bool
DCPUInfo::HasHardwareSSE()
{
    return  DAMAS_R_HW_SSE( detail::sgCPUInfo.features_bitfield );
}

//static
bool
DCPUInfo::HasHardwareSSE2()
{
    return  DAMAS_R_HW_SSE2( detail::sgCPUInfo.features_bitfield );
}

//static
bool
DCPUInfo::HasHardwareSSE3()
{
    return  DAMAS_R_HW_SSE3( detail::sgCPUInfo.features_bitfield );
}

//static
bool
DCPUInfo::HasHardwareSSSE3()
{
    return  DAMAS_R_HW_SSSE3( detail::sgCPUInfo.features_bitfield );
}

//static
bool
DCPUInfo::HasHardwareSSE41()
{
    return  DAMAS_R_HW_SSE41( detail::sgCPUInfo.features_bitfield );
}

//static
bool
DCPUInfo::HasHardwareSSE42()
{
    return  DAMAS_R_HW_SSE42( detail::sgCPUInfo.features_bitfield );
}

//static
bool
DCPUInfo::HasHardwareSSE4a()
{
    return  DAMAS_R_HW_SSE4A( detail::sgCPUInfo.features_bitfield );
}

//static
bool
DCPUInfo::HasHardwareAES()
{
    return  DAMAS_R_HW_AES( detail::sgCPUInfo.features_bitfield );
}

//static
bool
DCPUInfo::HasHardwareSHA()
{
    return  DAMAS_R_HW_SHA( detail::sgCPUInfo.features_bitfield );
}

//static
bool
DCPUInfo::HasHardwareAVX()
{
    return  DAMAS_R_HW_AVX( detail::sgCPUInfo.features_bitfield );
}

//static
bool
DCPUInfo::HasHardwareXOP()
{
    return  DAMAS_R_HW_XOP( detail::sgCPUInfo.features_bitfield );
}

//static
bool
DCPUInfo::HasHardwareFMA3()
{
    return  DAMAS_R_HW_FMA3( detail::sgCPUInfo.features_bitfield );
}

//static
bool
DCPUInfo::HasHardwareFMA4()
{
    return  DAMAS_R_HW_FMA4( detail::sgCPUInfo.features_bitfield );
}

//static
bool
DCPUInfo::HasHardwareAVX2()
{
    return  DAMAS_R_HW_AVX2( detail::sgCPUInfo.features_bitfield );
}

//static
bool
DCPUInfo::HasHardwareAVX512_F()
{
    return  DAMAS_R_HW_AVX512_F( detail::sgCPUInfo.features_bitfield );
}

//static
bool
DCPUInfo::HasHardwareAVX512_PF()
{
    return  DAMAS_R_HW_AVX512_PF( detail::sgCPUInfo.features_bitfield );
}

//static
bool
DCPUInfo::HasHardwareAVX512_ER()
{
    return  DAMAS_R_HW_AVX512_ER( detail::sgCPUInfo.features_bitfield );
}

//static
bool
DCPUInfo::HasHardwareAVX512_CD()
{
    return  DAMAS_R_HW_AVX512_CD( detail::sgCPUInfo.features_bitfield );
}

//static
bool
DCPUInfo::HasHardwareAVX512_VL()
{
    return  DAMAS_R_HW_AVX512_VL( detail::sgCPUInfo.features_bitfield );
}

//static
bool
DCPUInfo::HasHardwareAVX512_BW()
{
    return  DAMAS_R_HW_AVX512_BW( detail::sgCPUInfo.features_bitfield );
}

//static
bool
DCPUInfo::HasHardwareAVX512_DQ()
{
    return  DAMAS_R_HW_AVX512_DQ( detail::sgCPUInfo.features_bitfield );
}

//static
bool
DCPUInfo::HasHardwareAVX512_IFMA()
{
    return  DAMAS_R_HW_AVX512_IFMA( detail::sgCPUInfo.features_bitfield );
}

//static
bool
DCPUInfo::HasHardwareAVX512_VBMI()
{
    return  DAMAS_R_HW_AVX512_VBMI( detail::sgCPUInfo.features_bitfield );
}

//static
uint32
DCPUInfo::MaxWorkers()
{
    return  detail::sgCPUInfo.max_workers;
}

//static
uint32
DCPUInfo::L1CacheSize()
{
    return  detail::sgCPUInfo.l1_cache_size;
}

//static
uint32
DCPUInfo::L1CacheLineSize()
{
    return  detail::sgCPUInfo.l1_cache_line_size;
}

DAMAS_NAMESPACE_END

