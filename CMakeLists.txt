cmake_minimum_required(VERSION 3.1)

project(game-dev)

add_executable(game-dev src/main.cpp src/Game.cpp src/Player.cpp)

target_link_libraries(game-dev SDL2main SDL2)