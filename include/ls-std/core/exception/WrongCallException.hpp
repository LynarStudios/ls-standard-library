/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-10
* Changed:         2023-02-10
*
* */

#ifndef LS_STD_WRONG_CALL_EXCEPTION_HPP
#define LS_STD_WRONG_CALL_EXCEPTION_HPP

#include <exception>
#include <ls-std/os/dynamic-goal.hpp>
#include <string>

namespace ls::std::core
{
  class LS_STD_DYNAMIC_GOAL WrongCallException : public ::std::exception
  {
    public:

      WrongCallException();
      explicit WrongCallException(::std::string _message);
      ~WrongCallException() override;

      [[nodiscard]] const char *what() const noexcept override;

    private:

      ::std::string message{};
  };
}

#endif
