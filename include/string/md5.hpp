/*
*   Damas
*__________________
* @file         md5.hpp
* @author       Clement Berthaud
* @brief        This file provides declaration for MD5 functions and DMD5 class.
* @copyright    Copyright 2021 Clément Berthaud
* @license      Please refer to LICENSE.md
*/
#pragma once
#include "core/core.hpp"

DAMAS_NAMESPACE_BEGIN
/// @class      DMD5
/// @brief      The DMD5 class provides a mean for computation of MD5 hash.
/// @details    Based on reference implementation of RFC 1321.
class DMD5
{
public:
    /// @fn         DMD5()
    /// @brief      Default Constructor.
    /// @details    Calls \e Init, ready to \e Update.
    DMD5();


    /// @fn         DMD5( const std::string& iText )
    /// @brief      Constructor from std::string.
    /// @details    Calls \e Init and computes hash directly, ready to \e Hexdiget.
    /// @param      iText   The text to process.
    DMD5( const std::string& iText );


    /// @fn         DMD5( const uint8* iData, uint32 iLen )
    /// @brief      Constructor from data and length.
    /// @details    Calls \e Init and computes hash directly, ready to \e Hexdiget.
    /// @param      iData   The data to process.
    /// @param      iLen    The length as bytes to process.
    DMD5( const uint8* iData, uint32 iLen );


private:
    /// @fn         Init()
    /// @brief      Initializes the state of the MD5 computer.
    void  Init();


    /// @fn         Transform( const uint8 block[64] )
    /// @brief      The main deterministic transform process.
    /// @details    Called from \e Update.
    void  Transform( const uint8 block[64] );


public:
    /// @fn         Update( const uint8 iBuf[], uint32 iLen )
    /// @brief      Update the data incrementally.
    /// @details    This can be called for the whole data at once, or as split batches, the resulting hash will be the same.
    /// @param      iBuf    The buffer to process.
    /// @param      iLen    The length as bytes of the buffer.
    void  Update( const uint8 iBuf[], uint32 iLen );


    /// @fn         Finalize()
    /// @brief      Finalize the hashing of the data.
    /// @details    This should be called after passing all the buffers to Update.
    /// @return     A reference to this finalized DMD5 object;
    DMD5&  Finalize();


    /// @fn         Hexdigest() const
    /// @brief      Query the Hex Digest as std::string.
    /// @return     A std::string representing the Hex hash.
    std::string  Hexdigest() const;

private:
    static  void  Decode( uint32 oOutput[], const uint8 iInput[], uint32 iLen );
    static  void  Encode( uint8 oOutput[], const uint32 iInput[], uint32 iLen );
    static  inline uint32 F( uint32 x, uint32 y, uint32 z );
    static  inline uint32 G( uint32 x, uint32 y, uint32 z );
    static  inline uint32 H( uint32 x, uint32 y, uint32 z  );
    static  inline uint32 I( uint32 x, uint32 y, uint32 z );
    static  inline uint32 Rotate( uint32 x, int n );
    static  inline void FF( uint32& a, uint32 b, uint32 c, uint32 d, uint32 x, uint32 s, uint32 ac );
    static  inline void GG( uint32& a, uint32 b, uint32 c, uint32 d, uint32 x, uint32 s, uint32 ac );
    static  inline void HH( uint32& a, uint32 b, uint32 c, uint32 d, uint32 x, uint32 s, uint32 ac );
    static  inline void II( uint32& a, uint32 b, uint32 c, uint32 d, uint32 x, uint32 s, uint32 ac );

private:
    bool    mFinalized;
    uint8   mBuffer[64];
    uint32  mCount[2];
    uint32  mState[4];
    uint8   mDigest[16];
};

/////////////////////////////////////////////////////
// Accessibility utility functions
/// @fn         MD5( const std::string iStr )
/// @brief      Shorthand function, computes MD5 for std::string directly
/// @param      iStr    The text to hash.
/// @return     A std::string representing the MD5 hash.
std::string  MD5( const std::string iStr );


/// @fn         MD5( const uint8* iData, int iLen )
/// @brief      Shorthand function, computes MD5 for std::string directly
/// @param      iData   The data to hash.
/// @param      iLen    The size in bytes of the data to hash.
/// @return     A std::string representing the MD5 hash.
std::string  MD5( const uint8* iData, int iLen );

DAMAS_NAMESPACE_END

