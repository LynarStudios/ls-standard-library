/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-12-09
 * Changed:         2022-12-12
 *
 * */

#include <ls_std/network/socket/PosixSocket.hpp>
#include <sys/socket.h>
#include <unistd.h>

int ls::std::network::PosixSocket::bind(int _socketFileDescriptor, const struct sockaddr *_address, socklen_t _addressLength)
{
  return ::bind(_socketFileDescriptor, _address, _addressLength);
}

int ls::std::network::PosixSocket::close(int _socketFileDescriptor)
{
  return ::close(_socketFileDescriptor);
}

int ls::std::network::PosixSocket::connect(int _socketFileDescriptor, const struct sockaddr *_address, socklen_t _addressLength)
{
  return ::connect(_socketFileDescriptor, _address, _addressLength);
}

int ls::std::network::PosixSocket::create(int _domain, int _type, int _protocol)
{
  return ::socket(_domain, _type, _protocol);
}

int ls::std::network::PosixSocket::listen(int _socketFileDescriptor, int _backlog)
{
  return ::listen(_socketFileDescriptor, _backlog);
}
