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
  class FileOperationExceptionTest : public ::testing::Test
  {
    protected:

      FileOperationExceptionTest() = default;
      ~FileOperationExceptionTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(FileOperationExceptionTest, constructor)
  {
    EXPECT_THROW({
                   try
                   {
                     throw ls_std::FileOperationException{};
                   }
                   catch (const ls_std::FileOperationException &_exception)
                   {
                     EXPECT_STREQ("FileOperationException thrown - file operation failed!", _exception.what());
                     throw;
                   }
                 }, ls_std::FileOperationException);
  }
}
