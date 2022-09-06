/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-09-06
 * Changed:         2022-09-06
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std_os.hpp>
#include <ls_std/ls_std_core.hpp>

namespace
{
  class RuntimeLibraryLoaderTest : public ::testing::Test
  {
    protected:

      RuntimeLibraryLoaderTest() = default;
      ~RuntimeLibraryLoaderTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(RuntimeLibraryLoaderTest, constructor_empty_path_parameter)
  {
    EXPECT_THROW({
                   try
                   {
                     ls::std::os::RuntimeLibraryLoader(ls::std::os::RuntimeLibraryLoaderParameter{});
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }
}
