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
  class FileNotFoundExceptionTest : public ::testing::Test
  {
    protected:

      FileNotFoundExceptionTest() = default;
      ~FileNotFoundExceptionTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(FileNotFoundExceptionTest, constructor)
  {
    EXPECT_THROW({
                   try
                   {
                     throw ls_std::FileNotFoundException{};
                   }
                   catch (const ls_std::FileNotFoundException &_exception)
                   {
                     EXPECT_STREQ("FileNotFoundException thrown - file not found!", _exception.what());
                     throw;
                   }
                 }, ls_std::FileNotFoundException);
  }
}
