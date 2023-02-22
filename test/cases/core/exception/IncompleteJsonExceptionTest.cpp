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
  class IncompleteJsonExceptionTest : public Test
  {
    protected:

      IncompleteJsonExceptionTest() = default;
      ~IncompleteJsonExceptionTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(IncompleteJsonExceptionTest, constructor)
  {
    EXPECT_THROW(
        {
          try
          {
            throw IncompleteJsonException{};
          }
          catch (const IncompleteJsonException &_exception)
          {
            string actual = _exception.what();
            string expected = _exception.getName() + " thrown - this JSON string is incomplete.";

            EXPECT_STREQ(expected.c_str(), actual.c_str());
            throw;
          }
        },
        IncompleteJsonException);
  }

  TEST_F(IncompleteJsonExceptionTest, constructor_dedicated_message)
  {
    EXPECT_THROW(
        {
          try
          {
            throw IncompleteJsonException{"incomplete: {\"name\":\"}"};
          }
          catch (const IncompleteJsonException &_exception)
          {
            string actual = _exception.what();
            string expected = _exception.getName() + " thrown - incomplete: {\"name\":\"}";

            EXPECT_STREQ(expected.c_str(), actual.c_str());
            throw;
          }
        },
        IncompleteJsonException);
  }

  TEST_F(IncompleteJsonExceptionTest, getName)
  {
    ASSERT_STREQ("IncompleteJsonException", IncompleteJsonException{}.getName().c_str());
  }
}
