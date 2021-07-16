/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-30
 * Changed:         2021-07-16
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>
#include <TestDataFactory.hpp>

namespace
{
  class XmlDocumentTest : public ::testing::Test
  {
    protected:

      XmlDocumentTest() = default;
      ~XmlDocumentTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(XmlDocumentTest, getDeclaration)
  {
    ls_std::XmlDocument document{};
    ASSERT_TRUE(document.getDeclaration() == nullptr);
  }

  TEST_F(XmlDocumentTest, getRootElement)
  {
    ls_std::XmlDocument document{};
    ASSERT_TRUE(document.getRootElement() == nullptr);
  }

  TEST_F(XmlDocumentTest, setDeclaration)
  {
    ls_std::XmlDocument document{};
    ASSERT_TRUE(document.getDeclaration() == nullptr);

    ls_std::XmlDeclaration declaration{"1.0"};
    document.setDeclaration(std::make_shared<ls_std::XmlDeclaration>(declaration));
    ASSERT_TRUE(document.getDeclaration() != nullptr);
    ASSERT_STREQ("1.0", document.getDeclaration()->getVersion().c_str());
  }

  TEST_F(XmlDocumentTest, setDeclaration_no_reference)
  {
    ls_std::XmlDocument document{};

    EXPECT_THROW({
                   try
                   {
                     document.setDeclaration(nullptr);
                   }
                   catch (const ls_std::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls_std::IllegalArgumentException);
  }

  TEST_F(XmlDocumentTest, setRootElement)
  {
    ls_std::XmlDocument document{};
    ASSERT_TRUE(document.getRootElement() == nullptr);

    ls_std::XmlDeclaration declaration{"1.0"};
    document.setRootElement(ls_std_test::TestDataFactory::createXmlContent());
    ASSERT_TRUE(document.getRootElement() != nullptr);
    ASSERT_STREQ("dialog", document.getRootElement()->getName().c_str());
  }

  TEST_F(XmlDocumentTest, setRootElement_no_reference)
  {
    ls_std::XmlDocument document{};

    EXPECT_THROW({
                   try
                   {
                     document.setRootElement(nullptr);
                   }
                   catch (const ls_std::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls_std::IllegalArgumentException);
  }

  TEST_F(XmlDocumentTest, toXml)
  {
    ls_std::XmlDocument document{};

    ls_std::XmlDeclaration declaration{"1.0"};
    declaration.setEncoding("UTF-8");
    declaration.setStandalone("yes");
    document.setDeclaration(std::make_shared<ls_std::XmlDeclaration>(declaration));

    document.setRootElement(ls_std_test::TestDataFactory::createXmlContent());
    std::string xmlStream = document.toXml();

    ASSERT_TRUE(!xmlStream.empty());

    std::string expectedXmlString = R"(<?xml version="1.0" encoding="UTF-8" standalone="yes" ?>
<dialog name="dungeon_001">
    <dialogUnit id="001">
        <text>Hello!</text>
    </dialogUnit>
    <dialogUnit id="002">
        <text>Hello again!</text>
    </dialogUnit>
</dialog>
)";

    ASSERT_STREQ(expectedXmlString.c_str(), xmlStream.c_str());
  }
}
