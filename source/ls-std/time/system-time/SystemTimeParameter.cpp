/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-03-15
* Changed:         2023-03-15
*
* */

#include <ls-std/time/system-time/IPosixClock.hpp>
#include <ls-std/time/system-time/SystemTimeParameter.hpp>
#include <memory>

using ls::std::time::IPosixClock;
using ls::std::time::SystemTimeParameter;
using std::shared_ptr;

SystemTimeParameter::SystemTimeParameter() = default;

SystemTimeParameter::~SystemTimeParameter() = default;

shared_ptr<IPosixClock> SystemTimeParameter::getPosixClock()
{
  return this->posixClock;
}

void SystemTimeParameter::setPosixClock(const shared_ptr<IPosixClock> &_posixClock)
{
  this->posixClock = _posixClock;
}
