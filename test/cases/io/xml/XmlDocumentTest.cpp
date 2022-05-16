/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-30
 * Changed:         2022-05-14
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std_core.hpp>
#include <ls_std/ls_std_io.hpp>
#include <ls_std_io_test.hpp>

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
    ls::std::io::XmlDocument document{};
    ASSERT_TRUE(document.getDeclaration() == nullptr);
  }

  TEST_F(XmlDocumentTest, getRootElement)
  {
    ls::std::io::XmlDocument document{};
    ASSERT_TRUE(document.getRootElement() == nullptr);
  }

  TEST_F(XmlDocumentTest, setDeclaration)
  {
    ls::std::io::XmlDocument document{};
    ASSERT_TRUE(document.getDeclaration() == nullptr);

    ls::std::io::XmlDeclaration declaration{"1.0"};
    document.setDeclaration(std::make_shared<ls::std::io::XmlDeclaration>(declaration));
    ASSERT_TRUE(document.getDeclaration() != nullptr);
    ASSERT_STREQ("1.0", document.getDeclaration()->getVersion().c_str());
  }

  TEST_F(XmlDocumentTest, setDeclaration_no_reference)
  {
    ls::std::io::XmlDocument document{};

    EXPECT_THROW({
                   try
                   {
                     document.setDeclaration(nullptr);
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }

  TEST_F(XmlDocumentTest, setRootElement)
  {
    ls::std::io::XmlDocument document{};
    ASSERT_TRUE(document.getRootElement() == nullptr);

    ls::std::io::XmlDeclaration declaration{"1.0"};
    document.setRootElement(ls_std_io_test::TestDataFactory::createXmlContent());
    ASSERT_TRUE(document.getRootElement() != nullptr);
    ASSERT_STREQ("dialog", document.getRootElement()->getName().c_str());
  }

  TEST_F(XmlDocumentTest, setRootElement_no_reference)
  {
    ls::std::io::XmlDocument document{};

    EXPECT_THROW({
                   try
                   {
                     document.setRootElement(nullptr);
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }

  TEST_F(XmlDocumentTest, toXml)
  {
    ls::std::io::XmlDocument document{};

    ls::std::io::XmlDeclaration declaration{"1.0"};
    declaration.setEncoding("UTF-8");
    declaration.setStandalone("yes");
    document.setDeclaration(std::make_shared<ls::std::io::XmlDeclaration>(declaration));

    document.setRootElement(ls_std_io_test::TestDataFactory::createXmlContent());
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
