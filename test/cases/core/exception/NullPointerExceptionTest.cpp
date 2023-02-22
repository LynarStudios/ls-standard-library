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
  class NullPointerExceptionTest : public Test
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
    EXPECT_THROW(
        {
          try
          {
            throw NullPointerException{};
          }
          catch (const NullPointerException &_exception)
          {
            string actual = _exception.what();
            string expected = _exception.getName() + " thrown - reference is null!";

            EXPECT_STREQ(expected.c_str(), actual.c_str());
            throw;
          }
        },
        NullPointerException);
  }

  TEST_F(NullPointerExceptionTest, constructor_dedicated_message)
  {
    EXPECT_THROW(
        {
          try
          {
            throw NullPointerException{"_value is null"};
          }
          catch (const NullPointerException &_exception)
          {
            string actual = _exception.what();
            string expected = _exception.getName() + " thrown - _value is null";

            EXPECT_STREQ(expected.c_str(), actual.c_str());
            throw;
          }
        },
        NullPointerException);
  }

  TEST_F(NullPointerExceptionTest, getName)
  {
    ASSERT_STREQ("NullPointerException", NullPointerException{"message"}.getName().c_str());
  }
}
