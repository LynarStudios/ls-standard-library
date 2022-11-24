/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-18
 * Changed:         2022-11-18
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std_network.hpp>

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
  };

  TEST_F(SocketAddressMapperTest, getClassName)
  {
    ASSERT_STREQ("SocketAddressMapper", SocketAddressMapper{}.getClassName().c_str());
  }

  TEST_F(SocketAddressMapperTest, from)
  {
    SocketAddressMapperParameter parameter{};
    parameter.protocolFamilyType = ProtocolFamilyType::PROTOCOL_FAMILY_TYPE_IPV4;

    ConvertedSocketAddress convertedSocketAddress = SocketAddressMapper::from();
  }
}
