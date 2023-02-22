/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-07
* Changed:         2023-02-22
*
* */

#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>

using namespace ls::std::core;
using namespace ::testing;
using namespace ::std;

namespace
{
  class ExceptionMessageTest : public Test
  {
    protected:

      ExceptionMessageTest() = default;
      ~ExceptionMessageTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(ExceptionMessageTest, toCharacterPointer)
  {
    string text = "hello!";

    ExceptionMessage message{text};
    char *characterPointer = message.toCharacterPointer();
    ASSERT_STREQ(text.c_str(), characterPointer);

    delete characterPointer;
  }

  TEST_F(ExceptionMessageTest, toCharacterPointer_empty)
  {
    ExceptionMessage message{""};
    ASSERT_TRUE(message.toCharacterPointer() == nullptr);
  }
}
