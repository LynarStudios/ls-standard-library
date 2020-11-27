##########################################################
# Basic
##########################################################

cmake_minimum_required(VERSION 3.17)
set(PROJECT_NAME ls_std)
set(RELEASE_VERSION 2020.2.3)
project(${PROJECT_NAME})

##########################################################
# Compiler Settings
##########################################################

message("${PROJECT_NAME}: Setting compiler flags...")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

######################################################
# Include Directories
######################################################

message("${PROJECT_NAME}: Adding include directories...")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/test)
include_directories(${CMAKE_CURRENT_LIST_DIR}/test/lib/googletest-1.8.1/googletest/include)
include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

######################################################
# Add Other CMake Dependencies
######################################################

message("${PROJECT_NAME}: Adding additional cmake dependencies...")
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/test/lib/googletest-1.8.1)

##########################################################
# Source Files
##########################################################

set(SOURCE_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/base/Class.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/boxing/Integer.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/boxing/Boolean.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/boxing/Float.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/boxing/Double.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/boxing/String.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/time/Date.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/io/File.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/boxing/Long.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/io/FileWriter.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/io/FileReader.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/io/StorableFile.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/io/FileOutputStream.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/io/logging/Logger.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/io/logging/LogLevel.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/serialization/json/boxing/SerializableJSONInteger.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/serialization/json/boxing/SerializableJSONLong.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/serialization/json/boxing/SerializableJSONString.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/serialization/json/boxing/SerializableJSONFloat.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/serialization/json/boxing/SerializableJSONDouble.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/serialization/json/boxing/SerializableJSONBoolean.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/logic/StateMachine.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/logic/State.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/logic/StateConnection.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/serialization/json/logic/SerializableJSONStateConnection.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/serialization/json/logic/SerializableJSONState.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/serialization/json/logic/SerializableJSONStateMachine.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/io/xml/XMLAttribute.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/io/xml/XMLNode.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/base/Version.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/io/xml/XMLDeclaration.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/io/xml/XMLDocument.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/io/xml/XMLReader.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/io/xml/XMLParserMock.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/io/StandardOutputWriter.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/logic/Narrator.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/logic/IListener.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/io/xml/XMLParser.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/event/Event.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/event/EventHandler.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/event/EventManager.cpp)

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
        ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/io/xml/XMLParserMockTest.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/test/classes/observer/TestDataCar.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/test/classes/observer/TestDataMercedesCar.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/logic/NarratorTest.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/io/xml/XMLParserTest.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/event/EventTest.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/test/classes/event/NewsAgency.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/test/classes/event/DailyNewsAgency.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/test/classes/event/SeriousNewsEvent.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/test/classes/event/GossipNewsEvent.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/test/classes/event/GossipNewsAgency.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/event/EventHandlerTest.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/event/EventManagerTest.cpp)

##########################################################
# Build
##########################################################

message("${PROJECT_NAME}: Building version ${RELEASE_VERSION}...")

add_executable(${PROJECT_NAME}_test ${TEST_FILES})

add_library("${PROJECT_NAME}_${RELEASE_VERSION}_static" STATIC ${SOURCE_FILES})
set_target_properties("${PROJECT_NAME}_${RELEASE_VERSION}_static" PROPERTIES DEBUG_POSTFIX "_d")

add_library("${PROJECT_NAME}_${RELEASE_VERSION}_shared" SHARED ${SOURCE_FILES})
set_target_properties("${PROJECT_NAME}_${RELEASE_VERSION}_shared" PROPERTIES DEBUG_POSTFIX "_d")

add_library("${PROJECT_NAME}_${RELEASE_VERSION}_module" MODULE ${SOURCE_FILES})
set_target_properties("${PROJECT_NAME}_${RELEASE_VERSION}_module" PROPERTIES DEBUG_POSTFIX "_d")

##########################################################
# Linking
##########################################################

message("${PROJECT_NAME}: Linking...")
target_link_libraries(${PROJECT_NAME}_test gtest gtest_main "${PROJECT_NAME}_${RELEASE_VERSION}_static")
