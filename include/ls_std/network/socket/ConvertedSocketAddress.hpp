/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-11-18
 * Changed:         2022-12-26
 *
 * */

#ifndef LS_STD_CONVERTED_SOCKET_ADDRESS_HPP
#define LS_STD_CONVERTED_SOCKET_ADDRESS_HPP

#include <ls_std/os/specification.hpp>

#if LS_STD_UNIX_PLATFORM
#include <netinet/in.h>
#endif

namespace ls::std::network
{
  struct ConvertedSocketAddress
  {
    #if LS_STD_UNIX_PLATFORM
    ::sockaddr_in socketAddressUnix{};
    ::socklen_t addressLength{};
    #endif
  };
}

#endif
