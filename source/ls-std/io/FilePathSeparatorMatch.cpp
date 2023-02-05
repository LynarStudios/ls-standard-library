/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-05
* Changed:         2023-02-05
*
* */

#include <ls-std/io/FilePathSeparator.hpp>
#include <ls-std/io/FilePathSeparatorMatch.hpp>

ls::std::io::FilePathSeparatorMatch::FilePathSeparatorMatch() = default;

ls::std::io::FilePathSeparatorMatch::~FilePathSeparatorMatch() = default;

bool ls::std::io::FilePathSeparatorMatch::operator()(char _char) const
{
  return _char == ls::std::io::FilePathSeparator::getWindowsFilePathSeparator() || _char == ls::std::io::FilePathSeparator::getUnixFilePathSeparator();
}
