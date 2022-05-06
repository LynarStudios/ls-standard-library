/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-18
 * Changed:         2022-05-05
 *
 * */

#ifndef LS_STD_NEW_LINE_HPP
#define LS_STD_NEW_LINE_HPP

#include <string>

namespace ls
{
  class NewLine
  {
    public:

      NewLine() = default;
      ~NewLine() = default;

      static ::std::string get()
      {
        ::std::string newLine{};

        #if defined(unix) || defined(__APPLE__)
        newLine = ls::NewLine::getUnixNewLine();
        #endif
        #ifdef _WIN32
        newLine = ls::NewLine::getWindowsNewLine();
        #endif

        return newLine;
      }

      static ::std::string getUnixNewLine()
      {
        return "\n";
      }

      static ::std::string getWindowsNewLine()
      {
        return "\r\n";
      }
  };
}

#endif
