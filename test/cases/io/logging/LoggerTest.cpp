/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-20
 * Changed:         2023-04-12
 *
 * */

#include <classes/TestHelper.hpp>
#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>
#include <ls-std/ls-std-io.hpp>

using ls::std::core::IllegalArgumentException;
using ls::std::core::interface_type::IWriter;
using ls::std::io::File;
using ls::std::io::FileOutputStream;
using ls::std::io::FileReader;
using ls::std::io::Logger;
using ls::std::io::LogLevelValue;
using ls::std::test::TestHelper;
using std::dynamic_pointer_cast;
using std::make_shared;
using std::shared_ptr;
using std::string;
using testing::Test;

namespace
{
  class LoggerTest : public Test
  {
    public:

      LoggerTest() = default;
      ~LoggerTest() override = default;

      static shared_ptr<IWriter> createFileLogger(const string &_logName)
      {
        string path = TestHelper::getResourcesFolderLocation() + _logName;
        File file{path};

        if (!file.exists())
        {
          file.createNewFile();
        }

        shared_ptr<IWriter> writer = make_shared<FileOutputStream>(file);

        return writer;
      }

      static string getContentFromLogFile(const string &_logName)
      {
        File file{TestHelper::getResourcesFolderLocation() + _logName};
        FileReader reader{file};
        string content{reader.read()};
        file.remove();

        return content;
      }
  };

  TEST_F(LoggerTest, constructor_no_writer_reference)
  {
    EXPECT_THROW(
        {
          try
          {
            Logger logger{nullptr};
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(LoggerTest, debug)
  {
    // write to log file

    string logName = "output-debug.log";
    shared_ptr<IWriter> writer = createFileLogger(logName);

    Logger logger{writer};
    logger.setLogLevel(LogLevelValue::DEBUG);
    logger.showLogLevel();
    logger.debug("1. line!");
    logger.info("2. line!");
    logger.error("3. line!");
    logger.fatal("4. line!");
    logger.warn("5. line!");
    logger.trace("6. line!");

    // get content and check

    dynamic_pointer_cast<FileOutputStream>(writer)->close();
    string content = getContentFromLogFile(logName);

    ASSERT_TRUE(content.find("1. line!") != string::npos);
    ASSERT_TRUE(content.find("2. line!") != string::npos);
    ASSERT_TRUE(content.find("3. line!") != string::npos);
    ASSERT_TRUE(content.find("4. line!") != string::npos);
    ASSERT_TRUE(content.find("5. line!") != string::npos);
    ASSERT_FALSE(content.find("6. line!") != string::npos);
  }

  TEST_F(LoggerTest, error)
  {
    // write to log file

    string logName = "output-error.log";
    shared_ptr<IWriter> writer = createFileLogger(logName);

    Logger logger{writer};
    logger.setLogLevel(LogLevelValue::ERR);
    logger.showLogLevel();
    logger.debug("1. line!");
    logger.info("2. line!");
    logger.error("3. line!");
    logger.fatal("4. line!");
    logger.warn("5. line!");
    logger.trace("6. line!");

    // get content and check

    dynamic_pointer_cast<FileOutputStream>(writer)->close();
    string content = getContentFromLogFile(logName);

    ASSERT_FALSE(content.find("1. line!") != string::npos);
    ASSERT_FALSE(content.find("2. line!") != string::npos);
    ASSERT_TRUE(content.find("3. line!") != string::npos);
    ASSERT_TRUE(content.find("4. line!") != string::npos);
    ASSERT_FALSE(content.find("5. line!") != string::npos);
    ASSERT_FALSE(content.find("6. line!") != string::npos);
  }

  TEST_F(LoggerTest, fatal)
  {
    // write to log file

    string logName = "output-fatal.log";
    shared_ptr<IWriter> writer = createFileLogger(logName);

    Logger logger{writer};
    logger.setLogLevel(LogLevelValue::FATAL);
    logger.showLogLevel();
    logger.debug("1. line!");
    logger.info("2. line!");
    logger.error("3. line!");
    logger.fatal("4. line!");
    logger.warn("5. line!");
    logger.trace("6. line!");

    // get content and check

    dynamic_pointer_cast<FileOutputStream>(writer)->close();
    string content = getContentFromLogFile(logName);

    ASSERT_FALSE(content.find("1. line!") != string::npos);
    ASSERT_FALSE(content.find("2. line!") != string::npos);
    ASSERT_FALSE(content.find("3. line!") != string::npos);
    ASSERT_TRUE(content.find("4. line!") != string::npos);
    ASSERT_FALSE(content.find("5. line!") != string::npos);
    ASSERT_FALSE(content.find("6. line!") != string::npos);
  }

  TEST_F(LoggerTest, getLogLevel)
  {
    Logger logger{createFileLogger("output.log")};
    ASSERT_EQ(LogLevelValue::INFO, logger.getLogLevel().getValue());
  }

  TEST_F(LoggerTest, hideLogLevel)
  {
    string logName = "hide-log-level-output-fatal.log";
    shared_ptr<IWriter> writer = createFileLogger(logName);

    Logger logger{writer};
    logger.setLogLevel(LogLevelValue::DEBUG);
    logger.hideLogLevel();
    logger.fatal("test message");

    // get content and check

    dynamic_pointer_cast<FileOutputStream>(writer)->close();
    string content = getContentFromLogFile(logName);

    ASSERT_TRUE(content.find("FATAL") == string::npos);
  }

  TEST_F(LoggerTest, info)
  {
    // write to log file

    string logName = "output-info.log";
    shared_ptr<IWriter> writer = createFileLogger(logName);

    Logger logger{writer};
    logger.setLogLevel(LogLevelValue::INFO);
    logger.showLogLevel();
    logger.fatal("1. line!");
    logger.error("2. line!");
    logger.warn("3. line!");
    logger.info("4. line!");
    logger.debug("5. line!");
    logger.trace("6. line!");

    // get content and check

    dynamic_pointer_cast<FileOutputStream>(writer)->close();
    string content = getContentFromLogFile(logName);

    ASSERT_TRUE(content.find("1. line!") != string::npos);
    ASSERT_TRUE(content.find("2. line!") != string::npos);
    ASSERT_TRUE(content.find("3. line!") != string::npos);
    ASSERT_TRUE(content.find("4. line!") != string::npos);
    ASSERT_FALSE(content.find("5. line!") != string::npos);
    ASSERT_FALSE(content.find("6. line!") != string::npos);
  }

  TEST_F(LoggerTest, setLogLevel)
  {
    Logger logger{createFileLogger("output.log")};
    logger.setLogLevel(LogLevelValue::ERR);

    ASSERT_EQ(LogLevelValue::ERR, logger.getLogLevel().getValue());
  }

  TEST_F(LoggerTest, showLogLevel)
  {
    string logName = "show-log-level-output-fatal.log";
    shared_ptr<IWriter> writer = createFileLogger(logName);

    Logger logger{writer};
    logger.setLogLevel(LogLevelValue::DEBUG);
    logger.showLogLevel();
    logger.fatal("test message");

    // get content and check

    dynamic_pointer_cast<FileOutputStream>(writer)->close();
    string content = getContentFromLogFile(logName);

    ASSERT_TRUE(content.find("FATAL") != string::npos);
  }

  TEST_F(LoggerTest, trace)
  {
    // write to log file

    string logName = "output-trace.log";
    shared_ptr<IWriter> writer = createFileLogger(logName);

    Logger logger{writer};
    logger.setLogLevel(LogLevelValue::TRACE);
    logger.showLogLevel();
    logger.fatal("1. line!");
    logger.error("2. line!");
    logger.warn("3. line!");
    logger.info("4. line!");
    logger.debug("5. line!");
    logger.trace("6. line!");

    // get content and check

    dynamic_pointer_cast<FileOutputStream>(writer)->close();
    string content = getContentFromLogFile(logName);

    ASSERT_TRUE(content.find("1. line!") != string::npos);
    ASSERT_TRUE(content.find("2. line!") != string::npos);
    ASSERT_TRUE(content.find("3. line!") != string::npos);
    ASSERT_TRUE(content.find("4. line!") != string::npos);
    ASSERT_TRUE(content.find("5. line!") != string::npos);
    ASSERT_TRUE(content.find("6. line!") != string::npos);
  }

  TEST_F(LoggerTest, warn)
  {
    // write to log file

    string logName = "output-warn.log";
    shared_ptr<IWriter> writer = createFileLogger(logName);

    Logger logger{writer};
    logger.setLogLevel(LogLevelValue::WARN);
    logger.showLogLevel();
    logger.fatal("1. line!");
    logger.error("2. line!");
    logger.warn("3. line!");
    logger.info("4. line!");
    logger.debug("5. line!");
    logger.trace("6. line!");

    // get content and check

    dynamic_pointer_cast<FileOutputStream>(writer)->close();
    string content = getContentFromLogFile(logName);

    ASSERT_TRUE(content.find("1. line!") != string::npos);
    ASSERT_TRUE(content.find("2. line!") != string::npos);
    ASSERT_TRUE(content.find("3. line!") != string::npos);
    ASSERT_FALSE(content.find("4. line!") != string::npos);
    ASSERT_FALSE(content.find("5. line!") != string::npos);
    ASSERT_FALSE(content.find("6. line!") != string::npos);
  }
}
