/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-30
 * Changed:         2020-10-26
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>
#include "../../../TestDataFactory.hpp"

namespace {
  class XMLDocumentTest : public ::testing::Test {
    protected:

      XMLDocumentTest() = default;
      ~XMLDocumentTest() override = default;

      void SetUp() override {}
      void TearDown() override {}
  };

  TEST_F(XMLDocumentTest, getDeclaration)
  {
    ls_std::XMLDocument document {};
    ASSERT_TRUE(document.getDeclaration() == nullptr);
  }

  TEST_F(XMLDocumentTest, getRootElement)
  {
    ls_std::XMLDocument document {};
    ASSERT_TRUE(document.getRootElement() == nullptr);
  }

  TEST_F(XMLDocumentTest, setDeclaration)
  {
    ls_std::XMLDocument document {};
    ASSERT_TRUE(document.getDeclaration() == nullptr);

    ls_std::XMLDeclaration declaration {"1.0"};
    document.setDeclaration(std::make_shared<ls_std::XMLDeclaration>(declaration));
    ASSERT_TRUE(document.getDeclaration() != nullptr);
    ASSERT_STREQ("1.0", document.getDeclaration()->getVersion().c_str());
  }

  TEST_F(XMLDocumentTest, setRootElement)
  {
    ls_std::XMLDocument document {};
    ASSERT_TRUE(document.getRootElement() == nullptr);

    ls_std::XMLDeclaration declaration {"1.0"};
    document.setRootElement(ls_std_test::TestDataFactory::createXMLContent());
    ASSERT_TRUE(document.getRootElement() != nullptr);
    ASSERT_STREQ("dialog", document.getRootElement()->getName().c_str());
  }

  TEST_F(XMLDocumentTest, toXML)
  {
    ls_std::XMLDocument document {};

    ls_std::XMLDeclaration declaration {"1.0"};
    declaration.setEncoding("UTF-8");
    declaration.setStandalone("yes");
    document.setDeclaration(std::make_shared<ls_std::XMLDeclaration>(declaration));

    document.setRootElement(ls_std_test::TestDataFactory::createXMLContent());
    std::string xmlStream = document.toXML();

    ASSERT_TRUE(!xmlStream.empty());

    std::string expectedXMLContent =
        R"(<?xml version="1.0" encoding="UTF-8" standalone="yes" ?>
<dialog name="dungeon_001">
    <dialogUnit id="001">
        <text>Hello!</text>
    </dialogUnit>
    <dialogUnit id="002">
        <text>Hello again!</text>
    </dialogUnit>
</dialog>
)";

    ASSERT_STREQ(expectedXMLContent.c_str(), xmlStream.c_str());
  }
}
