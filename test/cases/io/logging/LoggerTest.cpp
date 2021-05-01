/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-20
 * Changed:         2021-04-23
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
  };

  TEST_F(LoggerTest, debug)
  {
    std::shared_ptr<ls_std::IWriter> writer = createFileLogger("output_debug.log");

    ls_std::Logger logger{writer};
    logger.setLogLevel(ls_std::LogLevelValue::DEBUG);
    logger.debug("1. line!");
    logger.info("2. line!");
    logger.error("3. line!");
    logger.fatal("4. line!");
    logger.warn("5. line!");
    logger.trace("6. line!");

    std::dynamic_pointer_cast<ls_std::FileOutputStream>(writer)->close();

    ls_std::File file{TestHelper::getResourcesFolderLocation() + "output_debug.log"};
    ls_std::FileReader reader{file};
    ls_std::String content{reader.read()};
    file.remove();

    ASSERT_TRUE(content.contains("1. line!"));
    ASSERT_TRUE(content.contains("2. line!"));
    ASSERT_TRUE(content.contains("3. line!"));
    ASSERT_TRUE(content.contains("4. line!"));
    ASSERT_TRUE(content.contains("5. line!"));
    ASSERT_FALSE(content.contains("6. line!"));
  }

  TEST_F(LoggerTest, error)
  {
    std::shared_ptr<ls_std::IWriter> writer = createFileLogger("output_error.log");

    ls_std::Logger logger{writer};
    logger.setLogLevel(ls_std::LogLevelValue::ERR);
    logger.debug("1. line!");
    logger.info("2. line!");
    logger.error("3. line!");
    logger.fatal("4. line!");
    logger.warn("5. line!");
    logger.trace("6. line!");

    std::dynamic_pointer_cast<ls_std::FileOutputStream>(writer)->close();

    ls_std::File file{TestHelper::getResourcesFolderLocation() + "output_error.log"};
    ls_std::FileReader reader{file};
    ls_std::String content{reader.read()};

    ASSERT_FALSE(content.contains("1. line!"));
    ASSERT_FALSE(content.contains("2. line!"));
    ASSERT_TRUE(content.contains("3. line!"));
    ASSERT_TRUE(content.contains("4. line!"));
    ASSERT_FALSE(content.contains("5. line!"));
    ASSERT_FALSE(content.contains("6. line!"));

    file.remove();
  }

  TEST_F(LoggerTest, fatal)
  {
    std::shared_ptr<ls_std::IWriter> writer = createFileLogger("output_fatal.log");

    ls_std::Logger logger{writer};
    logger.setLogLevel(ls_std::LogLevelValue::FATAL);
    logger.debug("1. line!");
    logger.info("2. line!");
    logger.error("3. line!");
    logger.fatal("4. line!");
    logger.warn("5. line!");
    logger.trace("6. line!");

    std::dynamic_pointer_cast<ls_std::FileOutputStream>(writer)->close();
    ls_std::File file{TestHelper::getResourcesFolderLocation() + "output_fatal.log"};

    ls_std::FileReader reader{file};
    ls_std::String content{reader.read()};

    ASSERT_FALSE(content.contains("1. line!"));
    ASSERT_FALSE(content.contains("2. line!"));
    ASSERT_FALSE(content.contains("3. line!"));
    ASSERT_TRUE(content.contains("4. line!"));
    ASSERT_FALSE(content.contains("5. line!"));
    ASSERT_FALSE(content.contains("6. line!"));

    file.remove();
  }

  TEST_F(LoggerTest, getLogLevel)
  {
    ls_std::Logger logger{createFileLogger("output.log")};
    ASSERT_EQ(ls_std::LogLevelValue::INFO, logger.getLogLevel());
  }

  TEST_F(LoggerTest, info)
  {
    std::shared_ptr<ls_std::IWriter> writer = createFileLogger("output_info.log");

    ls_std::Logger logger{writer};
    logger.setLogLevel(ls_std::LogLevelValue::INFO);
    logger.fatal("1. line!");
    logger.error("2. line!");
    logger.warn("3. line!");
    logger.info("4. line!");
    logger.debug("5. line!");
    logger.trace("6. line!");

    std::dynamic_pointer_cast<ls_std::FileOutputStream>(writer)->close();
    ls_std::File file{TestHelper::getResourcesFolderLocation() + "output_info.log"};

    ls_std::FileReader reader{file};
    ls_std::String content{reader.read()};

    ASSERT_TRUE(content.contains("1. line!"));
    ASSERT_TRUE(content.contains("2. line!"));
    ASSERT_TRUE(content.contains("3. line!"));
    ASSERT_TRUE(content.contains("4. line!"));
    ASSERT_FALSE(content.contains("5. line!"));
    ASSERT_FALSE(content.contains("6. line!"));

    file.remove();
  }

  TEST_F(LoggerTest, setLogLevel)
  {
    ls_std::Logger logger{createFileLogger("output.log")};
    logger.setLogLevel(ls_std::LogLevelValue::ERR);

    ASSERT_EQ(ls_std::LogLevelValue::ERR, logger.getLogLevel());
  }

  TEST_F(LoggerTest, trace)
  {
    std::shared_ptr<ls_std::IWriter> writer = createFileLogger("output_trace.log");

    ls_std::Logger logger{writer};
    logger.setLogLevel(ls_std::LogLevelValue::TRACE);
    logger.fatal("1. line!");
    logger.error("2. line!");
    logger.warn("3. line!");
    logger.info("4. line!");
    logger.debug("5. line!");
    logger.trace("6. line!");

    std::dynamic_pointer_cast<ls_std::FileOutputStream>(writer)->close();
    ls_std::File file{TestHelper::getResourcesFolderLocation() + "output_trace.log"};

    ls_std::FileReader reader{file};
    ls_std::String content{reader.read()};

    ASSERT_TRUE(content.contains("1. line!"));
    ASSERT_TRUE(content.contains("2. line!"));
    ASSERT_TRUE(content.contains("3. line!"));
    ASSERT_TRUE(content.contains("4. line!"));
    ASSERT_TRUE(content.contains("5. line!"));
    ASSERT_TRUE(content.contains("6. line!"));

    file.remove();
  }

  TEST_F(LoggerTest, warn)
  {
    std::shared_ptr<ls_std::IWriter> writer = createFileLogger("output_warn.log");

    ls_std::Logger logger{writer};
    logger.setLogLevel(ls_std::LogLevelValue::WARN);
    logger.fatal("1. line!");
    logger.error("2. line!");
    logger.warn("3. line!");
    logger.info("4. line!");
    logger.debug("5. line!");
    logger.trace("6. line!");

    std::dynamic_pointer_cast<ls_std::FileOutputStream>(writer)->close();
    ls_std::File file{TestHelper::getResourcesFolderLocation() + "output_warn.log"};

    ls_std::FileReader reader{file};
    ls_std::String content{reader.read()};

    ASSERT_TRUE(content.contains("1. line!"));
    ASSERT_TRUE(content.contains("2. line!"));
    ASSERT_TRUE(content.contains("3. line!"));
    ASSERT_FALSE(content.contains("4. line!"));
    ASSERT_FALSE(content.contains("5. line!"));
    ASSERT_FALSE(content.contains("6. line!"));

    file.remove();
  }
}
