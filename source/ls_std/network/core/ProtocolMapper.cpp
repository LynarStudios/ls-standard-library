/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-11-17
 * Changed:         2022-12-26
 *
 * */

#include <ls_std/os/specification.hpp>
#include <ls_std/network/core/ProtocolMapper.hpp>
#if LS_STD_UNIX_PLATFORM
#include <sys/socket.h>
#endif
#include <ls_std/core/exception/IllegalArgumentException.hpp>

ls::std::network::ProtocolMapper::ProtocolMapper() : ls::std::core::Class("ProtocolMapper")
{}

ls::std::network::Protocol ls::std::network::ProtocolMapper::from(const ls::std::network::ProtocolType &_protocolType)
{
  #if LS_STD_UNIX_PLATFORM
  return ls::std::network::ProtocolMapper::_toUnixProtocol(_protocolType);
  #endif
}

#if LS_STD_UNIX_PLATFORM
ls::std::network::Protocol ls::std::network::ProtocolMapper::_toUnixProtocol(const ls::std::network::ProtocolType &_protocolType)
{
  ls::std::network::Protocol protocol{};

  switch (_protocolType)
  {
    case ls::std::network::ProtocolType::PROTOCOL_TYPE_UDP:
    {
      protocol.unixProtocol = SOCK_DGRAM;
    } break;
    case ls::std::network::ProtocolType::PROTOCOL_TYPE_TCP:
    {
      protocol.unixProtocol = SOCK_STREAM;
    } break;
    case ls::std::network::ProtocolType::PROTOCOL_TYPE_NOT_INITIALIZED:
    {
      throw ls::std::core::IllegalArgumentException{};
    }
  }

  return protocol;
}
#endif
