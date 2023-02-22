/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2023-02-04
 * Changed:         2023-02-22
 *
 * */

#include <ls-std/core/exception/ExceptionMessage.hpp>
#include <ls-std/core/exception/NullPointerException.hpp>

ls::std::core::NullPointerException::NullPointerException() : ls::std::core::Exception("NullPointerException")
{}

ls::std::core::NullPointerException::NullPointerException(::std::string _message) : ls::std::core::NullPointerException()
{
  this->message = ::std::move(_message);
}

ls::std::core::NullPointerException::~NullPointerException() noexcept = default;

const char *ls::std::core::NullPointerException::what() const noexcept
{
  ::std::string concatenatedMessage = this->name + " thrown - ";

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
