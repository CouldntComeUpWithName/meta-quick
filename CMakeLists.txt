cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 20)

project(ctype-info)

add_library(ctype-info INTERFACE)

target_include_directories(ctype-info INTERFACE "include")

add_subdirectory(tests)