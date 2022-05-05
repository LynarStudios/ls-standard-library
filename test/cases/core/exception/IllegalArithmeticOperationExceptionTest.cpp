/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-05-01
 * Changed:         2022-05-05
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>

namespace
{
  class IllegalArithmeticOperationExceptionTest : public ::testing::Test
  {
    protected:

      IllegalArithmeticOperationExceptionTest() = default;
      ~IllegalArithmeticOperationExceptionTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(IllegalArithmeticOperationExceptionTest, constructor)
  {
    EXPECT_THROW({
                   try
                   {
                     throw ls::IllegalArithmeticOperationException{};
                   }
                   catch (const ls::IllegalArithmeticOperationException &_exception)
                   {
                     EXPECT_STREQ("IllegalArithmeticOperationException thrown - arithmetic operation is not allowed!", _exception.what());
                     throw;
                   }
                 }, ls::IllegalArithmeticOperationException);
  }
}
