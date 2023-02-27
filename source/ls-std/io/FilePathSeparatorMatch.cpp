/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-05
* Changed:         2023-02-23
*
* */

#include <ls-std/io/FilePathSeparator.hpp>
#include <ls-std/io/FilePathSeparatorMatch.hpp>

using ls::std::io::FilePathSeparator;
using ls::std::io::FilePathSeparatorMatch;

FilePathSeparatorMatch::FilePathSeparatorMatch() = default;

FilePathSeparatorMatch::~FilePathSeparatorMatch() = default;

bool FilePathSeparatorMatch::operator()(char _char) const
{
  return _char == FilePathSeparator::getWindowsFilePathSeparator() || _char == FilePathSeparator::getUnixFilePathSeparator();
}
