#
#   Damas
#__________________
# @file         Library.cmake
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
    "include/*"
    "source/*"
)

# Create Project
if( ${DAMAS_BUILD_SHARED} )
   add_library( damas SHARED ${source_list} )
   target_compile_definitions( damas PRIVATE DAMAS_BUILD_SHARED )
else()
   add_library( damas STATIC ${source_list} )
   target_compile_definitions( damas PRIVATE DAMAS_STATIC_LIBRARY )
endif()

# Compile Definitions
target_compile_definitions(
    damas
    PUBLIC
    UNICODE
    PRIVATE
    DAMAS_DEF_VERSION_EPOCH=${DAMAS_VERSION_EPOCH}
    DAMAS_DEF_VERSION_MINOR=${DAMAS_VERSION_MINOR}
    DAMAS_DEF_VERSION_PATCH=${DAMAS_VERSION_PATCH}
    DAMAS_DEF_GIT_COMMIT_HASH=${DAMAS_GIT_COMMIT_HASH}
    DAMAS_DEF_GIT_COMMIT_ABBREVIATED_HASH=${DAMAS_GIT_COMMIT_ABBREVIATED_HASH}
    DAMAS_DEF_GIT_BRANCH_NAME=${DAMAS_GIT_BRANCH_NAME}
    DAMAS_GENERATION_TIMESTAMP=${DAMAS_GENERATION_TIMESTAMP}
)

# Include
target_include_directories(
    damas
    PUBLIC
    "include/"
    PRIVATE
    "source/"
)

# Link
#target_link_libraries( damas PRIVATE x )

# Configure
set_target_properties( damas PROPERTIES OUTPUT_NAME "damas${DAMAS_VERSION_EPOCH}" )
set_target_properties( damas PROPERTIES PREFIX "${DAMAS_BINARY_PREFIX}" )
set_target_properties( damas PROPERTIES FOLDER damas )

# Pretty
foreach(source IN LISTS source_list)
    get_filename_component(source_path "${source}" PATH)
    string(REPLACE "/" "\\" source_path_msvc "${source_path}")
    source_group("${source_path_msvc}" FILES "${source}")
endforeach()

