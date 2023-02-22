cmake_minimum_required(VERSION 3.23)
project(gyak1 C)

set(CMAKE_C_STANDARD 23)

add_executable(gyak1 main.c Sources/functions.c Headers/functions.h Headers/constants.h)

include_directories(Headers)
