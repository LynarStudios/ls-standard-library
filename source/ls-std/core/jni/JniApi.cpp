/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-04-07
* Changed:         2023-04-11
*
* */

#include <ls-std/core/evaluator/NullPointerArgumentEvaluator.hpp>
#include <ls-std/core/jni/JniApi.hpp>

using ls::std::core::NullPointerArgumentEvaluator;
using ls::std::core::experimental::JniApi;
using std::string;

JniApi::JniApi(JNIEnv *_environment)
{
  NullPointerArgumentEvaluator{_environment, "Java environment is not being provided!"}.evaluate();
  this->environment = _environment;
}

JniApi::~JniApi() noexcept = default;

jboolean JniApi::callBooleanMethod(jobject _javaObject, jmethodID _methodId)
{
  return this->environment->CallBooleanMethod(_javaObject, _methodId);
}

jbyte JniApi::callByteMethod(jobject _javaObject, jmethodID _methodId)
{
  return this->environment->CallByteMethod(_javaObject, _methodId);
}

jchar JniApi::callCharMethod(jobject _javaObject, jmethodID _methodId)
{
  return this->environment->CallCharMethod(_javaObject, _methodId);
}

jdouble JniApi::callDoubleMethod(jobject _javaObject, jmethodID _methodId)
{
  return this->environment->CallDoubleMethod(_javaObject, _methodId);
}

jfloat JniApi::callFloatMethod(jobject _javaObject, jmethodID _methodId)
{
  return this->environment->CallFloatMethod(_javaObject, _methodId);
}

jint JniApi::callIntMethod(jobject _javaObject, jmethodID _methodId)
{
  return this->environment->CallIntMethod(_javaObject, _methodId);
}

jlong JniApi::callLongMethod(jobject _javaObject, jmethodID _methodId)
{
  return this->environment->CallLongMethod(_javaObject, _methodId);
}

jshort JniApi::callShortMethod(jobject _javaObject, jmethodID _methodId)
{
  return this->environment->CallShortMethod(_javaObject, _methodId);
}

jclass JniApi::findClass(const string &_classPath)
{
  return this->environment->FindClass(_classPath.c_str());
}

jmethodID JniApi::getMethodId(jclass _javaClass, const char *_methodIdentifier, const char *_methodSignature)
{
  return this->environment->GetMethodID(_javaClass, _methodIdentifier, _methodSignature);
}
