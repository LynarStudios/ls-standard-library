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

using ls::std::core::IndexOutOfBoundsException;
using std::string;
using testing::Test;

namespace
{
  class IndexOutOfBoundsExceptionTest : public Test
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
            string actual = _exception.what();
            string expected = _exception.getName() + " thrown - provided index is out of bounds!";

            EXPECT_STREQ(expected.c_str(), actual.c_str());
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
            string actual = _exception.what();
            string expected = _exception.getName() + " thrown - index 3 is out of bounds!";

            EXPECT_STREQ(expected.c_str(), actual.c_str());
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
