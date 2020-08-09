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

  TEST_F(BooleanTest, operatorNot) {
    ls_std::Boolean expression {};
    ASSERT_TRUE(!expression);
  }

  TEST_F(BooleanTest, operatorNotNegative) {
    ls_std::Boolean expression {true};
    ASSERT_FALSE(!expression);
  }

  TEST_F(BooleanTest, operatorAnd) {
    ls_std::Boolean expressionA {true};
    ls_std::Boolean expressionB {3 == 3};

    ASSERT_TRUE(expressionA && expressionB);
    ASSERT_TRUE(expressionB && expressionA);
    ASSERT_TRUE(expressionA && true);
    ASSERT_TRUE(expressionA && 1);
    ASSERT_TRUE(1 && expressionB);
  }

  TEST_F(BooleanTest, operatorAndNegative) {
    ls_std::Boolean expressionA {true};
    ls_std::Boolean expressionB {3 == 4};

    ASSERT_FALSE(expressionA && expressionB);
    ASSERT_FALSE(expressionB && expressionA);
    ASSERT_FALSE(expressionB && (3 == 4));
    ASSERT_FALSE(expressionB && 0);
    ASSERT_FALSE(expressionB && false);
  }

  TEST_F(BooleanTest, operatorOr) {
    ls_std::Boolean expressionA {false};
    ls_std::Boolean expressionB {3 == 3};

    ASSERT_TRUE(expressionA || expressionB);
    ASSERT_TRUE(expressionB || expressionA);
    ASSERT_TRUE(expressionA || 1);
    ASSERT_TRUE(expressionA || true);
    ASSERT_TRUE(1 || expressionA);
  }

  TEST_F(BooleanTest, operatorOrNegative) {
    ls_std::Boolean expressionA {false};
    ls_std::Boolean expressionB {3 == 4};

    ASSERT_FALSE(expressionA || expressionB);
    ASSERT_FALSE(expressionB || expressionA);
    ASSERT_FALSE(expressionA || 0);
    ASSERT_FALSE(expressionA || false);
    ASSERT_FALSE(0 || expressionA);
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
