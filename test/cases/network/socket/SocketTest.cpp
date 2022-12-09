/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-16
 * Changed:         2022-12-09
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std_network.hpp>
#include <ls_std_network_test.hpp>

using namespace ls::std::network;
using namespace ::testing;
using namespace ls_std_network_test;

namespace
{
  class SocketTest : public ::testing::Test
  {
    protected:

      SocketTest() = default;
      ~SocketTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}

      static SocketParameter generateSocketParameter()
      {
        SocketParameter socketParameter{};
        socketParameter.protocolFamilyType = ProtocolFamilyType::PROTOCOL_FAMILY_TYPE_IPV4;

        SocketAddress socketAddress{};
        socketAddress.protocolType = ProtocolType::PROTOCOL_TYPE_TCP;
        socketAddress.ipAddress = "127.0.0.1";
        socketAddress.port = 2220;
        socketParameter.socketAddress = socketAddress;

        return socketParameter;
      }
  };

  TEST_F(SocketTest, getClassName)
  {
    ASSERT_STREQ("Socket", Socket{generateSocketParameter()}.getClassName().c_str());
  }

  TEST_F(SocketTest, connect)
  {
    #if defined(unix) || defined(__APPLE__)
    MockPosixSocket mockPosixSocket{};
    EXPECT_CALL(mockPosixSocket, connect(_, _, _)).Times(1);
    ON_CALL(mockPosixSocket, connect(_, _, _)).WillByDefault(Return(true));
    #endif

    Socket socket{generateSocketParameter()};
    ASSERT_TRUE(socket.connect());
  }

  TEST_F(SocketTest, isInitialized)
  {
    Socket socket{generateSocketParameter()};
    ASSERT_TRUE(socket.isInitialized());
  }
}
