/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-11-16
 * Changed:         2022-12-28
 *
 * */

#ifndef LS_STD_PROTOCOL_TYPE_HPP
#define LS_STD_PROTOCOL_TYPE_HPP

namespace ls::std::network
{
  enum ProtocolType
  {
    LS_STD_PROTOCOL_TYPE_NOT_INITIALIZED = 0,
    LS_STD_PROTOCOL_TYPE_UDP,
    LS_STD_PROTOCOL_TYPE_TCP
  };
}

#endif
