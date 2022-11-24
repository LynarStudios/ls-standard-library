/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-11-18
 * Changed:         2022-11-18
 *
 * */

#ifndef LS_STD_SOCKET_ADDRESS_MAPPER_PARAMETER_HPP
#define LS_STD_SOCKET_ADDRESS_MAPPER_PARAMETER_HPP

#include "SocketAddress.hpp"
#include <ls_std/network/core/ProtocolFamilyType.hpp>

namespace ls::std::network
{
  struct SocketAddressMapperParameter
  {
    ls::std::network::SocketAddress socketAddress{};
    ls::std::network::ProtocolFamilyType protocolFamilyType{};
  };
}

#endif
