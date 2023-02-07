/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-07
* Changed:         2023-02-07
*
* */

#ifndef LS_STD_EXCEPTION_MESSAGE_HPP
#define LS_STD_EXCEPTION_MESSAGE_HPP

#include <ls-std/os/dynamic-goal.hpp>
#include <string>

namespace LS_STD_DYNAMIC_GOAL ls::std::core
{
  class ExceptionMessage
  {
    public:

      explicit ExceptionMessage(::std::string _message);
      ~ExceptionMessage();

      char *toCharacterPointer();

    private:

      ::std::string message{};
  };
}

#endif
