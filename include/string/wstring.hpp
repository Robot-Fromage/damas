/*
*   Damas
*__________________
* @file         wstring.hpp
* @author       Clement Berthaud
* @brief        This file provides the declaration for the DWString class.
* @copyright    Copyright 2021 Clément Berthaud
* @license      Please refer to LICENSE.md
*/
#pragma once
#include "core/core.hpp"
#include "memory/array.hpp"

DAMAS_NAMESPACE_BEGIN
class DString;

/// @class      DWString
/// @brief      The DWString class provides a simple dynamic string class
/// @details    The need of a custom DWString class rose from the fact that std::
///             classes cannot be exported easily accross dll boundaries when
///             Damas is compiled as a shared library.
///
///             \sa DString
class DAMAS_API DWString
{
public:
    typedef wchar_t char_type;

public:
    /* Destructor. */
    ~DWString();

    /* Default constructor. */
    DWString();

    /* Constructor from C string. */
    DWString( const char_type* iStr );

    /* Copy constructor. */
    DWString( const DWString& iStr );

    /* Move constructor. */
    DWString( DWString&& iStr );

    /* Conversion constructor from WString. */
    DWString( const DString& iWStr );

    /* Copy assignment operator. */
    DWString& operator=( const DWString& iStr );

    /* Move assignment operator. */
    DWString& operator=( DWString&& iStr );

    /* Request explicit copy of string */
    DWString Copy() const;

    /* Request substring of string */
    DWString SubString( uint64 iPos, uint64 iCount ) const;

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
    DString ToString() const;

    /*! Append a string. */
    DWString& Append( const DWString& iStr );

    /*! Append a string. */
    DWString& Append( const char_type* iStr );

    /*! Append a char. */
    DWString& Append( char_type iChar );

    /*! Prepend a string. */
    DWString& Prepend( const DWString& iStr );

    /*! Prepend a string. */
    DWString& Prepend( const char_type* iStr );

    /*! Prepend a char. */
    DWString& Prepend( char_type iChar );

    /* Equality operator */
    bool operator==( const DWString& iOther );

    /* Inequality operator */
    bool operator!=( const DWString& iOther );

    /* To Int */
    int ToInt() const;

    /* To Unsigned Int */
    unsigned int ToUnsignedInt() const;

    /* To Float */
    float ToFloat() const;

    /* To Double */
    double ToDouble() const;

    /* Static Maker from Int */
    static DWString FromInt( int iValue );

    /* Static Maker from Unsigned Int */
    static DWString FromUnsignedInt( unsigned int iValue );

    /* Static Maker from Float */
    static DWString FromFloat( float iValue );

    /* Static Maker from Double */
    static DWString FromDouble( double iValue );

    /* Static Maker from WString */
    static DWString FromString( const DString& iValue );

    /* Transform in place to uppercase */
    DWString& TransformUpperCase();

    /* Transform in place to lowercase */
    DWString& TransformLowerCase();

    /* Conversion to uppercase */
    DWString ToUpper() const;

    /* Conversion to lowercase */
    DWString ToLower() const;

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
    TArray< DWString > Split( const DWString& iSep ) const;

    /* Erase part of string */
    DWString& Erase( uint64 iPos, uint64 iCount );

    /* Insert part of string */
    DWString& Insert( uint64 iPos, const DWString& iStr );

    /* Find First occurence */
    int64 FindFirst( const DWString& iStr ) const;

    /* Find Last occurence */
    int64 FindLast( const DWString& iStr ) const;

    /* Find occurence starting for position */
    int64 FindFrom( uint64 iPos, const DWString& iStr ) const;

    /* Replace First occurence */
    bool ReplaceFirst( const DWString& iA, const DWString& iB );

    /* Replace Last occurence */
    bool ReplaceLast( const DWString& iA, const DWString& iB );

    /* Replace occurence starting for position */
    bool ReplaceFrom( uint64 iPos, const DWString& iA, const DWString& iB );

    /* Replace all occurences */
    void ReplaceAll( const DWString& iA, const DWString& iB );

private:
    void CleanupBulk();
    void GrowBulk( uint64 iSize, uint64 iCopyOffset = 0 );
    DWString( uint64 iSize );

private:
    char_type* mBulk; ///< The main raw string buffer storage. A pascal string or C string with trailing null termination character.
    uint64 mCapacity; ///< The string capacity, may be bigger than size. The real size of the buffer storage, including the null termination character.
    uint64 mSize; ///< The string usage size, not including the null termination character, althoug other null characters can be inside the usable string.
};

DAMAS_NAMESPACE_END

