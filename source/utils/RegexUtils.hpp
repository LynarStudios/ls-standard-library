/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-18
 * Changed:         2020-08-18
 *
 * */

#ifndef REGEX_UTILS_HPP
#define REGEX_UTILS_HPP

#include <string>
#include <regex>

namespace ls_std {
  class RegexUtils {
    public:

      RegexUtils() = default;
      ~RegexUtils() = default;

      static std::string escapeString(const std::string &_text)
      {
        static std::regex regexMetaEscape(R"(([\^\$\\\.\*\+\?\(\)\[\]\{\}\|]))");
        return std::regex_replace(_text, regexMetaEscape, R"(\$1)");
      }
  };
}

#endif