/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-03-15
* Changed:         2023-03-15
*
* */

#ifndef LS_STD_I_POSIX_CLOCK_HPP
#define LS_STD_I_POSIX_CLOCK_HPP

#include <cstdint>
#include <ls-std/os/dynamic-goal.hpp>

namespace ls::std::time
{
  class LS_STD_DYNAMIC_GOAL IPosixClock
  {
    public:

      IPosixClock();
      virtual ~IPosixClock();

      virtual bool setTime(uint32_t _timeStamp) = 0;
  };
}

#endif
