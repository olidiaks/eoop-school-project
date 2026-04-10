cmake_minimum_required(VERSION 4.1)
project(Project)

set(CMAKE_CXX_STANDARD 26)

add_executable(Project main.cpp
        Class.cpp
        Class.h
        Student.cpp
        Student.h
        Teacher.cpp
        Teacher.h
        School.cpp
        School.h)
