/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2023-02-04
 * Changed:         2023-02-07
 *
 * */

#include <ls-std/core/exception/FileNotFoundException.hpp>
#include <utility>

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

  return ls::std::core::FileNotFoundException::_mapMessageToRawPointer(concatenatedMessage);
}

char *ls::std::core::FileNotFoundException::_mapMessageToRawPointer(const ::std::string &_message)
{
  char *rawPointerMessage = new char[_message.size() + 1];
  strcpy(rawPointerMessage, _message.c_str());
  rawPointerMessage[_message.size()] = '\0';

  return rawPointerMessage;
}
