/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-14
 * Changed:         2020-08-14
 *
 * */

#include <gtest/gtest.h>
#include "../../../source/boxing/Double.hpp"
#include "../../../source/serialization/boxing/SerializableJSONDouble.hpp"
#include "../../../source/boxing/String.hpp"
#include "../../TestHelper.hpp"
#include "../../../source/io/File.hpp"
#include "../../../source/io/FileWriter.hpp"
#include "../../../source/io/StorableFile.hpp"

namespace {
  class DoubleTest : public ::testing::Test {
    protected:

      DoubleTest() = default;
      ~DoubleTest() override = default;

      void SetUp() override {}
      void TearDown() override {}
  };

  // assignment operators

  TEST_F(DoubleTest, operatorAssignment)
  {
    ls_std::Double x {13.023};
    ASSERT_EQ(13.023, x);

    x = 44.22;
    ASSERT_EQ(44.22, x);

    ls_std::Double y {3.0};
    x = y;
    ASSERT_EQ(3.0, x);
  }

  // arithmetic operators

  TEST_F(DoubleTest, operatorHyphen)
  {
    ls_std::Double x {3.25};
    ASSERT_DOUBLE_EQ(-3.25, -x);
  }

  TEST_F(DoubleTest, operatorAddition)
  {
    ls_std::Double x {3.1415};
    ls_std::Double y {2.223};
    ls_std::Double z {x + y};

    ASSERT_DOUBLE_EQ(5.3645, z);
    ASSERT_DOUBLE_EQ(5.3645, x + 2.223);
  }

  TEST_F(DoubleTest, operatorMultiplication)
  {
    ls_std::Double x {3.14};
    ls_std::Double y {2.22};
    ls_std::Double z {x * y};

    ASSERT_DOUBLE_EQ(6.9708, z);
    ASSERT_DOUBLE_EQ(6.9708, x * 2.22);
  }

  TEST_F(DoubleTest, operatorSubstraction)
  {
    ls_std::Double x {3.1415};
    ls_std::Double y {2.225};
    ls_std::Double z {x - y};

    ASSERT_DOUBLE_EQ(0.9165, z);
    ASSERT_DOUBLE_EQ(0.9165, x - 2.225);
  }

  TEST_F(DoubleTest, operatorDivision)
  {
    ls_std::Double x {2.25};
    ls_std::Double y {0.5};
    ls_std::Double z {x / y};

    ASSERT_DOUBLE_EQ(4.5, z);
    ASSERT_DOUBLE_EQ(4.5, x / 0.5);
  }

  // compound operators

  TEST_F(DoubleTest, operatorAddEqual)
  {
    ls_std::Double x {2.25000000};
    ls_std::Double y {-0.39000000};
    ASSERT_DOUBLE_EQ(2.25000000, x);

    x += 3.14000000;
    ASSERT_DOUBLE_EQ(5.39000000, x);

    x += y;
    ASSERT_DOUBLE_EQ(5.0000000, x);
  }

  TEST_F(DoubleTest, operatorSubEqual)
  {
    ls_std::Double x {2.25};
    ls_std::Double y {-0.04};
    ASSERT_DOUBLE_EQ(2.25, x);

    x -= 1.14;
    ASSERT_DOUBLE_EQ(1.11, x);

    x -= y;
    ASSERT_DOUBLE_EQ(1.15, x);
  }

  TEST_F(DoubleTest, operatorMulEqual)
  {
    ls_std::Double x {2.25000000};
    ls_std::Double y {0.04000000};
    ASSERT_DOUBLE_EQ(2.25000000, x);

    x *= 1.14000000;
    ASSERT_DOUBLE_EQ(2.56500000, x);

    x *= y;
    ASSERT_DOUBLE_EQ(0.102600000, x);
  }

  TEST_F(DoubleTest, operatorDivEqual)
  {
    ls_std::Double x {2.25};
    ls_std::Double y {1.5};
    ASSERT_DOUBLE_EQ(2.25, x);

    x /= 0.05;
    ASSERT_DOUBLE_EQ(45.0, x);

    x /= y;
    ASSERT_DOUBLE_EQ(30.0, x);
  }

  // comparison operators

  TEST_F(DoubleTest, operatorEqual)
  {
    ls_std::Double x {3.14159};
    ls_std::Double y {3.14159};

    ASSERT_TRUE(x == y);
    ASSERT_TRUE(y == x);
    ASSERT_TRUE(x == 3.14159);
    ASSERT_TRUE(3.14159 == x);
  }

  TEST_F(DoubleTest, operatorNotEqual)
  {
    ls_std::Double x {3.1415};
    ls_std::Double y {3.1414};

    ASSERT_TRUE(x != y);
    ASSERT_TRUE(y != x);
    ASSERT_TRUE(x != 3.1414);
    ASSERT_TRUE(3.1414 != x);
  }

  TEST_F(DoubleTest, operatorGreaterThan)
  {
    ls_std::Double x {3.1415};
    ls_std::Double y {3.1414};

    ASSERT_TRUE(x > y);
    ASSERT_TRUE(x > 3.1414);
  }

  TEST_F(DoubleTest, operatorGreaterThanNegative)
  {
    ls_std::Double x {3.1414};
    ls_std::Double y {3.1414};

    ASSERT_FALSE(x > y);
    ASSERT_FALSE(x > 3.1414);
  }

  TEST_F(DoubleTest, operatorGreaterThanEqual)
  {
    ls_std::Double x {3.1414};
    ls_std::Double y {3.1414};
    ls_std::Double z {3.1415};

    ASSERT_TRUE(x >= y);
    ASSERT_TRUE(z >= y);
    ASSERT_TRUE(x >= 3.1414);
    ASSERT_TRUE(z >= 3.1414);
  }

  TEST_F(DoubleTest, operatorGreaterThanEqualNegative)
  {
    ls_std::Double x {3.1414};
    ls_std::Double y {3.1415};

    ASSERT_FALSE(x >= y);
    ASSERT_FALSE(x >= 3.1415);
  }

  TEST_F(DoubleTest, operatorLessThan)
  {
    ls_std::Double x {3.1413};
    ls_std::Double y {3.1414};

    ASSERT_TRUE(x < y);
    ASSERT_TRUE(x < 3.1414);
  }

  TEST_F(DoubleTest, operatorLessThanNegative)
  {
    ls_std::Double x {3.1414};
    ls_std::Double y {3.1414};

    ASSERT_FALSE(x < y);
    ASSERT_FALSE(x < 3.1414);
  }

  TEST_F(DoubleTest, operatorLessThanEqual)
  {
    ls_std::Double x {3.1414};
    ls_std::Double y {3.1414};
    ls_std::Double z {3.1415};

    ASSERT_TRUE(x <= y);
    ASSERT_TRUE(x <= z);
    ASSERT_TRUE(x <= 3.1414);
    ASSERT_TRUE(x <= 3.1415);
  }

  TEST_F(DoubleTest, operatorLessThanEqualNegative)
  {
    ls_std::Double x {3.1415};
    ls_std::Double y {3.1414};

    ASSERT_FALSE(x <= y);
    ASSERT_FALSE(x <= 3.1414);
  }

  // increment / decrement operator

  TEST_F(DoubleTest, operatorIncrement)
  {
    ls_std::Double x {3.1415};
    ASSERT_DOUBLE_EQ(3.1415, x);

    ++x;
    ASSERT_DOUBLE_EQ(4.1415, x);

    ++x;
    ASSERT_DOUBLE_EQ(5.1415, x);
  }

  TEST_F(DoubleTest, operatorDecrement)
  {
    ls_std::Double x {3.1415};
    ASSERT_DOUBLE_EQ(3.1415, x);

    --x;
    ASSERT_DOUBLE_EQ(2.1415, x);

    --x;
    ASSERT_DOUBLE_EQ(1.1415, x);
  }

  // implementation

  TEST_F(DoubleTest, load)
  {
    // preparation

    std::shared_ptr<ls_std::Double> x = std::make_shared<ls_std::Double>();
    std::string path = TestHelper::getResourcesFolderLocation() + "tmp_storable_double.json";
    ls_std::File file {path};
    file.createNewFile();
    ls_std::FileWriter writer {file};
    writer.write(R"({"value":3.14159})");

    auto serializable = std::make_shared<ls_std::SerializableJSONDouble>(x);
    x->setSerializable(std::dynamic_pointer_cast<ls_std::ISerializable>(serializable));

    auto storable = std::make_shared<ls_std::StorableFile>(path);
    x->setStorable(std::dynamic_pointer_cast<ls_std::IStorable>(storable));

    // check

    x->load();
    ASSERT_DOUBLE_EQ(3.14159, *x);

    file.remove();
  }

  TEST_F(DoubleTest, marshal)
  {
    std::shared_ptr<ls_std::Double> x = std::make_shared<ls_std::Double>(3.14159);

    auto serializable = std::make_shared<ls_std::SerializableJSONDouble>(x);
    x->setSerializable(std::dynamic_pointer_cast<ls_std::ISerializable>(serializable));
    ls_std::String jsonString {x->marshal()};

    ASSERT_TRUE(jsonString.contains(R"({"value":3.14159)"));

    *x = 17.13149;
    jsonString = x->marshal();
    ASSERT_TRUE(jsonString.contains(R"({"value":17.1314)"));
  }

  TEST_F(DoubleTest, parse)
  {
    ls_std::Double x {};

    x.parse("3.1415");
    ASSERT_DOUBLE_EQ(3.1415, x);

    x.parse("-2.1415");
    ASSERT_DOUBLE_EQ(-2.1415, x);
  }

  TEST_F(DoubleTest, toString)
  {
    ls_std::Double x {13.1543};
    ASSERT_TRUE(x.toString().find("13.1543") != std::string::npos);
  }

  TEST_F(DoubleTest, unmarshal)
  {
    std::shared_ptr<ls_std::Double> x = std::make_shared<ls_std::Double>(3.14159);

    ASSERT_DOUBLE_EQ(3.14159, *x);

    auto serializable = std::make_shared<ls_std::SerializableJSONDouble>(x);
    x->setSerializable(std::dynamic_pointer_cast<ls_std::ISerializable>(serializable));
    x->unmarshal(R"({"value":17.4132})");

    ASSERT_DOUBLE_EQ(17.4132, *x);
  }

  // additional functionality

  TEST_F(DoubleTest, getEpsilon)
  {
    ls_std::Double x {};
    ASSERT_DOUBLE_EQ(0.00000001, x.getEpsilon());
  }

  TEST_F(DoubleTest, getValue)
  {
    ls_std::Double x {3.1415};
    ASSERT_DOUBLE_EQ(3.1415, x.getValue());
  }

  TEST_F(DoubleTest, setEpsilon)
  {
    ls_std::Double x {};
    x.setEpsilon(0.01);
    ASSERT_DOUBLE_EQ(0.01, x.getEpsilon());
  }
}
