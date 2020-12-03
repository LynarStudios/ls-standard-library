# Lynar Studios - Standard Library 2020.3.0 #

This is a cross-platform standard library written in C++ which provides basic functionality and implementation, like:
 
- Boxing Classes
- File Operations
- Minimal Reflection
- Date Class
- State Machine Class
- Serialization
- JSON
- XML
- Logger Class
- Event Handling

It has been tested on __Windows__, __Linux__ and __MacOS__ systems.

### Changelog ###

- added event handling functionality
- added observer pattern classes
- added xml parser class by reducing complexity of xml reader class
- ls_std::Class is now polymorphic
- fixed some include directives 
- made existing serialization classes flyweight classes

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

This project contains unit tests to accomplish test coverage.  
To run those unit tests you have to adjust __TestHelper__ class by adding your personal test folder path to __getTestFolderLocation__ method.  
There you have to adjust __location__ variable based on the operating system you're using.
