/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-16
 * Changed:         2022-11-17
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std_network.hpp>

using namespace ls::std::network;

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
        socketParameter.socketAddress = socketAddress;

        return socketParameter;
      }
  };

  TEST_F(SocketTest, getClassName)
  {
    ASSERT_STREQ("Socket", Socket{generateSocketParameter()}.getClassName().c_str());
  }

  TEST_F(SocketTest, isInitialized)
  {
    Socket socket{generateSocketParameter()};
    ASSERT_TRUE(socket.isInitialized());
  }
}
