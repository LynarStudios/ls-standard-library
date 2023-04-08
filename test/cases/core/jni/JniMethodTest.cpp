/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-04-08
* Changed:         2023-04-08
*
* */

#include <gtest/gtest.h>
#include <ls-std/ls-std-core-jni.hpp>
#include <ls-std/ls-std-core.hpp>
#include <memory>

using ls::std::core::IllegalArgumentException;
using ls::std::core::JniMethod;
using std::make_shared;
using testing::Test;

namespace
{
  class JniMethodTest : public Test
  {
    public:

      JniMethodTest() = default;
      ~JniMethodTest() override = default;
  };

  TEST_F(JniMethodTest, constructor_empty_method_identifier)
  {
    EXPECT_THROW(
        {
          try
          {
            JniMethod method("", "()B");
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(JniMethodTest, constructor_empty_method_signature)
  {
    EXPECT_THROW(
        {
          try
          {
            JniMethod method("getDay", "");
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(JniMethodTest, getMethodId)
  {
    JniMethod method{"getDay", "()B"};
    ASSERT_TRUE(method.getMethodId() == nullptr);
  }

  TEST_F(JniMethodTest, getMethodIdentifier)
  {
    JniMethod method{"getDay", "()B"};
    ASSERT_STREQ("getDay", method.getMethodIdentifier().c_str());
  }

  TEST_F(JniMethodTest, getMethodSignature)
  {
    JniMethod method{"getDay", "()B"};
    ASSERT_STREQ("()B", method.getMethodSignature().c_str());
  }

  TEST_F(JniMethodTest, setMethodId)
  {
    JniMethod method{"getDay", "()B"};
    jmethodID methodId = (jmethodID) make_shared<int>().get();
    method.setMethodId(methodId);

    ASSERT_TRUE(method.getMethodId() == methodId);
  }

  TEST_F(JniMethodTest, setMethodIdentifier)
  {
    JniMethod method{"getDay", "()B"};
    method.setMethodIdentifier("getHour");

    ASSERT_STREQ("getHour", method.getMethodIdentifier().c_str());
  }

  TEST_F(JniMethodTest, setMethodSignature)
  {
    JniMethod method{"getDay", "()B"};
    method.setMethodSignature("()I");

    ASSERT_STREQ("()I", method.getMethodSignature().c_str());
  }
}
