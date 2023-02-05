/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-18
 * Changed:         2023-02-05
 *
 * */

#ifndef LS_STD_REGEX_UTILS_HPP
#define LS_STD_REGEX_UTILS_HPP

#include <ls-std/os/dynamic-goal.hpp>
#include <string>

namespace ls::std::core
{
  class LS_STD_DYNAMIC_GOAL RegexUtils
  {
    public:

      RegexUtils();
      ~RegexUtils();

      static ::std::string escapeString(const ::std::string &_text);
  };
}

#endif
