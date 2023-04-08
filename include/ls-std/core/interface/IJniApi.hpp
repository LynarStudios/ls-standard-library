/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-04-07
* Changed:         2023-04-08
*
* */

#ifndef LS_STD_I_JNI_API_HPP
#define LS_STD_I_JNI_API_HPP

#include <jni.h>
#include <ls-std/os/dynamic-goal.hpp>
#include <string>

namespace ls::std::core::interface_type
{
  class LS_STD_DYNAMIC_GOAL IJniApi
  {
    public:

      IJniApi();
      virtual ~IJniApi();

      virtual jbyte callByteMethod(jobject _javaObject, jmethodID _methodId) = 0;
      virtual jint callIntMethod(jobject _javaObject, jmethodID _methodId) = 0;
      virtual jclass findClass(const ::std::string &_classPath) = 0;
      virtual jmethodID getMethodId(jclass _javaClass, const char *_methodIdentifier, const char *_methodSignature) = 0;
  };
}

#endif
