/*
*   Damas
*__________________
* @file         type.hpp
* @author       Clement Berthaud
* @brief        This file declares a concept of the Damas language.
* @copyright    Copyright 2021 Clément Berthaud
* @license      Please refer to LICENSE.md
*/
#pragma once
#include "core/core.hpp"
#include <string>

DAMAS_NAMESPACE_BEGIN
/// @class      DType
/// @brief      The DType class represents a type in the Damas language.
/// @details    DType stores a type detailled information.
struct DAMAS_API DType
{
    uint8 size;
    std::string name;
    const eTypeIdentity identity;
};

DType sgDType_uint8  { 1, "uint8",  eTypeIdentity::kPure };
DType sgDType_uint16 { 2, "uint16", eTypeIdentity::kPure };
DType sgDType_uint32 { 4, "uint32", eTypeIdentity::kPure };
DType sgDType_uint64 { 8, "uint64", eTypeIdentity::kPure };
DType sgDType_int8   { 1, "int8",   eTypeIdentity::kPure };
DType sgDType_int16  { 2, "int16",  eTypeIdentity::kPure };
DType sgDType_int32  { 4, "int32",  eTypeIdentity::kPure };
DType sgDType_int64  { 8, "int64",  eTypeIdentity::kPure };

DAMAS_NAMESPACE_END

