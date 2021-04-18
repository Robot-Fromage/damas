/*
*   Damas
*__________________
* @file         cpuinfo_p.hpp
* @author       Clement Berthaud
* @brief        This file provides the declaration for the DCPUInfo_Private tools.
* @copyright    Copyright 2021 Clement Berthaud.
* @license      Please refer to LICENSE.md
*/
#pragma once
#include "core/core.hpp"

DAMAS_NAMESPACE_BEGIN
/// @class      DCPUInfo_Private
/// @brief      The DCPUInfo_Private provides the internal mechanisms for
///             cpu_info.
/// @details    DCPUInfo_Private uses a variation of the pimpl idiom in
///             cpu_info to abstract the platform specifics.
struct DCPUInfo_Private
{
    DCPUInfo_Private();
    uint64 features_bitfield;
    uint32 max_workers;
    uint32 l1_cache_size;
    uint32 l1_cache_line_size;
};

DAMAS_NAMESPACE_END

