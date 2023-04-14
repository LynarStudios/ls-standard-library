/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2023-02-04
 * Changed:         2023-03-28
 *
 * */

#include <ls-std/core/exception/EventNotSubscribedException.hpp>
#include <ls-std/core/exception/ExceptionMessage.hpp>

using ls::std::core::EventNotSubscribedException;
using ls::std::core::Exception;
using std::move;
using std::string;

EventNotSubscribedException::EventNotSubscribedException() : Exception("EventNotSubscribedException")
{}

EventNotSubscribedException::EventNotSubscribedException(string _message) : EventNotSubscribedException()
{
  this->message = ::move(_message);
}

EventNotSubscribedException::~EventNotSubscribedException() noexcept = default;

const char *EventNotSubscribedException::what() const noexcept
{
  return this->_getIdentifiedMessage("event was not subscribed!");
}
