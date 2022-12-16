/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-11-16
 * Changed:         2022-12-16
 *
 * */

#include <ls_std/network/socket/Socket.hpp>
#include <ls_std/network/core/ProtocolFamilyMapper.hpp>
#include <ls_std/network/core/ProtocolMapper.hpp>
#include <ls_std/network/socket/ConvertedSocketAddress.hpp>
#include <ls_std/network/socket/SocketAddressMapper.hpp>
#include <ls_std/core/api/socket/PosixSocket.hpp>
#include <ls_std/core/api/io/PosixReader.hpp>
#include <ls_std/core/exception/WrongProtocolException.hpp>
#include <ls_std/core/exception/IllegalArgumentException.hpp>
#include <ls_std/core/exception/FileOperationException.hpp>
#include <memory>

ls::std::network::Socket::Socket(ls::std::network::SocketParameter _parameter) : ls::std::core::Class("Socket"),
parameter(::std::move(_parameter))
{
  #if defined(unix) || defined(__APPLE__)
  this->unixDescriptor = ls::std::network::Socket::_initUnix();
  this->initialized = this->unixDescriptor != -1;
  #endif
}

ls::std::network::Socket::~Socket()
{
  delete[] this->readBuffer;
}

ls::std::core::type::byte_field ls::std::network::Socket::read()
{
  if (!this->readBufferSet)
  {
    this->_initReadBuffer(); // TODO: is this really wise to initialize once? what if reading second time wouldn't work?
    this->readBufferSet = true;
  }

  return this->_read();
}

bool ls::std::network::Socket::accept()
{
  if (this->parameter.socketAddress.protocolType != PROTOCOL_TYPE_TCP)
  {
    throw ls::std::core::WrongProtocolException{};
  }

  #if defined(unix) || defined(__APPLE__)
  return ls::std::network::Socket::_acceptUnix();
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

bool ls::std::network::Socket::_acceptUnix()
{
  ls::std::network::ConvertedSocketAddress convertedSocketAddress = ls::std::network::SocketAddressMapper::from(ls::std::network::Socket::_createSocketAddressMapperParameter());
  return this->parameter.posixSocket->accept(this->unixDescriptor, reinterpret_cast<sockaddr *>(&convertedSocketAddress.socketAddressUnix), &convertedSocketAddress.addressLength) >= 0;
}

bool ls::std::network::Socket::_bindUnix()
{
  ls::std::network::ConvertedSocketAddress convertedSocketAddress = ls::std::network::SocketAddressMapper::from(ls::std::network::Socket::_createSocketAddressMapperParameter());
  return this->parameter.posixSocket->bind(this->unixDescriptor, reinterpret_cast<const sockaddr *>(&convertedSocketAddress.socketAddressUnix), convertedSocketAddress.addressLength) == 0;
}

bool ls::std::network::Socket::_closeUnix()
{
  return this->parameter.posixSocket->close(this->unixDescriptor) == 0;
}

bool ls::std::network::Socket::_connectUnix()
{
  ls::std::network::ConvertedSocketAddress convertedSocketAddress = ls::std::network::SocketAddressMapper::from(ls::std::network::Socket::_createSocketAddressMapperParameter());
  return this->parameter.posixSocket->connect(this->unixDescriptor, reinterpret_cast<const sockaddr *>(&convertedSocketAddress.socketAddressUnix), convertedSocketAddress.addressLength) == 0;
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

void ls::std::network::Socket::_initReadBuffer()
{
  if (this->parameter.readBufferSize <= 0)
  {
    throw ls::std::core::IllegalArgumentException{};
  }

  this->readBuffer = new ls::std::core::type::byte[this->parameter.readBufferSize];
}

#if defined(unix) || defined(__APPLE__)
bool ls::std::network::Socket::_initUnix()
{
  this->_setPosixReaderApi();
  this->_setUnixSocketApi(); // TODO: rename to _setPosixSocketApi
  ls::std::network::ConvertedProtocolFamily convertedProtocolFamily = ls::std::network::ProtocolFamilyMapper::from(this->parameter.protocolFamilyType);
  ls::std::network::Protocol protocol = ls::std::network::ProtocolMapper::from(this->parameter.socketAddress.protocolType);

  return this->parameter.posixSocket->create(convertedProtocolFamily.unixDomain, protocol.unixProtocol, 0) != -1;
}

bool ls::std::network::Socket::_listenUnix()
{
  return this->parameter.posixSocket->listen(this->unixDescriptor, this->parameter.queueSize) == 0;
}
#endif

ls::std::core::type::byte_field ls::std::network::Socket::_read()
{
  #if defined(unix) || defined(__APPLE__)
  return this->_readUnix();
  #endif
}

#if defined(unix) || defined(__APPLE__)
ls::std::core::type::byte_field ls::std::network::Socket::_readUnix()
{
  size_t size = this->parameter.posixReader->read(this->unixDescriptor, this->readBuffer, this->parameter.readBufferSize);

  if (size == -1)
  {
    throw ls::std::core::FileOperationException{};
  }

  return ls::std::core::type::byte_field{this->readBuffer, size};
}

void ls::std::network::Socket::_setPosixReaderApi()
{
  if (this->parameter.posixReader == nullptr)
  {
    this->parameter.posixReader = ::std::make_shared<ls::std::core::api::PosixReader>();
  }
}

void ls::std::network::Socket::_setUnixSocketApi()
{
  if (this->parameter.posixSocket == nullptr)
  {
    this->parameter.posixSocket = ::std::make_shared<ls::std::core::api::PosixSocket>();
  }
}
#endif
