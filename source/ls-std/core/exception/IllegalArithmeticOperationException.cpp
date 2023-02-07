/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2023-02-04
 * Changed:         2023-02-07
 *
 * */

#include <ls-std/core/exception/ExceptionMessage.hpp>
#include <ls-std/core/exception/IllegalArithmeticOperationException.hpp>

ls::std::core::IllegalArithmeticOperationException::IllegalArithmeticOperationException() = default;

ls::std::core::IllegalArithmeticOperationException::IllegalArithmeticOperationException(::std::string _message) : message(::std::move(_message))
{}

ls::std::core::IllegalArithmeticOperationException::~IllegalArithmeticOperationException() = default;

const char *ls::std::core::IllegalArithmeticOperationException::what() const noexcept
{
  ::std::string concatenatedMessage = "IllegalArithmeticOperationException thrown - ";

  if (this->message.empty())
  {
    concatenatedMessage = concatenatedMessage + "arithmetic operation is not allowed!";
  }
  else
  {
    concatenatedMessage = concatenatedMessage + this->message;
  }

  return ExceptionMessage{concatenatedMessage}.toCharacterPointer();
}
