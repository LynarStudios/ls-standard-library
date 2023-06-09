/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-15
 * Changed:         2023-02-22
 *
 * */

#ifndef LS_STD_FILE_PATH_SEPARATOR_HPP
#define LS_STD_FILE_PATH_SEPARATOR_HPP

#include <ls-std/os/dynamic-goal.hpp>
#include <string>

namespace ls::std::io
{
  class LS_STD_DYNAMIC_GOAL FilePathSeparator
  {
    public:

      FilePathSeparator();
      ~FilePathSeparator();

      [[nodiscard]] static char get();
      [[nodiscard]] static char getUnixFilePathSeparator();
      [[nodiscard]] static char getWindowsFilePathSeparator();
  };
}

#endif
