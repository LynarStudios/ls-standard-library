/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-04-08
* Changed:         2023-04-08
*
* */

#include <ls-std/core/jni/JniReturnValue.hpp>

using ls::std::core::JniReturnValue;

JniReturnValue::JniReturnValue() = default;

JniReturnValue::~JniReturnValue() = default;

jbyte JniReturnValue::getByteValue() const
{
  return this->byteValue;
}

void JniReturnValue::setByteValue(jbyte _byteValue)
{
  this->byteValue = _byteValue;
}
