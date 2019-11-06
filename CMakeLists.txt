# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("cmake_cross_platform")

# Include sub-projects.
add_subdirectory ("cmake_cross_platform")
set_property(TARGET cmake_cross_platform PROPERTY CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
