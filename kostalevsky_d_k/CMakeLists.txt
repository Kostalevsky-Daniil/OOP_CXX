cmake_minimum_required(VERSION 3.18)

set(CMAKE_CXX_STANDART 20)

project(kostalevsky_d_k)

find_package(doctest REQUIRED)

add_subdirectory(prj.lab)
add_subdirectory(prj.test)
