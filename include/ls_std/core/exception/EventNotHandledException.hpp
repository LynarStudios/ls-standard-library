/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-05-27
 * Changed:         2022-06-29
 *
 * */

#ifndef LS_STD_EVENT_NOT_HANDLED_EXCEPTION_HPP
#define LS_STD_EVENT_NOT_HANDLED_EXCEPTION_HPP

#include <exception>
#include <ls_std/os/dynamic_goal.hpp>

namespace ls
{
  namespace std
  {
    namespace core
    {
      class DYNAMIC_GOAL EventNotHandledException : public ::std::exception
      {
        public:

          EventNotHandledException() = default;

          const char *what() const noexcept override
          {
            return "EventNotHandledException thrown - event was not handled - nothing happened!";
          };
      };
    }
  }
}

#endif
