#
#   Damas
#__________________
# @file         DetectGit.cmake
# @author       Clement Berthaud
# @brief        CMake utility.
# @copyright    Copyright 2021 Clément BERTHAUD.
# @license      Please refer to LICENSE.md
#
cmake_minimum_required( VERSION 3.11.0 )

execute_process(
    COMMAND git log -1 --format=%H
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    OUTPUT_VARIABLE DAMAS_GIT_COMMIT_HASH
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

execute_process(
    COMMAND git log -1 --format=%h
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    OUTPUT_VARIABLE DAMAS_GIT_COMMIT_ABBREVIATED_HASH
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

execute_process(
    COMMAND git rev-parse --abbrev-ref HEAD
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    OUTPUT_VARIABLE DAMAS_GIT_BRANCH_NAME
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

