cmake_minimum_required(VERSION 3.27)
project(untitled C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled main.c
        core/logIn.c
        core/headers/logIn.h
        core/singUp.c
        core/headers/singUp.h
        core/structs.c
        core/headers/structs.h
        core/runner.c
        core/headers/runner.h)
