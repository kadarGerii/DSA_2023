cmake_minimum_required(VERSION 3.23)
project(hazi3 C)

set(CMAKE_C_STANDARD 23)

add_executable(hazi3 Sources/main.c cmake-build-debug/Sources/functions.c cmake-build-debug/Headers/functions.h)
