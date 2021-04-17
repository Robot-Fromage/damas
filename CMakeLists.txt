#
#   Damas
#__________________
# @file         CMakeLists.txt
# @author       Clement Berthaud
# @brief        CMake project generation.
# @copyright    Copyright 2021 Clément BERTHAUD.
# @license      Please refer to LICENSE.md
#
CMake_minimum_required(VERSION 3.11.0)

# Input
option( DAMAS_BUILD_SHARED      "Build the library shared or statically."           ON      )
option( DAMAS_BUILD_EXAMPLES    "Build the library examples."                       OFF     )
option( DAMAS_FORCE_ASSERT      "Build the library with forced assert."             OFF     )
option( DAMAS_USE_NAMESPACE     "Build the library with forced namespace."          OFF     )

# Setup
message( "Starting environnement setup before generation." )
include( ${CMAKE_CURRENT_SOURCE_DIR}/tool/CMake/DetectCompiler.cmake )
include( ${CMAKE_CURRENT_SOURCE_DIR}/tool/CMake/ConfigureGeneration.cmake )
include( ${CMAKE_CURRENT_SOURCE_DIR}/tool/CMake/SetCompilerFlags.cmake )
include( ${CMAKE_CURRENT_SOURCE_DIR}/tool/CMake/DetectVersion.cmake )
include( ${CMAKE_CURRENT_SOURCE_DIR}/tool/CMake/DetectGit.cmake )
include( ${CMAKE_CURRENT_SOURCE_DIR}/tool/CMake/DetectTimestamp.cmake )
include( ${CMAKE_CURRENT_SOURCE_DIR}/tool/CMake/AddLibraryModule.cmake )

# Project
message( "Starting project generation." )
project( Damas${ULIS_VERSION_MAJOR}_Project )

