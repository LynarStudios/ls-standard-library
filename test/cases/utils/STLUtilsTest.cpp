/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2021-04-23
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>
#include <vector>
#include <list>
#include <string>

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
    std::vector<int> values{1, 13, 7, 8};
    std::list<std::string> names{"Tim", "Alex", "Nadine"};

    ASSERT_TRUE((ls_std::STLUtils::contains(values, 1)));
    ASSERT_TRUE((ls_std::STLUtils::contains(values, 13)));
    ASSERT_TRUE((ls_std::STLUtils::contains(values, 7)));
    ASSERT_TRUE((ls_std::STLUtils::contains(values, 8)));

    ASSERT_TRUE((ls_std::STLUtils::contains(names, "Tim")));
    ASSERT_TRUE((ls_std::STLUtils::contains(names, "Alex")));
    ASSERT_TRUE((ls_std::STLUtils::contains(names, "Nadine")));
  }

  TEST_F(STLUtilsTest, containsNegative)
  {
    std::vector<int> values{1, 13, 7, 8};
    std::list<std::string> names{"Tim", "Alex", "Nadine"};

    ASSERT_FALSE((ls_std::STLUtils::contains(values, 55)));
    ASSERT_FALSE((ls_std::STLUtils::contains(values, 9)));

    ASSERT_FALSE((ls_std::STLUtils::contains(names, "Lena")));
    ASSERT_FALSE((ls_std::STLUtils::contains(names, "Mirco")));
  }

  TEST_F(STLUtilsTest, getListElementAt)
  {
    std::list<int> values{1, 13, 7, 8};
    std::list<std::string> names{"Tim", "Alex", "Nadine"};

    ASSERT_EQ(1, (ls_std::STLUtils::getListElementAt(values, 0)));
    ASSERT_EQ(13, (ls_std::STLUtils::getListElementAt(values, 1)));
    ASSERT_EQ(7, (ls_std::STLUtils::getListElementAt(values, 2)));
    ASSERT_EQ(8, (ls_std::STLUtils::getListElementAt(values, 3)));

    ASSERT_STREQ("Tim", ls_std::STLUtils::getListElementAt(names, 0).c_str());
    ASSERT_STREQ("Alex", ls_std::STLUtils::getListElementAt(names, 1).c_str());
    ASSERT_STREQ("Nadine", ls_std::STLUtils::getListElementAt(names, 2).c_str());
  }

  TEST_F(STLUtilsTest, getListElementAtNegative)
  {
    std::list<int> values{1, 13, 7, 8};
    std::list<std::string> names{"Tim", "Alex", "Nadine"};

    ASSERT_EQ(0, (ls_std::STLUtils::getListElementAt(values, 15)));
    ASSERT_STREQ("", ls_std::STLUtils::getListElementAt(names, 15).c_str());
  }
}
