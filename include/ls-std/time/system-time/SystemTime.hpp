/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-03-07
* Changed:         2023-03-15
*
* */

#ifndef LS_STD_SYSTEM_TIME_HPP
#define LS_STD_SYSTEM_TIME_HPP

#include "SystemTimeParameter.hpp"
#include <cstdint>
#include <ls-std/core/Class.hpp>
#include <ls-std/os/dynamic-goal.hpp>
#include <memory>

namespace ls::std::time
{
  class LS_STD_DYNAMIC_GOAL SystemTime : public ls::std::core::Class
  {
    public:

      explicit SystemTime(const ::std::shared_ptr<ls::std::time::SystemTimeParameter> &_parameter);
      SystemTime();
      ~SystemTime() noexcept override;

      [[nodiscard]] bool set(uint32_t _timeStamp);

    private:

      ::std::shared_ptr<ls::std::time::SystemTimeParameter> parameter{};

      void _generateParameter();
  };
}

#endif
