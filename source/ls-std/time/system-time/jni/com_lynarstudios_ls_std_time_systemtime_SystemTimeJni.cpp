/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-03-16
* Changed:         2023-04-09
*
* */

#include <iostream>
#include <ls-std/core/evaluator/NullPointerEvaluator.hpp>
#include <ls-std/core/jni/JniClass.hpp>
#include <ls-std/core/jni/JniClassParameter.hpp>
#include <ls-std/time/common/jni/JniDateParameterMapper.hpp>
#include <ls-std/time/system-time/SystemTime.hpp>
#include <ls-std/time/system-time/jni/com_lynarstudios_ls_std_time_systemtime_SystemTimeJni.h>
#include <memory>

using ls::std::core::JniClass;
using ls::std::core::JniClassParameter;
using ls::std::core::NullPointerEvaluator;
using ls::std::time::DateParameter;
using ls::std::time::SystemTime;
using ls::std::time::experimental::JniDateParameterMapper;
using ls::std::time::type::Day;
using ls::std::time::type::Hour;
using ls::std::time::type::Minute;
using ls::std::time::type::Month;
using ls::std::time::type::Second;
using ls::std::time::type::Year;
using std::cout;
using std::endl;
using std::make_shared;
using std::pair;
using std::shared_ptr;
using std::string;

JNIEXPORT jboolean JNICALL Java_com_lynarstudios_ls_std_time_systemtime_SystemTimeJni_set(JNIEnv *_environment, jobject _object, jobject _dateParameter)
{
  shared_ptr<JniClassParameter> parameter = make_shared<JniClassParameter>();
  parameter->setJavaEnvironment(_environment);
  parameter->setJavaObject(_dateParameter);

  JniClass javaClass{parameter, "com/lynarstudios/ls/std/time/systemtime/DateParameter"};
  javaClass.load();

  javaClass.loadMethod("getYear", "()I");
  javaClass.loadMethod("getMonth", "()B");
  javaClass.loadMethod("getDay", "()B");
  javaClass.loadMethod("getHour", "()B");
  javaClass.loadMethod("getMinute", "()B");
  javaClass.loadMethod("getSecond", "()B");

  // map

  DateParameter dateParameter = JniDateParameterMapper::toDateParameter(javaClass);
  bool success = SystemTime{}.set(dateParameter);

  if (success)
  {
    cout << R"lit(system time successfully set to ")lit" << dateParameter.getYear() << "-" << (int) dateParameter.getMonth() << "-" << (int) dateParameter.getDay() << " " << (int) dateParameter.getHour() << ":" << (int) dateParameter.getMinute() << ":" << (int) dateParameter.getSecond() << R"lit(" ...)lit" << endl;
  }
  else
  {
    cout << "could not set system time ..." << endl;
  }

  return success;
}
