/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-12-30
 * Changed:         2022-12-31
 *
 * */

#ifndef LS_STD_UNIX_SOCKET_DESCRIPTOR_HPP
#define LS_STD_UNIX_SOCKET_DESCRIPTOR_HPP

#include <ls_std/core/types/SocketTypes.hpp>

namespace ls::std::network
{
  class UnixSocketDescriptor
  {
    public:

      explicit UnixSocketDescriptor(const ls::std::core::type::connection_id& _connectionId, const int& _descriptor);
      ~UnixSocketDescriptor();

      bool operator () (const ls::std::network::UnixSocketDescriptor& _socketDescriptor) const;

      [[nodiscard]] ls::std::core::type::connection_id getConnectionId() const;
      [[nodiscard]] int getDescriptor() const;

    private:

      ls::std::core::type::connection_id connectionId{};
      int descriptor{};
  };
}

#endif
