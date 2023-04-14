/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-03-31
* Changed:         2023-03-31
*
* */

#ifndef LS_STD_I_CLOCK_HPP
#define LS_STD_I_CLOCK_HPP

#include <ls-std/os/dynamic-goal.hpp>
#include <ls-std/time/common/DateParameter.hpp>

namespace ls::std::time
{
  class LS_STD_DYNAMIC_GOAL IClock
  {
    public:

      IClock();
      virtual ~IClock();

      virtual bool setTime(const ls::std::time::DateParameter &_dateParameter) = 0;
  };
}

#endif
