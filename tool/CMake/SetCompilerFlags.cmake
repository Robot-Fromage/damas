#
#   Damas
#__________________
# @file         SetCompilerFlags.cmake
# @author       Clement Berthaud
# @brief        CMake utility.
# @copyright    Copyright 2021 Clément BERTHAUD.
# @license      Please refer to LICENSE.md
#
cmake_minimum_required( VERSION 3.11.0 )

# Clang
if( ${DAMAS_CLANG} )
    set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -msse4.2 -mavx2 -mfma" )
    # Disable C++ exceptions.
    string( REGEX REPLACE "-fexceptions" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}" )
    set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-exceptions" )
    # Disable RTTI.
    string( REGEX REPLACE "-frtti" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}" )
    set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-rtti" )
endif()

# GCC
if( ${DAMAS_GCC} )
    set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -msse -msse4.2 -mavx -mavx2 -mfma -fabi-version=0 -W -pthread" )
    # Disable C++ exceptions.
    string( REGEX REPLACE "-fexceptions" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}" )
    set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-exceptions" )
    # Disable RTTI.
    string( REGEX REPLACE "-frtti" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}" )
    set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-rtti" )
endif()

# MinGW
if( ${DAMAS_MINGW} )
    set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -msse -msse4.2 -mavx -mavx2 -mfma -fabi-version=0 -W" )
    # Disable C++ exceptions.
    string( REGEX REPLACE "-fexceptions" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}" )
    set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-exceptions" )
    # Disable RTTI.
    string( REGEX REPLACE "-frtti" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}" )
    set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-rtti" )
endif()

# MSVC
if( ${DAMAS_MSVC} )
    set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHsc -D__SSE4_2__ -D__AVX2__" )
    set( CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Z7 -MP -Od -MDd" )
    # Disable C++ exceptions.
    string( REGEX REPLACE "/EH[a-z]+" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}" )
    set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHs-c-" )
    add_definitions( -D_HAS_EXCEPTIONS=0 )
    # Disable RTTI.
    string( REGEX REPLACE "/GR" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}" )
    set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /GR-" )
endif()

