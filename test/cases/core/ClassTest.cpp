/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-16
 * Changed:         2022-12-16
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std_core.hpp>
#include <ls_std_core_test.hpp>

using namespace ls::std::core;
using namespace ::std;
using namespace ls_std_core_test;

namespace
{
  class ClassTest : public ::testing::Test
  {
    protected:

      ClassTest() = default;
      ~ClassTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(ClassTest, constructor_empty_parameter)
  {
    EXPECT_THROW({
                   try
                   {
                     Class object{""};
                   }
                   catch (const IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, IllegalArgumentException);
  }

  TEST_F(ClassTest, destructor)
  {
    shared_ptr<MockClass> object = make_shared<MockClass>();
    EXPECT_CALL(*object, Die());
  }

  TEST_F(ClassTest, getClassName)
  {
    Class object{"Class"};
    ASSERT_STREQ("Class", object.getClassName().c_str());
  }

}
