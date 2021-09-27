/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-05-01
 * Changed:         2021-05-01
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>

namespace
{
  class NullPointerExceptionTest : public ::testing::Test
  {
    protected:

      NullPointerExceptionTest() = default;
      ~NullPointerExceptionTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(NullPointerExceptionTest, constructor)
  {
    EXPECT_THROW({
                   try
                   {
                     throw ls_std::NullPointerException{};
                   }
                   catch (const ls_std::NullPointerException &_exception)
                   {
                     EXPECT_STREQ("NullPointerException thrown - reference is null!", _exception.what());
                     throw;
                   }
                 }, ls_std::NullPointerException);
  }
}
