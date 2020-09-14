/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-09
 * Changed:         2020-09-14
 *
 * */

#include <gtest/gtest.h>
#include "../../../source/boxing/Integer.hpp"
#include "../../../source/serialization/json/boxing/SerializableJSONInteger.hpp"
#include "../../../source/io/StorableFile.hpp"
#include "../../TestHelper.hpp"
#include "../../../source/io/FileWriter.hpp"

namespace {
  class IntegerTest : public ::testing::Test {
    protected:

      IntegerTest() = default;
      ~IntegerTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  // assignment operators

  TEST_F(IntegerTest, operatorAssignment)
  {
    ls_std::Integer x {13};
    ASSERT_EQ(13, x);

    x = 44;
    ASSERT_EQ(44, x);

    ls_std::Integer y {3};
    x = y;
    ASSERT_EQ(3, x);
  }

  // arithmetic operators

  TEST_F(IntegerTest, operatorHyphen)
  {
    ls_std::Integer x {13};
    ls_std::Integer y {-13};

    ASSERT_EQ(-13, -x);
    ASSERT_EQ(13, -y);
  }

  TEST_F(IntegerTest, operatorAddition)
  {
    ls_std::Integer x {13};
    ls_std::Integer y {7};
    ls_std::Integer z {-15};

    ASSERT_EQ(20, x + y);
    ASSERT_EQ(8, 1 + y);
    ASSERT_EQ(5, x + y + z);
    ASSERT_EQ(15, x + 2);
    ASSERT_EQ(0, x + 2 + z);
  }

  TEST_F(IntegerTest, operatorMultiplication)
  {
    ls_std::Integer x {3};
    ls_std::Integer y {7};
    ls_std::Integer z {5};

    ASSERT_EQ(21, x * y);
    ASSERT_EQ(105, x * y * z);
    ASSERT_EQ(6, x * 2);
    ASSERT_EQ(71, 1 + y * 2 * z);
  }

  TEST_F(IntegerTest, operatorSubtraction)
  {
    ls_std::Integer x {51};
    ls_std::Integer y {17};

    ASSERT_EQ(34, x - y);
    ASSERT_EQ(30, x - 21);
    ASSERT_EQ(13, x - 21 - y);
  }

  TEST_F(IntegerTest, operatorDivision)
  {
    ls_std::Integer x {81};
    ls_std::Integer y {9};

    ASSERT_EQ(9, x / y);
    ASSERT_EQ(3, 9 / 3);
    ASSERT_EQ(3, x / y / 3);
    ASSERT_EQ(1, 19 / 10);
  }

  TEST_F(IntegerTest, operatorModulus)
  {
    ls_std::Integer x {85};
    ls_std::Integer y {9};

    ASSERT_EQ(4, x % y);
    ASSERT_EQ(1, x % 3);
  }

  // compound operators

  TEST_F(IntegerTest, operatorAddEqual)
  {
    ls_std::Integer x {4};
    ls_std::Integer y {2};
    ASSERT_EQ(4, x);

    x += y;
    ASSERT_EQ(6, x);

    x += 4;
    ASSERT_EQ(10, x);

    x += -5;
    ASSERT_EQ(5, x);
  }

  TEST_F(IntegerTest, operatorSubEqual)
  {
    ls_std::Integer x {14};
    ls_std::Integer y {2};
    ASSERT_EQ(14, x);

    x -= y;
    ASSERT_EQ(12, x);

    x -= 6;
    ASSERT_EQ(6, x);

    x -= -3;
    ASSERT_EQ(9, x);
  }

  TEST_F(IntegerTest, operatorMulEqual)
  {
    ls_std::Integer x {6};
    ls_std::Integer y {3};
    ASSERT_EQ(6, x);

    x *= y;
    ASSERT_EQ(18, x);

    x *= 2;
    ASSERT_EQ(36, x);
  }

  TEST_F(IntegerTest, operatorDivEqual)
  {
    ls_std::Integer x {12};
    ls_std::Integer y {3};
    ASSERT_EQ(12, x);

    x /= y;
    ASSERT_EQ(4, x);

    x /= 2;
    ASSERT_EQ(2, x);
  }

  // comparison operators

  TEST_F(IntegerTest, operatorEqual)
  {
    ls_std::Integer x {12};
    ls_std::Integer y {3};
    ls_std::Integer z {3};

    ASSERT_TRUE(x == 12);
    ASSERT_TRUE(y == z);
    ASSERT_TRUE(z == y);
  }

  TEST_F(IntegerTest, operatorNotEqual)
  {
    ls_std::Integer x {12};
    ls_std::Integer y {3};
    ls_std::Integer z {3};

    ASSERT_TRUE(x != 14);
    ASSERT_TRUE(y != x);
    ASSERT_TRUE(z != x);
  }

  TEST_F(IntegerTest, operatorGreaterThan)
  {
    ls_std::Integer x {12};
    ls_std::Integer y {3};

    ASSERT_TRUE(x > 4);
    ASSERT_TRUE(x > y);
  }

  TEST_F(IntegerTest, operatorGreaterThanNegative)
  {
    ls_std::Integer x {12};
    ls_std::Integer y {3};

    ASSERT_FALSE(x > 14);
    ASSERT_FALSE(x > (y + 20));
  }

  TEST_F(IntegerTest, operatorGreaterThanEqual)
  {
    ls_std::Integer x {12};
    ls_std::Integer y {12};

    ASSERT_TRUE(x >= 12);
    ASSERT_TRUE(x >= y);
  }

  TEST_F(IntegerTest, operatorGreaterThanEqualNegative)
  {
    ls_std::Integer x {12};
    ls_std::Integer y {13};

    ASSERT_FALSE(x >= 13);
    ASSERT_FALSE(x >= y);
  }

  TEST_F(IntegerTest, operatorLessThan)
  {
    ls_std::Integer x {10};
    ls_std::Integer y {12};

    ASSERT_TRUE(x < 12);
    ASSERT_TRUE(x < y);
  }

  TEST_F(IntegerTest, operatorLessThanNegative)
  {
    ls_std::Integer x {10};
    ls_std::Integer y {10};

    ASSERT_FALSE(x < 10);
    ASSERT_FALSE(x < y);
  }

  TEST_F(IntegerTest, operatorLessThanEqual)
  {
    ls_std::Integer x {10};
    ls_std::Integer y {10};

    ASSERT_TRUE(x <= 11);
    ASSERT_TRUE(x <= y);
  }

  TEST_F(IntegerTest, operatorLessThanEqualNegative)
  {
    ls_std::Integer x {11};
    ls_std::Integer y {10};

    ASSERT_FALSE(x <= 10);
    ASSERT_FALSE(x <= y);
  }

  // logical operators

  TEST_F(IntegerTest, operatorNot)
  {
    ls_std::Integer x {};
    ASSERT_TRUE(!x);
  }

  TEST_F(IntegerTest, operatorNotNegative)
  {
    ls_std::Integer x {10};
    ASSERT_FALSE(!x);
  }

  TEST_F(IntegerTest, operatorAnd)
  {
    ls_std::Integer x {1};
    ls_std::Integer y {1};
    ASSERT_TRUE(x && 1);
    ASSERT_TRUE(x && true);
    ASSERT_TRUE(x && y);
  }

  TEST_F(IntegerTest, operatorAndNegative)
  {
    ls_std::Integer x {};
    ls_std::Integer y {1};
    ASSERT_FALSE(x && 1);
    ASSERT_FALSE(x && true);
    ASSERT_FALSE(x && y);
  }

  TEST_F(IntegerTest, operatorOr)
  {
    ls_std::Integer x {};
    ls_std::Integer y {1};
    ASSERT_TRUE(x || 1);
    ASSERT_TRUE(x || true);
    ASSERT_TRUE(x || y);
  }

  TEST_F(IntegerTest, operatorOrNegative)
  {
    ls_std::Integer x {};
    ls_std::Integer y {};
    ASSERT_FALSE(x || 0);
    ASSERT_FALSE(x || false);
    ASSERT_FALSE(x || y);
  }

  // increment / decrement operator

  TEST_F(IntegerTest, operatorIncrement)
  {
    ls_std::Integer x {};

    ++x;
    ASSERT_EQ(1, x);

    ++x;
    ASSERT_EQ(2, x);
  }

  TEST_F(IntegerTest, operatorDecrement)
  {
    ls_std::Integer x {};

    --x;
    ASSERT_EQ(-1, x);

    --x;
    ASSERT_EQ(-2, x);
  }

  // implementation

  TEST_F(IntegerTest, load)
  {
    // preparation

    std::shared_ptr<ls_std::Integer> x = std::make_shared<ls_std::Integer>();
    std::string path = TestHelper::getResourcesFolderLocation() + "tmp_storable_integer.json";
    ls_std::File file {path};
    file.createNewFile();
    ls_std::FileWriter writer {file};
    writer.write(R"({"value":1990})");

    auto serializable = std::make_shared<ls_std::SerializableJSONInteger>(x);
    x->setSerializable(std::dynamic_pointer_cast<ls_std::ISerializable>(serializable));

    auto storable = std::make_shared<ls_std::StorableFile>(path);
    x->setStorable(std::dynamic_pointer_cast<ls_std::IStorable>(storable));

    // check

    x->load();
    ASSERT_EQ(1990, *x);

    file.remove();
  }

  TEST_F(IntegerTest, marshal)
  {
    std::shared_ptr<ls_std::Integer> x = std::make_shared<ls_std::Integer>(3);

    auto serializable = std::make_shared<ls_std::SerializableJSONInteger>(x);
    x->setSerializable(std::dynamic_pointer_cast<ls_std::ISerializable>(serializable));

    ASSERT_STREQ(R"({"value":3})", x->marshal().c_str());

    *x = 17;
    ASSERT_STREQ(R"({"value":17})", x->marshal().c_str());
  }

  TEST_F(IntegerTest, parse)
  {
    ls_std::Integer x {};

    x.parse("1989");
    ASSERT_EQ(1989, x);

    x.parse("-17");
    ASSERT_EQ(-17, x);
  }

  TEST_F(IntegerTest, toString)
  {
    ls_std::Integer x {112};
    ASSERT_STREQ("112", x.toString().c_str());
  }

  TEST_F(IntegerTest, unmarshal)
  {
    std::shared_ptr<ls_std::Integer> x = std::make_shared<ls_std::Integer>(13);
    ASSERT_EQ(13, *x);

    auto serializable = std::make_shared<ls_std::SerializableJSONInteger>(x);
    x->setSerializable(std::dynamic_pointer_cast<ls_std::ISerializable>(serializable));

    x->unmarshal(R"({"value":1989})");

    ASSERT_EQ(1989, *x);
  }

  // additional functionality

  TEST_F(IntegerTest, getValue)
  {
    ls_std::Integer x {3};
    ASSERT_EQ(3, x.getValue());
  }

  // additional testing

  TEST_F(IntegerTest, constApproach)
  {
    const ls_std::Integer x {3};
    ASSERT_EQ(3, x);

//     x = 4; // wouldn't work
  }
}
