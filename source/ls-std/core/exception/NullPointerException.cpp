/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2023-02-04
 * Changed:         2023-02-07
 *
 * */

#include <ls-std/core/exception/ExceptionMessage.hpp>
#include <ls-std/core/exception/NullPointerException.hpp>

ls::std::core::NullPointerException::NullPointerException() = default;

ls::std::core::NullPointerException::NullPointerException(::std::string _message) : message(::std::move(_message))
{}

ls::std::core::NullPointerException::~NullPointerException() = default;

const char *ls::std::core::NullPointerException::what() const noexcept
{
  ::std::string concatenatedMessage = "NullPointerException thrown - ";

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
