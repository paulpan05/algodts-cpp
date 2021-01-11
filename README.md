# Algorithms and Data Structures in C++

To begin testing the algorithms, make a folder called `build` in the root project directory.

cd into the directory, then enter `cmake ..` to initialize the build files in the `build` directory.

In the build directory, enter `make` to compile the project files.

Include
```
if(WIN32)
        set(CMAKE_TOOLCHAIN_FILE $ENV{VCPKG_TOOLCHAIN_FILE})
endif()
```
before project in ```CMakeLists.txt``` on Windows platform.

Also, add ```VCPKG_DEFAULT_TRIPLET``` as ```x64-windows``` and ```VCPKG_TOOLCHAIN_FILE``` as ```C:\vcpkg\scripts\buildsystems\vcpkg.cmake``` on Windows.

If a makefile is desired, do ```cmake -G "NMake Makefiles" ..``` on Windows to specify the nmake generator.
