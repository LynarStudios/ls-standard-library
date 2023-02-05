/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-05
* Changed:         2023-02-05
*
* */

#include <gtest/gtest.h>
#include <ls-std/ls-std-io.hpp>
#include <string>

using namespace ls::std::io;
using namespace ::std;

namespace
{
  class KvParseParameterTest : public ::testing::Test
  {
    protected:

      KvParseParameterTest() = default;
      ~KvParseParameterTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(KvParseParameterTest, getIndex)
  {
    ASSERT_EQ(0, KvParseParameter{}.getIndex());
  }

  TEST_F(KvParseParameterTest, getLine)
  {
    ASSERT_TRUE(KvParseParameter{}.getLine().empty());
  }

  TEST_F(KvParseParameterTest, setIndex)
  {
    KvParseParameter parameter{};
    parameter.setIndex(3);

    ASSERT_EQ(3, parameter.getIndex());
  }

  TEST_F(KvParseParameterTest, setLine)
  {
    KvParseParameter parameter{};
    string line = "key=value";
    parameter.setLine(line);

    ASSERT_STREQ(line.c_str(), parameter.getLine().c_str());
  }
}
