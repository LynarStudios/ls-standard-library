/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-04-07
* Changed:         2023-04-07
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

      virtual jclass findClass(const ::std::string &_classPath) = 0;
  };
}

#endif
