/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2023-02-04
 * Changed:         2023-02-04
 *
 * */

#include <ls-std/core/utils/RegexUtils.hpp>
#include <regex>

ls::std::core::RegexUtils::RegexUtils() = default;

ls::std::core::RegexUtils::~RegexUtils() = default;

::std::string ls::std::core::RegexUtils::escapeString(const ::std::string &_text)
{
  static ::std::regex regexMetaEscape(R"(([\^\$\\\.\*\+\?\(\)\[\]\{\}\|]))");
  return ::std::regex_replace(_text, regexMetaEscape, R"(\$1)");
}
