/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-04-08
* Changed:         2023-04-11
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

  TEST_F(JniReturnValueTest, getBooleanValue)
  {
    JniReturnValue returnValue{};
    ASSERT_FALSE(returnValue.getBooleanValue());
  }

  TEST_F(JniReturnValueTest, getByteValue)
  {
    JniReturnValue returnValue{};
    ASSERT_EQ(0, returnValue.getByteValue());
  }

  TEST_F(JniReturnValueTest, getCharValue)
  {
    JniReturnValue returnValue{};
    ASSERT_EQ(0, (int) returnValue.getCharValue());
  }

  TEST_F(JniReturnValueTest, getFloatValue)
  {
    JniReturnValue returnValue{};
    ASSERT_FLOAT_EQ(0.0f, returnValue.getFloatValue());
  }

  TEST_F(JniReturnValueTest, getIntegerValue)
  {
    JniReturnValue returnValue{};
    ASSERT_EQ(0, returnValue.getIntegerValue());
  }

  TEST_F(JniReturnValueTest, getLongValue)
  {
    JniReturnValue returnValue{};
    ASSERT_EQ(0, returnValue.getLongValue());
  }

  TEST_F(JniReturnValueTest, getShortValue)
  {
    JniReturnValue returnValue{};
    ASSERT_EQ(0, returnValue.getShortValue());
  }

  TEST_F(JniReturnValueTest, setBooleanValue)
  {
    JniReturnValue returnValue{};
    returnValue.setBooleanValue(true);

    ASSERT_TRUE(returnValue.getBooleanValue());
  }

  TEST_F(JniReturnValueTest, setByteValue)
  {
    JniReturnValue returnValue{};
    returnValue.setByteValue(22);

    ASSERT_EQ(22, returnValue.getByteValue());
  }

  TEST_F(JniReturnValueTest, setCharValue)
  {
    JniReturnValue returnValue{};
    returnValue.setCharValue('P');

    ASSERT_EQ('P', returnValue.getCharValue());
  }

  TEST_F(JniReturnValueTest, setFloatValue)
  {
    JniReturnValue returnValue{};
    returnValue.setFloatValue(13.56f);

    ASSERT_FLOAT_EQ(13.56f, returnValue.getFloatValue());
  }

  TEST_F(JniReturnValueTest, setIntegerValue)
  {
    JniReturnValue returnValue{};
    returnValue.setIntegerValue(1989);

    ASSERT_EQ(1989, returnValue.getIntegerValue());
  }

  TEST_F(JniReturnValueTest, setLongValue)
  {
    JniReturnValue returnValue{};
    returnValue.setLongValue(16992831);

    ASSERT_EQ(16992831, returnValue.getLongValue());
  }

  TEST_F(JniReturnValueTest, setShortValue)
  {
    JniReturnValue returnValue{};
    returnValue.setShortValue(13);

    ASSERT_EQ(13, returnValue.getShortValue());
  }
}
