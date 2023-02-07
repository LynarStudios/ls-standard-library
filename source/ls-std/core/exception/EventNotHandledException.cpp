/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2023-02-04
 * Changed:         2023-02-07
 *
 * */

#include <ls-std/core/exception/EventNotHandledException.hpp>
#include <ls-std/core/exception/ExceptionMessage.hpp>

ls::std::core::EventNotHandledException::EventNotHandledException() = default;

ls::std::core::EventNotHandledException::EventNotHandledException(::std::string _message) : message(::std::move(_message))
{}

ls::std::core::EventNotHandledException::~EventNotHandledException() = default;

const char *ls::std::core::EventNotHandledException::what() const noexcept
{
  ::std::string concatenatedMessage = "EventNotHandledException thrown - ";

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
