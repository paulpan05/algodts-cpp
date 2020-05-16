cmake_minimum_required( VERSION 3.0 )

project( algodts-cpp )

set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11" )

include_directories( ./include ./src ./test )

file( GLOB SOURCES "./src/*.cpp" "./src/**/*.cpp" "./test/*.cpp" "./test/**/*.cpp" )

add_executable( tests ${SOURCES} )
