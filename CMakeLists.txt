cmake_minimum_required(VERSION 3.28)
project(CP)

set(CMAKE_CXX_STANDARD 17)

add_compile_options(
        -O2
        -Wall
        -Wextra
        -Wshadow
        -Wfloat-equal
)

add_executable(CP main.cpp
        bits/stdc++.h)