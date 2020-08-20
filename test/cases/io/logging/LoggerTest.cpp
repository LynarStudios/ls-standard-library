/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-20
 * Changed:         2020-08-20
 *
 * */

#include <gtest/gtest.h>
#include "../../../../source/io/logging/Logger.hpp"
#include "../../../TestHelper.hpp"
#include "../../../../source/io/FileReader.hpp"
#include "../../../../source/boxing/String.hpp"

namespace {
  class LoggerTest : public ::testing::Test {
    protected:

      LoggerTest() = default;
      ~LoggerTest() override = default;

      void SetUp() override {}
      void TearDown() override {}
  };

  TEST_F(LoggerTest, debug)
  {
    std::string path = TestHelper::getResourcesFolderLocation() + "output_debug.log";

    ls_std::Logger logger {path};
    logger.setLogLevel(ls_std::LogLevelValue::DEBUG);
    logger.debug("1. line!");
    logger.info("2. line!");
    logger.error("3. line!");
    logger.fatal("4. line!");
    logger.warn("5. line!");
    logger.trace("6. line!");

    logger.close();

    ls_std::File file {path};
    ls_std::FileReader reader {file};
    ls_std::String content {reader.read()};

    ASSERT_TRUE(content.contains("1. line!"));
    ASSERT_TRUE(content.contains("2. line!"));
    ASSERT_TRUE(content.contains("3. line!"));
    ASSERT_TRUE(content.contains("4. line!"));
    ASSERT_TRUE(content.contains("5. line!"));
    ASSERT_FALSE(content.contains("6. line!"));

    file.remove();
  }

  TEST_F(LoggerTest, error)
  {
    std::string path = TestHelper::getResourcesFolderLocation() + "output_error.log";

    ls_std::Logger logger {path};
    logger.setLogLevel(ls_std::LogLevelValue::ERR);
    logger.debug("1. line!");
    logger.info("2. line!");
    logger.error("3. line!");
    logger.fatal("4. line!");
    logger.warn("5. line!");
    logger.trace("6. line!");

    logger.close();

    ls_std::File file {path};
    ls_std::FileReader reader {file};
    ls_std::String content {reader.read()};

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
    std::string path = TestHelper::getResourcesFolderLocation() + "output_fatal.log";

    ls_std::Logger logger {path};
    logger.setLogLevel(ls_std::LogLevelValue::FATAL);
    logger.debug("1. line!");
    logger.info("2. line!");
    logger.error("3. line!");
    logger.fatal("4. line!");
    logger.warn("5. line!");
    logger.trace("6. line!");

    logger.close();
    ls_std::File file {path};

    ls_std::FileReader reader {file};
    ls_std::String content {reader.read()};

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
    ls_std::Logger logger {TestHelper::getResourcesFolderLocation() + "output.log"};
    ASSERT_EQ(ls_std::LogLevelValue::INFO, logger.getLogLevel());
  }

  TEST_F(LoggerTest, info)
  {
    std::string path = TestHelper::getResourcesFolderLocation() + "output_info.log";

    ls_std::Logger logger {path};
    logger.setLogLevel(ls_std::LogLevelValue::INFO);
    logger.fatal("1. line!");
    logger.error("2. line!");
    logger.warn("3. line!");
    logger.info("4. line!");
    logger.debug("5. line!");
    logger.trace("6. line!");

    logger.close();
    ls_std::File file {path};

    ls_std::FileReader reader {file};
    ls_std::String content {reader.read()};

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
    ls_std::Logger logger {TestHelper::getResourcesFolderLocation() + "output.log"};
    logger.setLogLevel(ls_std::LogLevelValue::ERR);

    ASSERT_EQ(ls_std::LogLevelValue::ERR, logger.getLogLevel());
  }

  TEST_F(LoggerTest, trace)
  {
    std::string path = TestHelper::getResourcesFolderLocation() + "output_trace.log";

    ls_std::Logger logger {path};
    logger.setLogLevel(ls_std::LogLevelValue::TRACE);
    logger.fatal("1. line!");
    logger.error("2. line!");
    logger.warn("3. line!");
    logger.info("4. line!");
    logger.debug("5. line!");
    logger.trace("6. line!");

    logger.close();
    ls_std::File file {path};

    ls_std::FileReader reader {file};
    ls_std::String content {reader.read()};

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
    std::string path = TestHelper::getResourcesFolderLocation() + "output_trace.log";

    ls_std::Logger logger {path};
    logger.setLogLevel(ls_std::LogLevelValue::WARN);
    logger.fatal("1. line!");
    logger.error("2. line!");
    logger.warn("3. line!");
    logger.info("4. line!");
    logger.debug("5. line!");
    logger.trace("6. line!");

    logger.close();
    ls_std::File file {path};

    ls_std::FileReader reader {file};
    ls_std::String content {reader.read()};

    ASSERT_TRUE(content.contains("1. line!"));
    ASSERT_TRUE(content.contains("2. line!"));
    ASSERT_TRUE(content.contains("3. line!"));
    ASSERT_FALSE(content.contains("4. line!"));
    ASSERT_FALSE(content.contains("5. line!"));
    ASSERT_FALSE(content.contains("6. line!"));

    file.remove();
  }
}
