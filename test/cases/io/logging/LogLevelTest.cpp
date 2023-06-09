/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-05-02
 * Changed:         2023-03-25
 *
 * */

#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>
#include <ls-std/ls-std-io.hpp>

using ls::std::core::IllegalArgumentException;
using ls::std::io::LogLevel;
using ls::std::io::LogLevelValue;
using testing::Test;

namespace
{
  class LogLevelTest : public Test
  {
    public:

      LogLevelTest() = default;
      ~LogLevelTest() override = default;
  };

  TEST_F(LogLevelTest, constructor_with_log_level_value_parameter)
  {
    LogLevel logLevel{LogLevelValue::INFO};
    ASSERT_EQ(LogLevelValue::INFO, logLevel.getValue());
  }

  TEST_F(LogLevelTest, constructor_default)
  {
    LogLevel logLevel{};
    ASSERT_EQ(LogLevelValue::FATAL, logLevel.getValue());
  }

  TEST_F(LogLevelTest, operator_assign)
  {
    LogLevel logLevel{LogLevelValue::DEBUG};
    logLevel = LogLevelValue::INFO;

    ASSERT_EQ(LogLevelValue::INFO, logLevel.getValue());
  }

  TEST_F(LogLevelTest, operator_lessThan)
  {
    LogLevel logLevel{}; // default is FATAL

    ASSERT_TRUE(logLevel < LogLevelValue::ERR);
    ASSERT_TRUE(logLevel < LogLevelValue::WARN);
    ASSERT_TRUE(logLevel < LogLevelValue::INFO);
    ASSERT_TRUE(logLevel < LogLevelValue::DEBUG);
    ASSERT_TRUE(logLevel < LogLevelValue::TRACE);
  }

  TEST_F(LogLevelTest, operator_lessThan_not_less_than)
  {
    LogLevel logLevel{LogLevelValue::DEBUG};
    ASSERT_FALSE(logLevel < LogLevelValue::ERR);
  }

  TEST_F(LogLevelTest, operator_less_than_equals)
  {
    LogLevel logLevel{}; // default is FATAL

    ASSERT_TRUE(logLevel <= LogLevelValue::FATAL);
    ASSERT_TRUE(logLevel <= LogLevelValue::ERR);
    ASSERT_TRUE(logLevel <= LogLevelValue::WARN);
    ASSERT_TRUE(logLevel <= LogLevelValue::INFO);
    ASSERT_TRUE(logLevel <= LogLevelValue::DEBUG);
    ASSERT_TRUE(logLevel <= LogLevelValue::TRACE);
  }

  TEST_F(LogLevelTest, operator_less_than_equals_not_less_than_equals)
  {
    LogLevel logLevel{LogLevelValue::DEBUG};
    ASSERT_FALSE(logLevel <= LogLevelValue::ERR);
  }

  TEST_F(LogLevelTest, operator_greater_than)
  {
    LogLevel logLevel{LogLevelValue::DEBUG};
    ASSERT_TRUE(logLevel > LogLevelValue::ERR);
  }

  TEST_F(LogLevelTest, operator_greater_than_not_greater_than)
  {
    LogLevel logLevel{LogLevelValue::DEBUG};
    ASSERT_FALSE(logLevel > LogLevelValue::DEBUG);
  }

  TEST_F(LogLevelTest, operator_greater_than_equals)
  {
    LogLevel logLevel{LogLevelValue::DEBUG};
    ASSERT_TRUE(logLevel >= LogLevelValue::ERR);
  }

  TEST_F(LogLevelTest, operator_greater_than_equals_not_greater_than_equals)
  {
    LogLevel logLevel{};
    ASSERT_FALSE(logLevel >= LogLevelValue::ERR);
  }

  TEST_F(LogLevelTest, operator_equals)
  {
    LogLevel logLevel{LogLevelValue::DEBUG};
    ASSERT_TRUE(logLevel == LogLevelValue::DEBUG);
  }

  TEST_F(LogLevelTest, operator_equals_not_equals)
  {
    LogLevel logLevel{LogLevelValue::TRACE};
    ASSERT_FALSE(logLevel == LogLevelValue::DEBUG);
  }

  TEST_F(LogLevelTest, getLogLevel)
  {
    ASSERT_EQ(LogLevelValue::FATAL, LogLevel{}.getValue());
  }

  TEST_F(LogLevelTest, setLogLevel_with_log_level_value)
  {
    LogLevel logLevel{};
    logLevel.setLogLevel(LogLevelValue::INFO);

    ASSERT_EQ(LogLevelValue::INFO, logLevel.getValue());
  }

  TEST_F(LogLevelTest, setLogLevel_with_string)
  {
    LogLevel logLevel{};

    logLevel.setLogLevel("FATAL");
    ASSERT_EQ(LogLevelValue::FATAL, logLevel.getValue());
    logLevel.setLogLevel("ERROR");
    ASSERT_EQ(LogLevelValue::ERR, logLevel.getValue());
    logLevel.setLogLevel("WARN");
    ASSERT_EQ(LogLevelValue::WARN, logLevel.getValue());
    logLevel.setLogLevel("INFO");
    ASSERT_EQ(LogLevelValue::INFO, logLevel.getValue());
    logLevel.setLogLevel("DEBUG");
    ASSERT_EQ(LogLevelValue::DEBUG, logLevel.getValue());
    logLevel.setLogLevel("TRACE");
    ASSERT_EQ(LogLevelValue::TRACE, logLevel.getValue());
  }

  TEST_F(LogLevelTest, setLogLevel_string_no_valid_string)
  {
    LogLevel logLevel{};

    EXPECT_THROW(
        {
          try
          {
            logLevel.setLogLevel("This is not a valid log level!");
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(LogLevelTest, toString)
  {
    LogLevel logLevel{};
    ASSERT_STREQ("FATAL", logLevel.toString().c_str());
    logLevel.setLogLevel(LogLevelValue::ERR);
    ASSERT_STREQ("ERROR", logLevel.toString().c_str());
    logLevel.setLogLevel(LogLevelValue::WARN);
    ASSERT_STREQ("WARN", logLevel.toString().c_str());
    logLevel.setLogLevel(LogLevelValue::INFO);
    ASSERT_STREQ("INFO", logLevel.toString().c_str());
    logLevel.setLogLevel(LogLevelValue::DEBUG);
    ASSERT_STREQ("DEBUG", logLevel.toString().c_str());
    logLevel.setLogLevel(LogLevelValue::TRACE);
    ASSERT_STREQ("TRACE", logLevel.toString().c_str());
  }
}
