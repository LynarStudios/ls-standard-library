/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2023-02-04
 * Changed:         2023-02-23
 *
 * */

#include <ls-std/core/exception/ExceptionMessage.hpp>
#include <ls-std/core/exception/FileNotFoundException.hpp>

using ls::std::core::Exception;
using ls::std::core::FileNotFoundException;
using std::move;
using std::string;

FileNotFoundException::FileNotFoundException() : Exception("FileNotFoundException")
{}

FileNotFoundException::FileNotFoundException(string _message) : FileNotFoundException()
{
  this->message = ::move(_message);
}

FileNotFoundException::~FileNotFoundException() noexcept = default;

const char *FileNotFoundException::what() const noexcept
{
  string concatenatedMessage = this->name + " thrown - ";

  if (this->message.empty())
  {
    concatenatedMessage = concatenatedMessage + "file not found!";
  }
  else
  {
    concatenatedMessage = concatenatedMessage + this->message;
  }

  return ExceptionMessage{concatenatedMessage}.toCharacterPointer();
}
