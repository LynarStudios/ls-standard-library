/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-04
* Changed:         2023-02-04
*
* */

#include <ls-std/io/FilePathSeparator.hpp>

ls::std::io::FilePathSeparator::FilePathSeparator() = default;

ls::std::io::FilePathSeparator::~FilePathSeparator() = default;

char ls::std::io::FilePathSeparator::get()
{
  char separator;

#ifdef _WIN32
  separator = ls::std::io::FilePathSeparator::getWindowsFilePathSeparator();
#endif
#if defined(unix) || defined(__APPLE__)
  separator = ls::std::io::FilePathSeparator::getUnixFilePathSeparator();
#endif

  return separator;
}

char ls::std::io::FilePathSeparator::getUnixFilePathSeparator()
{
  return '/';
}

char ls::std::io::FilePathSeparator::getWindowsFilePathSeparator()
{
  return '\\';
}
