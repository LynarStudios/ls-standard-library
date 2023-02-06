/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-18
 * Changed:         2023-02-06
 *
 * */

#ifndef LS_STD_NEW_LINE_HPP
#define LS_STD_NEW_LINE_HPP

#include <ls-std/os/dynamic-goal.hpp>
#include <string>

namespace ls::std::io
{
  class LS_STD_DYNAMIC_GOAL NewLine
  {
    public:

      NewLine();
      ~NewLine();

      [[nodiscard]] static ::std::string get();
      [[nodiscard]] static ::std::string getUnixNewLine();
      [[nodiscard]] static ::std::string getWindowsNewLine();
  };
}

#endif
