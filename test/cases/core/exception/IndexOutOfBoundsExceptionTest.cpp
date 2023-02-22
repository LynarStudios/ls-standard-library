/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-10
* Changed:         2023-02-22
*
* */

#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>
#include <string>

using namespace ls::std::core;

namespace
{
  class IndexOutOfBoundsExceptionTest : public ::testing::Test
  {
    protected:

      IndexOutOfBoundsExceptionTest() = default;
      ~IndexOutOfBoundsExceptionTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(IndexOutOfBoundsExceptionTest, constructor)
  {
    EXPECT_THROW(
        {
          try
          {
            throw IndexOutOfBoundsException{};
          }
          catch (const IndexOutOfBoundsException &_exception)
          {
            ::std::string message = _exception.what();
            EXPECT_STREQ("IndexOutOfBoundsException thrown - provided index is out of bounds!", message.c_str());
            throw;
          }
        },
        IndexOutOfBoundsException);
  }

  TEST_F(IndexOutOfBoundsExceptionTest, constructor_dedicated_message)
  {
    EXPECT_THROW(
        {
          try
          {
            throw IndexOutOfBoundsException{"index 3 is out of bounds!"};
          }
          catch (const IndexOutOfBoundsException &_exception)
          {
            ::std::string message = _exception.what();
            EXPECT_STREQ("IndexOutOfBoundsException thrown - index 3 is out of bounds!", message.c_str());
            throw;
          }
        },
        IndexOutOfBoundsException);
  }

  TEST_F(IndexOutOfBoundsExceptionTest, getName)
  {
    ASSERT_STREQ("IndexOutOfBoundsException", IndexOutOfBoundsException{}.getName().c_str());
  }
}
