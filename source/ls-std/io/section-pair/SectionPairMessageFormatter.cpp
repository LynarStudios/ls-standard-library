/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-22
* Changed:         2023-02-22
*
* */

#include <ls-std/io/section-pair/SectionPairMessageFormatter.hpp>
#include <regex>

ls::std::io::SectionPairMessageFormatter::SectionPairMessageFormatter() = default;

ls::std::io::SectionPairMessageFormatter::~SectionPairMessageFormatter() = default;

::std::string ls::std::io::SectionPairMessageFormatter::getFormattedMessage(const ::std::string &_message)
{
  ::std::string formattedMessage = _message;
  formattedMessage = ::std::regex_replace(formattedMessage, ::std::regex(R"(\r{1}\n{1})"), "{WINDOWS_LINE_BREAK}");
  formattedMessage = ::std::regex_replace(formattedMessage, ::std::regex(R"(\n{1})"), "{UNIX_LINE_BREAK}");

  return formattedMessage;
}
