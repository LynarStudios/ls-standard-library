/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-05-02
 * Changed:         2023-02-03
 *
 * */

#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>

using namespace ls::std::core;

namespace
{
  class LibraryVersionTest : public ::testing::Test
  {
    protected:

      LibraryVersionTest() = default;
      ~LibraryVersionTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(LibraryVersionTest, getVersion)
  {
    ASSERT_STREQ("2023.1.0", getVersion().c_str());
  }
}
