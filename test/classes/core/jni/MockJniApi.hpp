/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-04-07
* Changed:         2023-04-11
*
* */

#ifndef LS_STD_MOCK_JNI_API_HPP
#define LS_STD_MOCK_JNI_API_HPP

#include <gmock/gmock.h>
#include <ls-std/core/interface/IJniApi.hpp>

namespace test::core::jni
{
  class MockJniApi : public ls::std::core::experimental::interface_type::IJniApi
  {
    public:

      MockJniApi();
      ~MockJniApi() noexcept override;

      MOCK_METHOD(jboolean, callBooleanMethod, (jobject _javaObject, jmethodID _methodId), (override));
      MOCK_METHOD(jbyte, callByteMethod, (jobject _javaObject, jmethodID _methodId), (override));
      MOCK_METHOD(jchar, callCharMethod, (jobject _javaObject, jmethodID _methodId), (override));
      MOCK_METHOD(jint, callIntMethod, (jobject _javaObject, jmethodID _methodId), (override));
      MOCK_METHOD(jshort, callShortMethod, (jobject _javaObject, jmethodID _methodId), (override));
      MOCK_METHOD(jclass, findClass, (const ::std::string &_classPath), (override));
      MOCK_METHOD(jmethodID, getMethodId, (jclass _javaClass, const char *_methodIdentifier, const char *_methodSignature), (override));
  };
}

#endif
