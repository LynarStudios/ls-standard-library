/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2023-02-04
 * Changed:         2023-02-23
 *
 * */

#include <ls-std/core/exception/ExceptionMessage.hpp>
#include <ls-std/core/exception/IllegalArithmeticOperationException.hpp>

using ls::std::core::Exception;
using ls::std::core::IllegalArithmeticOperationException;
using std::move;
using std::string;

IllegalArithmeticOperationException::IllegalArithmeticOperationException() : Exception("IllegalArithmeticOperationException")
{}

IllegalArithmeticOperationException::IllegalArithmeticOperationException(string _message) : IllegalArithmeticOperationException()
{
  this->message = ::move(_message);
}

IllegalArithmeticOperationException::~IllegalArithmeticOperationException() noexcept = default;

const char *IllegalArithmeticOperationException::what() const noexcept
{
  string concatenatedMessage = this->name + " thrown - ";

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
