/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-05-02
 * Changed:         2022-05-05
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>

namespace
{
  class LogLevelTest : public ::testing::Test
  {
    protected:

      LogLevelTest() = default;
      ~LogLevelTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(LogLevelTest, constructor_with_log_level_value_parameter)
  {
    ls::LogLevel logLevel{ls::LogLevelValue::INFO};
    ASSERT_EQ(ls::LogLevelValue::INFO, logLevel);
  }

  TEST_F(LogLevelTest, constructor_default)
  {
    ls::LogLevel logLevel{};
    ASSERT_EQ(ls::LogLevelValue::FATAL, logLevel);
  }

  TEST_F(LogLevelTest, operator_assign)
  {
    ls::LogLevel logLevel{ls::LogLevelValue::DEBUG};
    logLevel = ls::LogLevelValue::INFO;

    ASSERT_EQ(ls::LogLevelValue::INFO, logLevel);
  }

  TEST_F(LogLevelTest, operator_lessThan)
  {
    ls::LogLevel logLevel{}; // default is FATAL

    ASSERT_TRUE(logLevel < ls::LogLevelValue::ERR);
    ASSERT_TRUE(logLevel < ls::LogLevelValue::WARN);
    ASSERT_TRUE(logLevel < ls::LogLevelValue::INFO);
    ASSERT_TRUE(logLevel < ls::LogLevelValue::DEBUG);
    ASSERT_TRUE(logLevel < ls::LogLevelValue::TRACE);
  }

  TEST_F(LogLevelTest, operator_lessThan_not_less_than)
  {
    ls::LogLevel logLevel{ls::LogLevelValue::DEBUG};
    ASSERT_FALSE(logLevel < ls::LogLevelValue::ERR);
  }

  TEST_F(LogLevelTest, operator_less_than_equals)
  {
    ls::LogLevel logLevel{}; // default is FATAL

    ASSERT_TRUE(logLevel <= ls::LogLevelValue::FATAL);
    ASSERT_TRUE(logLevel <= ls::LogLevelValue::ERR);
    ASSERT_TRUE(logLevel <= ls::LogLevelValue::WARN);
    ASSERT_TRUE(logLevel <= ls::LogLevelValue::INFO);
    ASSERT_TRUE(logLevel <= ls::LogLevelValue::DEBUG);
    ASSERT_TRUE(logLevel <= ls::LogLevelValue::TRACE);
  }

  TEST_F(LogLevelTest, operator_less_than_equals_not_less_than_equals)
  {
    ls::LogLevel logLevel{ls::LogLevelValue::DEBUG};
    ASSERT_FALSE(logLevel <= ls::LogLevelValue::ERR);
  }

  TEST_F(LogLevelTest, operator_greater_than)
  {
    ls::LogLevel logLevel{ls::LogLevelValue::DEBUG};
    ASSERT_TRUE(logLevel > ls::LogLevelValue::ERR);
  }

  TEST_F(LogLevelTest, operator_greater_than_not_greater_than)
  {
    ls::LogLevel logLevel{ls::LogLevelValue::DEBUG};
    ASSERT_FALSE(logLevel > ls::LogLevelValue::DEBUG);
  }

  TEST_F(LogLevelTest, operator_greater_than_equals)
  {
    ls::LogLevel logLevel{ls::LogLevelValue::DEBUG};
    ASSERT_TRUE(logLevel >= ls::LogLevelValue::ERR);
  }

  TEST_F(LogLevelTest, operator_greater_than_equals_not_greater_than_equals)
  {
    ls::LogLevel logLevel{};
    ASSERT_FALSE(logLevel >= ls::LogLevelValue::ERR);
  }

  TEST_F(LogLevelTest, operator_equals)
  {
    ls::LogLevel logLevel{ls::LogLevelValue::DEBUG};
    ASSERT_TRUE(logLevel == ls::LogLevelValue::DEBUG);
  }

  TEST_F(LogLevelTest, operator_equals_not_equals)
  {
    ls::LogLevel logLevel{ls::LogLevelValue::TRACE};
    ASSERT_FALSE(logLevel == ls::LogLevelValue::DEBUG);
  }

  TEST_F(LogLevelTest, setLogLevel_with_log_level_value)
  {
    ls::LogLevel logLevel{};
    logLevel.setLogLevel(ls::LogLevelValue::INFO);

    ASSERT_EQ(ls::LogLevelValue::INFO, logLevel);
  }

  TEST_F(LogLevelTest, setLogLevel_with_string)
  {
    ls::LogLevel logLevel{};

    logLevel.setLogLevel("FATAL");
    ASSERT_EQ(ls::LogLevelValue::FATAL, logLevel);
    logLevel.setLogLevel("ERROR");
    ASSERT_EQ(ls::LogLevelValue::ERR, logLevel);
    logLevel.setLogLevel("WARN");
    ASSERT_EQ(ls::LogLevelValue::WARN, logLevel);
    logLevel.setLogLevel("INFO");
    ASSERT_EQ(ls::LogLevelValue::INFO, logLevel);
    logLevel.setLogLevel("DEBUG");
    ASSERT_EQ(ls::LogLevelValue::DEBUG, logLevel);
    logLevel.setLogLevel("TRACE");
    ASSERT_EQ(ls::LogLevelValue::TRACE, logLevel);
  }

  TEST_F(LogLevelTest, setLogLevel_string_no_valid_string)
  {
    ls::LogLevel logLevel{};

    EXPECT_THROW({
                   try
                   {
                     logLevel.setLogLevel("This is not a valid log level!");
                   }
                   catch (const ls::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::IllegalArgumentException);
  }

  TEST_F(LogLevelTest, toString)
  {
    ls::LogLevel logLevel{};
    ASSERT_STREQ("FATAL", logLevel.toString().c_str());
    logLevel.setLogLevel(ls::LogLevelValue::ERR);
    ASSERT_STREQ("ERROR", logLevel.toString().c_str());
    logLevel.setLogLevel(ls::LogLevelValue::WARN);
    ASSERT_STREQ("WARN", logLevel.toString().c_str());
    logLevel.setLogLevel(ls::LogLevelValue::INFO);
    ASSERT_STREQ("INFO", logLevel.toString().c_str());
    logLevel.setLogLevel(ls::LogLevelValue::DEBUG);
    ASSERT_STREQ("DEBUG", logLevel.toString().c_str());
    logLevel.setLogLevel(ls::LogLevelValue::TRACE);
    ASSERT_STREQ("TRACE", logLevel.toString().c_str());
  }
}
