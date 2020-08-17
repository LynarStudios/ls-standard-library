/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2020-08-17
 *
 * */

#include <gtest/gtest.h>
#include "../../../source/utils/STLUtils.hpp"
#include <vector>
#include <list>
#include <string>

namespace {
  class STLUtilsTest : public ::testing::Test {
    protected:

      STLUtilsTest() = default;
      ~STLUtilsTest() override = default;

      void SetUp() override {}
      void TearDown() override {}
  };

  TEST_F(STLUtilsTest, contains)
  {
    std::vector<int> values {1, 13, 7, 8};
    std::list<std::string> names {"Tim", "Alex", "Nadine"};

    ASSERT_TRUE((ls_std::STLUtils<std::vector<int>, int>::contains(values, 1)));
    ASSERT_TRUE((ls_std::STLUtils<std::vector<int>, int>::contains(values, 13)));
    ASSERT_TRUE((ls_std::STLUtils<std::vector<int>, int>::contains(values, 7)));
    ASSERT_TRUE((ls_std::STLUtils<std::vector<int>, int>::contains(values, 8)));

    ASSERT_TRUE((ls_std::STLUtils<std::list<std::string>, std::string>::contains(names, "Tim")));
    ASSERT_TRUE((ls_std::STLUtils<std::list<std::string>, std::string>::contains(names, "Alex")));
    ASSERT_TRUE((ls_std::STLUtils<std::list<std::string>, std::string>::contains(names, "Nadine")));
  }

  TEST_F(STLUtilsTest, containsNegative)
  {
    std::vector<int> values{1, 13, 7, 8};
    std::list<std::string> names{"Tim", "Alex", "Nadine"};

    ASSERT_FALSE((ls_std::STLUtils<std::vector<int>, int>::contains(values, 55)));
    ASSERT_FALSE((ls_std::STLUtils<std::vector<int>, int>::contains(values, 9)));

    ASSERT_FALSE((ls_std::STLUtils<std::list<std::string>, std::string>::contains(names, "Lena")));
    ASSERT_FALSE((ls_std::STLUtils<std::list<std::string>, std::string>::contains(names, "Mirco")));
  }
}
