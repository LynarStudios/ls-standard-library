####################################################################################################################
####################################################################################################################
####################################################################################################################
# General
####################################################################################################################
####################################################################################################################
####################################################################################################################

##########################################################
# Basic
##########################################################

cmake_minimum_required(VERSION 3.17)
project(ls_std VERSION 2022.2.0)

set(MODULE_NAME_BOXING ls_std_boxing)
set(MODULE_NAME_CORE ls_std_core)
set(MODULE_NAME_ENCODING ls_std_encoding)
set(MODULE_NAME_EVENT ls_std_event)
set(MODULE_NAME_IO ls_std_io)
set(MODULE_NAME_LOGIC ls_std_logic)
set(MODULE_NAME_TIME ls_std_time)

set(GOOGLE_TEST_MODULE googletest-1.11.0)

##########################################################
# Options
##########################################################

option(LS_STD_BUILD_WITH_TESTS "Build project with tests..." ON)
option(LS_STD_BUILD_WITH_SUPPORTED_COMPILER "Build project with supported compiler only..." ON)
option(LS_STD_BUILD_STATIC "Build ls_std static library..." ON)
option(LS_STD_BUILD_SHARED "Build ls_std shared library..." OFF)
option(LS_STD_BUILD_MODULE "Build ls_std module library..." OFF)

set(TARGET_COUNTER 0)

if (${LS_STD_BUILD_STATIC})
    math(EXPR TARGET_COUNTER "${TARGET_COUNTER} + 1")
    set(GOAL "static library")
endif ()

if (${LS_STD_BUILD_SHARED})
    math(EXPR TARGET_COUNTER "${TARGET_COUNTER} + 1")
    set(GOAL "shared library")
endif ()

if (${LS_STD_BUILD_MODULE})
    math(EXPR TARGET_COUNTER "${TARGET_COUNTER} + 1")
    set(GOAL "module library")
endif ()

message("${PROJECT_NAME}: [Goal] ${GOAL}")

if (TARGET_COUNTER GREATER 1)
    message("${PROJECT_NAME}: [Error] only one goal supported at the same time!")
    return()
endif ()

if (TARGET_COUNTER EQUAL 0)
    message("${PROJECT_NAME}: [Error] no goal selected!")
    return()
endif ()

##########################################################
# Compiler Settings
##########################################################

message("${PROJECT_NAME}: Setting compiler flags...")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

##########################################################
# Compiler Support
##########################################################

if(${LS_STD_BUILD_WITH_SUPPORTED_COMPILER})
    message("${PROJECT_NAME}: build with compiler support...")

    # define supported compilers

    if (${CMAKE_CXX_COMPILER_ID} STREQUAL MSVC OR ${CMAKE_CXX_COMPILER_ID} STREQUAL GNU)
        message("${PROJECT_NAME}: ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION} is supported...")
    else()
        message("${PROJECT_NAME}: [Error] ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION} is not supported... terminated!")
        return()
    endif ()

    # define which compilers are supported for shared or module goal

    if (${CMAKE_CXX_COMPILER_ID} STREQUAL MSVC AND ${LS_STD_BUILD_MODULE})
        message("${PROJECT_NAME}: [Error] building \"${GOAL}\" with ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION} is not supported... terminated!")
        return()
    endif ()
endif()

# define which goals can run tests

if (${LS_STD_BUILD_WITH_TESTS} AND ${LS_STD_BUILD_MODULE})
    message("${PROJECT_NAME}: [Error] building \"${GOAL}\" with tests is not supported... terminated!")
    return()
endif ()

######################################################
# Include Directories
######################################################

message("${PROJECT_NAME}: Adding include directories...")

if (${LS_STD_BUILD_WITH_TESTS})
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/test)
    include_directories(${CMAKE_CURRENT_LIST_DIR}/test/lib/${GOOGLE_TEST_MODULE}/googletest/include)
    include_directories(${CMAKE_CURRENT_LIST_DIR}/test/lib/${GOOGLE_TEST_MODULE}/googlemock/include)
endif ()

include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

######################################################
# Add Other CMake Dependencies
######################################################

message("${PROJECT_NAME}: Adding additional cmake dependencies...")

if (${LS_STD_BUILD_WITH_TESTS})
    add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/test/lib/${GOOGLE_TEST_MODULE})
endif ()

####################################################################################################################
####################################################################################################################
####################################################################################################################
# Source Files Modularization
####################################################################################################################
####################################################################################################################
####################################################################################################################

set(SOURCE_FILES_BOXING
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/boxing/Boolean.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/boxing/Double.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/boxing/Float.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/boxing/Integer.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/boxing/Long.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/boxing/String.cpp)

set(SOURCE_FILES_CORE
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/core/Class.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/core/Version.cpp)

set(SOURCE_FILES_ENCODING
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/encoding/Base64.cpp)

set(SOURCE_FILES_EVENT
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/event/serialization/SerializableJsonEvent.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/event/Event.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/event/EventHandler.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/event/EventManager.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/event/Narrator.cpp)

set(SOURCE_FILES_IO
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/io/kv/KvDocument.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/io/kv/KvFileReader.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/io/kv/KvPair.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/io/kv/KvParser.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/io/logging/Logger.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/io/logging/LogLevel.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/io/xml/XmlAttribute.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/io/xml/XmlDeclaration.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/io/xml/XmlDocument.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/io/xml/XmlNode.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/io/xml/XmlParser.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/io/xml/XmlReader.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/io/File.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/io/FileOutputStream.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/io/FileReader.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/io/FileWriter.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/io/StandardOutputWriter.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/io/StorableFile.cpp)

set(SOURCE_FILES_LOGIC
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/logic/serialization/SerializableJsonState.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/logic/serialization/SerializableJsonStateConnection.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/logic/serialization/SerializableJsonStateMachine.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/logic/State.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/logic/StateConnection.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/logic/StateMachine.cpp)

set(SOURCE_FILES_TIME
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls_std/time/Date.cpp)

####################################################################################################################
####################################################################################################################
####################################################################################################################
# Test Files Modularization
####################################################################################################################
####################################################################################################################
####################################################################################################################

if (${LS_STD_BUILD_WITH_TESTS})
    set(TEST_FILES_BOXING
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/boxing/BooleanTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/boxing/DoubleTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/boxing/FloatTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/boxing/IntegerTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/boxing/LongTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/boxing/StringTest.cpp)

    set(TEST_FILES_CORE
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/core/exception/EventNotHandledExceptionTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/core/exception/EventNotSubscribedExceptionTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/core/exception/FileNotFoundExceptionTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/core/exception/FileOperationExceptionTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/core/exception/IllegalArgumentExceptionTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/core/exception/IllegalArithmeticOperationExceptionTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/core/exception/IncompleteJsonExceptionTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/core/exception/NullPointerExceptionTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/core/utils/RegexUtilsTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/core/utils/STLUtilsTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/core/ClassTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/core/LibraryVersionTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/core/VersionTest.cpp)

    set(TEST_FILES_ENCODING
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/encoding/Base64Test.cpp)

    set(TEST_FILES_EVENT
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/event/serialization/SerializableJsonEventTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/event/EventHandlerTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/event/EventManagerTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/event/EventTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/event/NarratorTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/classes/event/Colour.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/classes/event/DailyNewsAgency.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/classes/event/GossipNewsAgency.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/classes/event/GossipNewsEvent.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/classes/event/NewsAgency.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/classes/event/SeriousNewsEvent.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/classes/event/TestDataCar.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/classes/event/TestDataMercedesCar.cpp)

    set(TEST_FILES_IO
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/io/kv/KvDocumentTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/io/kv/KvFileReaderTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/io/kv/KvPairTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/io/kv/KvParserTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/io/logging/LoggerTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/io/logging/LogLevelTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/io/xml/XmlAttributeTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/io/xml/XmlDeclarationTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/io/xml/XmlDocumentTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/io/xml/XmlNodeTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/io/xml/XmlParserTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/io/xml/XmlParserTestWrapperTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/io/xml/XmlReaderTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/io/FileOutputStreamTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/io/FileReaderTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/io/FileTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/io/FileWriterTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/io/StandardOutputWriterTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/io/StorableFileTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/classes/io/xml/TestDataFactory.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/classes/io/xml/XmlParserTestWrapper.cpp)

    set(TEST_FILES_LOGIC
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/logic/serialization/SerializableJsonStateConnectionTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/logic/serialization/SerializableJsonStateMachineTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/logic/serialization/SerializableJsonStateTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/logic/StateConnectionTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/logic/StateMachineTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/logic/StateTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/classes/logic/TestDataFactory.cpp)

    set(TEST_FILES_SERIALIZATION
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/serialization/JsonTest.cpp)

    set(TEST_FILES_TIME
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/time/DateTest.cpp)
endif ()

####################################################################################################################
####################################################################################################################
####################################################################################################################
# Test Suite Builds
####################################################################################################################
####################################################################################################################
####################################################################################################################

##########################################################
# Build Tests (boxing)
##########################################################

if (${LS_STD_BUILD_WITH_TESTS})
    message("${MODULE_NAME_BOXING}: Building tests...")
    add_executable(${MODULE_NAME_BOXING}_test ${TEST_FILES_BOXING})
endif ()

##########################################################
# Build Tests (core)
##########################################################

if (${LS_STD_BUILD_WITH_TESTS})
    message("${MODULE_NAME_CORE}: Building tests...")
    add_executable(${MODULE_NAME_CORE}_test ${TEST_FILES_CORE})
endif ()

##########################################################
# Build Tests (encoding)
##########################################################

if (${LS_STD_BUILD_WITH_TESTS})
    message("${MODULE_NAME_ENCODING}: Building tests...")
    add_executable(${MODULE_NAME_ENCODING}_test ${TEST_FILES_ENCODING})
endif ()

##########################################################
# Build Tests (event)
##########################################################

if (${LS_STD_BUILD_WITH_TESTS})
    message("${MODULE_NAME_EVENT}: Building tests...")
    add_executable(${MODULE_NAME_EVENT}_test ${TEST_FILES_EVENT})
endif ()

##########################################################
# Build Tests (io)
##########################################################

if (${LS_STD_BUILD_WITH_TESTS})
    message("${MODULE_NAME_IO}: Building tests...")
    add_executable(${MODULE_NAME_IO}_test ${TEST_FILES_IO})
endif ()

##########################################################
# Build Tests (logic)
##########################################################

if (${LS_STD_BUILD_WITH_TESTS})
    message("${MODULE_NAME_LOGIC}: Building tests...")
    add_executable(${MODULE_NAME_LOGIC}_test ${TEST_FILES_LOGIC})
endif ()

##########################################################
# Build Tests (time)
##########################################################

if (${LS_STD_BUILD_WITH_TESTS})
    message("${MODULE_NAME_TIME}: Building tests...")
    add_executable(${MODULE_NAME_TIME}_test ${TEST_FILES_TIME})
endif ()

##########################################################
# Build Tests (all)
##########################################################

if (${LS_STD_BUILD_WITH_TESTS})
    message("${PROJECT_NAME}: Building tests...")
    add_executable(${PROJECT_NAME}_test
            ${TEST_FILES_BOXING}
            ${TEST_FILES_CORE}
            ${TEST_FILES_ENCODING}
            ${TEST_FILES_EVENT}
            ${TEST_FILES_IO}
            ${TEST_FILES_LOGIC}
            ${TEST_FILES_SERIALIZATION}
            ${TEST_FILES_TIME})
endif ()

####################################################################################################################
####################################################################################################################
####################################################################################################################
# Build Library Binaries
####################################################################################################################
####################################################################################################################
####################################################################################################################

##########################################################
# Build Library (boxing)
##########################################################

message("${PROJECT_NAME}: Building ${MODULE_NAME_BOXING} library version ${PROJECT_VERSION}...")

if (${LS_STD_BUILD_STATIC})
    add_library("${MODULE_NAME_BOXING}" STATIC ${SOURCE_FILES_BOXING})
    set_target_properties("${MODULE_NAME_BOXING}" PROPERTIES DEBUG_POSTFIX "_d")
endif ()

if (${LS_STD_BUILD_SHARED})
    add_library("${MODULE_NAME_BOXING}" SHARED ${SOURCE_FILES_BOXING})
    target_link_libraries("${MODULE_NAME_BOXING}" ${MODULE_NAME_CORE})
    set_target_properties("${MODULE_NAME_BOXING}" PROPERTIES DEBUG_POSTFIX "_d")
endif ()

if (${LS_STD_BUILD_MODULE})
    add_library("${MODULE_NAME_BOXING}" MODULE ${SOURCE_FILES_BOXING})
    set_target_properties("${MODULE_NAME_BOXING}" PROPERTIES DEBUG_POSTFIX "_d")
endif ()

##########################################################
# Build Library (core)
##########################################################

message("${PROJECT_NAME}: Building ${MODULE_NAME_CORE} library version ${PROJECT_VERSION}...")

if (${LS_STD_BUILD_STATIC})
    add_library("${MODULE_NAME_CORE}" STATIC ${SOURCE_FILES_CORE})
    set_target_properties("${MODULE_NAME_CORE}" PROPERTIES DEBUG_POSTFIX "_d")
endif ()

if (${LS_STD_BUILD_SHARED})
    add_library("${MODULE_NAME_CORE}" SHARED ${SOURCE_FILES_CORE})
    set_target_properties("${MODULE_NAME_CORE}" PROPERTIES DEBUG_POSTFIX "_d")
endif ()

if (${LS_STD_BUILD_MODULE})
    add_library("${MODULE_NAME_CORE}" MODULE ${SOURCE_FILES_CORE})
    set_target_properties("${MODULE_NAME_CORE}" PROPERTIES DEBUG_POSTFIX "_d")
endif ()

##########################################################
# Build Library (encoding)
##########################################################

message("${PROJECT_NAME}: Building ${MODULE_NAME_ENCODING} library version ${PROJECT_VERSION}...")

if (${LS_STD_BUILD_STATIC})
    add_library("${MODULE_NAME_ENCODING}" STATIC ${SOURCE_FILES_ENCODING})
    set_target_properties("${MODULE_NAME_ENCODING}" PROPERTIES DEBUG_POSTFIX "_d")
endif ()

if (${LS_STD_BUILD_SHARED})
    add_library("${MODULE_NAME_ENCODING}" SHARED ${SOURCE_FILES_ENCODING})
    set_target_properties("${MODULE_NAME_ENCODING}" PROPERTIES DEBUG_POSTFIX "_d")
endif ()

if (${LS_STD_BUILD_MODULE})
    add_library("${MODULE_NAME_ENCODING}" MODULE ${SOURCE_FILES_ENCODING})
    set_target_properties("${MODULE_NAME_ENCODING}" PROPERTIES DEBUG_POSTFIX "_d")
endif ()

##########################################################
# Build Library (event)
##########################################################

message("${PROJECT_NAME}: Building ${MODULE_NAME_EVENT} library version ${PROJECT_VERSION}...")

if (${LS_STD_BUILD_STATIC})
    add_library("${MODULE_NAME_EVENT}" STATIC ${SOURCE_FILES_EVENT})
    set_target_properties("${MODULE_NAME_EVENT}" PROPERTIES DEBUG_POSTFIX "_d")
endif ()

if (${LS_STD_BUILD_SHARED})
    add_library("${MODULE_NAME_EVENT}" SHARED ${SOURCE_FILES_EVENT})
    target_link_libraries("${MODULE_NAME_EVENT}" ${MODULE_NAME_CORE})
    set_target_properties("${MODULE_NAME_EVENT}" PROPERTIES DEBUG_POSTFIX "_d")
endif ()

if (${LS_STD_BUILD_MODULE})
    add_library("${MODULE_NAME_EVENT}" MODULE ${SOURCE_FILES_EVENT})
    set_target_properties("${MODULE_NAME_EVENT}" PROPERTIES DEBUG_POSTFIX "_d")
endif ()

##########################################################
# Build Library (io)
##########################################################

message("${PROJECT_NAME}: Building ${MODULE_NAME_IO} library version ${PROJECT_VERSION}...")

if (${LS_STD_BUILD_STATIC})
    add_library("${MODULE_NAME_IO}" STATIC ${SOURCE_FILES_IO})
    set_target_properties("${MODULE_NAME_IO}" PROPERTIES DEBUG_POSTFIX "_d")
endif ()

if (${LS_STD_BUILD_SHARED})
    add_library("${MODULE_NAME_IO}" SHARED ${SOURCE_FILES_IO})
    target_link_libraries("${MODULE_NAME_IO}" ${MODULE_NAME_CORE})
    set_target_properties("${MODULE_NAME_IO}" PROPERTIES DEBUG_POSTFIX "_d")
endif ()

if (${LS_STD_BUILD_MODULE})
    add_library("${MODULE_NAME_IO}" MODULE ${SOURCE_FILES_IO})
    set_target_properties("${MODULE_NAME_IO}" PROPERTIES DEBUG_POSTFIX "_d")
endif ()

##########################################################
# Build Library (logic)
##########################################################

message("${PROJECT_NAME}: Building ${MODULE_NAME_LOGIC} library version ${PROJECT_VERSION}...")

if (${LS_STD_BUILD_STATIC})
    add_library("${MODULE_NAME_LOGIC}" STATIC ${SOURCE_FILES_LOGIC})
    set_target_properties("${MODULE_NAME_LOGIC}" PROPERTIES DEBUG_POSTFIX "_d")
endif ()

if (${LS_STD_BUILD_SHARED})
    add_library("${MODULE_NAME_LOGIC}" SHARED ${SOURCE_FILES_LOGIC})
    target_link_libraries("${MODULE_NAME_LOGIC}" ${MODULE_NAME_CORE})
    set_target_properties("${MODULE_NAME_LOGIC}" PROPERTIES DEBUG_POSTFIX "_d")
endif ()

if (${LS_STD_BUILD_MODULE})
    add_library("${MODULE_NAME_LOGIC}" MODULE ${SOURCE_FILES_LOGIC})
    set_target_properties("${MODULE_NAME_LOGIC}" PROPERTIES DEBUG_POSTFIX "_d")
endif ()

##########################################################
# Build Library (time)
##########################################################

message("${PROJECT_NAME}: Building ${MODULE_NAME_TIME} library version ${PROJECT_VERSION}...")

if (${LS_STD_BUILD_STATIC})
    add_library("${MODULE_NAME_TIME}" STATIC ${SOURCE_FILES_TIME})
    set_target_properties("${MODULE_NAME_TIME}" PROPERTIES DEBUG_POSTFIX "_d")
endif ()

if (${LS_STD_BUILD_SHARED})
    add_library("${MODULE_NAME_TIME}" SHARED ${SOURCE_FILES_TIME})
    target_link_libraries("${MODULE_NAME_TIME}" ${MODULE_NAME_CORE})
    set_target_properties("${MODULE_NAME_TIME}" PROPERTIES DEBUG_POSTFIX "_d")
endif ()

if (${LS_STD_BUILD_MODULE})
    add_library("${MODULE_NAME_TIME}" MODULE ${SOURCE_FILES_TIME})
    set_target_properties("${MODULE_NAME_TIME}" PROPERTIES DEBUG_POSTFIX "_d")
endif ()

####################################################################################################################
####################################################################################################################
####################################################################################################################
# Test Suite: Linking
####################################################################################################################
####################################################################################################################
####################################################################################################################

##########################################################
# Linking (boxing)
##########################################################

if (${LS_STD_BUILD_WITH_TESTS})
    message("${MODULE_NAME_BOXING}: Linking libraries for test application...")
    target_link_libraries(${MODULE_NAME_BOXING}_test
            gtest
            gmock
            gtest_main
            "${MODULE_NAME_BOXING}"
            "${MODULE_NAME_CORE}")
endif ()

##########################################################
# Linking (core)
##########################################################

if (${LS_STD_BUILD_WITH_TESTS})
    message("${MODULE_NAME_CORE}: Linking libraries for test application...")
    target_link_libraries(${MODULE_NAME_CORE}_test
            gtest
            gmock
            gtest_main
            "${MODULE_NAME_CORE}")
endif ()

##########################################################
# Linking (encoding)
##########################################################

if (${LS_STD_BUILD_WITH_TESTS})
    message("${MODULE_NAME_ENCODING}: Linking libraries for test application...")
    target_link_libraries(${MODULE_NAME_ENCODING}_test
            gtest
            gmock
            gtest_main
            "${MODULE_NAME_ENCODING}"
            "${MODULE_NAME_CORE}")
endif ()

##########################################################
# Linking (event)
##########################################################

if (${LS_STD_BUILD_WITH_TESTS})
    message("${MODULE_NAME_EVENT}: Linking libraries for test application...")
    target_link_libraries(${MODULE_NAME_EVENT}_test
            gtest
            gmock
            gtest_main
            "${MODULE_NAME_EVENT}"
            "${MODULE_NAME_CORE}")
endif ()

##########################################################
# Linking (io)
##########################################################

if (${LS_STD_BUILD_WITH_TESTS})
    message("${MODULE_NAME_IO}: Linking libraries for test application...")
    target_link_libraries(${MODULE_NAME_IO}_test
            gtest
            gmock
            gtest_main
            "${MODULE_NAME_IO}"
            "${MODULE_NAME_CORE}")
endif ()

##########################################################
# Linking (logic)
##########################################################

if (${LS_STD_BUILD_WITH_TESTS})
    message("${MODULE_NAME_LOGIC}: Linking libraries for test application...")
    target_link_libraries(${MODULE_NAME_LOGIC}_test
            gtest
            gmock
            gtest_main
            "${MODULE_NAME_LOGIC}"
            "${MODULE_NAME_CORE}")
endif ()

##########################################################
# Linking (time)
##########################################################

if (${LS_STD_BUILD_WITH_TESTS})
    message("${MODULE_NAME_TIME}: Linking libraries for test application...")
    target_link_libraries(${MODULE_NAME_TIME}_test
            gtest
            gmock
            gtest_main
            "${MODULE_NAME_TIME}"
            "${MODULE_NAME_CORE}")
endif ()

##########################################################
# Linking (all)
##########################################################

if (${LS_STD_BUILD_WITH_TESTS})
    message("${PROJECT_NAME}: Linking libraries for test application...")
    target_link_libraries(${PROJECT_NAME}_test
            gtest
            gmock
            gtest_main
            "${MODULE_NAME_CORE}"
            "${MODULE_NAME_BOXING}"
            "${MODULE_NAME_ENCODING}"
            "${MODULE_NAME_EVENT}"
            "${MODULE_NAME_IO}"
            "${MODULE_NAME_LOGIC}"
            "${MODULE_NAME_TIME}")
endif ()
