/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-11-16
 * Changed:         2022-11-16
 *
 * */

#ifndef LS_STD_PROTOCOL_FAMILY_MAPPER_HPP
#define LS_STD_PROTOCOL_FAMILY_MAPPER_HPP

#include <ls_std/core/Class.hpp>
#include <ls_std/network/core/ProtocolFamily.hpp>
#include <ls_std/network/core/ProtocolFamilyType.hpp>

namespace ls::std::network
{
  class ProtocolFamilyMapper : public ls::std::core::Class
  {
    public:

      ProtocolFamilyMapper();
      ~ProtocolFamilyMapper() override = default;

      [[nodiscard]] static ls::std::network::ProtocolFamily from(const ls::std::network::ProtocolFamilyType& _protocolFamilyType);

    private:

      [[nodiscard]] static ls::std::network::ProtocolFamily _toUnixProtocolFamily(const ls::std::network::ProtocolFamilyType& _protocolFamilyType);
  };
}

#endif
