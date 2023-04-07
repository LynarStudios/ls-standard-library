/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-04-07
* Changed:         2023-04-07
*
* */

#include <ls-std/core/evaluator/NullPointerArgumentEvaluator.hpp>
#include <ls-std/core/jni/JniApi.hpp>

using ls::std::core::JniApi;
using ls::std::core::NullPointerArgumentEvaluator;
using std::string;

JniApi::JniApi(JNIEnv *_environment)
{
  NullPointerArgumentEvaluator{_environment}.evaluate();
  this->environment = _environment;
}

JniApi::~JniApi() noexcept = default;

jclass JniApi::findClass(const string &_classPath)
{
  return this->environment->FindClass(_classPath.c_str());
}

jmethodID JniApi::getMethodId(jclass _javaClass, const char *_methodIdentifier, const char *_methodSignature)
{
  return this->environment->GetMethodID(_javaClass, _methodIdentifier, _methodSignature);
}
