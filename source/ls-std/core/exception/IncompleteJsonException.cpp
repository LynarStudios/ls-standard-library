/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2023-02-04
 * Changed:         2023-02-23
 *
 * */

#include <ls-std/core/exception/ExceptionMessage.hpp>
#include <ls-std/core/exception/IncompleteJsonException.hpp>

using ls::std::core::Exception;
using ls::std::core::IncompleteJsonException;
using std::move;
using std::string;

IncompleteJsonException::IncompleteJsonException() : Exception("IncompleteJsonException")
{}

IncompleteJsonException::IncompleteJsonException(string _message) : IncompleteJsonException()
{
  this->message = ::move(_message);
}

IncompleteJsonException::~IncompleteJsonException() noexcept = default;

const char *IncompleteJsonException::what() const noexcept
{
  string concatenatedMessage = this->name + " thrown - ";

  if (this->message.empty())
  {
    concatenatedMessage = concatenatedMessage + "this JSON string is incomplete.";
  }
  else
  {
    concatenatedMessage = concatenatedMessage + this->message;
  }

  return ExceptionMessage{concatenatedMessage}.toCharacterPointer();
}
