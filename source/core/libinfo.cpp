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
namespace detail {
static constexpr char* sgVersionString = DAMAS_STRINGIFY( DAMAS_VERSION_EPOCH.DAMAS_VERSION_MINOR.DAMAS_VERSION_PATCH );
static constexpr char* sgVersionEpochString = DAMAS_VERSION_EPOCH_STR;
static constexpr char* sgVersionMinorString = DAMAS_VERSION_MINOR_STR;
static constexpr char* sgVersionPatchString = DAMAS_VERSION_PATCH_STR;
static constexpr char* sgConfigurationString = DAMAS_STRINGIFY( DAMAS_CONFIGURATION );
static constexpr char* sgCompilationTimeString = __DATE__ ", " __TIME__;
static constexpr char* sgCompilerNameString = DAMAS_STRINGIFY( DAMAS_COMPILER_NAME );
static constexpr char* sgCompilerVersionString = DAMAS_STRINGIFY( DAMAS_COMPILER_VERSION );
static constexpr char* sgPlatformNameString = DAMAS_STRINGIFY( DAMAS_PLATFORM_NAME );
static constexpr char* sgCompilerInformationString = DAMAS_STRINGIFY( DAMAS_COMPILER_NAME DAMAS_COMPILER_VERSION );
static constexpr char* sgGitBranchNameString = DAMAS_GIT_BRANCH_NAME_STR;
static constexpr char* sgGitCommitHashString = DAMAS_GIT_COMMIT_HASH_STR;
static constexpr char* sgGitCommitAbbreviatedHashString = DAMAS_GIT_COMMIT_ABBREVIATED_HASH_STR;
} // namespace detail

//static
const char*
DLibInfo::VersionString()
{
    return  detail::sgVersionString;
}

//static
const char*
DLibInfo::VersionEpochString()
{
    return  detail::sgVersionEpochString;
}

//static
const char*
DLibInfo::VersionMinorString()
{
    return  detail::sgVersionMinorString;
}

//static
const char*
DLibInfo::VersionPatchString()
{
    return  detail::sgVersionPatchString;
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
const char*
DLibInfo::ConfigurationString()
{
    return  detail::sgConfigurationString;
}

//static
const char*
DLibInfo::CompilationTimeString()
{
    return  detail::sgCompilationTimeString;
}

//static
const char*
DLibInfo::CompilerNameString()
{
    return  detail::sgCompilerNameString;
}

//static
const char*
DLibInfo::CompilerVersionString()
{
    return  detail::sgCompilerVersionString;
}

//static
const char*
DLibInfo::CompilerInformationString()
{
    return  detail::sgCompilerInformationString;
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

// static
const char*
DLibInfo::PlatformNameString()
{
    return  detail::sgPlatformNameString;
}

//static
const char*
DLibInfo::BranchNameString()
{
    return  detail::sgGitBranchNameString;
}

//static
const char*
DLibInfo::CommitHashString()
{
    return  detail::sgGitCommitHashString;
}

//static
const char*
DLibInfo::CommitAbbreviatedHashString()
{
    return  detail::sgGitCommitAbbreviatedHashString;
}

//static
DString
DLibInfo::LibraryInformationString()
{
    const char* on( "on" );
    const char* off( "off" );
    const char* sse = CompiledWithSSE42() ? on : off;
    const char* avx = CompiledWithAVX2() ?  on : off;
    // 4.0.0 (Aug 15 2020, 15:12:04) [MSVC v.1916 x64] {Release}
    return  DString( ConfigurationString() ) + " " + VersionString() + " "
            + "(" + BranchNameString() + ":" + CommitAbbreviatedHashString() + ", " + CompilationTimeString() + ") "
            + "[" + CompilerInformationString() + " x64] "
            + "{SSE4.2:" + sse + ", AVX2:" + avx + "};";
}

DAMAS_NAMESPACE_END

