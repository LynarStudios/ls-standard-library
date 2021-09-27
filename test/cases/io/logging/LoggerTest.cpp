/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-20
 * Changed:         2021-07-16
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

      static std::shared_ptr<ls_std::IWriter> createFileLogger(const std::string &_logName)
      {
        std::string path = TestHelper::getResourcesFolderLocation() + _logName;
        ls_std::File file{path};

        if (!file.exists())
        {
          file.createNewFile();
        }

        std::shared_ptr<ls_std::IWriter> writer = std::dynamic_pointer_cast<ls_std::IWriter>(std::make_shared<ls_std::FileOutputStream>(file));

        return writer;
      }

      static ls_std::String getContentFromLogFile(const std::string &_logName)
      {
        ls_std::File file{TestHelper::getResourcesFolderLocation() + _logName};
        ls_std::FileReader reader{file};
        ls_std::String content{reader.read()};
        file.remove();

        return content;
      }
  };

  TEST_F(LoggerTest, constructor_no_writer_reference)
  {
    EXPECT_THROW({
                   try
                   {
                     ls_std::Logger logger{nullptr};
                   }
                   catch (const ls_std::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls_std::IllegalArgumentException);
  }

  TEST_F(LoggerTest, debug)
  {
    // write to log file

    std::string logName = "output_debug.log";
    std::shared_ptr<ls_std::IWriter> writer = createFileLogger(logName);

    ls_std::Logger logger{writer};
    logger.setLogLevel(ls_std::LogLevelValue::DEBUG);
    logger.debug("1. line!");
    logger.info("2. line!");
    logger.error("3. line!");
    logger.fatal("4. line!");
    logger.warn("5. line!");
    logger.trace("6. line!");

    // get content and check

    std::dynamic_pointer_cast<ls_std::FileOutputStream>(writer)->close();
    ls_std::String content = getContentFromLogFile(logName);

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
    std::shared_ptr<ls_std::IWriter> writer = createFileLogger(logName);

    ls_std::Logger logger{writer};
    logger.setLogLevel(ls_std::LogLevelValue::ERR);
    logger.debug("1. line!");
    logger.info("2. line!");
    logger.error("3. line!");
    logger.fatal("4. line!");
    logger.warn("5. line!");
    logger.trace("6. line!");

    // get content and check

    std::dynamic_pointer_cast<ls_std::FileOutputStream>(writer)->close();
    ls_std::String content = getContentFromLogFile(logName);

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
    std::shared_ptr<ls_std::IWriter> writer = createFileLogger(logName);

    ls_std::Logger logger{writer};
    logger.setLogLevel(ls_std::LogLevelValue::FATAL);
    logger.debug("1. line!");
    logger.info("2. line!");
    logger.error("3. line!");
    logger.fatal("4. line!");
    logger.warn("5. line!");
    logger.trace("6. line!");

    // get content and check

    std::dynamic_pointer_cast<ls_std::FileOutputStream>(writer)->close();
    ls_std::String content = getContentFromLogFile(logName);

    ASSERT_FALSE(content.contains("1. line!"));
    ASSERT_FALSE(content.contains("2. line!"));
    ASSERT_FALSE(content.contains("3. line!"));
    ASSERT_TRUE(content.contains("4. line!"));
    ASSERT_FALSE(content.contains("5. line!"));
    ASSERT_FALSE(content.contains("6. line!"));
  }

  TEST_F(LoggerTest, getLogLevel)
  {
    ls_std::Logger logger{createFileLogger("output.log")};
    ASSERT_EQ(ls_std::LogLevelValue::INFO, logger.getLogLevel());
  }

  TEST_F(LoggerTest, info)
  {
    // write to log file

    std::string logName = "output_info.log";
    std::shared_ptr<ls_std::IWriter> writer = createFileLogger(logName);

    ls_std::Logger logger{writer};
    logger.setLogLevel(ls_std::LogLevelValue::INFO);
    logger.fatal("1. line!");
    logger.error("2. line!");
    logger.warn("3. line!");
    logger.info("4. line!");
    logger.debug("5. line!");
    logger.trace("6. line!");

    // get content and check

    std::dynamic_pointer_cast<ls_std::FileOutputStream>(writer)->close();
    ls_std::String content = getContentFromLogFile(logName);

    ASSERT_TRUE(content.contains("1. line!"));
    ASSERT_TRUE(content.contains("2. line!"));
    ASSERT_TRUE(content.contains("3. line!"));
    ASSERT_TRUE(content.contains("4. line!"));
    ASSERT_FALSE(content.contains("5. line!"));
    ASSERT_FALSE(content.contains("6. line!"));
  }

  TEST_F(LoggerTest, setLogLevel)
  {
    ls_std::Logger logger{createFileLogger("output.log")};
    logger.setLogLevel(ls_std::LogLevelValue::ERR);

    ASSERT_EQ(ls_std::LogLevelValue::ERR, logger.getLogLevel());
  }

  TEST_F(LoggerTest, trace)
  {
    // write to log file

    std::string logName = "output_trace.log";
    std::shared_ptr<ls_std::IWriter> writer = createFileLogger(logName);

    ls_std::Logger logger{writer};
    logger.setLogLevel(ls_std::LogLevelValue::TRACE);
    logger.fatal("1. line!");
    logger.error("2. line!");
    logger.warn("3. line!");
    logger.info("4. line!");
    logger.debug("5. line!");
    logger.trace("6. line!");

    // get content and check

    std::dynamic_pointer_cast<ls_std::FileOutputStream>(writer)->close();
    ls_std::String content = getContentFromLogFile(logName);

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
    std::shared_ptr<ls_std::IWriter> writer = createFileLogger(logName);

    ls_std::Logger logger{writer};
    logger.setLogLevel(ls_std::LogLevelValue::WARN);
    logger.fatal("1. line!");
    logger.error("2. line!");
    logger.warn("3. line!");
    logger.info("4. line!");
    logger.debug("5. line!");
    logger.trace("6. line!");

    // get content and check

    std::dynamic_pointer_cast<ls_std::FileOutputStream>(writer)->close();
    ls_std::String content = getContentFromLogFile(logName);

    ASSERT_TRUE(content.contains("1. line!"));
    ASSERT_TRUE(content.contains("2. line!"));
    ASSERT_TRUE(content.contains("3. line!"));
    ASSERT_FALSE(content.contains("4. line!"));
    ASSERT_FALSE(content.contains("5. line!"));
    ASSERT_FALSE(content.contains("6. line!"));
  }
}
