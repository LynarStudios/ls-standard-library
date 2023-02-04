/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-09
 * Changed:         2023-02-04
 *
 * */

#include <gtest/gtest.h>
#include <ls-std/ls-std-boxing.hpp>
#include <ls-std/ls-std-core.hpp>

using namespace ls::std::boxing;
using namespace ls::std::core;
using namespace ::std;

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
    Boolean expression{};
    expression = true;

    ASSERT_TRUE(expression);
  }

  TEST_F(BooleanTest, operator_assignment_integer)
  {
    Boolean expression{};
    expression = 1;

    ASSERT_TRUE(expression);
  }

  // stream operators

  TEST_F(BooleanTest, operator_output_stream)
  {
    Boolean expression{true};
    ostringstream _stream{};
    _stream << expression;

    ASSERT_STREQ("true", _stream.str().c_str());
  }

  // logical operators

  TEST_F(BooleanTest, operator_negation_negative_value)
  {
    Boolean expression{};
    ASSERT_TRUE(!expression);
  }

  TEST_F(BooleanTest, operator_negation_positive_value)
  {
    Boolean expression{true};
    ASSERT_FALSE(!expression);
  }

  TEST_F(BooleanTest, operator_and)
  {
    Boolean expressionA{true};
    Boolean expressionB{3 == 3};

    ASSERT_TRUE(expressionA && expressionB);
    ASSERT_TRUE(expressionB && expressionA);
    ASSERT_TRUE(expressionA && true);
    ASSERT_TRUE(expressionA && 1);
    ASSERT_TRUE(1 && expressionB);
  }

  TEST_F(BooleanTest, operator_and_with_false_result)
  {
    Boolean expressionA{true};
    Boolean expressionB{3 == 4};

    ASSERT_FALSE(expressionA && expressionB);
    ASSERT_FALSE(expressionB && expressionA);
    ASSERT_FALSE(expressionB && (3 == 4));
    ASSERT_FALSE(expressionB && 0);
    ASSERT_FALSE(expressionB && false);
  }

  TEST_F(BooleanTest, operator_or)
  {
    Boolean expressionA{false};
    Boolean expressionB{3 == 3};

    ASSERT_TRUE(expressionA || expressionB);
    ASSERT_TRUE(expressionB || expressionA);
    ASSERT_TRUE(expressionA || 1);
    ASSERT_TRUE(expressionA || true);
    ASSERT_TRUE(1 || expressionA);
  }

  TEST_F(BooleanTest, operator_or_with_false_result)
  {
    Boolean expressionA{false};
    Boolean expressionB{3 == 4};

    ASSERT_FALSE(expressionA || expressionB);
    ASSERT_FALSE(expressionB || expressionA);
    ASSERT_FALSE(expressionA || 0);
    ASSERT_FALSE(expressionA || false);
    ASSERT_FALSE(0 || expressionA);
  }

  // implementation

  TEST_F(BooleanTest, parse_true_value)
  {
    Boolean expression{};

    expression.parse("true");
    ASSERT_TRUE(expression);

    expression.parse("tRue");
    ASSERT_TRUE(expression);

    expression.parse("TRUE");
    ASSERT_TRUE(expression);
  }

  TEST_F(BooleanTest, parse_false_value)
  {
    Boolean expression{};

    expression.parse("false");
    ASSERT_FALSE(expression);

    expression.parse("fAlSe");
    ASSERT_FALSE(expression);

    expression.parse("FALSE");
    ASSERT_FALSE(expression);
  }

  TEST_F(BooleanTest, parse_with_invalid_parameter)
  {
    EXPECT_THROW(
        {
          try
          {
            Boolean expression{};
            expression.parse("hello");
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(BooleanTest, toString_true)
  {
    Boolean expression{2 < 3};
    ASSERT_STREQ("true", expression.toString().c_str());
  }

  TEST_F(BooleanTest, toString_false)
  {
    Boolean expression{4 < 3};
    ASSERT_STREQ("false", expression.toString().c_str());
  }

  // additional functionality

  TEST_F(BooleanTest, getValue)
  {
    Boolean x{2 < 3};
    ASSERT_TRUE(x.getValue());
  }

  TEST_F(BooleanTest, XOR_with_positive_result)
  {
    Boolean x{2 < 3};
    Boolean y{4 < 3};

    ASSERT_TRUE(Boolean::XOR(x, y));
    ASSERT_TRUE(Boolean::XOR(y, x));
    ASSERT_TRUE(Boolean::XOR(y, true));
    ASSERT_TRUE(Boolean::XOR(true, y));
    ASSERT_TRUE(Boolean::XOR(true, false));
    ASSERT_TRUE(Boolean::XOR(false, true));
  }

  TEST_F(BooleanTest, XOR_with_negative_result)
  {
    Boolean w{};
    Boolean x{true};
    Boolean y{};
    Boolean z{true};

    ASSERT_FALSE(Boolean::XOR(x, z));
    ASSERT_FALSE(Boolean::XOR(w, y));
    ASSERT_FALSE(Boolean::XOR(true, true));
    ASSERT_FALSE(Boolean::XOR(false, false));
    ASSERT_FALSE(Boolean::XOR(w, false));
    ASSERT_FALSE(Boolean::XOR(false, w));
  }
}
