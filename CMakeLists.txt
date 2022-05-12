cmake_minimum_required(VERSION 3.10)

project(findstr)

set (CMAKE_CXX_STANDARD 11)
#set (CMAKE_CXX_FLAGS "-O3 -fno-vectorize -Rpass-analysis=.* -Rpass=.* -Rpass-missed=.*")
set (CMAKE_CXX_FLAGS "-O3")
set (CMAKE_C_FLAGS "-O3")
find_package(benchmark REQUIRED)

add_executable(findstr findstr.cpp)
target_link_libraries(findstr benchmark::benchmark)
