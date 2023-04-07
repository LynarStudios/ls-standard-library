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
using ls::std::core::NullPointerException;
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

      JniClass createJniClass(const string &_classPath)
      {
        shared_ptr<JniClassParameter> parameter = make_shared<JniClassParameter>();
        this->jniApi = make_shared<MockJniApi>();
        parameter->setJniApi(this->jniApi);
        shared_ptr<JNIEnv> environment = make_shared<JNIEnv>();
        parameter->setJavaEnvironment(environment.get());

        return JniClass{parameter, _classPath};
      }

      shared_ptr<MockJniApi> jniApi{};
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

  TEST_F(JniClassTest, hasMethod)
  {
    string classPath = "java.utils.String";
    JniClass javaClass = this->createJniClass(classPath);

    ASSERT_FALSE(javaClass.hasMethod("getDay"));
  }

  TEST_F(JniClassTest, load)
  {
    string classPath = "java.utils.String";
    JniClass javaClass = this->createJniClass(classPath);

    EXPECT_CALL(*this->jniApi, findClass(classPath)).Times(AtLeast(1));
    ON_CALL(*this->jniApi, findClass(classPath)).WillByDefault(Return(make_shared<_jclass>().get()));

    ASSERT_TRUE(javaClass.load());
  }

  TEST_F(JniClassTest, loadMethod)
  {
    string classPath = "java.utils.String";
    JniClass javaClass = this->createJniClass(classPath);

    EXPECT_CALL(*this->jniApi, findClass(classPath)).Times(AtLeast(1));
    ON_CALL(*this->jniApi, findClass(classPath)).WillByDefault(Return(make_shared<_jclass>().get()));
    string methodIdentifier = "getDay";
    string methodSignature = "()B";
    EXPECT_CALL(*this->jniApi, getMethodId(testing::_, methodIdentifier.c_str(), methodSignature.c_str())).Times(AtLeast(1));
    jmethodID methodId = (jmethodID) make_shared<int>().get();
    ON_CALL(*this->jniApi, getMethodId(testing::_, methodIdentifier.c_str(), methodSignature.c_str())).WillByDefault(Return(methodId));

    ASSERT_TRUE(javaClass.load());
    ASSERT_TRUE(javaClass.loadMethod(methodIdentifier, methodSignature));
  }

  TEST_F(JniClassTest, loadMethod_repeat)
  {
    string classPath = "java.utils.String";
    JniClass javaClass = this->createJniClass(classPath);

    EXPECT_CALL(*this->jniApi, findClass(classPath)).Times(AtLeast(1));
    ON_CALL(*this->jniApi, findClass(classPath)).WillByDefault(Return(make_shared<_jclass>().get()));
    string methodIdentifier = "getDay";
    string methodSignature = "()B";
    EXPECT_CALL(*this->jniApi, getMethodId(testing::_, methodIdentifier.c_str(), methodSignature.c_str())).Times(AtLeast(1));
    jmethodID methodId = (jmethodID) make_shared<int>().get();
    ON_CALL(*this->jniApi, getMethodId(testing::_, methodIdentifier.c_str(), methodSignature.c_str())).WillByDefault(Return(methodId));

    ASSERT_TRUE(javaClass.load());
    ASSERT_TRUE(javaClass.loadMethod(methodIdentifier, methodSignature));
    ASSERT_FALSE(javaClass.loadMethod(methodIdentifier, methodSignature));
  }

  TEST_F(JniClassTest, loadMethod_without_previous_class_load)
  {
    string classPath = "java.utils.String";
    JniClass javaClass = this->createJniClass(classPath);

    string methodIdentifier = "getDay";
    string methodSignature = "()B";

    EXPECT_THROW(
        {
          try
          {
            javaClass.loadMethod(methodIdentifier, methodSignature);
          }
          catch (const NullPointerException &_exception)
          {
            throw;
          }
        },
        NullPointerException);
  }
}
