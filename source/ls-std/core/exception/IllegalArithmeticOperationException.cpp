/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2023-02-04
 * Changed:         2023-02-22
 *
 * */

#include <ls-std/core/exception/ExceptionMessage.hpp>
#include <ls-std/core/exception/IllegalArithmeticOperationException.hpp>

ls::std::core::IllegalArithmeticOperationException::IllegalArithmeticOperationException() : ls::std::core::Exception("IllegalArithmeticOperationException")
{}

ls::std::core::IllegalArithmeticOperationException::IllegalArithmeticOperationException(::std::string _message) : ls::std::core::IllegalArithmeticOperationException()
{
  this->message = ::std::move(_message);
}

ls::std::core::IllegalArithmeticOperationException::~IllegalArithmeticOperationException() noexcept = default;

const char *ls::std::core::IllegalArithmeticOperationException::what() const noexcept
{
  ::std::string concatenatedMessage = this->name + " thrown - ";

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
