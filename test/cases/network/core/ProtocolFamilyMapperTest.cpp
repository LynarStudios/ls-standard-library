/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-16
 * Changed:         2022-11-16
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std_network.hpp>
#if defined(unix) || defined(__APPLE__)
#include <sys/socket.h>
#endif
#include <ls_std/ls_std_core.hpp>

using namespace ls::std::network;
using namespace ls::std::core;

namespace
{
  class ProtocolFamilyMapperTest : public ::testing::Test
  {
    protected:

      ProtocolFamilyMapperTest() = default;
      ~ProtocolFamilyMapperTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(ProtocolFamilyMapperTest, getClassName)
  {
    ASSERT_STREQ("ProtocolFamilyMapper", ProtocolFamilyMapper{}.getClassName().c_str());
  }

  TEST_F(ProtocolFamilyMapperTest, from)
  {
    ProtocolFamily protocolFamily = ProtocolFamilyMapper::from(ProtocolFamilyType::PROTOCOL_FAMILY_TYPE_IPV4);

    #if defined(unix) || defined(__APPLE__)
    ASSERT_EQ(AF_INET, protocolFamily.unixDomain);
    #endif
  }

  TEST_F(ProtocolFamilyMapperTest, from_invalid_protocol_type)
  {
    EXPECT_THROW({
                   try
                   {
                     ProtocolFamily protocolFamily = ProtocolFamilyMapper::from(ProtocolFamilyType::PROTOCOL_FAMILY_TYPE_NOT_INITIALIZED);
                   }
                   catch (const IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, IllegalArgumentException);
  }
}
