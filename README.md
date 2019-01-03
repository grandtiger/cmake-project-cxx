# cmake-program-c
_____________________________________________________________________________________________________
Description.
-------------------------------------------------------------------------------------------
Simpe CMake project template for C program. seems like a good candidate for adding on additions the you may find useful 
for basic C programs

Requirements.
-------------------------------------------------------------------------------------------
These are the base requirements to build and use for this project from a source package (as described below):

* [CMake](https://cmake.org/) v3.12.2 or newer.



Using CMake.
-------------------------------------------------------------------------------------------
This project comes with a CMake build script ( that can be used on a wide range of platforms ("C" stands 
for cross-platform. ).  If you don't have CMake installed already, you can download it for free from 
[CMake](http://www.cmake.org/).

CMake works by generating native makefiles or build projects that can be used in the compiler environment 
of your choice. You can either build SqdTest as a standalone project or it can be incorporated into an 
existing CMake build for another project.

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
