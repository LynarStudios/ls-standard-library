/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-11-16
 * Changed:         2022-11-16
 *
 * */

#ifndef LS_STD_SOCKET_ADDRESS_HPP
#define LS_STD_SOCKET_ADDRESS_HPP

#include <ls_std/network/core/ProtocolType.hpp>
#include <ls_std/core/types/SocketTypes.hpp>

namespace ls::std::network
{
  struct SocketAddress
  {
    ls::std::network::ProtocolType protocolType{};
    ls::std::core::type::ip_address ipAddress{};
    ls::std::core::type::port port{};
  };
}

#endif
