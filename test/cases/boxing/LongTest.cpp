/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2020-08-25
 *
 * */

#include <gtest/gtest.h>
#include "../../../source/boxing/Long.hpp"

namespace {
  class LongTest : public ::testing::Test {
    protected:

      LongTest() = default;
      ~LongTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  // assignment operators

  TEST_F(LongTest, operatorAssignment)
  {
    ls_std::Long x {13};
    ASSERT_EQ(13, x);

    x = 44;
    ASSERT_EQ(44, x);

    ls_std::Long y {3};
    x = y;
    ASSERT_EQ(3, x);
  }

  // arithmetic operators

  TEST_F(LongTest, operatorHyphen)
  {
    ls_std::Long x {13};
    ls_std::Long y {-13};

    ASSERT_EQ(-13, -x);
    ASSERT_EQ(13, -y);
  }

  TEST_F(LongTest, operatorAddition)
  {
    ls_std::Long x {13};
    ls_std::Long y {7};
    ls_std::Long z {-15};

    ASSERT_EQ(20, x + y);
    ASSERT_EQ(8, 1 + y);
    ASSERT_EQ(5, x + y + z);
    ASSERT_EQ(15, x + (long) 2);
    ASSERT_EQ(0, x + (long) 2 + z);
  }

  TEST_F(LongTest, operatorMultiplication)
  {
    ls_std::Long x {3};
    ls_std::Long y {7};
    ls_std::Long z {5};

    ASSERT_EQ(21, x * y);
    ASSERT_EQ(105, x * y * z);
    ASSERT_EQ(6, x * (long) 2);
    ASSERT_EQ(71, 1 + y * (long) 2 * z);
  }

  TEST_F(LongTest, operatorSubtraction)
  {
    ls_std::Long x {51};
    ls_std::Long y {17};

    ASSERT_EQ(34, x - y);
    ASSERT_EQ(30, x - (long) 21);
    ASSERT_EQ(13, x - (long) 21 - y);
  }

  TEST_F(LongTest, operatorDivision)
  {
    ls_std::Long x {81};
    ls_std::Long y {9};

    ASSERT_EQ(9, x / y);
    ASSERT_EQ(3, 9 / 3);
    ASSERT_EQ(3, x / y / 3);
    ASSERT_EQ(1, 19 / 10);
  }

  TEST_F(LongTest, operatorModulus)
  {
    ls_std::Long x {85};
    ls_std::Long y {9};

    ASSERT_EQ(4, x % y);
    ASSERT_EQ(1, x % (long) 3);
  }

  // compound operators

  TEST_F(LongTest, operatorAddEqual)
  {
    ls_std::Long x {4};
    ls_std::Long y {2};
    ASSERT_EQ(4, x);

    x += y;
    ASSERT_EQ(6, x);

    x += 4;
    ASSERT_EQ(10, x);

    x += -5;
    ASSERT_EQ(5, x);
  }

  TEST_F(LongTest, operatorSubEqual)
  {
    ls_std::Long x {14};
    ls_std::Long y {2};
    ASSERT_EQ(14, x);

    x -= y;
    ASSERT_EQ(12, x);

    x -= 6;
    ASSERT_EQ(6, x);

    x -= -3;
    ASSERT_EQ(9, x);
  }

  TEST_F(LongTest, operatorMulEqual)
  {
    ls_std::Long x {6};
    ls_std::Long y {3};
    ASSERT_EQ(6, x);

    x *= y;
    ASSERT_EQ(18, x);

    x *= 2;
    ASSERT_EQ(36, x);
  }

  TEST_F(LongTest, operatorDivEqual)
  {
    ls_std::Long x {12};
    ls_std::Long y {3};
    ASSERT_EQ(12, x);

    x /= y;
    ASSERT_EQ(4, x);

    x /= 2;
    ASSERT_EQ(2, x);
  }

  // comparison operators

  TEST_F(LongTest, operatorEqual)
  {
    ls_std::Long x {12};
    ls_std::Long y {3};
    ls_std::Long z {3};

    ASSERT_TRUE(x == (long) 12);
    ASSERT_TRUE(y == z);
    ASSERT_TRUE(z == y);
  }

  TEST_F(LongTest, operatorNotEqual)
  {
    ls_std::Long x {12};
    ls_std::Long y {3};
    ls_std::Long z {3};

    ASSERT_TRUE(x != (long) 14);
    ASSERT_TRUE(y != x);
    ASSERT_TRUE(z != x);
  }

  TEST_F(LongTest, operatorGreaterThan)
  {
    ls_std::Long x {12};
    ls_std::Long y {3};

    ASSERT_TRUE(x > (long) 4);
    ASSERT_TRUE(x > y);
  }

  TEST_F(LongTest, operatorGreaterThanNegative)
  {
    ls_std::Long x {12};
    ls_std::Long y {3};

    ASSERT_FALSE(x > (long) 14);
    ASSERT_FALSE(x > (y + (long) 20));
  }

  TEST_F(LongTest, operatorGreaterThanEqual)
  {
    ls_std::Long x {12};
    ls_std::Long y {12};

    ASSERT_TRUE(x >= (long) 12);
    ASSERT_TRUE(x >= y);
  }

  TEST_F(LongTest, operatorGreaterThanEqualNegative)
  {
    ls_std::Long x {12};
    ls_std::Long y {13};

    ASSERT_FALSE(x >= (long) 13);
    ASSERT_FALSE(x >= y);
  }

  TEST_F(LongTest, operatorLessThan)
  {
    ls_std::Long x {10};
    ls_std::Long y {12};

    ASSERT_TRUE(x < (long) 12);
    ASSERT_TRUE(x < y);
  }

  TEST_F(LongTest, operatorLessThanNegative)
  {
    ls_std::Long x {10};
    ls_std::Long y {10};

    ASSERT_FALSE(x < (long) 10);
    ASSERT_FALSE(x < y);
  }

  TEST_F(LongTest, operatorLessThanEqual)
  {
    ls_std::Long x {10};
    ls_std::Long y {10};

    ASSERT_TRUE(x <= (long) 11);
    ASSERT_TRUE(x <= y);
  }

  TEST_F(LongTest, operatorLessThanEqualNegative)
  {
    ls_std::Long x {11};
    ls_std::Long y {10};

    ASSERT_FALSE(x <= (long) 10);
    ASSERT_FALSE(x <= y);
  }

  // logical operators

  TEST_F(LongTest, operatorNot)
  {
    ls_std::Long x {};
    ASSERT_TRUE(!x);
  }

  TEST_F(LongTest, operatorNotNegative)
  {
    ls_std::Long x {10};
    ASSERT_FALSE(!x);
  }

  TEST_F(LongTest, operatorAnd)
  {
    ls_std::Long x {1};
    ls_std::Long y {1};
    ASSERT_TRUE(x && (long) 1);
    ASSERT_TRUE(x && true);
    ASSERT_TRUE(x && y);
  }

  TEST_F(LongTest, operatorAndNegative)
  {
    ls_std::Long x {};
    ls_std::Long y {1};
    ASSERT_FALSE(x && (long) 1);
    ASSERT_FALSE(x && true);
    ASSERT_FALSE(x && y);
  }

  TEST_F(LongTest, operatorOr)
  {
    ls_std::Long x {};
    ls_std::Long y {1};
    ASSERT_TRUE(x || (long) 1);
    ASSERT_TRUE(x || true);
    ASSERT_TRUE(x || y);
  }

  TEST_F(LongTest, operatorOrNegative)
  {
    ls_std::Long x {};
    ls_std::Long y {};
    ASSERT_FALSE(x || (long) 0);
    ASSERT_FALSE(x || false);
    ASSERT_FALSE(x || y);
  }

  // increment / decrement operator

  TEST_F(LongTest, operatorIncrement)
  {
    ls_std::Long x {};

    ++x;
    ASSERT_EQ(1, x);

    ++x;
    ASSERT_EQ(2, x);
  }

  TEST_F(LongTest, operatorDecrement)
  {
    ls_std::Long x {};

    --x;
    ASSERT_EQ(-1, x);

    --x;
    ASSERT_EQ(-2, x);
  }

  // implementation

  TEST_F(LongTest, parse)
  {
    ls_std::Long x {};

    x.parse("1989");
    ASSERT_EQ(1989, x);

    x.parse("-17");
    ASSERT_EQ(-17, x);
  }

  TEST_F(LongTest, toString)
  {
    ls_std::Long x {112};
    ASSERT_STREQ("112", x.toString().c_str());
  }

  // additional functionality

  TEST_F(LongTest, getValue)
  {
    ls_std::Long x {3};
    ASSERT_EQ(3, x.getValue());
  }

  // additional testing

  TEST_F(LongTest, constApproach)
  {
    const ls_std::Long x {3};
    ASSERT_EQ(3, x);

//     x = 4; // wouldn't work
  }
}
