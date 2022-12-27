/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-12-12
 * Changed:         2022-12-12
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std_core.hpp>

using namespace ls::std::core;

namespace
{
  class SocketOperationFailedExceptionTest : public ::testing::Test
  {
    protected:

      SocketOperationFailedExceptionTest() = default;
      ~SocketOperationFailedExceptionTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(SocketOperationFailedExceptionTest, constructor)
  {
    EXPECT_THROW({
                   try
                   {
                     throw SocketOperationFailedException{};
                   }
                   catch (const SocketOperationFailedException &_exception)
                   {
                     EXPECT_STREQ("SocketOperationFailedException thrown - operation on socket was not successful!", _exception.what());
                     throw;
                   }
                 }, SocketOperationFailedException);
  }
}
