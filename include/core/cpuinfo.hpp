/*
*   Damas
*__________________
* @file         cpuinfo.hpp
* @author       Clement Berthaud
* @brief        This file contains the declaration of the cpuinfo tools.
* @copyright    Copyright 2021 Clément Berthaud
* @license      Please refer to LICENSE.md
*/
#pragma once
#include "core/core.hpp"

DAMAS_NAMESPACE_BEGIN
/// @class      DCPUInfo
/// @brief      The DCPUInfo class provides a mean of fetching informations
///             about the CPU in a single-CPU, multicore environment.
/// @details    DCPUInfo provides functions to fetch wether support for 64
///             bits features or SIMD extensions are supported on the CPU that
///             runs the compiled code, at runtime. It has no relation with the
///             computer that compiled the code in the first place, it is a
///             cross-platform tool used to detecting wether the consumer of
///             the library code is able to rely on the implementations
///             compiled with these SIMD features in mind. Additionnaly, it
///             provides extra information about the CPU vendor, and some
///             information about the OS, in relation to its support for the
///             features sets or for 64bit features, although 64bit is always
///             assumed to be true.
///             DCPUInfo also provides some insight about the hardware such
///             as the number of available cores, or the size of cache lines.
class DAMAS_API DCPUInfo
{
private:
    ~DCPUInfo() = delete;
    DCPUInfo() = delete;
    DCPUInfo( const DCPUInfo& ) = delete;
    DCPUInfo( DCPUInfo&& ) = delete;

public:
    static bool IsHardwareAmd();
    static bool IsHardwareIntel();
    static bool IsOSx64();
    static bool HasOsAvx();
    static bool HasOsAvx512();
    static bool HasHardwarex64();
    static bool HasHardwareMMX();
    static bool HasHardwareABM();
    static bool HasHardwareRDRAND();
    static bool HasHardwareBMI1();
    static bool HasHardwareBMI2();
    static bool HasHardwareADX();
    static bool HasHardwarePREFETCHWT1();
    static bool HasHardwareMPX();
    static bool HasHardwareSSE();
    static bool HasHardwareSSE2();
    static bool HasHardwareSSE3();
    static bool HasHardwareSSSE3();
    static bool HasHardwareSSE41();
    static bool HasHardwareSSE42();
    static bool HasHardwareSSE4a();
    static bool HasHardwareAES();
    static bool HasHardwareSHA();
    static bool HasHardwareAVX();
    static bool HasHardwareXOP();
    static bool HasHardwareFMA3();
    static bool HasHardwareFMA4();
    static bool HasHardwareAVX2();
    static bool HasHardwareAVX512_F();
    static bool HasHardwareAVX512_PF();
    static bool HasHardwareAVX512_ER();
    static bool HasHardwareAVX512_CD();
    static bool HasHardwareAVX512_VL();
    static bool HasHardwareAVX512_BW();
    static bool HasHardwareAVX512_DQ();
    static bool HasHardwareAVX512_IFMA();
    static bool HasHardwareAVX512_VBMI();
    static uint32 MaxWorkers();
    static uint32 L1CacheSize();
    static uint32 L1CacheLineSize();
};

DAMAS_NAMESPACE_END

