/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-18
 * Changed:         2022-05-13
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std_core.hpp>

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
    std::string escapedString = ls::std::core::RegexUtils::escapeString("Hello?!");
    ASSERT_STREQ(R"(Hello\?!)", escapedString.c_str());

    escapedString = ls::std::core::RegexUtils::escapeString(R"(\)");
    ASSERT_STREQ(R"(\\)", escapedString.c_str());
  }
}
