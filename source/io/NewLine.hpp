/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-18
 * Changed:         2020-08-18
 *
 * */

#ifndef NEW_LINE_HPP
#define NEW_LINE_HPP

#include <string>

namespace ls_std {
  class NewLine {
    public:

      NewLine() = default;
      ~NewLine() = default;

      static std::string get() {
        std::string newLine {};

        #if defined(unix) || defined(__APPLE__)
          newLine = ls_std::NewLine::getUnixNewLine();
        #endif
        #ifdef _WIN32
          newLine = ls_std::NewLine::getWindowsNewLine();
        #endif

        return newLine;
      }

      static std::string getUnixNewLine() {
        return "\n";
      }

      static std::string getWindowsNewLine() {
        return "\r\n";
      }
  };
}

#endif
