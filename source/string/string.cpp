/*
*   Damas
*__________________
* @file         string.cpp
* @author       Clement Berthaud
* @brief        This file provides the definition for the DString class.
* @copyright    Copyright 2021 Clément Berthaud
* @license      Please refer to LICENSE.md
*/
#include "string/string.hpp"
#include "math/math.hpp"
#include "string/crc32.hpp"
#include "string/md5.hpp"
#include "string/uuid.hpp"
#include "string/wstring.hpp"
#include <string>
#include <cstring>

DAMAS_NAMESPACE_BEGIN
DString::~DString() {
    if( mBulk )
        CleanupBulk();
}

DString::DString()
    : mBulk( new char_type[1] )
    , mCapacity( 1 )
    , mSize( 0 )
{
    mBulk[0] = '\0';
}

DString::DString( const char_type* iStr )
    : mBulk( nullptr )
    , mCapacity( 0 )
    , mSize( 0 )
{
    uint64 cap = strlen( iStr ) + 1;
    mBulk = new char_type[ cap ];
    memcpy( mBulk, iStr, sizeof( char_type ) * cap );
    mCapacity = cap;
    mSize = cap - 1;
    mBulk[ mSize ] = '\0';
}

DString::DString( const DString& iStr )
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

DString::DString( DString&& iStr )
    : mBulk( iStr.mBulk )
    , mCapacity( iStr.mCapacity )
    , mSize( iStr.mSize )
{
    iStr.mBulk = nullptr;
    iStr.mCapacity = 0;
    iStr.mSize = 0;
}

DString::DString( const DWString& iWStr )
    : mBulk( nullptr )
    , mCapacity( 0 )
    , mSize( 0 )
{
    DAMAS_ASSERT( false, "TODO" );
}

DString&
DString::operator=( const DString& iStr ) {
    DAMAS_ASSERT( iStr.mBulk != mBulk, "Cannot assign itself" );
    CleanupBulk();
    uint64 cap = iStr.Size() + 1;
    mBulk = new char_type[ cap ];
    memcpy( mBulk, iStr.mBulk, sizeof( char_type ) * cap );
    mCapacity = cap;
    mSize = cap - 1;
    return  (*this);
}

DString&
DString::operator=( DString&& iStr ) {
    DAMAS_ASSERT( iStr.mBulk != mBulk, "Cannot assign itself" );
    mBulk = iStr.mBulk;
    mCapacity = iStr.mCapacity;
    mSize = iStr.mSize;
    iStr.mBulk = nullptr;
    iStr.mCapacity = 0;
    iStr.mSize = 0;
    return  (*this);
}

DString
DString::Copy() const {
    return  DString( *this );
}

DString
DString::SubString( uint64 iPos, uint64 iCount ) const {
    uint64 start = DMath::Min( iPos, mSize );
    uint64 end = DMath::Min( iPos + iCount, mSize );
    uint64 len = end - start;
    DString result( len );
    memcpy( result.mBulk, mBulk + start, len );
    result.mBulk[len] = '\0';

    return  result;
}

uint64
DString::Capacity() const {
    return  mCapacity;
}

uint64
DString::Size() const {
    return  mSize;
}

const DString::char_type*
DString::Data() const {
    return  mBulk;
}


DString::char_type&
DString::operator[]( uint64 iIndex ) {
    DAMAS_ASSERT( mSize > 0, "Bad call, string is empty" );
    DAMAS_ASSERT( iIndex >= 0 && iIndex < mSize, "Bad Index" );
    DAMAS_ASSERT( mBulk != nullptr, "Error, no bulk, string is uninitialized" );
    return  mBulk[ iIndex ];
}

const DString::char_type&
DString::operator[]( uint64 iIndex ) const {
    DAMAS_ASSERT( mSize > 0, "Bad call, string is empty" );
    DAMAS_ASSERT( iIndex >= 0 && iIndex < mSize, "Bad Index" );
    DAMAS_ASSERT( mBulk != nullptr, "Error, no bulk, string is uninitialized" );
    return  mBulk[ iIndex ];
}

DString::char_type&
DString::At( uint64 iIndex ) {
    DAMAS_ASSERT( mSize > 0, "Bad call, string is empty" );
    DAMAS_ASSERT( iIndex >= 0 && iIndex < mSize, "Bad Index" );
    DAMAS_ASSERT( mBulk != nullptr, "Error, no bulk, string is uninitialized" );
    return  mBulk[ iIndex ];
}

const DString::char_type&
DString::At( uint64 iIndex ) const {
    DAMAS_ASSERT( mSize > 0, "Bad call, string is empty" );
    DAMAS_ASSERT( iIndex >= 0 && iIndex < mSize, "Bad Index" );
    DAMAS_ASSERT( mBulk != nullptr, "Error, no bulk, string is uninitialized" );
    return  mBulk[ iIndex ];
}

DString::char_type&
DString::Front() {
    DAMAS_ASSERT( mSize > 0, "Bad call, string is empty" );
    DAMAS_ASSERT( mBulk != nullptr, "Error, no bulk, string is uninitialized" );
    return  mBulk[ 0 ];
}

const
DString::char_type&
DString::Front() const {
    DAMAS_ASSERT( mSize > 0, "Bad call, string is empty" );
    DAMAS_ASSERT( mBulk != nullptr, "Error, no bulk, string is uninitialized" );
    return  mBulk[ 0 ];
}

DString::char_type&
DString::Back() {
    DAMAS_ASSERT( mSize > 0, "Bad call, string is empty" );
    DAMAS_ASSERT( mBulk != nullptr, "Error, no bulk, string is uninitialized" );
    return  mBulk[ mSize - 1 ];
}

const DString::char_type&
DString::Back() const {
    DAMAS_ASSERT( mSize > 0, "Bad call, string is empty" );
    DAMAS_ASSERT( mBulk != nullptr, "Error, no bulk, string is uninitialized" );
    return  mBulk[ mSize - 1 ];
}

DWString
DString::ToWString() const {
    DAMAS_ASSERT( false, "TODO" );
    DWString result;
    return  result;
}

DString&
DString::Append( const DString& iStr ) {
    uint64 len = mSize + iStr.mSize;
    GrowBulk( len );
    memcpy( mBulk + mSize, iStr.mBulk, iStr.mSize + 1 );
    mSize = len;
    return  (*this);
}

DString&
DString::Append( const char_type* iStr ) {
    uint64 olen = strlen( iStr );
    uint64 len = mSize + olen;
    GrowBulk( len );
    memcpy( mBulk + mSize, iStr, olen + 1 );
    mSize = len;
    return  (*this);
}

DString&
DString::Append( char_type iChar ) {
    uint64 len = mSize + 1;
    GrowBulk( len );
    mBulk[ mSize ] = iChar;
    mBulk[ len ] = '\0';
    mSize = len;
    return  (*this);
}

DString&
DString::Prepend( const DString& iStr ) {
    uint64 len = mSize + iStr.mSize;
    GrowBulk( len, iStr.mSize );
    mSize = len;
    memcpy( mBulk, iStr.mBulk, iStr.mSize );
    return  (*this);
}

DString&
DString::Prepend( const char_type* iStr ) {
    uint64 olen = strlen( iStr );
    uint64 len = mSize + olen;
    GrowBulk( len, olen );
    memcpy( mBulk, iStr, olen );
    mSize = len;
    return  (*this);
}

DString&
DString::Prepend( char_type iChar ) {
    uint64 len = mSize + 1;
    GrowBulk( len, 1 );
    mBulk[ 0 ] = iChar;
    mSize = len;
    return  (*this);
}

bool
DString::operator==( const DString& iOther ) {
    if( mSize != iOther.mSize )
        return  false;

    for( uint64 i = 0; i < mSize; ++i )
        if( mBulk[i] != iOther.mBulk[i] )
            return  false;

    return  true;
}

bool
DString::operator!=( const DString& iOther ) {
    return  !( (*this) == iOther );
}

int
DString::ToInt() const {
    return  std::atoi( mBulk );
}

unsigned int
DString::ToUnsignedInt() const {
    return  std::stoul( mBulk );
}


float
DString::ToFloat() const {
    return  std::stof( mBulk );
}

double
DString::ToDouble() const {
    return  std::stod( mBulk );
}

//static
DString
DString::FromInt( int iValue ) {
    std::string tmp = std::to_string( iValue );
    uint64 len = strlen( tmp.c_str() );
    DString result( len );
    memcpy( result.mBulk, tmp.c_str(), len + 1 );
    return  result;
}

//static
DString
DString::FromUnsignedInt( unsigned int iValue ) {
    std::string tmp = std::to_string( iValue );
    uint64 len = strlen( tmp.c_str() );
    DString result( len );
    memcpy( result.mBulk, tmp.c_str(), len + 1 );
    return  result;
}

//static
DString
DString::FromFloat( float iValue ) {
    std::string tmp = std::to_string( iValue );
    uint64 len = strlen( tmp.c_str() );
    DString result( len );
    memcpy( result.mBulk, tmp.c_str(), len + 1 );
    return  result;
}

//static
DString
DString::FromDouble( double iValue ) {
    std::string tmp = std::to_string( iValue );
    uint64 len = strlen( tmp.c_str() );
    DString result( len );
    memcpy( result.mBulk, tmp.c_str(), len + 1 );
    return  result;
}

//static
DString
DString::FromWString( const DWString& iValue ) {
    DAMAS_ASSERT( false, "TODO" );
    return  DString();
}

DString&
DString::TransformUpperCase() {
    for( uint64 i = 0; i < mSize; ++i )
        mBulk[i] = toupper( mBulk[i] );
    return  (*this);
}

DString&
DString::TransformLowerCase() {
    for( uint64 i = 0; i < mSize; ++i )
        mBulk[i] = tolower( mBulk[i] );
    return  (*this);
}

DString
DString::ToUpper() const {
    DString result( *this );
    result.TransformUpperCase();
    return  result;
}

DString
DString::ToLower() const {
    DString result( *this );
    result.TransformLowerCase();
    return  result;
}

bool
DString::IsEmpty() const {
    return  mSize == 0;
}

void
DString::Reserve( uint64 iCapacity ) {
    if( iCapacity > mCapacity ) {
        char_type* tmp = new char_type[ iCapacity ];
        memcpy( tmp, mBulk, mSize + 1 );
        mCapacity = iCapacity;
        CleanupBulk();
        mBulk = tmp;
    }
}

void
DString::Shrink() {
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
DString::Resize( uint64 iSize, char_type iChar ) {
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
        mBulk[ mSize ] = '\0';
    }
}

void
DString::Clear() {
    CleanupBulk();
    mBulk = new char_type[1];
    mCapacity = 1;
    mSize = 0;
    mBulk[0] = '\0';
}

TArray< DString >
DString::Split( const DString& iSep ) const {
    TArray< DString > result;
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

DString&
DString::Erase( uint64 iPos, uint64 iCount ) {
    uint64 start = DMath::Min( iPos, mSize );
    uint64 end = DMath::Min( iPos + iCount, mSize );
    uint64 rem = mSize - end;
    uint64 len = rem + start;
    memmove( mBulk + start, mBulk + end, rem );
    mSize = len;
    mBulk[ mSize ] = '\0';
    return  (*this);
}

DString&
DString::Insert( uint64 iPos, const DString& iStr ) {
    // Implemented this way because i'm lazy.
    // Can be optimized.
    return  operator=( std::move( SubString( 0, iPos ).Append( iStr ).Append( SubString( iPos + iStr.Size(), mSize ) ) ) );
}

int64
DString::FindFirst( const DString& iStr ) const {
    return  FindFrom( 0, iStr );
}

int64
DString::FindLast( const DString& iStr ) const {
    int64 result = -1;
    while( 1 ) {
        int64 tmp = FindFrom( result + 1, iStr );
        if( tmp == -1 )
            return  result;
        result = tmp;
    }
}

int64
DString::FindFrom( uint64 iPos, const DString& iStr ) const {
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
DString::ReplaceFirst( const DString& iA, const DString& iB ) {
    int64 index = FindFirst( iA );
    if( index != -1 ) {
        Erase( index, iA.Size() );
        Insert( index, iB );
        return  true;
    }
    return  false;
}

bool
DString::ReplaceLast( const DString& iA, const DString& iB ) {
    int64 index = FindLast( iA );
    if( index != -1 ) {
        Erase( index, iA.Size() );
        Insert( index, iB );
        return  true;
    }
    return  false;
}

bool
DString::ReplaceFrom( uint64 iPos, const DString& iA, const DString& iB ) {
    int64 index = FindFrom( iPos, iA );
    if( index != -1 ) {
        Erase( index, iA.Size() );
        Insert( index, iB );
        return  true;
    }
    return  false;
}

void
DString::ReplaceAll( const DString& iA, const DString& iB ) {
    while( ReplaceFirst( iA, iB ) ) {}
}

// Internal operators
DString&
DString::operator+=( const DString& iOther ) {
    return  Append( iOther );
}

DString&
DString::operator+=( const char_type* iOther ) {
    return  Append( iOther );
}

// Private
void
DString::CleanupBulk() {
    DAMAS_ASSERT( mBulk, "Bad State" );
    delete [] mBulk;
    mBulk = nullptr;
}

void
DString::GrowBulk( uint64 iSize, uint64 iCopyOffset ) {
    uint64 cap = iSize + 1;
    if( cap > mCapacity ) {
        char_type* tmp = new char_type[ cap ];
        memcpy( tmp + iCopyOffset, mBulk, mSize + 1 );
        mCapacity = cap;
        CleanupBulk();
        mBulk = tmp;
    }
}

DString::DString( uint64 iSize )
    : mBulk( new char_type[ iSize + 1 ] )
    , mCapacity( iSize + 1 )
    , mSize( iSize )
{
}

DString
operator+( const DString& iA, const DString& iB ) {
    return  iA.Copy().Append( iB );
}

DString
operator+( const DString& iA, const DString::char_type* iB ) {
    return  iA.Copy().Append( iB );
}

DAMAS_NAMESPACE_END

