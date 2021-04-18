/*
*   Damas
*__________________
* @file         memory.hpp
* @author       Clement Berthaud
* @brief        This file provides the declaration for the memory functions.
* @copyright    Copyright 2021 Clément Berthaud
* @license      Please refer to LICENSE.md
*/
#pragma once
#include "core/core.hpp"

DAMAS_NAMESPACE_BEGIN
DAMAS_API void* XMalloc( uint64 iSizeBytes );
DAMAS_API void XFree( void* iAlloc );
DAMAS_NAMESPACE_END

