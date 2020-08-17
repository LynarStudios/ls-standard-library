/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-15
 * Changed:         2020-08-17
 *
 * */

#ifndef FILE_OPERATION_EXCEPTION_HPP
#define FILE_OPERATION_EXCEPTION_HPP

#include <exception>
#include <string>

namespace ls_std {
  class FileOperationException : public std::exception {
    public:

      explicit FileOperationException() = default;

      const char *what() const noexcept override {
        return "file operation failed!";
      }
  };
}

#endif
