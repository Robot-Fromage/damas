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
option( DAMAS_BUILD_SHARED "Build the library as shared or static." ON )

# Setup
message( "Starting environnement setup before generation." )
include( ${CMAKE_CURRENT_SOURCE_DIR}/tool/CMake/ConfigureGeneration.cmake )
include( ${CMAKE_CURRENT_SOURCE_DIR}/tool/CMake/DetectVersion.cmake )
include( ${CMAKE_CURRENT_SOURCE_DIR}/tool/CMake/DetectTimestamp.cmake )
include( ${CMAKE_CURRENT_SOURCE_DIR}/tool/CMake/DetectGit.cmake )

# Functions
include( ${CMAKE_CURRENT_SOURCE_DIR}/tool/CMake/SubdirList.cmake )

# Project
message( "Starting project generation." )
project( Damas${ULIS_VERSION_EPOCH}_Project )
include( ${CMAKE_CURRENT_SOURCE_DIR}/tool/CMake/DetectCompiler.cmake )
include( ${CMAKE_CURRENT_SOURCE_DIR}/tool/CMake/SetCompilerFlags.cmake )

# Library Dependencies
#include( ${CMAKE_CURRENT_SOURCE_DIR}/tool/CMake/FindX.cmake )

# Library
include( ${CMAKE_CURRENT_SOURCE_DIR}/tool/CMake/Library.cmake )

# Interactive interpreter
include( ${CMAKE_CURRENT_SOURCE_DIR}/tool/CMake/Interpreter.cmake )

# Install
include( ${CMAKE_CURRENT_SOURCE_DIR}/tool/CMake/Install.cmake )

