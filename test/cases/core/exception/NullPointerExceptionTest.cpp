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
                     throw ls::std::core::NullPointerException{};
                   }
                   catch (const ls::std::core::NullPointerException &_exception)
                   {
                     EXPECT_STREQ("NullPointerException thrown - reference is null!", _exception.what());
                     throw;
                   }
                 }, ls::std::core::NullPointerException);
  }
}
