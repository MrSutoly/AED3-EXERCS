cmake_minimum_required(VERSION 4.0)
project(Trab1Matriz C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Trab1Matriz
        main.c
        matriz.c
        matriz.h)
