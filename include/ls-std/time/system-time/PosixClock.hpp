/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-03-15
* Changed:         2023-03-15
*
* */

#ifndef LS_STD_POSIX_CLOCK_HPP
#define LS_STD_POSIX_CLOCK_HPP

#include "IPosixClock.hpp"
#include <cstdint>
#include <ls-std/os/dynamic-goal.hpp>

namespace ls::std::time
{
  class LS_STD_DYNAMIC_GOAL PosixClock : public ls::std::time::IPosixClock
  {
    public:

      PosixClock();
      ~PosixClock() noexcept override;

      [[nodiscard]] bool setTime(uint32_t _timeStamp) override;
  };
}

#endif
