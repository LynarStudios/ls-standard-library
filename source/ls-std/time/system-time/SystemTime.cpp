/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-03-15
* Changed:         2023-04-01
*
* */

#include <ls-std/core/Class.hpp>
#include <ls-std/core/evaluator/NullPointerArgumentEvaluator.hpp>
#if defined(unix) || defined(__APPLE__)
  #include <ls-std/time/system-time/PosixClock.hpp>
#endif
#include <ls-std/time/system-time/SystemTime.hpp>
#include <ls-std/time/system-time/SystemTimeParameter.hpp>
#ifdef _WIN32
  #include <ls-std/time/system-time/WindowsClock.hpp>
#endif
#include <memory>

using ls::std::core::Class;
using ls::std::core::NullPointerArgumentEvaluator;
using ls::std::time::DateParameter;
#if defined(unix) || defined(__APPLE__)
using ls::std::time::PosixClock;
#endif
using ls::std::time::SystemTime;
using ls::std::time::SystemTimeParameter;
#ifdef _WIN32
using ls::std::time::WindowsClock;
#endif
using ls::std::time::type::UnixTimestamp;
using std::make_shared;
using std::shared_ptr;

SystemTime::SystemTime(const shared_ptr<SystemTimeParameter> &_parameter) : SystemTime()
{
  NullPointerArgumentEvaluator{_parameter}.evaluate();
  this->parameter = _parameter;
}

SystemTime::SystemTime() : Class("SystemTime")
{
  this->_generateParameter();
}

SystemTime::~SystemTime() noexcept = default;

bool SystemTime::set(const DateParameter &_dateParameter)
{
  return this->parameter->getClock()->setTime(_dateParameter);
}

void SystemTime::_generateParameter()
{
  this->parameter = make_shared<SystemTimeParameter>();

#if defined(unix) || defined(__APPLE__)
  this->parameter->setClock(make_shared<PosixClock>());
#endif
#ifdef _WIN32
  this->parameter->setClock(make_shared<WindowsClock>());
#endif
}
