/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-22
* Changed:         2023-03-28
*
* */

#include <ls-std/core/exception/Exception.hpp>
#include <ls-std/core/exception/ExceptionMessage.hpp>

using ls::std::core::Exception;
using std::move;
using std::string;

Exception::Exception(string _name) : name(::move(_name))
{}

Exception::~Exception() noexcept = default;

string Exception::getName() const
{
  return this->name;
}

const char *Exception::_getIdentifiedMessage(const string &_defaultMessage) const
{
  string concatenatedMessage = this->name + " thrown - ";

  if (this->message.empty())
  {
    concatenatedMessage = concatenatedMessage + _defaultMessage;
  }
  else
  {
    concatenatedMessage = concatenatedMessage + this->message;
  }

  return ExceptionMessage{concatenatedMessage}.toCharacterPointer();
}
