/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-15
 * Changed:         2022-05-05
 *
 * */

#ifndef FILE_PATH_SEPARATOR_HPP
#define FILE_PATH_SEPARATOR_HPP

#include <string>

namespace ls
{
  class FilePathSeparator
  {
    public:

      FilePathSeparator() = default;
      ~FilePathSeparator() = default;

      static char get()
      {
        char separator;

        #ifdef _WIN32
        separator = ls::FilePathSeparator::getWindowsFilePathSeparator();
        #endif
        #if defined(unix) || defined(__APPLE__)
        separator = ls::FilePathSeparator::getUnixFilePathSeparator();
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
