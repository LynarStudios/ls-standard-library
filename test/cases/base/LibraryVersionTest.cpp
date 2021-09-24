/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-05-02
 * Changed:         2021-09-24
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>

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
    ASSERT_STREQ("2021.2.0", ls_std::getVersion().c_str());
  }
}
