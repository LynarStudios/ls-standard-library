/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-27
 * Changed:         2022-12-27
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std_network.hpp>

using namespace ls::std::network;

namespace
{
  class SocketIT : public ::testing::Test
  {
    protected:

      SocketIT() = default;
      ~SocketIT() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(SocketIT, local_server_client)
  {
    // create server parameter

    SocketParameter serverParameter{};
    serverParameter.protocolFamilyType = PROTOCOL_FAMILY_TYPE_IPV4; // TODO: add library prefix to constant value
    serverParameter.socketAddress.protocolType = PROTOCOL_TYPE_TCP; // TODO: add library prefix to constant value
    serverParameter.socketAddress.port = 5099;
    serverParameter.queueSize = 5;

    // create client parameter

    SocketParameter clientParameter{};
    clientParameter.protocolFamilyType = PROTOCOL_FAMILY_TYPE_IPV4;
    clientParameter.socketAddress.protocolType = PROTOCOL_TYPE_TCP;
    clientParameter.socketAddress.ipAddress = "127.0.0.1";
    clientParameter.socketAddress.port = 5099;

    // start server

    Socket serverSocket{serverParameter};

    ASSERT_TRUE(serverSocket.bind());
    ASSERT_TRUE(serverSocket.listen());

    // start client

    Socket clientSocket{clientParameter};

    ASSERT_TRUE(clientSocket.connect());

    // close sockets

    ASSERT_TRUE(clientSocket.close());
    ASSERT_TRUE(serverSocket.close());
  }
}
