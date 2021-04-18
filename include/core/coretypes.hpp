/*
*   Damas
*__________________
* @file         coretypes.hpp
* @author       Clement Berthaud
* @brief        This file defines core types for the Damas library.
* @copyright    Copyright 2021 Clément Berthaud
* @license      Please refer to LICENSE.md
*/
#pragma once
#include "core/platform.hpp"
#include <cstdint>
#include <cstring>
#include <limits>
#include <memory>

DAMAS_NAMESPACE_BEGIN
// Typdefs
typedef  uint8_t    uint8;      ///< 8bit unsigned.
typedef  uint16_t   uint16;     ///< 16bit unsigned.
typedef  uint32_t   uint32;     ///< 32bit unsigned.
typedef  uint64_t   uint64;     ///< 64bit unsigned.
typedef  int8_t     int8;       ///< 8bit signed.
typedef  int16_t    int16;      ///< 16bit signed.
typedef  int32_t    int32;      ///< 32bit signed.
typedef  int64_t    int64;      ///< 64bit signed.
typedef  float      ufloat;     ///< 32bits float in normal range [0;1].
typedef  double     udouble;    ///< 64bits double in normal range [0;1].
typedef  int64      dmsError;   ///< Signed integer errors reports.

// Max
#define DAMAS_UINT16_MAX 0xFFFF
#define DAMAS_UINT64_MAX 0xFFFFFFFFFFFFFFFF
#ifndef FLT_MAX
#define FLT_MAX __FLT_MAX__
#endif
#define DAMAS_FLOAT_MAX FLT_MAX

// Macro for switch enumerators
#define DAMAS_COMP_OP_CASE_DO( _CASE, _ACTION, _E1, _E2, _E3 )              case _CASE: { _ACTION( _CASE, _E1, _E2, _E3 ); break; }
#define DAMAS_SWITCH_FOR_ALL_DO( iValue, _SUBSET, _ACTION, _E1, _E2, _E3 )  switch( iValue ) { _SUBSET( DAMAS_COMP_OP_CASE_DO, _ACTION, _E1, _E2, _E3 ) }

// Macro for all types for template instanciation
#define DAMAS_FOR_ALL_TYPES_DO( X, _E0, _E1, _E2, _E3 )     \
    X( uint8,   _E0, _E1, _E2, _E3 )                        \
    X( uint16,  _E0, _E1, _E2, _E3 )                        \
    X( uint32,  _E0, _E1, _E2, _E3 )                        \
    X( ufloat,  _E0, _E1, _E2, _E3 )                        \
    X( udouble, _E0, _E1, _E2, _E3 )

// dmsError reports
#define DAMAS_SUCCESS                       0
#define DAMAS_WARNING                       -1
#define DAMAS_ERROR                         +1

// enums
enum class eValueCategory : uint8
{
      kLValue = 0
    , kRValue = 1
};

enum class eValueIdentity : uint8
{
      kLiteral = 0
    , kNamed = 1
};

enum class eTypeIdentity : uint8
{
      kPure = 0
    , kComposite = 1
    , kArray = 2
};

DAMAS_NAMESPACE_END

