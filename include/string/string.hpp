/*
*   Damas
*__________________
* @file         string.hpp
* @author       Clement Berthaud
* @brief        This file provides the declaration for the DString class.
* @copyright    Copyright 2021 Clément Berthaud
* @license      Please refer to LICENSE.md
*/
#pragma once
#include "core/core.hpp"
#include "memory/array.hpp"

DAMAS_NAMESPACE_BEGIN
class DWString;

/// @class      DString
/// @brief      The DString class provides a simple dynamic string class
/// @details    The need of a custom DString class rose from the fact that std::
///             classes cannot be exported easily accross dll boundaries when
///             Damas is compiled as a shared library.
///             \sa DWString
class DAMAS_API DString
{
public:
    typedef char char_type;

public:
    /* Destructor. */
    ~DString();

    /* Default constructor. */
    DString();

    /* Constructor from C string. */
    DString( const char_type* iStr );

    /* Copy constructor. */
    DString( const DString& iStr );

    /* Move constructor. */
    DString( DString&& iStr );

    /* Conversion constructor from WString. */
    DString( const DWString& iWStr );

    /* Copy assignment operator. */
    DString& operator=( const DString& iStr );

    /* Move assignment operator. */
    DString& operator=( DString&& iStr );

    /* Request explicit copy of string */
    DString Copy() const;

    /* Request substring of string */
    DString SubString( uint64 iPos, uint64 iCount ) const;

    /*! Returns the string capacity. */
    uint64 Capacity() const;

    /*! Returns the string size. */
    uint64 Size() const;

    /*! Returns the const raw storage. */
    const char_type* Data() const;

    /*! Access char_type at index. */
    char_type& operator[]( uint64 iIndex );

    /*! Access const char_type at index. */
    const char_type& operator[]( uint64 iIndex ) const;

    /*! Access char_type at index. */
    char_type& At( uint64 iIndex );

    /*! Access const char_type at index. */
    const char_type& At( uint64 iIndex ) const;

    /*! Access char_type at front. */
    char_type& Front();

    /*! Access const char_type at front. */
    const char_type& Front() const;

    /*! Access char_type at back. */
    char_type& Back();

    /*! Access const char_type at back. */
    const char_type& Back() const;

    /*! Convert to WString. */
    DWString ToWString() const;

    /*! Append a string. */
    DString& Append( const DString& iStr );

    /*! Append a string. */
    DString& Append( const char_type* iStr );

    /*! Append a char. */
    DString& Append( char_type iChar );

    /*! Prepend a string. */
    DString& Prepend( const DString& iStr );

    /*! Prepend a string. */
    DString& Prepend( const char_type* iStr );

    /*! Prepend a char. */
    DString& Prepend( char_type iChar );

    /* Equality operator */
    bool operator==( const DString& iOther );

    /* Inequality operator */
    bool operator!=( const DString& iOther );

    /* To Int */
    int ToInt() const;

    /* To Unsigned Int */
    unsigned int ToUnsignedInt() const;

    /* To Float */
    float ToFloat() const;

    /* To Double */
    double ToDouble() const;

    /* Static Maker from Int */
    static DString FromInt( int iValue );

    /* Static Maker from Unsigned Int */
    static DString FromUnsignedInt( unsigned int iValue );

    /* Static Maker from Float */
    static DString FromFloat( float iValue );

    /* Static Maker from Double */
    static DString FromDouble( double iValue );

    /* Static Maker from WString */
    static DString FromWString( const DWString& iValue );

    /* Transform in place to uppercase */
    DString& TransformUpperCase();

    /* Transform in place to lowercase */
    DString& TransformLowerCase();

    /* Conversion to uppercase */
    DString ToUpper() const;

    /* Conversion to lowercase */
    DString ToLower() const;

    /*! Returns wether the array is empty or not. */
    bool IsEmpty() const;

    /*!
        Reserve some capacity for future usage, if iCapacity is bigger than the
        current capacity. If iCapacity is lower or equal to capacity, this
        function does nothing.
        This function might invalid the underlying buffer.
        The size doesn't change.
    */
    void Reserve( uint64 iCapacity );

    /*!
        Shrink the capacity to fit the size.
        If the capacity is already the same as the size, the function does
        nothing.
        This function might invalid the underlying buffer.
        The size doesn't change.
    */
    void Shrink();

    /*!
        Resize the actual usage size of the container.
        This function might invalid the underlying buffer.
    */
    void Resize( uint64 iSize, char_type iChar = char_type() );

    /*! Clear the string, deallocating everything. */
    void Clear();

    /*! Split the string. */
    TArray< DString > Split( const DString& iSep ) const;

    /* Erase part of string */
    DString& Erase( uint64 iPos, uint64 iCount );

    /* Insert part of string */
    DString& Insert( uint64 iPos, const DString& iStr );

    /* Find First occurence */
    int64 FindFirst( const DString& iStr ) const;

    /* Find Last occurence */
    int64 FindLast( const DString& iStr ) const;

    /* Find occurence starting for position */
    int64 FindFrom( uint64 iPos, const DString& iStr ) const;

    /* Replace First occurence */
    bool ReplaceFirst( const DString& iA, const DString& iB );

    /* Replace Last occurence */
    bool ReplaceLast( const DString& iA, const DString& iB );

    /* Replace occurence starting for position */
    bool ReplaceFrom( uint64 iPos, const DString& iA, const DString& iB );

    /* Replace all occurences */
    void ReplaceAll( const DString& iA, const DString& iB );

    /* Operator += */
    DString& operator+=( const DString& iOther );

    /* Operator += */
    DString& operator+=( const char_type* iOther );

private:
    void CleanupBulk();
    void GrowBulk( uint64 iSize, uint64 iCopyOffset = 0 );
    DString( uint64 iSize );

private:
    char_type* mBulk; ///< The main raw string buffer storage. A pascal string or C string with trailing null termination character.
    uint64 mCapacity; ///< The string capacity, may be bigger than size. The real size of the buffer storage, including the null termination character.
    uint64 mSize; ///< The string usage size, not including the null termination character, althoug other null characters can be inside the usable string.
};

DString operator+( const DString& iA, const DString& iB );
DString operator+( const DString& iA, const DString::char_type* iB );

DAMAS_NAMESPACE_END

