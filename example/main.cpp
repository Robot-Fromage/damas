/*
*   Damasio
*__________________
* @file         main.cpp
* @author       Clement Berthaud
* @brief        This file provides an interactive io example to work with Damas.
* @copyright    Copyright 2021 Clément Berthaud
* @license      Please refer to LICENSE.md
*/
#pragma once
#include <damas>
#include <iostream>

int
main( int argc, char *argv[] )
{
    std::cout << dms::DLibInfo::LibraryInformationString() << std::endl;
    std::cout << "IsHardwareAmd:            " << dms::DCPUInfo::IsHardwareAmd()             << std::endl;
    std::cout << "IsHardwareIntel:          " << dms::DCPUInfo::IsHardwareIntel()           << std::endl;
    std::cout << "IsOSx64:                  " << dms::DCPUInfo::IsOSx64()                   << std::endl;
    std::cout << "HasOsAvx                  " << dms::DCPUInfo::HasOsAvx()                  << std::endl;
    std::cout << "HasOsAvx512:              " << dms::DCPUInfo::HasOsAvx512()               << std::endl;
    std::cout << "HasHardwarex64:           " << dms::DCPUInfo::HasHardwarex64()            << std::endl;
    std::cout << "HasHardwareMMX:           " << dms::DCPUInfo::HasHardwareMMX()            << std::endl;
    std::cout << "HasHardwareABM:           " << dms::DCPUInfo::HasHardwareABM()            << std::endl;
    std::cout << "HasHardwareRDRAND:        " << dms::DCPUInfo::HasHardwareRDRAND()         << std::endl;
    std::cout << "HasHardwareBMI1:          " << dms::DCPUInfo::HasHardwareBMI1()           << std::endl;
    std::cout << "HasHardwareBMI2:          " << dms::DCPUInfo::HasHardwareBMI2()           << std::endl;
    std::cout << "HasHardwareADX:           " << dms::DCPUInfo::HasHardwareADX()            << std::endl;
    std::cout << "HasHardwarePREFETCHWT1:   " << dms::DCPUInfo::HasHardwarePREFETCHWT1()    << std::endl;
    std::cout << "HasHardwareMPX:           " << dms::DCPUInfo::HasHardwareMPX()            << std::endl;
    std::cout << "HasHardwareSSE:           " << dms::DCPUInfo::HasHardwareSSE()            << std::endl;
    std::cout << "HasHardwareSSE2:          " << dms::DCPUInfo::HasHardwareSSE2()           << std::endl;
    std::cout << "HasHardwareSSE3:          " << dms::DCPUInfo::HasHardwareSSE3()           << std::endl;
    std::cout << "HasHardwareSSSE3:         " << dms::DCPUInfo::HasHardwareSSSE3()          << std::endl;
    std::cout << "HasHardwareSSE41:         " << dms::DCPUInfo::HasHardwareSSE41()          << std::endl;
    std::cout << "HasHardwareSSE42:         " << dms::DCPUInfo::HasHardwareSSE42()          << std::endl;
    std::cout << "HasHardwareSSE4a:         " << dms::DCPUInfo::HasHardwareSSE4a()          << std::endl;
    std::cout << "HasHardwareAES:           " << dms::DCPUInfo::HasHardwareAES()            << std::endl;
    std::cout << "HasHardwareSHA:           " << dms::DCPUInfo::HasHardwareSHA()            << std::endl;
    std::cout << "HasHardwareAVX:           " << dms::DCPUInfo::HasHardwareAVX()            << std::endl;
    std::cout << "HasHardwareXOP:           " << dms::DCPUInfo::HasHardwareXOP()            << std::endl;
    std::cout << "HasHardwareFMA3:          " << dms::DCPUInfo::HasHardwareFMA3()           << std::endl;
    std::cout << "HasHardwareFMA4:          " << dms::DCPUInfo::HasHardwareFMA4()           << std::endl;
    std::cout << "HasHardwareAVX2:          " << dms::DCPUInfo::HasHardwareAVX2()           << std::endl;
    std::cout << "HasHardwareAVX512_F:      " << dms::DCPUInfo::HasHardwareAVX512_F()       << std::endl;
    std::cout << "HasHardwareAVX512_PF:     " << dms::DCPUInfo::HasHardwareAVX512_PF()      << std::endl;
    std::cout << "HasHardwareAVX512_ER:     " << dms::DCPUInfo::HasHardwareAVX512_ER()      << std::endl;
    std::cout << "HasHardwareAVX512_CD:     " << dms::DCPUInfo::HasHardwareAVX512_CD()      << std::endl;
    std::cout << "HasHardwareAVX512_VL:     " << dms::DCPUInfo::HasHardwareAVX512_VL()      << std::endl;
    std::cout << "HasHardwareAVX512_BW:     " << dms::DCPUInfo::HasHardwareAVX512_BW()      << std::endl;
    std::cout << "HasHardwareAVX512_DQ:     " << dms::DCPUInfo::HasHardwareAVX512_DQ()      << std::endl;
    std::cout << "HasHardwareAVX512_IFMA:   " << dms::DCPUInfo::HasHardwareAVX512_IFMA()    << std::endl;
    std::cout << "HasHardwareAVX512_VBMI:   " << dms::DCPUInfo::HasHardwareAVX512_VBMI()    << std::endl;
    std::cout << "MaxWorkers:               " << dms::DCPUInfo::MaxWorkers()                << std::endl;
    std::cout << "L1CacheSize:              " << dms::DCPUInfo::L1CacheSize()               << std::endl;
    std::cout << "L1CacheLineSize:          " << dms::DCPUInfo::L1CacheLineSize()           << std::endl;
    return  0;
}








































