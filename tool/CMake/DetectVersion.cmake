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

file( STRINGS "VERSION" DAMAS_FULL_VERSION )
string( REPLACE "." ";" DAMAS_VERSION_LIST ${DAMAS_FULL_VERSION} )
list( GET DAMAS_VERSION_LIST 0 DAMAS_VERSION_EPOCH )
list( GET DAMAS_VERSION_LIST 1 DAMAS_VERSION_MINOR )
list( GET DAMAS_VERSION_LIST 2 DAMAS_VERSION_PATCH )

