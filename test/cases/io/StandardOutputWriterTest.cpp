/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-09-18
 * Changed:         2023-02-22
 *
 * */

#include <gtest/gtest.h>
#include <ls-std/ls-std-io.hpp>

using namespace ls::std::io;
using namespace ::testing;

namespace
{
  class StandardOutputWriterTest : public Test
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
    StandardOutputWriter writer{};
    ASSERT_TRUE(writer.write("Try something!"));
  }
}
