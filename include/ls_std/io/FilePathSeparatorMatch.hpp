/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-15
 * Changed:         2022-07-01
 *
 * */

#ifndef LS_STD_FILE_PATH_MATCH_HPP
#define LS_STD_FILE_PATH_MATCH_HPP

#include "FilePathSeparator.hpp"
#include <ls_std/os/dynamic_goal.hpp>

namespace ls
{
  namespace std
  {
    namespace io
    {
      struct DYNAMIC_GOAL FilePathSeparatorMatch
      {
        bool operator()(char _char) const
        {
          return _char == ls::std::io::FilePathSeparator::getWindowsFilePathSeparator() || _char == ls::std::io::FilePathSeparator::getUnixFilePathSeparator();
        }
      };
    }
  }
}

#endif
