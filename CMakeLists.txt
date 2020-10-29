##########################################################
# Basic
##########################################################

cmake_minimum_required(VERSION 3.17)
set(PROJECT_NAME ls_std)
set(RELEASE_VERSION 2020.1.0)
project(${PROJECT_NAME})

##########################################################
# Compiler
##########################################################

message("${PROJECT_NAME}: Setting compiler flags...")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")

######################################################
# Include Directories
######################################################

message("${PROJECT_NAME}: Adding include directories...")

include_directories(${CMAKE_CURRENT_LIST_DIR}/test/lib/googletest-1.8.1/googletest/include)
include_directories(${CMAKE_CURRENT_LIST_DIR}/source/lib/nlohmann_json/include/nlohmann)
include_directories(${CMAKE_CURRENT_LIST_DIR}/source/lib/rapid_xml/include)
include_directories(${CMAKE_CURRENT_LIST_DIR}/source/lib/tiny_xml_2/include)

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
        ${CMAKE_CURRENT_SOURCE_DIR}/source/io/logging/LogLevelValue.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/serialization/ISerializable.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/serialization/json/boxing/SerializableJSONInteger.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/serialization/json/boxing/SerializableJSONInteger.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/serialization/json/boxing/SerializableJSONLong.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/serialization/json/boxing/SerializableJSONLong.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/serialization/json/boxing/SerializableJSONString.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/serialization/json/boxing/SerializableJSONString.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/serialization/json/boxing/SerializableJSONFloat.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/serialization/json/boxing/SerializableJSONFloat.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/serialization/json/boxing/SerializableJSONDouble.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/serialization/json/boxing/SerializableJSONDouble.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/serialization/json/boxing/SerializableJSONBoolean.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/serialization/json/boxing/SerializableJSONBoolean.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/logic/StateMachine.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/logic/StateMachine.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/logic/State.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/logic/State.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/logic/StateConnection.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/logic/StateConnection.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/logic/StateMachineTypes.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/serialization/json/logic/SerializableJSONStateConnection.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/serialization/json/logic/SerializableJSONStateConnection.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/serialization/json/logic/SerializableJSONState.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/serialization/json/logic/SerializableJSONState.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/serialization/json/logic/SerializableJSONStateMachine.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/serialization/json/logic/SerializableJSONStateMachine.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/io/xml/XMLAttribute.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/io/xml/XMLAttribute.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/io/xml/XMLNode.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/io/xml/XMLNode.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/io/xml/XMLDocument.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/io/xml/XMLDeclaration.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/base/Version.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/base/Version.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/io/xml/XMLDeclaration.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/io/xml/XMLDocument.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/io/xml/XMLReader.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/io/xml/XMLReader.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/io/xml/XMLParseMode.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/io/xml/XMLParseData.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/io/xml/XMLReaderMock.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/io/xml/XMLReaderMock.cpp)

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
        ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/serialization/json/JSONTest.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/serialization/json/boxing/SerializableJSONIntegerTest.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/serialization/json/boxing/SerializableJSONLongTest.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/serialization/json/boxing/SerializableJSONStringTest.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/serialization/json/boxing/SerializableJSONFloatTest.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/serialization/json/boxing/SerializableJSONDoubleTest.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/serialization/json/boxing/SerializableJSONBooleanTest.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/logic/StateTest.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/logic/StateMachineTest.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/logic/StateConnectionTest.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/serialization/json/logic/SerializableJSONStateConnectionTest.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/serialization/json/logic/SerializableJSONStateTest.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/serialization/json/logic/SerializableJSONStateMachineTest.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/test/TestDataFactory.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/test/TestDataFactory.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/io/xml/XMLAttributeTest.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/io/xml/XMLNodeTest.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/base/VersionTest.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/io/xml/XMLDeclarationTest.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/io/xml/XMLDocumentTest.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/io/xml/XMLReaderTest.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/io/xml/XMLReaderMockTest.cpp)

##########################################################
# Build
##########################################################

message("${PROJECT_NAME}: Building version ${RELEASE_VERSION}...")

add_executable(${PROJECT_NAME}_test ${TEST_FILES})
add_library("${PROJECT_NAME}_${RELEASE_VERSION}_static" ${SOURCE_FILES})
add_library("${PROJECT_NAME}_${RELEASE_VERSION}" SHARED ${SOURCE_FILES})

##########################################################
# Linking
##########################################################

message("${PROJECT_NAME}: Linking...")
target_link_libraries(${PROJECT_NAME}_test gtest gtest_main "${PROJECT_NAME}_${RELEASE_VERSION}_static")
