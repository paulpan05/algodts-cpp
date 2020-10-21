cmake_minimum_required( VERSION 3.0 )

project( algodts-cpp )

set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++17" )

set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

file( GLOB SOURCES "./test/*.cpp" "./test/**/*.cpp" )

add_executable( tests ${SOURCES} )

target_include_directories( tests PUBLIC include )
