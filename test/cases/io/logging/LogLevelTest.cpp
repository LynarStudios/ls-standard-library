/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-05-02
 * Changed:         2022-05-14
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std_core.hpp>
#include <ls_std/ls_std_io.hpp>

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
    ls::std::io::LogLevel logLevel{ls::std::io::LogLevelValue::INFO};
    ASSERT_EQ(ls::std::io::LogLevelValue::INFO, logLevel);
  }

  TEST_F(LogLevelTest, constructor_default)
  {
    ls::std::io::LogLevel logLevel{};
    ASSERT_EQ(ls::std::io::LogLevelValue::FATAL, logLevel);
  }

  TEST_F(LogLevelTest, operator_assign)
  {
    ls::std::io::LogLevel logLevel{ls::std::io::LogLevelValue::DEBUG};
    logLevel = ls::std::io::LogLevelValue::INFO;

    ASSERT_EQ(ls::std::io::LogLevelValue::INFO, logLevel);
  }

  TEST_F(LogLevelTest, operator_lessThan)
  {
    ls::std::io::LogLevel logLevel{}; // default is FATAL

    ASSERT_TRUE(logLevel < ls::std::io::LogLevelValue::ERR);
    ASSERT_TRUE(logLevel < ls::std::io::LogLevelValue::WARN);
    ASSERT_TRUE(logLevel < ls::std::io::LogLevelValue::INFO);
    ASSERT_TRUE(logLevel < ls::std::io::LogLevelValue::DEBUG);
    ASSERT_TRUE(logLevel < ls::std::io::LogLevelValue::TRACE);
  }

  TEST_F(LogLevelTest, operator_lessThan_not_less_than)
  {
    ls::std::io::LogLevel logLevel{ls::std::io::LogLevelValue::DEBUG};
    ASSERT_FALSE(logLevel < ls::std::io::LogLevelValue::ERR);
  }

  TEST_F(LogLevelTest, operator_less_than_equals)
  {
    ls::std::io::LogLevel logLevel{}; // default is FATAL

    ASSERT_TRUE(logLevel <= ls::std::io::LogLevelValue::FATAL);
    ASSERT_TRUE(logLevel <= ls::std::io::LogLevelValue::ERR);
    ASSERT_TRUE(logLevel <= ls::std::io::LogLevelValue::WARN);
    ASSERT_TRUE(logLevel <= ls::std::io::LogLevelValue::INFO);
    ASSERT_TRUE(logLevel <= ls::std::io::LogLevelValue::DEBUG);
    ASSERT_TRUE(logLevel <= ls::std::io::LogLevelValue::TRACE);
  }

  TEST_F(LogLevelTest, operator_less_than_equals_not_less_than_equals)
  {
    ls::std::io::LogLevel logLevel{ls::std::io::LogLevelValue::DEBUG};
    ASSERT_FALSE(logLevel <= ls::std::io::LogLevelValue::ERR);
  }

  TEST_F(LogLevelTest, operator_greater_than)
  {
    ls::std::io::LogLevel logLevel{ls::std::io::LogLevelValue::DEBUG};
    ASSERT_TRUE(logLevel > ls::std::io::LogLevelValue::ERR);
  }

  TEST_F(LogLevelTest, operator_greater_than_not_greater_than)
  {
    ls::std::io::LogLevel logLevel{ls::std::io::LogLevelValue::DEBUG};
    ASSERT_FALSE(logLevel > ls::std::io::LogLevelValue::DEBUG);
  }

  TEST_F(LogLevelTest, operator_greater_than_equals)
  {
    ls::std::io::LogLevel logLevel{ls::std::io::LogLevelValue::DEBUG};
    ASSERT_TRUE(logLevel >= ls::std::io::LogLevelValue::ERR);
  }

  TEST_F(LogLevelTest, operator_greater_than_equals_not_greater_than_equals)
  {
    ls::std::io::LogLevel logLevel{};
    ASSERT_FALSE(logLevel >= ls::std::io::LogLevelValue::ERR);
  }

  TEST_F(LogLevelTest, operator_equals)
  {
    ls::std::io::LogLevel logLevel{ls::std::io::LogLevelValue::DEBUG};
    ASSERT_TRUE(logLevel == ls::std::io::LogLevelValue::DEBUG);
  }

  TEST_F(LogLevelTest, operator_equals_not_equals)
  {
    ls::std::io::LogLevel logLevel{ls::std::io::LogLevelValue::TRACE};
    ASSERT_FALSE(logLevel == ls::std::io::LogLevelValue::DEBUG);
  }

  TEST_F(LogLevelTest, setLogLevel_with_log_level_value)
  {
    ls::std::io::LogLevel logLevel{};
    logLevel.setLogLevel(ls::std::io::LogLevelValue::INFO);

    ASSERT_EQ(ls::std::io::LogLevelValue::INFO, logLevel);
  }

  TEST_F(LogLevelTest, setLogLevel_with_string)
  {
    ls::std::io::LogLevel logLevel{};

    logLevel.setLogLevel("FATAL");
    ASSERT_EQ(ls::std::io::LogLevelValue::FATAL, logLevel);
    logLevel.setLogLevel("ERROR");
    ASSERT_EQ(ls::std::io::LogLevelValue::ERR, logLevel);
    logLevel.setLogLevel("WARN");
    ASSERT_EQ(ls::std::io::LogLevelValue::WARN, logLevel);
    logLevel.setLogLevel("INFO");
    ASSERT_EQ(ls::std::io::LogLevelValue::INFO, logLevel);
    logLevel.setLogLevel("DEBUG");
    ASSERT_EQ(ls::std::io::LogLevelValue::DEBUG, logLevel);
    logLevel.setLogLevel("TRACE");
    ASSERT_EQ(ls::std::io::LogLevelValue::TRACE, logLevel);
  }

  TEST_F(LogLevelTest, setLogLevel_string_no_valid_string)
  {
    ls::std::io::LogLevel logLevel{};

    EXPECT_THROW({
                   try
                   {
                     logLevel.setLogLevel("This is not a valid log level!");
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }

  TEST_F(LogLevelTest, toString)
  {
    ls::std::io::LogLevel logLevel{};
    ASSERT_STREQ("FATAL", logLevel.toString().c_str());
    logLevel.setLogLevel(ls::std::io::LogLevelValue::ERR);
    ASSERT_STREQ("ERROR", logLevel.toString().c_str());
    logLevel.setLogLevel(ls::std::io::LogLevelValue::WARN);
    ASSERT_STREQ("WARN", logLevel.toString().c_str());
    logLevel.setLogLevel(ls::std::io::LogLevelValue::INFO);
    ASSERT_STREQ("INFO", logLevel.toString().c_str());
    logLevel.setLogLevel(ls::std::io::LogLevelValue::DEBUG);
    ASSERT_STREQ("DEBUG", logLevel.toString().c_str());
    logLevel.setLogLevel(ls::std::io::LogLevelValue::TRACE);
    ASSERT_STREQ("TRACE", logLevel.toString().c_str());
  }
}
