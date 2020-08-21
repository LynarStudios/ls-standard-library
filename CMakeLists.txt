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
include_directories(${CMAKE_CURRENT_LIST_DIR}/source/lib/nlohmann_json/include/nlohmann)

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
        ${CMAKE_CURRENT_SOURCE_DIR}/source/exception/IllegalArithmeticOperationException.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/base/Types.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/boxing/Boolean.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/boxing/Boolean.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/exception/IllegalArgumentException.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/boxing/Float.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/boxing/Float.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/boxing/Double.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/boxing/Double.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/boxing/String.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/boxing/String.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/time/Date.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/time/Date.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/io/File.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/io/File.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/exception/FileOperationException.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/io/FilePathSeparatorMatch.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/io/FilePathSeparator.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/utils/STLUtils.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/boxing/Long.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/boxing/Long.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/io/IWriter.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/io/FileWriter.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/io/FileWriter.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/exception/FileNotFoundException.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/io/IReader.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/io/FileReader.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/io/FileReader.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/io/NewLine.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/utils/RegexUtils.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/io/IStorable.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/io/StorableFile.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/io/StorableFile.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/io/logging/LogLevel.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/io/FileOutputStream.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/io/FileOutputStream.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/io/logging/Logger.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/io/logging/Logger.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/io/logging/LogLevel.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/io/logging/LogLevelValue.hpp)

set(TEST_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/boxing/IntegerTest.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/boxing/BooleanTest.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/boxing/FloatTest.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/boxing/DoubleTest.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/boxing/StringTest.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/time/DateTest.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/io/FileTest.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/test/TestHelper.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/base/ClassTest.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/utils/STLUtilsTest.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/boxing/LongTest.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/io/FileWriterTest.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/io/FileReaderTest.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/utils/RegexUtilsTest.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/io/StorableFileTest.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/io/FileOutputStreamTest.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/io/logging/LoggerTest.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/json/JSONTest.cpp)

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
