/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-05-02
 * Changed:         2023-03-05
 *
 * */

#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>

using ls::std::core::LibraryVersion;
using testing::Test;

namespace
{
  class LibraryVersionTest : public Test
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
    ASSERT_STREQ("2023.2.0", LibraryVersion::getVersion().c_str());
  }
}
