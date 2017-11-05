cmake_minimum_required(VERSION 3.8)
project(cpp_lab)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp utility.hpp utility.cpp)
add_executable(cpp_lab ${SOURCE_FILES})