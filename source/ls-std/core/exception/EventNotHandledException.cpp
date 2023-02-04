/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2023-02-04
 * Changed:         2023-02-04
 *
 * */

#include <ls-std/core/exception/EventNotHandledException.hpp>

ls::std::core::EventNotHandledException::EventNotHandledException() = default;

ls::std::core::EventNotHandledException::~EventNotHandledException() = default;

const char *ls::std::core::EventNotHandledException::what() const noexcept
{
  return "EventNotHandledException thrown - event was not handled - nothing happened!";
}
