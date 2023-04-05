cmake_minimum_required(VERSION 3.23)
project(lab5_3 C)

set(CMAKE_C_STANDARD 23)

add_executable(lab5_3 main.c Sources/circular_queue.c Headers/circular_queue.h Sources/patients.c Headers/patients.h)
