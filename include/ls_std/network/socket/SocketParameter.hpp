/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-11-16
 * Changed:         2022-12-16
 *
 * */

#ifndef LS_STD_SOCKET_PARAMETER_HPP
#define LS_STD_SOCKET_PARAMETER_HPP

#include <ls_std/network/core/ProtocolFamilyType.hpp>
#include <ls_std/core/interface/IPosixSocket.hpp>
#include <ls_std/core/interface/IPosixReader.hpp>
#include "SocketAddress.hpp"
#include <memory>

namespace ls::std::network
{
  struct SocketParameter
  {
    ::std::shared_ptr<ls::std::core::interface_type::IPosixReader> posixReader{};
    ::std::shared_ptr<ls::std::core::interface_type::IPosixSocket> posixSocket{};
    ls::std::network::ProtocolFamilyType protocolFamilyType{};
    int queueSize{};
    size_t readBufferSize{};
    ls::std::network::SocketAddress socketAddress{};
  };
}

#endif
