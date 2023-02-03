/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-18
 * Changed:         2023-02-03
 *
 * */

#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>

using namespace ls::std::core;
using namespace ::std;

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
    string escapedString = RegexUtils::escapeString("Hello?!");
    ASSERT_STREQ(R"(Hello\?!)", escapedString.c_str());

    escapedString = RegexUtils::escapeString(R"(\)");
    ASSERT_STREQ(R"(\\)", escapedString.c_str());
  }
}
