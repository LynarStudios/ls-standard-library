/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-10-18
 * Changed:         2023-02-03
 *
 * */

#include <gtest/gtest.h>
#include <ls-std-io-test.hpp>

using namespace ls_std_io_test;
using namespace ::std;

namespace
{
  class XmlParserTestWrapperTest : public ::testing::Test
  {
    protected:

      XmlParserTestWrapperTest() = default;
      ~XmlParserTestWrapperTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(XmlParserTestWrapperTest, readAttribute)
  {
    pair<string, string> attribute = XmlParserTestWrapper::readAttribute(R"(name="tim")");
    ASSERT_TRUE(attribute.first == "name");
    ASSERT_TRUE(attribute.second == "tim");

    attribute = XmlParserTestWrapper::readAttribute(R"(id="dialog_001")");
    ASSERT_TRUE(attribute.first == "id");
    ASSERT_TRUE(attribute.second == "dialog_001");
  }

  TEST_F(XmlParserTestWrapperTest, readAttributes)
  {
    // first case

    string tag = R"(<?xml version="1.0" encoding="UTF-8" ?>)";
    list<pair<string, string>> attributes = XmlParserTestWrapper::readAttributes(tag);

    ASSERT_EQ(2, attributes.size());

    auto iterator = next(attributes.begin(), 0);
    ASSERT_TRUE(iterator->first == "version");
    ASSERT_TRUE(iterator->second == "1.0");

    iterator = next(attributes.begin(), 1);
    ASSERT_TRUE(iterator->first == "encoding");
    ASSERT_TRUE(iterator->second == "UTF-8");

    // second case

    tag = R"(<stateMachine name="test_machine">)";
    attributes = XmlParserTestWrapper::readAttributes(tag);

    ASSERT_EQ(1, attributes.size());

    iterator = next(attributes.begin(), 0);
    ASSERT_TRUE(iterator->first == "name");
    ASSERT_TRUE(iterator->second == "test_machine");
  }
}
