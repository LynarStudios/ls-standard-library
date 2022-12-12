/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-11-16
 * Changed:         2022-12-12
 *
 * */

#ifndef LS_STD_SOCKET_PARAMETER_HPP
#define LS_STD_SOCKET_PARAMETER_HPP

#include <ls_std/network/core/ProtocolFamilyType.hpp>
#include "SocketAddress.hpp"
#include <memory>

namespace ls::std::network
{
  struct SocketParameter
  {
    ::std::shared_ptr<ls::std::core::interface_type::IPosixSocket> posixSocket{};
    ls::std::network::ProtocolFamilyType protocolFamilyType{};
    ls::std::network::SocketAddress socketAddress{};
    int queueSize{};
  };
}

#endif
