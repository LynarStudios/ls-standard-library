/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-11-16
 * Changed:         2022-11-18
 *
 * */

#include <ls_std/network/socket/Socket.hpp>
#if defined(unix) || defined(__APPLE__)
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#endif
#include <ls_std/network/core/ProtocolFamilyMapper.hpp>
#include <ls_std/network/core/ProtocolMapper.hpp>

ls::std::network::Socket::Socket(const ls::std::network::SocketParameter& _parameter) : ls::std::core::Class("Socket"),
parameter(_parameter)
{
  #if defined(unix) || defined(__APPLE__)
  this->unixDescriptor = ls::std::network::Socket::_initUnix(_parameter);
  this->initialized = this->unixDescriptor != -1;
  #endif
}

bool ls::std::network::Socket::connect()
{
  #if defined(unix) || defined(__APPLE__)
  return ls::std::network::Socket::_connectUnix();
  #endif
}

bool ls::std::network::Socket::isInitialized() const
{
  return this->initialized;
}

#if defined(unix) || defined(__APPLE__)
bool ls::std::network::Socket::_connectUnix() const
{
  sockaddr_in socketAddressUnix{}; // TODO: put everything inside a dedicated mapper
  socketAddressUnix.sin_port = htons(this->parameter.socketAddress.port);

  ls::std::network::ProtocolFamily protocolFamily = ls::std::network::ProtocolFamilyMapper::from(this->parameter.protocolFamilyType);
  socketAddressUnix.sin_family = protocolFamily.unixDomain;
  inet_aton(this->parameter.socketAddress.ipAddress.c_str(), &socketAddressUnix.sin_addr);

  return ::connect(this->unixDescriptor, reinterpret_cast<const sockaddr *>(&socketAddressUnix), sizeof(socketAddressUnix)) == 0;
}
#endif

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
