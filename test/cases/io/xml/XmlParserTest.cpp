/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-26
 * Changed:         2023-02-03
 *
 * */

#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>
#include <ls-std/ls-std-io.hpp>
#include "TestHelper.hpp"

using namespace ls::std::core;
using namespace ls::std::core::type;
using namespace ls::std::io;
using namespace ::std;
using namespace ls_std_test;

namespace
{
  class XmlParserTest : public ::testing::Test
  {
    protected:

      XmlParserTest() = default;
      ~XmlParserTest() override = default;

      static byte_field readXmlStateMachine()
      {
        string xmlPath = TestHelper::getResourcesFolderLocation() + "state_machine_test.xml";
        File file{xmlPath};
        byte_field data = FileReader{file}.read();

        return data;
      }

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(XmlParserTest, constructor)
  {
    shared_ptr<XmlDocument> document{};

    EXPECT_THROW({
                   try
                   {
                     XmlParser xmlParser{document};
                   }
                   catch (const IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, IllegalArgumentException);
  }

  TEST_F(XmlParserTest, read)
  {
    XmlParser xmlParser{make_shared<XmlDocument>()};
    list<shared_ptr<XmlNode>> children, statesChildren, memoryChildren, connectionChildren{};
    list<shared_ptr<XmlAttribute>> attributes{};

    byte_field data = readXmlStateMachine();
    xmlParser.parse(data);

    // check declaration

    ASSERT_STREQ("UTF-8", xmlParser.getDocument()->getDeclaration()->getEncoding().c_str());
    ASSERT_STREQ("1.0", xmlParser.getDocument()->getDeclaration()->getVersion().c_str());
    ASSERT_STREQ("yes", xmlParser.getDocument()->getDeclaration()->getStandalone().c_str());

    // check root element

    shared_ptr<XmlNode> root = xmlParser.getDocument()->getRootElement();
    ASSERT_STREQ("stateMachine", root->getName().c_str());
    ASSERT_STREQ("name", root->getAttributes().front()->getName().c_str());
    ASSERT_EQ(1, root->getAttributes().size());
    ASSERT_STREQ("test_machine", root->getAttributes().front()->getValue().c_str());

    // root children

    children = root->getChildren();
    ASSERT_EQ(3, children.size());
    ASSERT_STREQ("states", STLUtils::getListElementAt(children, 0)->getName().c_str());
    ASSERT_TRUE(STLUtils::getListElementAt(children, 0)->getAttributes().empty());
    ASSERT_STREQ("currentState", STLUtils::getListElementAt(children, 1)->getName().c_str());
    ASSERT_TRUE(STLUtils::getListElementAt(children, 1)->getAttributes().empty());
    ASSERT_STREQ("memory", STLUtils::getListElementAt(children, 2)->getName().c_str());
    ASSERT_TRUE(STLUtils::getListElementAt(children, 2)->getAttributes().empty());

    // states

    statesChildren = STLUtils::getListElementAt(children, 0)->getChildren();
    ASSERT_EQ(5, statesChildren.size());

    ASSERT_STREQ("state", STLUtils::getListElementAt(statesChildren, 0)->getName().c_str());
    ASSERT_EQ(1, STLUtils::getListElementAt(statesChildren, 0)->getAttributes().size());
    ASSERT_STREQ("id", STLUtils::getListElementAt(statesChildren, 0)->getAttributes().front()->getName().c_str());
    ASSERT_STREQ("A", STLUtils::getListElementAt(statesChildren, 0)->getAttributes().front()->getValue().c_str());
    ASSERT_TRUE(STLUtils::getListElementAt(statesChildren, 0)->getValue().empty());
    ASSERT_EQ(1, STLUtils::getListElementAt(statesChildren, 0)->getChildren().size());
    ASSERT_STREQ("connections", STLUtils::getListElementAt(statesChildren, 0)->getChildren().front()->getName().c_str());
    ASSERT_TRUE(STLUtils::getListElementAt(statesChildren, 0)->getChildren().front()->getValue().empty());
    ASSERT_TRUE(STLUtils::getListElementAt(statesChildren, 0)->getChildren().front()->getAttributes().empty());
    connectionChildren = STLUtils::getListElementAt(statesChildren, 0)->getChildren().front()->getChildren();
    ASSERT_EQ(1, connectionChildren.size());
    ASSERT_STREQ("connection", STLUtils::getListElementAt(connectionChildren, 0)->getName().c_str());
    ASSERT_TRUE(STLUtils::getListElementAt(connectionChildren, 0)->getValue().empty());
    attributes = STLUtils::getListElementAt(connectionChildren, 0)->getAttributes();
    ASSERT_EQ(3, attributes.size());
    ASSERT_STREQ("connectionId", STLUtils::getListElementAt(attributes, 0)->getName().c_str());
    ASSERT_STREQ("AB", STLUtils::getListElementAt(attributes, 0)->getValue().c_str());
    ASSERT_STREQ("condition", STLUtils::getListElementAt(attributes, 1)->getName().c_str());
    ASSERT_STREQ("false", STLUtils::getListElementAt(attributes, 1)->getValue().c_str());
    ASSERT_STREQ("id", STLUtils::getListElementAt(attributes, 2)->getName().c_str());
    ASSERT_STREQ("B", STLUtils::getListElementAt(attributes, 2)->getValue().c_str());

    ASSERT_STREQ("state", STLUtils::getListElementAt(statesChildren, 1)->getName().c_str());
    ASSERT_EQ(1, STLUtils::getListElementAt(statesChildren, 1)->getAttributes().size());
    ASSERT_STREQ("id", STLUtils::getListElementAt(statesChildren, 1)->getAttributes().front()->getName().c_str());
    ASSERT_STREQ("B", STLUtils::getListElementAt(statesChildren, 1)->getAttributes().front()->getValue().c_str());
    ASSERT_TRUE(STLUtils::getListElementAt(statesChildren, 1)->getValue().empty());
    ASSERT_EQ(1, STLUtils::getListElementAt(statesChildren, 1)->getChildren().size());
    ASSERT_STREQ("connections", STLUtils::getListElementAt(statesChildren, 1)->getChildren().front()->getName().c_str());
    ASSERT_TRUE(STLUtils::getListElementAt(statesChildren, 1)->getChildren().front()->getValue().empty());
    ASSERT_TRUE(STLUtils::getListElementAt(statesChildren, 1)->getChildren().front()->getAttributes().empty());
    connectionChildren = STLUtils::getListElementAt(statesChildren, 1)->getChildren().front()->getChildren();
    ASSERT_EQ(2, connectionChildren.size());
    ASSERT_STREQ("connection", STLUtils::getListElementAt(connectionChildren, 0)->getName().c_str());
    ASSERT_TRUE(STLUtils::getListElementAt(connectionChildren, 0)->getValue().empty());
    attributes = STLUtils::getListElementAt(connectionChildren, 0)->getAttributes();
    ASSERT_EQ(3, attributes.size());
    ASSERT_STREQ("connectionId", STLUtils::getListElementAt(attributes, 0)->getName().c_str());
    ASSERT_STREQ("BC", STLUtils::getListElementAt(attributes, 0)->getValue().c_str());
    ASSERT_STREQ("condition", STLUtils::getListElementAt(attributes, 1)->getName().c_str());
    ASSERT_STREQ("false", STLUtils::getListElementAt(attributes, 1)->getValue().c_str());
    ASSERT_STREQ("id", STLUtils::getListElementAt(attributes, 2)->getName().c_str());
    ASSERT_STREQ("C", STLUtils::getListElementAt(attributes, 2)->getValue().c_str());
    ASSERT_STREQ("connection", STLUtils::getListElementAt(connectionChildren, 1)->getName().c_str());
    ASSERT_TRUE(STLUtils::getListElementAt(connectionChildren, 1)->getValue().empty());
    attributes = STLUtils::getListElementAt(connectionChildren, 1)->getAttributes();
    ASSERT_EQ(3, attributes.size());
    ASSERT_STREQ("connectionId", STLUtils::getListElementAt(attributes, 0)->getName().c_str());
    ASSERT_STREQ("BD", STLUtils::getListElementAt(attributes, 0)->getValue().c_str());
    ASSERT_STREQ("condition", STLUtils::getListElementAt(attributes, 1)->getName().c_str());
    ASSERT_STREQ("false", STLUtils::getListElementAt(attributes, 1)->getValue().c_str());
    ASSERT_STREQ("id", STLUtils::getListElementAt(attributes, 2)->getName().c_str());
    ASSERT_STREQ("D", STLUtils::getListElementAt(attributes, 2)->getValue().c_str());

    ASSERT_STREQ("state", STLUtils::getListElementAt(statesChildren, 2)->getName().c_str());
    ASSERT_EQ(1, STLUtils::getListElementAt(statesChildren, 2)->getAttributes().size());
    ASSERT_STREQ("id", STLUtils::getListElementAt(statesChildren, 2)->getAttributes().front()->getName().c_str());
    ASSERT_STREQ("C", STLUtils::getListElementAt(statesChildren, 2)->getAttributes().front()->getValue().c_str());
    ASSERT_TRUE(STLUtils::getListElementAt(statesChildren, 2)->getValue().empty());
    ASSERT_EQ(1, STLUtils::getListElementAt(statesChildren, 2)->getChildren().size());
    ASSERT_STREQ("connections", STLUtils::getListElementAt(statesChildren, 2)->getChildren().front()->getName().c_str());
    ASSERT_TRUE(STLUtils::getListElementAt(statesChildren, 2)->getChildren().front()->getValue().empty());
    ASSERT_TRUE(STLUtils::getListElementAt(statesChildren, 2)->getChildren().front()->getAttributes().empty());
    connectionChildren = STLUtils::getListElementAt(statesChildren, 2)->getChildren().front()->getChildren();
    ASSERT_EQ(1, connectionChildren.size());
    ASSERT_STREQ("connection", STLUtils::getListElementAt(connectionChildren, 0)->getName().c_str());
    ASSERT_TRUE(STLUtils::getListElementAt(connectionChildren, 0)->getValue().empty());
    attributes = STLUtils::getListElementAt(connectionChildren, 0)->getAttributes();
    ASSERT_EQ(3, attributes.size());
    ASSERT_STREQ("connectionId", STLUtils::getListElementAt(attributes, 0)->getName().c_str());
    ASSERT_STREQ("CE", STLUtils::getListElementAt(attributes, 0)->getValue().c_str());
    ASSERT_STREQ("condition", STLUtils::getListElementAt(attributes, 1)->getName().c_str());
    ASSERT_STREQ("false", STLUtils::getListElementAt(attributes, 1)->getValue().c_str());
    ASSERT_STREQ("id", STLUtils::getListElementAt(attributes, 2)->getName().c_str());
    ASSERT_STREQ("E", STLUtils::getListElementAt(attributes, 2)->getValue().c_str());

    ASSERT_STREQ("state", STLUtils::getListElementAt(statesChildren, 3)->getName().c_str());
    ASSERT_EQ(1, STLUtils::getListElementAt(statesChildren, 3)->getAttributes().size());
    ASSERT_STREQ("id", STLUtils::getListElementAt(statesChildren, 3)->getAttributes().front()->getName().c_str());
    ASSERT_STREQ("D", STLUtils::getListElementAt(statesChildren, 3)->getAttributes().front()->getValue().c_str());
    ASSERT_TRUE(STLUtils::getListElementAt(statesChildren, 3)->getChildren().front()->getAttributes().empty());
    connectionChildren = STLUtils::getListElementAt(statesChildren, 3)->getChildren().front()->getChildren();
    ASSERT_EQ(1, connectionChildren.size());
    ASSERT_STREQ("connection", STLUtils::getListElementAt(connectionChildren, 0)->getName().c_str());
    ASSERT_TRUE(STLUtils::getListElementAt(connectionChildren, 0)->getValue().empty());
    attributes = STLUtils::getListElementAt(connectionChildren, 0)->getAttributes();
    ASSERT_EQ(3, attributes.size());
    ASSERT_STREQ("connectionId", STLUtils::getListElementAt(attributes, 0)->getName().c_str());
    ASSERT_STREQ("DE", STLUtils::getListElementAt(attributes, 0)->getValue().c_str());
    ASSERT_STREQ("condition", STLUtils::getListElementAt(attributes, 1)->getName().c_str());
    ASSERT_STREQ("false", STLUtils::getListElementAt(attributes, 1)->getValue().c_str());
    ASSERT_STREQ("id", STLUtils::getListElementAt(attributes, 2)->getName().c_str());
    ASSERT_STREQ("E", STLUtils::getListElementAt(attributes, 2)->getValue().c_str());

    ASSERT_STREQ("state", STLUtils::getListElementAt(statesChildren, 4)->getName().c_str());
    ASSERT_EQ(1, STLUtils::getListElementAt(statesChildren, 4)->getAttributes().size());
    ASSERT_STREQ("id", STLUtils::getListElementAt(statesChildren, 4)->getAttributes().front()->getName().c_str());
    ASSERT_STREQ("E", STLUtils::getListElementAt(statesChildren, 4)->getAttributes().front()->getValue().c_str());
    ASSERT_TRUE(STLUtils::getListElementAt(statesChildren, 4)->getChildren().empty());

    // current state

    ASSERT_STREQ("currentState", STLUtils::getListElementAt(children, 1)->getName().c_str());
    ASSERT_STREQ("A", STLUtils::getListElementAt(children, 1)->getValue().c_str());
    ASSERT_TRUE(STLUtils::getListElementAt(children, 1)->getChildren().empty());
    ASSERT_TRUE(STLUtils::getListElementAt(children, 1)->getAttributes().empty());

    // memory

    memoryChildren = STLUtils::getListElementAt(children, 2)->getChildren();
    ASSERT_EQ(3, memoryChildren.size());

    ASSERT_STREQ("location", STLUtils::getListElementAt(memoryChildren, 0)->getName().c_str());
    ASSERT_STREQ("A", STLUtils::getListElementAt(memoryChildren, 0)->getValue().c_str());
    ASSERT_TRUE(STLUtils::getListElementAt(memoryChildren, 0)->getChildren().empty());
    ASSERT_TRUE(STLUtils::getListElementAt(memoryChildren, 0)->getAttributes().empty());

    ASSERT_STREQ("location", STLUtils::getListElementAt(memoryChildren, 1)->getName().c_str());
    ASSERT_STREQ("B", STLUtils::getListElementAt(memoryChildren, 1)->getValue().c_str());
    ASSERT_TRUE(STLUtils::getListElementAt(memoryChildren, 1)->getChildren().empty());
    ASSERT_TRUE(STLUtils::getListElementAt(memoryChildren, 1)->getAttributes().empty());

    ASSERT_STREQ("location", STLUtils::getListElementAt(memoryChildren, 2)->getName().c_str());
    ASSERT_STREQ("C", STLUtils::getListElementAt(memoryChildren, 2)->getValue().c_str());
    ASSERT_TRUE(STLUtils::getListElementAt(memoryChildren, 2)->getChildren().empty());
    ASSERT_TRUE(STLUtils::getListElementAt(memoryChildren, 2)->getAttributes().empty());
  }

  TEST_F(XmlParserTest, getDocument)
  {
    string xmlPath = TestHelper::getResourcesFolderLocation() + "state_machine_test.xml";
    XmlParser xmlParser{make_shared<XmlDocument>()};

    ASSERT_TRUE(xmlParser.getDocument() != nullptr);
  }

  TEST_F(XmlParserTest, setDocument)
  {
    string xmlPath = TestHelper::getResourcesFolderLocation() + "state_machine_test.xml";
    shared_ptr<XmlDocument> document = make_shared<XmlDocument>();
    XmlParser xmlParser{document};
    ASSERT_TRUE(xmlParser.getDocument() == document);

    document = make_shared<XmlDocument>();
    xmlParser.setDocument(document);
    ASSERT_TRUE(xmlParser.getDocument() == document);
  }

  TEST_F(XmlParserTest, setDocument_no_reference)
  {
    shared_ptr<XmlDocument> document = make_shared<XmlDocument>();
    XmlParser xmlParser{document};

    EXPECT_THROW({
                   try
                   {
                     xmlParser.setDocument(nullptr);
                   }
                   catch (const IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, IllegalArgumentException);
  }
}
