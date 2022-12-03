cmake_minimum_required(VERSION 3.10)  # CMake version check
project(rt)               # Create project "simple_example"
set(CAMKE_CXX_STARDARD 11)

add_definitions("-Wall -g")
# Add main.cpp file of project root directory as source file
SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/output/bin)
SET(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/output/lib)

set(CMAKE_SKIP_BUILD_RPATH FALSE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
set(CMAKE_INSTALL_RPATH $ORIGIN/../lib)

file(GLOB SOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
    *.cpp)

include_directories(include)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(main ${SOURCE_FILES})

# add_library(rt SHARED ${SOURCE_FILES})
# set(LINK_PATH "/home/g/wecode/rt-main/cpp/lib")
set(LINK_PATH "/home/ge/dev/rt/cpp/lib")
message(STATUS ${LINK_PATH})


find_library(GTEST_PATH gtest ${LINK_PATH})
IF(NOT GTEST_PATH)
    MESSAGE(FATAL_ERROR "libgtest not found")
ENDIF(NOT GTEST_PATH)

find_library(GTESTMAIN_PATH gtest_main ${LINK_PATH})
IF(NOT GTESTMAIN_PATH)
    MESSAGE(FATAL_ERROR "gtest_main not found")
ENDIF(NOT GTESTMAIN_PATH)

find_library(GMOCK_PATH gmock ${LINK_PATH})
IF(NOT GMOCK_PATH)
    MESSAGE(FATAL_ERROR "gmock not found")
ENDIF(NOT GMOCK_PATH)

find_library(GMOCKMAIN_PATH gmock_main ${LINK_PATH})
IF(NOT GMOCKMAIN_PATH)
    MESSAGE(FATAL_ERROR "gmock_main not found")
ENDIF(NOT GMOCKMAIN_PATH)

message(STATUS ${GTEST_PATH})
message(STATUS ${GTESTMAIN_PATH})
message(STATUS ${GMOCK_PATH})
message(STATUS ${GMOCKMAIN_PATH})

# link_directories(${LINK_PATH})

target_link_libraries(main ${GTEST_PATH} ${GTESTMAIN_PATH} ${GMOCK_PATH} ${GMOCKMAIN_PATH} pthread)
# target_link_libraries(rt ${GTEST_PATH} ${GTESTMAIN_PATH} ${GMOCK_PATH} ${GMOCKMAIN_PATH} pthread)
