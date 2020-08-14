/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-14
 * Changed:         2020-08-14
 *
 * */

#include <gtest/gtest.h>
#include <regex>
#include "../../../source/time/Date.hpp"

namespace {
  class DateTest : public ::testing::Test {
    protected:

      DateTest() = default;
      ~DateTest() override = default;

      void SetUp() override {}
      void TearDown() override {}
  };

  // arithmetic operators

  TEST_F(DateTest, operatorAdd)
  {
    ls_std::Date date {};
    time_t timestamp = date.getTime();

    date = date + 1;
    ASSERT_EQ(timestamp + 86400, date.getTime());
  }

  // additional functionality

  TEST_F(DateTest, after)
  {
    ls_std::Date date {};

    ls_std::Date date2 {};
    date2.setTime(1000000);

    ASSERT_TRUE(date.after(date2));
  }

  TEST_F(DateTest, before)
  {
    ls_std::Date date {};
    date.setTime(1000000);

    ls_std::Date date2 {};

    ASSERT_TRUE(date.before(date2));
  }

  TEST_F(DateTest, getTime)
  {
    ls_std::Date date {};
    ASSERT_TRUE(date.getTime() > 0);
  }

  TEST_F(DateTest, setTime)
  {
    ls_std::Date date {};
    ASSERT_TRUE(date.getTime() > 1000000);

    date.setTime(1000);
    ASSERT_EQ(1000, date.getTime());
  }

  TEST_F(DateTest, toString)
  {
    ls_std::Date date {};
    std::string regexSearchString = R"((\d{4}-\d{2}-\d{2} \d{2}:\d{2}:\d{2}))";
    std::regex _regex {regexSearchString};
    std::string dateString = date.toString();

    ASSERT_TRUE(std::regex_match(dateString, _regex));
  }
}
