/*
*   Damas
*__________________
* @file         libinfo.hpp
* @author       Clement Berthaud
* @brief        This file contains the declaration of the libinfo tools.
* @copyright    Copyright 2021 Clément Berthaud
* @license      Please refer to LICENSE.md
*/
#pragma once
#include "core/core.hpp"
#include <string>

DAMAS_NAMESPACE_BEGIN
/// @class      DLibInfo
/// @brief      The DLibInfo class provides a mean to access information
///             about the library.
/// @details    DLibInfo allows the user to query informations such as
///             the version of the library, the branch or commit it was
///             compiled from, as well as other informations such as the
///             compiler that was used and its version.
class DAMAS_API DLibInfo
{
private:
    ~DLibInfo() = delete;
    DLibInfo() = delete;
    DLibInfo( const DLibInfo& ) = delete;
    DLibInfo( DLibInfo&& ) = delete;

public:
    /*! Retrieve the full version string "major.minor.patch". */
    static std::string VersionString();

    /*! Retrieve the major version string. */
    static std::string VersionEpochString();

    /*! Retrieve the minor version string. */
    static std::string VersionMinorString();

    /*! Retrieve the patch version string. */
    static std::string VersionPatchString();

    /*! Retrieve the major version number. */
    static uint64 VersionEpoch();

    /*! Retrieve the minor version number. */
    static uint64 VersionMinor();

    /*! Retrieve the patch version number. */
    static uint64 VersionPatch();

    /*! Retrieve the built configuration ( Debug, Release, RelWithDebInfo ). */
    static std::string ConfigurationString();

    /*! Retrieve the compilation date and time e.g: "Aug 15 2020, 15:12:04". */
    static std::string CompilationTimeString();

    /*! Retrieve the compiler name string */
    static std::string CompilerNameString();

    /*! Retrieve the compiler version string */
    static std::string CompilerVersionString();

    /*! Retrieve the full information string */
    static std::string CompilerInformationString();

    /*! Retrieve wether the library was compiled for x64 target */
    static bool CompiledForx64();

    /*! Retrieve wether the library was compiled with AVX2 support */
    static bool CompiledWithAVX2();

    /*! Retrieve wether the library was compiled with SSE42 support */
    static bool CompiledWithSSE42();

    /*! Retrieve wether the library was built as a shared library ( true: shared, false: static ). */
    static bool BuiltAsSharedLibrary();

    /*! Retrieve the git branch from where it was compiled if available */
    static std::string BranchNameString();

    /*! Retrieve the git commit hash from where it was compiled if available */
    static std::string CommitHashString();

    /*! Retrieve the git commit hash from where it was compiled if available */
    static std::string CommitAbbreviatedHashString();

    /*! Retrieve the full library identification string */
    static std::string LibraryInformationString();
};

DAMAS_NAMESPACE_END

