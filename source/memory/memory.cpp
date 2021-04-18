/*
*   Damas
*__________________
* @file         memory.cpp
* @author       Clement Berthaud
* @brief        This file provides the definition for the memory functions.
* @copyright    Copyright 2021 Clément Berthaud
* @license      Please refer to LICENSE.md
*/
#include "memory/memory.hpp"

DAMAS_NAMESPACE_BEGIN
void*
XMalloc(
    uint64 iSizeBytes
)
{
    return  malloc( iSizeBytes );
}

void
XFree(
    void* iAlloc
)
{
    free( iAlloc );
}

DAMAS_NAMESPACE_END

