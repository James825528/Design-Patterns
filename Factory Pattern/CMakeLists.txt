cmake_minimum_required(VERSION 3.0.0)
project(Factory VERSION 0.1.0 LANGUAGES C CXX)
include_directories(
        ${PROJECT_SOURCE_DIR}/inc
        ${PROJECT_SOURCE_DIR}/src
)
file(GLOB all_SRCS
        "${PROJECT_SOURCE_DIR}/inc/*.h"
        "${PROJECT_SOURCE_DIR}/inc/*.hpp"
        "${PROJECT_SOURCE_DIR}/src/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/*.c"
        )
set (CMAKE_CXX_FLAGS "-std=c++11")
add_executable(Factory ${all_SRCS} main.cpp)
# add_executable(Factory main.cpp)


