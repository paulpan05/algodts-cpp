cmake_minimum_required( VERSION 3.0 )

project( algodts-cpp )

set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++17" )

set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

include_directories( ./include )

if( APPLE )
	include_directories( /usr/local/include )
	link_directories( /usr/local/lib )
endif()

file( GLOB TEST_SOURCES "./test/*.cpp" "./test/**/*.cpp" )

add_executable( tests ${TEST_SOURCES} )
