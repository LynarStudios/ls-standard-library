##########################################################
# Basic
##########################################################

cmake_minimum_required(VERSION 3.17)
project(ls_std VERSION 2021.1.0)

##########################################################
# Options
##########################################################

option(LS_STD_BUILD_WITH_TESTS "Build project with tests..." OFF)
option(LS_STD_BUILD_STATIC "Build ls_std static library..." ON)
option(LS_STD_BUILD_SHARED "Build ls_std shared library..." OFF)
option(LS_STD_BUILD_MODULE "Build ls_std module library..." OFF)

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

if (${LS_STD_BUILD_WITH_TESTS})
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/test)
    include_directories(${CMAKE_CURRENT_LIST_DIR}/test/lib/googletest-1.8.1/googletest/include)
    include_directories(${CMAKE_CURRENT_LIST_DIR}/test/lib/googletest-1.8.1/googlemock/include)
endif ()

include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

######################################################
# Add Other CMake Dependencies
######################################################

message("${PROJECT_NAME}: Adding additional cmake dependencies...")

if (${LS_STD_BUILD_WITH_TESTS})
    add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/test/lib/googletest-1.8.1)
endif ()

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
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/serialization/json/boxing/SerializableJsonInteger.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/serialization/json/boxing/SerializableJsonLong.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/serialization/json/boxing/SerializableJsonString.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/serialization/json/boxing/SerializableJsonFloat.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/serialization/json/boxing/SerializableJsonDouble.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/serialization/json/boxing/SerializableJsonBoolean.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/logic/StateMachine.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/logic/State.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/logic/StateConnection.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/serialization/json/logic/SerializableJsonStateConnection.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/serialization/json/logic/SerializableJsonState.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/serialization/json/logic/SerializableJsonStateMachine.cpp
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
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/event/EventManager.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/serialization/json/event/SerializableJsonEvent.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/io/kv/KVPair.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/io/kv/KVDocument.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/io/kv/KVParser.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/io/kv/KVReader.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/factory/serialization/json/SerializableJsonFactory.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/factory/serialization/json/boxing/SerializableJsonBooleanFactory.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/factory/serialization/json/boxing/SerializableJsonDoubleFactory.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/factory/serialization/json/boxing/SerializableJsonFloatFactory.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/factory/serialization/json/boxing/SerializableJsonIntegerFactory.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/factory/serialization/json/boxing/SerializableJsonLongFactory.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/factory/serialization/json/boxing/SerializableJsonStringFactory.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/factory/serialization/json/event/SerializableJsonEventFactory.cpp)

if (${LS_STD_BUILD_WITH_TESTS})
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
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/serialization/json/JsonTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/serialization/json/boxing/SerializableJsonIntegerTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/serialization/json/boxing/SerializableJsonLongTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/serialization/json/boxing/SerializableJsonStringTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/serialization/json/boxing/SerializableJsonFloatTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/serialization/json/boxing/SerializableJsonDoubleTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/serialization/json/boxing/SerializableJsonBooleanTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/logic/StateTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/logic/StateMachineTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/logic/StateConnectionTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/serialization/json/logic/SerializableJsonStateConnectionTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/serialization/json/logic/SerializableJsonStateTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/serialization/json/logic/SerializableJsonStateMachineTest.cpp
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
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/event/EventManagerTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/serialization/json/event/SerializableJsonEventTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/io/kv/KVPairTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/io/kv/KVDocumentTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/io/kv/KVParserTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/io/kv/KVReaderTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/factory/serialization/json/SerializableFactoryTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/factory/serialization/json/boxing/SerializableJsonBooleanFactoryTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/factory/serialization/json/boxing/SerializableJsonDoubleFactoryTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/factory/serialization/json/boxing/SerializableJsonFloatFactoryTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/factory/serialization/json/boxing/SerializableJsonIntegerFactoryTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/factory/serialization/json/boxing/SerializableJsonLongFactoryTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/factory/serialization/json/boxing/SerializableJsonStringFactoryTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/factory/serialization/json/event/SerializableJsonEventFactoryTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/classes/factory/SerializableTestFactory.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/exception/FileNotFoundExceptionTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/exception/FileOperationExceptionTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/exception/IllegalArgumentExceptionTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/exception/IllegalArithmeticOperationExceptionTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/exception/IncompleteJsonExceptionTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/exception/NullPointerExceptionTest.cpp)
endif ()

##########################################################
# Build Tests
##########################################################

if (${LS_STD_BUILD_WITH_TESTS})
    message("${PROJECT_NAME}: Building tests...")
    add_executable(${PROJECT_NAME}_test ${TEST_FILES})
endif ()

##########################################################
# Build Library
##########################################################

message("${PROJECT_NAME}: Building library version ${PROJECT_VERSION}...")

if (${LS_STD_BUILD_STATIC})
    add_library("${PROJECT_NAME}_${PROJECT_VERSION}_static" STATIC ${SOURCE_FILES})
    set_target_properties("${PROJECT_NAME}_${PROJECT_VERSION}_static" PROPERTIES DEBUG_POSTFIX "_d")
endif ()

if (${LS_STD_BUILD_SHARED})
    add_library("${PROJECT_NAME}_${PROJECT_VERSION}_shared" SHARED ${SOURCE_FILES})
    set_target_properties("${PROJECT_NAME}_${PROJECT_VERSION}_shared" PROPERTIES DEBUG_POSTFIX "_d")
endif ()

if (${LS_STD_BUILD_MODULE})
    add_library("${PROJECT_NAME}_${PROJECT_VERSION}_module" MODULE ${SOURCE_FILES})
    set_target_properties("${PROJECT_NAME}_${PROJECT_VERSION}_module" PROPERTIES DEBUG_POSTFIX "_d")
endif ()

##########################################################
# Linking
##########################################################

if (${LS_STD_BUILD_WITH_TESTS})
    message("${PROJECT_NAME}: Linking libraries for test application...")

    if (WIN32)
        SET(CMAKE_FIND_LIBRARY_PREFIXES "")
        SET(CMAKE_FIND_LIBRARY_SUFFIXES ".lib" ".dll")

        find_library(WSOCK32_LIBRARY wsock32)
        find_library(WS2_32_LIBRARY ws2_32)
        message("${PROJECT_NAME}: library search - ${WSOCK32_LIBRARY}...")
        message("${PROJECT_NAME}: library search - ${WS2_32_LIBRARY}...")

        target_link_libraries(${PROJECT_NAME}_test gtest gmock gtest_main "${WSOCK32_LIBRARY}" "${WS2_32_LIBRARY}" "${PROJECT_NAME}_${PROJECT_VERSION}_static")
    endif ()

    if (UNIX)
        target_link_libraries(${PROJECT_NAME}_test gtest gmock gtest_main "${PROJECT_NAME}_${PROJECT_VERSION}_static")
    endif ()
endif ()
