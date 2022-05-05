/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-16
 * Changed:         2022-05-05
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>
#include <ls_std_test.hpp>

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
                     ls::Class object{""};
                   }
                   catch (const ls::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::IllegalArgumentException);
  }

  TEST_F(ClassTest, destructor)
  {
    std::shared_ptr<ls_std_test::ClassWrapper> object = std::make_shared<ls_std_test::ClassWrapper>();
    EXPECT_CALL(*object, Die());
  }

  TEST_F(ClassTest, getClassName)
  {
    ls::Class object{"Class"};
    ASSERT_STREQ("Class", object.getClassName().c_str());
  }

}
