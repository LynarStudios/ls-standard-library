/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-03-15
* Changed:         2023-03-31
*
* */

#include <ctime>
#include <ls-std/time/common/DateParameterMapper.hpp>
#include <ls-std/time/system-time/PosixClock.hpp>

using ls::std::time::DateParameter;
using ls::std::time::DateParameterMapper;
using ls::std::time::PosixClock;
using ls::std::time::type::UnixTimestamp;

PosixClock::PosixClock() = default;

PosixClock::~PosixClock() noexcept = default;

bool PosixClock::setTime(const DateParameter &_dateParameter)
{
  UnixTimestamp timestamp = DateParameterMapper::toUnixTimestamp(_dateParameter);
  timespec timespec{timestamp, 0};
  return clock_settime(CLOCK_REALTIME, &timespec) == 0;
}
