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
using namespace dms;

struct DUint8Object : public DObject {
    uint8 value;

    static
    void
    Dealloc( DUint8Object* oSelf ) {
        delete  oSelf;
    }

    static
    void
    Alloc( DUint8Object* oSelf ) {
        delete  oSelf;
    }

    static
    dmsError
    InitProc( DUint8Object* ioSelf, DObject* iArgs ) {
        ioSelf->refcount = 1;
        ioSelf->value = 0;
        return  DAMAS_SUCCESS;
    }

    static
    DObject*
    New( DType* iType, DObject* iArgs ) {
        DUint8Object* self = new DUint8Object();
    }
};

static
DType
sgDType_uint8 {
    "uint8"
    , 1
    , DAMAS_TPFLAG_PURE
    , "Basic numeric type uint8"
    , nullptr
    , nullptr
    , nullptr
};

int
main( int argc, char *argv[] )
{
    std::cout << "IsHardwareAmd:            " << DCPUInfo::IsHardwareAmd()             << std::endl;
    std::cout << "IsHardwareIntel:          " << DCPUInfo::IsHardwareIntel()           << std::endl;
    std::cout << "IsOSx64:                  " << DCPUInfo::IsOSx64()                   << std::endl;
    std::cout << "HasOsAvx                  " << DCPUInfo::HasOsAvx()                  << std::endl;
    std::cout << "HasOsAvx512:              " << DCPUInfo::HasOsAvx512()               << std::endl;
    std::cout << "HasHardwarex64:           " << DCPUInfo::HasHardwarex64()            << std::endl;
    std::cout << "HasHardwareMMX:           " << DCPUInfo::HasHardwareMMX()            << std::endl;
    std::cout << "HasHardwareABM:           " << DCPUInfo::HasHardwareABM()            << std::endl;
    std::cout << "HasHardwareRDRAND:        " << DCPUInfo::HasHardwareRDRAND()         << std::endl;
    std::cout << "HasHardwareBMI1:          " << DCPUInfo::HasHardwareBMI1()           << std::endl;
    std::cout << "HasHardwareBMI2:          " << DCPUInfo::HasHardwareBMI2()           << std::endl;
    std::cout << "HasHardwareADX:           " << DCPUInfo::HasHardwareADX()            << std::endl;
    std::cout << "HasHardwarePREFETCHWT1:   " << DCPUInfo::HasHardwarePREFETCHWT1()    << std::endl;
    std::cout << "HasHardwareMPX:           " << DCPUInfo::HasHardwareMPX()            << std::endl;
    std::cout << "HasHardwareSSE:           " << DCPUInfo::HasHardwareSSE()            << std::endl;
    std::cout << "HasHardwareSSE2:          " << DCPUInfo::HasHardwareSSE2()           << std::endl;
    std::cout << "HasHardwareSSE3:          " << DCPUInfo::HasHardwareSSE3()           << std::endl;
    std::cout << "HasHardwareSSSE3:         " << DCPUInfo::HasHardwareSSSE3()          << std::endl;
    std::cout << "HasHardwareSSE41:         " << DCPUInfo::HasHardwareSSE41()          << std::endl;
    std::cout << "HasHardwareSSE42:         " << DCPUInfo::HasHardwareSSE42()          << std::endl;
    std::cout << "HasHardwareSSE4a:         " << DCPUInfo::HasHardwareSSE4a()          << std::endl;
    std::cout << "HasHardwareAES:           " << DCPUInfo::HasHardwareAES()            << std::endl;
    std::cout << "HasHardwareSHA:           " << DCPUInfo::HasHardwareSHA()            << std::endl;
    std::cout << "HasHardwareAVX:           " << DCPUInfo::HasHardwareAVX()            << std::endl;
    std::cout << "HasHardwareXOP:           " << DCPUInfo::HasHardwareXOP()            << std::endl;
    std::cout << "HasHardwareFMA3:          " << DCPUInfo::HasHardwareFMA3()           << std::endl;
    std::cout << "HasHardwareFMA4:          " << DCPUInfo::HasHardwareFMA4()           << std::endl;
    std::cout << "HasHardwareAVX2:          " << DCPUInfo::HasHardwareAVX2()           << std::endl;
    std::cout << "HasHardwareAVX512_F:      " << DCPUInfo::HasHardwareAVX512_F()       << std::endl;
    std::cout << "HasHardwareAVX512_PF:     " << DCPUInfo::HasHardwareAVX512_PF()      << std::endl;
    std::cout << "HasHardwareAVX512_ER:     " << DCPUInfo::HasHardwareAVX512_ER()      << std::endl;
    std::cout << "HasHardwareAVX512_CD:     " << DCPUInfo::HasHardwareAVX512_CD()      << std::endl;
    std::cout << "HasHardwareAVX512_VL:     " << DCPUInfo::HasHardwareAVX512_VL()      << std::endl;
    std::cout << "HasHardwareAVX512_BW:     " << DCPUInfo::HasHardwareAVX512_BW()      << std::endl;
    std::cout << "HasHardwareAVX512_DQ:     " << DCPUInfo::HasHardwareAVX512_DQ()      << std::endl;
    std::cout << "HasHardwareAVX512_IFMA:   " << DCPUInfo::HasHardwareAVX512_IFMA()    << std::endl;
    std::cout << "HasHardwareAVX512_VBMI:   " << DCPUInfo::HasHardwareAVX512_VBMI()    << std::endl;
    std::cout << "MaxWorkers:               " << DCPUInfo::MaxWorkers()                << std::endl;
    std::cout << "L1CacheSize:              " << DCPUInfo::L1CacheSize()               << std::endl;
    std::cout << "L1CacheLineSize:          " << DCPUInfo::L1CacheLineSize()           << std::endl;
    std::cout << DLibInfo::LibraryInformationString() << std::endl;
    return  0;
}








































