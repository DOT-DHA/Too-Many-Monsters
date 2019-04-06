cmake_minimum_required(VERSION 3.12)
project(Too_Many_Monsters)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Too_Many_Monsters
        Character.cpp
        Character.hh
        Enemy.cpp
        Enemy.hh
        main.cpp
        Main.h)
