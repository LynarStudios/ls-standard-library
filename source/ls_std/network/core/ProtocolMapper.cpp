/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-11-17
 * Changed:         2022-11-17
 *
 * */

#include <ls_std/network/core/ProtocolMapper.hpp>
#if defined(unix) || defined(__APPLE__)
#include <sys/socket.h>
#endif
#include <ls_std/core/exception/IllegalArgumentException.hpp>

ls::std::network::ProtocolMapper::ProtocolMapper() : ls::std::core::Class("ProtocolMapper")
{}

ls::std::network::Protocol ls::std::network::ProtocolMapper::from(const ls::std::network::ProtocolType &_protocolType)
{
  #if defined(unix) || defined(__APPLE__)
  return ls::std::network::ProtocolMapper::_toUnixProtocol(_protocolType);
  #endif
}

#if defined(unix) || defined(__APPLE__)
ls::std::network::Protocol ls::std::network::ProtocolMapper::_toUnixProtocol(const ls::std::network::ProtocolType &_protocolType)
{
  ls::std::network::Protocol protocol{};

  switch (_protocolType)
  {
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
