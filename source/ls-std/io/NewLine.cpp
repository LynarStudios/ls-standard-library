/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-04
* Changed:         2023-02-23
*
* */

#include <ls-std/io/NewLine.hpp>

using ls::std::io::NewLine;
using std::string;

NewLine::NewLine() = default;

NewLine::~NewLine() = default;

string NewLine::get()
{
  string newLine{};

#if defined(unix) || defined(__APPLE__)
  newLine = NewLine::getUnixNewLine();
#endif
#ifdef _WIN32
  newLine = NewLine::getWindowsNewLine();
#endif

  return newLine;
}

string NewLine::getUnixNewLine()
{
  return "\n";
}

string NewLine::getWindowsNewLine()
{
  return "\r\n";
}
