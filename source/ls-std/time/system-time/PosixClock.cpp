/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-03-15
* Changed:         2023-03-15
*
* */

#include <ctime>
#include <ls-std/time/system-time/PosixClock.hpp>

using ls::std::time::PosixClock;

PosixClock::PosixClock() = default;

PosixClock::~PosixClock() noexcept = default;

bool PosixClock::setTime(uint32_t _timeStamp)
{
  timespec timespec{_timeStamp, 0};
  return clock_settime(CLOCK_REALTIME, &timespec) == 0;
}
