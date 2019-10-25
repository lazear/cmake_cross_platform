# CMakeList.txt : CMake project for cmake_cross_platform, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (cmake_cross_platform 
	"cmake_cross_platform.cpp" "cmake_cross_platform.h"
	"testfile.cpp" "testfile.h"
)

# TODO: Add tests and install targets if needed.