/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-04
* Changed:         2023-02-04
*
* */

#include <ls-std/io/NewLine.hpp>

ls::std::io::NewLine::NewLine() = default;

ls::std::io::NewLine::~NewLine() = default;

::std::string ls::std::io::NewLine::get()
{
  ::std::string newLine{};

#if defined(unix) || defined(__APPLE__)
  newLine = ls::std::io::NewLine::getUnixNewLine();
#endif
#ifdef _WIN32
  newLine = ls::std::io::NewLine::getWindowsNewLine();
#endif

  return newLine;
}

::std::string ls::std::io::NewLine::getUnixNewLine()
{
  return "\n";
}

::std::string ls::std::io::NewLine::getWindowsNewLine()
{
  return "\r\n";
}
