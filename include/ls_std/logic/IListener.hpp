/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-14
 * Changed:         2022-04-29
 *
 * */

#ifndef LS_STD_I_LISTENER_HPP
#define LS_STD_I_LISTENER_HPP

#include <ls_std/core/Class.hpp>

namespace ls_std
{
  class IListener
  {
    public:

      IListener() = default;
      ~IListener() = default;

      virtual void listen(const ls_std::Class &_info) = 0;
  };
}

#endif
