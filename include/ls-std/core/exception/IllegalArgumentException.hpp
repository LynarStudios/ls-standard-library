/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-09
 * Changed:         2023-02-07
 *
 * */

#ifndef LS_STD_ILLEGAL_ARGUMENT_EXCEPTION_HPP
#define LS_STD_ILLEGAL_ARGUMENT_EXCEPTION_HPP

#include <exception>
#include <ls-std/os/dynamic-goal.hpp>
#include <string>

namespace ls::std::core
{
  class LS_STD_DYNAMIC_GOAL IllegalArgumentException : public ::std::exception
  {
    public:

      IllegalArgumentException();
      explicit IllegalArgumentException(::std::string _message);
      ~IllegalArgumentException() override;

      [[nodiscard]] const char *what() const noexcept override;

    private:

      ::std::string message{};
  };
}

#endif
