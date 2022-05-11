/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-09-18
 * Changed:         2022-05-11
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>

namespace
{
  class StandardOutputWriterTest : public ::testing::Test
  {
    protected:

      StandardOutputWriterTest() = default;
      ~StandardOutputWriterTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(StandardOutputWriterTest, write)
  {
    ls::std::io::StandardOutputWriter writer{};
    ASSERT_TRUE(writer.write("Try something!"));
  }
}
