/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-05-01
 * Changed:         2022-05-13
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std_core.hpp>

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
                     throw ls::std::core::IllegalArgumentException{};
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     EXPECT_STREQ("IllegalArgumentException thrown - passed argument is not valid!", _exception.what());
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }
}
