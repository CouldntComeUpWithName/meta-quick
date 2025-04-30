cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 20)

project(meta-quick)

add_library(meta-quick INTERFACE)

target_include_directories(meta-quick INTERFACE "include")

add_subdirectory(tests)