/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-14
 * Changed:         2023-02-03
 *
 * */

#include <gtest/gtest.h>
#include <regex>
#include <ls-std/ls-std-time.hpp>

using namespace ls::std::time;
using namespace ::std;

namespace
{
  class DateTest : public ::testing::Test
  {
    protected:

      DateTest() = default;
      ~DateTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  // arithmetic operators

  TEST_F(DateTest, operator_add)
  {
    Date date{};
    time_t timestamp = date.getTime();

    date = date + 1;
    ASSERT_EQ(timestamp + 86400, date.getTime());
  }

  TEST_F(DateTest, operator_add_with_negative_value)
  {
    Date date{};
    time_t timestamp = date.getTime();

    date = date + (-1);
    ASSERT_EQ(timestamp - 86400, date.getTime());
  }

  TEST_F(DateTest, operator_subtraction)
  {
    Date date{};
    time_t timestamp = date.getTime();

    date = date - 1;
    ASSERT_EQ(timestamp - 86400, date.getTime());
  }

  TEST_F(DateTest, operator_subtraction_with_negative_value)
  {
    Date date{};
    time_t timestamp = date.getTime();

    date = date - (-1);
    ASSERT_EQ(timestamp + 86400, date.getTime());
  }

  TEST_F(DateTest, operator_plus_equals)
  {
    Date date{};
    time_t timestamp = date.getTime();

    date += 2;
    time_t expectedTimestamp = timestamp + 86400 * 2;
    ASSERT_EQ(expectedTimestamp, date.getTime());
  }

  TEST_F(DateTest, operator_plus_equals_with_negative_value)
  {
    Date date{};
    time_t timestamp = date.getTime();

    date += -2;
    time_t expectedTimestamp = timestamp - 86400 * 2;
    ASSERT_EQ(expectedTimestamp, date.getTime());
  }

  TEST_F(DateTest, operator_minus_equals)
  {
    Date date{};
    time_t timestamp = date.getTime();

    date -= 2;
    time_t expectedTimestamp = timestamp - 86400 * 2;
    ASSERT_EQ(expectedTimestamp, date.getTime());
  }

  TEST_F(DateTest, operator_minus_equals_with_negative_value)
  {
    Date date{};
    time_t timestamp = date.getTime();

    date -= -2;
    time_t expectedTimestamp = timestamp + 86400 * 2;
    ASSERT_EQ(expectedTimestamp, date.getTime());
  }

  // additional functionality

  TEST_F(DateTest, after)
  {
    Date date{}; // today

    Date referenceDate{};
    referenceDate = referenceDate - 1; // yesterday

    ASSERT_TRUE(date.after(referenceDate));
  }

  TEST_F(DateTest, after_is_before_refernce_date)
  {
    Date date{}; // is today
    Date referenceDate{};

    referenceDate = referenceDate + 1; // is tomorrow

    ASSERT_FALSE(date.after(referenceDate));
  }

  TEST_F(DateTest, before)
  {
    Date date{};
    date = date - 1; // yesterday

    Date referenceDate{}; // today

    ASSERT_TRUE(date.before(referenceDate));
  }

  TEST_F(DateTest, before_is_after_reference_date)
  {
    Date date{}; // today
    Date referenceDate{};

    referenceDate = referenceDate - 1; // yesterday

    ASSERT_FALSE(date.before(referenceDate));
  }

  TEST_F(DateTest, getDay)
  {
    Date date{};
    date.setTime(1597433693);

    ASSERT_EQ(14, date.getDay());
  }

  TEST_F(DateTest, getHour)
  {
    Date date{};
    date.setTime(1597433693);

    ASSERT_EQ(21, date.getHour());
  }

  TEST_F(DateTest, getMinute)
  {
    Date date{};
    date.setTime(1597433693);

    ASSERT_EQ(34, date.getMinute());
  }

  TEST_F(DateTest, getMonth)
  {
    Date date{};
    date.setTime(1597433693);

    ASSERT_EQ(8, date.getMonth());
  }

  TEST_F(DateTest, getSecond)
  {
    Date date{};
    date.setTime(1597433693);

    ASSERT_EQ(53, date.getSecond());
  }

  TEST_F(DateTest, getTime)
  {
    Date date{};
    ASSERT_TRUE(date.getTime() > 0);
  }

  TEST_F(DateTest, getYear)
  {
    Date date{};
    date.setTime(1597433693);

    ASSERT_EQ(2020, date.getYear());
  }

  TEST_F(DateTest, setTime)
  {
    Date date{};
    ASSERT_TRUE(date.getTime() > 1000000);

    date.setTime(1000);
    ASSERT_EQ(1000, date.getTime());
  }

  TEST_F(DateTest, toString)
  {
    Date date{};
    string regexSearchString = R"((\d{4}-\d{2}-\d{2} \d{2}:\d{2}:\d{2}))";
    regex _regex{regexSearchString};
    string dateString = date.toString();

    ASSERT_TRUE(regex_match(dateString, _regex));
  }
}
