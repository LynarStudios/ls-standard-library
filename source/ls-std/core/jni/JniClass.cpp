/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-04-07
* Changed:         2023-04-08
*
* */

#include <ls-std/core/ConditionalFunctionExecutor.hpp>
#include <ls-std/core/evaluator/EmptyStringArgumentEvaluator.hpp>
#include <ls-std/core/evaluator/NullPointerArgumentEvaluator.hpp>
#include <ls-std/core/evaluator/NullPointerEvaluator.hpp>
#include <ls-std/core/jni/JniApi.hpp>
#include <ls-std/core/jni/JniClass.hpp>
#include <memory>

using ls::std::core::ConditionalFunctionExecutor;
using ls::std::core::EmptyStringArgumentEvaluator;
using ls::std::core::JniApi;
using ls::std::core::JniClass;
using ls::std::core::JniClassParameter;
using ls::std::core::JniMethod;
using ls::std::core::JniReturnValue;
using ls::std::core::NullPointerArgumentEvaluator;
using ls::std::core::NullPointerEvaluator;
using std::make_pair;
using std::make_shared;
using std::pair;
using std::shared_ptr;
using std::string;

JniClass::JniClass(const shared_ptr<JniClassParameter> &_parameter, const string &_path)
{
  NullPointerArgumentEvaluator{_parameter}.evaluate();
  EmptyStringArgumentEvaluator{_path}.evaluate();
  NullPointerArgumentEvaluator{_parameter->getJavaEnvironment()}.evaluate();
  this->parameter = _parameter;
  this->path = _path;
  ConditionalFunctionExecutor{_parameter->getJniApi() == nullptr}.execute([this]() { _createJniApi(); });
}

JniClass::~JniClass() = default;

JniReturnValue JniClass::callMethod(const string &_methodIdentifier)
{
  JniReturnValue returnValue{};

  if (this->_hasMethod(_methodIdentifier))
  {
    this->_callByteMethod(_methodIdentifier, returnValue);
  }

  return returnValue;
}

bool JniClass::hasMethod(const string &_methodIdentifier)
{
  return this->_hasMethod(_methodIdentifier);
}

bool JniClass::load()
{
  this->javaClass = this->parameter->getJniApi()->findClass(this->path);
  return this->javaClass != nullptr;
}

bool JniClass::loadMethod(const string &_methodIdentifier, const string &_methodSignature)
{
  NullPointerEvaluator{this->javaClass}.evaluate();
  jmethodID methodId = this->parameter->getJniApi()->getMethodId(this->javaClass, _methodIdentifier.c_str(), _methodSignature.c_str());
  bool succeeded = methodId != nullptr && !this->_hasMethod(_methodIdentifier);

  if (succeeded)
  {
    JniMethod method{_methodIdentifier, _methodSignature};
    method.setMethodId(methodId);
    succeeded = this->methods.insert(make_pair<string, JniMethod>(string{_methodIdentifier}, JniMethod{method})).second;
  }

  return succeeded;
}

void JniClass::_callByteMethod(const string &_methodIdentifier, JniReturnValue &_returnValue)
{
  JniMethod method = this->methods.at(_methodIdentifier);
  string searchString = ")B";
  string methodSignature = method.getMethodSignature();
  bool hasBooleanReturnType = methodSignature.rfind(searchString) == (methodSignature.size() - searchString.size());

  if (hasBooleanReturnType)
  {
    _returnValue.setByteValue(this->parameter->getJniApi()->callByteMethod(this->parameter->getJavaObject(), method.getMethodId()));
  }
}

void JniClass::_createJniApi()
{
  this->parameter->setJniApi(make_shared<JniApi>(this->parameter->getJavaEnvironment()));
}

bool JniClass::_hasMethod(const string &_methodIdentifier)
{
  return this->methods.find(_methodIdentifier) != this->methods.end();
}
