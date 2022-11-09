/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2022-11-09
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std_core.hpp>
#include <vector>
#include <list>
#include <string>

using namespace ls::std::core;
using namespace ::std;

namespace
{
  class STLUtilsTest : public ::testing::Test
  {
    protected:

      STLUtilsTest() = default;
      ~STLUtilsTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(STLUtilsTest, contains)
  {
    vector<int> values{1, 13, 7, 8};
    list<string> names{"Tim", "Alex", "Nadine"};

    ASSERT_TRUE((STLUtils::contains(values, 1)));
    ASSERT_TRUE((STLUtils::contains(values, 13)));
    ASSERT_TRUE((STLUtils::contains(values, 7)));
    ASSERT_TRUE((STLUtils::contains(values, 8)));

    ASSERT_TRUE((STLUtils::contains(names, "Tim")));
    ASSERT_TRUE((STLUtils::contains(names, "Alex")));
    ASSERT_TRUE((STLUtils::contains(names, "Nadine")));
  }

  TEST_F(STLUtilsTest, containsNegative)
  {
    vector<int> values{1, 13, 7, 8};
    list<string> names{"Tim", "Alex", "Nadine"};

    ASSERT_FALSE((STLUtils::contains(values, 55)));
    ASSERT_FALSE((STLUtils::contains(values, 9)));

    ASSERT_FALSE((STLUtils::contains(names, "Lena")));
    ASSERT_FALSE((STLUtils::contains(names, "Mirco")));
  }

  TEST_F(STLUtilsTest, getListElementAt)
  {
    list<int> values{1, 13, 7, 8};
    list<string> names{"Tim", "Alex", "Nadine"};

    ASSERT_EQ(1, (STLUtils::getListElementAt(values, 0)));
    ASSERT_EQ(13, (STLUtils::getListElementAt(values, 1)));
    ASSERT_EQ(7, (STLUtils::getListElementAt(values, 2)));
    ASSERT_EQ(8, (STLUtils::getListElementAt(values, 3)));

    ASSERT_STREQ("Tim", STLUtils::getListElementAt(names, 0).c_str());
    ASSERT_STREQ("Alex", STLUtils::getListElementAt(names, 1).c_str());
    ASSERT_STREQ("Nadine", STLUtils::getListElementAt(names, 2).c_str());
  }

  TEST_F(STLUtilsTest, getListElementAtNegative)
  {
    list<int> values{1, 13, 7, 8};
    list<string> names{"Tim", "Alex", "Nadine"};

    ASSERT_EQ(0, (STLUtils::getListElementAt(values, 15)));
    ASSERT_STREQ("", STLUtils::getListElementAt(names, 15).c_str());
  }
}
