/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-07
 * Changed:         2020-08-07
 *
 * */

#ifndef ILLEGAL_OPERATION_EXCEPTION_HPP
#define ILLEGAL_OPERATION_EXCEPTION_HPP

#include <exception>

namespace ls_std {
  class IllegalOperationException : public std::exception {
    public:

      const char *what() const noexcept override {
        return "operation is not valid...";
      }
  };
}

#endif
