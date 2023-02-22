/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2023-02-22
 *
 * */

#include <gtest/gtest.h>
#include <ls-std/ls-std-boxing.hpp>
#include <ls-std/ls-std-core.hpp>

using ls::std::boxing::Long;
using ls::std::core::IllegalArithmeticOperationException;
using ls::std::core::type::long_type;
using testing::Test;

namespace
{
  class LongTest : public Test
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
    Long x{13};
    Long y{3};
    x = y;

    ASSERT_EQ(3, x.getValue());
  }

  TEST_F(LongTest, operator_assignment_with_value)
  {
    Long x{13};
    x = (long_type) 3;

    ASSERT_EQ(3, x.getValue());
  }

  // arithmetic operators

  TEST_F(LongTest, operator_negative)
  {
    Long x{13};
    Long y{-13};

    ASSERT_EQ(-13, -x);
    ASSERT_EQ(13, -y);
  }

  TEST_F(LongTest, operator_add_with_reference)
  {
    Long x{13};
    Long y{7};

    ASSERT_EQ(20, x + y);
  }

  TEST_F(LongTest, operator_add_with_value)
  {
    Long x{13};
    ASSERT_EQ(20, x + (long_type) 7);
  }

  TEST_F(LongTest, operator_mul_with_reference)
  {
    Long x{3};
    Long y{7};

    ASSERT_EQ(21, x * y);
  }

  TEST_F(LongTest, operator_mul_with_value)
  {
    Long x{3};
    ASSERT_EQ(21, x * (long_type) 7);
  }

  TEST_F(LongTest, operator_sub_with_reference)
  {
    Long x{51};
    Long y{17};

    ASSERT_EQ(34, x - y);
  }

  TEST_F(LongTest, operator_sub_with_value)
  {
    Long x{51};
    ASSERT_EQ(34, x - (long_type) 17);
  }

  TEST_F(LongTest, operator_div_with_reference)
  {
    Long x{81};
    Long y{9};

    ASSERT_EQ(9, x / y);
  }

  TEST_F(LongTest, operator_div_with_value)
  {
    Long x{81};
    ASSERT_EQ(9, x / (long_type) 9);
  }

  TEST_F(LongTest, operator_div_by_zero_with_reference)
  {
    EXPECT_THROW(
        {
          try
          {
            Long x{9};
            Long y{0};

            x = x / y;
          }
          catch (const IllegalArithmeticOperationException &_exception)
          {
            throw;
          }
        },
        IllegalArithmeticOperationException);
  }

  TEST_F(LongTest, operator_div_by_zero_with_value)
  {
    EXPECT_THROW(
        {
          try
          {
            Long x{9};
            x = x / (long_type) 0;
          }
          catch (const IllegalArithmeticOperationException &_exception)
          {
            throw;
          }
        },
        IllegalArithmeticOperationException);
  }

  TEST_F(LongTest, operator_mod_with_reference)
  {
    Long x{85};
    Long y{9};

    ASSERT_EQ(4, x % y);
  }

  TEST_F(LongTest, operator_mod_with_value)
  {
    Long x{85};
    ASSERT_EQ(4, x % (long_type) 9);
  }

  // compound operators

  TEST_F(LongTest, operator_add_equals_with_reference)
  {
    Long x{4};
    Long y{2};
    x += y;

    ASSERT_EQ(6, x.getValue());
  }

  TEST_F(LongTest, operator_add_equals_with_value)
  {
    Long x{4};
    x += (long_type) 2;

    ASSERT_EQ(6, x.getValue());
  }

  TEST_F(LongTest, operator_sub_equals_with_reference)
  {
    Long x{14};
    Long y{2};
    x -= y;

    ASSERT_EQ(12, x.getValue());
  }

  TEST_F(LongTest, operator_sub_equals_with_value)
  {
    Long x{14};
    x -= (long_type) 2;

    ASSERT_EQ(12, x.getValue());
  }

  TEST_F(LongTest, operator_mul_equals_with_reference)
  {
    Long x{6};
    Long y{3};
    x *= y;

    ASSERT_EQ(18, x.getValue());
  }

  TEST_F(LongTest, operator_mul_equals_with_value)
  {
    Long x{6};
    x *= (long_type) 3;

    ASSERT_EQ(18, x.getValue());
  }

  TEST_F(LongTest, operator_div_equals_with_reference)
  {
    Long x{12};
    Long y{3};
    x /= y;

    ASSERT_EQ(4, x.getValue());
  }

  TEST_F(LongTest, operator_div_equals_with_value)
  {
    Long x{12};
    x /= (long_type) 3;

    ASSERT_EQ(4, x.getValue());
  }

  TEST_F(LongTest, operator_div_equals_by_zero_with_reference)
  {
    EXPECT_THROW(
        {
          try
          {
            Long x{9};
            Long y{0};

            x = x /= y;
          }
          catch (const IllegalArithmeticOperationException &_exception)
          {
            throw;
          }
        },
        IllegalArithmeticOperationException);
  }

  TEST_F(LongTest, operator_div_equals_by_zero_with_value)
  {
    EXPECT_THROW(
        {
          try
          {
            Long x{9};
            x = x /= (long_type) 0;
          }
          catch (const IllegalArithmeticOperationException &_exception)
          {
            throw;
          }
        },
        IllegalArithmeticOperationException);
  }

  // comparison operators

  TEST_F(LongTest, operator_equals_with_reference)
  {
    Long x{12};
    Long y{12};

    ASSERT_TRUE(x == y);
  }

  TEST_F(LongTest, operator_equals_with_value)
  {
    Long x{12};
    ASSERT_TRUE(x == (long_type) 12);
  }

  TEST_F(LongTest, operator_not_equals_with_reference)
  {
    Long x{12};
    Long y{3};

    ASSERT_TRUE(x != y);
  }

  TEST_F(LongTest, operator_not_equals_with_value)
  {
    Long x{12};
    ASSERT_TRUE(x != (long_type) 3);
  }

  TEST_F(LongTest, operator_greater_than_with_reference)
  {
    Long x{12};
    Long y{3};

    ASSERT_TRUE(x > y);
  }

  TEST_F(LongTest, operator_greater_than_with_value)
  {
    Long x{12};
    ASSERT_TRUE(x > (long_type) 3);
  }

  TEST_F(LongTest, operator_greater_than_equals_with_reference)
  {
    Long x{12};
    Long y{12};

    ASSERT_TRUE(x >= y);
  }

  TEST_F(LongTest, operator_greater_than_equals_with_value)
  {
    Long x{12};
    ASSERT_TRUE(x >= (long_type) 12);
  }

  TEST_F(LongTest, operator_less_than_with_reference)
  {
    Long x{10};
    Long y{12};

    ASSERT_TRUE(x < y);
  }

  TEST_F(LongTest, operator_less_than_with_value)
  {
    Long x{10};
    Long y{12};

    ASSERT_TRUE(x < (long_type) 12);
  }

  TEST_F(LongTest, operator_less_than_equals_with_reference)
  {
    Long x{10};
    Long y{10};

    ASSERT_TRUE(x <= y);
  }

  TEST_F(LongTest, operator_less_than_equals_with_value)
  {
    Long x{10};
    ASSERT_TRUE(x <= (long_type) 10);
  }

  // logical operators

  TEST_F(LongTest, operator_negation)
  {
    Long x{};
    ASSERT_TRUE(!x);
  }

  TEST_F(LongTest, operator_and_with_reference)
  {
    Long x{1};
    Long y{1};

    ASSERT_TRUE(x && y);
  }

  TEST_F(LongTest, operator_and_with_value)
  {
    Long x{1};
    ASSERT_TRUE(x && (long_type) 1);
  }

  TEST_F(LongTest, operator_and_with_boolean)
  {
    Long x{1};
    ASSERT_TRUE(x && true);
  }

  TEST_F(LongTest, operator_or_with_reference)
  {
    Long x{};
    Long y{1};

    ASSERT_TRUE(x || y);
  }

  TEST_F(LongTest, operator_or_with_value)
  {
    Long x{};
    ASSERT_TRUE(x || (long_type) 1);
  }

  TEST_F(LongTest, operator_or_with_boolean)
  {
    Long x{};
    ASSERT_TRUE(x || true);
  }

  // increment / decrement operator

  TEST_F(LongTest, operator_increment)
  {
    Long x{};
    ++x;

    ASSERT_EQ(1, x.getValue());
  }

  TEST_F(LongTest, operator_decrement)
  {
    Long x{};
    --x;

    ASSERT_EQ(-1, x.getValue());
  }

  // implementation

  TEST_F(LongTest, parse_with_positive_value)
  {
    Long x{};

    x.parse("1989");
    ASSERT_EQ(1989, x.getValue());
  }

  TEST_F(LongTest, parse_with_negative_value)
  {
    Long x{};

    x.parse("-17");
    ASSERT_EQ(-17, x.getValue());
  }

  TEST_F(LongTest, toString)
  {
    Long x{112};
    ASSERT_STREQ("112", x.toString().c_str());
  }

  // additional functionality

  TEST_F(LongTest, getValue)
  {
    Long x{3};
    ASSERT_EQ(3, x.getValue());
  }

  // additional testing

  TEST_F(LongTest, constApproach)
  {
    const Long x{3};
    ASSERT_EQ(3, x.getValue());

    // x = 4; // wouldn't work
  }
}
