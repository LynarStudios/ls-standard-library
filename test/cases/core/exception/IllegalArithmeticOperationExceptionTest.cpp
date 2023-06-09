/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-05-01
 * Changed:         2023-03-25
 *
 * */

#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>
#include <string>

using ls::std::core::IllegalArithmeticOperationException;
using std::string;
using testing::Test;

namespace
{
  class IllegalArithmeticOperationExceptionTest : public Test
  {
    public:

      IllegalArithmeticOperationExceptionTest() = default;
      ~IllegalArithmeticOperationExceptionTest() override = default;
  };

  TEST_F(IllegalArithmeticOperationExceptionTest, constructor)
  {
    EXPECT_THROW(
        {
          try
          {
            throw IllegalArithmeticOperationException{};
          }
          catch (const IllegalArithmeticOperationException &_exception)
          {
            string actual = _exception.what();
            string expected = _exception.getName() + " thrown - arithmetic operation is not allowed!";

            EXPECT_STREQ(expected.c_str(), actual.c_str());
            throw;
          }
        },
        IllegalArithmeticOperationException);
  }

  TEST_F(IllegalArithmeticOperationExceptionTest, constructor_dedicated_message)
  {
    EXPECT_THROW(
        {
          try
          {
            throw IllegalArithmeticOperationException{"division by zero"};
          }
          catch (const IllegalArithmeticOperationException &_exception)
          {
            string actual = _exception.what();
            string expected = _exception.getName() + " thrown - division by zero";

            EXPECT_STREQ(expected.c_str(), actual.c_str());
            throw;
          }
        },
        IllegalArithmeticOperationException);
  }

  TEST_F(IllegalArithmeticOperationExceptionTest, getName)
  {
    ASSERT_STREQ("IllegalArithmeticOperationException", IllegalArithmeticOperationException{}.getName().c_str());
  }
}
