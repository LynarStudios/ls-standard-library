/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-04-07
* Changed:         2023-04-10
*
* */

#ifndef LS_STD_JNI_CLASS_PARAMETER_HPP
#define LS_STD_JNI_CLASS_PARAMETER_HPP

#include <jni.h>
#include <ls-std/core/interface/IJniApi.hpp>
#include <ls-std/os/dynamic-goal.hpp>
#include <memory>
#include <string>

namespace ls::std::core::experimental
{
  class LS_STD_DYNAMIC_GOAL JniClassParameter
  {
    public:

      JniClassParameter();
      ~JniClassParameter();

      [[nodiscard]] JNIEnv *getJavaEnvironment();
      [[nodiscard]] jobject getJavaObject();
      [[nodiscard]] ::std::shared_ptr<ls::std::core::experimental::interface_type::IJniApi> getJniApi();
      void setJavaEnvironment(JNIEnv *_environment);
      void setJavaObject(jobject _javaObject);
      void setJniApi(const ::std::shared_ptr<ls::std::core::experimental::interface_type::IJniApi> &_jniApi);

    private:

      JNIEnv *environment{};
      jobject javaObject{};
      ::std::shared_ptr<ls::std::core::experimental::interface_type::IJniApi> jniApi{};
  };
}

#endif
