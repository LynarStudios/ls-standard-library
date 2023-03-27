/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-03-27
* Changed:         2023-03-27
*
* */

#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>
#include <string>

using ls::std::core::NotImplementedException;
using std::string;
using testing::Test;

namespace
{
  class NotImplementedExceptionTest : public Test
  {
    public:

      NotImplementedExceptionTest() = default;
      ~NotImplementedExceptionTest() override = default;
  };

  TEST_F(NotImplementedExceptionTest, constructor)
  {
    EXPECT_THROW(
        {
          try
          {
            throw NotImplementedException{};
          }
          catch (const NotImplementedException &_exception)
          {
            string actual = _exception.what();
            string expected = _exception.getName() + " thrown - method is not implemented and should not be used!";

            EXPECT_STREQ(expected.c_str(), actual.c_str());
            throw;
          }
        },
        NotImplementedException);
  }

  TEST_F(NotImplementedExceptionTest, constructor_dedicated_message)
  {
    EXPECT_THROW(
        {
          try
          {
            throw NotImplementedException{R"lit(method "marshal" is not implemented!)lit"};
          }
          catch (const NotImplementedException &_exception)
          {
            string actual = _exception.what();
            string expected = _exception.getName() + R"lit( thrown - method "marshal" is not implemented!)lit";

            EXPECT_STREQ(expected.c_str(), actual.c_str());
            throw;
          }
        },
        NotImplementedException);
  }

  TEST_F(NotImplementedExceptionTest, getName)
  {
    ASSERT_STREQ("NotImplementedException", NotImplementedException{}.getName().c_str());
  }
}
