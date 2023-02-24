/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-10
* Changed:         2023-02-23
*
* */

#include <ls-std/core/exception/ExceptionMessage.hpp>
#include <ls-std/core/exception/IndexOutOfBoundsException.hpp>

using ls::std::core::Exception;
using ls::std::core::IndexOutOfBoundsException;
using std::move;
using std::string;

IndexOutOfBoundsException::IndexOutOfBoundsException() : Exception("IndexOutOfBoundsException")
{}

IndexOutOfBoundsException::IndexOutOfBoundsException(string _message) : IndexOutOfBoundsException()
{
  this->message = ::move(_message);
}

IndexOutOfBoundsException::~IndexOutOfBoundsException() noexcept = default;

const char *IndexOutOfBoundsException::what() const noexcept
{
  string concatenatedMessage = this->name + " thrown - ";

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
