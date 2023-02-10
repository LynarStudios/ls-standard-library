/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-10
* Changed:         2023-02-10
*
* */

#include <ls-std/core/exception/ExceptionMessage.hpp>
#include <ls-std/core/exception/IndexOutOfBoundsException.hpp>

ls::std::core::IndexOutOfBoundsException::IndexOutOfBoundsException() = default;

ls::std::core::IndexOutOfBoundsException::IndexOutOfBoundsException(::std::string _message) : message(::std::move(_message))
{}

ls::std::core::IndexOutOfBoundsException::~IndexOutOfBoundsException() = default;

const char *ls::std::core::IndexOutOfBoundsException::what() const noexcept
{
  ::std::string concatenatedMessage = "IndexOutOfBoundsException thrown - ";

  if (this->message.empty())
  {
    concatenatedMessage = concatenatedMessage + "provided index is out of bounds!";
  }
  else
  {
    concatenatedMessage = concatenatedMessage + this->message;
  }

  return ExceptionMessage{concatenatedMessage}.toCharacterPointer();
}
