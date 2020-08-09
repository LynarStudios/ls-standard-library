/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-09
 * Changed:         2020-08-09
 *
 * */

#include <gtest/gtest.h>
#include "../../../source/boxing/Boolean.hpp"

namespace {
  class BooleanTest : public ::testing::Test {
    protected:

      BooleanTest() = default;
      ~BooleanTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(BooleanTest, operatorOutputStream)
  {
    ls_std::Boolean expression {true};
    std::ostringstream _stream {};
    _stream << expression;

    ASSERT_STREQ("true", _stream.str().c_str());
  }

  TEST_F(BooleanTest, parse)
  {
    ls_std::Boolean expression {};

    expression.parse("true");
    ASSERT_TRUE(expression);

    expression.parse("tRue");
    ASSERT_TRUE(expression);

    expression.parse("TRUE");
    ASSERT_TRUE(expression);
  }

  TEST_F(BooleanTest, parseNegative)
  {
    ls_std::Boolean expression {};

    expression.parse("false");
    ASSERT_FALSE(expression);

    expression.parse("fAlSe");
    ASSERT_FALSE(expression);

    expression.parse("FALSE");
    ASSERT_FALSE(expression);
  }
}
