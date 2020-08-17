/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2020-08-17
 *
 * */

#ifndef FILE_NOT_FOUND_EXCEPTION_HPP
#define FILE_NOT_FOUND_EXCEPTION_HPP

#include <exception>
#include <string>
#include <cstring>

namespace ls_std {
  class FileNotFoundException : public std::exception {
    public:

      FileNotFoundException() = default;

      const char *what() const noexcept override {
        return "file not found!";
      };
  };
}

#endif
