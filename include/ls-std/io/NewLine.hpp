/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-18
 * Changed:         2023-02-04
 *
 * */

#ifndef LS_STD_NEW_LINE_HPP
#define LS_STD_NEW_LINE_HPP

#include <string>

namespace ls::std::io
{
  class NewLine
  {
    public:

      NewLine();
      ~NewLine();

      static ::std::string get();
      static ::std::string getUnixNewLine();
      static ::std::string getWindowsNewLine();
  };
}

#endif
