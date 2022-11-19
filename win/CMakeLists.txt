cmake_minimum_required(VERSION 3.13)  # CMake version check



set(CMAKE_CXX_COMPILER "D:/mingw64/bin/g++.exe")

set(CMAKE_C_COMPILER "D:/mingw64/bin/gcc.exe")

project(main)               # Create project "simple_example"

set(CAMKE_CXX_STARDARD 11)

# Add main.cpp file of project root directory as source file
set(SOURCE_FILES main.cpp)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(main.out ${SOURCE_FILES})

add_library(rt SHARED ${SOURCE_FILES})