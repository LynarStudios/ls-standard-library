/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-04-08
* Changed:         2023-04-08
*
* */

#include <ls-std/core/evaluator/EmptyStringArgumentEvaluator.hpp>
#include <ls-std/core/jni/JniMethod.hpp>

using ls::std::core::EmptyStringArgumentEvaluator;
using ls::std::core::JniMethod;
using std::string;

JniMethod::JniMethod(const string &_methodIdentifier, const string &_methodSignature)
{
  EmptyStringArgumentEvaluator{_methodIdentifier}.evaluate();
  EmptyStringArgumentEvaluator{_methodSignature}.evaluate();
  this->methodIdentifier = _methodIdentifier;
  this->methodSignature = _methodSignature;
}

JniMethod::~JniMethod() = default;

jmethodID JniMethod::getMethodId()
{
  return this->methodId;
}

string JniMethod::getMethodIdentifier()
{
  return this->methodIdentifier;
}

string JniMethod::getMethodSignature()
{
  return this->methodSignature;
}

void JniMethod::setMethodId(jmethodID _methodId)
{
  this->methodId = _methodId;
}

void JniMethod::setMethodIdentifier(const string &_methodIdentifier)
{
  this->methodIdentifier = _methodIdentifier;
}

void JniMethod::setMethodSignature(const string &_methodSignature)
{
  this->methodSignature = _methodSignature;
}
