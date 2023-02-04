/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-07
 * Changed:         2023-02-03
 *
 * */

#ifndef LS_STD_I_BOXING_HPP
#define LS_STD_I_BOXING_HPP

#include <string>

namespace ls::std::core::interface_type
{
  class IBoxing
  {
    public:

      IBoxing() = default;
      ~IBoxing() = default;

      virtual void parse(::std::string _parseText) = 0;
      virtual ::std::string toString() = 0;
  };
}

#endif
