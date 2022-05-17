/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-01-08
 * Changed:         2022-05-17
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std_encoding.hpp>

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

  TEST_F(Base64Test, encode)
  {
    ls::std::encoding::Base64 base64{};

    ASSERT_STREQ("YWJj", base64.encode("abc").c_str());
  }

  TEST_F(Base64Test, decode)
  {
    ls::std::encoding::Base64 base64{};

    ASSERT_STREQ("abc", base64.decode("YWJj").c_str());
    ASSERT_STREQ("abcde", base64.decode("YWJjZGU=").c_str());
    ASSERT_STREQ("Hello C++!", base64.decode("SGVsbG8gQysrIQ==").c_str());
  }
}
