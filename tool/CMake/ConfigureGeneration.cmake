#
#   Damas
#__________________
# @file         ConfigureGeneration.cmake
# @author       Clement Berthaud
# @brief        CMake utility.
# @copyright    Copyright 2021 Clément BERTHAUD.
# @license      Please refer to LICENSE.md
#
cmake_minimum_required( VERSION 3.11.0 )

set( CMAKE_CONFIGURATION_TYPES RelWithDebInfo Debug Release CACHE STRING INTERNAL FORCE )
set( CMAKE_DEBUG_POSTFIX d )
set( CMAKE_SUPPRESS_REGENERATION true )
set( CMAKE_SKIP_INSTALL_ALL_DEPENDENCY true )
set( CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} -D DAMAS_FORCE_ASSERT -D DAMAS_RELWITHDEBINFO" )
set_property( GLOBAL PROPERTY USE_FOLDERS ON )

