/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-04-07
* Changed:         2023-04-08
*
* */

#include <gtest/gtest.h>
#include <ls-std-core-jni-test.hpp>
#include <ls-std/ls-std-core-jni.hpp>
#include <memory>

using ls::std::core::JniApi;
using ls::std::core::JniClassParameter;
using ls::std::core::interface_type::IJniApi;
using std::make_shared;
using std::shared_ptr;
using test::core::jni::MockJniApi;
using testing::Test;

namespace
{
  class JniClassParameterTest : public Test
  {
    public:

      JniClassParameterTest() = default;
      ~JniClassParameterTest() override = default;
  };

  TEST_F(JniClassParameterTest, getJavaEnvironment)
  {
    JniClassParameter parameter{};
    ASSERT_TRUE(parameter.getJavaEnvironment() == nullptr);
  }

  TEST_F(JniClassParameterTest, getJavaObject)
  {
    JniClassParameter parameter{};
    ASSERT_TRUE(parameter.getJavaObject() == nullptr);
  }

  TEST_F(JniClassParameterTest, getJniApi)
  {
    JniClassParameter parameter{};
    ASSERT_TRUE(parameter.getJniApi() == nullptr);
  }

  TEST_F(JniClassParameterTest, setJavaEnvironment)
  {
    JniClassParameter parameter{};
    shared_ptr<JNIEnv> environment = make_shared<JNIEnv>();
    parameter.setJavaEnvironment(environment.get());

    ASSERT_TRUE(parameter.getJavaEnvironment() == environment.get());
  }

  TEST_F(JniClassParameterTest, setJavaObject)
  {
    JniClassParameter parameter{};
    shared_ptr<_jobject> javaObject = make_shared<_jobject>();
    parameter.setJavaObject(javaObject.get());

    ASSERT_TRUE(parameter.getJavaObject() == javaObject.get());
  }

  TEST_F(JniClassParameterTest, setJniApi)
  {
    JniClassParameter parameter{};
    shared_ptr<IJniApi> jniApi = make_shared<MockJniApi>();
    parameter.setJniApi(jniApi);

    ASSERT_TRUE(parameter.getJniApi() == jniApi);
  }
}
