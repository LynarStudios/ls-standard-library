/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-04-08
* Changed:         2023-04-08
*
* */

#ifndef LS_STD_JNI_RETURN_VALUE_HPP
#define LS_STD_JNI_RETURN_VALUE_HPP

#include <jni.h>
#include <ls-std/os/dynamic-goal.hpp>

namespace ls::std::core
{
  class LS_STD_DYNAMIC_GOAL JniReturnValue
  {
    public:

      JniReturnValue();
      ~JniReturnValue();

      [[nodiscard]] jbyte getByteValue() const;
      [[nodiscard]] jint getIntegerValue() const;
      void setByteValue(jbyte _byteValue);
      void setIntegerValue(jint _integerValue);

    private:

      jbyte byteValue{};
      jint integerValue{};
  };
}

#endif
