/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-09
 * Changed:         2021-07-14
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
    ls_std::Integer x{};
    ls_std::Integer y{3};
    x = y;

    ASSERT_EQ(3, x);
  }

  TEST_F(IntegerTest, operator_assignment_with_value)
  {
    ls_std::Integer x{};
    x = 44;

    ASSERT_EQ(44, x);
  }

  // arithmetic operators

  TEST_F(IntegerTest, operator_negative)
  {
    ls_std::Integer x{13};
    ls_std::Integer y{-13};

    ASSERT_EQ(-13, -x);
    ASSERT_EQ(13, -y);
  }

  TEST_F(IntegerTest, operator_add_with_reference)
  {
    ls_std::Integer x{13};
    ls_std::Integer y{7};

    ASSERT_EQ(20, x + y);
  }

  TEST_F(IntegerTest, operator_add_with_value)
  {
    ls_std::Integer x{13};
    ASSERT_EQ(20, x + 7);
  }

  TEST_F(IntegerTest, operator_mul_with_reference)
  {
    ls_std::Integer x{3};
    ls_std::Integer y{7};

    ASSERT_EQ(21, x * y);
  }

  TEST_F(IntegerTest, operator_mul_with_value)
  {
    ls_std::Integer x{3};
    ASSERT_EQ(21, x * 7);
  }

  TEST_F(IntegerTest, operator_sub_with_reference)
  {
    ls_std::Integer x{51};
    ls_std::Integer y{17};

    ASSERT_EQ(34, x - y);
  }

  TEST_F(IntegerTest, operator_sub_with_value)
  {
    ls_std::Integer x{51};
    ASSERT_EQ(34, x - 17);
  }

  TEST_F(IntegerTest, operator_div_with_reference)
  {
    ls_std::Integer x{81};
    ls_std::Integer y{9};

    ASSERT_EQ(9, x / y);
  }

  TEST_F(IntegerTest, operator_div_with_value)
  {
    ls_std::Integer x{81};
    ASSERT_EQ(9, x / 9);
  }

  TEST_F(IntegerTest, operator_div_by_zero_with_reference)
  {
    EXPECT_THROW({
                   try
                   {
                     ls_std::Integer x{9};
                     ls_std::Integer y{0};

                     x = x / y;
                   } catch (const ls_std::IllegalArithmeticOperationException &_exception)
                   {
                     throw;
                   }
                 }, ls_std::IllegalArithmeticOperationException);
  }

  TEST_F(IntegerTest, operator_div_by_zero_with_value)
  {
    EXPECT_THROW({
                   try
                   {
                     ls_std::Integer x{9};
                     x = x / 0;
                   } catch (const ls_std::IllegalArithmeticOperationException &_exception)
                   {
                     throw;
                   }
                 }, ls_std::IllegalArithmeticOperationException);
  }

  TEST_F(IntegerTest, operator_mod_with_reference)
  {
    ls_std::Integer x{85};
    ls_std::Integer y{9};

    ASSERT_EQ(4, x % y);
  }

  TEST_F(IntegerTest, operator_mod_with_value)
  {
    ls_std::Integer x{85};
    ASSERT_EQ(4, x % 9);
  }

  // compound operators

  TEST_F(IntegerTest, operator_add_assign_with_reference)
  {
    ls_std::Integer x{4};
    ls_std::Integer y{2};
    x += y;

    ASSERT_EQ(6, x);
  }

  TEST_F(IntegerTest, operator_add_assign_with_value)
  {
    ls_std::Integer x{4};
    x += 2;

    ASSERT_EQ(6, x);
  }

  TEST_F(IntegerTest, operator_sub_assign_with_reference)
  {
    ls_std::Integer x{14};
    ls_std::Integer y{2};
    x -= y;

    ASSERT_EQ(12, x);
  }

  TEST_F(IntegerTest, operator_sub_assign_with_value)
  {
    ls_std::Integer x{14};
    x -= 2;

    ASSERT_EQ(12, x);
  }

  TEST_F(IntegerTest, operator_mul_assign_with_reference)
  {
    ls_std::Integer x{6};
    ls_std::Integer y{3};
    x *= y;

    ASSERT_EQ(18, x);
  }

  TEST_F(IntegerTest, operator_mul_assign_with_value)
  {
    ls_std::Integer x{6};
    x *= 3;

    ASSERT_EQ(18, x);
  }

  TEST_F(IntegerTest, operator_div_assign_with_reference)
  {
    ls_std::Integer x{12};
    ls_std::Integer y{3};
    x /= y;

    ASSERT_EQ(4, x);
  }

  TEST_F(IntegerTest, operator_div_assign_with_value)
  {
    ls_std::Integer x{12};
    x /= 3;

    ASSERT_EQ(4, x);
  }

  TEST_F(IntegerTest, operator_div_assign_by_zero_with_reference)
  {
    EXPECT_THROW({
                   try
                   {
                     ls_std::Integer x{9};
                     ls_std::Integer y{0};

                     x = x /= y;
                   } catch (const ls_std::IllegalArithmeticOperationException &_exception)
                   {
                     throw;
                   }
                 }, ls_std::IllegalArithmeticOperationException);
  }

  TEST_F(IntegerTest, operator_div_assign_by_zero_with_value)
  {
    EXPECT_THROW({
                   try
                   {
                     ls_std::Integer x{9};
                     x = x /= 0;
                   } catch (const ls_std::IllegalArithmeticOperationException &_exception)
                   {
                     throw;
                   }
                 }, ls_std::IllegalArithmeticOperationException);
  }

  // comparison operators

  TEST_F(IntegerTest, operator_equals_with_reference)
  {
    ls_std::Integer x{12};
    ls_std::Integer y{12};

    ASSERT_TRUE(x == y);
  }

  TEST_F(IntegerTest, operator_equals_with_value)
  {
    ls_std::Integer x{12};

    ASSERT_TRUE(x == 12);
  }

  TEST_F(IntegerTest, operator_not_equals_with_reference)
  {
    ls_std::Integer x{12};
    ls_std::Integer y{3};

    ASSERT_TRUE(x != y);
  }

  TEST_F(IntegerTest, operator_not_equals_with_value)
  {
    ls_std::Integer x{12};
    ASSERT_TRUE(x != 3);
  }

  TEST_F(IntegerTest, operator_greater_than_with_reference)
  {
    ls_std::Integer x{12};
    ls_std::Integer y{3};

    ASSERT_TRUE(x > y);
  }

  TEST_F(IntegerTest, operator_greater_than_with_value)
  {
    ls_std::Integer x{12};
    ASSERT_TRUE(x > 3);
  }

  TEST_F(IntegerTest, operator_greater_than_equals_with_reference)
  {
    ls_std::Integer x{12};
    ls_std::Integer y{12};

    ASSERT_TRUE(x >= y);
  }

  TEST_F(IntegerTest, operator_greater_than_equals_with_value)
  {
    ls_std::Integer x{12};
    ASSERT_TRUE(x >= 12);
  }

  TEST_F(IntegerTest, operator_less_than_with_reference)
  {
    ls_std::Integer x{10};
    ls_std::Integer y{12};

    ASSERT_TRUE(x < y);
  }

  TEST_F(IntegerTest, operator_less_than_with_value)
  {
    ls_std::Integer x{10};
    ASSERT_TRUE(x < 12);
  }

  TEST_F(IntegerTest, operator_less_than_equals_with_reference)
  {
    ls_std::Integer x{10};
    ls_std::Integer y{10};

    ASSERT_TRUE(x <= y);
  }

  TEST_F(IntegerTest, operator_less_than_equals_with_value)
  {
    ls_std::Integer x{10};
    ASSERT_TRUE(x <= 10);
  }

  // logical operators

  TEST_F(IntegerTest, operator_negation)
  {
    ls_std::Integer x{};
    ASSERT_TRUE(!x);
  }

  TEST_F(IntegerTest, operator_and_with_reference)
  {
    ls_std::Integer x{1};
    ls_std::Integer y{1};

    ASSERT_TRUE(x && y);
  }

  TEST_F(IntegerTest, operator_and_with_value)
  {
    ls_std::Integer x{1};
    ASSERT_TRUE(x && 1);
  }

  TEST_F(IntegerTest, operator_and_with_boolean)
  {
    ls_std::Integer x{1};
    ASSERT_TRUE(x && true);
  }

  TEST_F(IntegerTest, operator_or_with_reference)
  {
    ls_std::Integer x{};
    ls_std::Integer y{1};

    ASSERT_TRUE(x || y);
  }

  TEST_F(IntegerTest, operator_or_with_value)
  {
    ls_std::Integer x{};
    ASSERT_TRUE(x || 1);
  }

  TEST_F(IntegerTest, operator_or_with_boolean)
  {
    ls_std::Integer x{};
    ASSERT_TRUE(x || true);
  }

  // increment / decrement operator

  TEST_F(IntegerTest, operator_increment)
  {
    ls_std::Integer x{};
    ++x;

    ASSERT_EQ(1, x);
  }

  TEST_F(IntegerTest, operator_decrement)
  {
    ls_std::Integer x{};

    --x;
    ASSERT_EQ(-1, x);
  }

  // implementation

  TEST_F(IntegerTest, parse_with_positive_value)
  {
    ls_std::Integer number{};

    number.parse("1989");
    ASSERT_EQ(1989, number);
  }

  TEST_F(IntegerTest, parse_with_negative_value)
  {
    ls_std::Integer number{};

    number.parse("-13");
    ASSERT_EQ(-13, number);
  }

  TEST_F(IntegerTest, toString)
  {
    ls_std::Integer number{112};
    ASSERT_STREQ("112", number.toString().c_str());
  }

  // additional functionality

  TEST_F(IntegerTest, getValue)
  {
    ls_std::Integer x{3};
    ASSERT_EQ(3, x.getValue());
  }

  // additional testing

  TEST_F(IntegerTest, constApproach)
  {
    const ls_std::Integer x{3};
    ASSERT_EQ(3, x);

    // x = 4; // wouldn't work
  }
}
