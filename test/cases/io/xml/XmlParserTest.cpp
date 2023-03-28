/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-26
 * Changed:         2023-03-25
 *
 * */

#include <classes/TestHelper.hpp>
#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>
#include <ls-std/ls-std-io.hpp>

using ls::std::core::IllegalArgumentException;
using ls::std::core::type::byte_field;
using ls::std::io::File;
using ls::std::io::FileReader;
using ls::std::io::XmlAttribute;
using ls::std::io::XmlDocument;
using ls::std::io::XmlNode;
using ls::std::io::XmlParser;
using ls::std::test::TestHelper;
using std::list;
using std::make_shared;
using std::shared_ptr;
using std::string;
using testing::Test;

namespace
{
  class XmlParserTest : public Test
  {
    public:

      XmlParserTest() = default;
      ~XmlParserTest() override = default;

      static shared_ptr<XmlAttribute> getAttributeAtPosition(const list<shared_ptr<XmlAttribute>> &_attributes, size_t _index)
      {
        shared_ptr<XmlAttribute> attribute{};

        if (_index < _attributes.size())
        {
          size_t counter{};

          for (const auto &_value : _attributes)
          {
            if (counter == _index)
            {
              attribute = _value;
              break;
            }

            counter++;
          }
        }

        return attribute;
      }

      static shared_ptr<XmlNode> getChildAtPosition(const list<shared_ptr<XmlNode>> &_children, size_t _index)
      {
        shared_ptr<XmlNode> node{};

        if (_index < _children.size())
        {
          size_t counter{};

          for (const auto &_value : _children)
          {
            if (counter == _index)
            {
              node = _value;
              break;
            }

            counter++;
          }
        }

        return node;
      }

      static byte_field readXmlStateMachine()
      {
        string xmlPath = TestHelper::getResourcesFolderLocation() + "state-machine-test.xml";
        File file{xmlPath};
        byte_field data = FileReader{file}.read();

        return data;
      }
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
    ASSERT_STREQ("states", XmlParserTest::getChildAtPosition(children, 0)->getName().c_str());
    ASSERT_TRUE(XmlParserTest::getChildAtPosition(children, 0)->getAttributes().empty());
    ASSERT_STREQ("currentState", XmlParserTest::getChildAtPosition(children, 1)->getName().c_str());
    ASSERT_TRUE(XmlParserTest::getChildAtPosition(children, 1)->getAttributes().empty());
    ASSERT_STREQ("memory", XmlParserTest::getChildAtPosition(children, 2)->getName().c_str());
    ASSERT_TRUE(XmlParserTest::getChildAtPosition(children, 2)->getAttributes().empty());

    // states

    statesChildren = XmlParserTest::getChildAtPosition(children, 0)->getChildren();
    ASSERT_EQ(5, statesChildren.size());

    ASSERT_STREQ("state", XmlParserTest::getChildAtPosition(statesChildren, 0)->getName().c_str());
    ASSERT_EQ(1, XmlParserTest::getChildAtPosition(statesChildren, 0)->getAttributes().size());
    ASSERT_STREQ("id", XmlParserTest::getChildAtPosition(statesChildren, 0)->getAttributes().front()->getName().c_str());
    ASSERT_STREQ("A", XmlParserTest::getChildAtPosition(statesChildren, 0)->getAttributes().front()->getValue().c_str());
    ASSERT_TRUE(XmlParserTest::getChildAtPosition(statesChildren, 0)->getValue().empty());
    ASSERT_EQ(1, XmlParserTest::getChildAtPosition(statesChildren, 0)->getChildren().size());
    ASSERT_STREQ("connections", XmlParserTest::getChildAtPosition(statesChildren, 0)->getChildren().front()->getName().c_str());
    ASSERT_TRUE(XmlParserTest::getChildAtPosition(statesChildren, 0)->getChildren().front()->getValue().empty());
    ASSERT_TRUE(XmlParserTest::getChildAtPosition(statesChildren, 0)->getChildren().front()->getAttributes().empty());
    connectionChildren = XmlParserTest::getChildAtPosition(statesChildren, 0)->getChildren().front()->getChildren();
    ASSERT_EQ(1, connectionChildren.size());
    ASSERT_STREQ("connection", XmlParserTest::getChildAtPosition(connectionChildren, 0)->getName().c_str());
    ASSERT_TRUE(XmlParserTest::getChildAtPosition(connectionChildren, 0)->getValue().empty());
    attributes = XmlParserTest::getChildAtPosition(connectionChildren, 0)->getAttributes();
    ASSERT_EQ(3, attributes.size());
    ASSERT_STREQ("connectionId", XmlParserTest::getAttributeAtPosition(attributes, 0)->getName().c_str());
    ASSERT_STREQ("AB", XmlParserTest::getAttributeAtPosition(attributes, 0)->getValue().c_str());
    ASSERT_STREQ("condition", XmlParserTest::getAttributeAtPosition(attributes, 1)->getName().c_str());
    ASSERT_STREQ("false", XmlParserTest::getAttributeAtPosition(attributes, 1)->getValue().c_str());
    ASSERT_STREQ("id", XmlParserTest::getAttributeAtPosition(attributes, 2)->getName().c_str());
    ASSERT_STREQ("B", XmlParserTest::getAttributeAtPosition(attributes, 2)->getValue().c_str());

    ASSERT_STREQ("state", XmlParserTest::getChildAtPosition(statesChildren, 1)->getName().c_str());
    ASSERT_EQ(1, XmlParserTest::getChildAtPosition(statesChildren, 1)->getAttributes().size());
    ASSERT_STREQ("id", XmlParserTest::getChildAtPosition(statesChildren, 1)->getAttributes().front()->getName().c_str());
    ASSERT_STREQ("B", XmlParserTest::getChildAtPosition(statesChildren, 1)->getAttributes().front()->getValue().c_str());
    ASSERT_TRUE(XmlParserTest::getChildAtPosition(statesChildren, 1)->getValue().empty());
    ASSERT_EQ(1, XmlParserTest::getChildAtPosition(statesChildren, 1)->getChildren().size());
    ASSERT_STREQ("connections", XmlParserTest::getChildAtPosition(statesChildren, 1)->getChildren().front()->getName().c_str());
    ASSERT_TRUE(XmlParserTest::getChildAtPosition(statesChildren, 1)->getChildren().front()->getValue().empty());
    ASSERT_TRUE(XmlParserTest::getChildAtPosition(statesChildren, 1)->getChildren().front()->getAttributes().empty());
    connectionChildren = XmlParserTest::getChildAtPosition(statesChildren, 1)->getChildren().front()->getChildren();
    ASSERT_EQ(2, connectionChildren.size());
    ASSERT_STREQ("connection", XmlParserTest::getChildAtPosition(connectionChildren, 0)->getName().c_str());
    ASSERT_TRUE(XmlParserTest::getChildAtPosition(connectionChildren, 0)->getValue().empty());
    attributes = XmlParserTest::getChildAtPosition(connectionChildren, 0)->getAttributes();
    ASSERT_EQ(3, attributes.size());
    ASSERT_STREQ("connectionId", XmlParserTest::getAttributeAtPosition(attributes, 0)->getName().c_str());
    ASSERT_STREQ("BC", XmlParserTest::getAttributeAtPosition(attributes, 0)->getValue().c_str());
    ASSERT_STREQ("condition", XmlParserTest::getAttributeAtPosition(attributes, 1)->getName().c_str());
    ASSERT_STREQ("false", XmlParserTest::getAttributeAtPosition(attributes, 1)->getValue().c_str());
    ASSERT_STREQ("id", XmlParserTest::getAttributeAtPosition(attributes, 2)->getName().c_str());
    ASSERT_STREQ("C", XmlParserTest::getAttributeAtPosition(attributes, 2)->getValue().c_str());
    ASSERT_STREQ("connection", XmlParserTest::getChildAtPosition(connectionChildren, 1)->getName().c_str());
    ASSERT_TRUE(XmlParserTest::getChildAtPosition(connectionChildren, 1)->getValue().empty());
    attributes = XmlParserTest::getChildAtPosition(connectionChildren, 1)->getAttributes();
    ASSERT_EQ(3, attributes.size());
    ASSERT_STREQ("connectionId", XmlParserTest::getAttributeAtPosition(attributes, 0)->getName().c_str());
    ASSERT_STREQ("BD", XmlParserTest::getAttributeAtPosition(attributes, 0)->getValue().c_str());
    ASSERT_STREQ("condition", XmlParserTest::getAttributeAtPosition(attributes, 1)->getName().c_str());
    ASSERT_STREQ("false", XmlParserTest::getAttributeAtPosition(attributes, 1)->getValue().c_str());
    ASSERT_STREQ("id", XmlParserTest::getAttributeAtPosition(attributes, 2)->getName().c_str());
    ASSERT_STREQ("D", XmlParserTest::getAttributeAtPosition(attributes, 2)->getValue().c_str());

    ASSERT_STREQ("state", XmlParserTest::getChildAtPosition(statesChildren, 2)->getName().c_str());
    ASSERT_EQ(1, XmlParserTest::getChildAtPosition(statesChildren, 2)->getAttributes().size());
    ASSERT_STREQ("id", XmlParserTest::getChildAtPosition(statesChildren, 2)->getAttributes().front()->getName().c_str());
    ASSERT_STREQ("C", XmlParserTest::getChildAtPosition(statesChildren, 2)->getAttributes().front()->getValue().c_str());
    ASSERT_TRUE(XmlParserTest::getChildAtPosition(statesChildren, 2)->getValue().empty());
    ASSERT_EQ(1, XmlParserTest::getChildAtPosition(statesChildren, 2)->getChildren().size());
    ASSERT_STREQ("connections", XmlParserTest::getChildAtPosition(statesChildren, 2)->getChildren().front()->getName().c_str());
    ASSERT_TRUE(XmlParserTest::getChildAtPosition(statesChildren, 2)->getChildren().front()->getValue().empty());
    ASSERT_TRUE(XmlParserTest::getChildAtPosition(statesChildren, 2)->getChildren().front()->getAttributes().empty());
    connectionChildren = XmlParserTest::getChildAtPosition(statesChildren, 2)->getChildren().front()->getChildren();
    ASSERT_EQ(1, connectionChildren.size());
    ASSERT_STREQ("connection", XmlParserTest::getChildAtPosition(connectionChildren, 0)->getName().c_str());
    ASSERT_TRUE(XmlParserTest::getChildAtPosition(connectionChildren, 0)->getValue().empty());
    attributes = XmlParserTest::getChildAtPosition(connectionChildren, 0)->getAttributes();
    ASSERT_EQ(3, attributes.size());
    ASSERT_STREQ("connectionId", XmlParserTest::getAttributeAtPosition(attributes, 0)->getName().c_str());
    ASSERT_STREQ("CE", XmlParserTest::getAttributeAtPosition(attributes, 0)->getValue().c_str());
    ASSERT_STREQ("condition", XmlParserTest::getAttributeAtPosition(attributes, 1)->getName().c_str());
    ASSERT_STREQ("false", XmlParserTest::getAttributeAtPosition(attributes, 1)->getValue().c_str());
    ASSERT_STREQ("id", XmlParserTest::getAttributeAtPosition(attributes, 2)->getName().c_str());
    ASSERT_STREQ("E", XmlParserTest::getAttributeAtPosition(attributes, 2)->getValue().c_str());

    ASSERT_STREQ("state", XmlParserTest::getChildAtPosition(statesChildren, 3)->getName().c_str());
    ASSERT_EQ(1, XmlParserTest::getChildAtPosition(statesChildren, 3)->getAttributes().size());
    ASSERT_STREQ("id", XmlParserTest::getChildAtPosition(statesChildren, 3)->getAttributes().front()->getName().c_str());
    ASSERT_STREQ("D", XmlParserTest::getChildAtPosition(statesChildren, 3)->getAttributes().front()->getValue().c_str());
    ASSERT_TRUE(XmlParserTest::getChildAtPosition(statesChildren, 3)->getChildren().front()->getAttributes().empty());
    connectionChildren = XmlParserTest::getChildAtPosition(statesChildren, 3)->getChildren().front()->getChildren();
    ASSERT_EQ(1, connectionChildren.size());
    ASSERT_STREQ("connection", XmlParserTest::getChildAtPosition(connectionChildren, 0)->getName().c_str());
    ASSERT_TRUE(XmlParserTest::getChildAtPosition(connectionChildren, 0)->getValue().empty());
    attributes = XmlParserTest::getChildAtPosition(connectionChildren, 0)->getAttributes();
    ASSERT_EQ(3, attributes.size());
    ASSERT_STREQ("connectionId", XmlParserTest::getAttributeAtPosition(attributes, 0)->getName().c_str());
    ASSERT_STREQ("DE", XmlParserTest::getAttributeAtPosition(attributes, 0)->getValue().c_str());
    ASSERT_STREQ("condition", XmlParserTest::getAttributeAtPosition(attributes, 1)->getName().c_str());
    ASSERT_STREQ("false", XmlParserTest::getAttributeAtPosition(attributes, 1)->getValue().c_str());
    ASSERT_STREQ("id", XmlParserTest::getAttributeAtPosition(attributes, 2)->getName().c_str());
    ASSERT_STREQ("E", XmlParserTest::getAttributeAtPosition(attributes, 2)->getValue().c_str());

    ASSERT_STREQ("state", XmlParserTest::getChildAtPosition(statesChildren, 4)->getName().c_str());
    ASSERT_EQ(1, XmlParserTest::getChildAtPosition(statesChildren, 4)->getAttributes().size());
    ASSERT_STREQ("id", XmlParserTest::getChildAtPosition(statesChildren, 4)->getAttributes().front()->getName().c_str());
    ASSERT_STREQ("E", XmlParserTest::getChildAtPosition(statesChildren, 4)->getAttributes().front()->getValue().c_str());
    ASSERT_TRUE(XmlParserTest::getChildAtPosition(statesChildren, 4)->getChildren().empty());

    // current state

    ASSERT_STREQ("currentState", XmlParserTest::getChildAtPosition(children, 1)->getName().c_str());
    ASSERT_STREQ("A", XmlParserTest::getChildAtPosition(children, 1)->getValue().c_str());
    ASSERT_TRUE(XmlParserTest::getChildAtPosition(children, 1)->getChildren().empty());
    ASSERT_TRUE(XmlParserTest::getChildAtPosition(children, 1)->getAttributes().empty());

    // memory

    memoryChildren = XmlParserTest::getChildAtPosition(children, 2)->getChildren();
    ASSERT_EQ(3, memoryChildren.size());

    ASSERT_STREQ("location", XmlParserTest::getChildAtPosition(memoryChildren, 0)->getName().c_str());
    ASSERT_STREQ("A", XmlParserTest::getChildAtPosition(memoryChildren, 0)->getValue().c_str());
    ASSERT_TRUE(XmlParserTest::getChildAtPosition(memoryChildren, 0)->getChildren().empty());
    ASSERT_TRUE(XmlParserTest::getChildAtPosition(memoryChildren, 0)->getAttributes().empty());

    ASSERT_STREQ("location", XmlParserTest::getChildAtPosition(memoryChildren, 1)->getName().c_str());
    ASSERT_STREQ("B", XmlParserTest::getChildAtPosition(memoryChildren, 1)->getValue().c_str());
    ASSERT_TRUE(XmlParserTest::getChildAtPosition(memoryChildren, 1)->getChildren().empty());
    ASSERT_TRUE(XmlParserTest::getChildAtPosition(memoryChildren, 1)->getAttributes().empty());

    ASSERT_STREQ("location", XmlParserTest::getChildAtPosition(memoryChildren, 2)->getName().c_str());
    ASSERT_STREQ("C", XmlParserTest::getChildAtPosition(memoryChildren, 2)->getValue().c_str());
    ASSERT_TRUE(XmlParserTest::getChildAtPosition(memoryChildren, 2)->getChildren().empty());
    ASSERT_TRUE(XmlParserTest::getChildAtPosition(memoryChildren, 2)->getAttributes().empty());
  }

  TEST_F(XmlParserTest, getDocument)
  {
    XmlParser xmlParser{make_shared<XmlDocument>()};
    ASSERT_TRUE(xmlParser.getDocument() != nullptr);
  }

  TEST_F(XmlParserTest, setDocument)
  {
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
