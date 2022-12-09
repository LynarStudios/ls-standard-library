/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-12-09
 * Changed:         2022-12-09
 *
 * */

#ifndef LS_STD_I_POSIX_SOCKET_HPP
#define LS_STD_I_POSIX_SOCKET_HPP

#include <sys/socket.h>

namespace ls::std::core::interface_type
{
  class IPosixSocket
  {
    public:

      virtual ~IPosixSocket() = default;

      virtual int connect(int _socketFileDescriptor, const struct sockaddr* _address, socklen_t _addressLength) = 0;
      virtual int create(int _domain, int _type, int _protocol) = 0; // constructor
  };
}

#endif
