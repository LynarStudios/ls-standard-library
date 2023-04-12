/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-03-15
* Changed:         2023-03-31
*
* */

#ifndef LS_STD_SYSTEM_TIME_PARAMETER_HPP
#define LS_STD_SYSTEM_TIME_PARAMETER_HPP

#include "IClock.hpp"
#include <ls-std/os/dynamic-goal.hpp>
#include <memory>

namespace ls::std::time
{
  class LS_STD_DYNAMIC_GOAL SystemTimeParameter
  {
    public:

      SystemTimeParameter();
      ~SystemTimeParameter();

      [[nodiscard]] ::std::shared_ptr<ls::std::time::IClock> getClock();
      void setClock(const ::std::shared_ptr<ls::std::time::IClock> &_clock);

    private:

      ::std::shared_ptr<ls::std::time::IClock> clock{};
  };
}

#endif
