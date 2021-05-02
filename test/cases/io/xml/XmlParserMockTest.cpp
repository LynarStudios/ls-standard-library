/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-10-18
 * Changed:         2021-05-02
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/io/xml/XmlParserMock.hpp>

namespace
{
  class XmlParserMockTest : public ::testing::Test
  {
    protected:

      XmlParserMockTest() = default;
      ~XmlParserMockTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(XmlParserMockTest, readAttribute)
  {
    std::pair<std::string, std::string> attribute = ls_std::XmlParserMock::readAttribute(R"(name="tim")");
    ASSERT_TRUE(attribute.first == "name");
    ASSERT_TRUE(attribute.second == "tim");

    attribute = ls_std::XmlParserMock::readAttribute(R"(id="dialog_001")");
    ASSERT_TRUE(attribute.first == "id");
    ASSERT_TRUE(attribute.second == "dialog_001");
  }

  TEST_F(XmlParserMockTest, readAttributes)
  {
    // first case

    std::string tag = R"(<?xml version="1.0" encoding="UTF-8" ?>)";
    std::list<std::pair<std::string, std::string>> attributes = ls_std::XmlParserMock::readAttributes(tag);

    ASSERT_EQ(2, attributes.size());

    auto iterator = std::next(attributes.begin(), 0);
    ASSERT_TRUE(iterator->first == "version");
    ASSERT_TRUE(iterator->second == "1.0");

    iterator = std::next(attributes.begin(), 1);
    ASSERT_TRUE(iterator->first == "encoding");
    ASSERT_TRUE(iterator->second == "UTF-8");

    // second case

    tag = R"(<stateMachine name="test_machine">)";
    attributes = ls_std::XmlParserMock::readAttributes(tag);

    ASSERT_EQ(1, attributes.size());

    iterator = std::next(attributes.begin(), 0);
    ASSERT_TRUE(iterator->first == "name");
    ASSERT_TRUE(iterator->second == "test_machine");
  }
}
