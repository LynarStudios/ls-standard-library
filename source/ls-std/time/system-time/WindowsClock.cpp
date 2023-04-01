/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-04-01
* Changed:         2023-04-01
*
* */

#include <ls-std/time/system-time/WindowsClock.hpp>

using ls::std::time::DateParameter;
using ls::std::time::WindowsClock;

WindowsClock::WindowsClock() = default;

WindowsClock::~WindowsClock() noexcept = default;

bool WindowsClock::setTime(const DateParameter &_dateParameter)
{
  return true; // TODO: implement
}
