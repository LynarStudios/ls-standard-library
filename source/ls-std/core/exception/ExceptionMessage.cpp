/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-07
* Changed:         2023-02-07
*
* */

#include <cstring>
#include <ls-std/core/exception/ExceptionMessage.hpp>

ls::std::core::ExceptionMessage::ExceptionMessage(::std::string _message) : message(::std::move(_message))
{}

ls::std::core::ExceptionMessage::~ExceptionMessage() = default;

char *ls::std::core::ExceptionMessage::toCharacterPointer()
{
  char *rawPointerMessage{};

  if (!this->message.empty())
  {
    rawPointerMessage = new char[this->message.size() + 1];
    strcpy(rawPointerMessage, this->message.c_str());
    rawPointerMessage[this->message.size()] = '\0';
  }

  return rawPointerMessage;
}
