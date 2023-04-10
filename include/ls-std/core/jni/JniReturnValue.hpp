/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-04-08
* Changed:         2023-04-10
*
* */

#ifndef LS_STD_JNI_RETURN_VALUE_HPP
#define LS_STD_JNI_RETURN_VALUE_HPP

#include <jni.h>
#include <ls-std/os/dynamic-goal.hpp>

namespace ls::std::core::experimental
{
  class LS_STD_DYNAMIC_GOAL JniReturnValue
  {
    public:

      JniReturnValue();
      ~JniReturnValue();

      [[nodiscard]] jboolean getBooleanValue() const;
      [[nodiscard]] jbyte getByteValue() const;
      [[nodiscard]] jint getIntegerValue() const;
      void setBooleanValue(jboolean _booleanValue);
      void setByteValue(jbyte _byteValue);
      void setIntegerValue(jint _integerValue);

    private:

      jboolean booleanValue{};
      jbyte byteValue{};
      jint integerValue{};
  };
}

#endif
