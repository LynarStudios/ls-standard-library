/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-04-09
* Changed:         2023-04-10
*
* */

#include <ls-std/core/jni/JniClass.hpp>
#include <ls-std/time/common/DateParameter.hpp>
#include <ls-std/time/common/jni/JniDateParameterMapper.hpp>

using ls::std::core::experimental::JniClass;
using ls::std::time::DateParameter;
using ls::std::time::experimental::JniDateParameterMapper;

JniDateParameterMapper::JniDateParameterMapper() = default;

JniDateParameterMapper::~JniDateParameterMapper() = default;

DateParameter JniDateParameterMapper::toDateParameter(const JniClass &_javaClass)
{
  JniClass javaClass = _javaClass;
  DateParameter dateParameter{};

  dateParameter.setYear(javaClass.callMethod("getYear").getIntegerValue());
  dateParameter.setMonth(javaClass.callMethod("getMonth").getByteValue());
  dateParameter.setDay(javaClass.callMethod("getDay").getByteValue());
  dateParameter.setHour(javaClass.callMethod("getHour").getByteValue());
  dateParameter.setMinute(javaClass.callMethod("getMinute").getByteValue());
  dateParameter.setSecond(javaClass.callMethod("getSecond").getByteValue());

  return dateParameter;
}
