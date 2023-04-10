/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-04-08
* Changed:         2023-04-10
*
* */

#ifndef LS_STD_JNI_METHOD_HPP
#define LS_STD_JNI_METHOD_HPP

#include <jni.h>
#include <ls-std/os/dynamic-goal.hpp>
#include <string>

namespace ls::std::core::experimental
{
  class LS_STD_DYNAMIC_GOAL JniMethod
  {
    public:

      explicit JniMethod(const ::std::string &_methodIdentifier, const ::std::string &_methodSignature);
      ~JniMethod();

      [[nodiscard]] jmethodID getMethodId();
      [[nodiscard]] ::std::string getMethodIdentifier();
      [[nodiscard]] ::std::string getMethodSignature();
      void setMethodId(jmethodID _methodId);
      void setMethodIdentifier(const ::std::string &_methodIdentifier);
      void setMethodSignature(const ::std::string &_methodSignature);

    private:

      jmethodID methodId{};
      ::std::string methodIdentifier{};
      ::std::string methodSignature{};
  };
}

#endif
