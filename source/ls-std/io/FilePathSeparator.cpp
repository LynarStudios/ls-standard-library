/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-04
* Changed:         2023-02-23
*
* */

#include <ls-std/io/FilePathSeparator.hpp>

using ls::std::io::FilePathSeparator;

FilePathSeparator::FilePathSeparator() = default;

FilePathSeparator::~FilePathSeparator() = default;

#if defined(unix) || defined(__APPLE__)
char FilePathSeparator::get()
{
  return '/';
}
#endif
#ifdef _WIN32
char FilePathSeparator::get()
{
  return '\\';
}
#endif

char FilePathSeparator::getUnixFilePathSeparator()
{
  return '/';
}

char FilePathSeparator::getWindowsFilePathSeparator()
{
  return '\\';
}
