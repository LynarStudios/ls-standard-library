/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-05
* Changed:         2023-02-05
*
* */

#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>
#include <ls-std/ls-std-io.hpp>

using namespace ls::std::core;
using namespace ls::std::io;
using namespace ::std;

namespace
{
  class XmlParseParameterTest : public ::testing::Test
  {
    protected:

      XmlParseParameterTest() = default;
      ~XmlParseParameterTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(XmlParseParameterTest, getLevel)
  {
    XmlParseParameter parameter{};
    ASSERT_EQ(0, parameter.getLevel());
  }

  TEST_F(XmlParseParameterTest, getNode)
  {
    XmlParseParameter parameter{};
    ASSERT_TRUE(parameter.getNode() == nullptr);
  }

  TEST_F(XmlParseParameterTest, setLevel)
  {
    XmlParseParameter parameter{};
    parameter.setLevel(3);

    ASSERT_EQ(3, parameter.getLevel());
  }

  TEST_F(XmlParseParameterTest, setNode)
  {
    XmlParseParameter parameter{};
    parameter.setNode(make_shared<XmlNode>("node"));

    ASSERT_TRUE(parameter.getNode() != nullptr);
  }

  TEST_F(XmlParseParameterTest, setNode_no_reference)
  {
    XmlParseParameter parameter{};

    EXPECT_THROW(
        {
          try
          {
            parameter.setNode(nullptr);
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }
}