/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-14
 * Changed:         2023-02-05
 *
 * */

#ifndef LS_STD_I_LISTENER_HPP
#define LS_STD_I_LISTENER_HPP

#include <ls-std/core/Class.hpp>
#include <ls-std/os/dynamic-goal.hpp>

namespace ls::std::core::interface_type
{
  class LS_STD_DYNAMIC_GOAL IListener
  {
    public:

      IListener();
      virtual ~IListener();

      virtual void listen(const ls::std::core::Class &_info) = 0;
  };
}

#endif
