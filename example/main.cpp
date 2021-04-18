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

template< typename T >
struct DBasicObject : DObject {
    T val;
};

#define DO( T, _E0, _E1, _E2, _E3 )                     \
    typedef DBasicObject< T >   T ## _Object; \
    DType T ## _Type = DType::MakeGeneric< T ## _Object >( #T, "Basic arithmetic " #T );
DAMAS_FOR_ALL_TYPES_DO( DO, 0, 0, 0, );

int
main( int argc, char *argv[] )
{
    uint8_Object* var_test = (uint8_Object*)uint8_Type.ObjectCreate();
    var_test->val = 50;
    uint32 hash = uint8_Type.hash( var_test );
    uint8_Type.ObjectDelete( var_test );

    uint8_Object* var_uint8 = (uint8_Object*)uint8_Type.ObjectCreate();
    uint16_Object*var_uint16 = (uint16_Object*)uint16_Type.ObjectCreate();
    uint32_Object* var_uint32 = (uint32_Object*)uint32_Type.ObjectCreate();
    uint64_Object* var_uint64 = (uint64_Object*)uint64_Type.ObjectCreate();
    int8_Object* var_int8 = (int8_Object*)int8_Type.ObjectCreate();
    int16_Object* var_int16 = (int16_Object*)int16_Type.ObjectCreate();
    int32_Object* var_int32 = (int32_Object*)int32_Type.ObjectCreate();
    int64_Object* var_int64 = (int64_Object*)int64_Type.ObjectCreate();
    float_Object* var_float = (float_Object*)float_Type.ObjectCreate();
    double_Object* var_double = (double_Object*)double_Type.ObjectCreate();
    uint8_Type.ObjectDelete( var_uint8 );
    uint16_Type.ObjectDelete( var_uint16 );
    uint32_Type.ObjectDelete( var_uint32 );
    uint64_Type.ObjectDelete( var_uint64 );
    int8_Type.ObjectDelete( var_int8 );
    int16_Type.ObjectDelete( var_int16 );
    int32_Type.ObjectDelete( var_int32 );
    int64_Type.ObjectDelete( var_int64 );
    float_Type.ObjectDelete( var_float );
    double_Type.ObjectDelete( var_double );

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
    std::cout << DLibInfo::LibraryInformationString().Data() << std::endl;
    return  0;
}








































