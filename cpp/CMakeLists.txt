cmake_minimum_required(VERSION 3.13)  # CMake version check
project(rt)               # Create project "simple_example"
set(CAMKE_CXX_STARDARD 11)

# Add main.cpp file of project root directory as source file
set(SOURCE_FILES main.cpp)

include_directories(include)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(main.out ${SOURCE_FILES})

add_library(rt SHARED ${SOURCE_FILES})
message(STATUS ${PROJECT_SOURCE_DIR}/lib)
#link_directories(${PROJECT_SOURCE_DIR}/lib)
link_directories("/home/ge/dev/googletest_demo/googletest/build/lib")
target_link_libraries(rt gtest gtest_main gmock gmock_main pthread)

#target_link_libraries(rt libgtest.a libgtest_main.a libgmock.a libgmock_main.a)
