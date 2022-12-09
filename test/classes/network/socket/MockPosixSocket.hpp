/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-12-09
 * Changed:         2022-12-09
 *
 * */

#ifndef LS_STD_MOCK_POSIX_SOCKET_HPP
#define LS_STD_MOCK_POSIX_SOCKET_HPP

#include <ls_std/ls_std_core.hpp>
#include <gmock/gmock.h>

namespace ls_std_network_test
{
  class MockPosixSocket : public ls::std::core::interface_type::IPosixSocket
  {
    public:

      MockPosixSocket() = default;
      ~MockPosixSocket() override = default;

      MOCK_METHOD(int, connect, (int _socketFileDescriptor, const struct sockaddr *_address, socklen_t _addressLength), (override));
      MOCK_METHOD(int, create, (int _domain, int _type, int _protocol), (override));
  };
}

#endif
