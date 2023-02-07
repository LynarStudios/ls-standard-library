/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2023-02-04
 * Changed:         2023-02-07
 *
 * */

#include <ls-std/core/exception/ExceptionMessage.hpp>
#include <ls-std/core/exception/IllegalArgumentException.hpp>

ls::std::core::IllegalArgumentException::IllegalArgumentException() = default;

ls::std::core::IllegalArgumentException::IllegalArgumentException(::std::string _message) : message(::std::move(_message))
{}

ls::std::core::IllegalArgumentException::~IllegalArgumentException() = default;

const char *ls::std::core::IllegalArgumentException::what() const noexcept
{
  ::std::string concatenatedMessage = "IllegalArgumentException thrown - ";

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
