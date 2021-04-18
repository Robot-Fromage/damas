/*
*   kaze
*__________________
* @file         cpu_info_generic.inl
* @author       Clement Berthaud
* @brief        This file provides the internals for the cpu_metrics tools.
* @copyright    Copyright 2021 Clement Berthaud.
* @license      Please refer to LICENSE.md
*/
#pragma once
#include "core/core.hpp"
#include "core/cpuinfo_helpers.hpp"

DAMAS_NAMESPACE_BEGIN
namespace detail {
void
cpuid( int32_t out[4], int32_t x )
{
    memset( out, 0, 4 * sizeof( int ) );
}

bool
detect_OS_x64() {
    return  true;
}

bool
detect_OS_AVX() {
    return  false;
}

bool
detect_OS_AVX512() {
    return  false;
}

std::string
get_vendor_string() {
    return  "Unknown";
}

void cache_info( uint8 iLevel, uint32 *oCacheSize, uint32* oLineSize ) {
    *oCacheSize = 0;
    *oLineSize = 0;
}

uint32 num_workers() {
    return  1;
}

} // namespace detail

DAMAS_NAMESPACE_END

