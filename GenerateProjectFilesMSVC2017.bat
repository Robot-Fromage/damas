@echo off
setlocal
pushd %~dp0

:: Make Generated dir for generated project if not exist
IF NOT EXIST build ( MKDIR build )

:: Step in Generated dir
cd build

:: Clean cmake garbage if there
IF EXIST CMakeFiles ( rmdir /S /Q CMakeFiles )
IF EXIST cmake_install.cmake ( del cmake_install.cmake )
IF EXIST CMakeCache.txt ( del CMakeCache.txt )

:: Rebuild Project
cmake   -G "Visual Studio 15 2017 Win64"    ^
        -DDAMAS_BUILD_SHARED=ON             ^
        ../.

PAUSE

