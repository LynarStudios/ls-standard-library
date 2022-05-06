/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-14
 * Changed:         2022-05-05
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>

namespace
{
  class DoubleTest : public ::testing::Test
  {
    protected:

      DoubleTest() = default;

      ~DoubleTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  // assignment operators

  TEST_F(DoubleTest, operator_assignment)
  {
    ls::std::boxing::Double x{};
    x = 44.22;

    ASSERT_EQ(44.22, x);
  }

  // arithmetic operators

  TEST_F(DoubleTest, operator_negative)
  {
    ls::std::boxing::Double x{3.25};
    ASSERT_DOUBLE_EQ(-3.25, -x);
  }

  TEST_F(DoubleTest, operator_addition_with_reference)
  {
    ls::std::boxing::Double x{3.1415};
    ls::std::boxing::Double y{2.223};
    ls::std::boxing::Double z{x + y};

    ASSERT_DOUBLE_EQ(5.3645, z);
  }

  TEST_F(DoubleTest, operator_addition_with_value)
  {
    ls::std::boxing::Double x{3.1415};
    ASSERT_DOUBLE_EQ(5.3645, x + 2.223);
  }

  TEST_F(DoubleTest, operator_multiplication_with_reference)
  {
    ls::std::boxing::Double x{3.14};
    ls::std::boxing::Double y{2.22};
    ls::std::boxing::Double z{x * y};

    ASSERT_DOUBLE_EQ(6.9708, z);
  }

  TEST_F(DoubleTest, operator_multiplication_with_value)
  {
    ls::std::boxing::Double x{3.14};
    ASSERT_DOUBLE_EQ(6.9708, x * 2.22);
  }

  TEST_F(DoubleTest, operator_substraction_with_reference)
  {
    ls::std::boxing::Double x{3.1415};
    ls::std::boxing::Double y{2.225};
    ls::std::boxing::Double z{x - y};

    ASSERT_DOUBLE_EQ(0.9165, z);
  }

  TEST_F(DoubleTest, operator_substraction_with_value)
  {
    ls::std::boxing::Double x{3.1415};
    ASSERT_DOUBLE_EQ(0.9165, x - 2.225);
  }

  TEST_F(DoubleTest, operator_division_with_reference)
  {
    ls::std::boxing::Double x{2.25};
    ls::std::boxing::Double y{0.5};
    ls::std::boxing::Double z{x / y};

    ASSERT_DOUBLE_EQ(4.5, z);
  }

  TEST_F(DoubleTest, operator_division_with_value)
  {
    ls::std::boxing::Double x{2.25};
    ASSERT_DOUBLE_EQ(4.5, x / 0.5);
  }

  // compound operators

  TEST_F(DoubleTest, operator_add_assign_with_reference)
  {
    ls::std::boxing::Double x{2.25000000};
    ls::std::boxing::Double y{3.14000000};

    x += y;
    ASSERT_DOUBLE_EQ(5.39000000, x);
  }

  TEST_F(DoubleTest, operator_add_assign_with_value)
  {
    ls::std::boxing::Double x{2.25000000};

    x += 3.14000000;
    ASSERT_DOUBLE_EQ(5.39000000, x);
  }

  TEST_F(DoubleTest, operator_sub_assign_with_reference)
  {
    ls::std::boxing::Double x{2.25};
    ls::std::boxing::Double y{0.04};

    x -= y;
    ASSERT_DOUBLE_EQ(2.21, x);
  }

  TEST_F(DoubleTest, operator_sub_assign_with_value)
  {
    ls::std::boxing::Double x{2.25};

    x -= 0.04;
    ASSERT_DOUBLE_EQ(2.21, x);
  }

  TEST_F(DoubleTest, operator_mul_assign_with_reference)
  {
    ls::std::boxing::Double x{2.25000000};
    ls::std::boxing::Double y{0.04000000};

    x *= y;
    ASSERT_DOUBLE_EQ(0.09000000, x);
  }

  TEST_F(DoubleTest, operator_mul_assign_with_value)
  {
    ls::std::boxing::Double x{2.25000000};

    x *= 0.04000000;
    ASSERT_DOUBLE_EQ(0.09000000, x);
  }

  TEST_F(DoubleTest, operator_division_assign_with_reference)
  {
    ls::std::boxing::Double x{2.25};
    ls::std::boxing::Double y{0.05};

    x /= y;
    ASSERT_DOUBLE_EQ(45.0, x);
  }

  TEST_F(DoubleTest, operator_division_assign_with_value)
  {
    ls::std::boxing::Double x{2.25};

    x /= 0.05;
    ASSERT_DOUBLE_EQ(45.0, x);
  }

  // comparison operators

  TEST_F(DoubleTest, operator_equals_with_reference)
  {
    ls::std::boxing::Double x{3.14159};
    ls::std::boxing::Double y{3.14159};

    ASSERT_TRUE(x == y);
    ASSERT_TRUE(y == x);
  }

  TEST_F(DoubleTest, operator_equals_with_value)
  {
    ls::std::boxing::Double x{3.14159};

    ASSERT_TRUE(x == 3.14159);
    ASSERT_TRUE(3.14159 == x);
  }

  TEST_F(DoubleTest, operator_not_equal_with_reference)
  {
    ls::std::boxing::Double x{3.1415};
    ls::std::boxing::Double y{3.1414};

    ASSERT_TRUE(x != y);
    ASSERT_TRUE(y != x);
  }

  TEST_F(DoubleTest, operator_not_equal_with_value)
  {
    ls::std::boxing::Double x{3.1415};

    ASSERT_TRUE(x != 3.1414);
    ASSERT_TRUE(3.1414 != x);
  }

  TEST_F(DoubleTest, operator_greater_than_with_reference)
  {
    ls::std::boxing::Double x{3.1415};
    ls::std::boxing::Double y{3.1414};

    ASSERT_TRUE(x > y);
  }

  TEST_F(DoubleTest, operator_greater_than_with_value)
  {
    ls::std::boxing::Double x{3.1415};
    ls::std::boxing::Double y{3.1414};

    ASSERT_TRUE(x > 3.1414);
  }

  TEST_F(DoubleTest, operator_greater_than_equals_with_reference)
  {
    ls::std::boxing::Double x{3.1414};
    ls::std::boxing::Double y{3.1414};
    ls::std::boxing::Double z{3.1415};

    ASSERT_TRUE(x >= y);
    ASSERT_TRUE(z >= y);
  }

  TEST_F(DoubleTest, operator_greater_than_equals_with_value)
  {
    ls::std::boxing::Double x{3.1414};
    ASSERT_TRUE(x >= 3.1414);
  }

  TEST_F(DoubleTest, operator_less_than_with_reference)
  {
    ls::std::boxing::Double x{3.1413};
    ls::std::boxing::Double y{3.1414};

    ASSERT_TRUE(x < y);
  }

  TEST_F(DoubleTest, operator_less_than_with_value)
  {
    ls::std::boxing::Double x{3.1413};
    ls::std::boxing::Double y{3.1414};

    ASSERT_TRUE(x < 3.1414);
  }

  TEST_F(DoubleTest, operator_less_than_equals_with_reference)
  {
    ls::std::boxing::Double x{3.1414};
    ls::std::boxing::Double y{3.1414};
    ls::std::boxing::Double z{3.1415};

    ASSERT_TRUE(x <= y);
    ASSERT_TRUE(x <= z);
  }

  TEST_F(DoubleTest, operator_less_than_equals_with_value)
  {
    ls::std::boxing::Double x{3.1414};
    ASSERT_TRUE(x <= 3.1414);
  }

  // increment / decrement operator

  TEST_F(DoubleTest, operator_increment)
  {
    ls::std::boxing::Double x{3.1415};

    ++x;
    ASSERT_DOUBLE_EQ(4.1415, x);
  }

  TEST_F(DoubleTest, operator_decrement)
  {
    ls::std::boxing::Double x{3.1415};

    --x;
    ASSERT_DOUBLE_EQ(2.1415, x);
  }

  // implementation

  TEST_F(DoubleTest, parse_with_positive_value)
  {
    ls::std::boxing::Double x{};

    x.parse("3.1415");
    ASSERT_DOUBLE_EQ(3.1415, x);
  }

  TEST_F(DoubleTest, parse_with_negative_value)
  {
    ls::std::boxing::Double x{};

    x.parse("-2.1415");
    ASSERT_DOUBLE_EQ(-2.1415, x);
  }

  TEST_F(DoubleTest, toString)
  {
    ls::std::boxing::Double x{13.1543};
    ASSERT_TRUE(x.toString().find("13.1543") != std::string::npos);
  }

  // additional functionality

  TEST_F(DoubleTest, getEpsilon)
  {
    ls::std::boxing::Double x{};
    ASSERT_DOUBLE_EQ(0.00000001, x.getEpsilon());
  }

  TEST_F(DoubleTest, getValue)
  {
    ls::std::boxing::Double x{3.1415};
    ASSERT_DOUBLE_EQ(3.1415, x.getValue());
  }

  TEST_F(DoubleTest, setEpsilon)
  {
    ls::std::boxing::Double x{};
    x.setEpsilon(0.01);

    ASSERT_DOUBLE_EQ(0.01, x.getEpsilon());
  }

  TEST_F(DoubleTest, setEpsilon_invalid_value)
  {
    ls::std::boxing::Double x{};

    EXPECT_THROW({
                   try
                   {
                     x.setEpsilon(0.0);
                   }
                   catch (const ls::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::IllegalArgumentException);
  }
}
