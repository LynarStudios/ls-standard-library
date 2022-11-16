/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-11-16
 * Changed:         2022-11-16
 *
 * */

#include <ls_std/network/core/ProtocolFamilyMapper.hpp>
#include <ls_std/core/exception/IllegalArgumentException.hpp>
#if defined(unix) || defined(__APPLE__)
#include <sys/socket.h>
#endif

ls::std::network::ProtocolFamilyMapper::ProtocolFamilyMapper() : ls::std::core::Class("ProtocolFamilyMapper")
{}

ls::std::network::ProtocolFamily ls::std::network::ProtocolFamilyMapper::from(const ls::std::network::ProtocolFamilyType &_protocolFamilyType)
{
  #if defined(unix) || defined(__APPLE__)
  return ls::std::network::ProtocolFamilyMapper::_toUnixProtocolFamily(_protocolFamilyType);
  #endif
}

#if defined(unix) || defined(__APPLE__)
ls::std::network::ProtocolFamily ls::std::network::ProtocolFamilyMapper::_toUnixProtocolFamily(const ls::std::network::ProtocolFamilyType &_protocolFamilyType)
{
  ls::std::network::ProtocolFamily protocolFamily{};

  switch(_protocolFamilyType)
  {
    case ls::std::network::ProtocolFamilyType::PROTOCOL_FAMILY_TYPE_IPV4:
    {
      protocolFamily.unixDomain = AF_INET;
    } break;
    case ls::std::network::ProtocolFamilyType::PROTOCOL_FAMILY_TYPE_NOT_INITIALIZED:
    {
      throw ls::std::core::IllegalArgumentException{};
    }
  }

  return protocolFamily;
}
#endif
