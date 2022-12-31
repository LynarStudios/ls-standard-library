/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-27
 * Changed:         2022-12-28
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std_network.hpp>

using namespace ls::std::network;
using namespace ::std;

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

  TEST_F(SocketIT, local_server_bind)
  {
    // SERVER: create parameter

    SocketParameter serverParameter{};
    serverParameter.protocolFamilyType = LS_STD_PROTOCOL_FAMILY_TYPE_IPV4;
    serverParameter.socketAddress.protocolType = LS_STD_PROTOCOL_TYPE_TCP;
    serverParameter.socketAddress.port = 5099;
    serverParameter.queueSize = 5;

    // SERVER: bind

    Socket serverSocket{serverParameter};
    ASSERT_TRUE(serverSocket.bind());

    ASSERT_TRUE(serverSocket.close());
  }
}
