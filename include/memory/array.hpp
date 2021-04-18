/*
*   Damas
*__________________
* @file         array.hpp
* @author       Clement Berthaud
* @brief        This file provides the definition for the TArray class.
* @copyright    Copyright 2021 Cl�ment Berthaud
* @license      Please refer to LICENSE.md
*/
#pragma once
#include "core/core.hpp"
#include "memory/memory.hpp"
#include "math/math.hpp"

DAMAS_NAMESPACE_BEGIN
/////////////////////////////////////////////////////
/// @class      TArray
/// @brief      The TArray class provides a simple dynamic array or vector
///             class for Damas interfaces.
/// @details    The need of a custom TArray class rose from the fact that std::
///             classes cannot be exported easily accross dll boundaries when
///             Damas is compiled as a shared library.
template< typename T >
class TArray
{
public:
    /*! Destroy the Array and cleanup memory. */
    ~TArray< T >()
    {
        CleanupBulk();
    }

    /*! Default constructor with size 0, capicity 0, uninitialized. */
    TArray< T >()
        : mBulk( nullptr )
        , mCapacity( 0 )
        , mSize( 0 )
    {}

    /*!
        Constructor with known size, both capacity and size will match the requested size.
        The array will have a size of iSize and the elements are default constructed.
    */
    TArray< T >( uint64 iSize )
        : mBulk( nullptr )
        , mCapacity( iSize )
        , mSize( iSize )
    {
        if( iSize > 0 ) {
            mBulk = reinterpret_cast< T* >( XMalloc( sizeof( T ) * iSize ) );
            for( uint64 i = 0; i < mSize; ++i ) {
                new  ( mBulk + i )  T;
            }
        }
    }

    /*! Copy constructor, explicitly removed. */
    TArray< T >( const TArray< T >& iOther ) = delete;

    /*! Copy Assignment Operator, explicitly removed. */
    TArray< T >& operator=( const TArray< T >& iOther ) = delete;

    /*! Move Assignment Operator, explicitly removed. */
    TArray< T >& operator=( TArray< T >&& iOther ) = delete;

    /*!
        Move constructor.
        The first object is left in a valid but empty state.
        The second object steals the buffer and the state ( size and capacity ).
    */
    TArray< T >( TArray< T >&& iOther )
        : mBulk( iOther.mBulk )
        , mCapacity( iOther.mCapacity )
        , mSize( iOther.mSize )
    {
        iOther.mBulk = nullptr;
        iOther.mSize = 0;
        iOther.mCapacity = 0;
    }

    /*! Returns the raw bits. */
    uint8* Bits() {
        return  reinterpret_cast< uint8* >( mBulk );
    }

    /*! Returns the const raw bits. */
    const uint8* Bits() const {
        return  reinterpret_cast< const uint8* >( mBulk );
    }

    /*! Returns the storage. */
    T* Data() {
        return  mBulk;
    }

    /*! Returns the const storage. */
    const T* Data() const {
        return  mBulk;
    }

    /*!
        Access component at index.
        The behaviour is undefined if the array has no size.
        The behaviour is undefined if the index is greater than the size.
        The behaviour is undefined if the underlying buffer is NULL, which
        indicates a corrupted states anyway.
    */
    T& operator[]( uint64 iIndex ) {
        DAMAS_ASSERT( mSize > 0, "Bad call, array is empty" );
        DAMAS_ASSERT( iIndex < mSize, "Bad Index" );
        DAMAS_ASSERT( mBulk != nullptr, "Error, no bulk, array is uninitialized" );
        return  mBulk[ iIndex ];
    }

    /*!
        Access const component at index.
        The behaviour is undefined if the array has no size.
        The behaviour is undefined if the index is greater than the size.
        The behaviour is undefined if the underlying buffer is NULL, which
        indicates a corrupted states anyway.
    */
    const T& operator[]( uint64 iIndex ) const {
        DAMAS_ASSERT( mSize > 0, "Bad call, array is empty" );
        DAMAS_ASSERT( iIndex < mSize, "Bad Index" );
        DAMAS_ASSERT( mBulk != nullptr, "Error, no bulk, array is uninitialized" );
        return  mBulk[ iIndex ];
    }

    /*!
        Access component at index. Alias of operator[]()

        \sa operator[]()
    */
    T& At( uint64 iIndex ) {
        DAMAS_ASSERT( mSize > 0, "Bad call, array is empty" );
        DAMAS_ASSERT( iIndex < mSize, "Bad Index" );
        DAMAS_ASSERT( mBulk != nullptr, "Error, no bulk, array is uninitialized" );
        return  mBulk[ iIndex ];
    }

    /*!
        Access component at index. Alias of operator[]()

        \sa operator[]() const
    */
    const T& At( uint64 iIndex ) const {
        DAMAS_ASSERT( mSize > 0, "Bad call, array is empty" );
        DAMAS_ASSERT( iIndex < mSize, "Bad Index" );
        DAMAS_ASSERT( mBulk != nullptr, "Error, no bulk, array is uninitialized" );
        return  mBulk[ iIndex ];
    }

    /*!
        Access component at front.
        The behaviour is undefined if the array is empty.
    */
    T& Front() {
        DAMAS_ASSERT( mSize > 0, "Bad call, array is empty" );
        return  At( 0 );
    }

    /*!
        Access const component at front.
        The behaviour is undefined if the array is empty.
    */
    const T& Front() const {
        DAMAS_ASSERT( mSize > 0, "Bad call, array is empty" );
        return  At( 0 );
    }

    /*!
        Access component at back.
        The behaviour is undefined if the array is empty.
    */
    T& Back() {
        DAMAS_ASSERT( mSize > 0, "Bad call, array is empty" );
        return  At( mSize - 1 );
    }

    /*!
        Access const component at back.
        The behaviour is undefined if the array is empty.
    */
    const T& Back() const {
        DAMAS_ASSERT( mSize > 0, "Bad call, array is empty" );
        return  At( mSize - 1 );
    }

    /*! Returns wether the array is empty or not. */
    bool IsEmpty() const {
        return  mSize == 0;
    }

    /*! Returns the array capacity. */
    uint64 Capacity() const {
        return  mCapacity;
    }

    /*! Returns the array size. */
    uint64 Size() const {
        return  mSize;
    }

    /*!
        Reserve some capacity for future usage, if iCapacity is bigger than the
        current capacity.

        If iCapacity is lower or equal to capacity, this function does nothing.

        This function might invalid existing pointers to the underlying buffer.

        The size doesn't change.
    */
    void Reserve( uint64 iCapacity ) {
        // Only if requested a bigger capacity
        if( iCapacity > mCapacity )
            ReallocBulk( iCapacity );
    }

    /*!
        Shrink the capacity to fit the size.
        If the capacity is already the same as the size, the function does
        nothing.
        This function might invalid the underlying buffer.
        The size doesn't change.
    */
    void Shrink() {
        // Only if capacity is bigger than size
        if( mCapacity > mSize )
            ReallocBulk( mSize );
    }

    /*!
        Resize the actual usage size of the container.
        This function might invalid the underlying buffer when requesting a bigger size.
        It has no effect if the requested size is the same as the current size.
    */
    void Resize( uint64 iSize ) {
        // If requested size equal to size, do nothing.
        if( iSize == mSize ) {
            // The buffer references remain valid.
            return;
        }

        // If request size 0, do a clear.
        if( iSize == 0 ) {
            // The buffer references become invalid.
            Clear();
            return;
        }

        // If there is enough capacity, no realloc is needed
        if( mCapacity >= iSize ) {
            // If the requested size is smaller, we just need to destroy the extras
            for( uint64 i = iSize; i < mSize; ++i )
                mBulk[ i ].~T();

            // If the requested size is bigger, we just need to create the extras
            for( uint64 i = mSize; i < iSize; ++i )
                new  ( mBulk + i )  T;

            // Set new size, capacity is untouched, the buffer references remain valid.
            mSize = iSize;
            return;
        }

        // Last case: there is not enough capacity and the requested size is bigger
        // Realloc bulk
        ReallocBulk( iSize );
        // Create the extras
        for( uint64 i = mSize; i < iSize; ++i )
            new  ( mBulk + i )  T;
        // Save new size.
        mSize = iSize;
    }

    /*!
        Clear the array, deallocating everything.
    */
    void Clear() {
        CleanupBulk();
    }

    /*!
        PopBack, remove last element.
        Behaviour is undefined if the array is empty.
    */
    void PopBack() {
        DAMAS_ASSERT( mSize > 0, "Bad call, array is empty" );
        DAMAS_ASSERT( mBulk != nullptr, "Error, no bulk, array is uninitialized" );
        mBulk[ ( --mSize ) ].~T();
    }

    /*!
        PushBack, insert a new element at the end of the buffer, possibly
        reallocating the underlying storage if the capacity has been reached.
    */
    void PushBack( const T& iValue = T() ) {
        CheckGrowBulk();
        new  ( mBulk + ( mSize++ ) )  T( iValue );
    }

    /*!
        PushBack, insert a new element at the end of the buffer, possibly
        reallocating the underlying storage if the capacity has been reached.
    */
    void PushBack( T&& iValue ) {
        CheckGrowBulk();
        new  ( mBulk + ( mSize++ ) )  T( std::forward< T >( iValue ) );
    }

    /*!
        EmplaceBack, emplace a new element at the end of the buffer, possibly
        reallocating the underlying storage if the capacity has been reached.
    */
    template< class ... Args >
    void EmplaceBack( Args&& ... args ) {
        CheckGrowBulk();
        new  ( mBulk + ( mSize++ ) )  T( std::forward< Args >( args ) ... );
    }

    /*!
        Insert, insert a new element at pos in the buffer, possibly
        reallocating the underlying storage if the capacity has been reached.
    */
    void Insert( uint64 iPos, const T& iValue ) {
        DAMAS_ASSERT( iPos < mSize, "Bad Index" );
        CheckGrowBulk();
        memmove( mBulk + iPos + 1, mBulk + iPos, mSize - iPos );
        new  ( mBulk + iPos )  T( iValue );
        mSize++;
    }

    /*!
        Insert, insert a new element at pos in the buffer, possibly
        reallocating the underlying storage if the capacity has been reached.
    */
    void Insert( uint64 iPos, T&& iValue ) {
        DAMAS_ASSERT( iPos < mSize, "Bad Index" );
        CheckGrowBulk();
        memmove( mBulk + iPos + 1, mBulk + iPos, mSize - iPos );
        new  ( mBulk + iPos )  T( std::forward< T >( iValue ) );
        mSize++;
    }

    /*!
        Emplace, emplace a new element at pos in the buffer, possibly
        reallocating the underlying storage if the capacity has been reached.
    */
    template< class ... Args >
    void Emplace( uint64 iPos, Args&& ... args ) {
        DAMAS_ASSERT( iPos < mSize, "Bad Index" );
        CheckGrowBulk();
        memmove( mBulk + iPos + 1, mBulk + iPos, mSize - iPos );
        new  ( mBulk + iPos )  T( std::forward< Args >(args) ... );
        mSize++;
    }

    /*!
        Insert, insert count new elements at pos in the buffer, possibly
        reallocating the underlying storage if the capacity has been reached.
    */
    void Insert( uint64 iPos, uint64 iCount, const T& iValue ) {
        DAMAS_ASSERT( iPos < mSize, "Bad Index" );
        Reserve( mSize + iCount );
        memmove( mBulk + iPos + iCount, mBulk + iPos, mSize - iPos );
        for( uint64 i = iPos; i < iPos + iCount; ++i )
            new  ( mBulk + i )  T( iValue );
        mSize += iCount;
    }

    /*!
        Erase elements at pos in the array.
        Behaviour is undefined if the array is empty.
    */
    void Erase( uint64 iPos, uint64 iCount = 1 ) {
        DAMAS_ASSERT( iPos + iCount <= mSize, "Bad arguments" );
        for( uint64 i = iPos; i < iPos + iCount; ++i )
            mBulk[i].~T();
        memmove( mBulk + iPos, mBulk + iPos + iCount, mSize - ( iPos + iCount ) );
        mSize -= iCount;
    }

    /*!
        Erase first found element, if found in the array.
        Behaviour is undefined if the array is empty.
        Does nothing if such element is not in the array.
    */
    void Erase( const T& iElement ) {
        DAMAS_ASSERT( mSize, "Bad arguments" );
        for( uint64 i = 0; i < mSize; ++i ) {
            if( mBulk[i] == iElement ) {
                Erase( i );
                return;
            }
        }
    }

private:
    /*!
        CleanupBulk explicitly calls destructors on elements to be removed, then
        deallocates the underlying bulk buffer and sets mBulk to nullptr.
    */
    void CleanupBulk() {
        if( mBulk != nullptr ) {
            for( uint64 i = 0; i < mSize; ++i ) {
                mBulk[i].~T();
            }
            XFree( mBulk );
            mBulk = nullptr;
        }
        mCapacity = 0;
        mSize = 0;
    }

    /*!
        Realloc bulk explicitly resize the bulk and performs a copy of what was
        previously there if any.
    */
    void ReallocBulk( uint64 iCapacity ) {
        // Allocate new bulk with new capacity.
        T* new_bulk = reinterpret_cast< T* >( XMalloc( sizeof( T ) * iCapacity ) );
        // If the old bulk was already initialized beforehand
        if( mBulk != nullptr ) {
            // Copy the old bulk in the new bulk, for the range the size.
            // What is outside the bounds of the size is left uninitialized
            memcpy( new_bulk, mBulk, sizeof( T ) * mSize );
            // Free the old bulk.
            XFree( mBulk );
        }
        // Point on the new allocation
        mBulk = new_bulk;
        // Save new capacity.
        mCapacity = iCapacity;
    }

    /*!
        Call Realloc bulk with ratio increment if needed.
    */
    void CheckGrowBulk() {
        if( mSize == mCapacity )
            ReallocBulk( DMath::Max( uint64(1), static_cast< uint64 >( DMath::Ceil( mCapacity * DMath::kGoldenRatio ) ) ) );
    }

private:
    T* mBulk; ///< The main buffer storage.
    uint64 mCapacity; ///< The array capacity, may be bigger than size.
    uint64 mSize; ///< The array usage size.
};

DAMAS_NAMESPACE_END

