/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-16
 * Changed:         2022-05-20
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std_core.hpp>
#include <ls_std_core_test.hpp>

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
                     ls::std::core::Class object{""};
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }

  TEST_F(ClassTest, destructor)
  {
    ::std::shared_ptr<ls_std_core_test::ClassWrapper> object = ::std::make_shared<ls_std_core_test::ClassWrapper>();
    EXPECT_CALL(*object, Die());
  }

  TEST_F(ClassTest, getClassName)
  {
    ls::std::core::Class object{"Class"};
    ASSERT_STREQ("Class", object.getClassName().c_str());
  }

}
