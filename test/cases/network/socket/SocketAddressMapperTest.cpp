/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-18
 * Changed:         2022-12-31
 *
 * */

#include <ls_std/ls_std_os.hpp>
#include <gtest/gtest.h>
#include <ls_std/ls_std_network.hpp>

#if LS_STD_UNIX_PLATFORM
#include <sys/socket.h>
#include "ls_std/network/socket/Socket.hpp"
#endif

using namespace ls::std::network;

namespace
{
  class SocketAddressMapperTest : public ::testing::Test
  {
    protected:

      SocketAddressMapperTest() = default;
      ~SocketAddressMapperTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}

      static SocketAddressMapperParameter createSocketAddressMapperParameter()
      {
        SocketAddressMapperParameter parameter{};
        parameter.protocolFamilyType = ProtocolFamilyType::LS_STD_PROTOCOL_FAMILY_TYPE_IPV4;

        SocketAddress socketAddress{};
        socketAddress.port = 8080;
        socketAddress.protocolType = LS_STD_PROTOCOL_TYPE_TCP;
        socketAddress.ipAddress = "127.0.0.1";
        parameter.socketAddress = socketAddress;

        return parameter;
      }
  };

  TEST_F(SocketAddressMapperTest, getClassName)
  {
    ASSERT_STREQ("SocketAddressMapper", SocketAddressMapper{}.getClassName().c_str());
  }

  TEST_F(SocketAddressMapperTest, from)
  {
    ConvertedSocketAddress convertedSocketAddress = SocketAddressMapper::from(createSocketAddressMapperParameter());

    #if LS_STD_UNIX_PLATFORM
    ASSERT_EQ(36895, convertedSocketAddress.socketAddressUnix.sin_port); // expected: return value of htons()
    ASSERT_EQ(AF_INET, convertedSocketAddress.socketAddressUnix.sin_family);
    ASSERT_EQ(16777343, convertedSocketAddress.socketAddressUnix.sin_addr.s_addr); // expected: return value of inet_aton()
    ASSERT_EQ(16, convertedSocketAddress.addressLength);
    #endif
  }

  TEST_F(SocketAddressMapperTest, from_with_empty_address)
  {
    SocketAddressMapperParameter parameter = createSocketAddressMapperParameter();
    parameter.socketAddress.ipAddress = "";
    ConvertedSocketAddress convertedSocketAddress = SocketAddressMapper::from(parameter);

    #if LS_STD_UNIX_PLATFORM
    ASSERT_EQ(36895, convertedSocketAddress.socketAddressUnix.sin_port); // expected: return value of htons()
    ASSERT_EQ(AF_INET, convertedSocketAddress.socketAddressUnix.sin_family);
    ASSERT_EQ(INADDR_ANY, convertedSocketAddress.socketAddressUnix.sin_addr.s_addr); // expected: return value of inet_aton()
    ASSERT_EQ(16, convertedSocketAddress.addressLength);
    #endif
  }
}
