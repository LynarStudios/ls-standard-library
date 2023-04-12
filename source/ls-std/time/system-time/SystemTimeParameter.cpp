/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-03-15
* Changed:         2023-03-31
*
* */

#include <ls-std/time/system-time/SystemTimeParameter.hpp>
#include <memory>

using ls::std::time::IClock;
using ls::std::time::SystemTimeParameter;
using std::shared_ptr;

SystemTimeParameter::SystemTimeParameter() = default;

SystemTimeParameter::~SystemTimeParameter() = default;

shared_ptr<IClock> SystemTimeParameter::getClock()
{
  return this->clock;
}

void SystemTimeParameter::setClock(const shared_ptr<IClock> &_clock)
{
  this->clock = _clock;
}
