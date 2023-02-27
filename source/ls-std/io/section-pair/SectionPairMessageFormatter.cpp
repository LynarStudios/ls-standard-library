/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-22
* Changed:         2023-02-23
*
* */

#include <ls-std/io/section-pair/SectionPairMessageFormatter.hpp>
#include <regex>

using ls::std::io::SectionPairMessageFormatter;
using std::regex;
using std::regex_replace;
using std::string;

SectionPairMessageFormatter::SectionPairMessageFormatter() = default;

SectionPairMessageFormatter::~SectionPairMessageFormatter() = default;

string SectionPairMessageFormatter::getFormattedMessage(const string &_message)
{
  string formattedMessage = _message;
  formattedMessage = regex_replace(formattedMessage, regex(R"(\r{1}\n{1})"), "{WINDOWS_LINE_BREAK}");
  formattedMessage = regex_replace(formattedMessage, regex(R"(\n{1})"), "{UNIX_LINE_BREAK}");

  return formattedMessage;
}
