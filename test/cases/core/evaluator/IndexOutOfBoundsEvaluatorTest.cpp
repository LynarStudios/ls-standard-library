/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-10
* Changed:         2023-03-25
*
* */

#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>
#include <string>

using ls::std::core::IndexOutOfBoundsEvaluator;
using ls::std::core::IndexOutOfBoundsException;
using std::string;
using testing::Test;

namespace
{
  class IndexOutOfBoundsEvaluatorTest : public Test
  {
    public:

      IndexOutOfBoundsEvaluatorTest() = default;
      ~IndexOutOfBoundsEvaluatorTest() override = default;
  };

  TEST_F(IndexOutOfBoundsEvaluatorTest, evaluate)
  {
    EXPECT_THROW(
        {
          try
          {
            IndexOutOfBoundsEvaluator(3, 2).evaluate();
          }
          catch (const IndexOutOfBoundsException &_exception)
          {
            string actual = _exception.what();
            string expected = _exception.getName() + " thrown - provided index is out of bounds!";

            ASSERT_STREQ(expected.c_str(), actual.c_str());
            throw;
          }
        },
        IndexOutOfBoundsException);
  }

  TEST_F(IndexOutOfBoundsEvaluatorTest, evaluate_dedicated_message)
  {
    EXPECT_THROW(
        {
          try
          {
            IndexOutOfBoundsEvaluator(3, 2, "index 3 is not in range of the containers size, which is 2!").evaluate();
          }
          catch (const IndexOutOfBoundsException &_exception)
          {
            string actual = _exception.what();
            string expected = _exception.getName() + " thrown - index 3 is not in range of the containers size, which is 2!";

            ASSERT_STREQ(expected.c_str(), actual.c_str());
            throw;
          }
        },
        IndexOutOfBoundsException);
  }
}
