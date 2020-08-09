/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-09
 * Changed:         2020-08-09
 *
 * */

#include <gtest/gtest.h>
#include "../../../source/boxing/Integer.hpp"

namespace
{
  class IntegerTest : public ::testing::Test
  {
    protected:

      IntegerTest() = default;
      ~IntegerTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(IntegerTest, operatorHyphen)
  {
    ls_std::Integer x {13};
    ls_std::Integer y {-13};

    ASSERT_EQ(-13, -x);
    ASSERT_EQ(13, -y);
  }

  TEST_F(IntegerTest, operatorAssignment)
  {
    ls_std::Integer x {13};
    ASSERT_EQ(13, x);

    x = 44;
    ASSERT_EQ(44, x);
  }

  TEST_F(IntegerTest, operatorAddition)
  {
    ls_std::Integer x {13};
    ls_std::Integer y {7};
    ls_std::Integer z {-15};

    ASSERT_EQ(20, x + y);
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
}
