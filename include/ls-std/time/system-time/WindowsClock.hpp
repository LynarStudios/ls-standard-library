/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-04-01
* Changed:         2023-04-01
*
* */

#ifndef LS_STD_WINDOW_CLOCK_HPP
#define LS_STD_WINDOW_CLOCK_HPP

#include "IClock.hpp"
#include <ls-std/os/dynamic-goal.hpp>

namespace ls::std::time
{
  class LS_STD_DYNAMIC_GOAL WindowsClock : public ls::std::time::IClock
  {
    public:

      WindowsClock();
      ~WindowsClock() noexcept override;

      [[nodiscard]] bool setTime(const ls::std::time::DateParameter &_dateParameter) override;
  };
}

#endif
