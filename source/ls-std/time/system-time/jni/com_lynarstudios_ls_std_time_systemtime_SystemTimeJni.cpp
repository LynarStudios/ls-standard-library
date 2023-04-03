/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-03-16
* Changed:         2023-04-03
*
* */

#include <ls-std/time/system-time/SystemTime.hpp>
#include <ls-std/time/system-time/jni/com_lynarstudios_ls_std_time_systemtime_SystemTimeJni.h>

using ls::std::time::DateParameter;
using ls::std::time::SystemTime;
using ls::std::time::type::Day;

JNIEXPORT jboolean JNICALL Java_com_lynarstudios_ls_std_time_systemtime_SystemTimeJni_set(JNIEnv *_environment, jobject _object, jobject _dateParameter)
{
  jclass dateParameterClass = _environment->GetObjectClass(_dateParameter);
  jmethodID getDayMethodId = _environment->GetMethodID(dateParameterClass, "getDay", "byte");
  DateParameter dateParameter{};

  return SystemTime{}.set(dateParameter);
}
