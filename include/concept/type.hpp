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
#include "concept/object.hpp"
#include "string/string.hpp"
#include "string/crc32.hpp"
#include "memory/memory.hpp"

DAMAS_NAMESPACE_BEGIN
struct DObject;
struct DType;
typedef DObject* (*fpUnaryOperator)( DObject* );
typedef DObject* (*fpBinaryOperator)( DObject*, DObject* );
typedef DObject* (*fpTernaryOperator)( DObject*, DObject*, DObject* );
typedef void (*fpDeallocFunc)( void* );
typedef void (*fpDeleteFunc)( DObject* );
typedef void (*fpDestructor)( DObject* );
typedef DObject* (*fpGetAttributeFunc)( DObject*, const char* );
typedef dmsError (*fpSetAttributeFunc)( DObject*, const char*, DObject* );
typedef DObject* (*fpReprFunc)( DObject* );
typedef uint32 (*fpHashFunc)( DObject* );
typedef dmsError (*fpInitProc)( DObject*, DObject* );
typedef DObject* (*fpNewFunc)( DType*, DObject* );
typedef DObject* (*fpAllocFunc)( DType* );

/// @class      DType
/// @brief      The DType class represents a type in the Damas language.
/// @details    DType stores a type detailed information.
struct DType
{
    DString name;
    uint8 size;
    DString doc;
    fpDeallocFunc dealloc;
    fpDeleteFunc deletef;
    fpDestructor destructor;
    fpReprFunc repr;
    fpHashFunc hash;
    fpInitProc init;
    fpNewFunc newf;
    fpAllocFunc alloc;

    static
    void
    GenericDealloc( void* iBuffer ) {
        XFree( iBuffer );
    }

    template< typename tObject >
    static
    void
    GenericDelete( DObject* iObject ) {
        GenericDestructor< tObject >( iObject );
        GenericDealloc( iObject );
    }

    template< typename tObject >
    static
    void
    GenericDestructor( DObject* iObject ) {
        reinterpret_cast< tObject* >( iObject )->~tObject();
    }

    template< typename tObject >
    static
    uint32
    GenericHash( DObject* iObject ) {
        tObject* obj = reinterpret_cast< tObject* >( iObject );
        uint32 offset = sizeof( int64 ) + sizeof( DType* );
        return CRC32( reinterpret_cast< uint8* >( obj ) + offset, obj->type->size - offset);
    }


    template< typename tObject >
    static
    dmsError
    GenericInit( DObject* iObject, DObject* iArgs = nullptr ) {
        tObject* obj = reinterpret_cast< tObject* >( iObject );
        memset( obj, 0, sizeof( tObject ) );
        return  DAMAS_SUCCESS;
    }

    static
    DObject*
    GenericNew( DType* iType, DObject* iArgs = nullptr ) {
        DObject* obj = iType->alloc( iType );
        iType->init( obj, iArgs );
        obj->refcount = 1;
        obj->type = iType;
        return  obj;
    }

    static
    DObject*
    GenericAlloc( DType* iType ) {
        return  reinterpret_cast< DObject* >( XMalloc( iType->size ) );
    }

    template< typename tObject >
    static
    DType
    MakeGeneric( const char* iName, const char* iDoc ) {
        return {
              iName
            , sizeof( tObject )
            , iDoc
            , GenericDealloc
            , GenericDelete< tObject >
            , GenericDestructor< tObject >
            , nullptr
            , GenericHash< tObject >
            , GenericInit< tObject >
            , GenericNew
            , GenericAlloc
        };
    }

    DObject*
    ObjectCreate() {
        return  newf( this, nullptr );
    }

    static
    void
    ObjectDelete( DObject* iObject ) {
        iObject->type->deletef( iObject );
    }
};

DAMAS_NAMESPACE_END

