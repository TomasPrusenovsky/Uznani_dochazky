cmake_minimum_required(VERSION 3.10)

project(OOP_Ukazky)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES "src/*.cpp")

add_executable(ukazky ${SOURCES})