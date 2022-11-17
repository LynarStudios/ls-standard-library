/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-17
 * Changed:         2022-11-17
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
  class ProtocolMapperTest : public ::testing::Test
  {
    protected:

      ProtocolMapperTest() = default;
      ~ProtocolMapperTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(ProtocolMapperTest, getClassName)
  {
    ASSERT_STREQ("ProtocolMapper", ProtocolMapper{}.getClassName().c_str());
  }

  TEST_F(ProtocolMapperTest, from)
  {
    Protocol protocol = ProtocolMapper::from(ProtocolType::PROTOCOL_TYPE_TCP);

    #if defined(unix) || defined(__APPLE__)
    ASSERT_EQ(SOCK_STREAM, protocol.unixProtocol);
    #endif
  }

  TEST_F(ProtocolMapperTest, from_invalid_protocol_type)
  {
    EXPECT_THROW({
                   try
                   {
                     Protocol protocol = ProtocolMapper::from(ProtocolType::PROTOCOL_TYPE_NOT_INITIALIZED);
                   }
                   catch (const IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, IllegalArgumentException);
  }
}
