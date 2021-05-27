/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-05-02
 * Changed:         2021-05-02
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

  TEST_F(LogLevelTest, constructor_withLogLevelValueParameter)
  {
    ls_std::LogLevel logLevel{ls_std::LogLevelValue::INFO};
    ASSERT_EQ(ls_std::LogLevelValue::INFO, logLevel);
  }

  TEST_F(LogLevelTest, constructor_default)
  {
    ls_std::LogLevel logLevel{};
    ASSERT_EQ(ls_std::LogLevelValue::FATAL, logLevel);
  }

  TEST_F(LogLevelTest, operator_assign)
  {
    ls_std::LogLevel logLevel{ls_std::LogLevelValue::DEBUG};
    logLevel = ls_std::LogLevelValue::INFO;

    ASSERT_EQ(ls_std::LogLevelValue::INFO, logLevel);
  }

  TEST_F(LogLevelTest, operator_lessThan)
  {
    ls_std::LogLevel logLevel{}; // default is FATAL

    ASSERT_TRUE(logLevel < ls_std::LogLevelValue::ERR);
    ASSERT_TRUE(logLevel < ls_std::LogLevelValue::WARN);
    ASSERT_TRUE(logLevel < ls_std::LogLevelValue::INFO);
    ASSERT_TRUE(logLevel < ls_std::LogLevelValue::DEBUG);
    ASSERT_TRUE(logLevel < ls_std::LogLevelValue::TRACE);
  }

  TEST_F(LogLevelTest, operator_lessThan_notLessThan)
  {
    ls_std::LogLevel logLevel{ls_std::LogLevelValue::DEBUG};
    ASSERT_FALSE(logLevel < ls_std::LogLevelValue::ERR);
  }

  TEST_F(LogLevelTest, operator_lessThanEqual)
  {
    ls_std::LogLevel logLevel{}; // default is FATAL

    ASSERT_TRUE(logLevel <= ls_std::LogLevelValue::FATAL);
    ASSERT_TRUE(logLevel <= ls_std::LogLevelValue::ERR);
    ASSERT_TRUE(logLevel <= ls_std::LogLevelValue::WARN);
    ASSERT_TRUE(logLevel <= ls_std::LogLevelValue::INFO);
    ASSERT_TRUE(logLevel <= ls_std::LogLevelValue::DEBUG);
    ASSERT_TRUE(logLevel <= ls_std::LogLevelValue::TRACE);
  }

  TEST_F(LogLevelTest, operator_lessThanEqual_notLessThanEqual)
  {
    ls_std::LogLevel logLevel{ls_std::LogLevelValue::DEBUG};
    ASSERT_FALSE(logLevel <= ls_std::LogLevelValue::ERR);
  }

  TEST_F(LogLevelTest, operator_greaterThan)
  {
    ls_std::LogLevel logLevel{ls_std::LogLevelValue::DEBUG};
    ASSERT_TRUE(logLevel > ls_std::LogLevelValue::ERR);
  }

  TEST_F(LogLevelTest, operator_greaterThan_notGreaterThan)
  {
    ls_std::LogLevel logLevel{ls_std::LogLevelValue::DEBUG};
    ASSERT_FALSE(logLevel > ls_std::LogLevelValue::DEBUG);
  }

  TEST_F(LogLevelTest, operator_greaterThanEqual)
  {
    ls_std::LogLevel logLevel{ls_std::LogLevelValue::DEBUG};
    ASSERT_TRUE(logLevel >= ls_std::LogLevelValue::ERR);
  }

  TEST_F(LogLevelTest, operator_greaterThanEqual_notGreaterThanEqual)
  {
    ls_std::LogLevel logLevel{};
    ASSERT_FALSE(logLevel >= ls_std::LogLevelValue::ERR);
  }

  TEST_F(LogLevelTest, operator_equals)
  {
    ls_std::LogLevel logLevel{ls_std::LogLevelValue::DEBUG};
    ASSERT_TRUE(logLevel == ls_std::LogLevelValue::DEBUG);
  }

  TEST_F(LogLevelTest, operator_equals_notEquals)
  {
    ls_std::LogLevel logLevel{ls_std::LogLevelValue::TRACE};
    ASSERT_FALSE(logLevel == ls_std::LogLevelValue::DEBUG);
  }

  TEST_F(LogLevelTest, setLogLevel_logLevelValue)
  {
    ls_std::LogLevel logLevel{};
    logLevel.setLogLevel(ls_std::LogLevelValue::INFO);

    ASSERT_EQ(ls_std::LogLevelValue::INFO, logLevel);
  }

  TEST_F(LogLevelTest, setLogLevel_string)
  {
    ls_std::LogLevel logLevel{};

    logLevel.setLogLevel("FATAL");
    ASSERT_EQ(ls_std::LogLevelValue::FATAL, logLevel);
    logLevel.setLogLevel("ERROR");
    ASSERT_EQ(ls_std::LogLevelValue::ERR, logLevel);
    logLevel.setLogLevel("WARN");
    ASSERT_EQ(ls_std::LogLevelValue::WARN, logLevel);
    logLevel.setLogLevel("INFO");
    ASSERT_EQ(ls_std::LogLevelValue::INFO, logLevel);
    logLevel.setLogLevel("DEBUG");
    ASSERT_EQ(ls_std::LogLevelValue::DEBUG, logLevel);
    logLevel.setLogLevel("TRACE");
    ASSERT_EQ(ls_std::LogLevelValue::TRACE, logLevel);
  }

  TEST_F(LogLevelTest, setLogLevel_string_noValidString)
  {
    ls_std::LogLevel logLevel{};

    EXPECT_THROW({
                   try
                   {
                     logLevel.setLogLevel("This is not a valid log level!");
                   }
                   catch (const ls_std::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls_std::IllegalArgumentException);
  }

  TEST_F(LogLevelTest, toString)
  {
    ls_std::LogLevel logLevel{};
    ASSERT_STREQ("FATAL", logLevel.toString().c_str());
    logLevel.setLogLevel(ls_std::LogLevelValue::ERR);
    ASSERT_STREQ("ERROR", logLevel.toString().c_str());
    logLevel.setLogLevel(ls_std::LogLevelValue::WARN);
    ASSERT_STREQ("WARN", logLevel.toString().c_str());
    logLevel.setLogLevel(ls_std::LogLevelValue::INFO);
    ASSERT_STREQ("INFO", logLevel.toString().c_str());
    logLevel.setLogLevel(ls_std::LogLevelValue::DEBUG);
    ASSERT_STREQ("DEBUG", logLevel.toString().c_str());
    logLevel.setLogLevel(ls_std::LogLevelValue::TRACE);
    ASSERT_STREQ("TRACE", logLevel.toString().c_str());
  }
}
