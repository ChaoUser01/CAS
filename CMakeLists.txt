cmake_minimum_required(VERSION 3.16)
project(CAS)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(
    CAS
    src/main.cpp
    src/core/Node.hpp
)
