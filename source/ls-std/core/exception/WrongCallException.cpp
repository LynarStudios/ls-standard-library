/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-10
* Changed:         2023-02-10
*
* */

#include <ls-std/core/exception/WrongCallException.hpp>
#include <ls-std/core/exception/ExceptionMessage.hpp>

ls::std::core::WrongCallException::WrongCallException() = default;

ls::std::core::WrongCallException::WrongCallException(::std::string _message) : message(::std::move(_message))
{}

ls::std::core::WrongCallException::~WrongCallException() = default;

const char *ls::std::core::WrongCallException::what() const noexcept
{
  ::std::string concatenatedMessage = "WrongCallException thrown - ";

  if (this->message.empty())
  {
    concatenatedMessage = concatenatedMessage + "this function / method call is invalid!";
  }
  else
  {
    concatenatedMessage = concatenatedMessage + this->message;
  }

  return ExceptionMessage{concatenatedMessage}.toCharacterPointer();
}
