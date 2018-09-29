#
# EPITECH PROJECT, 2018
#   cpp_indie_studio
# File description:
#  cmake
#
cmake_minimum_required(VERSION 3.10)
project(cpp_indie_studio)

include_directories(Includes Includes/FileSystem)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall -Werror")

set(SRCS_DIR Srcs/)
file(
        GLOB_RECURSE
        SRCS
        ${SRCS_DIR}*.cpp
        )

set(INCS_DIR Includes/)
file(
        GLOB_RECURSE
        INCS
        ${INCS_DIR}*.hpp
)

add_executable(bomberman ${SRCS} ${INCS} Includes/Renderer/Renderer.hpp Srcs/Renderer/Renderer.cpp Srcs/Renderer/cursor.cpp Srcs/Renderer/assets.cpp)

target_link_libraries(bomberman Irrlicht)
target_link_libraries(bomberman GL)
