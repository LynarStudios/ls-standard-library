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
  class IncompleteJsonExceptionTest : public ::testing::Test
  {
    protected:

      IncompleteJsonExceptionTest() = default;
      ~IncompleteJsonExceptionTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(IncompleteJsonExceptionTest, constructor)
  {
    EXPECT_THROW({
                   try
                   {
                     throw IncompleteJsonException{};
                   }
                   catch (const IncompleteJsonException &_exception)
                   {
                     EXPECT_STREQ("IncompleteJsonException thrown - this JSON string is incomplete.", _exception.what());
                     throw;
                   }
                 }, IncompleteJsonException);
  }
}
