/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-04-07
* Changed:         2023-04-10
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
using ls::std::core::NullPointerArgumentEvaluator;
using ls::std::core::NullPointerEvaluator;
using ls::std::core::experimental::JniApi;
using ls::std::core::experimental::JniClass;
using ls::std::core::experimental::JniClassParameter;
using ls::std::core::experimental::JniMethod;
using ls::std::core::experimental::JniReturnValue;
using std::make_pair;
using std::make_shared;
using std::pair;
using std::shared_ptr;
using std::string;

JniClass::JniClass(const shared_ptr<JniClassParameter> &_parameter, const string &_path)
{
  NullPointerArgumentEvaluator{_parameter, "no provided reference to JNI class parameter!"}.evaluate();
  EmptyStringArgumentEvaluator{_path, "path to associated Java class is empty!"}.evaluate();
  NullPointerArgumentEvaluator{_parameter->getJavaEnvironment(), "Java environment is not being provided!"}.evaluate();
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
    this->_callBooleanMethod(_methodIdentifier, returnValue);
    this->_callByteMethod(_methodIdentifier, returnValue);
    this->_callIntMethod(_methodIdentifier, returnValue);
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
  NullPointerEvaluator{this->javaClass, "no Java class reference available for loading class method!"}.evaluate();
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

void JniClass::_callBooleanMethod(const ::std::string &_methodIdentifier, ls::std::core::experimental::JniReturnValue &_returnValue)
{
  JniMethod method = this->methods.at(_methodIdentifier);
  string searchString = ")Z";
  string methodSignature = method.getMethodSignature();
  bool hasBooleanReturnType = methodSignature.rfind(searchString) == (methodSignature.size() - searchString.size());

  if (hasBooleanReturnType)
  {
    _returnValue.setBooleanValue(this->parameter->getJniApi()->callBooleanMethod(this->parameter->getJavaObject(), method.getMethodId()));
  }
}

void JniClass::_callByteMethod(const ::std::string &_methodIdentifier, ls::std::core::experimental::JniReturnValue &_returnValue)
{
  JniMethod method = this->methods.at(_methodIdentifier);
  string searchString = ")B";
  string methodSignature = method.getMethodSignature();
  bool hasByteReturnType = methodSignature.rfind(searchString) == (methodSignature.size() - searchString.size());

  if (hasByteReturnType)
  {
    _returnValue.setByteValue(this->parameter->getJniApi()->callByteMethod(this->parameter->getJavaObject(), method.getMethodId()));
  }
}

void JniClass::_callIntMethod(const string &_methodIdentifier, JniReturnValue &_returnValue)
{
  JniMethod method = this->methods.at(_methodIdentifier);
  string searchString = ")I";
  string methodSignature = method.getMethodSignature();
  bool hasIntegerReturnType = methodSignature.rfind(searchString) == (methodSignature.size() - searchString.size());

  if (hasIntegerReturnType)
  {
    _returnValue.setIntegerValue(this->parameter->getJniApi()->callIntMethod(this->parameter->getJavaObject(), method.getMethodId()));
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
