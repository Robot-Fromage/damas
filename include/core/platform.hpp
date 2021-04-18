/*
*   Damas
*__________________
* @file         platform.hpp
* @author       Clement Berthaud
* @brief        This file contains core platform definitions.
* @copyright    Copyright 2021 Clément Berthaud
* @license      Please refer to LICENSE.md
*/
#pragma once
#include <iostream>

/////////////////////////////////////////////////////
// Macros detect info
#ifdef  DAMAS_DEF_VERSION_EPOCH
#define DAMAS_VERSION_EPOCH DAMAS_DEF_VERSION_EPOCH
#else
#define DAMAS_VERSION_EPOCH 0
#endif //  DAMAS_DEF_VERSION_EPOCH

#ifdef  DAMAS_DEF_VERSION_MINOR
#define DAMAS_VERSION_MINOR DAMAS_DEF_VERSION_MINOR
#else
#define DAMAS_VERSION_MINOR 0
#endif //  DAMAS_DEF_VERSION_MINOR

#ifdef  DAMAS_DEF_VERSION_PATCH
#define DAMAS_VERSION_PATCH DAMAS_DEF_VERSION_PATCH
#else
#define DAMAS_VERSION_PATCH 0
#endif //  DAMAS_DEF_VERSION_PATCH

#ifdef  DAMAS_DEF_GIT_COMMIT_HASH
#define DAMAS_GIT_COMMIT_HASH DAMAS_DEF_GIT_COMMIT_HASH
#else
#define DAMAS_GIT_COMMIT_HASH 0
#endif //  DAMAS_DEF_GIT_COMMIT_HASH

#ifdef  DAMAS_DEF_GIT_COMMIT_ABBREVIATED_HASH
#define DAMAS_GIT_COMMIT_ABBREVIATED_HASH DAMAS_DEF_GIT_COMMIT_ABBREVIATED_HASH
#else
#define DAMAS_GIT_COMMIT_ABBREVIATED_HASH 0
#endif //  DAMAS_DEF_GIT_COMMIT_ABBREVIATED_HASH

#ifdef  DAMAS_DEF_GIT_BRANCH_NAME
#define DAMAS_GIT_BRANCH_NAME DAMAS_DEF_GIT_BRANCH_NAME
#else
#define DAMAS_GIT_BRANCH_NAME 0
#endif //  DAMAS_DEF_GIT_BRANCH_NAME

#define DAMAS_XSTRINGIFY( X ) #X
#define DAMAS_STRINGIFY( X ) DAMAS_XSTRINGIFY( X )
#define DAMAS_VERSION_EPOCH_STR DAMAS_STRINGIFY( DAMAS_VERSION_EPOCH )
#define DAMAS_VERSION_MINOR_STR DAMAS_STRINGIFY( DAMAS_VERSION_MINOR )
#define DAMAS_VERSION_PATCH_STR DAMAS_STRINGIFY( DAMAS_VERSION_PATCH )
#define DAMAS_GIT_COMMIT_HASH_STR                DAMAS_STRINGIFY( DAMAS_GIT_COMMIT_HASH )
#define DAMAS_GIT_COMMIT_ABBREVIATED_HASH_STR    DAMAS_STRINGIFY( DAMAS_GIT_COMMIT_ABBREVIATED_HASH )
#define DAMAS_GIT_BRANCH_NAME_STR                DAMAS_STRINGIFY( DAMAS_GIT_BRANCH_NAME )

/////////////////////////////////////////////////////
// Detect Build Configuration
#ifndef DAMAS_RELWITHDEBINFO
    #ifdef NDEBUG
        #define DAMAS_RELEASE
        #define DAMAS_CONFIGURATION Release
    #else
        #define DAMAS_DEBUG
        #define DAMAS_CONFIGURATION Debug
    #endif
#else
    #define DAMAS_CONFIGURATION RelWithDebInfo
#endif

/////////////////////////////////////////////////////
// Detect Compiler
#if defined(__clang__)
    #define DAMAS_CLANG
    #define DAMAS_COMPILER_NAME CLANG
    #define DAMAS_COMPILER_VERSION __clang_major__.__clang_minor__.__clang_patchlevel__
#elif defined(__GNUC__) || defined(__GNUG__)
    #define DAMAS_GCC
    #define DAMAS_COMPILER_VERSION __GNUC__.__GNUC_MINOR__
#define DAMAS_COMPILER_NAME GCC
#elif defined(_MSC_VER)
    #define DAMAS_MSVC
    #define DAMAS_COMPILER_NAME MSVC
    #define DAMAS_COMPILER_VERSION _MSC_VER
#elif defined(__MINGW64__)
    #define DAMAS_MINGW64
    #define DAMAS_COMPILER_NAME MINGW64
    #define DAMAS_COMPILER_VERSION __MINGW64_VERSION_MAJOR.__MINGW64_VERSION_MINOR
#else
    #define DAMAS_UNKNOWN_COMPILER
    #define DAMAS_COMPILER_NAME UNKNOWN
    #define DAMAS_COMPILER_VERSION 0
#endif

/////////////////////////////////////////////////////
// Disable CRT Secure non standard msvc versions of functions such as strcpy_s
#ifdef _MSC_VER
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif // !_CRT_SECURE_NO_WARNINGS
#endif

/////////////////////////////////////////////////////
// Detect Platform
#ifdef __EMSCRIPTEN__
    #define DAMAS_EMSCRIPTEN
#else
    #ifdef _WIN32
        #define DAMAS_WIN
       #ifdef _WIN64
          #define DAMAS_WIN64
          #define DAMAS_PLATFORM_NAME WIN64
       #else
          #define DAMAS_WIN32
          #define DAMAS_PLATFORM_NAME WIN32
       #endif
    #elif __APPLE__
        #include "TargetConditionals.h"
        #if TARGET_IPHONE_SIMULATOR
             #define DAMAS_IOS_SIMULATOR
             #define DAMAS_PLATFORM_NAME IOS_SIMULATOR
        #elif TARGET_OS_IPHONE
             #define DAMAS_IOS_DEVICE
             #define DAMAS_PLATFORM_NAME IOS_DEVICE
        #elif TARGET_OS_MAC
            #define DAMAS_MACOS
             #define DAMAS_PLATFORM_NAME MACOS
        #else
             #error "Unknown Apple platform"
             #define DAMAS_PLATFORM_NAME UNKNOWN
        #endif
    #elif __linux__
        #define DAMAS_LINUX
        #define DAMAS_PLATFORM_NAME LINUX
    #elif __unix__
        #define DAMAS_UNIX
        #define DAMAS_PLATFORM_NAME UNIX
    #elif defined(_POSIX_VERSION)
        #define DAMAS_POSIX
        #define DAMAS_PLATFORM_NAME POSIX
    #else
        #error "Unknown Platform"
        #define DAMAS_PLATFORM_NAME UNKNOWN
    #endif
#endif

/////////////////////////////////////////////////////
// Disable thread and SIMD for Emscripten target
#ifdef DAMAS_EMSCRIPTEN
#define DAMAS_NO_THREAD_SUPPORT
#define DAMAS_NO_SIMD_SUPPORT
#endif

/////////////////////////////////////////////////////
// Force Inline Utility
#define DAMAS_ENABLE_FORCEINLINE
#define DAMAS_ENABLE_VECTORCALL
#define DAMAS_ENABLE_RESTRICT

#ifdef DAMAS_ENABLE_FORCEINLINE
    #if defined(__clang__)
    #define DAMAS_FORCEINLINE inline __attribute__ ((always_inline))
    #elif defined(__GNUC__) || defined(__GNUG__)
    #define DAMAS_FORCEINLINE inline __attribute__ ((always_inline))
    #elif defined(_MSC_VER)
    #define DAMAS_FORCEINLINE __forceinline
    #else
    #define DAMAS_FORCEINLINE inline
    #endif
#else
    #define DAMAS_FORCEINLINE inline
#endif // DAMAS_ENABLE_FORCEINLINE

#ifdef DAMAS_ENABLE_VECTORCALL
    #if defined(__clang__)
    #define DAMAS_VECTORCALL __vectorcall
    #elif defined(__GNUC__) || defined(__GNUG__)
    #define DAMAS_VECTORCALL
    #elif defined(_MSC_VER)
    #define DAMAS_VECTORCALL __vectorcall
    #else
    #define DAMAS_VECTORCALL __vectorcall
    #endif
#else
    #define DAMAS_VECTORCALL
#endif // DAMAS_ENABLE_FORCEINLINE

#ifdef DAMAS_ENABLE_RESTRICT
    #if defined(__clang__)
    #define DAMAS_RESTRICT __restrict
    #elif defined(__GNUC__) || defined(__GNUG__)
    #define DAMAS_RESTRICT __restrict
    #elif defined(_MSC_VER)
    #define DAMAS_RESTRICT __restrict
    #else
    #define DAMAS_RESTRICT __restrict
    #endif
#else
    #define DAMAS_RESTRICT
#endif // DAMAS_ENABLE_RESTRICT

/////////////////////////////////////////////////////
// Export utility macros
#ifdef DAMAS_WIN
    #ifdef DAMAS_STATIC_LIBRARY
        #define DAMAS_BUILT_AS_STATIC_LIBRARY
        #define DAMAS_API
    #else
        #ifdef DAMAS_BUILD_SHARED
            #define DAMAS_BUILT_AS_SHARED_LIBRARY
            #define DAMAS_API __declspec( dllexport )
        #else
            #define DAMAS_BUILT_AS_SHARED_LIBRARY
            #define DAMAS_API __declspec( dllimport )
        #endif
    #endif
#else
    #define DAMAS_API
#endif

/////////////////////////////////////////////////////
// Macros for Thread and SIMD activation, for embeded targets or WASM
#ifndef DAMAS_NO_THREAD_SUPPORT
#define DAMAS_COMPILED_WITH_THREAD_SUPPORT
#endif // !DAMAS_NO_THREAD_SUPPORT

#ifndef DAMAS_NO_SIMD_SUPPORT
#define DAMAS_COMPILED_WITH_SIMD_SUPPORT
#endif // !DAMAS_NO_SIMD_SUPPORT

#ifndef DAMAS_NO_FILESYSTEM_SUPPORT
#define DAMAS_COMPILED_WITH_FILESYSTEM_SUPPORT
#endif // !DAMAS_NO_SIMD_SUPPORT

/////////////////////////////////////////////////////
// Erors
//#pragma warning(disable : 4251)     // Shut down dll interface warnings.
//#pragma warning(disable : 26812)    // Shut non-class enum warnings.
#pragma warning(disable : 4010)     // Shut single-line comment contains line-continuation character
#pragma warning(disable : 4996)     // Shut CRT SECURE
/////////////////////////////////////////////////////
// Define Namespaces
#define DAMAS_NAMESPACE_NAME        dms
#define DAMAS_NAMESPACE_ENABLED
#ifdef DAMAS_NAMESPACE_ENABLED
#define DAMAS_NAMESPACE_BEGIN       namespace DAMAS_NAMESPACE_NAME {
#define DAMAS_NAMESPACE_END          }
namespace DAMAS_NAMESPACE_NAME       {}
#else
#define DAMAS_NAMESPACE_BEGIN
#define DAMAS_NAMESPACE_END
#endif

/////////////////////////////////////////////////////
// Crash Behaviours
#define DAMAS_CRASH *((volatile int*)0) = 0

/////////////////////////////////////////////////////
// Assert Behaviours

#if defined( DAMAS_DEBUG ) || defined( DAMAS_RELWITHDEBINFO ) || defined( DAMAS_FORCE_ASSERT )
    #define DAMAS_ASSERT( cond, log )  if( !( cond ) ) { std::cout << __FILE__ << " " << __FUNCTION__ << " " << __LINE__ << " " << "Assertion failed: " << log << std::endl; DAMAS_CRASH; }
    #define DAMAS_ASSERT_RETURN_ERROR( cond, log, ret )  if( !( cond ) ) { std::cout << __FILE__ << " " << __FUNCTION__ << " " << __LINE__ << " " << "Assertion failed: " << log << std::endl; DAMAS_CRASH; return  ret; }
    #define DAMAS_ASSERT_ENABLED
#else
    #define DAMAS_ASSERT( cond, log )
    #define DAMAS_ASSERT_RETURN_ERROR( cond, log, ret ) { return  ret; }
#endif

/////////////////////////////////////////////////////
// SIMD PATCH FOR GNU < 9
// CHECK: this conflicts with xcode sometimes identifying itself as GNUC < 9 but defining the appropriate simd instructions.
#ifdef DAMAS_COMPILED_WITH_SIMD_SUPPORT
#if defined( DAMAS_GCC ) && ( defined( DAMAS_WIN ) || defined( DAMAS_LINUX ) )
#if __GNUC__ < 9
// unaligned load and store functions
#define _mm_loadu_si16(p) _mm_cvtsi32_si128(*(unsigned short const*)(p))
#define _mm_storeu_si16(p, a) (void)(*(short*)(p) = (short)_mm_cvtsi128_si32((a)))
#define _mm_loadu_si32(p) _mm_cvtsi32_si128(*(unsigned int const*)(p))
#define _mm_storeu_si32(p, a) (void)(*(int*)(p) = _mm_cvtsi128_si32((a)))
#define _mm_loadu_si64(p) _mm_loadl_epi64((__m128i const*)(p))
#define _mm_storeu_si64(p, a) (_mm_storel_epi64((__m128i*)(p), (a)))
#endif
#endif
#include <immintrin.h>
#endif

/////////////////////////////////////////////////////
// Conditional compile time detection macro in order to decide if we should include SIMD versions in the various dispatch
#ifdef DAMAS_COMPILED_WITH_SIMD_SUPPORT
    #ifdef __AVX2__
        #define DAMAS_COMPILETIME_AVX_SUPPORT
    #endif
    #ifdef __SSE4_2__
        #define DAMAS_COMPILETIME_SSE_SUPPORT
    #endif
#endif

