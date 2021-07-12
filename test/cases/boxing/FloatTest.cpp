/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-14
 * Changed:         2021-07-12
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>
#include <TestHelper.hpp>

namespace
{
  class FloatTest : public ::testing::Test
  {
    protected:

      FloatTest() = default;
      ~FloatTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  // assignment operators

  TEST_F(FloatTest, operator_assignment)
  {
    ls_std::Float x{13.023f};

    x = 44.22f;
    ASSERT_EQ(44.22f, x);
  }

  // arithmetic operators

  TEST_F(FloatTest, operator_negative)
  {
    ls_std::Float x{3.25f};
    ASSERT_FLOAT_EQ(-3.25f, -x);
  }

  TEST_F(FloatTest, operator_addition_with_reference)
  {
    ls_std::Float x{3.1415f};
    ls_std::Float y{2.223f};
    ls_std::Float z{x + y};

    ASSERT_FLOAT_EQ(5.3645f, z);
  }

  TEST_F(FloatTest, operator_addition_with_value)
  {
    ls_std::Float x{3.1415f};
    ASSERT_FLOAT_EQ(5.3645f, x + 2.223f);
  }

  TEST_F(FloatTest, operator_multiplication_with_reference)
  {
    ls_std::Float x{3.14f};
    ls_std::Float y{2.22f};
    ls_std::Float z{x * y};

    ASSERT_FLOAT_EQ(6.9708f, z);
  }

  TEST_F(FloatTest, operator_multiplication_with_value)
  {
    ls_std::Float x{3.14f};
    ASSERT_FLOAT_EQ(6.9708f, x * 2.22f);
  }

  TEST_F(FloatTest, operator_substraction_with_reference)
  {
    ls_std::Float x{3.1415f};
    ls_std::Float y{2.225f};
    ls_std::Float z{x - y};

    ASSERT_FLOAT_EQ(0.9165f, z);
  }

  TEST_F(FloatTest, operator_substraction_with_value)
  {
    ls_std::Float x{3.1415f};
    ASSERT_FLOAT_EQ(0.9165f, x - 2.225f);
  }

  TEST_F(FloatTest, operator_division_with_reference)
  {
    ls_std::Float x{2.25f};
    ls_std::Float y{0.5f};
    ls_std::Float z{x / y};

    ASSERT_FLOAT_EQ(4.5f, z);
  }

  TEST_F(FloatTest, operator_division_with_value)
  {
    ls_std::Float x{2.25f};
    ASSERT_FLOAT_EQ(4.5f, x / 0.5f);
  }

  // compound operators

  TEST_F(FloatTest, operator_add_assign_with_reference)
  {
    ls_std::Float x{2.25f};
    ls_std::Float y{3.14f};
    x += y;

    ASSERT_FLOAT_EQ(5.39f, x);
  }

  TEST_F(FloatTest, operator_add_assign_with_value)
  {
    ls_std::Float x{2.25f};
    x += 3.14f;

    ASSERT_FLOAT_EQ(5.39f, x);
  }

  TEST_F(FloatTest, operator_sub_assign_with_reference)
  {
    ls_std::Float x{2.25f};
    ls_std::Float y{1.14f};
    x -= y;

    ASSERT_FLOAT_EQ(1.11f, x);
  }

  TEST_F(FloatTest, operator_sub_assign_with_value)
  {
    ls_std::Float x{2.25f};
    x -= 1.14f;

    ASSERT_FLOAT_EQ(1.11f, x);
  }

  TEST_F(FloatTest, operator_mul_assign_with_reference)
  {
    ls_std::Float x{2.25f};
    ls_std::Float y{0.04f};
    x *= y;

    ASSERT_FLOAT_EQ(0.09f, x);
  }

  TEST_F(FloatTest, operator_mul_assign_with_value)
  {
    ls_std::Float x{2.25f};
    x *= 1.14f;

    ASSERT_FLOAT_EQ(2.565f, x);
  }

  TEST_F(FloatTest, operator_division_assign_with_reference)
  {
    ls_std::Float x{2.25f};
    ls_std::Float y{1.5f};
    x /= y;

    ASSERT_FLOAT_EQ(1.5f, x);
  }

  TEST_F(FloatTest, operator_division_assign_with_value)
  {
    ls_std::Float x{2.25f};
    x /= 0.05f;

    ASSERT_FLOAT_EQ(45.0f, x);
  }

  // comparison operators

  TEST_F(FloatTest, operator_equals_with_reference)
  {
    ls_std::Float x{3.14159f};
    ls_std::Float y{3.14159f};

    ASSERT_TRUE(x == y);
    ASSERT_TRUE(y == x);
  }

  TEST_F(FloatTest, operator_equals_with_value)
  {
    ls_std::Float x{3.14159f};
    ASSERT_TRUE(x == 3.14159f);
  }

  TEST_F(FloatTest, operator_not_equals_with_reference)
  {
    ls_std::Float x{3.1415f};
    ls_std::Float y{3.1414f};

    ASSERT_TRUE(x != y);
    ASSERT_TRUE(y != x);
  }

  TEST_F(FloatTest, operator_not_equals_with_value)
  {
    ls_std::Float x{3.1415f};
    ASSERT_TRUE(x != 3.1414f);
  }

  TEST_F(FloatTest, operator_greater_than_with_reference)
  {
    ls_std::Float x{3.1415f};
    ls_std::Float y{3.1414f};

    ASSERT_TRUE(x > y);
    ASSERT_TRUE(x > 3.1414f);
  }

  TEST_F(FloatTest, operator_greater_than_with_value)
  {
    ls_std::Float x{3.1415f};
    ASSERT_TRUE(x > 3.1414f);
  }

  TEST_F(FloatTest, operator_greater_than_equals_with_reference)
  {
    ls_std::Float x{3.1414f};
    ls_std::Float y{3.1414f};
    ls_std::Float z{3.1415f};

    ASSERT_TRUE(x >= y);
    ASSERT_TRUE(z >= y);
  }

  TEST_F(FloatTest, operator_greater_than_equals_with_value)
  {
    ls_std::Float x{3.1414f};
    ls_std::Float z{3.1415f};

    ASSERT_TRUE(x >= 3.1414f);
    ASSERT_TRUE(z >= 3.1414f);
  }

  TEST_F(FloatTest, operator_less_than_with_reference)
  {
    ls_std::Float x{3.1413f};
    ls_std::Float y{3.1414f};

    ASSERT_TRUE(x < y);
  }

  TEST_F(FloatTest, operator_less_than_with_value)
  {
    ls_std::Float x{3.1413f};
    ASSERT_TRUE(x < 3.1414f);
  }

  TEST_F(FloatTest, operator_less_than_equals_with_reference)
  {
    ls_std::Float x{3.1414f};
    ls_std::Float y{3.1414f};
    ls_std::Float z{3.1415f};

    ASSERT_TRUE(x <= y);
    ASSERT_TRUE(x <= z);
  }

  TEST_F(FloatTest, operator_less_than_equals_with_value)
  {
    ls_std::Float x{3.1414f};

    ASSERT_TRUE(x <= 3.1414f);
    ASSERT_TRUE(x <= 3.1415f);
  }

  // increment / decrement operator

  TEST_F(FloatTest, operator_increment)
  {
    ls_std::Float x{3.1415f};
    ++x;

    ASSERT_FLOAT_EQ(4.1415f, x);
  }

  TEST_F(FloatTest, operator_decrement)
  {
    ls_std::Float x{3.1415f};
    --x;

    ASSERT_FLOAT_EQ(2.1415f, x);
  }

  // implementation

  TEST_F(FloatTest, parse)
  {
    ls_std::Float number{};

    number.parse("3.1415f");
    ASSERT_FLOAT_EQ(3.1415f, number);
  }

  TEST_F(FloatTest, toString)
  {
    ls_std::Float x{13.1543f};
    ASSERT_TRUE(x.toString().find("13.1543") != std::string::npos);
  }

  // additional functionality

  TEST_F(FloatTest, getEpsilon)
  {
    ls_std::Float x{};
    ASSERT_FLOAT_EQ(0.00001f, x.getEpsilon());
  }

  TEST_F(FloatTest, getValue)
  {
    ls_std::Float x{3.1415f};
    ASSERT_FLOAT_EQ(3.1415f, x.getValue());
  }

  TEST_F(FloatTest, setEpsilon)
  {
    ls_std::Float x{};
    x.setEpsilon(0.01f);

    ASSERT_FLOAT_EQ(0.01f, x.getEpsilon());
  }

  TEST_F(FloatTest, setEpsilon_invalid_value)
  {
    ls_std::Float x{};

    EXPECT_THROW({
                   try
                   {
                     x.setEpsilon(0.0f);
                   }
                   catch (const ls_std::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls_std::IllegalArgumentException);
  }
}
