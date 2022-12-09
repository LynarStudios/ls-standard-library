/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-11-16
 * Changed:         2022-12-09
 *
 * */

#include <ls_std/network/socket/Socket.hpp>
#include <ls_std/network/core/ProtocolFamilyMapper.hpp>
#include <ls_std/network/core/ProtocolMapper.hpp>
#include <ls_std/network/socket/ConvertedSocketAddress.hpp>
#include <ls_std/network/socket/SocketAddressMapper.hpp>

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
bool ls::std::network::Socket::_connectUnix()
{
  ls::std::network::ConvertedSocketAddress convertedSocketAddress = ls::std::network::SocketAddressMapper::from(ls::std::network::Socket::_createSocketAddressMapperParameter());
  return this->posixSocket.connect(this->unixDescriptor, reinterpret_cast<const sockaddr *>(&convertedSocketAddress.socketAddressUnix), sizeof(convertedSocketAddress.socketAddressUnix)) == 0;
}
#endif

ls::std::network::SocketAddressMapperParameter ls::std::network::Socket::_createSocketAddressMapperParameter() const
{
  ls::std::network::SocketAddressMapperParameter mapperParameter{};
  mapperParameter.socketAddress = this->parameter.socketAddress;
  mapperParameter.protocolFamilyType = this->parameter.protocolFamilyType;

  return mapperParameter;
}

bool ls::std::network::Socket::_init(const ls::std::network::SocketParameter &_parameter)
{
  #if defined(unix) || defined(__APPLE__)
  return this->_initUnix(_parameter);
  #endif
}

#if defined(unix) || defined(__APPLE__)
bool ls::std::network::Socket::_initUnix(const ls::std::network::SocketParameter &_parameter)
{
  ls::std::network::ConvertedProtocolFamily convertedProtocolFamily = ls::std::network::ProtocolFamilyMapper::from(_parameter.protocolFamilyType);
  ls::std::network::Protocol protocol = ls::std::network::ProtocolMapper::from(_parameter.socketAddress.protocolType);

  return this->posixSocket.create(convertedProtocolFamily.unixDomain, protocol.unixProtocol, 0);
}
#endif
