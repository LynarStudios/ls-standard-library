/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-11-16
 * Changed:         2022-11-17
 *
 * */

#include <ls_std/network/socket/Socket.hpp>
#if defined(unix) || defined(__APPLE__)
#include <sys/socket.h>
#endif
#include <ls_std/network/core/ProtocolFamilyMapper.hpp>
#include <ls_std/network/core/ProtocolMapper.hpp>

ls::std::network::Socket::Socket(const ls::std::network::SocketParameter& _parameter) : ls::std::core::Class("Socket"),
parameter(_parameter)
{
  this->initialized = ls::std::network::Socket::_initUnix(_parameter);
}

bool ls::std::network::Socket::isInitialized() const
{
  return this->initialized;
}

bool ls::std::network::Socket::_init(const ls::std::network::SocketParameter &_parameter)
{
  #if defined(unix) || defined(__APPLE__)
  return ls::std::network::Socket::_initUnix(_parameter);
  #endif
}

#if defined(unix) || defined(__APPLE__)
bool ls::std::network::Socket::_initUnix(const ls::std::network::SocketParameter &_parameter)
{
  ls::std::network::ProtocolFamily protocolFamily = ls::std::network::ProtocolFamilyMapper::from(_parameter.protocolFamilyType);
  ls::std::network::Protocol protocol = ls::std::network::ProtocolMapper::from(_parameter.socketAddress.protocolType);

  return socket(protocolFamily.unixDomain, protocol.unixProtocol, 0);
}
#endif
