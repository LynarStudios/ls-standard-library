/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-16
 * Changed:         2023-02-03
 *
 * */

#include <gtest/gtest.h>
#include <ls-std-core-test.hpp>
#include <ls-std/ls-std-core.hpp>

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
    shared_ptr<ClassWrapper> object = make_shared<ClassWrapper>();
    EXPECT_CALL(*object, Die());
  }

  TEST_F(ClassTest, getClassName)
  {
    Class object{"Class"};
    ASSERT_STREQ("Class", object.getClassName().c_str());
  }

}
