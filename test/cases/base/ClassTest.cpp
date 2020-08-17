/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-16
 * Changed:         2020-08-16
 *
 * */

#include <gtest/gtest.h>
#include "../../../source/base/Class.hpp"

namespace {
  class ClassTest : public ::testing::Test {
    protected:

      ClassTest() = default;
      ~ClassTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(ClassTest, getClassName)
  {
    ls_std::Class object {"Class"};
    ASSERT_STREQ("Class", object.getClassName().c_str());
  }
}