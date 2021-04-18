/*
*   Damas
*__________________
* @file         wstring.cpp
* @author       Clement Berthaud
* @brief        This file provides the definition for the DWString class.
* @copyright    Copyright 2021 Clément Berthaud
* @license      Please refer to LICENSE.md
*/
#include "string/wstring.hpp"
#include "math/math.hpp"
#include "string/crc32.hpp"
#include "string/md5.hpp"
#include "string/uuid.hpp"
#include "string/string.hpp"
#include <string>
#include <cstring>

DAMAS_NAMESPACE_BEGIN
DWString::~DWString() {
    if( mBulk )
        CleanupBulk();
}

DWString::DWString()
    : mBulk( new char_type[1] )
    , mCapacity( 1 )
    , mSize( 0 )
{
    mBulk[0] = L'\0';
}

DWString::DWString( const char_type* iStr )
    : mBulk( nullptr )
    , mCapacity( 0 )
    , mSize( 0 )
{
    uint64 cap = wcslen( iStr ) + 1;
    mBulk = new char_type[ cap ];
    memcpy( mBulk, iStr, sizeof( char_type ) * cap );
    mCapacity = cap;
    mSize = cap - 1;
    mBulk[ mSize ] = L'\0';
}

DWString::DWString( const DWString& iStr )
    : mBulk( nullptr )
    , mCapacity( 0 )
    , mSize( 0 )
{
    uint64 cap = iStr.Size() + 1;
    mBulk = new char_type[ cap ];
    memcpy( mBulk, iStr.mBulk, sizeof( char_type ) * cap );
    mCapacity = cap;
    mSize = cap - 1;
}

DWString::DWString( DWString&& iStr )
    : mBulk( iStr.mBulk )
    , mCapacity( iStr.mCapacity )
    , mSize( iStr.mSize )
{
    iStr.mBulk = nullptr;
    iStr.mCapacity = 0;
    iStr.mSize = 0;
}

DWString::DWString( const DString& iWStr )
    : mBulk( nullptr )
    , mCapacity( 0 )
    , mSize( 0 )
{
    DAMAS_ASSERT( false, "TODO" );
}

DWString&
DWString::operator=( const DWString& iStr ) {
    DAMAS_ASSERT( iStr.mBulk != mBulk, "Cannot assign itself" );
    CleanupBulk();
    uint64 cap = iStr.Size() + 1;
    mBulk = new char_type[ cap ];
    memcpy( mBulk, iStr.mBulk, sizeof( char_type ) * cap );
    mCapacity = cap;
    mSize = cap - 1;
    return  (*this);
}

DWString&
DWString::operator=( DWString&& iStr ) {
    DAMAS_ASSERT( iStr.mBulk != mBulk, "Cannot assign itself" );
    mBulk = iStr.mBulk;
    mCapacity = iStr.mCapacity;
    mSize = iStr.mSize;
    iStr.mBulk = nullptr;
    iStr.mCapacity = 0;
    iStr.mSize = 0;
    return  (*this);
}

DWString
DWString::Copy() const {
    return  DWString( *this );
}

DWString
DWString::SubString( uint64 iPos, uint64 iCount ) const {
    uint64 start = DMath::Min( iPos, mSize );
    uint64 end = DMath::Min( iPos + iCount, mSize );
    uint64 len = end - start;
    DWString result( len );
    memcpy( result.mBulk, mBulk + start, len );
    result.mBulk[len] = L'\0';

    return  result;
}

uint64
DWString::Capacity() const {
    return  mCapacity;
}

uint64
DWString::Size() const {
    return  mSize;
}

const DWString::char_type*
DWString::Data() const {
    return  mBulk;
}


DWString::char_type&
DWString::operator[]( uint64 iIndex ) {
    DAMAS_ASSERT( mSize > 0, "Bad call, string is empty" );
    DAMAS_ASSERT( iIndex >= 0 && iIndex < mSize, "Bad Index" );
    DAMAS_ASSERT( mBulk != nullptr, "Error, no bulk, string is uninitialized" );
    return  mBulk[ iIndex ];
}

const DWString::char_type&
DWString::operator[]( uint64 iIndex ) const {
    DAMAS_ASSERT( mSize > 0, "Bad call, string is empty" );
    DAMAS_ASSERT( iIndex >= 0 && iIndex < mSize, "Bad Index" );
    DAMAS_ASSERT( mBulk != nullptr, "Error, no bulk, string is uninitialized" );
    return  mBulk[ iIndex ];
}

DWString::char_type&
DWString::At( uint64 iIndex ) {
    DAMAS_ASSERT( mSize > 0, "Bad call, string is empty" );
    DAMAS_ASSERT( iIndex >= 0 && iIndex < mSize, "Bad Index" );
    DAMAS_ASSERT( mBulk != nullptr, "Error, no bulk, string is uninitialized" );
    return  mBulk[ iIndex ];
}

const DWString::char_type&
DWString::At( uint64 iIndex ) const {
    DAMAS_ASSERT( mSize > 0, "Bad call, string is empty" );
    DAMAS_ASSERT( iIndex >= 0 && iIndex < mSize, "Bad Index" );
    DAMAS_ASSERT( mBulk != nullptr, "Error, no bulk, string is uninitialized" );
    return  mBulk[ iIndex ];
}

DWString::char_type&
DWString::Front() {
    DAMAS_ASSERT( mSize > 0, "Bad call, string is empty" );
    DAMAS_ASSERT( mBulk != nullptr, "Error, no bulk, string is uninitialized" );
    return  mBulk[ 0 ];
}

const
DWString::char_type&
DWString::Front() const {
    DAMAS_ASSERT( mSize > 0, "Bad call, string is empty" );
    DAMAS_ASSERT( mBulk != nullptr, "Error, no bulk, string is uninitialized" );
    return  mBulk[ 0 ];
}

DWString::char_type&
DWString::Back() {
    DAMAS_ASSERT( mSize > 0, "Bad call, string is empty" );
    DAMAS_ASSERT( mBulk != nullptr, "Error, no bulk, string is uninitialized" );
    return  mBulk[ mSize - 1 ];
}

const DWString::char_type&
DWString::Back() const {
    DAMAS_ASSERT( mSize > 0, "Bad call, string is empty" );
    DAMAS_ASSERT( mBulk != nullptr, "Error, no bulk, string is uninitialized" );
    return  mBulk[ mSize - 1 ];
}

DString
DWString::ToString() const {
    DAMAS_ASSERT( false, "TODO" );
    DString result;
    return  result;
}

DWString&
DWString::Append( const DWString& iStr ) {
    uint64 len = mSize + iStr.mSize;
    GrowBulk( len );
    memcpy( mBulk + mSize, iStr.mBulk, iStr.mSize + 1 );
    mSize = len;
    return  (*this);
}

DWString&
DWString::Append( const char_type* iStr ) {
    uint64 olen = wcslen( iStr );
    uint64 len = mSize + olen;
    GrowBulk( len );
    memcpy( mBulk + mSize, iStr, olen + 1 );
    mSize = len;
    return  (*this);
}

DWString&
DWString::Append( char_type iChar ) {
    uint64 len = mSize + 1;
    GrowBulk( len );
    mBulk[ mSize ] = iChar;
    mBulk[ len ] = L'\0';
    mSize = len;
    return  (*this);
}

DWString&
DWString::Prepend( const DWString& iStr ) {
    uint64 len = mSize + iStr.mSize;
    GrowBulk( len, iStr.mSize );
    mSize = len;
    memcpy( mBulk, iStr.mBulk, iStr.mSize );
    return  (*this);
}

DWString&
DWString::Prepend( const char_type* iStr ) {
    uint64 olen = wcslen( iStr );
    uint64 len = mSize + olen;
    GrowBulk( len, olen );
    memcpy( mBulk, iStr, olen );
    mSize = len;
    return  (*this);
}

DWString&
DWString::Prepend( char_type iChar ) {
    uint64 len = mSize + 1;
    GrowBulk( len, 1 );
    mBulk[ 0 ] = iChar;
    mSize = len;
    return  (*this);
}

bool
DWString::operator==( const DWString& iOther ) {
    if( mSize != iOther.mSize )
        return  false;

    for( uint64 i = 0; i < mSize; ++i )
        if( mBulk[i] != iOther.mBulk[i] )
            return  false;

    return  true;
}

bool
DWString::operator!=( const DWString& iOther ) {
    return  !( (*this) == iOther );
}

int
DWString::ToInt() const {
    return  std::wcstol( mBulk, nullptr, 10 );
}

unsigned int
DWString::ToUnsignedInt() const {
    return  std::wcstoul( mBulk, nullptr, 10 );
}


float
DWString::ToFloat() const {
    return  std::wcstof( mBulk, nullptr );
}

double
DWString::ToDouble() const {
    return  std::wcstod( mBulk, nullptr );
}

//static
DWString
DWString::FromInt( int iValue ) {
    std::wstring tmp = std::to_wstring( iValue );
    uint64 len = wcslen( tmp.c_str() );
    DWString result( len );
    memcpy( result.mBulk, tmp.c_str(), len + 1 );
    return  result;
}

//static
DWString
DWString::FromUnsignedInt( unsigned int iValue ) {
    std::wstring tmp = std::to_wstring( iValue );
    uint64 len = wcslen( tmp.c_str() );
    DWString result( len );
    memcpy( result.mBulk, tmp.c_str(), len + 1 );
    return  result;
}

//static
DWString
DWString::FromFloat( float iValue ) {
    std::wstring tmp = std::to_wstring( iValue );
    uint64 len = wcslen( tmp.c_str() );
    DWString result( len );
    memcpy( result.mBulk, tmp.c_str(), len + 1 );
    return  result;
}

//static
DWString
DWString::FromDouble( double iValue ) {
    std::wstring tmp = std::to_wstring( iValue );
    uint64 len = wcslen( tmp.c_str() );
    DWString result( len );
    memcpy( result.mBulk, tmp.c_str(), len + 1 );
    return  result;
}

//static
DWString
DWString::FromString( const DString& iValue ) {
    DAMAS_ASSERT( false, "TODO" );
    return  DWString();
}

DWString&
DWString::TransformUpperCase() {
    for( uint64 i = 0; i < mSize; ++i )
        mBulk[i] = toupper( mBulk[i] );
    return  (*this);
}

DWString&
DWString::TransformLowerCase() {
    for( uint64 i = 0; i < mSize; ++i )
        mBulk[i] = tolower( mBulk[i] );
    return  (*this);
}

DWString
DWString::ToUpper() const {
    DWString result( *this );
    result.TransformUpperCase();
    return  result;
}

DWString
DWString::ToLower() const {
    DWString result( *this );
    result.TransformLowerCase();
    return  result;
}

bool
DWString::IsEmpty() const {
    return  mSize == 0;
}

void
DWString::Reserve( uint64 iCapacity ) {
    if( iCapacity > mCapacity ) {
        char_type* tmp = new char_type[ iCapacity ];
        memcpy( tmp, mBulk, mSize + 1 );
        mCapacity = iCapacity;
        CleanupBulk();
        mBulk = tmp;
    }
}

void
DWString::Shrink() {
    uint64 cap = mSize + 1;
    if( mCapacity > cap ) {
        char_type* tmp = new char_type[ cap ];
        memcpy( tmp, mBulk, cap );
        mCapacity = cap;
        CleanupBulk();
        mBulk = tmp;
    }
}

void
DWString::Resize( uint64 iSize, char_type iChar ) {
    if( iSize == mSize )
        return;

    if( iSize == 0 ) {
        Clear();
    } else {
        GrowBulk( iSize );
        for( uint64 i = mSize; i < iSize; ++i ) {
            mBulk[i] = iChar;
        }

        mSize = iSize;
        mBulk[ mSize ] = L'\0';
    }
}

void
DWString::Clear() {
    CleanupBulk();
    mBulk = new char_type[1];
    mCapacity = 1;
    mSize = 0;
    mBulk[0] = L'\0';
}

TArray< DWString >
DWString::Split( const DWString& iSep ) const {
    TArray< DWString > result;
    int64 prev = -1;
    while( 1 ) {
        int64 next = FindFrom( prev + 1, iSep );
        if( next == -1 ) {
            result.PushBack( SubString( prev, mSize - prev ) );
            break;
        } else {
            result.PushBack( SubString( prev, next - prev ) );
        }
        prev = next;
    }
    return  result;
}

DWString&
DWString::Erase( uint64 iPos, uint64 iCount ) {
    uint64 start = DMath::Min( iPos, mSize );
    uint64 end = DMath::Min( iPos + iCount, mSize );
    uint64 rem = mSize - end;
    uint64 len = rem + start;
    memmove( mBulk + start, mBulk + end, rem );
    mSize = len;
    mBulk[ mSize ] = L'\0';
    return  (*this);
}

DWString&
DWString::Insert( uint64 iPos, const DWString& iStr ) {
    // Implemented this way because i'm lazy.
    // Can be optimized.
    return  operator=( std::move( SubString( 0, iPos ).Append( iStr ).Append( SubString( iPos + iStr.Size(), mSize ) ) ) );
}

int64
DWString::FindFirst( const DWString& iStr ) const {
    return  FindFrom( 0, iStr );
}

int64
DWString::FindLast( const DWString& iStr ) const {
    int64 result = -1;
    while( 1 ) {
        int64 tmp = FindFrom( result + 1, iStr );
        if( tmp == -1 )
            return  result;
        result = tmp;
    }
}

int64
DWString::FindFrom( uint64 iPos, const DWString& iStr ) const {
    int64 result = -1;

    for( uint64 i = iPos; i < mSize; ++i ) {
        for( uint64 j = 0; j < iStr.mSize; ++j ) {
            if( i + j > mSize )
                goto end;

            if( mBulk[ i + j ] != iStr.mBulk[j] )
                goto next;
        }
        result = i;
        next:
        continue;
    }

    end:
    return  result;
}

bool
DWString::ReplaceFirst( const DWString& iA, const DWString& iB ) {
    int64 index = FindFirst( iA );
    if( index != -1 ) {
        Erase( index, iA.Size() );
        Insert( index, iB );
        return  true;
    }
    return  false;
}

bool
DWString::ReplaceLast( const DWString& iA, const DWString& iB ) {
    int64 index = FindLast( iA );
    if( index != -1 ) {
        Erase( index, iA.Size() );
        Insert( index, iB );
        return  true;
    }
    return  false;
}

bool
DWString::ReplaceFrom( uint64 iPos, const DWString& iA, const DWString& iB ) {
    int64 index = FindFrom( iPos, iA );
    if( index != -1 ) {
        Erase( index, iA.Size() );
        Insert( index, iB );
        return  true;
    }
    return  false;
}

void
DWString::ReplaceAll( const DWString& iA, const DWString& iB ) {
    while( ReplaceFirst( iA, iB ) ) {}
}

// Private
void
DWString::CleanupBulk() {
    DAMAS_ASSERT( mBulk, "Bad State" );
    delete [] mBulk;
    mBulk = nullptr;
}

void
DWString::GrowBulk( uint64 iSize, uint64 iCopyOffset ) {
    uint64 cap = iSize + 1;
    if( cap > mCapacity ) {
        char_type* tmp = new char_type[ cap ];
        memcpy( tmp + iCopyOffset, mBulk, mSize + 1 );
        mCapacity = cap;
        CleanupBulk();
        mBulk = tmp;
    }
}

DWString::DWString( uint64 iSize )
    : mBulk( new char_type[ iSize + 1 ] )
    , mCapacity( iSize + 1 )
    , mSize( iSize )
{
}

DAMAS_NAMESPACE_END

