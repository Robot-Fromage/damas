## Build From Source
This page explains how to build Damas from source.  
Damas favors the use of [CMake](https://cmake.org/) to manage the build process, so this document shows how to generate project files and compile using it.  
It is possible to setup your own custom build process, but this is not covered here.

# Table of Contents
- [Requirements](@ref requirements)
    + [Softwares](@ref softwares)
    + [Operating Systems](@ref os)
    + [Compilers](@ref compilers)
- [Getting Started](@ref getting-started)
- [Windows](@ref windows)
    + [Visual Studio 15 2017 - MSVC](@ref vs2017)
    + [Visual Studio 16 2019 - MSVC](@ref vs2019)
    + [Visual Studio - Clang/LLVM](@ref vsclang)
    + [MinGW Makefiles - GCC](@ref mingw)
- [macOS](@ref macos)
    + [Xcode - Clang/LLVM](@ref xcode)
- [Linux](@ref linux)
    + [Sublime Text2 - Unix Makefiles - GCC](@ref sublime)
- [Additional Build Options](@ref additional)

# Requirements {#requirements}
Damas is meant to be used with desktop software applications on modern architectures, for processors supporting x86-64, and with 64-bit operating systems.  
There is no guaranty that Damas is able to compile and run for other platforms such as Android or embedded systems.

### Softwares {#softwares}
The following softwares are required in order to collect and build Damas from source:
- [CMake](https://cmake.org/)
- [git](https://git-scm.com/)

### Operating Systems {#os}
The following operating systems are officially supported, both as target platforms and hosts for compiling the library. They are tested on a regular basis:
- Windows
    + Windows 7
    + Windows 8
    + Windows 10
- macOS
- Linux
    + Ubuntu

### Compilers {#compilers}
The following compilers are officially supported and frequently tested:
- MSVC
    + 2017
    + 2019
- Clang/LLVM
- GCC
- MinGW GCC

# Getting Started {#getting-started}
First and foremost, you have to clone the repo and checkout a stable commit, we recommend building the release and not the latest dev state, unless you are willing to contribute or try the possibly unstable latest features.
Then the build process is very similar for all the following platforms.  
The steps involved describe commands typed in the shell or command prompt, assuming both cmake and git are available from the path.  
This is the typical out of source build process with CMake:
```d
    git clone https://github.com/Robot-Fromage/damas
    cd damas
    git checkout release
    cd ..
    mkdir damas_build
    cd damas_build
    cmake -G "Generator" ../damas
```
[Here is a list of CMake generators and documentation](https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html)

# Windows {#windows}
The following sections describes the step-by-step process for Windows.
### Visual Studio 15 2017 - MSVC {#vs2017}
```d
    git clone https://github.com/Robot-Fromage/damas
    mkdir damas_build
    cd damas_build
    cmake -G "Visual Studio 15 2017 Win64" ../damas
```
### Visual Studio 16 2019 - MSVC {#vs2019}
```d
    git clone https://github.com/Robot-Fromage/damas
    mkdir damas_build
    cd damas_build
    cmake -G "Visual Studio 16 2019" -A x64 ../damas
```
### Visual Studio - Clang/LLVM {#vsclang}
```d
    git clone https://github.com/Robot-Fromage/damas
    mkdir damas_build
    cd damas_build
    cmake -G "Visual Studio 15 2017 Win64" -T"llvm" ../damas
```
### MinGW Makefiles - GCC {#mingw}
```d
    git clone https://github.com/Robot-Fromage/damas
    mkdir damas_build
    cd damas_build
    mkdir Release
    cd Release
    cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release ../../damas
    cd ..
    mkdir Debug
    cd Debug
    cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Debug ../../damas
```
# macOS {#macos}
The following sections describes the step-by-step process for macOS.
### Xcode - Clang/LLVM {#xcode}
```d
    git clone https://github.com/Robot-Fromage/damas
    mkdir damas_build
    cd damas_build
    cmake -G "Xcode" ../damas
```
# Linux {#linux}
The following sections describes the step-by-step process for Linux.
### Sublime Text2 - Unix Makefiles - GCC {#sublime}
```d
    git clone https://github.com/Robot-Fromage/damas
    mkdir damas_build
    cd damas_build
    mkdir Release
    cd Release
    cmake -G "Sublime Text 2 - Unix Makefiles" -DCMAKE_BUILD_TYPE=Release ../../damas
    cd ..
    mkdir Debug
    cd Debug
    cmake -G "Sublime Text 2 - Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug ../../damas
```

# Additional Build Options {#additional}
On top of the default CMake generation process, you can specify more build options to customize your build or enable or disable components in the Damas library.
| Option Name                   | Type      | Default   | Meaning                                                                                                   |
|------------------------------ |-----------|-----------|-----------------------------------------------------------------------------------------------------------|
| DAMAS_BUILD_SHARED            | BOOL      | ON        | Wether to build dynamic library or not.                                                                   |
| DAMAS_BUILD_PYTHON_MODULE     | BOOL      | OFF       | Wether to generate and build the python binding or not.                                                   |
| DAMAS_BUILD_TESTS             | BOOL      | OFF       | Wether to generate and build the tests or not.                                                            |
| DAMAS_BUILD_SAMPLES           | BOOL      | OFF       | Wether to generate and build the samples or not.                                                          |
| DAMAS_FORCE_ASSERTS           | BOOL      | OFF       | Wether to force asserts in RelWithDebInfo or Release builds or not ( recommended for RelWithDebInfo ).    |
| DAMAS_BINARY_PREFIX           | STRING    | ""        | Indicates a prefix for the output binaries.                                                               |

This is an example for Windows, Visual Studio 16 2019 - MSVC, with all options:
```d
    git clone https://github.com/Robot-Fromage/damas
    mkdir damas_build
    cd damas_build
    cmake   -G "Visual Studio 16 2019"      ^
            -A x64                          ^
            -DDAMAS_BUILD_SHARED=ON         ^
            -DDAMAS_BUILD_PYTHON_MODULE=ON  ^
            -DDAMAS_BUILD_TESTS=ON          ^
            -DDAMAS_BUILD_SAMPLES=ON        ^
            ../damas
```

