/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-03-07
* Changed:         2023-03-07
*
* */

#ifndef LS_STD_SYSTEM_TIME_HPP
#define LS_STD_SYSTEM_TIME_HPP

#include <ls-std/core/Class.hpp>
#include <ls-std/os/dynamic-goal.hpp>

namespace ls::std::time
{
  class LS_STD_DYNAMIC_GOAL SystemTime : public ls::std::core::Class
  {
    public:

      SystemTime();
      ~SystemTime() noexcept override;

      bool set(uint64_t _timeStamp);
  };
}

#endif
