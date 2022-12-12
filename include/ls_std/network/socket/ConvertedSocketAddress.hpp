/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-11-18
 * Changed:         2022-12-12
 *
 * */

#ifndef LS_STD_CONVERTED_SOCKET_ADDRESS_HPP
#define LS_STD_CONVERTED_SOCKET_ADDRESS_HPP

#if defined(unix) || defined(__APPLE__)
#include <netinet/in.h>
#endif

namespace ls::std::network
{
  struct ConvertedSocketAddress
  {
    #if defined(unix) || defined(__APPLE__)
    ::sockaddr_in socketAddressUnix{};
    ::socklen_t addressLength{};
    #endif
  };
}

#endif
