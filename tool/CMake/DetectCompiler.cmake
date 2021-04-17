#
#   Damas
#__________________
# @file         DetectCompiler.cmake
# @author       Clement Berthaud
# @brief        CMake utility.
# @copyright    Copyright 2021 Clément BERTHAUD.
# @license      Please refer to LICENSE.md
#
cmake_minimum_required( VERSION 3.11.0 )

if( "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang" )
    set( DAMAS_CLANG 1 )
elseif( "${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" )
    if( "${CMAKE_HOST_SYSTEM_NAME}" STREQUAL "Linux" )
        set( DAMAS_GCC 1 )
    elseif( "${CMAKE_HOST_SYSTEM_NAME}" STREQUAL "Windows" ) #mingw
        set( DAMAS_MINGW 1 )
    endif()
elseif( "${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC" ) #msvc
    set( DAMAS_MSVC 1 )
endif()

