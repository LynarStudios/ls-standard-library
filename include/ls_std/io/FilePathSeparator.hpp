/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-15
 * Changed:         2022-05-11
 *
 * */

#ifndef FILE_PATH_SEPARATOR_HPP
#define FILE_PATH_SEPARATOR_HPP

#include <string>

namespace ls
{
  namespace std
  {
    namespace io
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
  }
}

#endif
