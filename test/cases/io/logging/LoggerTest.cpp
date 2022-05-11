/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-20
 * Changed:         2022-05-11
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>
#include <TestHelper.hpp>

namespace
{
  class LoggerTest : public ::testing::Test
  {
    protected:

      LoggerTest() = default;
      ~LoggerTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}

      static std::shared_ptr<ls::std::core::IWriter> createFileLogger(const std::string &_logName)
      {
        std::string path = TestHelper::getResourcesFolderLocation() + _logName;
        ls::std::io::File file{path};

        if (!file.exists())
        {
          file.createNewFile();
        }

        std::shared_ptr<ls::std::core::IWriter> writer = std::dynamic_pointer_cast<ls::std::core::IWriter>(std::make_shared<ls::std::io::FileOutputStream>(file));

        return writer;
      }

      static ls::std::boxing::String getContentFromLogFile(const std::string &_logName)
      {
        ls::std::io::File file{TestHelper::getResourcesFolderLocation() + _logName};
        ls::std::io::FileReader reader{file};
        ls::std::boxing::String content{reader.read()};
        file.remove();

        return content;
      }
  };

  TEST_F(LoggerTest, constructor_no_writer_reference)
  {
    EXPECT_THROW({
                   try
                   {
                     ls::std::io::Logger logger{nullptr};
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }

  TEST_F(LoggerTest, debug)
  {
    // write to log file

    std::string logName = "output_debug.log";
    std::shared_ptr<ls::std::core::IWriter> writer = createFileLogger(logName);

    ls::std::io::Logger logger{writer};
    logger.setLogLevel(ls::std::io::LogLevelValue::DEBUG);
    logger.debug("1. line!");
    logger.info("2. line!");
    logger.error("3. line!");
    logger.fatal("4. line!");
    logger.warn("5. line!");
    logger.trace("6. line!");

    // get content and check

    std::dynamic_pointer_cast<ls::std::io::FileOutputStream>(writer)->close();
    ls::std::boxing::String content = getContentFromLogFile(logName);

    ASSERT_TRUE(content.contains("1. line!"));
    ASSERT_TRUE(content.contains("2. line!"));
    ASSERT_TRUE(content.contains("3. line!"));
    ASSERT_TRUE(content.contains("4. line!"));
    ASSERT_TRUE(content.contains("5. line!"));
    ASSERT_FALSE(content.contains("6. line!"));
  }

  TEST_F(LoggerTest, error)
  {
    // write to log file

    std::string logName = "output_error.log";
    std::shared_ptr<ls::std::core::IWriter> writer = createFileLogger(logName);

    ls::std::io::Logger logger{writer};
    logger.setLogLevel(ls::std::io::LogLevelValue::ERR);
    logger.debug("1. line!");
    logger.info("2. line!");
    logger.error("3. line!");
    logger.fatal("4. line!");
    logger.warn("5. line!");
    logger.trace("6. line!");

    // get content and check

    std::dynamic_pointer_cast<ls::std::io::FileOutputStream>(writer)->close();
    ls::std::boxing::String content = getContentFromLogFile(logName);

    ASSERT_FALSE(content.contains("1. line!"));
    ASSERT_FALSE(content.contains("2. line!"));
    ASSERT_TRUE(content.contains("3. line!"));
    ASSERT_TRUE(content.contains("4. line!"));
    ASSERT_FALSE(content.contains("5. line!"));
    ASSERT_FALSE(content.contains("6. line!"));
  }

  TEST_F(LoggerTest, fatal)
  {
    // write to log file

    std::string logName = "output_fatal.log";
    std::shared_ptr<ls::std::core::IWriter> writer = createFileLogger(logName);

    ls::std::io::Logger logger{writer};
    logger.setLogLevel(ls::std::io::LogLevelValue::FATAL);
    logger.debug("1. line!");
    logger.info("2. line!");
    logger.error("3. line!");
    logger.fatal("4. line!");
    logger.warn("5. line!");
    logger.trace("6. line!");

    // get content and check

    std::dynamic_pointer_cast<ls::std::io::FileOutputStream>(writer)->close();
    ls::std::boxing::String content = getContentFromLogFile(logName);

    ASSERT_FALSE(content.contains("1. line!"));
    ASSERT_FALSE(content.contains("2. line!"));
    ASSERT_FALSE(content.contains("3. line!"));
    ASSERT_TRUE(content.contains("4. line!"));
    ASSERT_FALSE(content.contains("5. line!"));
    ASSERT_FALSE(content.contains("6. line!"));
  }

  TEST_F(LoggerTest, getLogLevel)
  {
    ls::std::io::Logger logger{createFileLogger("output.log")};
    ASSERT_EQ(ls::std::io::LogLevelValue::INFO, logger.getLogLevel());
  }

  TEST_F(LoggerTest, info)
  {
    // write to log file

    std::string logName = "output_info.log";
    std::shared_ptr<ls::std::core::IWriter> writer = createFileLogger(logName);

    ls::std::io::Logger logger{writer};
    logger.setLogLevel(ls::std::io::LogLevelValue::INFO);
    logger.fatal("1. line!");
    logger.error("2. line!");
    logger.warn("3. line!");
    logger.info("4. line!");
    logger.debug("5. line!");
    logger.trace("6. line!");

    // get content and check

    std::dynamic_pointer_cast<ls::std::io::FileOutputStream>(writer)->close();
    ls::std::boxing::String content = getContentFromLogFile(logName);

    ASSERT_TRUE(content.contains("1. line!"));
    ASSERT_TRUE(content.contains("2. line!"));
    ASSERT_TRUE(content.contains("3. line!"));
    ASSERT_TRUE(content.contains("4. line!"));
    ASSERT_FALSE(content.contains("5. line!"));
    ASSERT_FALSE(content.contains("6. line!"));
  }

  TEST_F(LoggerTest, setLogLevel)
  {
    ls::std::io::Logger logger{createFileLogger("output.log")};
    logger.setLogLevel(ls::std::io::LogLevelValue::ERR);

    ASSERT_EQ(ls::std::io::LogLevelValue::ERR, logger.getLogLevel());
  }

  TEST_F(LoggerTest, trace)
  {
    // write to log file

    std::string logName = "output_trace.log";
    std::shared_ptr<ls::std::core::IWriter> writer = createFileLogger(logName);

    ls::std::io::Logger logger{writer};
    logger.setLogLevel(ls::std::io::LogLevelValue::TRACE);
    logger.fatal("1. line!");
    logger.error("2. line!");
    logger.warn("3. line!");
    logger.info("4. line!");
    logger.debug("5. line!");
    logger.trace("6. line!");

    // get content and check

    std::dynamic_pointer_cast<ls::std::io::FileOutputStream>(writer)->close();
    ls::std::boxing::String content = getContentFromLogFile(logName);

    ASSERT_TRUE(content.contains("1. line!"));
    ASSERT_TRUE(content.contains("2. line!"));
    ASSERT_TRUE(content.contains("3. line!"));
    ASSERT_TRUE(content.contains("4. line!"));
    ASSERT_TRUE(content.contains("5. line!"));
    ASSERT_TRUE(content.contains("6. line!"));
  }

  TEST_F(LoggerTest, warn)
  {
    // write to log file

    std::string logName = "output_warn.log";
    std::shared_ptr<ls::std::core::IWriter> writer = createFileLogger(logName);

    ls::std::io::Logger logger{writer};
    logger.setLogLevel(ls::std::io::LogLevelValue::WARN);
    logger.fatal("1. line!");
    logger.error("2. line!");
    logger.warn("3. line!");
    logger.info("4. line!");
    logger.debug("5. line!");
    logger.trace("6. line!");

    // get content and check

    std::dynamic_pointer_cast<ls::std::io::FileOutputStream>(writer)->close();
    ls::std::boxing::String content = getContentFromLogFile(logName);

    ASSERT_TRUE(content.contains("1. line!"));
    ASSERT_TRUE(content.contains("2. line!"));
    ASSERT_TRUE(content.contains("3. line!"));
    ASSERT_FALSE(content.contains("4. line!"));
    ASSERT_FALSE(content.contains("5. line!"));
    ASSERT_FALSE(content.contains("6. line!"));
  }
}
