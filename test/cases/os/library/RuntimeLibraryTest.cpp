/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-10-27
 * Changed:         2022-10-27
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std_os.hpp>
#include <ls_std/ls_std_core.hpp>

namespace
{
  class RuntimeLibraryTest : public ::testing::Test
  {
    protected:

      RuntimeLibraryTest() = default;
      ~RuntimeLibraryTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(RuntimeLibraryTest, addSymbol)
  {
    ls::std::os::RuntimeLibrary runtimeLibrary{};
    ls::std::core::type::runtime_library_entry entry = ::std::make_pair<::std::string, void *>("_func", (void *) ::std::make_shared<int>().get());

    ASSERT_TRUE(runtimeLibrary.addSymbol(entry));
  }

  TEST_F(RuntimeLibraryTest, addSymbol_empty_key)
  {
    EXPECT_THROW({
                   try
                   {
                     ls::std::os::RuntimeLibrary runtimeLibrary{};
                     runtimeLibrary.addSymbol(::std::make_pair<::std::string, void *>("", (void *) ::std::make_shared<int>().get()));
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }

  TEST_F(RuntimeLibraryTest, addSymbol_empty_reference)
  {
    EXPECT_THROW({
                   try
                   {
                     ls::std::os::RuntimeLibrary runtimeLibrary{};
                     runtimeLibrary.addSymbol(::std::make_pair<::std::string, void *>("_func", (void *) nullptr));
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }

  TEST_F(RuntimeLibraryTest, getSymbol)
  {
    ls::std::os::RuntimeLibrary runtimeLibrary{};
    ls::std::core::type::runtime_library_entry entry = ::std::make_pair<::std::string, void *>("_func", (void *) ::std::make_shared<int>().get());

    ASSERT_TRUE(runtimeLibrary.addSymbol(entry));
    ASSERT_TRUE(runtimeLibrary.getSymbol("_func") != nullptr);
  }

  TEST_F(RuntimeLibraryTest, getSymbol_not_available)
  {
    ls::std::os::RuntimeLibrary runtimeLibrary{};
    ASSERT_TRUE(runtimeLibrary.getSymbol("_func") == nullptr);
  }

  TEST_F(RuntimeLibraryTest, hasSymbol)
  {
    ls::std::os::RuntimeLibrary runtimeLibrary{};
    ls::std::core::type::runtime_library_entry entry = ::std::make_pair<::std::string, void *>("_func", (void *) ::std::make_shared<int>().get());

    ASSERT_TRUE(runtimeLibrary.addSymbol(entry));
    ASSERT_TRUE(runtimeLibrary.hasSymbol("_func"));
  }

  TEST_F(RuntimeLibraryTest, hasSymbol_not_available)
  {
    ls::std::os::RuntimeLibrary runtimeLibrary{};
    ASSERT_FALSE(runtimeLibrary.hasSymbol("_func"));
  }
}
