/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-04-07
* Changed:         2023-04-10
*
* */

#include <ls-std/core/evaluator/NullPointerArgumentEvaluator.hpp>
#include <ls-std/core/jni/JniApi.hpp>

using ls::std::core::NullPointerArgumentEvaluator;
using ls::std::core::experimental::JniApi;
using std::string;

JniApi::JniApi(JNIEnv *_environment)
{
  NullPointerArgumentEvaluator{_environment}.evaluate();
  this->environment = _environment;
}

JniApi::~JniApi() noexcept = default;

jbyte JniApi::callByteMethod(jobject _javaObject, jmethodID _methodId)
{
  return this->environment->CallByteMethod(_javaObject, _methodId);
}

jint JniApi::callIntMethod(jobject _javaObject, jmethodID _methodId)
{
  return this->environment->CallIntMethod(_javaObject, _methodId);
}

jclass JniApi::findClass(const string &_classPath)
{
  return this->environment->FindClass(_classPath.c_str());
}

jmethodID JniApi::getMethodId(jclass _javaClass, const char *_methodIdentifier, const char *_methodSignature)
{
  return this->environment->GetMethodID(_javaClass, _methodIdentifier, _methodSignature);
}
