/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-14
 * Changed:         2021-04-23
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

  TEST_F(FloatTest, operatorAssignment)
  {
    ls_std::Float x{13.023f};
    ASSERT_EQ(13.023f, x);

    x = 44.22f;
    ASSERT_EQ(44.22f, x);

    ls_std::Float y{3.0f};
    x = y;
    ASSERT_EQ(3.0f, x);
  }

  // arithmetic operators

  TEST_F(FloatTest, operatorHyphen)
  {
    ls_std::Float x{3.25f};
    ASSERT_FLOAT_EQ(-3.25f, -x);
  }

  TEST_F(FloatTest, operatorAddition)
  {
    ls_std::Float x{3.1415f};
    ls_std::Float y{2.223f};
    ls_std::Float z{x + y};

    ASSERT_FLOAT_EQ(5.3645f, z);
    ASSERT_FLOAT_EQ(5.3645f, x + 2.223f);
  }

  TEST_F(FloatTest, operatorMultiplication)
  {
    ls_std::Float x{3.14f};
    ls_std::Float y{2.22f};
    ls_std::Float z{x * y};

    ASSERT_FLOAT_EQ(6.9708f, z);
    ASSERT_FLOAT_EQ(6.9708f, x * 2.22f);
  }

  TEST_F(FloatTest, operatorSubstraction)
  {
    ls_std::Float x{3.1415f};
    ls_std::Float y{2.225f};
    ls_std::Float z{x - y};

    ASSERT_FLOAT_EQ(0.9165f, z);
    ASSERT_FLOAT_EQ(0.9165f, x - 2.225f);
  }

  TEST_F(FloatTest, operatorDivision)
  {
    ls_std::Float x{2.25f};
    ls_std::Float y{0.5f};
    ls_std::Float z{x / y};

    ASSERT_FLOAT_EQ(4.5f, z);
    ASSERT_FLOAT_EQ(4.5f, x / 0.5f);
  }

  // compound operators

  TEST_F(FloatTest, operatorAddEqual)
  {
    ls_std::Float x{2.25f};
    ls_std::Float y{-0.39f};
    ASSERT_FLOAT_EQ(2.25f, x);

    x += 3.14f;
    ASSERT_FLOAT_EQ(5.39f, x);

    x += y;
    ASSERT_FLOAT_EQ(5.0f, x);
  }

  TEST_F(FloatTest, operatorSubEqual)
  {
    ls_std::Float x{2.25f};
    ls_std::Float y{-0.04f};
    ASSERT_FLOAT_EQ(2.25f, x);

    x -= 1.14f;
    ASSERT_FLOAT_EQ(1.11f, x);

    x -= y;
    ASSERT_FLOAT_EQ(1.15f, x);
  }

  TEST_F(FloatTest, operatorMulEqual)
  {
    ls_std::Float x{2.25f};
    ls_std::Float y{0.04f};
    ASSERT_FLOAT_EQ(2.25f, x);

    x *= 1.14f;
    ASSERT_FLOAT_EQ(2.565f, x);

    x *= y;
    ASSERT_FLOAT_EQ(0.1026f, x);
  }

  TEST_F(FloatTest, operatorDivEqual)
  {
    ls_std::Float x{2.25f};
    ls_std::Float y{1.5f};
    ASSERT_FLOAT_EQ(2.25f, x);

    x /= 0.05f;
    ASSERT_FLOAT_EQ(45.0f, x);

    x /= y;
    ASSERT_FLOAT_EQ(30.0f, x);
  }

  // comparison operators

  TEST_F(FloatTest, operatorEqual)
  {
    ls_std::Float x{3.14159f};
    ls_std::Float y{3.14159f};

    ASSERT_TRUE(x == y);
    ASSERT_TRUE(y == x);
    ASSERT_TRUE(x == 3.14159f);
    ASSERT_TRUE(3.14159f == x);
  }

  TEST_F(FloatTest, operatorNotEqual)
  {
    ls_std::Float x{3.1415f};
    ls_std::Float y{3.1414f};

    ASSERT_TRUE(x != y);
    ASSERT_TRUE(y != x);
    ASSERT_TRUE(x != 3.1414f);
    ASSERT_TRUE(3.1414 != x);
  }

  TEST_F(FloatTest, operatorGreaterThan)
  {
    ls_std::Float x{3.1415f};
    ls_std::Float y{3.1414f};

    ASSERT_TRUE(x > y);
    ASSERT_TRUE(x > 3.1414f);
  }

  TEST_F(FloatTest, operatorGreaterThanNegative)
  {
    ls_std::Float x{3.1414f};
    ls_std::Float y{3.1414f};

    ASSERT_FALSE(x > y);
    ASSERT_FALSE(x > 3.1414f);
  }

  TEST_F(FloatTest, operatorGreaterThanEqual)
  {
    ls_std::Float x{3.1414f};
    ls_std::Float y{3.1414f};
    ls_std::Float z{3.1415f};

    ASSERT_TRUE(x >= y);
    ASSERT_TRUE(z >= y);
    ASSERT_TRUE(x >= 3.1414f);
    ASSERT_TRUE(z >= 3.1414f);
  }

  TEST_F(FloatTest, operatorGreaterThanEqualNegative)
  {
    ls_std::Float x{3.1414f};
    ls_std::Float y{3.1415f};

    ASSERT_FALSE(x >= y);
    ASSERT_FALSE(x >= 3.1415f);
  }

  TEST_F(FloatTest, operatorLessThan)
  {
    ls_std::Float x{3.1413f};
    ls_std::Float y{3.1414f};

    ASSERT_TRUE(x < y);
    ASSERT_TRUE(x < 3.1414f);
  }

  TEST_F(FloatTest, operatorLessThanNegative)
  {
    ls_std::Float x{3.1414f};
    ls_std::Float y{3.1414f};

    ASSERT_FALSE(x < y);
    ASSERT_FALSE(x < 3.1414f);
  }

  TEST_F(FloatTest, operatorLessThanEqual)
  {
    ls_std::Float x{3.1414f};
    ls_std::Float y{3.1414f};
    ls_std::Float z{3.1415f};

    ASSERT_TRUE(x <= y);
    ASSERT_TRUE(x <= z);
    ASSERT_TRUE(x <= 3.1414f);
    ASSERT_TRUE(x <= 3.1415f);
  }

  TEST_F(FloatTest, operatorLessThanEqualNegative)
  {
    ls_std::Float x{3.1415f};
    ls_std::Float y{3.1414f};

    ASSERT_FALSE(x <= y);
    ASSERT_FALSE(x <= 3.1414f);
  }

  // increment / decrement operator

  TEST_F(FloatTest, operatorIncrement)
  {
    ls_std::Float x{3.1415f};
    ASSERT_FLOAT_EQ(3.1415f, x);

    ++x;
    ASSERT_FLOAT_EQ(4.1415f, x);

    ++x;
    ASSERT_FLOAT_EQ(5.1415f, x);
  }

  TEST_F(FloatTest, operatorDecrement)
  {
    ls_std::Float x{3.1415f};
    ASSERT_FLOAT_EQ(3.1415f, x);

    --x;
    ASSERT_FLOAT_EQ(2.1415f, x);

    --x;
    ASSERT_FLOAT_EQ(1.1415f, x);
  }

  // implementation

  TEST_F(FloatTest, load)
  {
    // preparation

    std::shared_ptr<ls_std::Float> x = std::make_shared<ls_std::Float>();
    std::string path = TestHelper::getResourcesFolderLocation() + "tmp_storable_float.json";
    ls_std::File file{path};
    file.createNewFile();
    ls_std::FileWriter writer{file};
    writer.write(R"({"value":3.14159})");

    auto serializable = std::make_shared<ls_std::SerializableJSONFloat>(x);
    x->setSerializable(std::dynamic_pointer_cast<ls_std::ISerializable>(serializable));

    auto storable = std::make_shared<ls_std::StorableFile>(path);
    x->setStorable(std::dynamic_pointer_cast<ls_std::IStorable>(storable));

    // check

    x->load();
    ASSERT_FLOAT_EQ(3.14159f, *x);

    file.remove();
  }

  TEST_F(FloatTest, marshal)
  {
    std::shared_ptr<ls_std::Float> x = std::make_shared<ls_std::Float>(3.14159f);

    auto serializable = std::make_shared<ls_std::SerializableJSONFloat>(x);
    x->setSerializable(std::dynamic_pointer_cast<ls_std::ISerializable>(serializable));
    ls_std::String jsonString{x->marshal()};

    ASSERT_TRUE(jsonString.contains(R"({"value":3.14159)"));

    *x = 17.13149f;
    jsonString = x->marshal();
    ASSERT_TRUE(jsonString.contains(R"({"value":17.1314)"));
  }

  TEST_F(FloatTest, parse)
  {
    ls_std::Float x{};

    x.parse("3.1415f");
    ASSERT_FLOAT_EQ(3.1415f, x);

    x.parse("-2.1415f");
    ASSERT_FLOAT_EQ(-2.1415f, x);
  }

  TEST_F(FloatTest, toString)
  {
    ls_std::Float x{13.1543f};
    ASSERT_TRUE(x.toString().find("13.1543") != std::string::npos);
  }

  TEST_F(FloatTest, unmarshal)
  {
    std::shared_ptr<ls_std::Float> x = std::make_shared<ls_std::Float>(3.14159f);

    ASSERT_FLOAT_EQ(3.14159f, *x);

    auto serializable = std::make_shared<ls_std::SerializableJSONFloat>(x);
    x->setSerializable(std::dynamic_pointer_cast<ls_std::ISerializable>(serializable));
    x->unmarshal(R"({"value":17.4132})");

    ASSERT_FLOAT_EQ(17.4132, *x);
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
}
