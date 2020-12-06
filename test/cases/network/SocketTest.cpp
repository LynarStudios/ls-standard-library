/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-06
 * Changed:         2020-12-06
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>

namespace {
  class SocketTest : public ::testing::Test {
    protected:

      SocketTest() = default;
      ~SocketTest() override = default;

      void SetUp() override {}
      void TearDown() override {}
  };

  TEST_F(SocketTest, create)
  {
    ls_std::Socket socket {};
    ASSERT_TRUE(socket.create(ls_std::ADDRESS_FAMILY_IP_V4, ls_std::SOCKET_TYPE_STREAM, ls_std::NETWORK_PROTOCOL_TCP_IP));
  }
}
