/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-05-01
 * Changed:         2022-11-09
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std_core.hpp>

using namespace ls::std::core;

namespace
{
  class IllegalArgumentExceptionTest : public ::testing::Test
  {
    protected:

      IllegalArgumentExceptionTest() = default;
      ~IllegalArgumentExceptionTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(IllegalArgumentExceptionTest, constructor)
  {
    EXPECT_THROW({
                   try
                   {
                     throw IllegalArgumentException{};
                   }
                   catch (const IllegalArgumentException &_exception)
                   {
                     EXPECT_STREQ("IllegalArgumentException thrown - passed argument is not valid!", _exception.what());
                     throw;
                   }
                 }, IllegalArgumentException);
  }
}
