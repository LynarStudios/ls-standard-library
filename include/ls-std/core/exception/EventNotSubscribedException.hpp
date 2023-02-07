/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-05-27
 * Changed:         2023-02-07
 *
 * */

#ifndef LS_STD_EVENT_NOT_SUBSCRIBED_EXCEPTION_HPP
#define LS_STD_EVENT_NOT_SUBSCRIBED_EXCEPTION_HPP

#include <exception>
#include <ls-std/os/dynamic-goal.hpp>
#include <string>

namespace ls::std::core
{
  class LS_STD_DYNAMIC_GOAL EventNotSubscribedException : public ::std::exception
  {
    public:

      EventNotSubscribedException();
      explicit EventNotSubscribedException(::std::string _message);
      ~EventNotSubscribedException() override;

      [[nodiscard]] const char *what() const noexcept override;

    private:

      ::std::string message{};
  };
}

#endif
