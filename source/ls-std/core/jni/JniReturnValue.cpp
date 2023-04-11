/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-04-08
* Changed:         2023-04-11
*
* */

#include <ls-std/core/jni/JniReturnValue.hpp>

using ls::std::core::experimental::JniReturnValue;

JniReturnValue::JniReturnValue() = default;

JniReturnValue::~JniReturnValue() = default;

jboolean JniReturnValue::getBooleanValue() const
{
  return this->booleanValue;
}

jbyte JniReturnValue::getByteValue() const
{
  return this->byteValue;
}

jchar JniReturnValue::getCharValue() const
{
  return this->charValue;
}

jint JniReturnValue::getIntegerValue() const
{
  return this->integerValue;
}

jlong JniReturnValue::getLongValue() const
{
  return this->longValue;
}

jshort JniReturnValue::getShortValue() const
{
  return this->shortValue;
}

void JniReturnValue::setBooleanValue(jboolean _booleanValue)
{
  this->booleanValue = _booleanValue;
}

void JniReturnValue::setByteValue(jbyte _byteValue)
{
  this->byteValue = _byteValue;
}

void JniReturnValue::setCharValue(jchar _charValue)
{
  this->charValue = _charValue;
}

void JniReturnValue::setIntegerValue(jint _integerValue)
{
  this->integerValue = _integerValue;
}

void JniReturnValue::setLongValue(jlong _longValue)
{
  this->longValue = _longValue;
}

void JniReturnValue::setShortValue(jshort _shortValue)
{
  this->shortValue = _shortValue;
}
