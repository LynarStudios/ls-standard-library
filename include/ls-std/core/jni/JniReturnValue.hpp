/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-04-08
* Changed:         2023-04-11
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
      [[nodiscard]] jchar getCharValue() const;
      [[nodiscard]] jdouble getDoubleValue() const;
      [[nodiscard]] jfloat getFloatValue() const;
      [[nodiscard]] jint getIntegerValue() const;
      [[nodiscard]] jlong getLongValue() const;
      [[nodiscard]] jshort getShortValue() const;
      void setBooleanValue(jboolean _booleanValue);
      void setByteValue(jbyte _byteValue);
      void setCharValue(jchar _charValue);
      void setDoubleValue(jdouble _doubleValue);
      void setFloatValue(jfloat _floatValue);
      void setIntegerValue(jint _integerValue);
      void setLongValue(jlong _longValue);
      void setShortValue(jshort _shortValue);

    private:

      jboolean booleanValue{};
      jbyte byteValue{};
      jchar charValue{};
      jdouble doubleValue{};
      jfloat floatValue{};
      jint integerValue{};
      jlong longValue{};
      jshort shortValue{};
  };
}

#endif
