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
// FDecl
struct DObject;
struct DType;
typedef void (*fpDestructor)( DObject* /* oSelf */ );
typedef void (*fpInitProc)( DObject* /* ioSelf */, DObject* /* iArgs */ );
typedef DObject* (*fpNewProc)( DType* /* iType */, DObject* /* iArgs */ );

/// @class      DType
/// @brief      The DType class represents a type in the Damas language.
/// @details    DType stores a type detailed information.
struct DAMAS_API DType
{
    const char* name;
    uint8 size;
    uint32 flags;
    const char* doc;
    fpDestructor destructor;
    fpInitProc initproc;
    fpNewProc newproc;
};

#define DAMAS_TPFLAG_PURE 0

DAMAS_NAMESPACE_END

