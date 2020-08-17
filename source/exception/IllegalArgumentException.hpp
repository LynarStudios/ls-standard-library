/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-09
 * Changed:         2020-08-17
 *
 * */

#ifndef ILLEGAL_ARGUMENT_EXCEPTION_HPP
#define ILLEGAL_ARGUMENT_EXCEPTION_HPP

#include <exception>

namespace ls_std {
  class IllegalArgumentException : public std::exception {
    public:

      IllegalArgumentException() = default;

      const char *what() const noexcept override {
        return "passed argument is not valid!";
      }
  };
}

#endif
