/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-16
 * Changed:         2022-12-28
 *
 * */

#include <ls_std/ls_std_os.hpp>
#include <gtest/gtest.h>
#include <ls_std/ls_std_network.hpp>
#if LS_STD_UNIX_PLATFORM
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
    ConvertedProtocolFamily convertedProtocolFamily = ProtocolFamilyMapper::from(ProtocolFamilyType::LS_STD_PROTOCOL_FAMILY_TYPE_IPV4);

    #if LS_STD_UNIX_PLATFORM
    ASSERT_EQ(AF_INET, convertedProtocolFamily.unixDomain);
    #endif
  }

  TEST_F(ProtocolFamilyMapperTest, from_invalid_protocol_family_type)
  {
    EXPECT_THROW({
                   try
                   {
                     ConvertedProtocolFamily convertedProtocolFamily = ProtocolFamilyMapper::from(ProtocolFamilyType::LS_STD_PROTOCOL_FAMILY_TYPE_NOT_INITIALIZED);
                   }
                   catch (const IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, IllegalArgumentException);
  }
}
