/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-12-09
 * Changed:         2022-12-09
 *
 * */

#ifndef LS_STD_POSIX_SOCKET_HPP
#define LS_STD_POSIX_SOCKET_HPP

#include <ls_std/core/interface/IPosixSocket.hpp>

namespace ls::std::network
{
  class PosixSocket : public ls::std::core::interface_type::IPosixSocket
  {
    public:

      PosixSocket() = default;
      ~PosixSocket() override = default;

      int connect(int _socketFileDescriptor, const struct sockaddr *_address, socklen_t _addressLength) override;
      int create(int _domain, int _type, int _protocol) override;
  };
}

#endif
