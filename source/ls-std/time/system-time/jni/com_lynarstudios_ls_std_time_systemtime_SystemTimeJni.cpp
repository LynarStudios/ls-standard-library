/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-03-16
* Changed:         2023-04-08
*
* */

#include <iostream>
#include <ls-std/core/evaluator/NullPointerEvaluator.hpp>
#include <ls-std/core/jni/JniClass.hpp>
#include <ls-std/core/jni/JniClassParameter.hpp>
#include <ls-std/time/system-time/SystemTime.hpp>
#include <ls-std/time/system-time/jni/com_lynarstudios_ls_std_time_systemtime_SystemTimeJni.h>
#include <memory>

using ls::std::core::JniClass;
using ls::std::core::JniClassParameter;
using ls::std::core::NullPointerEvaluator;
using ls::std::time::DateParameter;
using ls::std::time::SystemTime;
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
  cout << (javaClass.load() ? "class loaded..." : "could not load class...") << endl;

  cout << (javaClass.loadMethod("getYear", "()I") ? "method loaded..." : "could not load method...") << endl;
  cout << (javaClass.loadMethod("getMonth", "()B") ? "method loaded..." : "could not load method...") << endl;
  cout << (javaClass.loadMethod("getDay", "()B") ? "method loaded..." : "could not load method...") << endl;
  cout << (javaClass.loadMethod("getHour", "()B") ? "method loaded..." : "could not load method...") << endl;
  cout << (javaClass.loadMethod("getMinute", "()B") ? "method loaded..." : "could not load method...") << endl;
  cout << (javaClass.loadMethod("getSecond", "()B") ? "method loaded..." : "could not load method...") << endl;

  Year year = javaClass.callMethod("getYear").getIntegerValue();
  Month month = javaClass.callMethod("getMonth").getByteValue();
  Day day = javaClass.callMethod("getDay").getByteValue();
  Hour hour = javaClass.callMethod("getHour").getByteValue();
  Minute minute = javaClass.callMethod("getMinute").getByteValue();
  Second second = javaClass.callMethod("getSecond").getByteValue();

  // map

  DateParameter dateParameter{};

  dateParameter.setYear(year);
  dateParameter.setMonth(month);
  dateParameter.setDay(day);
  dateParameter.setHour(hour);
  dateParameter.setMinute(minute);
  dateParameter.setSecond(second);

  return SystemTime{}.set(dateParameter);
}
