/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-30
 * Changed:         2023-02-23
 *
 * */

#include <gtest/gtest.h>
#include <ls-std-io-test.hpp>
#include <ls-std/ls-std-core.hpp>
#include <ls-std/ls-std-io.hpp>

using ls::std::core::IllegalArgumentException;
using ls::std::io::XmlDeclaration;
using ls::std::io::XmlDocument;
using std::make_shared;
using std::string;
using test::io::TestDataFactory;
using testing::Test;

namespace
{
  class XmlDocumentTest : public Test
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
    XmlDocument document{};
    ASSERT_TRUE(document.getDeclaration() == nullptr);
  }

  TEST_F(XmlDocumentTest, getRootElement)
  {
    XmlDocument document{};
    ASSERT_TRUE(document.getRootElement() == nullptr);
  }

  TEST_F(XmlDocumentTest, setDeclaration)
  {
    XmlDocument document{};
    ASSERT_TRUE(document.getDeclaration() == nullptr);

    XmlDeclaration declaration{"1.0"};
    document.setDeclaration(make_shared<XmlDeclaration>(declaration));
    ASSERT_TRUE(document.getDeclaration() != nullptr);
    ASSERT_STREQ("1.0", document.getDeclaration()->getVersion().c_str());
  }

  TEST_F(XmlDocumentTest, setDeclaration_no_reference)
  {
    XmlDocument document{};

    EXPECT_THROW(
        {
          try
          {
            document.setDeclaration(nullptr);
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(XmlDocumentTest, setRootElement)
  {
    XmlDocument document{};
    ASSERT_TRUE(document.getRootElement() == nullptr);

    document.setRootElement(TestDataFactory::createXmlContent());
    ASSERT_TRUE(document.getRootElement() != nullptr);
    ASSERT_STREQ("dialog", document.getRootElement()->getName().c_str());
  }

  TEST_F(XmlDocumentTest, setRootElement_no_reference)
  {
    XmlDocument document{};

    EXPECT_THROW(
        {
          try
          {
            document.setRootElement(nullptr);
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(XmlDocumentTest, toXml)
  {
    XmlDocument document{};

    XmlDeclaration declaration{"1.0"};
    declaration.setEncoding("UTF-8");
    declaration.setStandalone("yes");
    document.setDeclaration(make_shared<XmlDeclaration>(declaration));

    document.setRootElement(TestDataFactory::createXmlContent());
    string xmlStream = document.toXml();

    ASSERT_TRUE(!xmlStream.empty());

    string expectedXmlString = R"(<?xml version="1.0" encoding="UTF-8" standalone="yes" ?>
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
