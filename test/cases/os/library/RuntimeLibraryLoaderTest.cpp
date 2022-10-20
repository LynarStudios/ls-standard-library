/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-09-06
 * Changed:         2022-10-20
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std_os.hpp>
#include <ls_std/ls_std_core.hpp>
#include "TestHelper.hpp"
#include <ls_std/ls_std_time.hpp>

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
        parameter.path = ls_std_test::TestHelper::getResourcesFolderLocation() + "libls_std_time.so";
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
    // TODO: also provide a debug library for loading - currently debug execution is not working due to lack of debug information

    ls::std::os::RuntimeLibraryLoader loader{createParameter()};
    ASSERT_TRUE(loader.open());
    ASSERT_TRUE(loader.loadSymbol("_ZN2ls3std4time4DateC1Ev"));

    using constructorType = ls::std::time::Date();
    ::std::function<ls::std::time::Date()> date{reinterpret_cast<constructorType*>(loader.getSymbol("_ZN2ls3std4time4DateC1Ev"))};

    ASSERT_TRUE(date().getDay() > 0);
    ASSERT_TRUE(date().getHour() > 0);
  }

  TEST_F(RuntimeLibraryLoaderTest, getSymbol_no_symbol)
  {
    ls::std::os::RuntimeLibraryLoader loader{createParameter()};

    ASSERT_TRUE(loader.open());
    ASSERT_TRUE(loader.getSymbol("_ZN2ls3std4time4DateC1Ev") == nullptr);
  }

  TEST_F(RuntimeLibraryLoaderTest, hasSymbol_not_found)
  {
    ls::std::os::RuntimeLibraryLoader loader{createParameter()};
    ASSERT_FALSE(loader.hasSymbol("getTimeStamp"));
  }

  TEST_F(RuntimeLibraryLoaderTest, loadSymbol)
  {
    ls::std::os::RuntimeLibraryLoader loader{createParameter()};
    ASSERT_TRUE(loader.open());
    ASSERT_TRUE(loader.loadSymbol("_ZN2ls3std4time4Date6getDayEv"));
  }

  TEST_F(RuntimeLibraryLoaderTest, loadSymbol_symbol_not_available)
  {
    ls::std::os::RuntimeLibraryLoader loader{createParameter()};
    ASSERT_TRUE(loader.open());
    ASSERT_FALSE(loader.loadSymbol("_ZN2ls3std4time4Date6getLeapEv"));
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
