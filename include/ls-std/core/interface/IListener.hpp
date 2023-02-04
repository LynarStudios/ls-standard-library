/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-14
 * Changed:         2023-02-03
 *
 * */

#ifndef LS_STD_I_LISTENER_HPP
#define LS_STD_I_LISTENER_HPP

#include <ls-std/core/Class.hpp>

namespace ls::std::core::interface_type
{
  class IListener
  {
    public:

      IListener() = default;
      ~IListener() = default;

      virtual void listen(const ls::std::core::Class &_info) = 0;
  };
}

#endif
