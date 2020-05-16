cmake_minimum_required( VERSION 3.0 )

project( algodts-cpp )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories( ./include ./src )

add_executable( binary ./src/main.cpp )
