cmake_minimum_required(VERSION 2.8.4)
project(homework3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(include)

add_subdirectory(src)
add_subdirectory(test)