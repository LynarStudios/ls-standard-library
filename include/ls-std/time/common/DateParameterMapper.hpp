/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-03-31
* Changed:         2023-03-31
*
* */

#ifndef LS_STD_DATE_PARAMETER_MAPPER_HPP
#define LS_STD_DATE_PARAMETER_MAPPER_HPP

#include "DateParameter.hpp"
#include <ls-std/os/dynamic-goal.hpp>
#include <ls-std/time/type/DateParameterTypes.hpp>

namespace ls::std::time
{
  class LS_STD_DYNAMIC_GOAL DateParameterMapper
  {
    public:

      DateParameterMapper();
      ~DateParameterMapper();

      [[nodiscard]] static ls::std::time::type::UnixTimestamp toUnixTimestamp(const ls::std::time::DateParameter &_dateParameter);
  };
}

#endif
