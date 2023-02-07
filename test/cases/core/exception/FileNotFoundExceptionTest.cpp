/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-05-01
 * Changed:         2023-02-07
 *
 * */

#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>

using namespace ls::std::core;

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
    EXPECT_THROW(
        {
          try
          {
            throw FileNotFoundException{};
          }
          catch (const FileNotFoundException &_exception)
          {
            EXPECT_STREQ("FileNotFoundException thrown - file not found!", _exception.what());
            throw;
          }
        },
        FileNotFoundException);
  }

  TEST_F(FileNotFoundExceptionTest, constructor_dedicated_message)
  {
    EXPECT_THROW(
        {
          try
          {
            throw FileNotFoundException{R"("settings.txt" not found!)"};
          }
          catch (const FileNotFoundException &_exception)
          {
            EXPECT_STREQ(R"(FileNotFoundException thrown - "settings.txt" not found!)", _exception.what());
            throw;
          }
        },
        FileNotFoundException);
  }
}
