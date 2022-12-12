/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-11-16
 * Changed:         2022-12-12
 *
 * */

#include <ls_std/network/socket/Socket.hpp>
#include <ls_std/network/core/ProtocolFamilyMapper.hpp>
#include <ls_std/network/core/ProtocolMapper.hpp>
#include <ls_std/network/socket/ConvertedSocketAddress.hpp>
#include <ls_std/network/socket/SocketAddressMapper.hpp>
#include <ls_std/network/socket/MockPosixSocket.hpp>
#include <ls_std/network/socket/PosixSocket.hpp>
#include <ls_std/core/exception/WrongProtocolException.hpp>
#include <memory>
#include <utility>

ls::std::network::Socket::Socket(ls::std::network::SocketParameter _parameter) : ls::std::core::Class("Socket"),
parameter(::std::move(_parameter))
{
  #if defined(unix) || defined(__APPLE__)
  this->unixDescriptor = ls::std::network::Socket::_initUnix();
  this->initialized = this->unixDescriptor != -1;
  #endif
}

bool ls::std::network::Socket::bind()
{
  #if defined(unix) || defined(__APPLE__)
  return ls::std::network::Socket::_bindUnix();
  #endif
}

bool ls::std::network::Socket::close()
{
  #if defined(unix) || defined(__APPLE__)
  return ls::std::network::Socket::_closeUnix();
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

bool ls::std::network::Socket::listen()
{
  if (this->parameter.socketAddress.protocolType != PROTOCOL_TYPE_TCP)
  {
    throw ls::std::core::WrongProtocolException{};
  }

  #if defined(unix) || defined(__APPLE__)
  return ls::std::network::Socket::_listenUnix();
  #endif
}

#if defined(unix) || defined(__APPLE__)
bool ls::std::network::Socket::_bindUnix()
{
  ls::std::network::ConvertedSocketAddress convertedSocketAddress = ls::std::network::SocketAddressMapper::from(ls::std::network::Socket::_createSocketAddressMapperParameter());
  return this->parameter.posixSocket->bind(this->unixDescriptor, reinterpret_cast<const sockaddr *>(&convertedSocketAddress.socketAddressUnix), sizeof(convertedSocketAddress.socketAddressUnix)) == 0;
}

bool ls::std::network::Socket::_closeUnix()
{
  return this->parameter.posixSocket->close(this->unixDescriptor) == 0;
}

bool ls::std::network::Socket::_connectUnix()
{
  ls::std::network::ConvertedSocketAddress convertedSocketAddress = ls::std::network::SocketAddressMapper::from(ls::std::network::Socket::_createSocketAddressMapperParameter());
  return this->parameter.posixSocket->connect(this->unixDescriptor, reinterpret_cast<const sockaddr *>(&convertedSocketAddress.socketAddressUnix), sizeof(convertedSocketAddress.socketAddressUnix)) == 0;
}
#endif

ls::std::network::SocketAddressMapperParameter ls::std::network::Socket::_createSocketAddressMapperParameter() const
{
  ls::std::network::SocketAddressMapperParameter mapperParameter{};
  mapperParameter.socketAddress = this->parameter.socketAddress;
  mapperParameter.protocolFamilyType = this->parameter.protocolFamilyType;

  return mapperParameter;
}

bool ls::std::network::Socket::_init()
{
  #if defined(unix) || defined(__APPLE__)
  return this->_initUnix();
  #endif
}

#if defined(unix) || defined(__APPLE__)
bool ls::std::network::Socket::_initUnix()
{
  this->_setUnixSocketApi();
  ls::std::network::ConvertedProtocolFamily convertedProtocolFamily = ls::std::network::ProtocolFamilyMapper::from(this->parameter.protocolFamilyType);
  ls::std::network::Protocol protocol = ls::std::network::ProtocolMapper::from(this->parameter.socketAddress.protocolType);

  return this->parameter.posixSocket->create(convertedProtocolFamily.unixDomain, protocol.unixProtocol, 0) != -1;
}

bool ls::std::network::Socket::_listenUnix()
{
  return this->parameter.posixSocket->listen(this->unixDescriptor, this->parameter.queueSize) == 0;
}

void ls::std::network::Socket::_setUnixSocketApi()
{
  if (this->parameter.posixSocket == nullptr)
  {
    this->parameter.posixSocket = ::std::make_shared<ls::std::network::PosixSocket>();
  }
}
#endif
