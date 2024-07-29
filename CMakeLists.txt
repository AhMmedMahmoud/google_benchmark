cmake_minimum_required(VERSION 3.14)
project(Demo)
set(CMAKE_CXX_STANDARD 14)

find_package(benchmark REQUIRED)

add_executable(ex1 example1.cpp)
target_link_libraries(ex1 benchmark::benchmark)

add_executable(ex2 example2.cpp)
target_link_libraries(ex2 benchmark::benchmark)