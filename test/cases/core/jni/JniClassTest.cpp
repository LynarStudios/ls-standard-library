/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-04-07
* Changed:         2023-04-07
*
* */

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <ls-std-core-jni-test.hpp>
#include <ls-std/ls-std-core-jni.hpp>
#include <ls-std/ls-std-core.hpp>
#include <memory>

using ls::std::core::IllegalArgumentException;
using ls::std::core::JniClass;
using ls::std::core::JniClassParameter;
using std::make_shared;
using std::shared_ptr;
using std::string;
using test::core::jni::MockJniApi;
using testing::AtLeast;
using testing::Return;
using testing::Test;

namespace
{
  class JniClassTest : public Test
  {
    public:

      JniClassTest() = default;
      ~JniClassTest() override = default;
  };

  TEST_F(JniClassTest, constructor_no_parameter_reference)
  {
    EXPECT_THROW(
        {
          try
          {
            JniClass javaClass(nullptr, "java.utils.String");
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(JniClassTest, constructor_empty_path)
  {
    EXPECT_THROW(
        {
          try
          {
            JniClass javaClass(make_shared<JniClassParameter>(), "");
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(JniClassTest, constructor_no_java_environment_reference)
  {
    EXPECT_THROW(
        {
          try
          {
            JniClass javaClass(make_shared<JniClassParameter>(), "java.utils.String");
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(JniClassTest, load)
  {
    shared_ptr<JniClassParameter> parameter = make_shared<JniClassParameter>();
    shared_ptr<MockJniApi> mockJniApi = make_shared<MockJniApi>();
    parameter->setJniApi(mockJniApi);
    shared_ptr<JNIEnv> environment = make_shared<JNIEnv>();
    parameter->setJavaEnvironment(environment.get());
    string classPath = "java.utils.String";
    JniClass javaClass{parameter, classPath};

    EXPECT_CALL(*mockJniApi, findClass(classPath)).Times(AtLeast(1));
    ON_CALL(*mockJniApi, findClass(classPath)).WillByDefault(Return(make_shared<_jclass>().get()));

    ASSERT_TRUE(javaClass.load());
  }
}
