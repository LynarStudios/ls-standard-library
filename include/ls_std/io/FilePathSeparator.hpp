/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-15
 * Changed:         2022-07-02
 *
 * */

#ifndef FILE_PATH_SEPARATOR_HPP
#define FILE_PATH_SEPARATOR_HPP

#include <string>
#include <ls_std/os/dynamic_goal.hpp>

namespace ls::std::io
{
  class DYNAMIC_GOAL FilePathSeparator
  {
    public:

      FilePathSeparator() = default;
      ~FilePathSeparator() = default;

      static char get()
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

      static char getUnixFilePathSeparator()
      {
        return '/';
      }

      static char getWindowsFilePathSeparator()
      {
        return '\\';
      }
  };
}

#endif
