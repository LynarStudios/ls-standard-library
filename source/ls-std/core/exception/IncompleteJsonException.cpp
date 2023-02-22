/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2023-02-04
 * Changed:         2023-02-22
 *
 * */

#include <ls-std/core/exception/ExceptionMessage.hpp>
#include <ls-std/core/exception/IncompleteJsonException.hpp>

ls::std::core::IncompleteJsonException::IncompleteJsonException() : ls::std::core::Exception("IncompleteJsonException")
{}

ls::std::core::IncompleteJsonException::IncompleteJsonException(::std::string _message) : ls::std::core::IncompleteJsonException()
{
  this->message = ::std::move(_message);
}

ls::std::core::IncompleteJsonException::~IncompleteJsonException() noexcept = default;

const char *ls::std::core::IncompleteJsonException::what() const noexcept
{
  ::std::string concatenatedMessage = this->name + " thrown - ";

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
