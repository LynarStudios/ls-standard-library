/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2023-02-04
 * Changed:         2023-02-22
 *
 * */

#include <ls-std/core/exception/EventNotSubscribedException.hpp>
#include <ls-std/core/exception/ExceptionMessage.hpp>

ls::std::core::EventNotSubscribedException::EventNotSubscribedException() : ls::std::core::Exception("EventNotSubscribedException")
{}

ls::std::core::EventNotSubscribedException::EventNotSubscribedException(::std::string _message) : ls::std::core::EventNotSubscribedException()
{
  this->message = ::std::move(_message);
}

ls::std::core::EventNotSubscribedException::~EventNotSubscribedException() noexcept = default;

const char *ls::std::core::EventNotSubscribedException::what() const noexcept
{
  ::std::string concatenatedMessage = this->name + " thrown - ";

  if (this->message.empty())
  {
    concatenatedMessage = concatenatedMessage + "event was not subscribed!";
  }
  else
  {
    concatenatedMessage = concatenatedMessage + this->message;
  }

  return ExceptionMessage{concatenatedMessage}.toCharacterPointer();
}
