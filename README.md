# Lynar Studios - Standard Library 2023.1.0 #

This is a cross-platform standard library written in C++ offering functionalities you would usually miss in C++'s standard template library (STL), especially if you would search for cross-platform implementations.  
This library has been tested on __Windows__, __Linux__ and __MacOS__ systems.
Following a modularized approach the following independent submodules are defined in scope of this library:
 
#### Boxing ####

This library module provides boxing classes for primitive data types (e.g. string, int, long, float...), adding additional functionalities.

#### Core ####

The core module is a base module providing common functionalities being shared among other library submodules. Functionalities provided by this module include interfaces, exceptions and base classes, which provide basic reflection functionalities.

#### Encoding ####

To encode a byte field (e.g. a binary file) for network transfer the __Base64__ encoding / decoding functionality is being provided by this submodule as a first feature.

#### Event ####

This submodule comes with events in a primitive form, as well as with handlers and managers to provide an intuitive event handling for your application.

#### IO ####

To handle file operations - or to receive information of a file - this library submodule provides an own __File__ class implementation, which can also be passed to library implemented input or output stream classes.  
Additionally __XML__ and __KV__ parsing functionalities are provided.

#### Time ####

A __Date__ class comes with this submodule, which you can use to represent a date and do operations on it. 

---
### Changelog ###

#### Features ####

- __AppleClang__ compiler is now officially supported
- exceptions provided by __core__ submodule now offer a constructor for passing dedicated messages
- evaluators have been added, which can check a state of variables and throw a dedicated exception in a single line and
  more convenient way
- a section-pair file standard has been implemented and is provided via __ls-std-io__ module, a definition of this
  standard can be found in the libraries __doc__ folder

#### Improvements ####

- __logic__ module has been removed from this library and can now be found in __ls-game-tool-kit__ library
- __core.utils__ module has been removed from this library to provide more clean implementations where it's needed
- namespaces have been completely removed from module tests to improve readability
- a new naming convention for files and directories has been introduced, where underscores were replaced by dashes entirely
- fetching the library version can now be achieved by using a dedicated __LibraryVersion__ class - the usage of a static function for this purpose has been removed completely
- missing nodiscard attributes have been added to library classes
- rename "types" folder in __core__ submodule to stick to naming convention
- key-value file standard has been removed from this library and is replaced by section-pair file standard

#### Fixes ####

- potential memory leaks have been resolved by strictly splitting prototypes and implementation project-wide, which enabled the usage of virtual or overridden destructors
- memory leaks inside exception test suite have been fixed

---
### Documentation ###

You can find a detailed documentation on Lynar Studios Website: lynarstudios.com

---
### License ###

This software is licensed and uses MIT-license. You can find a __LICENSE.MIT__ file inside the project's root directory.

---
### Building ###

Building this library would result into providing binaries for each library module and CLI tool: 

| binary              | type                       |
|---------------------|----------------------------|
| __cli-base64__      | CLI executable             |
| __ls-std-boxing__   | library (static / dynamic) |
| __ls-std-core__     | library (static / dynamic) |
| __ls-std-encoding__ | library (static / dynamic) |
| __ls-std-event__    | library (static / dynamic) |
| __ls-std-io__       | library (static / dynamic) |
| __ls-std-time__     | library (static / dynamic) |

#### Prerequisites ####

To build this library you'd need a supported __toolchain__ in place, consisting of a build tool and compiler. The following table is a listing of supported compilers and build tools associated with operating systems, where this library has been tested:

| Supported Compiler<br/>(mandatory) | OS              | Supported Compiler Version<br/>(mandatory) | Build Tool<br/>(mandatory) | Build Tool Version (mandatory) |
|------------------------------------|-----------------|--------------------------------------------|----------------------------|--------------------------------|
| GCC                                | Linux Mint 20.3 | 12.2.0                                     | CMake                      | \>= 3.24.0                     |
| Clang                              | Linux Mint 20.3 | 12.0.0-3ubuntu1~20.04.5                    | CMake                      | \>= 3.24.0                     |
| MinGW-w64 / GCC                    | Windows 10      | 11.2.0                                     | CMake                      | \>= 3.24.0                     |
| MSVC                               | Windows 10      | 19.32.31332.0                              | CMake                      | \>= 3.24.0                     |
| AppleClang                         | MacOS Monterey  | 14.0.0                                     | CMake                      | \>= 3.24.0                     |

Please note, that where the underlying operating system is optional in this listing, the toolchain itself is not! This means, that by default you should use one of the supported listed toolchains.  
In case you'd like to use an unsupported toolchain, you can enforce this during CMake project generation. For that have a look at the CMake flag usage section below.

#### Generate CMake Project (Unix) ####

To prepare a CMake project, create a build folder within the project's root folder (where the CMakeLists.txt file is located) via CLI and navigate to it:

```
mkdir cmake-build-release
cd cmake-build-release
```

Inside this folder generate the CMake project:

```
cmake ../
```

Alternatively, the CMake project generation can be controlled by providing library specific CMake flags. The following table is a listing of available flags:

| CMake Flag                               | Default Value | Description                                                                                                                                          |
|------------------------------------------|---------------|------------------------------------------------------------------------------------------------------------------------------------------------------|
| __LS_STD_BUILD_WITH_TESTS__              | OFF           | This flag can be enabled to build automated tests, like unit or integration tests.                                                                   |
| __LS_STD_BUILD_WITH_SUPPORTED_COMPILER__ | ON            | This flag enforces the usage of supported compilers, only.<br/>For usage of an unsupported toolchain, set this flag to __OFF__.                      |
| __LS_STD_BUILD_STATIC__                  | ON            | This flag indicates, that all library modules should be built as static goals.  <br/>Please note, that __LS_STD_BUILD_SHARED__ has to be turned off. |
| __LS_STD_BUILD_SHARED__                  | OFF           | This flag indicates, that all library modules should be built as shared goals.  <br/>Please note, that __LS_STD_BUILD_STATIC__ has to be turned off. |

To use one or more of these flags, you'd have to adjust previous command, like:

```
cmake -DLS_STD_BUILD_WITH_TESTS=ON ../
```

#### Compile Project ####

Now, that the CMake project is generated, you should find CMake generated files inside previously created build folder. In order to compile the project run:   

```
cmake --build . --config Release
```

Once compilation is done, you should find generated binaries within __cmake-build-release__ folder.

---
### Link ls-std Libraries (CMake) ###

If you would like to add this library's modules to your own CMake project, make sure that you would add the libraries' include directory:

```
include_directories(${CMAKE_CURRENT_LIST_DIR}/path/to/this/library/include)
```

Then link the libraries' binary files, like:

```
target_link_libraries(... ls-std-core ls-std-boxing ...)
```

---

### Run Automated Tests ###

When enabling test build CMake flag during CMake project generation, executable test suite binaries will be generated during project compilation.  
You would then find individual module test suites, as well as a whole project test suite, which can be run via CLI.
