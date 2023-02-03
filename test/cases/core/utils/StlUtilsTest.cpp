/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2023-02-03
 *
 * */

#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>
#include <vector>
#include <list>
#include <string>

using namespace ls::std::core;
using namespace ::std;

namespace
{
  class StlUtilsTest : public ::testing::Test
  {
    protected:

      StlUtilsTest() = default;
      ~StlUtilsTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(StlUtilsTest, contains)
  {
    vector<int> values{1, 13, 7, 8};
    list<string> names{"Tim", "Alex", "Nadine"};

    ASSERT_TRUE((StlUtils::contains(values, 1)));
    ASSERT_TRUE((StlUtils::contains(values, 13)));
    ASSERT_TRUE((StlUtils::contains(values, 7)));
    ASSERT_TRUE((StlUtils::contains(values, 8)));

    ASSERT_TRUE((StlUtils::contains(names, "Tim")));
    ASSERT_TRUE((StlUtils::contains(names, "Alex")));
    ASSERT_TRUE((StlUtils::contains(names, "Nadine")));
  }

  TEST_F(StlUtilsTest, containsNegative)
  {
    vector<int> values{1, 13, 7, 8};
    list<string> names{"Tim", "Alex", "Nadine"};

    ASSERT_FALSE((StlUtils::contains(values, 55)));
    ASSERT_FALSE((StlUtils::contains(values, 9)));

    ASSERT_FALSE((StlUtils::contains(names, "Lena")));
    ASSERT_FALSE((StlUtils::contains(names, "Mirco")));
  }

  TEST_F(StlUtilsTest, getListElementAt)
  {
    list<int> values{1, 13, 7, 8};
    list<string> names{"Tim", "Alex", "Nadine"};

    ASSERT_EQ(1, (StlUtils::getListElementAt(values, 0)));
    ASSERT_EQ(13, (StlUtils::getListElementAt(values, 1)));
    ASSERT_EQ(7, (StlUtils::getListElementAt(values, 2)));
    ASSERT_EQ(8, (StlUtils::getListElementAt(values, 3)));

    ASSERT_STREQ("Tim", StlUtils::getListElementAt(names, 0).c_str());
    ASSERT_STREQ("Alex", StlUtils::getListElementAt(names, 1).c_str());
    ASSERT_STREQ("Nadine", StlUtils::getListElementAt(names, 2).c_str());
  }

  TEST_F(StlUtilsTest, getListElementAtNegative)
  {
    list<int> values{1, 13, 7, 8};
    list<string> names{"Tim", "Alex", "Nadine"};

    ASSERT_EQ(0, (StlUtils::getListElementAt(values, 15)));
    ASSERT_STREQ("", StlUtils::getListElementAt(names, 15).c_str());
  }
}
