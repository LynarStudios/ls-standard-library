/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-09
 * Changed:         2022-05-05
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>
#include <TestHelper.hpp>

namespace
{
  class BooleanTest : public ::testing::Test
  {
    protected:

      BooleanTest() = default;
      ~BooleanTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  // assignment operators

  TEST_F(BooleanTest, operator_assignment_boolean)
  {
    ls::Boolean expression{};
    expression = true;

    ASSERT_TRUE(expression);
  }

  TEST_F(BooleanTest, operator_assignment_integer)
  {
    ls::Boolean expression{};
    expression = 1;

    ASSERT_TRUE(expression);
  }

  // stream operators

  TEST_F(BooleanTest, operator_output_stream)
  {
    ls::Boolean expression{true};
    std::ostringstream _stream{};
    _stream << expression;

    ASSERT_STREQ("true", _stream.str().c_str());
  }

  // logical operators

  TEST_F(BooleanTest, operator_negation_negative_value)
  {
    ls::Boolean expression{};
    ASSERT_TRUE(!expression);
  }

  TEST_F(BooleanTest, operator_negation_positive_value)
  {
    ls::Boolean expression{true};
    ASSERT_FALSE(!expression);
  }

  TEST_F(BooleanTest, operator_and)
  {
    ls::Boolean expressionA{true};
    ls::Boolean expressionB{3 == 3};

    ASSERT_TRUE(expressionA && expressionB);
    ASSERT_TRUE(expressionB && expressionA);
    ASSERT_TRUE(expressionA && true);
    ASSERT_TRUE(expressionA && 1);
    ASSERT_TRUE(1 && expressionB);
  }

  TEST_F(BooleanTest, operator_and_with_false_result)
  {
    ls::Boolean expressionA{true};
    ls::Boolean expressionB{3 == 4};

    ASSERT_FALSE(expressionA && expressionB);
    ASSERT_FALSE(expressionB && expressionA);
    ASSERT_FALSE(expressionB && (3 == 4));
    ASSERT_FALSE(expressionB && 0);
    ASSERT_FALSE(expressionB && false);
  }

  TEST_F(BooleanTest, operator_or)
  {
    ls::Boolean expressionA{false};
    ls::Boolean expressionB{3 == 3};

    ASSERT_TRUE(expressionA || expressionB);
    ASSERT_TRUE(expressionB || expressionA);
    ASSERT_TRUE(expressionA || 1);
    ASSERT_TRUE(expressionA || true);
    ASSERT_TRUE(1 || expressionA);
  }

  TEST_F(BooleanTest, operator_or_with_false_result)
  {
    ls::Boolean expressionA{false};
    ls::Boolean expressionB{3 == 4};

    ASSERT_FALSE(expressionA || expressionB);
    ASSERT_FALSE(expressionB || expressionA);
    ASSERT_FALSE(expressionA || 0);
    ASSERT_FALSE(expressionA || false);
    ASSERT_FALSE(0 || expressionA);
  }

  // implementation

  TEST_F(BooleanTest, parse_true_value)
  {
    ls::Boolean expression{};

    expression.parse("true");
    ASSERT_TRUE(expression);

    expression.parse("tRue");
    ASSERT_TRUE(expression);

    expression.parse("TRUE");
    ASSERT_TRUE(expression);
  }

  TEST_F(BooleanTest, parse_false_value)
  {
    ls::Boolean expression{};

    expression.parse("false");
    ASSERT_FALSE(expression);

    expression.parse("fAlSe");
    ASSERT_FALSE(expression);

    expression.parse("FALSE");
    ASSERT_FALSE(expression);
  }

  TEST_F(BooleanTest, parse_with_invalid_parameter)
  {
    EXPECT_THROW({
                   try
                   {
                     ls::Boolean expression{};
                     expression.parse("hello");
                   } catch (const ls::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::IllegalArgumentException);
  }

  TEST_F(BooleanTest, toString_true)
  {
    ls::Boolean expression{2 < 3};
    ASSERT_STREQ("true", expression.toString().c_str());
  }

  TEST_F(BooleanTest, toString_false)
  {
    ls::Boolean expression{4 < 3};
    ASSERT_STREQ("false", expression.toString().c_str());
  }

  // additional functionality

  TEST_F(BooleanTest, getValue)
  {
    ls::Boolean x{2 < 3};
    ASSERT_TRUE(x.getValue());
  }

  TEST_F(BooleanTest, XOR_with_positive_result)
  {
    ls::Boolean x{2 < 3};
    ls::Boolean y{4 < 3};

    ASSERT_TRUE(ls::Boolean::XOR(x, y));
    ASSERT_TRUE(ls::Boolean::XOR(y, x));
    ASSERT_TRUE(ls::Boolean::XOR(y, true));
    ASSERT_TRUE(ls::Boolean::XOR(true, y));
    ASSERT_TRUE(ls::Boolean::XOR(true, false));
    ASSERT_TRUE(ls::Boolean::XOR(false, true));
  }

  TEST_F(BooleanTest, XOR_with_negative_result)
  {
    ls::Boolean w{};
    ls::Boolean x{true};
    ls::Boolean y{};
    ls::Boolean z{true};

    ASSERT_FALSE(ls::Boolean::XOR(x, z));
    ASSERT_FALSE(ls::Boolean::XOR(w, y));
    ASSERT_FALSE(ls::Boolean::XOR(true, true));
    ASSERT_FALSE(ls::Boolean::XOR(false, false));
    ASSERT_FALSE(ls::Boolean::XOR(w, false));
    ASSERT_FALSE(ls::Boolean::XOR(false, w));
  }
}
