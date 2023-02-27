/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-07
* Changed:         2023-02-23
*
* */

#include <cstring>
#include <ls-std/core/exception/ExceptionMessage.hpp>

using ls::std::core::ExceptionMessage;
using std::move;
using std::string;

ExceptionMessage::ExceptionMessage(string _message) : message(::move(_message))
{}

ExceptionMessage::~ExceptionMessage() = default;

char *ExceptionMessage::toCharacterPointer()
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
