# Lynar Studios - Standard Library 2022.2.0 #

This is a cross-platform standard library written in C++ offering functionalities you would usually miss in C++'s standard template library (STL), especially if you would search for cross-platform implementations.  
This library has been tested on __Windows__, __Linux__ and __MacOS__ systems.
Following a modularized approach the following submodules are defined in scope of this library, which are independent:
 
#### Boxing ####

This library module provides boxing classes for primitive data types (e.g. string, int, long, float...) to provide additional functionalities.

#### Core ####

The core module is a base module providing a base __Class__, exceptions, data types and interfaces. Usually the other submodules are dependent on this module. 

#### Encoding ####

To encode a byte field (e.g. a binary file) for transfer the __Base64__ encoding / decoding functionality is being provided by this submodule as a first feature.

#### Event ####

This submodule comes with an __Event__ class, as well as with handlers and managers to provide an intuitive event handling for your application.

#### IO ####

To handle file operations - or to receive information of a file - this library submodule provides an own __File__ class implementation, which can also be passed to library implemented input or output stream classes.  
Additionally __XML__ and __KV__ parsing functionalities are provided by this submodule.

#### Logic ####

Functionalities provided by this submodule support your project with some nice logical features. The first one being provided by it is a state machine.

#### Time ####

A __Date__ class comes with this submodule, which you can use to represent a date and do operations on it. 

---
### Changelog ###

#### Features ####

- this library is now being compiled with C++ 17 standard
- this library can now build shared libraries by using MSVC
- Clang support has been added to this library
- added Base64 CLI Tool, which enables a user to use Base64 encoding and decoding functionalities via CLI
- JSON type alias has been added to avoid direct nlohmann library usage

#### Improvements ####

- none

#### Fixes ####

- none

---
### Documentation ###

You can find a detailed documentation on Lynar Studios Website: lynarstudios.com

---
### License ###

This software is licensed and uses MIT-license. You can find a __LICENSE.MIT__ file inside the project's root directory.

---
### Building ###

To build this library you'd need a recent version of __cmake__ and your OS specific compiler collection, like __gcc__ or __MinGW__ installed.  
Inside project's root directory create the following folder:

```
cmake_build_release
```

Open your OS specific command line interface (CLI) and navigate to this new folder and run the following command to configure the project and generate a native build system:  

```
cmake ../
```

Inside __cmake_build_release__ folder you will now find cmake generated files. To compile the library now, just run:   

```
cmake --build . --config Release
```

__Please note__: Currently only a small set of compilers is officially supported. If you'd like to compile with an unsupported compiler, you have to set __LS_STD_BUILD_WITH_SUPPORTED_COMPILER__ - option in _CMakeLists.txt_ file to __OFF__ - then reset and reload the cmake project.  

Find below a table of compiler/OS combinations which have been tested during library version development:

| Supported Compiler | OS              | Compiler Version        |
|--------------------|-----------------|-------------------------|
| GCC                | Linux Mint 20.3 | 12.1.0                  |
| Clang              | Linux Mint 20.3 | 12.0.0-3ubuntu1~20.04.5 |
| MinGW-w64 / GCC    | Windows 10      | 11.2.0                  |
| MSVC               | Windows 10      | 19.32.31332.0           |

---
### Add Library To Your CMake Project ###

If you would like to add this library to your CMake project (__CMakeLists.txt__ file), make sure that you would add the libraries' include directory:

```
include_directories(${CMAKE_CURRENT_LIST_DIR}/path/to/this/library/include)
```

Then link the libraries' binary file inside your __CMakeLists.txt__ file:

```
target_link_libraries(... libls_std_core libls_std_boxing ...)
```

---
### Testing ###

This project contains unit tests to provide test coverage.  
To run those tests you have to build this project with option __LS_STD_BUILD_WITH_TESTS__ set to __ON__ - then reset and reload the CMake project.
