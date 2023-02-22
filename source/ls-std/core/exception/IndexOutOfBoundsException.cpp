/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-10
* Changed:         2023-02-22
*
* */

#include <ls-std/core/exception/ExceptionMessage.hpp>
#include <ls-std/core/exception/IndexOutOfBoundsException.hpp>

ls::std::core::IndexOutOfBoundsException::IndexOutOfBoundsException() : ls::std::core::Exception("IndexOutOfBoundsException")
{}

ls::std::core::IndexOutOfBoundsException::IndexOutOfBoundsException(::std::string _message) : ls::std::core::IndexOutOfBoundsException()
{
  this->message = ::std::move(_message);
}

ls::std::core::IndexOutOfBoundsException::~IndexOutOfBoundsException() = default;

const char *ls::std::core::IndexOutOfBoundsException::what() const noexcept
{
  ::std::string concatenatedMessage = this->name + " thrown - ";

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
