cmake_minimum_required(VERSION 3.10)

project(findstr)

set (CMAKE_CXX_STANDARD 17)
if (NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type selected, default to Release")
    set(CMAKE_BUILD_TYPE "Release")
endif()

find_package(benchmark REQUIRED)

add_executable(findstr findstr.cpp)
target_link_libraries(findstr benchmark::benchmark)
