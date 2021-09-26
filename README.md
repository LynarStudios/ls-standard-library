# Lynar Studios - Standard Library 2021.2.0 #

This is a cross-platform standard library written in C++ offering functionalities you'd usually miss in C++ standard library, especially if you'd search for cross-platform implementations. This library has been tested on __Windows__, __Linux__ and __MacOS__ systems.
 
#### Boxing ####

This library provides boxing classes for primitive data types (e.g. string, int, long, float...) to add additional functionalities for each one of them.
 
#### File ####

To handle file operations - or to receive information of a file - this library provides an own __File__ class implementation, which can also be passed to library implemented input or output stream classes.

#### Base ####

This is a collection of very basic functionalities like a base __Class__ which provides minimal reflection like class name. Also, you have the possibility with this collection to fetch this libraries version or even handle own versions for your project.

#### Time ####

A __Date__ class comes with this collection, which you can use to represent a date and doing operations on it. 

#### Logic ####

This collection of classes provides some nice functionalities to support your project with some nice logical features, like state machines and observer pattern supporting classes.

#### Serialization ####

Serialization is very important nowadays to persist data. This library offers a serializable interface, which can then be implemented in your project.  
In addition to that there is already JSON serialization-based implementation for some public library classes.

#### JSON ####

This library uses a transitive JSON dependency, which is in line with our license model. Many thanks to __Niels Lohmann__ for writing this nice little library.

#### XML ####

To handle XML files this library has an own XML parser implementation, which uses modern C++ features, such as shared pointers.

#### Logger ####

For logging functionality you might need for your project there is a __Logger__ class coming with this library, which is also able to handle different log level.

#### Event Handling ####

With this first implemented milestone of event handling this library provides functionalities for creating and firing events.

#### Exception ####

This library provides some basic exceptions which can be used in your project to create awareness of certain error behaviour.

#### KV ####

A key value file offers the possibility to store simple information pairs in a file. This library provides parsing functionalities for __.kv__ files.

### Changelog ###

#### Features ####

- extended EventManager class by adding EventHandler availability check method
- added exceptions for event management
- extended Date class by introducing __+=__ and __-=__ operators
- it's now possible to retrieve library version
- added more operators to __LogLevel__ class
- added factory interface

#### Improvements ####

- increased test coverage by adding more unit tests
- improved overall error handling by adding more error checks
- reduced overall unnecessary complexity of public classes 
- improved naming of certain classes

#### Fixes ####

- add missing header files to main header file

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
