/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2023-02-04
 * Changed:         2023-02-22
 *
 * */

#include <ls-std/core/exception/ExceptionMessage.hpp>
#include <ls-std/core/exception/FileOperationException.hpp>

ls::std::core::FileOperationException::FileOperationException() : ls::std::core::Exception("FileOperationException")
{}

ls::std::core::FileOperationException::FileOperationException(::std::string _message) : ls::std::core::FileOperationException()
{
  this->message = ::std::move(_message);
}

ls::std::core::FileOperationException::~FileOperationException() = default;

const char *ls::std::core::FileOperationException::what() const noexcept
{
  ::std::string concatenatedMessage = this->name + " thrown - ";

  if (this->message.empty())
  {
    concatenatedMessage = concatenatedMessage + "file operation failed!";
  }
  else
  {
    concatenatedMessage = concatenatedMessage + this->message;
  }

  return ExceptionMessage{concatenatedMessage}.toCharacterPointer();
}
