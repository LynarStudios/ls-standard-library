/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-05-01
 * Changed:         2023-02-22
 *
 * */

#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>
#include <string>

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
    EXPECT_THROW(
        {
          try
          {
            throw FileOperationException{};
          }
          catch (const FileOperationException &_exception)
          {
            ::std::string actual = _exception.what();
            ::std::string expected = _exception.getName() + " thrown - file operation failed!";

            EXPECT_STREQ(expected.c_str(), actual.c_str());
            throw;
          }
        },
        FileOperationException);
  }

  TEST_F(FileOperationExceptionTest, constructor_dedicated_message)
  {
    EXPECT_THROW(
        {
          try
          {
            throw FileOperationException{R"(creating directory "tmp")"};
          }
          catch (const FileOperationException &_exception)
          {
            ::std::string actual = _exception.what();
            ::std::string expected = _exception.getName() + R"( thrown - creating directory "tmp")";

            EXPECT_STREQ(expected.c_str(), actual.c_str());
            throw;
          }
        },
        FileOperationException);
  }

  TEST_F(FileOperationExceptionTest, getName)
  {
    ASSERT_STREQ("FileOperationException", FileOperationException{}.getName().c_str());
  }
}
