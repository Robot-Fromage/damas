#
#   Damas
#__________________
# @file         AddLibraryModule.cmake
# @author       Clement Berthaud
# @brief        CMake utility.
# @copyright    Copyright 2021 Clément BERTHAUD.
# @license      Please refer to LICENSE.md
#
cmake_minimum_required( VERSION 3.11.0 )

function( AddLibraryModule iModuleName )
    # PARSE PRETTY NAMES
    string( SUBSTRING ${iModuleName} 1 -1 name_without_k )
    string( TOUPPER ${name_without_k} uppercase_name )
    set( API_NAME "DAMAS_${uppercase_name}_API" )

    # ADD PROJECT
    add_library( ${iModuleName} SHARED )
    target_compile_definitions( ${iModuleName} PRIVATE DAMAS_BUILD_SHARED )
    set_target_properties( ${iModuleName} PROPERTIES OUTPUT_NAME "K${DAMAS_VERSION_EPOCH}${name_without_k}" )
    set_target_properties( ${iModuleName} PROPERTIES FOLDER DamasLib )

    # ADD MODULE SOURCE
    file(
        GLOB_RECURSE
        source_list
        RELATIVE
        "${CMAKE_CURRENT_SOURCE_DIR}"
        "Source/DamasLib/${iModuleName}/*"
    )
    target_sources( ${iModuleName} PRIVATE ${source_list} )

    # PARSE PRETTIER FOLDER GROUPS
    foreach( source IN LISTS source_list )
        get_filename_component( source_path "${source}" PATH )
        string( REPLACE "/" "\\" source_path_msvc "${source_path}" )
        string( REPLACE "Source/DamasLib/${iModuleName}" "" source_path_msvc "${source_path}" )
        source_group( "${source_path_msvc}" FILES "${source}" )
    endforeach()

    # INCLUDE MODULE DIRS, PUBLIC IS EXPORTED
    target_include_directories(
        ${iModuleName}
        PUBLIC
        "Source/DamasLib/${iModuleName}/Public/"
        PRIVATE
        "Source/DamasLib/${iModuleName}/Private/"
    )

    # UNICODE
    target_compile_definitions(
        ${iModuleName}
        PUBLIC
        UNICODE
        PRIVATE
        DAMAS_INVALID_PROJECT=${DAMAS_GENERATION_TIMESTAMP}
    )

    # DLL EXPORT / IMPORT FOR WINDOWS
    if( "${CMAKE_HOST_SYSTEM_NAME}" STREQUAL "Windows" )
        target_compile_definitions(
            ${iModuleName}
            PRIVATE
            ${API_NAME}=DAMAS_DLLEXPORT
            INTERFACE
            ${API_NAME}=DAMAS_DLLIMPORT
        )
    else()
        target_compile_definitions(
            ${iModuleName}
            PUBLIC
            ${API_NAME}
        )
    endif()

endfunction()

