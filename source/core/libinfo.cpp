/*
*   Damas
*__________________
* @file         libinfo.cpp
* @author       Clement Berthaud
* @brief        This file contains the definition of the libinfo tools.
* @copyright    Copyright 2021 Clément Berthaud
* @license      Please refer to LICENSE.md
*/
#include "core/libinfo.hpp"

DAMAS_NAMESPACE_BEGIN
//static
std::string
DLibInfo::VersionString()
{
    return  VersionEpochString() + "." + VersionMinorString() + "." + VersionPatchString();
}

//static
std::string
DLibInfo::VersionEpochString()
{
    return  std::string( DAMAS_VERSION_EPOCH_STR );
}

//static
std::string
DLibInfo::VersionMinorString()
{
    return  std::string( DAMAS_VERSION_MINOR_STR );
}

//static
std::string
DLibInfo::VersionPatchString()
{
    return  std::string( DAMAS_VERSION_PATCH_STR );
}

//static
uint64
DLibInfo::VersionEpoch()
{
    return  DAMAS_VERSION_EPOCH;
}

//static
uint64
DLibInfo::VersionMinor()
{
    return  DAMAS_VERSION_MINOR;
}

//static
uint64
DLibInfo::VersionPatch()
{
    return  DAMAS_VERSION_PATCH;
}

//static
std::string
DLibInfo::ConfigurationString()
{
#if defined( DAMAS_DEBUG )
    return  std::string( "Debug" );
#elif defined( DAMAS_RELEASE )
    return  std::string( "Release" );
#elif defined( DAMAS_RELWITHDEBINFO )
    return  std::string( "RelWithDebInfo" );
#endif
}

//static
std::string
DLibInfo::CompilationTimeString()
{
    return  std::string( __DATE__ ) + ", " + std::string( __TIME__ );
}

//static
std::string
DLibInfo::CompilerNameString()
{
#if defined( DAMAS_CLANG )
    return  std::string( "CLANG" );
#elif defined( DAMAS_GCC )
    return  std::string( "GCC" );
#elif defined( DAMAS_MSVC )
    return  std::string( "MSVC" );
#elif defined( DAMAS_MINGW64 )
    return  std::string( "MINGW64" );
#elif defined( DAMAS_EMSCRIPTEN )
    return  std::string( "EMSCRIPTEN" );
#else
    return  std::string( "UNKNOWN" );
#endif
}

//static
std::string
DLibInfo::CompilerVersionString()
{
#if defined( DAMAS_CLANG )
    return  std::string( DAMAS_STRINGIFY( __clang_major__ ) ) + "." + DAMAS_STRINGIFY( __clang_minor__ ) + "." + DAMAS_STRINGIFY( __clang_patchlevel__ );
#elif defined( DAMAS_GCC )
    return  std::string( DAMAS_STRINGIFY( __GNUC__ ) ) + "." + DAMAS_STRINGIFY( __GNUC_MINOR__ );
#elif defined( DAMAS_MSVC )
    return  std::string( DAMAS_STRINGIFY( _MSC_VER ) );
#elif defined( DAMAS_MINGW64 )
    return  std::string( DAMAS_STRINGIFY( __MINGW64_VERSION_EPOCH ) ) + "." + DAMAS_STRINGIFY( __MINGW64_VERSION_MINOR );
#else
    return  std::string( "" );
#endif
}

//static
std::string
DLibInfo::CompilerInformationString()
{
    return  CompilerNameString() + " " + CompilerVersionString();
}

//static
bool
DLibInfo::CompiledForx64()
{
    // We just assume this to be always true for now.
    // Compilation for 32 bits should fail anyways.
    return  true;
}

//static
bool
DLibInfo::CompiledWithAVX2()
{
#ifdef DAMAS_COMPILETIME_AVX_SUPPORT
    return  true;
#else
    return  false;
#endif
}

//static
bool
DLibInfo::CompiledWithSSE42()
{
#ifdef DAMAS_COMPILETIME_SSE_SUPPORT
    return  true;
#else
    return  false;
#endif
}

//static
bool
DLibInfo::BuiltAsSharedLibrary()
{
#ifdef DAMAS_BUILT_AS_SHARED_LIBRARY
    return  true;
#else
    return  false;
#endif
}

//static
std::string
DLibInfo::BranchNameString()
{
    return  std::string( DAMAS_GIT_BRANCH_NAME_STR );
}

//static
std::string
DLibInfo::CommitHashString()
{
    return  std::string( DAMAS_GIT_COMMIT_HASH_STR );
}

//static
std::string
DLibInfo::CommitAbbreviatedHashString()
{
    return  std::string( DAMAS_GIT_COMMIT_ABBREVIATED_HASH_STR );
}

//static
std::string
DLibInfo::LibraryInformationString()
{
    std::string on( "on" );
    std::string off( "off" );
    std::string sse = CompiledWithSSE42() ? on : off;
    std::string avx = CompiledWithAVX2() ?  on : off;
    // 4.0.0 (Aug 15 2020, 15:12:04) [MSVC v.1916 x64] {Release}
    return  ConfigurationString() + " " + VersionString() + " "
            + "(" + BranchNameString() + ":" + CommitAbbreviatedHashString() + ", " + CompilationTimeString() + ") "
            + "[" + CompilerInformationString() + " x64] "
            + "{SSE4.2:" + sse + ", AVX2:" + avx + "};";
}

DAMAS_NAMESPACE_END

