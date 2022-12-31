/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-12-30
 * Changed:         2022-12-31
 *
 * */

#include <ls_std/network/socket/UnixSocketDescriptor.hpp>

ls::std::network::UnixSocketDescriptor::UnixSocketDescriptor(const ls::std::core::type::connection_id& _connectionId, const int& _descriptor) :
connectionId(_connectionId),
descriptor(_descriptor)
{}

ls::std::network::UnixSocketDescriptor::~UnixSocketDescriptor()
= default;

bool ls::std::network::UnixSocketDescriptor::operator()(const ls::std::network::UnixSocketDescriptor &_socketDescriptor) const
{
  return _socketDescriptor.getConnectionId() == this->connectionId;
}

ls::std::core::type::connection_id ls::std::network::UnixSocketDescriptor::getConnectionId() const
{
  return this->connectionId;
}

int ls::std::network::UnixSocketDescriptor::getDescriptor() const
{
  return this->descriptor;
}
