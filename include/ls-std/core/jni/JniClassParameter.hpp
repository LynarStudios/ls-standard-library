/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-04-07
* Changed:         2023-04-07
*
* */

#ifndef LS_STD_JNI_CLASS_PARAMETER_HPP
#define LS_STD_JNI_CLASS_PARAMETER_HPP

#include <jni.h>
#include <ls-std/core/interface/IJniApi.hpp>
#include <ls-std/os/dynamic-goal.hpp>
#include <memory>
#include <string>

namespace ls::std::core
{
  class LS_STD_DYNAMIC_GOAL JniClassParameter
  {
    public:

      JniClassParameter();
      ~JniClassParameter();

      [[nodiscard]] JNIEnv *getJavaEnvironment();
      [[nodiscard]] ::std::shared_ptr<ls::std::core::interface_type::IJniApi> getJniApi();
      void setJavaEnvironment(JNIEnv *_environment);
      void setJniApi(const ::std::shared_ptr<ls::std::core::interface_type::IJniApi> &_jniApi);

    private:

      JNIEnv *environment{};
      ::std::shared_ptr<ls::std::core::interface_type::IJniApi> jniApi{};
  };
}

#endif
