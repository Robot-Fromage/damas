set -e
cd "`dirname "$0"`"

## Make Generated dir for generated project if not exist
if [ ! -d build ]; then 
	mkdir build
fi

## Step in Generated dir
cd build

## Clean cmake garbage if there
if [ -d CMakeFiles ]; then
	rm -r CMakeFiles
fi
if [ -f cmake_install.cmake ]; then
	rm cmake_install.cmake
fi
if [ -f CMakeCache.txt ]; then
	rm CMakeCache.txt
fi

## Rebuild Project
cmake -G "Xcode" -DDAMAS_BUILD_SHARED=ON -DDAMAS_BUILD_TESTS=ON ../.