/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2023-02-04
 * Changed:         2023-02-23
 *
 * */

#include <ls-std/core/exception/ExceptionMessage.hpp>
#include <ls-std/core/exception/FileOperationException.hpp>

using ls::std::core::Exception;
using ls::std::core::FileOperationException;
using std::move;
using std::string;

FileOperationException::FileOperationException() : Exception("FileOperationException")
{}

FileOperationException::FileOperationException(string _message) : FileOperationException()
{
  this->message = ::move(_message);
}

FileOperationException::~FileOperationException() noexcept = default;

const char *FileOperationException::what() const noexcept
{
  string concatenatedMessage = this->name + " thrown - ";

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
