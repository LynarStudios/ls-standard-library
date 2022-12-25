/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-12-09
 * Changed:         2022-12-25
 *
 * */

#ifndef LS_STD_MOCK_POSIX_SOCKET_HPP
#define LS_STD_MOCK_POSIX_SOCKET_HPP

#include <ls_std/ls_std_common.hpp>
#include <gmock/gmock.h>

namespace ls_std_core_test
{
  class MockPosixSocket : public ls::std::common::interface_type::IPosixSocket // TODO: move to "common" module
  {
    public:

      MockPosixSocket() = default;
      ~MockPosixSocket() override = default;

      MOCK_METHOD(int, accept, (int _socketFileDescriptor, struct sockaddr *_address, socklen_t* _addressLength), (override));
      MOCK_METHOD(int, bind, (int _socketFileDescriptor, const struct sockaddr *_address, socklen_t _addressLength), (override));
      MOCK_METHOD(int, close, (int _socketFileDescriptor), (override));
      MOCK_METHOD(int, connect, (int _socketFileDescriptor, const struct sockaddr *_address, socklen_t _addressLength), (override));
      MOCK_METHOD(int, create, (int _domain, int _type, int _protocol), (override));
      MOCK_METHOD(int, listen, (int _socketFileDescriptor, int _backlog), (override));
  };
}

#endif
