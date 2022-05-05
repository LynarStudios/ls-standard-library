/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-15
 * Changed:         2022-05-05
 *
 * */

#ifndef LS_STD_FILE_PATH_MATCH_HPP
#define LS_STD_FILE_PATH_MATCH_HPP

#include "FilePathSeparator.hpp"

namespace ls
{
  struct FilePathSeparatorMatch
  {
    bool operator()(char _char) const
    {
      return _char == ls::FilePathSeparator::getWindowsFilePathSeparator() || _char == ls::FilePathSeparator::getUnixFilePathSeparator();
    }
  };
}

#endif
