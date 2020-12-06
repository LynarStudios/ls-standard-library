/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-06
 * Changed:         2020-12-06
 *
 * */

#include <ls_std/network/Socket.hpp>

#if defined(unix) || defined(__APPLE__)
#include <sys/socket.h>
#include <resolv.h>
#include <unistd.h>
#endif
#ifdef _WIN32
#include <http.h>
#endif

ls_std::Socket::Socket() : ls_std::Class("Socket")
{}

bool ls_std::Socket::close() const
{
  bool closed;

  #if defined(unix) || defined(__APPLE__)
    int result = ::close(this->descriptor);
    closed = result == 0;
  #endif

  return closed;
}

bool ls_std::Socket::create(ls_std::AddressFamily _addressFamily, ls_std::SocketType _socketType, ls_std::NetworkProtocol _networkProtocol)
{
  bool created;

  #if defined(unix) || defined(__APPLE__)
    this->descriptor = ls_std::Socket::_create(_addressFamily, _socketType, _networkProtocol);
    created = this->descriptor >= 0;
  #endif
  #ifdef _WIN32
    this->descriptor = ls_std::Socket::_create(_addressFamily, _socketType, _networkProtocol);
    created = this->descriptor >= 0;
  #endif

  return created;
}

int ls_std::Socket::_convertAddressFamily(ls_std::AddressFamily _addressFamily)
{
  int addressFamily;

  switch(_addressFamily)
  {
    case ls_std::ADDRESS_FAMILY_IP_V4:
    {
      addressFamily = AF_INET;
    } break;
    case ls_std::ADDRESS_FAMILY_IP_V6:
    {
      addressFamily = AF_INET6;
    } break;
  }

  return addressFamily;
}

int ls_std::Socket::_convertNetworkProtocol(ls_std::NetworkProtocol _networkProtocol)
{
  int networkProtocol;

  switch(_networkProtocol)
  {
    case ls_std::NETWORK_PROTOCOL_TCP_IP:
    {
      networkProtocol = IPPROTO_TCP;
    } break;
    case ls_std::NETWORK_PROTOCOL_UDP_IP:
    {
      networkProtocol = IPPROTO_UDP;
    } break;
  }

  return networkProtocol;
}

int ls_std::Socket::_convertSocketType(ls_std::SocketType _socketType)
{
  int socketType;

  switch(_socketType)
  {
    case ls_std::SOCKET_TYPE_STREAM:
    {
      socketType = SOCK_STREAM;
    } break;
    case ls_std::SOCKET_TYPE_DATAGRAM:
    {
      socketType = SOCK_DGRAM;
    } break;
  }

  return socketType;
}

#if defined(unix) || defined(__APPLE__)
  int ls_std::Socket::_create(ls_std::AddressFamily _addressFamily, ls_std::SocketType _socketType, ls_std::NetworkProtocol _networkProtocol)
  {
    int addressFamily = ls_std::Socket::_convertAddressFamily(_addressFamily);
    int socketType = ls_std::Socket::_convertSocketType(_socketType);
    int networkProtocol = ls_std::Socket::_convertNetworkProtocol(_networkProtocol);

    return socket(addressFamily, socketType, networkProtocol);
  }
#endif

#ifdef _WIN32
  SOCKET ls_std::Socket::_create(ls_std::AddressFamily _addressFamily, ls_std::SocketType _socketType, ls_std::NetworkProtocol _networkProtocol)
  {
    int addressFamily = ls_std::Socket::_convertAddressFamily(_addressFamily);
    int socketType = ls_std::Socket::_convertSocketType(_socketType);
    int networkProtocol = ls_std::Socket::_convertNetworkProtocol(_networkProtocol);

    return socket(addressFamily, socketType, networkProtocol);
  }
#endif
