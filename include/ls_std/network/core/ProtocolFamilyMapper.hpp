/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-11-16
 * Changed:         2022-12-09
 *
 * */

#ifndef LS_STD_PROTOCOL_FAMILY_MAPPER_HPP
#define LS_STD_PROTOCOL_FAMILY_MAPPER_HPP

#include <ls_std/core/Class.hpp>
#include <ls_std/network/core/ConvertedProtocolFamily.hpp>
#include <ls_std/network/core/ProtocolFamilyType.hpp>
#include <ls_std/os/dynamic_goal.hpp>

namespace ls::std::network
{
  class LS_STD_DYNAMIC_GOAL ProtocolFamilyMapper : public ls::std::core::Class
  {
    public:

      ProtocolFamilyMapper();
      ~ProtocolFamilyMapper() override = default;

      [[nodiscard]] static ls::std::network::ConvertedProtocolFamily from(const ls::std::network::ProtocolFamilyType& _protocolFamilyType);

    private:

      #if defined(unix) || defined(__APPLE__)
      [[nodiscard]] static ls::std::network::ConvertedProtocolFamily _toUnixProtocolFamily(const ls::std::network::ProtocolFamilyType& _protocolFamilyType);
      #endif
  };
}

#endif
