/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-23
 * Changed:         2021-04-23
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>

namespace
{
  class XMLAttributeTest : public ::testing::Test
  {
    protected:

      XMLAttributeTest() = default;
      ~XMLAttributeTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(XMLAttributeTest, getName)
  {
    ls_std::XMLAttribute attribute{"id"};
    ASSERT_STREQ("id", attribute.getName().c_str());
  }

  TEST_F(XMLAttributeTest, getValue)
  {
    ls_std::XMLAttribute attribute{"id"};
    ASSERT_TRUE(attribute.getValue().empty());
  }

  TEST_F(XMLAttributeTest, setName)
  {
    ls_std::XMLAttribute attribute{"id"};
    attribute.setName("id2");

    ASSERT_STREQ("id2", attribute.getName().c_str());
  }

  TEST_F(XMLAttributeTest, setValue)
  {
    ls_std::XMLAttribute attribute{"id"};
    attribute.setValue("some_content");

    ASSERT_STREQ("some_content", attribute.getValue().c_str());
  }

  TEST_F(XMLAttributeTest, toXML)
  {
    ls_std::XMLAttribute attribute{"id"};
    attribute.setValue("some_content");

    ASSERT_STREQ(R"(id="some_content")", attribute.toXML().c_str());
  }
}
