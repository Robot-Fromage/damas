#
#   Damas
#__________________
# @file         SubdirList.cmake
# @author       Clement Berthaud
# @brief        CMake utility.
# @copyright    Copyright 2018-2021
# @license      Please refer to LICENSE.md
cmake_minimum_required( VERSION 3.11.0 )

MACRO( SUBDIRLIST result curdir )
    FILE( GLOB children RELATIVE ${curdir} ${curdir}/* )
    SET( dirlist "" )
    FOREACH( child ${children} )
        IF( IS_DIRECTORY ${curdir}/${child} )
            LIST( APPEND dirlist ${child} )
        ENDIF()
    ENDFOREACH()
    SET(${result} ${dirlist})
ENDMACRO()

