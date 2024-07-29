cmake_minimum_required(VERSION 3.14)
project(Demo)
set(CMAKE_CXX_STANDARD 14)

find_package(benchmark REQUIRED)

add_executable(MyTarget mybenchmark.cpp)
target_link_libraries(MyTarget benchmark::benchmark)