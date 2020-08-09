##########################################################
# Basic
##########################################################

cmake_minimum_required(VERSION 3.17)
set(PROJECT_NAME ls_std)
project(${PROJECT_NAME})

##########################################################
# Compiler
##########################################################

set(CMAKE_CXX_STANDARD 11)

##########################################################
# Source Files
##########################################################

set(SOURCE_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/source/boxing/Integer.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/base/Class.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/base/Class.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/boxing/Integer.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/boxing/IBoxing.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/exception/IllegalOperationException.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/base/Types.hpp)

##########################################################
# Build
##########################################################

add_library(${PROJECT_NAME} ${SOURCE_FILES})
