/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-04-08
* Changed:         2023-04-10
*
* */

#include <ls-std/core/jni/JniReturnValue.hpp>

using ls::std::core::experimental::JniReturnValue;

JniReturnValue::JniReturnValue() = default;

JniReturnValue::~JniReturnValue() = default;

jbyte JniReturnValue::getByteValue() const
{
  return this->byteValue;
}

jint JniReturnValue::getIntegerValue() const
{
  return this->integerValue;
}

void JniReturnValue::setByteValue(jbyte _byteValue)
{
  this->byteValue = _byteValue;
}

void JniReturnValue::setIntegerValue(jint _integerValue)
{
  this->integerValue = _integerValue;
}
