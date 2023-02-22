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
            ::std::string actual = _exception.what();
            ::std::string expected = _exception.getName() + " thrown - file not found!";

            EXPECT_STREQ(expected.c_str(), actual.c_str());
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
            ::std::string actual = _exception.what();
            ::std::string expected = _exception.getName() + R"( thrown - "settings.txt" not found!)";

            EXPECT_STREQ(expected.c_str(), actual.c_str());
            throw;
          }
        },
        FileNotFoundException);
  }

  TEST_F(FileNotFoundExceptionTest, getName)
  {
    ASSERT_STREQ("FileNotFoundException", FileNotFoundException{}.getName().c_str());
  }
}
