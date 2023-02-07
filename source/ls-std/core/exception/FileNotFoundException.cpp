/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2023-02-04
 * Changed:         2023-02-07
 *
 * */

#include <ls-std/core/exception/ExceptionMessage.hpp>
#include <ls-std/core/exception/FileNotFoundException.hpp>

ls::std::core::FileNotFoundException::FileNotFoundException() = default;

ls::std::core::FileNotFoundException::FileNotFoundException(::std::string _message) : message(::std::move(_message))
{}

ls::std::core::FileNotFoundException::~FileNotFoundException() = default;

const char *ls::std::core::FileNotFoundException::what() const noexcept
{
  ::std::string concatenatedMessage = "FileNotFoundException thrown - ";

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
