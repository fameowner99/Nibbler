cmake_minimum_required(VERSION 3.12)
project(Nibbler)

set(CMAKE_CXX_STANDARD 14)

find_library(libsdl SDL2)


add_executable(Nibbler
        src/Game.cpp
        src/GUI.cpp
        src/main.cpp
        src/Object.cpp
        src/Snake.cpp
        src/Position.cpp)

target_link_libraries(Nibbler ${libsdl})


