/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-15
 * Changed:         2020-08-15
 *
 * */

#ifndef FILE_PATH_MATCH_HPP
#define FILE_PATH_MATCH_HPP

#include "FilePathSeparator.hpp"

namespace ls_std {
  struct FilePathSeparatorMatch {
    bool operator()(char _char) const {
      return _char == ls_std::FilePathSeparator::getUnixFilePathSeparator() || _char == ls_std::FilePathSeparator::getLinuxFilePathSeparator();
    }
  };
}

#endif
