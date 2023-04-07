/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-04-07
* Changed:         2023-04-07
*
* */

#include <ls-std/core/jni/JniClassParameter.hpp>

using ls::std::core::JniClassParameter;
using ls::std::core::interface_type::IJniApi;
using std::shared_ptr;
using std::string;

JniClassParameter::JniClassParameter() = default;

JniClassParameter::~JniClassParameter() = default;

JNIEnv *JniClassParameter::getJavaEnvironment()
{
  return this->environment;
}

shared_ptr<IJniApi> JniClassParameter::getJniApi()
{
  return this->jniApi;
}

void JniClassParameter::setJavaEnvironment(JNIEnv *_environment)
{
  this->environment = _environment;
}

void JniClassParameter::setJniApi(const shared_ptr<IJniApi> &_jniApi)
{
  this->jniApi = _jniApi;
}
