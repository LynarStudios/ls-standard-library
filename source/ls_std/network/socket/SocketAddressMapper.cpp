/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-11-18
 * Changed:         2022-12-26
 *
 * */

#include <ls_std/os/specification.hpp>
#include <ls_std/network/socket/SocketAddressMapper.hpp>
#include <ls_std/network/core/ConvertedProtocolFamily.hpp>
#include <ls_std/network/core/ProtocolFamilyMapper.hpp>
#if LS_STD_UNIX_PLATFORM
#include <netinet/in.h>
#include <arpa/inet.h>
#endif

ls::std::network::SocketAddressMapper::SocketAddressMapper() : ls::std::core::Class("SocketAddressMapper")
{}

ls::std::network::ConvertedSocketAddress ls::std::network::SocketAddressMapper::from(const ls::std::network::SocketAddressMapperParameter &_parameter)
{
  ls::std::network::ConvertedSocketAddress convertedSocketAddress{};

  #if LS_STD_UNIX_PLATFORM
  convertedSocketAddress.socketAddressUnix = ls::std::network::SocketAddressMapper::_toSockAddressUnix(_parameter);
  convertedSocketAddress.addressLength = sizeof(convertedSocketAddress.socketAddressUnix);
  #endif

  return convertedSocketAddress;
}

#if LS_STD_UNIX_PLATFORM
::sockaddr_in ls::std::network::SocketAddressMapper::_toSockAddressUnix(const ls::std::network::SocketAddressMapperParameter &_parameter)
{
  ::sockaddr_in socketAddressUnix{};
  socketAddressUnix.sin_port = ::htons(_parameter.socketAddress.port);

  ls::std::network::ConvertedProtocolFamily convertedProtocolFamily = ls::std::network::ProtocolFamilyMapper::from(_parameter.protocolFamilyType);
  socketAddressUnix.sin_family = convertedProtocolFamily.unixDomain;

  if (!_parameter.socketAddress.ipAddress.empty())
  {
    ::inet_aton(_parameter.socketAddress.ipAddress.c_str(), &socketAddressUnix.sin_addr);
  }
  else
  {
    socketAddressUnix.sin_addr.s_addr = INADDR_ANY;
  }

  return socketAddressUnix;
}
#endif
