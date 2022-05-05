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
  class IntegerTest : public ::testing::Test
  {
    protected:

      IntegerTest() = default;

      ~IntegerTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  // assignment operators

  TEST_F(IntegerTest, operator_assignment_with_reference)
  {
    ls::Integer x{};
    ls::Integer y{3};
    x = y;

    ASSERT_EQ(3, x);
  }

  TEST_F(IntegerTest, operator_assignment_with_value)
  {
    ls::Integer x{};
    x = 44;

    ASSERT_EQ(44, x);
  }

  // arithmetic operators

  TEST_F(IntegerTest, operator_negative)
  {
    ls::Integer x{13};
    ls::Integer y{-13};

    ASSERT_EQ(-13, -x);
    ASSERT_EQ(13, -y);
  }

  TEST_F(IntegerTest, operator_add_with_reference)
  {
    ls::Integer x{13};
    ls::Integer y{7};

    ASSERT_EQ(20, x + y);
  }

  TEST_F(IntegerTest, operator_add_with_value)
  {
    ls::Integer x{13};
    ASSERT_EQ(20, x + 7);
  }

  TEST_F(IntegerTest, operator_mul_with_reference)
  {
    ls::Integer x{3};
    ls::Integer y{7};

    ASSERT_EQ(21, x * y);
  }

  TEST_F(IntegerTest, operator_mul_with_value)
  {
    ls::Integer x{3};
    ASSERT_EQ(21, x * 7);
  }

  TEST_F(IntegerTest, operator_sub_with_reference)
  {
    ls::Integer x{51};
    ls::Integer y{17};

    ASSERT_EQ(34, x - y);
  }

  TEST_F(IntegerTest, operator_sub_with_value)
  {
    ls::Integer x{51};
    ASSERT_EQ(34, x - 17);
  }

  TEST_F(IntegerTest, operator_div_with_reference)
  {
    ls::Integer x{81};
    ls::Integer y{9};

    ASSERT_EQ(9, x / y);
  }

  TEST_F(IntegerTest, operator_div_with_value)
  {
    ls::Integer x{81};
    ASSERT_EQ(9, x / 9);
  }

  TEST_F(IntegerTest, operator_div_by_zero_with_reference)
  {
    EXPECT_THROW({
                   try
                   {
                     ls::Integer x{9};
                     ls::Integer y{0};

                     x = x / y;
                   } catch (const ls::IllegalArithmeticOperationException &_exception)
                   {
                     throw;
                   }
                 }, ls::IllegalArithmeticOperationException);
  }

  TEST_F(IntegerTest, operator_div_by_zero_with_value)
  {
    EXPECT_THROW({
                   try
                   {
                     ls::Integer x{9};
                     x = x / 0;
                   } catch (const ls::IllegalArithmeticOperationException &_exception)
                   {
                     throw;
                   }
                 }, ls::IllegalArithmeticOperationException);
  }

  TEST_F(IntegerTest, operator_mod_with_reference)
  {
    ls::Integer x{85};
    ls::Integer y{9};

    ASSERT_EQ(4, x % y);
  }

  TEST_F(IntegerTest, operator_mod_with_value)
  {
    ls::Integer x{85};
    ASSERT_EQ(4, x % 9);
  }

  // compound operators

  TEST_F(IntegerTest, operator_add_assign_with_reference)
  {
    ls::Integer x{4};
    ls::Integer y{2};
    x += y;

    ASSERT_EQ(6, x);
  }

  TEST_F(IntegerTest, operator_add_assign_with_value)
  {
    ls::Integer x{4};
    x += 2;

    ASSERT_EQ(6, x);
  }

  TEST_F(IntegerTest, operator_sub_assign_with_reference)
  {
    ls::Integer x{14};
    ls::Integer y{2};
    x -= y;

    ASSERT_EQ(12, x);
  }

  TEST_F(IntegerTest, operator_sub_assign_with_value)
  {
    ls::Integer x{14};
    x -= 2;

    ASSERT_EQ(12, x);
  }

  TEST_F(IntegerTest, operator_mul_assign_with_reference)
  {
    ls::Integer x{6};
    ls::Integer y{3};
    x *= y;

    ASSERT_EQ(18, x);
  }

  TEST_F(IntegerTest, operator_mul_assign_with_value)
  {
    ls::Integer x{6};
    x *= 3;

    ASSERT_EQ(18, x);
  }

  TEST_F(IntegerTest, operator_div_assign_with_reference)
  {
    ls::Integer x{12};
    ls::Integer y{3};
    x /= y;

    ASSERT_EQ(4, x);
  }

  TEST_F(IntegerTest, operator_div_assign_with_value)
  {
    ls::Integer x{12};
    x /= 3;

    ASSERT_EQ(4, x);
  }

  TEST_F(IntegerTest, operator_div_assign_by_zero_with_reference)
  {
    EXPECT_THROW({
                   try
                   {
                     ls::Integer x{9};
                     ls::Integer y{0};

                     x = x /= y;
                   } catch (const ls::IllegalArithmeticOperationException &_exception)
                   {
                     throw;
                   }
                 }, ls::IllegalArithmeticOperationException);
  }

  TEST_F(IntegerTest, operator_div_assign_by_zero_with_value)
  {
    EXPECT_THROW({
                   try
                   {
                     ls::Integer x{9};
                     x = x /= 0;
                   } catch (const ls::IllegalArithmeticOperationException &_exception)
                   {
                     throw;
                   }
                 }, ls::IllegalArithmeticOperationException);
  }

  // comparison operators

  TEST_F(IntegerTest, operator_equals_with_reference)
  {
    ls::Integer x{12};
    ls::Integer y{12};

    ASSERT_TRUE(x == y);
  }

  TEST_F(IntegerTest, operator_equals_with_value)
  {
    ls::Integer x{12};

    ASSERT_TRUE(x == 12);
  }

  TEST_F(IntegerTest, operator_not_equals_with_reference)
  {
    ls::Integer x{12};
    ls::Integer y{3};

    ASSERT_TRUE(x != y);
  }

  TEST_F(IntegerTest, operator_not_equals_with_value)
  {
    ls::Integer x{12};
    ASSERT_TRUE(x != 3);
  }

  TEST_F(IntegerTest, operator_greater_than_with_reference)
  {
    ls::Integer x{12};
    ls::Integer y{3};

    ASSERT_TRUE(x > y);
  }

  TEST_F(IntegerTest, operator_greater_than_with_value)
  {
    ls::Integer x{12};
    ASSERT_TRUE(x > 3);
  }

  TEST_F(IntegerTest, operator_greater_than_equals_with_reference)
  {
    ls::Integer x{12};
    ls::Integer y{12};

    ASSERT_TRUE(x >= y);
  }

  TEST_F(IntegerTest, operator_greater_than_equals_with_value)
  {
    ls::Integer x{12};
    ASSERT_TRUE(x >= 12);
  }

  TEST_F(IntegerTest, operator_less_than_with_reference)
  {
    ls::Integer x{10};
    ls::Integer y{12};

    ASSERT_TRUE(x < y);
  }

  TEST_F(IntegerTest, operator_less_than_with_value)
  {
    ls::Integer x{10};
    ASSERT_TRUE(x < 12);
  }

  TEST_F(IntegerTest, operator_less_than_equals_with_reference)
  {
    ls::Integer x{10};
    ls::Integer y{10};

    ASSERT_TRUE(x <= y);
  }

  TEST_F(IntegerTest, operator_less_than_equals_with_value)
  {
    ls::Integer x{10};
    ASSERT_TRUE(x <= 10);
  }

  // logical operators

  TEST_F(IntegerTest, operator_negation)
  {
    ls::Integer x{};
    ASSERT_TRUE(!x);
  }

  TEST_F(IntegerTest, operator_and_with_reference)
  {
    ls::Integer x{1};
    ls::Integer y{1};

    ASSERT_TRUE(x && y);
  }

  TEST_F(IntegerTest, operator_and_with_value)
  {
    ls::Integer x{1};
    ASSERT_TRUE(x && 1);
  }

  TEST_F(IntegerTest, operator_and_with_boolean)
  {
    ls::Integer x{1};
    ASSERT_TRUE(x && true);
  }

  TEST_F(IntegerTest, operator_or_with_reference)
  {
    ls::Integer x{};
    ls::Integer y{1};

    ASSERT_TRUE(x || y);
  }

  TEST_F(IntegerTest, operator_or_with_value)
  {
    ls::Integer x{};
    ASSERT_TRUE(x || 1);
  }

  TEST_F(IntegerTest, operator_or_with_boolean)
  {
    ls::Integer x{};
    ASSERT_TRUE(x || true);
  }

  // increment / decrement operator

  TEST_F(IntegerTest, operator_increment)
  {
    ls::Integer x{};
    ++x;

    ASSERT_EQ(1, x);
  }

  TEST_F(IntegerTest, operator_decrement)
  {
    ls::Integer x{};

    --x;
    ASSERT_EQ(-1, x);
  }

  // implementation

  TEST_F(IntegerTest, parse_with_positive_value)
  {
    ls::Integer number{};

    number.parse("1989");
    ASSERT_EQ(1989, number);
  }

  TEST_F(IntegerTest, parse_with_negative_value)
  {
    ls::Integer number{};

    number.parse("-13");
    ASSERT_EQ(-13, number);
  }

  TEST_F(IntegerTest, toString)
  {
    ls::Integer number{112};
    ASSERT_STREQ("112", number.toString().c_str());
  }

  // additional functionality

  TEST_F(IntegerTest, getValue)
  {
    ls::Integer x{3};
    ASSERT_EQ(3, x.getValue());
  }

  // additional testing

  TEST_F(IntegerTest, constApproach)
  {
    const ls::Integer x{3};
    ASSERT_EQ(3, x);

    // x = 4; // wouldn't work
  }
}
