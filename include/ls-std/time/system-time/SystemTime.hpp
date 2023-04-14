/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-03-07
* Changed:         2023-03-31
*
* */

#ifndef LS_STD_SYSTEM_TIME_HPP
#define LS_STD_SYSTEM_TIME_HPP

#include "SystemTimeParameter.hpp"
#include <cstdint>
#include <ls-std/core/Class.hpp>
#include <ls-std/os/dynamic-goal.hpp>
#include <ls-std/time/common/DateParameter.hpp>
#include <ls-std/time/type/DateParameterTypes.hpp>
#include <memory>

namespace ls::std::time
{
  class LS_STD_DYNAMIC_GOAL SystemTime : public ls::std::core::Class
  {
    public:

      explicit SystemTime(const ::std::shared_ptr<ls::std::time::SystemTimeParameter> &_parameter);
      SystemTime();
      ~SystemTime() noexcept override;

      [[nodiscard]] bool set(const ls::std::time::DateParameter &_dateParameter);

    private:

      ::std::shared_ptr<ls::std::time::SystemTimeParameter> parameter{};

      void _generateParameter();
  };
}

#endif
