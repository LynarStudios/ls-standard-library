/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-11-18
 * Changed:         2022-11-18
 *
 * */

#ifndef LS_STD_SOCKET_ADDRESS_MAPPER_HPP
#define LS_STD_SOCKET_ADDRESS_MAPPER_HPP

#include <ls_std/core/Class.hpp>
#include <ls_std/os/dynamic_goal.hpp>
#include "ConvertedSocketAddress.hpp"
#include "SocketAddressMapperParameter.hpp"
#if defined(unix) || defined(__APPLE__)
#include <netinet/in.h>
#endif

namespace ls::std::network
{
  class LS_STD_DYNAMIC_GOAL SocketAddressMapper : public ls::std::core::Class // TODO: does this make sense, since all methods are static
  {
    public:

      SocketAddressMapper();
      ~SocketAddressMapper() override = default;

      [[nodiscard]] static ls::std::network::ConvertedSocketAddress from(const ls::std::network::SocketAddressMapperParameter& _parameter);

    private:

      #if defined(unix) || defined(__APPLE__)
      [[nodiscard]] static ::sockaddr_in _toSockAddressUnix(const ls::std::network::SocketAddressMapperParameter& _parameter);
      #endif
  };
}

#endif
