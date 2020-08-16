/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-15
 * Changed:         2020-08-16
 *
 * */

#ifndef FILE_PATH_SEPARATOR_HPP
#define FILE_PATH_SEPARATOR_HPP

#include <string>

namespace ls_std {
  class FilePathSeparator {
    public:

      FilePathSeparator() = default;
      ~FilePathSeparator() = default;

      static char getLinuxFilePathSeparator() {
        return '/';
      }

      static char getOperatingSystemSpecificSeparator() {
        char separator {};

        #ifdef _WIN32
          separator = ls_std::FilePathSeparator::getUnixFilePathSeparator();
        #endif
        #ifdef unix
          separator = ls_std::FilePathSeparator::getLinuxFilePathSeparator();
        #endif
        #ifdef __APPLE__
          separator = ls_std::FilePathSeparator::getLinuxFilePathSeparator();
        #endif

        return separator;
      }

      static char getUnixFilePathSeparator() {
        return '\\';
      }
  };
}

#endif
