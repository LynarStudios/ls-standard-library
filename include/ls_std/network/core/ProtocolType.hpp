/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-11-16
 * Changed:         2022-11-16
 *
 * */

#ifndef LS_STD_PROTOCOL_TYPE_HPP
#define LS_STD_PROTOCOL_TYPE_HPP

namespace ls::std::network
{
  enum ProtocolType
  {
    PROTOCOL_TYPE_NOT_INITIALIZED = 0,
    PROTOCOL_TYPE_TCP
  };
}

#endif
