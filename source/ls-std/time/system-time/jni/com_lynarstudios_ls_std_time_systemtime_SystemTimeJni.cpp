/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-03-16
* Changed:         2023-04-04
*
* */

#include <ls-std/core/evaluator/NullPointerEvaluator.hpp>
#include <ls-std/time/system-time/SystemTime.hpp>
#include <ls-std/time/system-time/jni/com_lynarstudios_ls_std_time_systemtime_SystemTimeJni.h>
#include <memory>

using ls::std::core::NullPointerEvaluator;
using ls::std::time::DateParameter;
using ls::std::time::SystemTime;
using ls::std::time::type::Day;
using std::make_shared;
using std::shared_ptr;

JNIEXPORT jboolean JNICALL Java_com_lynarstudios_ls_std_time_systemtime_SystemTimeJni_set(JNIEnv *_environment, jobject _object, jobject _dateParameter)
{
  jclass dateParameterClass = _environment->FindClass("com.lynarstudios.ls.std.time.systemtime.DateParameter");
  NullPointerEvaluator(dateParameterClass, R"lit("DateParameter" class could not be found and is null!)lit").evaluate();

  jmethodID getDayMethodId = _environment->GetMethodID(dateParameterClass, "getDay", "()B");
  NullPointerEvaluator(getDayMethodId, R"lit("getDay" method could not be found and is null!)lit").evaluate();

  DateParameter dateParameter{};
  Day day = _environment->CallByteMethod((jobject) _environment, getDayMethodId, getDayMethodId);
  dateParameter.setDay(day);

  return SystemTime{}.set(dateParameter);
}
