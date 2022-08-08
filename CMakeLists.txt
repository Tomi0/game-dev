cmake_minimum_required(VERSION 3.1)

project(game-dev)

include_directories(${CMAKE_SOURCE_DIR}/include)

aux_source_directory(${CMAKE_SOURCE_DIR}/src SOURCE_DIRECTORY)

add_executable(game-dev ${SOURCE_DIRECTORY})

target_link_libraries(game-dev SDL2main SDL2)