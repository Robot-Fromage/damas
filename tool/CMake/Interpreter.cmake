#
#   Damas
#__________________
# @file         Interpreter.cmake
# @author       Clement Berthaud
# @brief        CMake utility.
# @copyright    Copyright 2021 Clément Berthaud
# @license      Please refer to LICENSE.md
cmake_minimum_required( VERSION 3.11.0 )

# Gather sources
file(
    GLOB_RECURSE
    source_list
    RELATIVE
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "example/*"
)

# Create Project
add_executable( damasio ${source_list} )

# Include
target_include_directories(
    damasio
    PRIVATE
    "example/"
)

# Link
target_link_libraries( damasio PRIVATE damas )

# Configure
set_target_properties( damasio PROPERTIES OUTPUT_NAME "damasio${DAMAS_VERSION_EPOCH}" )
set_target_properties( damasio PROPERTIES PREFIX "${DAMAS_BINARY_PREFIX}" )
set_target_properties( damasio PROPERTIES FOLDER damas )

# Pretty
foreach(source IN LISTS source_list)
    get_filename_component(source_path "${source}" PATH)
    string(REPLACE "/" "\\" source_path_msvc "${source_path}")
    source_group("${source_path_msvc}" FILES "${source}")
endforeach()

