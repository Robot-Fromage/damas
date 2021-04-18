#
#   Damas
#__________________
# @file         Install.cmake
# @author       Clement Berthaud
# @brief        CMake utility.
# @copyright    Copyright 2021 Clément Berthaud
# @license      Please refer to LICENSE.md
cmake_minimum_required( VERSION 3.11.0 )

# Install
string( TIMESTAMP DAMAS_TODAY_DATE "%d/%m/%Y" )
set( DAMAS_INSTALL_NAME "install_Damas${DAMAS_FULL_VERSION}_${CMAKE_HOST_SYSTEM_NAME}_${CMAKE_CXX_COMPILER_ID}_x64" )
set( CMAKE_INSTALL_PREFIX "${PROJECT_BINARY_DIR}/../${DAMAS_INSTALL_NAME}" CACHE PATH "Install Path" FORCE )
write_file( ".VERSION"      ${DAMAS_FULL_VERSION}     )
write_file( ".TIMESTAMP"    ${DAMAS_TODAY_DATE}  )
write_file( ".COMMIT"       "commit: [${DAMAS_GIT_COMMIT_HASH}](${DAMAS_GIT_COMMIT_ABBREVIATED_HASH}), on branch: [${DAMAS_GIT_BRANCH_NAME}]" )

install(
    TARGETS damas
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(
    DIRECTORY ${PROJECT_SOURCE_DIR}/include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    COMPONENT headers
)

install( FILES AUTHORS          DESTINATION "." COMPONENT runtime )
install( FILES LICENSE          DESTINATION "." COMPONENT runtime )
install( FILES "${PROJECT_BINARY_DIR}/.VERSION"     DESTINATION "." COMPONENT runtime )
install( FILES "${PROJECT_BINARY_DIR}/.TIMESTAMP"   DESTINATION "." COMPONENT runtime )
install( FILES "${PROJECT_BINARY_DIR}/.COMMIT"      DESTINATION "." COMPONENT runtime )
#install( FILES 3rdparty/x/LICENSE                   DESTINATION "./3rdparty/x/."            COMPONENT runtime )

