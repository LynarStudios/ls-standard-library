/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-04-07
* Changed:         2023-04-11
*
* */

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <ls-std-core-jni-test.hpp>
#include <ls-std/ls-std-core-jni.hpp>
#include <ls-std/ls-std-core.hpp>
#include <memory>

using ls::std::core::IllegalArgumentException;
using ls::std::core::NullPointerException;
using ls::std::core::experimental::JniClass;
using ls::std::core::experimental::JniClassParameter;
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
            string expected = _exception.getName() + " thrown - no provided reference to JNI class parameter!";
            string actual = _exception.what();

            ASSERT_STREQ(expected.c_str(), actual.c_str());
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
            string expected = _exception.getName() + " thrown - path to associated Java class is empty!";
            string actual = _exception.what();

            ASSERT_STREQ(expected.c_str(), actual.c_str());
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
            string expected = _exception.getName() + " thrown - Java environment is not being provided!";
            string actual = _exception.what();

            ASSERT_STREQ(expected.c_str(), actual.c_str());
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(JniClassTest, callMethod_boolean_return_value)
  {
    string classPath = "java.utils.String";
    JniClass javaClass = this->createJniClass(classPath);

    EXPECT_CALL(*this->jniApi, findClass(classPath)).Times(AtLeast(1));
    ON_CALL(*this->jniApi, findClass(classPath)).WillByDefault(Return(make_shared<_jclass>().get()));

    string methodIdentifier = "isBlue";
    string methodSignature = "()Z";
    EXPECT_CALL(*this->jniApi, getMethodId(testing::_, methodIdentifier.c_str(), methodSignature.c_str())).Times(AtLeast(1));
    jmethodID methodId = (jmethodID) make_shared<int>().get();
    ON_CALL(*this->jniApi, getMethodId(testing::_, methodIdentifier.c_str(), methodSignature.c_str())).WillByDefault(Return(methodId));

    EXPECT_CALL(*this->jniApi, callBooleanMethod(testing::_, methodId)).Times(AtLeast(1));
    ON_CALL(*this->jniApi, callBooleanMethod(testing::_, methodId)).WillByDefault(Return(true));

    ASSERT_TRUE(javaClass.load());
    ASSERT_TRUE(javaClass.loadMethod(methodIdentifier, methodSignature));
    ASSERT_TRUE(javaClass.callMethod(methodIdentifier).getBooleanValue());
  }

  TEST_F(JniClassTest, callMethod_byte_return_value)
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

    EXPECT_CALL(*this->jniApi, callByteMethod(testing::_, methodId)).Times(AtLeast(1));
    ON_CALL(*this->jniApi, callByteMethod(testing::_, methodId)).WillByDefault(Return(22));

    ASSERT_TRUE(javaClass.load());
    ASSERT_TRUE(javaClass.loadMethod(methodIdentifier, methodSignature));
    ASSERT_EQ(22, javaClass.callMethod(methodIdentifier).getByteValue());
  }

  TEST_F(JniClassTest, callMethod_char_return_value)
  {
    string classPath = "java.utils.String";
    JniClass javaClass = this->createJniClass(classPath);

    EXPECT_CALL(*this->jniApi, findClass(classPath)).Times(AtLeast(1));
    ON_CALL(*this->jniApi, findClass(classPath)).WillByDefault(Return(make_shared<_jclass>().get()));

    string methodIdentifier = "getLetter";
    string methodSignature = "()C";
    EXPECT_CALL(*this->jniApi, getMethodId(testing::_, methodIdentifier.c_str(), methodSignature.c_str())).Times(AtLeast(1));
    jmethodID methodId = (jmethodID) make_shared<int>().get();
    ON_CALL(*this->jniApi, getMethodId(testing::_, methodIdentifier.c_str(), methodSignature.c_str())).WillByDefault(Return(methodId));

    EXPECT_CALL(*this->jniApi, callCharMethod(testing::_, methodId)).Times(AtLeast(1));
    ON_CALL(*this->jniApi, callCharMethod(testing::_, methodId)).WillByDefault(Return('P'));

    ASSERT_TRUE(javaClass.load());
    ASSERT_TRUE(javaClass.loadMethod(methodIdentifier, methodSignature));
    ASSERT_EQ('P', javaClass.callMethod(methodIdentifier).getCharValue());
  }

  TEST_F(JniClassTest, callMethod_integer_return_value)
  {
    string classPath = "java.utils.String";
    JniClass javaClass = this->createJniClass(classPath);

    EXPECT_CALL(*this->jniApi, findClass(classPath)).Times(AtLeast(1));
    ON_CALL(*this->jniApi, findClass(classPath)).WillByDefault(Return(make_shared<_jclass>().get()));

    string methodIdentifier = "getYear";
    string methodSignature = "()I";
    EXPECT_CALL(*this->jniApi, getMethodId(testing::_, methodIdentifier.c_str(), methodSignature.c_str())).Times(AtLeast(1));
    jmethodID methodId = (jmethodID) make_shared<int>().get();
    ON_CALL(*this->jniApi, getMethodId(testing::_, methodIdentifier.c_str(), methodSignature.c_str())).WillByDefault(Return(methodId));

    EXPECT_CALL(*this->jniApi, callIntMethod(testing::_, methodId)).Times(AtLeast(1));
    ON_CALL(*this->jniApi, callIntMethod(testing::_, methodId)).WillByDefault(Return(1989));

    ASSERT_TRUE(javaClass.load());
    ASSERT_TRUE(javaClass.loadMethod(methodIdentifier, methodSignature));
    ASSERT_EQ(1989, javaClass.callMethod(methodIdentifier).getIntegerValue());
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
            string expected = _exception.getName() + " thrown - no Java class reference available for loading class method!";
            string actual = _exception.what();

            ASSERT_STREQ(expected.c_str(), actual.c_str());
            throw;
          }
        },
        NullPointerException);
  }
}
