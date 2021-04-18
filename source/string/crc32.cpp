/*
*   Damas
*__________________
* @file         crc32.cpp
* @author       Clement Berthaud
* @brief        This file provides definition for CRC32 function.
* @copyright    Copyright 2021 Clément Berthaud
* @license      Please refer to LICENSE.md
*/
#include "string/crc32.hpp"

DAMAS_NAMESPACE_BEGIN
/////////////////////////////////////////////////////
// CRC32
uint32
CRC32( const uint8*iData, int iLen )
{
    int i = 0;
    int j = 0;
    unsigned int byte = 0;
    unsigned int crc = 0;
    unsigned int mask = 0;

    i = 0;
    crc = 0xFFFFFFFF;
    while( i < iLen )
    {
        byte = iData[i];
        crc = crc ^ byte;
        for( j = 7; j >= 0; j-- )
        {
            #pragma warning(push)
            #pragma warning(disable : 4146)
            mask = static_cast< unsigned int >( -( crc & 1 ) );
            crc = ( crc >> 1 ) ^ ( 0xEDB88320 & mask );
            #pragma warning(pop)
        }
        i = i + 1;
    }

    return  ~crc;
}

DAMAS_NAMESPACE_END

