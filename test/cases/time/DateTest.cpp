/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-14
 * Changed:         2021-05-22
 *
 * */

#include <gtest/gtest.h>
#include <regex>
#include <ls_std/ls_std.hpp>

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
    ls_std::Date date{};
    time_t timestamp = date.getTime();

    date = date + 1;
    ASSERT_EQ(timestamp + 86400, date.getTime());
  }

  TEST_F(DateTest, operator_add_with_negative_value)
  {
    ls_std::Date date{};
    time_t timestamp = date.getTime();

    date = date + (-1);
    ASSERT_EQ(timestamp - 86400, date.getTime());
  }

  TEST_F(DateTest, operator_subtraction)
  {
    ls_std::Date date{};
    time_t timestamp = date.getTime();

    date = date - 1;
    ASSERT_EQ(timestamp - 86400, date.getTime());
  }

  TEST_F(DateTest, operator_subtraction_with_negative_value)
  {
    ls_std::Date date{};
    time_t timestamp = date.getTime();

    date = date - (-1);
    ASSERT_EQ(timestamp + 86400, date.getTime());
  }

  // additional functionality

  TEST_F(DateTest, after)
  {
    ls_std::Date date{}; // today

    ls_std::Date referenceDate{};
    referenceDate = referenceDate - 1; // yesterday

    ASSERT_TRUE(date.after(referenceDate));
  }

  TEST_F(DateTest, after_is_before_refernce_date)
  {
    ls_std::Date date{}; // is today
    ls_std::Date referenceDate{};

    referenceDate = referenceDate + 1; // is tomorrow

    ASSERT_FALSE(date.after(referenceDate));
  }

  TEST_F(DateTest, before)
  {
    ls_std::Date date{};
    date = date - 1; // yesterday

    ls_std::Date referenceDate{}; // today

    ASSERT_TRUE(date.before(referenceDate));
  }

  TEST_F(DateTest, before_is_after_reference_date)
  {
    ls_std::Date date{}; // today
    ls_std::Date referenceDate{};

    referenceDate = referenceDate - 1; // yesterday

    ASSERT_FALSE(date.before(referenceDate));
  }

  TEST_F(DateTest, getDay)
  {
    ls_std::Date date{};
    date.setTime(1597433693);

    ASSERT_EQ(14, date.getDay());
  }

  TEST_F(DateTest, getHour)
  {
    ls_std::Date date{};
    date.setTime(1597433693);

    ASSERT_EQ(21, date.getHour());
  }

  TEST_F(DateTest, getMinute)
  {
    ls_std::Date date{};
    date.setTime(1597433693);

    ASSERT_EQ(34, date.getMinute());
  }

  TEST_F(DateTest, getMonth)
  {
    ls_std::Date date{};
    date.setTime(1597433693);

    ASSERT_EQ(8, date.getMonth());
  }

  TEST_F(DateTest, getSecond)
  {
    ls_std::Date date{};
    date.setTime(1597433693);

    ASSERT_EQ(53, date.getSecond());
  }

  TEST_F(DateTest, getTime)
  {
    ls_std::Date date{};
    ASSERT_TRUE(date.getTime() > 0);
  }

  TEST_F(DateTest, getYear)
  {
    ls_std::Date date{};
    date.setTime(1597433693);

    ASSERT_EQ(2020, date.getYear());
  }

  TEST_F(DateTest, setTime)
  {
    ls_std::Date date{};
    ASSERT_TRUE(date.getTime() > 1000000);

    date.setTime(1000);
    ASSERT_EQ(1000, date.getTime());
  }

  TEST_F(DateTest, toString)
  {
    ls_std::Date date{};
    std::string regexSearchString = R"((\d{4}-\d{2}-\d{2} \d{2}:\d{2}:\d{2}))";
    std::regex _regex{regexSearchString};
    std::string dateString = date.toString();

    ASSERT_TRUE(std::regex_match(dateString, _regex));
  }
}
