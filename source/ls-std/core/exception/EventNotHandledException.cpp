/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2023-02-04
 * Changed:         2023-03-28
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
  return this->_getIdentifiedMessage("event was not handled - nothing happened!");
}
