#
#   Damas
#__________________
# @file         DetectVersion.cmake
# @author       Clement Berthaud
# @brief        CMake utility.
# @copyright    Copyright 2021 Clément BERTHAUD.
# @license      Please refer to LICENSE.md
#
cmake_minimum_required( VERSION 3.11.0 )

file( STRINGS "VERSION" Damas_FULL_VERSION )
string( REPLACE "." ";" Damas_VERSION_LIST ${Damas_FULL_VERSION} )
list( GET DAMAS_VERSION_LIST 0 Damas_VERSION_MAJOR )
list( GET DAMAS_VERSION_LIST 1 Damas_VERSION_MINOR )
list( GET DAMAS_VERSION_LIST 2 Damas_VERSION_PATCH )

