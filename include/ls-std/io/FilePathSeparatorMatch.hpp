/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-15
 * Changed:         2023-02-04
 *
 * */

#ifndef LS_STD_FILE_PATH_MATCH_HPP
#define LS_STD_FILE_PATH_MATCH_HPP

#include "FilePathSeparator.hpp"

namespace ls::std::io
{
  struct FilePathSeparatorMatch // TODO: turn to class, rather than keeping it as struct
  {
    bool operator()(char _char) const
    {
      return _char == ls::std::io::FilePathSeparator::getWindowsFilePathSeparator() || _char == ls::std::io::FilePathSeparator::getUnixFilePathSeparator();
    }
  };
}

#endif
