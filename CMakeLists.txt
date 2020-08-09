##########################################################
# Basic
##########################################################

cmake_minimum_required(VERSION 3.17)
set(PROJECT_NAME ls_std)
project(${PROJECT_NAME})

##########################################################
# Compiler
##########################################################

message("${PROJECT_NAME}: Setting compiler flags...")
set(CMAKE_CXX_STANDARD 11)

######################################################
# Include Directories
######################################################

message("${PROJECT_NAME}: Adding include directories...")
include_directories(${CMAKE_CURRENT_LIST_DIR}/test/lib/googletest-1.8.1/googletest/include)

######################################################
# Add Other CMake Dependencies
######################################################

message("${PROJECT_NAME}: Adding additional cmake dependencies...")
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/test/lib/googletest-1.8.1)

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
        ${CMAKE_CURRENT_SOURCE_DIR}/source/base/Types.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/boxing/Boolean.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/boxing/Boolean.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/exception/IllegalArgumentException.hpp)

set(TEST_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/boxing/IntegerTest.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/boxing/BooleanTest.cpp)

##########################################################
# Build
##########################################################

message("${PROJECT_NAME}: Building...")

add_executable(${PROJECT_NAME}_test ${TEST_FILES})
add_library(${PROJECT_NAME} ${SOURCE_FILES})

##########################################################
# Linking
##########################################################

message("${PROJECT_NAME}: Linking...")
target_link_libraries(${PROJECT_NAME}_test gtest gtest_main ls_std)
