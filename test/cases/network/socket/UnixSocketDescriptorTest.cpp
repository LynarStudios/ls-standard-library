/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-12-31
 * Changed:         2022-12-31
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std_network.hpp>

using namespace ls::std::network;

namespace
{
  class UnixSocketDescriptorTest : public ::testing::Test
  {
    protected:

      UnixSocketDescriptorTest() = default;
      ~UnixSocketDescriptorTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(UnixSocketDescriptorTest, getConnectionId)
  {
    UnixSocketDescriptor socketDescriptor{1, 14};
    ASSERT_EQ(1, socketDescriptor.getConnectionId());
  }

  TEST_F(UnixSocketDescriptorTest, getDescriptor)
  {
    UnixSocketDescriptor socketDescriptor{1, 14};
    ASSERT_EQ(14, socketDescriptor.getDescriptor());
  }
}
