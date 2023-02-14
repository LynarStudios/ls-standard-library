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
project(ls-std VERSION 2023.1.0)

set(MODULE_NAME_BOXING ls-std-boxing)
set(MODULE_NAME_CORE ls-std-core)
set(MODULE_NAME_ENCODING ls-std-encoding)
set(MODULE_NAME_EVENT ls-std-event)
set(MODULE_NAME_IO ls-std-io)
set(MODULE_NAME_TIME ls-std-time)

set(GOOGLE_TEST_MODULE googletest-1.11.0)

set(CLI_NAME_BASE64 cli-base64)

##########################################################
# Options
##########################################################

option(LS_STD_BUILD_WITH_TESTS "Build project with tests..." OFF)
option(LS_STD_BUILD_WITH_SUPPORTED_COMPILER "Build project with supported compiler only..." ON)
option(LS_STD_BUILD_STATIC "Build ls-std static library..." ON)
option(LS_STD_BUILD_SHARED "Build ls-std shared library..." OFF)

set(TARGET_COUNTER 0)

if (${LS_STD_BUILD_STATIC})
    math(EXPR TARGET_COUNTER "${TARGET_COUNTER} + 1")
    set(GOAL "static library")
endif ()

if (${LS_STD_BUILD_SHARED})
    math(EXPR TARGET_COUNTER "${TARGET_COUNTER} + 1")
    set(GOAL "shared library")
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

    if (${CMAKE_CXX_COMPILER_ID} STREQUAL MSVC OR
            ${CMAKE_CXX_COMPILER_ID} STREQUAL GNU OR
            ${CMAKE_CXX_COMPILER_ID} STREQUAL Clang OR
            ${CMAKE_CXX_COMPILER_ID} STREQUAL AppleClang)
        message("${PROJECT_NAME}: ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION} is supported...")
    else()
        message("${PROJECT_NAME}: [Error] ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION} is not supported... terminated!")
        return()
    endif ()
endif()

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
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/boxing/Boolean.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/boxing/Double.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/boxing/Float.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/boxing/Integer.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/boxing/Long.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/boxing/String.cpp)

set(SOURCE_FILES_CORE
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/core/evaluator/EmptyStringArgumentEvaluator.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/core/evaluator/IndexOutOfBoundsEvaluator.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/core/evaluator/NullPointerArgumentEvaluator.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/core/evaluator/NullPointerEvaluator.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/core/exception/EventNotHandledException.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/core/exception/EventNotSubscribedException.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/core/exception/ExceptionMessage.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/core/exception/FileNotFoundException.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/core/exception/FileOperationException.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/core/exception/IllegalArgumentException.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/core/exception/IllegalArithmeticOperationException.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/core/exception/IncompleteJsonException.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/core/exception/IndexOutOfBoundsException.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/core/exception/NullPointerException.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/core/exception/WrongCallException.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/core/interface/IBoxing.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/core/interface/IEncoding.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/core/interface/IEvaluator.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/core/interface/IEventSubscriber.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/core/interface/IListener.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/core/interface/IReader.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/core/interface/ISerializable.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/core/interface/IStorable.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/core/interface/IValidator.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/core/interface/IWriter.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/core/Class.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/core/ConditionalFunctionExecutor.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/core/LibraryVersion.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/core/Version.cpp)

set(SOURCE_FILES_ENCODING
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/encoding/Base64.cpp)

set(SOURCE_FILES_EVENT
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/event/serialization/SerializableJsonEvent.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/event/Event.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/event/EventHandler.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/event/EventManager.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/event/Narrator.cpp)

set(SOURCE_FILES_IO
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/io/kv/KvDocument.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/io/kv/KvFileReader.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/io/kv/KvPair.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/io/kv/KvParseParameter.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/io/kv/KvParser.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/io/logging/Logger.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/io/logging/LogLevel.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/io/section-pair/evaluator/SectionPairIdentifierArgumentEvaluator.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/io/section-pair/evaluator/SectionPairRowValueArgumentEvaluator.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/io/section-pair/model/SectionPairRow.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/io/section-pair/model/SectionPairRowListValue.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/io/section-pair/model/SectionPairRowSingleValue.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/io/section-pair/model/SectionPairRowValue.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/io/section-pair/model/SectionPairSection.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/io/section-pair/validator/SectionPairIdentifierValidator.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/io/section-pair/validator/SectionPairRowValueValidator.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/io/section-pair/serialization/SerializableSectionPairRow.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/io/section-pair/serialization/SerializableSectionPairRowListValue.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/io/section-pair/serialization/SerializableSectionPairRowSingleValue.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/io/xml/XmlAttribute.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/io/xml/XmlDeclaration.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/io/xml/XmlDocument.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/io/xml/XmlNode.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/io/xml/XmlParseParameter.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/io/xml/XmlParser.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/io/xml/XmlReader.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/io/File.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/io/FileOutputStream.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/io/FilePathSeparator.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/io/FilePathSeparatorMatch.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/io/FileReader.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/io/FileWriter.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/io/NewLine.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/io/StandardOutputWriter.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/io/StorableFile.cpp)

set(SOURCE_FILES_TIME
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/time/Date.cpp)

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
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/core/evaluator/EmptyStringArgumentEvaluatorTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/core/evaluator/IndexOutOfBoundsEvaluatorTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/core/evaluator/NullPointerArgumentEvaluatorTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/core/evaluator/NullPointerEvaluatorTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/core/exception/EventNotHandledExceptionTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/core/exception/EventNotSubscribedExceptionTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/core/exception/ExceptionMessageTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/core/exception/FileNotFoundExceptionTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/core/exception/FileOperationExceptionTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/core/exception/IllegalArgumentExceptionTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/core/exception/IllegalArithmeticOperationExceptionTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/core/exception/IncompleteJsonExceptionTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/core/exception/IndexOutOfBoundsExceptionTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/core/exception/NullPointerExceptionTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/core/exception/WrongCallExceptionTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/core/ClassTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/core/ConditionalFunctionExecutorTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/core/LibraryVersionTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/core/VersionTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/classes/core/ClassWrapper.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/classes/core/MathOddValidator.cpp)

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
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/io/kv/KvParseParameterTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/io/kv/KvParserTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/io/logging/LoggerTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/io/logging/LogLevelTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/io/section-pair/evaluator/SectionPairIdentifierArgumentEvaluatorTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/io/section-pair/evaluator/SectionPairRowValueArgumentEvaluatorTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/io/section-pair/validator/SectionPairIdentifierValidatorTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/io/section-pair/validator/SectionPairRowValueValidatorTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/io/section-pair/model/SectionPairRowListValueTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/io/section-pair/model/SectionPairRowSingleValueTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/io/section-pair/model/SectionPairRowTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/io/section-pair/model/SectionPairSectionTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/io/section-pair/serialization/SerializableSectionPairRowListValueTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/io/section-pair/serialization/SerializableSectionPairRowSingleValueTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/io/section-pair/serialization/SerializableSectionPairRowTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/io/xml/XmlAttributeTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/io/xml/XmlDeclarationTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/io/xml/XmlDocumentTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/io/xml/XmlNodeTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/cases/io/xml/XmlParseParameterTest.cpp
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
    add_executable(${MODULE_NAME_BOXING}-test ${TEST_FILES_BOXING})
endif ()

##########################################################
# Build Tests (core)
##########################################################

if (${LS_STD_BUILD_WITH_TESTS})
    message("${MODULE_NAME_CORE}: Building tests...")
    add_executable(${MODULE_NAME_CORE}-test ${TEST_FILES_CORE})
endif ()

##########################################################
# Build Tests (encoding)
##########################################################

if (${LS_STD_BUILD_WITH_TESTS})
    message("${MODULE_NAME_ENCODING}: Building tests...")
    add_executable(${MODULE_NAME_ENCODING}-test ${TEST_FILES_ENCODING})
endif ()

##########################################################
# Build Tests (event)
##########################################################

if (${LS_STD_BUILD_WITH_TESTS})
    message("${MODULE_NAME_EVENT}: Building tests...")
    add_executable(${MODULE_NAME_EVENT}-test ${TEST_FILES_EVENT})
endif ()

##########################################################
# Build Tests (io)
##########################################################

if (${LS_STD_BUILD_WITH_TESTS})
    message("${MODULE_NAME_IO}: Building tests...")
    add_executable(${MODULE_NAME_IO}-test
            ${CMAKE_CURRENT_SOURCE_DIR}/test/classes/TestHelper.cpp
            ${TEST_FILES_IO})
endif ()

##########################################################
# Build Tests (time)
##########################################################

if (${LS_STD_BUILD_WITH_TESTS})
    message("${MODULE_NAME_TIME}: Building tests...")
    add_executable(${MODULE_NAME_TIME}-test ${TEST_FILES_TIME})
endif ()

##########################################################
# Build Tests (all)
##########################################################

if (${LS_STD_BUILD_WITH_TESTS})
    message("${PROJECT_NAME}: Building tests...")
    add_executable(${PROJECT_NAME}-test
            ${CMAKE_CURRENT_SOURCE_DIR}/test/classes/TestHelper.cpp
            ${TEST_FILES_BOXING}
            ${TEST_FILES_CORE}
            ${TEST_FILES_ENCODING}
            ${TEST_FILES_EVENT}
            ${TEST_FILES_IO}
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
    set_target_properties("${MODULE_NAME_BOXING}" PROPERTIES DEBUG_POSTFIX "-d")
endif ()

if (${LS_STD_BUILD_SHARED})
    add_library("${MODULE_NAME_BOXING}" SHARED ${SOURCE_FILES_BOXING})
    target_link_libraries("${MODULE_NAME_BOXING}" ${MODULE_NAME_CORE})
    set_target_properties("${MODULE_NAME_BOXING}" PROPERTIES DEBUG_POSTFIX "-d")
endif ()

##########################################################
# Build Library (core)
##########################################################

message("${PROJECT_NAME}: Building ${MODULE_NAME_CORE} library version ${PROJECT_VERSION}...")

if (${LS_STD_BUILD_STATIC})
    add_library("${MODULE_NAME_CORE}" STATIC ${SOURCE_FILES_CORE})
    set_target_properties("${MODULE_NAME_CORE}" PROPERTIES DEBUG_POSTFIX "-d")
endif ()

if (${LS_STD_BUILD_SHARED})
    add_library("${MODULE_NAME_CORE}" SHARED ${SOURCE_FILES_CORE})
    set_target_properties("${MODULE_NAME_CORE}" PROPERTIES DEBUG_POSTFIX "-d")
endif ()

##########################################################
# Build Library (encoding)
##########################################################

message("${PROJECT_NAME}: Building ${MODULE_NAME_ENCODING} library version ${PROJECT_VERSION}...")

if (${LS_STD_BUILD_STATIC})
    add_library("${MODULE_NAME_ENCODING}" STATIC ${SOURCE_FILES_ENCODING})
    set_target_properties("${MODULE_NAME_ENCODING}" PROPERTIES DEBUG_POSTFIX "-d")
endif ()

if (${LS_STD_BUILD_SHARED})
    add_library("${MODULE_NAME_ENCODING}" SHARED ${SOURCE_FILES_ENCODING})
    set_target_properties("${MODULE_NAME_ENCODING}" PROPERTIES DEBUG_POSTFIX "-d")
endif ()

# CLI base64

add_executable(${CLI_NAME_BASE64}
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ls-std/encoding/cli/cli-base64-main.cpp)

##########################################################
# Build Library (event)
##########################################################

message("${PROJECT_NAME}: Building ${MODULE_NAME_EVENT} library version ${PROJECT_VERSION}...")

if (${LS_STD_BUILD_STATIC})
    add_library("${MODULE_NAME_EVENT}" STATIC ${SOURCE_FILES_EVENT})
    set_target_properties("${MODULE_NAME_EVENT}" PROPERTIES DEBUG_POSTFIX "-d")
endif ()

if (${LS_STD_BUILD_SHARED})
    add_library("${MODULE_NAME_EVENT}" SHARED ${SOURCE_FILES_EVENT})
    target_link_libraries("${MODULE_NAME_EVENT}" ${MODULE_NAME_CORE})
    set_target_properties("${MODULE_NAME_EVENT}" PROPERTIES DEBUG_POSTFIX "-d")
endif ()

##########################################################
# Build Library (io)
##########################################################

message("${PROJECT_NAME}: Building ${MODULE_NAME_IO} library version ${PROJECT_VERSION}...")

if (${LS_STD_BUILD_STATIC})
    add_library("${MODULE_NAME_IO}" STATIC ${SOURCE_FILES_IO})
    set_target_properties("${MODULE_NAME_IO}" PROPERTIES DEBUG_POSTFIX "-d")
endif ()

if (${LS_STD_BUILD_SHARED})
    add_library("${MODULE_NAME_IO}" SHARED ${SOURCE_FILES_IO})
    target_link_libraries("${MODULE_NAME_IO}" ${MODULE_NAME_CORE})
    set_target_properties("${MODULE_NAME_IO}" PROPERTIES DEBUG_POSTFIX "-d")
endif ()

##########################################################
# Build Library (time)
##########################################################

message("${PROJECT_NAME}: Building ${MODULE_NAME_TIME} library version ${PROJECT_VERSION}...")

if (${LS_STD_BUILD_STATIC})
    add_library("${MODULE_NAME_TIME}" STATIC ${SOURCE_FILES_TIME})
    set_target_properties("${MODULE_NAME_TIME}" PROPERTIES DEBUG_POSTFIX "-d")
endif ()

if (${LS_STD_BUILD_SHARED})
    add_library("${MODULE_NAME_TIME}" SHARED ${SOURCE_FILES_TIME})
    target_link_libraries("${MODULE_NAME_TIME}" ${MODULE_NAME_CORE})
    set_target_properties("${MODULE_NAME_TIME}" PROPERTIES DEBUG_POSTFIX "-d")
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
    target_link_libraries(${MODULE_NAME_BOXING}-test
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
    target_link_libraries(${MODULE_NAME_CORE}-test
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
    target_link_libraries(${MODULE_NAME_ENCODING}-test
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
    target_link_libraries(${MODULE_NAME_EVENT}-test
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
    target_link_libraries(${MODULE_NAME_IO}-test
            gtest
            gmock
            gtest_main
            "${MODULE_NAME_IO}"
            "${MODULE_NAME_CORE}")
endif ()

##########################################################
# Linking (time)
##########################################################

if (${LS_STD_BUILD_WITH_TESTS})
    message("${MODULE_NAME_TIME}: Linking libraries for test application...")
    target_link_libraries(${MODULE_NAME_TIME}-test
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
    target_link_libraries(${PROJECT_NAME}-test
            gtest
            gmock
            gtest_main
            "${MODULE_NAME_BOXING}"
            "${MODULE_NAME_ENCODING}"
            "${MODULE_NAME_EVENT}"
            "${MODULE_NAME_IO}"
            "${MODULE_NAME_TIME}"
            "${MODULE_NAME_CORE}")
endif ()

####################################################################################################################
####################################################################################################################
####################################################################################################################
# CLI - Base64: Linking
####################################################################################################################
####################################################################################################################
####################################################################################################################

target_link_libraries(${CLI_NAME_BASE64}
        "${MODULE_NAME_ENCODING}"
        "${MODULE_NAME_CORE}")
