/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-03-15
* Changed:         2023-04-01
*
* */

#ifndef LS_STD_POSIX_CLOCK_HPP
#define LS_STD_POSIX_CLOCK_HPP

#include "IClock.hpp"
#include <cstdint>
#include <ls-std/time/type/DateParameterTypes.hpp>

namespace ls::std::time
{
  class PosixClock : public ls::std::time::IClock
  {
    public:

      PosixClock();
      ~PosixClock() noexcept override;

      [[nodiscard]] bool setTime(const ls::std::time::DateParameter &_dateParameter) override;
  };
}

#endif
