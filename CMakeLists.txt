cmake_minimum_required(VERSION 3.5)

set (CMAKE_CXX_STANDARD 11)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

project (cpp-fractal)
add_subdirectory(libs)
add_subdirectory(main)