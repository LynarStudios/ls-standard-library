/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-15
 * Changed:         2020-08-15
 *
 * */

#ifndef FILE_OPERATION_EXCEPTION_HPP
#define FILE_OPERATION_EXCEPTION_HPP

#include <exception>
#include <string>

namespace ls_std {
  class FileOperationException : public std::exception {
    public:

      explicit FileOperationException(std::string _filePath):
      filePath(std::move(_filePath))
      {}

      const char *what() const noexcept override {
        const std::string errorMessage = "file operation failed!\nfile: " + this->filePath;
        return std::move(errorMessage.c_str());
      }

    private:

      std::string filePath {};
  };
}

#endif
