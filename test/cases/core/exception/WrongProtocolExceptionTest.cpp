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
  class WrongProtocolExceptionTest : public ::testing::Test
  {
    protected:

      WrongProtocolExceptionTest() = default;
      ~WrongProtocolExceptionTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(WrongProtocolExceptionTest, constructor)
  {
    EXPECT_THROW({
                   try
                   {
                     throw WrongProtocolException{};
                   }
                   catch (const WrongProtocolException &_exception)
                   {
                     EXPECT_STREQ("WrongProtocolException thrown - the available protocol is not valid for this operation!", _exception.what());
                     throw;
                   }
                 }, WrongProtocolException);
  }
}
