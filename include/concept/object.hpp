/*
*   Damas
*__________________
* @file         object.hpp
* @author       Clement Berthaud
* @brief        This file declares a concept of the Damas language.
* @copyright    Copyright 2021 Clément Berthaud
* @license      Please refer to LICENSE.md
*/
#pragma once
#include "core/core.hpp"

DAMAS_NAMESPACE_BEGIN
// FDecl
struct DType;

/// @class      DObject
/// @brief      The DObject class represents an object in the Damas language.
/// @details    DObject stores an object detailed information.
struct DAMAS_API DObject
{
    int64 refcount;
    DType* type;

    DObject* Adress() {
        return  this;
    }

    const DObject* Adress() const {
        return  this;
    }
};

DAMAS_NAMESPACE_END

