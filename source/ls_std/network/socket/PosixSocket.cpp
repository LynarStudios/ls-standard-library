/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-12-09
 * Changed:         2022-12-09
 *
 * */

#include <ls_std/network/socket/PosixSocket.hpp>
#include <sys/socket.h>

int ls::std::network::PosixSocket::connect(int _socketFileDescriptor, const struct sockaddr *_address, socklen_t _addressLength)
{
  return ::connect(_socketFileDescriptor, _address, _addressLength);
}

int ls::std::network::PosixSocket::create(int _domain, int _type, int _protocol)
{
  return ::socket(_domain, _type, _protocol);
}
