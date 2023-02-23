/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2023-02-04
 * Changed:         2023-02-23
 *
 * */

#include <ls-std/core/exception/ExceptionMessage.hpp>
#include <ls-std/core/exception/IllegalArgumentException.hpp>

using ls::std::core::Exception;
using ls::std::core::IllegalArgumentException;
using std::move;
using std::string;

IllegalArgumentException::IllegalArgumentException() : Exception("IllegalArgumentException")
{}

IllegalArgumentException::IllegalArgumentException(string _message) : IllegalArgumentException()
{
  this->message = ::move(_message);
}

IllegalArgumentException::~IllegalArgumentException() noexcept = default;

const char *IllegalArgumentException::what() const noexcept
{
  string concatenatedMessage = this->name + " thrown - ";

  if (this->message.empty())
  {
    concatenatedMessage = concatenatedMessage + "passed argument is not valid!";
  }
  else
  {
    concatenatedMessage = concatenatedMessage + this->message;
  }

  return ExceptionMessage{concatenatedMessage}.toCharacterPointer();
}
