/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2023-02-04
 * Changed:         2023-02-23
 *
 * */

#include <ls-std/core/exception/ExceptionMessage.hpp>
#include <ls-std/core/exception/NullPointerException.hpp>

using ls::std::core::Exception;
using ls::std::core::NullPointerException;
using std::move;
using std::string;

NullPointerException::NullPointerException() : Exception("NullPointerException")
{}

NullPointerException::NullPointerException(string _message) : NullPointerException()
{
  this->message = ::move(_message);
}

NullPointerException::~NullPointerException() noexcept = default;

const char *NullPointerException::what() const noexcept
{
  string concatenatedMessage = this->name + " thrown - ";

  if (this->message.empty())
  {
    concatenatedMessage = concatenatedMessage + "reference is null!";
  }
  else
  {
    concatenatedMessage = concatenatedMessage + this->message;
  }

  return ExceptionMessage{concatenatedMessage}.toCharacterPointer();
}
