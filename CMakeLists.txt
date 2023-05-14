cmake_minimum_required(VERSION 3.25)
project(OOP_project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(OOP_project
        Book.cpp
        Book.h
        BookArray.cpp
        BookArray.h
        main.cpp
        Manager.cpp
        Manager.h
        User.cpp
        User.h
        UserArray.cpp
        UserArray.h)
