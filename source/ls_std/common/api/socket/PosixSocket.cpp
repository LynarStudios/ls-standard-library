/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-12-09
 * Changed:         2022-12-25
 *
 * */

#include <ls_std/common/api/socket/PosixSocket.hpp>
#include <sys/socket.h>
#include <unistd.h>

int ls::std::common::api::PosixSocket::accept(int _socketFileDescriptor, struct sockaddr *_address, socklen_t* _addressLength)
{
  return ::accept(_socketFileDescriptor, _address, _addressLength);
}

int ls::std::common::api::PosixSocket::bind(int _socketFileDescriptor, const struct sockaddr *_address, socklen_t _addressLength)
{
  return ::bind(_socketFileDescriptor, _address, _addressLength);
}

int ls::std::common::api::PosixSocket::close(int _socketFileDescriptor)
{
  return ::close(_socketFileDescriptor);
}

int ls::std::common::api::PosixSocket::connect(int _socketFileDescriptor, const struct sockaddr *_address, socklen_t _addressLength)
{
  return ::connect(_socketFileDescriptor, _address, _addressLength);
}

int ls::std::common::api::PosixSocket::create(int _domain, int _type, int _protocol)
{
  return ::socket(_domain, _type, _protocol);
}

int ls::std::common::api::PosixSocket::listen(int _socketFileDescriptor, int _backlog)
{
  return ::listen(_socketFileDescriptor, _backlog);
}
