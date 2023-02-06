/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-26
 * Changed:         2023-02-06
 *
 * */

#include <classes/TestHelper.hpp>
#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>
#include <ls-std/ls-std-io.hpp>

using namespace ls::std::core;
using namespace ls::std::core::type;
using namespace ls::std::io;
using namespace ::std;
using namespace ls::std::test;

namespace
{
  class XmlParserTest : public ::testing::Test
  {
    protected:

      XmlParserTest() = default;
      ~XmlParserTest() override = default;

      static byte_field readXmlStateMachine()
      {
        string xmlPath = TestHelper::getResourcesFolderLocation() + "state-machine-test.xml";
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

    EXPECT_THROW(
        {
          try
          {
            XmlParser xmlParser = XmlParser{document};
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
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
    ASSERT_STREQ("states", StlUtils::getListElementAt(children, 0)->getName().c_str());
    ASSERT_TRUE(StlUtils::getListElementAt(children, 0)->getAttributes().empty());
    ASSERT_STREQ("currentState", StlUtils::getListElementAt(children, 1)->getName().c_str());
    ASSERT_TRUE(StlUtils::getListElementAt(children, 1)->getAttributes().empty());
    ASSERT_STREQ("memory", StlUtils::getListElementAt(children, 2)->getName().c_str());
    ASSERT_TRUE(StlUtils::getListElementAt(children, 2)->getAttributes().empty());

    // states

    statesChildren = StlUtils::getListElementAt(children, 0)->getChildren();
    ASSERT_EQ(5, statesChildren.size());

    ASSERT_STREQ("state", StlUtils::getListElementAt(statesChildren, 0)->getName().c_str());
    ASSERT_EQ(1, StlUtils::getListElementAt(statesChildren, 0)->getAttributes().size());
    ASSERT_STREQ("id", StlUtils::getListElementAt(statesChildren, 0)->getAttributes().front()->getName().c_str());
    ASSERT_STREQ("A", StlUtils::getListElementAt(statesChildren, 0)->getAttributes().front()->getValue().c_str());
    ASSERT_TRUE(StlUtils::getListElementAt(statesChildren, 0)->getValue().empty());
    ASSERT_EQ(1, StlUtils::getListElementAt(statesChildren, 0)->getChildren().size());
    ASSERT_STREQ("connections", StlUtils::getListElementAt(statesChildren, 0)->getChildren().front()->getName().c_str());
    ASSERT_TRUE(StlUtils::getListElementAt(statesChildren, 0)->getChildren().front()->getValue().empty());
    ASSERT_TRUE(StlUtils::getListElementAt(statesChildren, 0)->getChildren().front()->getAttributes().empty());
    connectionChildren = StlUtils::getListElementAt(statesChildren, 0)->getChildren().front()->getChildren();
    ASSERT_EQ(1, connectionChildren.size());
    ASSERT_STREQ("connection", StlUtils::getListElementAt(connectionChildren, 0)->getName().c_str());
    ASSERT_TRUE(StlUtils::getListElementAt(connectionChildren, 0)->getValue().empty());
    attributes = StlUtils::getListElementAt(connectionChildren, 0)->getAttributes();
    ASSERT_EQ(3, attributes.size());
    ASSERT_STREQ("connectionId", StlUtils::getListElementAt(attributes, 0)->getName().c_str());
    ASSERT_STREQ("AB", StlUtils::getListElementAt(attributes, 0)->getValue().c_str());
    ASSERT_STREQ("condition", StlUtils::getListElementAt(attributes, 1)->getName().c_str());
    ASSERT_STREQ("false", StlUtils::getListElementAt(attributes, 1)->getValue().c_str());
    ASSERT_STREQ("id", StlUtils::getListElementAt(attributes, 2)->getName().c_str());
    ASSERT_STREQ("B", StlUtils::getListElementAt(attributes, 2)->getValue().c_str());

    ASSERT_STREQ("state", StlUtils::getListElementAt(statesChildren, 1)->getName().c_str());
    ASSERT_EQ(1, StlUtils::getListElementAt(statesChildren, 1)->getAttributes().size());
    ASSERT_STREQ("id", StlUtils::getListElementAt(statesChildren, 1)->getAttributes().front()->getName().c_str());
    ASSERT_STREQ("B", StlUtils::getListElementAt(statesChildren, 1)->getAttributes().front()->getValue().c_str());
    ASSERT_TRUE(StlUtils::getListElementAt(statesChildren, 1)->getValue().empty());
    ASSERT_EQ(1, StlUtils::getListElementAt(statesChildren, 1)->getChildren().size());
    ASSERT_STREQ("connections", StlUtils::getListElementAt(statesChildren, 1)->getChildren().front()->getName().c_str());
    ASSERT_TRUE(StlUtils::getListElementAt(statesChildren, 1)->getChildren().front()->getValue().empty());
    ASSERT_TRUE(StlUtils::getListElementAt(statesChildren, 1)->getChildren().front()->getAttributes().empty());
    connectionChildren = StlUtils::getListElementAt(statesChildren, 1)->getChildren().front()->getChildren();
    ASSERT_EQ(2, connectionChildren.size());
    ASSERT_STREQ("connection", StlUtils::getListElementAt(connectionChildren, 0)->getName().c_str());
    ASSERT_TRUE(StlUtils::getListElementAt(connectionChildren, 0)->getValue().empty());
    attributes = StlUtils::getListElementAt(connectionChildren, 0)->getAttributes();
    ASSERT_EQ(3, attributes.size());
    ASSERT_STREQ("connectionId", StlUtils::getListElementAt(attributes, 0)->getName().c_str());
    ASSERT_STREQ("BC", StlUtils::getListElementAt(attributes, 0)->getValue().c_str());
    ASSERT_STREQ("condition", StlUtils::getListElementAt(attributes, 1)->getName().c_str());
    ASSERT_STREQ("false", StlUtils::getListElementAt(attributes, 1)->getValue().c_str());
    ASSERT_STREQ("id", StlUtils::getListElementAt(attributes, 2)->getName().c_str());
    ASSERT_STREQ("C", StlUtils::getListElementAt(attributes, 2)->getValue().c_str());
    ASSERT_STREQ("connection", StlUtils::getListElementAt(connectionChildren, 1)->getName().c_str());
    ASSERT_TRUE(StlUtils::getListElementAt(connectionChildren, 1)->getValue().empty());
    attributes = StlUtils::getListElementAt(connectionChildren, 1)->getAttributes();
    ASSERT_EQ(3, attributes.size());
    ASSERT_STREQ("connectionId", StlUtils::getListElementAt(attributes, 0)->getName().c_str());
    ASSERT_STREQ("BD", StlUtils::getListElementAt(attributes, 0)->getValue().c_str());
    ASSERT_STREQ("condition", StlUtils::getListElementAt(attributes, 1)->getName().c_str());
    ASSERT_STREQ("false", StlUtils::getListElementAt(attributes, 1)->getValue().c_str());
    ASSERT_STREQ("id", StlUtils::getListElementAt(attributes, 2)->getName().c_str());
    ASSERT_STREQ("D", StlUtils::getListElementAt(attributes, 2)->getValue().c_str());

    ASSERT_STREQ("state", StlUtils::getListElementAt(statesChildren, 2)->getName().c_str());
    ASSERT_EQ(1, StlUtils::getListElementAt(statesChildren, 2)->getAttributes().size());
    ASSERT_STREQ("id", StlUtils::getListElementAt(statesChildren, 2)->getAttributes().front()->getName().c_str());
    ASSERT_STREQ("C", StlUtils::getListElementAt(statesChildren, 2)->getAttributes().front()->getValue().c_str());
    ASSERT_TRUE(StlUtils::getListElementAt(statesChildren, 2)->getValue().empty());
    ASSERT_EQ(1, StlUtils::getListElementAt(statesChildren, 2)->getChildren().size());
    ASSERT_STREQ("connections", StlUtils::getListElementAt(statesChildren, 2)->getChildren().front()->getName().c_str());
    ASSERT_TRUE(StlUtils::getListElementAt(statesChildren, 2)->getChildren().front()->getValue().empty());
    ASSERT_TRUE(StlUtils::getListElementAt(statesChildren, 2)->getChildren().front()->getAttributes().empty());
    connectionChildren = StlUtils::getListElementAt(statesChildren, 2)->getChildren().front()->getChildren();
    ASSERT_EQ(1, connectionChildren.size());
    ASSERT_STREQ("connection", StlUtils::getListElementAt(connectionChildren, 0)->getName().c_str());
    ASSERT_TRUE(StlUtils::getListElementAt(connectionChildren, 0)->getValue().empty());
    attributes = StlUtils::getListElementAt(connectionChildren, 0)->getAttributes();
    ASSERT_EQ(3, attributes.size());
    ASSERT_STREQ("connectionId", StlUtils::getListElementAt(attributes, 0)->getName().c_str());
    ASSERT_STREQ("CE", StlUtils::getListElementAt(attributes, 0)->getValue().c_str());
    ASSERT_STREQ("condition", StlUtils::getListElementAt(attributes, 1)->getName().c_str());
    ASSERT_STREQ("false", StlUtils::getListElementAt(attributes, 1)->getValue().c_str());
    ASSERT_STREQ("id", StlUtils::getListElementAt(attributes, 2)->getName().c_str());
    ASSERT_STREQ("E", StlUtils::getListElementAt(attributes, 2)->getValue().c_str());

    ASSERT_STREQ("state", StlUtils::getListElementAt(statesChildren, 3)->getName().c_str());
    ASSERT_EQ(1, StlUtils::getListElementAt(statesChildren, 3)->getAttributes().size());
    ASSERT_STREQ("id", StlUtils::getListElementAt(statesChildren, 3)->getAttributes().front()->getName().c_str());
    ASSERT_STREQ("D", StlUtils::getListElementAt(statesChildren, 3)->getAttributes().front()->getValue().c_str());
    ASSERT_TRUE(StlUtils::getListElementAt(statesChildren, 3)->getChildren().front()->getAttributes().empty());
    connectionChildren = StlUtils::getListElementAt(statesChildren, 3)->getChildren().front()->getChildren();
    ASSERT_EQ(1, connectionChildren.size());
    ASSERT_STREQ("connection", StlUtils::getListElementAt(connectionChildren, 0)->getName().c_str());
    ASSERT_TRUE(StlUtils::getListElementAt(connectionChildren, 0)->getValue().empty());
    attributes = StlUtils::getListElementAt(connectionChildren, 0)->getAttributes();
    ASSERT_EQ(3, attributes.size());
    ASSERT_STREQ("connectionId", StlUtils::getListElementAt(attributes, 0)->getName().c_str());
    ASSERT_STREQ("DE", StlUtils::getListElementAt(attributes, 0)->getValue().c_str());
    ASSERT_STREQ("condition", StlUtils::getListElementAt(attributes, 1)->getName().c_str());
    ASSERT_STREQ("false", StlUtils::getListElementAt(attributes, 1)->getValue().c_str());
    ASSERT_STREQ("id", StlUtils::getListElementAt(attributes, 2)->getName().c_str());
    ASSERT_STREQ("E", StlUtils::getListElementAt(attributes, 2)->getValue().c_str());

    ASSERT_STREQ("state", StlUtils::getListElementAt(statesChildren, 4)->getName().c_str());
    ASSERT_EQ(1, StlUtils::getListElementAt(statesChildren, 4)->getAttributes().size());
    ASSERT_STREQ("id", StlUtils::getListElementAt(statesChildren, 4)->getAttributes().front()->getName().c_str());
    ASSERT_STREQ("E", StlUtils::getListElementAt(statesChildren, 4)->getAttributes().front()->getValue().c_str());
    ASSERT_TRUE(StlUtils::getListElementAt(statesChildren, 4)->getChildren().empty());

    // current state

    ASSERT_STREQ("currentState", StlUtils::getListElementAt(children, 1)->getName().c_str());
    ASSERT_STREQ("A", StlUtils::getListElementAt(children, 1)->getValue().c_str());
    ASSERT_TRUE(StlUtils::getListElementAt(children, 1)->getChildren().empty());
    ASSERT_TRUE(StlUtils::getListElementAt(children, 1)->getAttributes().empty());

    // memory

    memoryChildren = StlUtils::getListElementAt(children, 2)->getChildren();
    ASSERT_EQ(3, memoryChildren.size());

    ASSERT_STREQ("location", StlUtils::getListElementAt(memoryChildren, 0)->getName().c_str());
    ASSERT_STREQ("A", StlUtils::getListElementAt(memoryChildren, 0)->getValue().c_str());
    ASSERT_TRUE(StlUtils::getListElementAt(memoryChildren, 0)->getChildren().empty());
    ASSERT_TRUE(StlUtils::getListElementAt(memoryChildren, 0)->getAttributes().empty());

    ASSERT_STREQ("location", StlUtils::getListElementAt(memoryChildren, 1)->getName().c_str());
    ASSERT_STREQ("B", StlUtils::getListElementAt(memoryChildren, 1)->getValue().c_str());
    ASSERT_TRUE(StlUtils::getListElementAt(memoryChildren, 1)->getChildren().empty());
    ASSERT_TRUE(StlUtils::getListElementAt(memoryChildren, 1)->getAttributes().empty());

    ASSERT_STREQ("location", StlUtils::getListElementAt(memoryChildren, 2)->getName().c_str());
    ASSERT_STREQ("C", StlUtils::getListElementAt(memoryChildren, 2)->getValue().c_str());
    ASSERT_TRUE(StlUtils::getListElementAt(memoryChildren, 2)->getChildren().empty());
    ASSERT_TRUE(StlUtils::getListElementAt(memoryChildren, 2)->getAttributes().empty());
  }

  TEST_F(XmlParserTest, getDocument)
  {
    string xmlPath = TestHelper::getResourcesFolderLocation() + "state-machine-test.xml";
    XmlParser xmlParser{make_shared<XmlDocument>()};

    ASSERT_TRUE(xmlParser.getDocument() != nullptr);
  }

  TEST_F(XmlParserTest, setDocument)
  {
    string xmlPath = TestHelper::getResourcesFolderLocation() + "state-machine-test.xml";
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

    EXPECT_THROW(
        {
          try
          {
            xmlParser.setDocument(nullptr);
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }
}
