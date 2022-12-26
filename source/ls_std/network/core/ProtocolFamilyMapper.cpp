/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-11-16
 * Changed:         2022-12-26
 *
 * */

#include <ls_std/os/specification.hpp>
#include <ls_std/network/core/ProtocolFamilyMapper.hpp>
#include <ls_std/core/exception/IllegalArgumentException.hpp>
#if LS_STD_UNIX_PLATFORM
#include <sys/socket.h>
#endif

ls::std::network::ProtocolFamilyMapper::ProtocolFamilyMapper() : ls::std::core::Class("ProtocolFamilyMapper")
{}

ls::std::network::ConvertedProtocolFamily ls::std::network::ProtocolFamilyMapper::from(const ls::std::network::ProtocolFamilyType &_protocolFamilyType)
{
  #if LS_STD_UNIX_PLATFORM
  return ls::std::network::ProtocolFamilyMapper::_toUnixProtocolFamily(_protocolFamilyType);
  #endif
}

#if LS_STD_UNIX_PLATFORM
ls::std::network::ConvertedProtocolFamily ls::std::network::ProtocolFamilyMapper::_toUnixProtocolFamily(const ls::std::network::ProtocolFamilyType &_protocolFamilyType)
{
  ls::std::network::ConvertedProtocolFamily convertedProtocolFamily{};

  switch(_protocolFamilyType)
  {
    case ls::std::network::ProtocolFamilyType::PROTOCOL_FAMILY_TYPE_IPV4:
    {
      convertedProtocolFamily.unixDomain = AF_INET;
    } break;
    case ls::std::network::ProtocolFamilyType::PROTOCOL_FAMILY_TYPE_NOT_INITIALIZED:
    {
      throw ls::std::core::IllegalArgumentException{};
    }
  }

  return convertedProtocolFamily;
}
#endif
