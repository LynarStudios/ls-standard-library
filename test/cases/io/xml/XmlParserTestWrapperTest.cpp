/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-10-18
 * Changed:         2021-05-02
 *
 * */

#include <gtest/gtest.h>
#include <classes/io/xml/XmlParserTestWrapper.hpp>

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
    std::pair<std::string, std::string> attribute = ls_std_test::XmlParserTestWrapper::readAttribute(R"(name="tim")");
    ASSERT_TRUE(attribute.first == "name");
    ASSERT_TRUE(attribute.second == "tim");

    attribute = ls_std_test::XmlParserTestWrapper::readAttribute(R"(id="dialog_001")");
    ASSERT_TRUE(attribute.first == "id");
    ASSERT_TRUE(attribute.second == "dialog_001");
  }

  TEST_F(XmlParserTestWrapperTest, readAttributes)
  {
    // first case

    std::string tag = R"(<?xml version="1.0" encoding="UTF-8" ?>)";
    std::list<std::pair<std::string, std::string>> attributes = ls_std_test::XmlParserTestWrapper::readAttributes(tag);

    ASSERT_EQ(2, attributes.size());

    auto iterator = std::next(attributes.begin(), 0);
    ASSERT_TRUE(iterator->first == "version");
    ASSERT_TRUE(iterator->second == "1.0");

    iterator = std::next(attributes.begin(), 1);
    ASSERT_TRUE(iterator->first == "encoding");
    ASSERT_TRUE(iterator->second == "UTF-8");

    // second case

    tag = R"(<stateMachine name="test_machine">)";
    attributes = ls_std_test::XmlParserTestWrapper::readAttributes(tag);

    ASSERT_EQ(1, attributes.size());

    iterator = std::next(attributes.begin(), 0);
    ASSERT_TRUE(iterator->first == "name");
    ASSERT_TRUE(iterator->second == "test_machine");
  }
}
