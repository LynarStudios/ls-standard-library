/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-20
 * Changed:         2022-05-05
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

      static std::shared_ptr<ls::IWriter> createFileLogger(const std::string &_logName)
      {
        std::string path = TestHelper::getResourcesFolderLocation() + _logName;
        ls::File file{path};

        if (!file.exists())
        {
          file.createNewFile();
        }

        std::shared_ptr<ls::IWriter> writer = std::dynamic_pointer_cast<ls::IWriter>(std::make_shared<ls::FileOutputStream>(file));

        return writer;
      }

      static ls::String getContentFromLogFile(const std::string &_logName)
      {
        ls::File file{TestHelper::getResourcesFolderLocation() + _logName};
        ls::FileReader reader{file};
        ls::String content{reader.read()};
        file.remove();

        return content;
      }
  };

  TEST_F(LoggerTest, constructor_no_writer_reference)
  {
    EXPECT_THROW({
                   try
                   {
                     ls::Logger logger{nullptr};
                   }
                   catch (const ls::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::IllegalArgumentException);
  }

  TEST_F(LoggerTest, debug)
  {
    // write to log file

    std::string logName = "output_debug.log";
    std::shared_ptr<ls::IWriter> writer = createFileLogger(logName);

    ls::Logger logger{writer};
    logger.setLogLevel(ls::LogLevelValue::DEBUG);
    logger.debug("1. line!");
    logger.info("2. line!");
    logger.error("3. line!");
    logger.fatal("4. line!");
    logger.warn("5. line!");
    logger.trace("6. line!");

    // get content and check

    std::dynamic_pointer_cast<ls::FileOutputStream>(writer)->close();
    ls::String content = getContentFromLogFile(logName);

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
    std::shared_ptr<ls::IWriter> writer = createFileLogger(logName);

    ls::Logger logger{writer};
    logger.setLogLevel(ls::LogLevelValue::ERR);
    logger.debug("1. line!");
    logger.info("2. line!");
    logger.error("3. line!");
    logger.fatal("4. line!");
    logger.warn("5. line!");
    logger.trace("6. line!");

    // get content and check

    std::dynamic_pointer_cast<ls::FileOutputStream>(writer)->close();
    ls::String content = getContentFromLogFile(logName);

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
    std::shared_ptr<ls::IWriter> writer = createFileLogger(logName);

    ls::Logger logger{writer};
    logger.setLogLevel(ls::LogLevelValue::FATAL);
    logger.debug("1. line!");
    logger.info("2. line!");
    logger.error("3. line!");
    logger.fatal("4. line!");
    logger.warn("5. line!");
    logger.trace("6. line!");

    // get content and check

    std::dynamic_pointer_cast<ls::FileOutputStream>(writer)->close();
    ls::String content = getContentFromLogFile(logName);

    ASSERT_FALSE(content.contains("1. line!"));
    ASSERT_FALSE(content.contains("2. line!"));
    ASSERT_FALSE(content.contains("3. line!"));
    ASSERT_TRUE(content.contains("4. line!"));
    ASSERT_FALSE(content.contains("5. line!"));
    ASSERT_FALSE(content.contains("6. line!"));
  }

  TEST_F(LoggerTest, getLogLevel)
  {
    ls::Logger logger{createFileLogger("output.log")};
    ASSERT_EQ(ls::LogLevelValue::INFO, logger.getLogLevel());
  }

  TEST_F(LoggerTest, info)
  {
    // write to log file

    std::string logName = "output_info.log";
    std::shared_ptr<ls::IWriter> writer = createFileLogger(logName);

    ls::Logger logger{writer};
    logger.setLogLevel(ls::LogLevelValue::INFO);
    logger.fatal("1. line!");
    logger.error("2. line!");
    logger.warn("3. line!");
    logger.info("4. line!");
    logger.debug("5. line!");
    logger.trace("6. line!");

    // get content and check

    std::dynamic_pointer_cast<ls::FileOutputStream>(writer)->close();
    ls::String content = getContentFromLogFile(logName);

    ASSERT_TRUE(content.contains("1. line!"));
    ASSERT_TRUE(content.contains("2. line!"));
    ASSERT_TRUE(content.contains("3. line!"));
    ASSERT_TRUE(content.contains("4. line!"));
    ASSERT_FALSE(content.contains("5. line!"));
    ASSERT_FALSE(content.contains("6. line!"));
  }

  TEST_F(LoggerTest, setLogLevel)
  {
    ls::Logger logger{createFileLogger("output.log")};
    logger.setLogLevel(ls::LogLevelValue::ERR);

    ASSERT_EQ(ls::LogLevelValue::ERR, logger.getLogLevel());
  }

  TEST_F(LoggerTest, trace)
  {
    // write to log file

    std::string logName = "output_trace.log";
    std::shared_ptr<ls::IWriter> writer = createFileLogger(logName);

    ls::Logger logger{writer};
    logger.setLogLevel(ls::LogLevelValue::TRACE);
    logger.fatal("1. line!");
    logger.error("2. line!");
    logger.warn("3. line!");
    logger.info("4. line!");
    logger.debug("5. line!");
    logger.trace("6. line!");

    // get content and check

    std::dynamic_pointer_cast<ls::FileOutputStream>(writer)->close();
    ls::String content = getContentFromLogFile(logName);

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
    std::shared_ptr<ls::IWriter> writer = createFileLogger(logName);

    ls::Logger logger{writer};
    logger.setLogLevel(ls::LogLevelValue::WARN);
    logger.fatal("1. line!");
    logger.error("2. line!");
    logger.warn("3. line!");
    logger.info("4. line!");
    logger.debug("5. line!");
    logger.trace("6. line!");

    // get content and check

    std::dynamic_pointer_cast<ls::FileOutputStream>(writer)->close();
    ls::String content = getContentFromLogFile(logName);

    ASSERT_TRUE(content.contains("1. line!"));
    ASSERT_TRUE(content.contains("2. line!"));
    ASSERT_TRUE(content.contains("3. line!"));
    ASSERT_FALSE(content.contains("4. line!"));
    ASSERT_FALSE(content.contains("5. line!"));
    ASSERT_FALSE(content.contains("6. line!"));
  }
}
