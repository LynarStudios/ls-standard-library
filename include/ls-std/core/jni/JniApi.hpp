/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-04-07
* Changed:         2023-04-10
*
* */

#ifndef LS_STD_JNI_API_HPP
#define LS_STD_JNI_API_HPP

#include <ls-std/core/interface/IJniApi.hpp>
#include <ls-std/os/dynamic-goal.hpp>

namespace ls::std::core::experimental
{
  class LS_STD_DYNAMIC_GOAL JniApi : public ls::std::core::experimental::interface_type::IJniApi
  {
    public:

      explicit JniApi(JNIEnv *_environment);
      ~JniApi() noexcept override;

      jboolean callBooleanMethod(jobject _javaObject, jmethodID _methodId) override;
      jbyte callByteMethod(jobject _javaObject, jmethodID _methodId) override;
      jint callIntMethod(jobject _javaObject, jmethodID _methodId) override;
      jclass findClass(const ::std::string &_classPath) override;
      jmethodID getMethodId(jclass _javaClass, const char *_methodIdentifier, const char *_methodSignature) override;

    private:

      JNIEnv *environment{};
  };
}

#endif
