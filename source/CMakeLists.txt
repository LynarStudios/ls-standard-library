cmake_minimum_required(VERSION 3.17)
set(PROJECT_NAME ls_std)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/boxing/Integer.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/base/Class.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/base/Class.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/boxing/Integer.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/boxing/IBoxing.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/exception/IllegalOperationException.hpp)

add_library(${PROJECT_NAME} ${SOURCE_FILES})
