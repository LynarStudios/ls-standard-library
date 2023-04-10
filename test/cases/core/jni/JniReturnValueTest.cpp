/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-04-08
* Changed:         2023-04-10
*
* */

#include <gtest/gtest.h>
#include <ls-std/ls-std-core-jni.hpp>

using ls::std::core::experimental::JniReturnValue;
using testing::Test;

namespace
{
  class JniReturnValueTest : public Test
  {
    public:

      JniReturnValueTest() = default;
      ~JniReturnValueTest() override = default;
  };

  TEST_F(JniReturnValueTest, getByteValue)
  {
    JniReturnValue returnValue{};
    ASSERT_EQ(0, returnValue.getByteValue());
  }

  TEST_F(JniReturnValueTest, getIntegerValue)
  {
    JniReturnValue returnValue{};
    ASSERT_EQ(0, returnValue.getIntegerValue());
  }

  TEST_F(JniReturnValueTest, setByteValue)
  {
    JniReturnValue returnValue{};
    returnValue.setByteValue(22);

    ASSERT_EQ(22, returnValue.getByteValue());
  }

  TEST_F(JniReturnValueTest, setIntegerValue)
  {
    JniReturnValue returnValue{};
    returnValue.setIntegerValue(1989);

    ASSERT_EQ(1989, returnValue.getIntegerValue());
  }
}
