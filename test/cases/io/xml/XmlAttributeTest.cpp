/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-23
 * Changed:         2022-05-14
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std_core.hpp>
#include <ls_std/ls_std_io.hpp>

namespace
{
  class XmlAttributeTest : public ::testing::Test
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
    EXPECT_THROW({
                   try
                   {
                     ls::std::io::XmlAttribute attribute{""};
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }

  TEST_F(XmlAttributeTest, getName)
  {
    ls::std::io::XmlAttribute attribute{"id"};
    ASSERT_STREQ("id", attribute.getName().c_str());
  }

  TEST_F(XmlAttributeTest, getValue)
  {
    ls::std::io::XmlAttribute attribute{"id"};
    ASSERT_TRUE(attribute.getValue().empty());
  }

  TEST_F(XmlAttributeTest, setName)
  {
    ls::std::io::XmlAttribute attribute{"id"};
    attribute.setName("id2");

    ASSERT_STREQ("id2", attribute.getName().c_str());
  }

  TEST_F(XmlAttributeTest, setName_empty_name)
  {
    EXPECT_THROW({
                   try
                   {
                     ls::std::io::XmlAttribute attribute{"id"};
                     attribute.setName("");
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }

  TEST_F(XmlAttributeTest, setValue)
  {
    ls::std::io::XmlAttribute attribute{"id"};
    attribute.setValue("some_content");

    ASSERT_STREQ("some_content", attribute.getValue().c_str());
  }

  TEST_F(XmlAttributeTest, setValue_empty_value)
  {
    EXPECT_THROW({
                   try
                   {
                     ls::std::io::XmlAttribute attribute{"id"};
                     attribute.setValue("");
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }

  TEST_F(XmlAttributeTest, toXml)
  {
    ls::std::io::XmlAttribute attribute{"id"};
    attribute.setValue("some_content");

    ASSERT_STREQ(R"(id="some_content")", attribute.toXml().c_str());
  }
}
