/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-03-16
* Changed:         2023-04-04
*
* */

#include <iostream>
#include <ls-std/core/evaluator/NullPointerEvaluator.hpp>
#include <ls-std/time/system-time/SystemTime.hpp>
#include <ls-std/time/system-time/jni/com_lynarstudios_ls_std_time_systemtime_SystemTimeJni.h>
#include <memory>
#include <string>
#include <utility>

using ls::std::core::NullPointerEvaluator;
using ls::std::time::DateParameter;
using ls::std::time::SystemTime;
using ls::std::time::type::Day;
using std::cout;
using std::endl;
using std::make_shared;
using std::pair;
using std::shared_ptr;
using std::string;

JNIEXPORT jboolean JNICALL Java_com_lynarstudios_ls_std_time_systemtime_SystemTimeJni_set(JNIEnv *_environment, jobject _object, jobject _dateParameter)
{
  string classPath = "com/lynarstudios/ls/std/time/systemtime/DateParameter";
  jclass dateParameterClass = _environment->FindClass(classPath.c_str());
  NullPointerEvaluator(dateParameterClass, R"lit(")lit" + classPath + R"lit(" path could not be found and is null!)lit").evaluate();
  cout << R"lit(found ")lit" << classPath << R"lit(" path...)lit" << endl;

  pair<string, string> getDayMethodSignature{"getDay", "()B"};
  jmethodID getDayMethodId = _environment->GetMethodID(dateParameterClass, getDayMethodSignature.first.c_str(), getDayMethodSignature.second.c_str());
  NullPointerEvaluator(getDayMethodId, R"lit(")lit" + getDayMethodSignature.second + "::" + getDayMethodSignature.first + R"lit(" could not be found and is null!)lit").evaluate();
  cout << R"lit(found ")lit" << getDayMethodSignature.second << "::" + getDayMethodSignature.first << R"lit(" method...)lit" << endl;

  DateParameter dateParameter{};
  Day day = _environment->CallByteMethod(_dateParameter, getDayMethodId);
  dateParameter.setDay(day);

  return SystemTime{}.set(dateParameter);
}
