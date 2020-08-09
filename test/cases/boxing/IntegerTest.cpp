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
}