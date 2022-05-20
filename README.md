# Lynar Studios - Standard Library 2022.1.0 #

This is a cross-platform standard library written in C++ offering functionalities you'd usually miss in C++'s standard template library (STL), especially if you'd search for cross-platform implementations. This library has been tested on __Windows__, __Linux__ and __MacOS__ systems.
Following a modularized approach the following submodules are defined in scope of this library, which are independent:
 
#### Boxing ####

This library module provides boxing classes for primitive data types (e.g. string, int, long, float...) to add additional functionalities for each one of them.

#### Core ####

The core module is a base module providing a base __Class__, exceptions, data types and interfaces. Usually the other submodules are dependent on this module. 

#### Encoding ####

To encode a byte field (e.g. binaries) for transfer the __Base64__ encoding / decoding functionality is being provided by this submodule as a first feature.

#### Event ####

This submodule comes with an __Event__ class, as well as with handlers and managers to provide an intuitive event managing for your application.

#### IO ####

To handle file operations - or to receive information of a file - this library submodule provides an own __File__ class implementation, which can also be passed to library implemented input or output stream classes.  
Additionally __XML__ and __KV__ parsing functionalities are provided by this submodule.

#### Logic ####

Functionalities provided by this submodule support your project with some nice logical features. The first one being provided by it is a state machine.

#### Time ####

A __Date__ class comes with this submodule, which you can use to represent a date and do operations on it. 

### Changelog ###

#### Features ####

- "encoding" submodule has been added providing __Base64__ encoding and decoding functionality

#### Improvements ####

- modularization has been improved by restructuring library files, which would result into having submodules - __there is no central header or binary file anymore__ - instead submodules can be linked independently now (e.g. using __ls_std_event.hpp__ and linking __libls_std_event.so__)
- there is a cmake guard now to ensure that only one goal at the time is being build
- test suites for shared libraries have been introduced to ensure that building and linking created shared library is working
- namespaces have been improved library wide and are more specific - __there is no _ls_std_ namespace anymore__ - instead you can choose submodule specific namespaces (e.g. _ls::std::boxing::_)

#### Fixes ####

- there is a cmake guard now to ensure that only one goal at the time is being build

### Documentation ###

You can find a detailed documentation on Lynar Studios Website: lynarstudios.com

### License ###

This software is licensed and uses MIT-license. You can find a __LICENSE.MIT__ file inside the project's root directory.

### Building ###

To build this library you'd need a recent version of __cmake__ and your OS specific compiler collection, like __gcc__, __MSVC__ or __AppleClang__ installed.  
Inside project's root directory create the following folder:

```
cmake_build_release
```

Open your OS specific command line window and navigate to this new folder and run the following command to configure the project and generate a native build system:  

```
cmake ../
```

Inside __cmake_build_release__ folder you will now find cmake generated files. To compile the library now, just run:   

```
cmake --build . --config Release
```

### Add Library To Your Project ###

If you would like to add this library to your cmake project - to the __CMakeLists.txt__ file - make sure that you add the libraries' include directory:

```
include_directories(${CMAKE_CURRENT_LIST_DIR}/path/to/this/library/include)
```

Then link the library binary file inside your __CMakeLists.txt__ file:

```
target_link_libraries(... "path/to/this/library/../libls_std_YYYY.MAJOR.MINOR.dll")
```

### Testing ###

This project contains unit tests to provide test coverage.  
To run those tests you have to build this project with option __LS_STD_BUILD_WITH_TESTS__ set to __ON__.
