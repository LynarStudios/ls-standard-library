/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-05-02
 * Changed:         2022-11-09
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std_core.hpp>

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
    ASSERT_STREQ("2022.3.0", getVersion().c_str());
  }
}
