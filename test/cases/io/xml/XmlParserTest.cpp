/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-26
 * Changed:         2022-05-15
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std_core.hpp>
#include <ls_std/ls_std_io.hpp>
#include "TestHelper.hpp"

namespace
{
  class XmlParserTest : public ::testing::Test
  {
    protected:

      XmlParserTest() = default;
      ~XmlParserTest() override = default;

      static ls::std::core::type::byte_field readXmlStateMachine()
      {
        std::string xmlPath = ls_std_test::TestHelper::getResourcesFolderLocation() + "state_machine_test.xml";
        ls::std::io::File file{xmlPath};
        ls::std::core::type::byte_field data = ls::std::io::FileReader{file}.read();

        return data;
      }

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(XmlParserTest, constructor)
  {
    std::shared_ptr<ls::std::io::XmlDocument> document{};

    EXPECT_THROW({
                   try
                   {
                     ls::std::io::XmlParser xmlParser{document};
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }

  TEST_F(XmlParserTest, read)
  {
    ls::std::io::XmlParser xmlParser{std::make_shared<ls::std::io::XmlDocument>()};
    std::list<std::shared_ptr<ls::std::io::XmlNode>> children, statesChildren, memoryChildren, connectionChildren{};
    std::list<std::shared_ptr<ls::std::io::XmlAttribute>> attributes{};

    ls::std::core::type::byte_field data = readXmlStateMachine();
    xmlParser.parse(data);

    // check declaration

    ASSERT_STREQ("UTF-8", xmlParser.getDocument()->getDeclaration()->getEncoding().c_str());
    ASSERT_STREQ("1.0", xmlParser.getDocument()->getDeclaration()->getVersion().c_str());
    ASSERT_STREQ("yes", xmlParser.getDocument()->getDeclaration()->getStandalone().c_str());

    // check root element

    std::shared_ptr<ls::std::io::XmlNode> root = xmlParser.getDocument()->getRootElement();
    ASSERT_STREQ("stateMachine", root->getName().c_str());
    ASSERT_STREQ("name", root->getAttributes().front()->getName().c_str());
    ASSERT_EQ(1, root->getAttributes().size());
    ASSERT_STREQ("test_machine", root->getAttributes().front()->getValue().c_str());

    // root children

    children = root->getChildren();
    ASSERT_EQ(3, children.size());
    ASSERT_STREQ("states", ls::std::core::STLUtils::getListElementAt(children, 0)->getName().c_str());
    ASSERT_TRUE(ls::std::core::STLUtils::getListElementAt(children, 0)->getAttributes().empty());
    ASSERT_STREQ("currentState", ls::std::core::STLUtils::getListElementAt(children, 1)->getName().c_str());
    ASSERT_TRUE(ls::std::core::STLUtils::getListElementAt(children, 1)->getAttributes().empty());
    ASSERT_STREQ("memory", ls::std::core::STLUtils::getListElementAt(children, 2)->getName().c_str());
    ASSERT_TRUE(ls::std::core::STLUtils::getListElementAt(children, 2)->getAttributes().empty());

    // states

    statesChildren = ls::std::core::STLUtils::getListElementAt(children, 0)->getChildren();
    ASSERT_EQ(5, statesChildren.size());

    ASSERT_STREQ("state", ls::std::core::STLUtils::getListElementAt(statesChildren, 0)->getName().c_str());
    ASSERT_EQ(1, ls::std::core::STLUtils::getListElementAt(statesChildren, 0)->getAttributes().size());
    ASSERT_STREQ("id", ls::std::core::STLUtils::getListElementAt(statesChildren, 0)->getAttributes().front()->getName().c_str());
    ASSERT_STREQ("A", ls::std::core::STLUtils::getListElementAt(statesChildren, 0)->getAttributes().front()->getValue().c_str());
    ASSERT_TRUE(ls::std::core::STLUtils::getListElementAt(statesChildren, 0)->getValue().empty());
    ASSERT_EQ(1, ls::std::core::STLUtils::getListElementAt(statesChildren, 0)->getChildren().size());
    ASSERT_STREQ("connections", ls::std::core::STLUtils::getListElementAt(statesChildren, 0)->getChildren().front()->getName().c_str());
    ASSERT_TRUE(ls::std::core::STLUtils::getListElementAt(statesChildren, 0)->getChildren().front()->getValue().empty());
    ASSERT_TRUE(ls::std::core::STLUtils::getListElementAt(statesChildren, 0)->getChildren().front()->getAttributes().empty());
    connectionChildren = ls::std::core::STLUtils::getListElementAt(statesChildren, 0)->getChildren().front()->getChildren();
    ASSERT_EQ(1, connectionChildren.size());
    ASSERT_STREQ("connection", ls::std::core::STLUtils::getListElementAt(connectionChildren, 0)->getName().c_str());
    ASSERT_TRUE(ls::std::core::STLUtils::getListElementAt(connectionChildren, 0)->getValue().empty());
    attributes = ls::std::core::STLUtils::getListElementAt(connectionChildren, 0)->getAttributes();
    ASSERT_EQ(3, attributes.size());
    ASSERT_STREQ("connectionId", ls::std::core::STLUtils::getListElementAt(attributes, 0)->getName().c_str());
    ASSERT_STREQ("AB", ls::std::core::STLUtils::getListElementAt(attributes, 0)->getValue().c_str());
    ASSERT_STREQ("condition", ls::std::core::STLUtils::getListElementAt(attributes, 1)->getName().c_str());
    ASSERT_STREQ("false", ls::std::core::STLUtils::getListElementAt(attributes, 1)->getValue().c_str());
    ASSERT_STREQ("id", ls::std::core::STLUtils::getListElementAt(attributes, 2)->getName().c_str());
    ASSERT_STREQ("B", ls::std::core::STLUtils::getListElementAt(attributes, 2)->getValue().c_str());

    ASSERT_STREQ("state", ls::std::core::STLUtils::getListElementAt(statesChildren, 1)->getName().c_str());
    ASSERT_EQ(1, ls::std::core::STLUtils::getListElementAt(statesChildren, 1)->getAttributes().size());
    ASSERT_STREQ("id", ls::std::core::STLUtils::getListElementAt(statesChildren, 1)->getAttributes().front()->getName().c_str());
    ASSERT_STREQ("B", ls::std::core::STLUtils::getListElementAt(statesChildren, 1)->getAttributes().front()->getValue().c_str());
    ASSERT_TRUE(ls::std::core::STLUtils::getListElementAt(statesChildren, 1)->getValue().empty());
    ASSERT_EQ(1, ls::std::core::STLUtils::getListElementAt(statesChildren, 1)->getChildren().size());
    ASSERT_STREQ("connections", ls::std::core::STLUtils::getListElementAt(statesChildren, 1)->getChildren().front()->getName().c_str());
    ASSERT_TRUE(ls::std::core::STLUtils::getListElementAt(statesChildren, 1)->getChildren().front()->getValue().empty());
    ASSERT_TRUE(ls::std::core::STLUtils::getListElementAt(statesChildren, 1)->getChildren().front()->getAttributes().empty());
    connectionChildren = ls::std::core::STLUtils::getListElementAt(statesChildren, 1)->getChildren().front()->getChildren();
    ASSERT_EQ(2, connectionChildren.size());
    ASSERT_STREQ("connection", ls::std::core::STLUtils::getListElementAt(connectionChildren, 0)->getName().c_str());
    ASSERT_TRUE(ls::std::core::STLUtils::getListElementAt(connectionChildren, 0)->getValue().empty());
    attributes = ls::std::core::STLUtils::getListElementAt(connectionChildren, 0)->getAttributes();
    ASSERT_EQ(3, attributes.size());
    ASSERT_STREQ("connectionId", ls::std::core::STLUtils::getListElementAt(attributes, 0)->getName().c_str());
    ASSERT_STREQ("BC", ls::std::core::STLUtils::getListElementAt(attributes, 0)->getValue().c_str());
    ASSERT_STREQ("condition", ls::std::core::STLUtils::getListElementAt(attributes, 1)->getName().c_str());
    ASSERT_STREQ("false", ls::std::core::STLUtils::getListElementAt(attributes, 1)->getValue().c_str());
    ASSERT_STREQ("id", ls::std::core::STLUtils::getListElementAt(attributes, 2)->getName().c_str());
    ASSERT_STREQ("C", ls::std::core::STLUtils::getListElementAt(attributes, 2)->getValue().c_str());
    ASSERT_STREQ("connection", ls::std::core::STLUtils::getListElementAt(connectionChildren, 1)->getName().c_str());
    ASSERT_TRUE(ls::std::core::STLUtils::getListElementAt(connectionChildren, 1)->getValue().empty());
    attributes = ls::std::core::STLUtils::getListElementAt(connectionChildren, 1)->getAttributes();
    ASSERT_EQ(3, attributes.size());
    ASSERT_STREQ("connectionId", ls::std::core::STLUtils::getListElementAt(attributes, 0)->getName().c_str());
    ASSERT_STREQ("BD", ls::std::core::STLUtils::getListElementAt(attributes, 0)->getValue().c_str());
    ASSERT_STREQ("condition", ls::std::core::STLUtils::getListElementAt(attributes, 1)->getName().c_str());
    ASSERT_STREQ("false", ls::std::core::STLUtils::getListElementAt(attributes, 1)->getValue().c_str());
    ASSERT_STREQ("id", ls::std::core::STLUtils::getListElementAt(attributes, 2)->getName().c_str());
    ASSERT_STREQ("D", ls::std::core::STLUtils::getListElementAt(attributes, 2)->getValue().c_str());

    ASSERT_STREQ("state", ls::std::core::STLUtils::getListElementAt(statesChildren, 2)->getName().c_str());
    ASSERT_EQ(1, ls::std::core::STLUtils::getListElementAt(statesChildren, 2)->getAttributes().size());
    ASSERT_STREQ("id", ls::std::core::STLUtils::getListElementAt(statesChildren, 2)->getAttributes().front()->getName().c_str());
    ASSERT_STREQ("C", ls::std::core::STLUtils::getListElementAt(statesChildren, 2)->getAttributes().front()->getValue().c_str());
    ASSERT_TRUE(ls::std::core::STLUtils::getListElementAt(statesChildren, 2)->getValue().empty());
    ASSERT_EQ(1, ls::std::core::STLUtils::getListElementAt(statesChildren, 2)->getChildren().size());
    ASSERT_STREQ("connections", ls::std::core::STLUtils::getListElementAt(statesChildren, 2)->getChildren().front()->getName().c_str());
    ASSERT_TRUE(ls::std::core::STLUtils::getListElementAt(statesChildren, 2)->getChildren().front()->getValue().empty());
    ASSERT_TRUE(ls::std::core::STLUtils::getListElementAt(statesChildren, 2)->getChildren().front()->getAttributes().empty());
    connectionChildren = ls::std::core::STLUtils::getListElementAt(statesChildren, 2)->getChildren().front()->getChildren();
    ASSERT_EQ(1, connectionChildren.size());
    ASSERT_STREQ("connection", ls::std::core::STLUtils::getListElementAt(connectionChildren, 0)->getName().c_str());
    ASSERT_TRUE(ls::std::core::STLUtils::getListElementAt(connectionChildren, 0)->getValue().empty());
    attributes = ls::std::core::STLUtils::getListElementAt(connectionChildren, 0)->getAttributes();
    ASSERT_EQ(3, attributes.size());
    ASSERT_STREQ("connectionId", ls::std::core::STLUtils::getListElementAt(attributes, 0)->getName().c_str());
    ASSERT_STREQ("CE", ls::std::core::STLUtils::getListElementAt(attributes, 0)->getValue().c_str());
    ASSERT_STREQ("condition", ls::std::core::STLUtils::getListElementAt(attributes, 1)->getName().c_str());
    ASSERT_STREQ("false", ls::std::core::STLUtils::getListElementAt(attributes, 1)->getValue().c_str());
    ASSERT_STREQ("id", ls::std::core::STLUtils::getListElementAt(attributes, 2)->getName().c_str());
    ASSERT_STREQ("E", ls::std::core::STLUtils::getListElementAt(attributes, 2)->getValue().c_str());

    ASSERT_STREQ("state", ls::std::core::STLUtils::getListElementAt(statesChildren, 3)->getName().c_str());
    ASSERT_EQ(1, ls::std::core::STLUtils::getListElementAt(statesChildren, 3)->getAttributes().size());
    ASSERT_STREQ("id", ls::std::core::STLUtils::getListElementAt(statesChildren, 3)->getAttributes().front()->getName().c_str());
    ASSERT_STREQ("D", ls::std::core::STLUtils::getListElementAt(statesChildren, 3)->getAttributes().front()->getValue().c_str());
    ASSERT_TRUE(ls::std::core::STLUtils::getListElementAt(statesChildren, 3)->getChildren().front()->getAttributes().empty());
    connectionChildren = ls::std::core::STLUtils::getListElementAt(statesChildren, 3)->getChildren().front()->getChildren();
    ASSERT_EQ(1, connectionChildren.size());
    ASSERT_STREQ("connection", ls::std::core::STLUtils::getListElementAt(connectionChildren, 0)->getName().c_str());
    ASSERT_TRUE(ls::std::core::STLUtils::getListElementAt(connectionChildren, 0)->getValue().empty());
    attributes = ls::std::core::STLUtils::getListElementAt(connectionChildren, 0)->getAttributes();
    ASSERT_EQ(3, attributes.size());
    ASSERT_STREQ("connectionId", ls::std::core::STLUtils::getListElementAt(attributes, 0)->getName().c_str());
    ASSERT_STREQ("DE", ls::std::core::STLUtils::getListElementAt(attributes, 0)->getValue().c_str());
    ASSERT_STREQ("condition", ls::std::core::STLUtils::getListElementAt(attributes, 1)->getName().c_str());
    ASSERT_STREQ("false", ls::std::core::STLUtils::getListElementAt(attributes, 1)->getValue().c_str());
    ASSERT_STREQ("id", ls::std::core::STLUtils::getListElementAt(attributes, 2)->getName().c_str());
    ASSERT_STREQ("E", ls::std::core::STLUtils::getListElementAt(attributes, 2)->getValue().c_str());

    ASSERT_STREQ("state", ls::std::core::STLUtils::getListElementAt(statesChildren, 4)->getName().c_str());
    ASSERT_EQ(1, ls::std::core::STLUtils::getListElementAt(statesChildren, 4)->getAttributes().size());
    ASSERT_STREQ("id", ls::std::core::STLUtils::getListElementAt(statesChildren, 4)->getAttributes().front()->getName().c_str());
    ASSERT_STREQ("E", ls::std::core::STLUtils::getListElementAt(statesChildren, 4)->getAttributes().front()->getValue().c_str());
    ASSERT_TRUE(ls::std::core::STLUtils::getListElementAt(statesChildren, 4)->getChildren().empty());

    // current state

    ASSERT_STREQ("currentState", ls::std::core::STLUtils::getListElementAt(children, 1)->getName().c_str());
    ASSERT_STREQ("A", ls::std::core::STLUtils::getListElementAt(children, 1)->getValue().c_str());
    ASSERT_TRUE(ls::std::core::STLUtils::getListElementAt(children, 1)->getChildren().empty());
    ASSERT_TRUE(ls::std::core::STLUtils::getListElementAt(children, 1)->getAttributes().empty());

    // memory

    memoryChildren = ls::std::core::STLUtils::getListElementAt(children, 2)->getChildren();
    ASSERT_EQ(3, memoryChildren.size());

    ASSERT_STREQ("location", ls::std::core::STLUtils::getListElementAt(memoryChildren, 0)->getName().c_str());
    ASSERT_STREQ("A", ls::std::core::STLUtils::getListElementAt(memoryChildren, 0)->getValue().c_str());
    ASSERT_TRUE(ls::std::core::STLUtils::getListElementAt(memoryChildren, 0)->getChildren().empty());
    ASSERT_TRUE(ls::std::core::STLUtils::getListElementAt(memoryChildren, 0)->getAttributes().empty());

    ASSERT_STREQ("location", ls::std::core::STLUtils::getListElementAt(memoryChildren, 1)->getName().c_str());
    ASSERT_STREQ("B", ls::std::core::STLUtils::getListElementAt(memoryChildren, 1)->getValue().c_str());
    ASSERT_TRUE(ls::std::core::STLUtils::getListElementAt(memoryChildren, 1)->getChildren().empty());
    ASSERT_TRUE(ls::std::core::STLUtils::getListElementAt(memoryChildren, 1)->getAttributes().empty());

    ASSERT_STREQ("location", ls::std::core::STLUtils::getListElementAt(memoryChildren, 2)->getName().c_str());
    ASSERT_STREQ("C", ls::std::core::STLUtils::getListElementAt(memoryChildren, 2)->getValue().c_str());
    ASSERT_TRUE(ls::std::core::STLUtils::getListElementAt(memoryChildren, 2)->getChildren().empty());
    ASSERT_TRUE(ls::std::core::STLUtils::getListElementAt(memoryChildren, 2)->getAttributes().empty());
  }

  TEST_F(XmlParserTest, getDocument)
  {
    std::string xmlPath = ls_std_test::TestHelper::getResourcesFolderLocation() + "state_machine_test.xml";
    ls::std::io::XmlParser xmlParser{std::make_shared<ls::std::io::XmlDocument>()};

    ASSERT_TRUE(xmlParser.getDocument() != nullptr);
  }

  TEST_F(XmlParserTest, setDocument)
  {
    std::string xmlPath = ls_std_test::TestHelper::getResourcesFolderLocation() + "state_machine_test.xml";
    std::shared_ptr<ls::std::io::XmlDocument> document = std::make_shared<ls::std::io::XmlDocument>();
    ls::std::io::XmlParser xmlParser{document};
    ASSERT_TRUE(xmlParser.getDocument() == document);

    document = std::make_shared<ls::std::io::XmlDocument>();
    xmlParser.setDocument(document);
    ASSERT_TRUE(xmlParser.getDocument() == document);
  }

  TEST_F(XmlParserTest, setDocument_no_reference)
  {
    std::shared_ptr<ls::std::io::XmlDocument> document = std::make_shared<ls::std::io::XmlDocument>();
    ls::std::io::XmlParser xmlParser{document};

    EXPECT_THROW({
                   try
                   {
                     xmlParser.setDocument(nullptr);
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }
}
