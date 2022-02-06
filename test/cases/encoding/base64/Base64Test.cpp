/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-01-08
 * Changed:         2022-02-06
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>

namespace
{
  class Base64Test : public ::testing::Test
  {
    protected:

      Base64Test() = default;
      ~Base64Test() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  /*
   * abc -> 01100001 01100010 01100011 -> 6382179
   * */
  TEST_F(Base64Test, encode)
  {
    ls_std::Base64 base64{};
    std::string sequence = "abc";

    ASSERT_STREQ("YWJj", base64.encode(sequence).c_str());
  }

  TEST_F(Base64Test, decode)
  {
    ls_std::Base64 base64{};
    std::string base64Sequence = "YWJjZA==";

    ASSERT_STREQ("abcd", base64.decode(base64Sequence).c_str());
  }
}
