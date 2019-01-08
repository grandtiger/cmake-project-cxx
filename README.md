# cmake-project-cxx
_____________________________________________________________________________________________________
Description.
-------------------------------------------------------------------------------------------
This is a simple general purpose CMake project template written for C++ programmers. 

This template includes a unit testing framework.

The external folder is also for libraries and frameworks that you would like to add to your project(s). 



Main features
-------------------------------------------------------------------------------------------
Uses cmake to generate build system files.
* [Catch2 framework](https://github.com/catchorg/Catch2.git) as the main unit testing framework.

* also comes with some utility functions.


Requirements.
-------------------------------------------------------------------------------------------
* [CMake](https://cmake.org/) v3.12.2 or newer.



Using CMake.
-------------------------------------------------------------------------------------------
This project comes with a CMake build script ( that can be used on a wide range of platforms ("C" stands 
for cross-platform. ).  If you don't have CMake installed already, you can download it for free from 
[CMake](http://www.cmake.org/).

To build the project, we first need to create a separate build directory:

```
mkdir build
```

Now that we've created our build directory (assuming it's created in the projct root), we can `cd` into it and run
`cmake` and pass the parent directory path to it, which is where the `CMakeLists.txt` file is located:

```
cd build
cmake ../
```

Once `cmake` is done generating makefiles, we can build the project by running `make` inside the build directory:

```
make
```
This will build the project.
