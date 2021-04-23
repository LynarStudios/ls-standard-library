/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-18
 * Changed:         2021-04-23
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>

namespace
{
  class RegexUtilsTest : public ::testing::Test
  {
    protected:

      RegexUtilsTest() = default;
      ~RegexUtilsTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(RegexUtilsTest, escapeString)
  {
    std::string escapedString = ls_std::RegexUtils::escapeString("Hello?!");
    ASSERT_STREQ(R"(Hello\?!)", escapedString.c_str());

    escapedString = ls_std::RegexUtils::escapeString(R"(\)");
    ASSERT_STREQ(R"(\\)", escapedString.c_str());
  }
}
