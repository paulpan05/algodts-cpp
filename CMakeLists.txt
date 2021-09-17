cmake_minimum_required( VERSION 3.1 )

set( CMAKE_BUILD_TYPE "Release" )
set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

if( WIN32 )
	set( CMAKE_TOOLCHAIN_FILE $ENV{VCPKG_TOOLCHAIN_FILE} )
endif()

project( algodts-cpp )

include_directories( ./include )

if( APPLE )
	include_directories( /usr/local/include )
	link_directories( /usr/local/lib )
endif()

find_package( Threads REQUIRED )

file( GLOB TEST_SOURCES "./test/*.cpp" "./test/**/*.cpp" )

add_executable( tests ${TEST_SOURCES} )

target_link_libraries( tests PRIVATE Threads::Threads )
