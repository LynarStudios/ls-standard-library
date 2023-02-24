/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-23
 * Changed:         2023-02-23
 *
 * */

#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>
#include <ls-std/ls-std-io.hpp>

using ls::std::core::IllegalArgumentException;
using ls::std::io::XmlAttribute;
using testing::Test;

namespace
{
  class XmlAttributeTest : public Test
  {
    protected:

      XmlAttributeTest() = default;
      ~XmlAttributeTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(XmlAttributeTest, constructor_empty_name)
  {
    EXPECT_THROW(
        {
          try
          {
            XmlAttribute attribute{""};
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(XmlAttributeTest, getName)
  {
    XmlAttribute attribute{"id"};
    ASSERT_STREQ("id", attribute.getName().c_str());
  }

  TEST_F(XmlAttributeTest, getValue)
  {
    XmlAttribute attribute{"id"};
    ASSERT_TRUE(attribute.getValue().empty());
  }

  TEST_F(XmlAttributeTest, setName)
  {
    XmlAttribute attribute{"id"};
    attribute.setName("id2");

    ASSERT_STREQ("id2", attribute.getName().c_str());
  }

  TEST_F(XmlAttributeTest, setName_empty_name)
  {
    EXPECT_THROW(
        {
          try
          {
            XmlAttribute attribute{"id"};
            attribute.setName("");
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(XmlAttributeTest, setValue)
  {
    XmlAttribute attribute{"id"};
    attribute.setValue("some_content");

    ASSERT_STREQ("some_content", attribute.getValue().c_str());
  }

  TEST_F(XmlAttributeTest, setValue_empty_value)
  {
    EXPECT_THROW(
        {
          try
          {
            XmlAttribute attribute{"id"};
            attribute.setValue("");
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(XmlAttributeTest, toXml)
  {
    XmlAttribute attribute{"id"};
    attribute.setValue("some_content");

    ASSERT_STREQ(R"(id="some_content")", attribute.toXml().c_str());
  }
}
