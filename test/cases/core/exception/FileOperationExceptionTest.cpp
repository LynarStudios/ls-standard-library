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
                     throw FileOperationException{};
                   }
                   catch (const FileOperationException &_exception)
                   {
                     EXPECT_STREQ("FileOperationException thrown - file operation failed!", _exception.what());
                     throw;
                   }
                 }, FileOperationException);
  }
}
