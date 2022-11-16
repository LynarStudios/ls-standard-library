/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-11-16
 * Changed:         2022-11-16
 *
 * */

#ifndef LS_STD_SOCKET_HPP
#define LS_STD_SOCKET_HPP

#include <ls_std/os/dynamic_goal.hpp>
#include <ls_std/core/Class.hpp>
#include "SocketParameter.hpp"

namespace ls::std::network
{
  class LS_STD_DYNAMIC_GOAL Socket : public ls::std::core::Class
  {
    public:

      explicit Socket(const ls::std::network::SocketParameter& _parameter);
      ~Socket() override = default;

    private:

      ls::std::network::SocketParameter parameter;
  };
}

#endif
