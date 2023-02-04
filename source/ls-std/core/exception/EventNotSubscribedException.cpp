/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2023-02-04
 * Changed:         2023-02-04
 *
 * */

#include <ls-std/core/exception/EventNotSubscribedException.hpp>

ls::std::core::EventNotSubscribedException::EventNotSubscribedException() = default;

ls::std::core::EventNotSubscribedException::~EventNotSubscribedException() = default;

const char *ls::std::core::EventNotSubscribedException::what() const noexcept
{
  return "EventNotSubscribedException thrown - event was not subscribed!";
}
