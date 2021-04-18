/*
*   Damas
*__________________
* @file         algorithmic.hpp
* @author       Clement Berthaud
* @brief        This file provides the definition for basic container functions.
* @copyright    Copyright 2021 Clément Berthaud
* @license      Please refer to LICENSE.md
*/
#pragma once
#include "core/core.hpp"
#include "memory/array.hpp"

DAMAS_NAMESPACE_BEGIN
class DAMAS_API DContainerAlgorithms {
public:
    template< typename T >
    static void BubbleSort( TArray< T >& ioArray ) {
        T temp;
        const int64 size = static_cast< int64 >( ioArray.Size() );
        for( int64 i = 0; i < size; ++i ) {
            for( int64 j = size - 1; j > i; --j ) {
                if( ioArray[j] < ioArray [j-1] ) {
                    temp = ioArray[j-1];
                    ioArray[j-1] = ioArray[j];
                    ioArray[j] = temp;
                }
            }
        }
    }
};

DAMAS_NAMESPACE_END

