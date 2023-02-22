/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-14
 * Changed:         2023-02-22
 *
 * */

#include <gtest/gtest.h>
#include <ls-std/ls-std-boxing.hpp>
#include <ls-std/ls-std-core.hpp>

using namespace ls::std::boxing;
using namespace ls::std::core;
using namespace ::std;
using namespace ::testing;

namespace
{
  class FloatTest : public Test
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
    Float x{13.023f};

    x = 44.22f;
    ASSERT_EQ(44.22f, x.getValue());
  }

  // arithmetic operators

  TEST_F(FloatTest, operator_negative)
  {
    Float x{3.25f};
    ASSERT_FLOAT_EQ(-3.25f, -x);
  }

  TEST_F(FloatTest, operator_addition_with_reference)
  {
    Float x{3.1415f};
    Float y{2.223f};
    Float z{x + y};

    ASSERT_FLOAT_EQ(5.3645f, z.getValue());
  }

  TEST_F(FloatTest, operator_addition_with_value)
  {
    Float x{3.1415f};
    ASSERT_FLOAT_EQ(5.3645f, x + 2.223f);
  }

  TEST_F(FloatTest, operator_multiplication_with_reference)
  {
    Float x{3.14f};
    Float y{2.22f};
    Float z{x * y};

    ASSERT_FLOAT_EQ(6.9708f, z.getValue());
  }

  TEST_F(FloatTest, operator_multiplication_with_value)
  {
    Float x{3.14f};
    ASSERT_FLOAT_EQ(6.9708f, x * 2.22f);
  }

  TEST_F(FloatTest, operator_substraction_with_reference)
  {
    Float x{3.1415f};
    Float y{2.225f};
    Float z{x - y};

    ASSERT_FLOAT_EQ(0.9165f, z.getValue());
  }

  TEST_F(FloatTest, operator_substraction_with_value)
  {
    Float x{3.1415f};
    ASSERT_FLOAT_EQ(0.9165f, x - 2.225f);
  }

  TEST_F(FloatTest, operator_division_with_reference)
  {
    Float x{2.25f};
    Float y{0.5f};
    Float z{x / y};

    ASSERT_FLOAT_EQ(4.5f, z.getValue());
  }

  TEST_F(FloatTest, operator_division_with_value)
  {
    Float x{2.25f};
    ASSERT_FLOAT_EQ(4.5f, x / 0.5f);
  }

  // compound operators

  TEST_F(FloatTest, operator_add_assign_with_reference)
  {
    Float x{2.25f};
    Float y{3.14f};
    x += y;

    ASSERT_FLOAT_EQ(5.39f, x.getValue());
  }

  TEST_F(FloatTest, operator_add_assign_with_value)
  {
    Float x{2.25f};
    x += 3.14f;

    ASSERT_FLOAT_EQ(5.39f, x.getValue());
  }

  TEST_F(FloatTest, operator_sub_assign_with_reference)
  {
    Float x{2.25f};
    Float y{1.14f};
    x -= y;

    ASSERT_FLOAT_EQ(1.11f, x.getValue());
  }

  TEST_F(FloatTest, operator_sub_assign_with_value)
  {
    Float x{2.25f};
    x -= 1.14f;

    ASSERT_FLOAT_EQ(1.11f, x.getValue());
  }

  TEST_F(FloatTest, operator_mul_assign_with_reference)
  {
    Float x{2.25f};
    Float y{0.04f};
    x *= y;

    ASSERT_FLOAT_EQ(0.09f, x.getValue());
  }

  TEST_F(FloatTest, operator_mul_assign_with_value)
  {
    Float x{2.25f};
    x *= 1.14f;

    ASSERT_FLOAT_EQ(2.565f, x.getValue());
  }

  TEST_F(FloatTest, operator_division_assign_with_reference)
  {
    Float x{2.25f};
    Float y{1.5f};
    x /= y;

    ASSERT_FLOAT_EQ(1.5f, x.getValue());
  }

  TEST_F(FloatTest, operator_division_assign_with_value)
  {
    Float x{2.25f};
    x /= 0.05f;

    ASSERT_FLOAT_EQ(45.0f, x.getValue());
  }

  // comparison operators

  TEST_F(FloatTest, operator_equals_with_reference)
  {
    Float x{3.14159f};
    Float y{3.14159f};

    ASSERT_TRUE(x == y);
    ASSERT_TRUE(y == x);
  }

  TEST_F(FloatTest, operator_equals_with_value)
  {
    Float x{3.14159f};
    ASSERT_TRUE(x == 3.14159f);
  }

  TEST_F(FloatTest, operator_not_equals_with_reference)
  {
    Float x{3.1415f};
    Float y{3.1414f};

    ASSERT_TRUE(x != y);
    ASSERT_TRUE(y != x);
  }

  TEST_F(FloatTest, operator_not_equals_with_value)
  {
    Float x{3.1415f};
    ASSERT_TRUE(x != 3.1414f);
  }

  TEST_F(FloatTest, operator_greater_than_with_reference)
  {
    Float x{3.1415f};
    Float y{3.1414f};

    ASSERT_TRUE(x > y);
    ASSERT_TRUE(x > 3.1414f);
  }

  TEST_F(FloatTest, operator_greater_than_with_value)
  {
    Float x{3.1415f};
    ASSERT_TRUE(x > 3.1414f);
  }

  TEST_F(FloatTest, operator_greater_than_equals_with_reference)
  {
    Float x{3.1414f};
    Float y{3.1414f};
    Float z{3.1415f};

    ASSERT_TRUE(x >= y);
    ASSERT_TRUE(z >= y);
  }

  TEST_F(FloatTest, operator_greater_than_equals_with_value)
  {
    Float x{3.1414f};
    Float z{3.1415f};

    ASSERT_TRUE(x >= 3.1414f);
    ASSERT_TRUE(z >= 3.1414f);
  }

  TEST_F(FloatTest, operator_less_than_with_reference)
  {
    Float x{3.1413f};
    Float y{3.1414f};

    ASSERT_TRUE(x < y);
  }

  TEST_F(FloatTest, operator_less_than_with_value)
  {
    Float x{3.1413f};
    ASSERT_TRUE(x < 3.1414f);
  }

  TEST_F(FloatTest, operator_less_than_equals_with_reference)
  {
    Float x{3.1414f};
    Float y{3.1414f};
    Float z{3.1415f};

    ASSERT_TRUE(x <= y);
    ASSERT_TRUE(x <= z);
  }

  TEST_F(FloatTest, operator_less_than_equals_with_value)
  {
    Float x{3.1414f};

    ASSERT_TRUE(x <= 3.1414f);
    ASSERT_TRUE(x <= 3.1415f);
  }

  // increment / decrement operator

  TEST_F(FloatTest, operator_increment)
  {
    Float x{3.1415f};
    ++x;

    ASSERT_FLOAT_EQ(4.1415f, x.getValue());
  }

  TEST_F(FloatTest, operator_decrement)
  {
    Float x{3.1415f};
    --x;

    ASSERT_FLOAT_EQ(2.1415f, x.getValue());
  }

  // implementation

  TEST_F(FloatTest, parse)
  {
    Float number{};

    number.parse("3.1415f");
    ASSERT_FLOAT_EQ(3.1415f, number.getValue());
  }

  TEST_F(FloatTest, toString)
  {
    Float x{13.1543f};
    ASSERT_TRUE(x.toString().find("13.1543") != string::npos);
  }

  // additional functionality

  TEST_F(FloatTest, getEpsilon)
  {
    Float x{};
    ASSERT_FLOAT_EQ(0.00001f, x.getEpsilon());
  }

  TEST_F(FloatTest, getValue)
  {
    Float x{3.1415f};
    ASSERT_FLOAT_EQ(3.1415f, x.getValue());
  }

  TEST_F(FloatTest, setEpsilon)
  {
    Float x{};
    x.setEpsilon(0.01f);

    ASSERT_FLOAT_EQ(0.01f, x.getEpsilon());
  }

  TEST_F(FloatTest, setEpsilon_invalid_value)
  {
    Float x{};

    EXPECT_THROW(
        {
          try
          {
            x.setEpsilon(0.0f);
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }
}
