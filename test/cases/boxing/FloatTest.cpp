/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-14
 * Changed:         2021-07-08
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

      static std::pair<std::shared_ptr<ls_std::File>, std::shared_ptr<ls_std::Float>> createPersistentTestFloat()
      {
        std::shared_ptr<ls_std::Float> number = std::make_shared<ls_std::Float>();
        std::string path = TestHelper::getResourcesFolderLocation() + "tmp_storable_float.json";
        std::shared_ptr<ls_std::File> file = std::make_shared<ls_std::File>(path);
        file->createNewFile();
        ls_std::FileWriter writer{*file};
        writer.write(R"({"value":3.14159})");

        auto serializable = std::make_shared<ls_std::SerializableJsonFloat>(number);
        number->setSerializable(std::dynamic_pointer_cast<ls_std::ISerializable>(serializable));

        auto storable = std::make_shared<ls_std::StorableFile>(path);
        number->setStorable(std::dynamic_pointer_cast<ls_std::IStorable>(storable));

        return std::pair<std::shared_ptr<ls_std::File>, std::shared_ptr<ls_std::Float>>(file, number);
      }
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

  TEST_F(FloatTest, load)
  {
    // preparation

    auto storableFloat = createPersistentTestFloat();

    // check

    storableFloat.second->load();
    ASSERT_FLOAT_EQ(3.14159f, *storableFloat.second);

    storableFloat.first->remove();
  }

  TEST_F(FloatTest, marshal)
  {
    std::shared_ptr<ls_std::Float> number = std::make_shared<ls_std::Float>(3.14159f);

    auto serializable = std::make_shared<ls_std::SerializableJsonFloat>(number);
    number->setSerializable(std::dynamic_pointer_cast<ls_std::ISerializable>(serializable));
    ls_std::String jsonString{number->marshal()};

    ASSERT_TRUE(jsonString.contains(R"({"value":3.14159)"));
  }

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

  TEST_F(FloatTest, unmarshal)
  {
    std::shared_ptr<ls_std::Float> number = std::make_shared<ls_std::Float>(3.14159f);

    auto serializable = std::make_shared<ls_std::SerializableJsonFloat>(number);
    number->setSerializable(std::dynamic_pointer_cast<ls_std::ISerializable>(serializable));
    number->unmarshal(R"({"value":17.4132})");

    ASSERT_FLOAT_EQ(17.4132, *number);
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

  TEST_F(FloatTest, setSerializable_no_reference)
  {
    ls_std::Float x{};

    EXPECT_THROW({
                   try
                   {
                     x.setSerializable(nullptr);
                   }
                   catch (const ls_std::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls_std::IllegalArgumentException);
  }

  TEST_F(FloatTest, setStorable_no_reference)
  {
    ls_std::Float x{};

    EXPECT_THROW({
                   try
                   {
                     x.setStorable(nullptr);
                   }
                   catch (const ls_std::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls_std::IllegalArgumentException);
  }
}
