/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-06
 * Changed:         2020-12-06
 *
 * */

#ifndef LS_STD_SOCKET_HPP
#define LS_STD_SOCKET_HPP

#include <ls_std/base/Class.hpp>
#include "AddressFamily.hpp"
#include "SocketType.hpp"
#include "NetworkProtocol.hpp"

#if defined(unix) || defined(__APPLE__)
#include <sys/types.h>
#include <sys/socket.h>
#endif

namespace ls_std {
  class Socket : public ls_std::Class {
    public:

      Socket();
      ~Socket() override = default;

      bool create(ls_std::AddressFamily _addressFamily, ls_std::SocketType _socketType, ls_std::NetworkProtocol _protocol);

    private:

      #if defined(unix) || defined(__APPLE__)
        int descriptor {};
      #endif

      static int _convertAddressFamily(ls_std::AddressFamily _addressFamily);
      static int _convertNetworkProtocol(ls_std::NetworkProtocol _networkProtocol);
      static int _convertSocketType(ls_std::SocketType _socketType);

      #if defined(unix) || defined(__APPLE__)
        static int _create(ls_std::AddressFamily _addressFamily, ls_std::SocketType _socketType, ls_std::NetworkProtocol _networkProtocol);
      #endif
  };
}

#endif
