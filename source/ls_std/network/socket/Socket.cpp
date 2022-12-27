/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-11-16
 * Changed:         2022-12-27
 *
 * */

#include <ls_std/os/specification.hpp>
#include <ls_std/network/socket/Socket.hpp>
#include <ls_std/network/core/ProtocolFamilyMapper.hpp>
#include <ls_std/network/core/ProtocolMapper.hpp>
#include <ls_std/network/socket/ConvertedSocketAddress.hpp>
#include <ls_std/network/socket/SocketAddressMapper.hpp>
#include <ls_std/common/api/socket/PosixSocket.hpp>
#include <ls_std/common/api/io/PosixReader.hpp>
#include <ls_std/common/api/io/PosixWriter.hpp>
#include <ls_std/core/exception/WrongProtocolException.hpp>
#include <ls_std/core/exception/IllegalArgumentException.hpp>
#include <ls_std/core/exception/FileOperationException.hpp>
#include <memory>
#include <ls_std/core/exception/SocketOperationFailedException.hpp>
#include <iostream>

ls::std::network::Socket::Socket(ls::std::network::SocketParameter _parameter) : ls::std::core::Class("Socket"),
parameter(::std::move(_parameter))
{
  this->_init();
}

ls::std::network::Socket::~Socket()
{
  delete[] this->readBuffer;

  #if LS_STD_UNIX_PLATFORM
  for (const auto& connection : this->unixAcceptDescriptors)
  {
    if (!this->_closeUnix(connection.second))
    {
      ::std::cerr << "could not close socket with id \"" << connection.first << "\"" << ::std::endl;
    }
  }

  if (!this->_closeUnix(this->unixDescriptor))
  {
    ::std::cerr << "could not close socket with descriptor \"" << this->unixDescriptor << "\"" << ::std::endl;
  }
  #endif
}

ls::std::core::type::byte_field ls::std::network::Socket::read()
{
  if (!this->readBufferSet)
  {
    this->_initReadBuffer(); // TODO: is this really wise to initialize once? what if reading second time wouldn't work? - test it with unit tests and remove it
    this->readBufferSet = true;
  }

  return this->_read();
}

bool ls::std::network::Socket::write(const ls::std::core::type::byte_field &_data)
{
  return this->_write(_data);
}

ls::std::core::type::connection_id ls::std::network::Socket::accept()
{
  if (this->parameter.socketAddress.protocolType != PROTOCOL_TYPE_TCP)
  {
    throw ls::std::core::WrongProtocolException{};
  }

  #if LS_STD_UNIX_PLATFORM
  return ls::std::network::Socket::_acceptUnix();
  #endif
}

bool ls::std::network::Socket::bind()
{
  #if LS_STD_UNIX_PLATFORM
  return ls::std::network::Socket::_bindUnix();
  #endif
}

bool ls::std::network::Socket::close()
{
  return this->_close();
}

bool ls::std::network::Socket::connect()
{
  #if LS_STD_UNIX_PLATFORM
  return ls::std::network::Socket::_connectUnix();
  #endif
}

bool ls::std::network::Socket::handle(const ls::std::core::type::connection_id &_acceptedConnectionId)
{
  bool focusSet{};

  if (this->_hasAcceptedConnection(_acceptedConnectionId))
  {
    this->currentAcceptedConnection = _acceptedConnectionId;
    focusSet = true;
  }

  return focusSet;
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

  #if LS_STD_UNIX_PLATFORM
  return ls::std::network::Socket::_listenUnix();
  #endif
}

#if LS_STD_UNIX_PLATFORM
ls::std::core::type::connection_id ls::std::network::Socket::_acceptUnix()
{
  ::sockaddr_in incoming{};
  ::socklen_t length{};
  ls::std::core::type::connection_id acceptedDescriptor = this->parameter.posixSocket->accept(this->unixDescriptor, reinterpret_cast<sockaddr *>(&incoming), &length);

  if (acceptedDescriptor >= 0)
  {
    ++this->unixUniqueDescriptorId;
    this->unixAcceptDescriptors.insert({this->unixUniqueDescriptorId, acceptedDescriptor});
  }
  else
  {
    throw ls::std::core::SocketOperationFailedException{};
  }

  return this->unixUniqueDescriptorId;
}

bool ls::std::network::Socket::_bindUnix()
{
  ls::std::network::ConvertedSocketAddress convertedSocketAddress = ls::std::network::SocketAddressMapper::from(ls::std::network::Socket::_createSocketAddressMapperParameter());
  return this->parameter.posixSocket->bind(this->unixDescriptor, reinterpret_cast<const sockaddr *>(&convertedSocketAddress.socketAddressUnix), convertedSocketAddress.addressLength) == 0;
}
#endif

bool ls::std::network::Socket::_close()
{
  #if LS_STD_UNIX_PLATFORM
  return ls::std::network::Socket::_closeUnix(this->unixDescriptor);
  #endif
}

#if LS_STD_UNIX_PLATFORM
bool ls::std::network::Socket::_closeUnix(const int& _descriptor)
{
  return this->parameter.posixSocket->close(_descriptor) == 0;
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

bool ls::std::network::Socket::_hasAcceptedConnection(const ls::std::core::type::connection_id &_connectionId)
{
  #if LS_STD_UNIX_PLATFORM
  return this->_hasAcceptedConnectionUnix(_connectionId);
  #endif
}

#if LS_STD_UNIX_PLATFORM
bool ls::std::network::Socket::_hasAcceptedConnectionUnix(const ls::std::core::type::connection_id &_connectionId)
{
  return this->unixAcceptDescriptors.find(_connectionId) != this->unixAcceptDescriptors.end();
}
#endif

void ls::std::network::Socket::_init()
{
  #if LS_STD_UNIX_PLATFORM
  this->initialized = ls::std::network::Socket::_initUnix();
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

#if LS_STD_UNIX_PLATFORM
bool ls::std::network::Socket::_initUnix()
{
  this->_setPosixReaderApi();
  this->_setPosixSocketApi();
  this->_setPosixWriterApi();
  ls::std::network::ConvertedProtocolFamily convertedProtocolFamily = ls::std::network::ProtocolFamilyMapper::from(this->parameter.protocolFamilyType);
  ls::std::network::Protocol protocol = ls::std::network::ProtocolMapper::from(this->parameter.socketAddress.protocolType);
  this->unixDescriptor = this->parameter.posixSocket->create(convertedProtocolFamily.unixDomain, protocol.unixProtocol, 0);

  return this->unixDescriptor != -1;
}

bool ls::std::network::Socket::_listenUnix()
{
  return this->parameter.posixSocket->listen(this->unixDescriptor, this->parameter.queueSize) == 0;
}
#endif

ls::std::core::type::byte_field ls::std::network::Socket::_read()
{
  #if LS_STD_UNIX_PLATFORM
  return this->_readUnix();
  #endif
}

#if LS_STD_UNIX_PLATFORM
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
    this->parameter.posixReader = ::std::make_shared<ls::std::common::api::PosixReader>();
  }
}

void ls::std::network::Socket::_setPosixSocketApi()
{
  if (this->parameter.posixSocket == nullptr)
  {
    this->parameter.posixSocket = ::std::make_shared<ls::std::common::api::PosixSocket>();
  }
}

void ls::std::network::Socket::_setPosixWriterApi()
{
  if (this->parameter.posixWriter == nullptr)
  {
    this->parameter.posixWriter = ::std::make_shared<ls::std::common::api::PosixWriter>();
  }
}
#endif

bool ls::std::network::Socket::_write(const ls::std::core::type::byte_field &_data)
{
  #if LS_STD_UNIX_PLATFORM
  return this->_writeUnix(_data);
  #endif
}

#if LS_STD_UNIX_PLATFORM
bool ls::std::network::Socket::_writeUnix(const ls::std::core::type::byte_field &_data)
{
  bool written{};

  if (!_data.empty())
  {
    size_t size = _data.size() + 1;
    char* buffer = new char[size];
    ::std::strcpy(buffer, _data.c_str());

    written = this->parameter.posixWriter->write(this->unixDescriptor, buffer, size) != -1;

    delete[] buffer;
  }

  return written;
}
#endif
