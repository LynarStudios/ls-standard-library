/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2023-02-04
 * Changed:         2023-02-23
 *
 * */

#include <ls-std/core/exception/EventNotHandledException.hpp>
#include <ls-std/core/exception/ExceptionMessage.hpp>

using ls::std::core::EventNotHandledException;
using ls::std::core::Exception;
using std::move;
using std::string;

EventNotHandledException::EventNotHandledException() : Exception("EventNotHandledException")
{}

EventNotHandledException::EventNotHandledException(string _message) : EventNotHandledException()
{
  this->message = ::move(_message);
}

EventNotHandledException::~EventNotHandledException() noexcept = default;

const char *EventNotHandledException::what() const noexcept
{
  string concatenatedMessage = this->name + " thrown - ";

  if (this->message.empty())
  {
    concatenatedMessage = concatenatedMessage + "event was not handled - nothing happened!";
  }
  else
  {
    concatenatedMessage = concatenatedMessage + this->message;
  }

  return ExceptionMessage{concatenatedMessage}.toCharacterPointer();
}
