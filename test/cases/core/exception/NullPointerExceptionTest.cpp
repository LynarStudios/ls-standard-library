/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-05-01
 * Changed:         2023-02-03
 *
 * */

#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>

using namespace ls::std::core;

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
                     throw NullPointerException{};
                   }
                   catch (const NullPointerException &_exception)
                   {
                     EXPECT_STREQ("NullPointerException thrown - reference is null!", _exception.what());
                     throw;
                   }
                 }, NullPointerException);
  }
}
