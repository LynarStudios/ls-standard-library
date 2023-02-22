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
using namespace ::testing;
using namespace ::std;

namespace
{
  class IllegalArgumentExceptionTest : public Test
  {
    protected:

      IllegalArgumentExceptionTest() = default;
      ~IllegalArgumentExceptionTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(IllegalArgumentExceptionTest, constructor)
  {
    EXPECT_THROW(
        {
          try
          {
            throw IllegalArgumentException{};
          }
          catch (const IllegalArgumentException &_exception)
          {
            string actual = _exception.what();
            string expected = _exception.getName() + " thrown - passed argument is not valid!";

            EXPECT_STREQ(expected.c_str(), actual.c_str());
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(IllegalArgumentExceptionTest, constructor_dedicated_message)
  {
    EXPECT_THROW(
        {
          try
          {
            throw IllegalArgumentException{"value is empty"};
          }
          catch (const IllegalArgumentException &_exception)
          {
            string actual = _exception.what();
            string expected = _exception.getName() + " thrown - value is empty";

            EXPECT_STREQ(expected.c_str(), actual.c_str());
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(IllegalArgumentExceptionTest, getName)
  {
    ASSERT_STREQ("IllegalArgumentException", IllegalArgumentException{}.getName().c_str());
  }
}
