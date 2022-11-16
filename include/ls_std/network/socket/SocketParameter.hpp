/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-11-16
 * Changed:         2022-11-16
 *
 * */

#ifndef LS_STD_SOCKET_PARAMETER_HPP
#define LS_STD_SOCKET_PARAMETER_HPP

#include <ls_std/network/core/ProtocolType.hpp>

namespace ls::std::network
{
  struct SocketParameter
  {
    ProtocolType protocolType{};
  };
}

#endif
