/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-03-29
* Changed:         2023-03-31
*
* */

#include <gtest/gtest.h>
#include <ls-std/ls-std-time.hpp>

using ls::std::time::DateParameter;
using testing::Test;

namespace
{
  class DateParameterTest : public Test
  {
    public:

      DateParameterTest() = default;
      ~DateParameterTest() override = default;
  };

  TEST_F(DateParameterTest, constructor)
  {
    DateParameter parameter{1989, 6, 1, 10, 52, 13};

    ASSERT_EQ(1989, parameter.getYear());
    ASSERT_EQ(6, parameter.getMonth());
    ASSERT_EQ(1, parameter.getDay());
    ASSERT_EQ(10, parameter.getHour());
    ASSERT_EQ(52, parameter.getMinute());
    ASSERT_EQ(13, parameter.getSecond());
  }

  TEST_F(DateParameterTest, operator_equals)
  {
    DateParameter requiredBirthday{1989, 6, 1, 10, 52, 13};
    DateParameter hisBirthday{1989, 6, 1, 10, 52, 13};

    ASSERT_TRUE(requiredBirthday == hisBirthday);
  }

  TEST_F(DateParameterTest, operator_equals_not_equals)
  {
    DateParameter hisBirthday{1989, 6, 1, 10, 52, 00};
    DateParameter herBirthday{1990, 10, 26, 11, 25, 00};

    ASSERT_FALSE(herBirthday == hisBirthday);
  }

  TEST_F(DateParameterTest, getDay)
  {
    DateParameter parameter{};
    ASSERT_EQ(0, parameter.getDay());
  }

  TEST_F(DateParameterTest, getHour)
  {
    DateParameter parameter{};
    ASSERT_EQ(0, parameter.getHour());
  }

  TEST_F(DateParameterTest, getMinute)
  {
    DateParameter parameter{};
    ASSERT_EQ(0, parameter.getMinute());
  }

  TEST_F(DateParameterTest, getMonth)
  {
    DateParameter parameter{};
    ASSERT_EQ(0, parameter.getMonth());
  }

  TEST_F(DateParameterTest, getSecond)
  {
    DateParameter parameter{};
    ASSERT_EQ(0, parameter.getSecond());
  }

  TEST_F(DateParameterTest, getYear)
  {
    DateParameter parameter{};
    ASSERT_EQ(0, parameter.getYear());
  }

  TEST_F(DateParameterTest, setDay)
  {
    DateParameter parameter{};
    parameter.setDay(1);

    ASSERT_EQ(1, parameter.getDay());
  }

  TEST_F(DateParameterTest, setHour)
  {
    DateParameter parameter{};
    parameter.setHour(10);

    ASSERT_EQ(10, parameter.getHour());
  }

  TEST_F(DateParameterTest, setMinute)
  {
    DateParameter parameter{};
    parameter.setMinute(52);

    ASSERT_EQ(52, parameter.getMinute());
  }

  TEST_F(DateParameterTest, setMonth)
  {
    DateParameter parameter{};
    parameter.setMonth(6);

    ASSERT_EQ(6, parameter.getMonth());
  }

  TEST_F(DateParameterTest, setSecond)
  {
    DateParameter parameter{};
    parameter.setSecond(13);

    ASSERT_EQ(13, parameter.getSecond());
  }

  TEST_F(DateParameterTest, setYear)
  {
    DateParameter parameter{};
    parameter.setYear(1989);

    ASSERT_EQ(1989, parameter.getYear());
  }
}
