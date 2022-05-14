/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2022-05-14
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std_core.hpp>
#include <ls_std/ls_std_boxing.hpp>

namespace
{
  class LongTest : public ::testing::Test
  {
    protected:

      LongTest() = default;

      ~LongTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  // assignment operators

  TEST_F(LongTest, operator_assignment_with_reference)
  {
    ls::std::boxing::Long x{13};
    ls::std::boxing::Long y{3};
    x = y;

    ASSERT_EQ(3, x);
  }

  TEST_F(LongTest, operator_assignment_with_value)
  {
    ls::std::boxing::Long x{13};
    x = (ls::std::core::type::long_type) 3;

    ASSERT_EQ(3, x);
  }

  // arithmetic operators

  TEST_F(LongTest, operator_negative)
  {
    ls::std::boxing::Long x{13};
    ls::std::boxing::Long y{-13};

    ASSERT_EQ(-13, -x);
    ASSERT_EQ(13, -y);
  }

  TEST_F(LongTest, operator_add_with_reference)
  {
    ls::std::boxing::Long x{13};
    ls::std::boxing::Long y{7};

    ASSERT_EQ(20, x + y);
  }

  TEST_F(LongTest, operator_add_with_value)
  {
    ls::std::boxing::Long x{13};
    ASSERT_EQ(20, x + (ls::std::core::type::long_type) 7);
  }

  TEST_F(LongTest, operator_mul_with_reference)
  {
    ls::std::boxing::Long x{3};
    ls::std::boxing::Long y{7};

    ASSERT_EQ(21, x * y);
  }

  TEST_F(LongTest, operator_mul_with_value)
  {
    ls::std::boxing::Long x{3};
    ASSERT_EQ(21, x * (ls::std::core::type::long_type) 7);
  }

  TEST_F(LongTest, operator_sub_with_reference)
  {
    ls::std::boxing::Long x{51};
    ls::std::boxing::Long y{17};

    ASSERT_EQ(34, x - y);
  }

  TEST_F(LongTest, operator_sub_with_value)
  {
    ls::std::boxing::Long x{51};
    ASSERT_EQ(34, x - (ls::std::core::type::long_type) 17);
  }

  TEST_F(LongTest, operator_div_with_reference)
  {
    ls::std::boxing::Long x{81};
    ls::std::boxing::Long y{9};

    ASSERT_EQ(9, x / y);
  }

  TEST_F(LongTest, operator_div_with_value)
  {
    ls::std::boxing::Long x{81};
    ASSERT_EQ(9, x / (ls::std::core::type::long_type) 9);
  }

  TEST_F(LongTest, operator_div_by_zero_with_reference)
  {
    EXPECT_THROW({
                   try
                   {
                     ls::std::boxing::Long x{9};
                     ls::std::boxing::Long y{0};

                     x = x / y;
                   } catch (const ls::std::core::IllegalArithmeticOperationException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArithmeticOperationException);
  }

  TEST_F(LongTest, operator_div_by_zero_with_value)
  {
    EXPECT_THROW({
                   try
                   {
                     ls::std::boxing::Long x{9};
                     x = x / (ls::std::core::type::long_type) 0;
                   } catch (const ls::std::core::IllegalArithmeticOperationException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArithmeticOperationException);
  }

  TEST_F(LongTest, operator_mod_with_reference)
  {
    ls::std::boxing::Long x{85};
    ls::std::boxing::Long y{9};

    ASSERT_EQ(4, x % y);
  }

  TEST_F(LongTest, operator_mod_with_value)
  {
    ls::std::boxing::Long x{85};
    ASSERT_EQ(4, x % (ls::std::core::type::long_type) 9);
  }

  // compound operators

  TEST_F(LongTest, operator_add_equals_with_reference)
  {
    ls::std::boxing::Long x{4};
    ls::std::boxing::Long y{2};
    x += y;

    ASSERT_EQ(6, x);
  }

  TEST_F(LongTest, operator_add_equals_with_value)
  {
    ls::std::boxing::Long x{4};
    x += (ls::std::core::type::long_type) 2;

    ASSERT_EQ(6, x);
  }

  TEST_F(LongTest, operator_sub_equals_with_reference)
  {
    ls::std::boxing::Long x{14};
    ls::std::boxing::Long y{2};
    x -= y;

    ASSERT_EQ(12, x);
  }

  TEST_F(LongTest, operator_sub_equals_with_value)
  {
    ls::std::boxing::Long x{14};
    x -= (ls::std::core::type::long_type) 2;

    ASSERT_EQ(12, x);
  }

  TEST_F(LongTest, operator_mul_equals_with_reference)
  {
    ls::std::boxing::Long x{6};
    ls::std::boxing::Long y{3};
    x *= y;

    ASSERT_EQ(18, x);
  }

  TEST_F(LongTest, operator_mul_equals_with_value)
  {
    ls::std::boxing::Long x{6};
    x *= (ls::std::core::type::long_type) 3;

    ASSERT_EQ(18, x);
  }

  TEST_F(LongTest, operator_div_equals_with_reference)
  {
    ls::std::boxing::Long x{12};
    ls::std::boxing::Long y{3};
    x /= y;

    ASSERT_EQ(4, x);
  }

  TEST_F(LongTest, operator_div_equals_with_value)
  {
    ls::std::boxing::Long x{12};
    x /= (ls::std::core::type::long_type) 3;

    ASSERT_EQ(4, x);
  }

  TEST_F(LongTest, operator_div_equals_by_zero_with_reference)
  {
    EXPECT_THROW({
                   try
                   {
                     ls::std::boxing::Long x{9};
                     ls::std::boxing::Long y{0};

                     x = x /= y;
                   } catch (const ls::std::core::IllegalArithmeticOperationException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArithmeticOperationException);
  }

  TEST_F(LongTest, operator_div_equals_by_zero_with_value)
  {
    EXPECT_THROW({
                   try
                   {
                     ls::std::boxing::Long x{9};
                     x = x /= (ls::std::core::type::long_type) 0;
                   } catch (const ls::std::core::IllegalArithmeticOperationException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArithmeticOperationException);
  }

  // comparison operators

  TEST_F(LongTest, operator_equals_with_reference)
  {
    ls::std::boxing::Long x{12};
    ls::std::boxing::Long y{12};

    ASSERT_TRUE(x == y);
  }

  TEST_F(LongTest, operator_equals_with_value)
  {
    ls::std::boxing::Long x{12};
    ASSERT_TRUE(x == (ls::std::core::type::long_type) 12);
  }

  TEST_F(LongTest, operator_not_equals_with_reference)
  {
    ls::std::boxing::Long x{12};
    ls::std::boxing::Long y{3};

    ASSERT_TRUE(x != y);
  }

  TEST_F(LongTest, operator_not_equals_with_value)
  {
    ls::std::boxing::Long x{12};
    ASSERT_TRUE(x != (ls::std::core::type::long_type) 3);
  }

  TEST_F(LongTest, operator_greater_than_with_reference)
  {
    ls::std::boxing::Long x{12};
    ls::std::boxing::Long y{3};

    ASSERT_TRUE(x > y);
  }

  TEST_F(LongTest, operator_greater_than_with_value)
  {
    ls::std::boxing::Long x{12};
    ASSERT_TRUE(x > (ls::std::core::type::long_type) 3);
  }

  TEST_F(LongTest, operator_greater_than_equals_with_reference)
  {
    ls::std::boxing::Long x{12};
    ls::std::boxing::Long y{12};

    ASSERT_TRUE(x >= y);
  }

  TEST_F(LongTest, operator_greater_than_equals_with_value)
  {
    ls::std::boxing::Long x{12};
    ASSERT_TRUE(x >= (ls::std::core::type::long_type) 12);
  }

  TEST_F(LongTest, operator_less_than_with_reference)
  {
    ls::std::boxing::Long x{10};
    ls::std::boxing::Long y{12};

    ASSERT_TRUE(x < y);
  }

  TEST_F(LongTest, operator_less_than_with_value)
  {
    ls::std::boxing::Long x{10};
    ls::std::boxing::Long y{12};

    ASSERT_TRUE(x < (ls::std::core::type::long_type) 12);
  }

  TEST_F(LongTest, operator_less_than_equals_with_reference)
  {
    ls::std::boxing::Long x{10};
    ls::std::boxing::Long y{10};

    ASSERT_TRUE(x <= y);
  }

  TEST_F(LongTest, operator_less_than_equals_with_value)
  {
    ls::std::boxing::Long x{10};
    ASSERT_TRUE(x <= (ls::std::core::type::long_type) 10);
  }

  // logical operators

  TEST_F(LongTest, operator_negation)
  {
    ls::std::boxing::Long x{};
    ASSERT_TRUE(!x);
  }

  TEST_F(LongTest, operator_and_with_reference)
  {
    ls::std::boxing::Long x{1};
    ls::std::boxing::Long y{1};

    ASSERT_TRUE(x && y);
  }

  TEST_F(LongTest, operator_and_with_value)
  {
    ls::std::boxing::Long x{1};
    ASSERT_TRUE(x && (ls::std::core::type::long_type) 1);
  }

  TEST_F(LongTest, operator_and_with_boolean)
  {
    ls::std::boxing::Long x{1};
    ASSERT_TRUE(x && true);
  }

  TEST_F(LongTest, operator_or_with_reference)
  {
    ls::std::boxing::Long x{};
    ls::std::boxing::Long y{1};

    ASSERT_TRUE(x || y);
  }

  TEST_F(LongTest, operator_or_with_value)
  {
    ls::std::boxing::Long x{};
    ASSERT_TRUE(x || (ls::std::core::type::long_type) 1);
  }

  TEST_F(LongTest, operator_or_with_boolean)
  {
    ls::std::boxing::Long x{};
    ASSERT_TRUE(x || true);
  }

  // increment / decrement operator

  TEST_F(LongTest, operator_increment)
  {
    ls::std::boxing::Long x{};
    ++x;

    ASSERT_EQ(1, x);
  }

  TEST_F(LongTest, operator_decrement)
  {
    ls::std::boxing::Long x{};
    --x;

    ASSERT_EQ(-1, x);
  }

  // implementation

  TEST_F(LongTest, parse_with_positive_value)
  {
    ls::std::boxing::Long x{};

    x.parse("1989");
    ASSERT_EQ(1989, x);
  }

  TEST_F(LongTest, parse_with_negative_value)
  {
    ls::std::boxing::Long x{};

    x.parse("-17");
    ASSERT_EQ(-17, x);
  }

  TEST_F(LongTest, toString)
  {
    ls::std::boxing::Long x{112};
    ASSERT_STREQ("112", x.toString().c_str());
  }

  // additional functionality

  TEST_F(LongTest, getValue)
  {
    ls::std::boxing::Long x{3};
    ASSERT_EQ(3, x.getValue());
  }

  // additional testing

  TEST_F(LongTest, constApproach)
  {
    const ls::std::boxing::Long x{3};
    ASSERT_EQ(3, x);

    // x = 4; // wouldn't work
  }
}
