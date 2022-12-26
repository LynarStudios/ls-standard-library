/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-11-17
 * Changed:         2022-12-26
 *
 * */

#ifndef LS_STD_PROTOCOL_MAPPER_HPP
#define LS_STD_PROTOCOL_MAPPER_HPP

#include <ls_std/os/specification.hpp>
#include <ls_std/os/dynamic_goal.hpp>
#include <ls_std/core/Class.hpp>
#include "Protocol.hpp"
#include "ProtocolType.hpp"

namespace ls::std::network
{
  class LS_STD_DYNAMIC_GOAL ProtocolMapper : public ls::std::core::Class
  {
    public:

      ProtocolMapper();
      ~ProtocolMapper() override = default;

      [[nodiscard]] static ls::std::network::Protocol from(const ls::std::network::ProtocolType& _protocolType);

    private:

      #if LS_STD_UNIX_PLATFORM
      [[nodiscard]] static ls::std::network::Protocol _toUnixProtocol(const ls::std::network::ProtocolType& _protocolType);
      #endif
  };
}

#endif
