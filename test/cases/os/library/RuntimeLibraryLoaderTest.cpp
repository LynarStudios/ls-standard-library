/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-09-06
 * Changed:         2022-10-23
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std_os.hpp>
#include <ls_std/ls_std_core.hpp>
#include "TestHelper.hpp"

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

      static ls::std::os::RuntimeLibraryLoaderParameter createParameter()
      {
        ls::std::os::RuntimeLibraryLoaderParameter parameter{};
        #if defined(unix) || defined(__APPLE__)
        parameter.path = ls_std_test::TestHelper::getResourcesFolderLocation() + "libtest_math_d.so";
        #endif

        return parameter;
      }
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

  TEST_F(RuntimeLibraryLoaderTest, close)
  {
    ls::std::os::RuntimeLibraryLoader loader{createParameter()};
    ASSERT_TRUE(loader.open());
    ASSERT_TRUE(loader.close());
  }

  TEST_F(RuntimeLibraryLoaderTest, close_no_handle)
  {
    ls::std::os::RuntimeLibraryLoader loader{createParameter()};
    ASSERT_FALSE(loader.close());
  }

  TEST_F(RuntimeLibraryLoaderTest, getSymbol)
  {
    ls::std::os::RuntimeLibraryLoader loader{createParameter()};
    ASSERT_TRUE(loader.open());
    ASSERT_TRUE(loader.loadSymbol("_ZN4Math3addERKiS1_"));

    using addSignature = int(const int&, const int&);
    ::std::function<addSignature> add{reinterpret_cast<addSignature*>(loader.getSymbol("_ZN4Math3addERKiS1_"))};

    ASSERT_EQ(5, add(2, 3));
  }

  TEST_F(RuntimeLibraryLoaderTest, getSymbol_no_symbol)
  {
    ls::std::os::RuntimeLibraryLoader loader{createParameter()};

    ASSERT_TRUE(loader.open());
    ASSERT_TRUE(loader.getSymbol("_ZN4Math3addERKiS1_") == nullptr);
  }

  TEST_F(RuntimeLibraryLoaderTest, hasSymbol_not_found)
  {
    ls::std::os::RuntimeLibraryLoader loader{createParameter()};
    ASSERT_FALSE(loader.hasSymbol("getSquare"));
  }

  TEST_F(RuntimeLibraryLoaderTest, loadSymbol)
  {
    ls::std::os::RuntimeLibraryLoader loader{createParameter()};
    ASSERT_TRUE(loader.open());
    ASSERT_TRUE(loader.loadSymbol("_ZN4Math3addERKiS1_"));
  }

  TEST_F(RuntimeLibraryLoaderTest, loadSymbol_symbol_not_available)
  {
    ls::std::os::RuntimeLibraryLoader loader{createParameter()};
    ASSERT_TRUE(loader.open());
    ASSERT_FALSE(loader.loadSymbol("_ZN4Math3subERKiS1_"));
  }

  TEST_F(RuntimeLibraryLoaderTest, open)
  {
    ls::std::os::RuntimeLibraryLoader loader{createParameter()};
    ASSERT_TRUE(loader.open());
  }

  TEST_F(RuntimeLibraryLoaderTest, open_no_library_found)
  {
    ls::std::os::RuntimeLibraryLoaderParameter parameter{};
    parameter.path = ls_std_test::TestHelper::getResourcesFolderLocation() + "libno_exist.so";

    ls::std::os::RuntimeLibraryLoader loader{parameter};
    ASSERT_FALSE(loader.open());
  }
}
