/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-10-10
 * Changed:         2020-10-22
 *
 * */

#include <gtest/gtest.h>
#include "../../../../source/io/xml/XMLReader.hpp"
#include "../../../TestHelper.hpp"
#include "../../../../source/utils/STLUtils.hpp"

namespace {
  class XMLReaderTest : public ::testing::Test {
    protected:

      XMLReaderTest() = default;
      ~XMLReaderTest() override = default;

      void SetUp() override {}
      void TearDown() override {}
  };

  TEST_F(XMLReaderTest, read)
  {
    std::string xmlPath = TestHelper::getResourcesFolderLocation() + "state_machine_test.xml";
    ls_std::XMLReader xmlReader {std::make_shared<ls_std::XMLDocument>(), xmlPath};
    std::list<std::shared_ptr<ls_std::XMLNode>> children, statesChildren, memoryChildren {};
    std::list<std::shared_ptr<ls_std::XMLAttribute>> attributes {};

    ASSERT_TRUE(!xmlReader.read().empty());

    // check declaration

    ASSERT_STREQ("UTF-8", xmlReader.getDocument()->getDeclaration()->getEncoding().c_str());
    ASSERT_STREQ("1.0", xmlReader.getDocument()->getDeclaration()->getVersion().c_str());
    ASSERT_TRUE(xmlReader.getDocument()->getDeclaration()->getStandalone().empty());

    // check root element

    std::shared_ptr<ls_std::XMLNode> root = xmlReader.getDocument()->getRootElement();
    ASSERT_STREQ("stateMachine", root->getName().c_str());
    ASSERT_STREQ("name", root->getAttributes().front()->getName().c_str());
    ASSERT_STREQ("test_machine", root->getAttributes().front()->getValue().c_str());

    // check 2. level

    children = root->getChildren();
    ASSERT_EQ(3, children.size());
    ASSERT_STREQ("states", ls_std::STLUtils::getListElementAt(children, 0)->getName().c_str());
    ASSERT_STREQ("currentState", ls_std::STLUtils::getListElementAt(children, 1)->getName().c_str());
    ASSERT_STREQ("memory", ls_std::STLUtils::getListElementAt(children, 2)->getName().c_str());

    // states

    statesChildren = ls_std::STLUtils::getListElementAt(children, 0)->getChildren();
    ASSERT_EQ(5, statesChildren.size());

    ASSERT_STREQ("state", ls_std::STLUtils::getListElementAt(statesChildren, 0)->getName().c_str());
    ASSERT_STREQ("id", ls_std::STLUtils::getListElementAt(statesChildren, 0)->getAttributes().front()->getName().c_str());
    ASSERT_STREQ("A", ls_std::STLUtils::getListElementAt(statesChildren, 0)->getAttributes().front()->getValue().c_str());

    ASSERT_STREQ("state", ls_std::STLUtils::getListElementAt(statesChildren, 1)->getName().c_str());
    ASSERT_STREQ("id", ls_std::STLUtils::getListElementAt(statesChildren, 1)->getAttributes().front()->getName().c_str());
    ASSERT_STREQ("B", ls_std::STLUtils::getListElementAt(statesChildren, 1)->getAttributes().front()->getValue().c_str());

    ASSERT_STREQ("state", ls_std::STLUtils::getListElementAt(statesChildren, 2)->getName().c_str());
    ASSERT_STREQ("id", ls_std::STLUtils::getListElementAt(statesChildren, 2)->getAttributes().front()->getName().c_str());
    ASSERT_STREQ("C", ls_std::STLUtils::getListElementAt(statesChildren, 2)->getAttributes().front()->getValue().c_str());

    ASSERT_STREQ("state", ls_std::STLUtils::getListElementAt(statesChildren, 3)->getName().c_str());
    ASSERT_STREQ("id", ls_std::STLUtils::getListElementAt(statesChildren, 3)->getAttributes().front()->getName().c_str());
    ASSERT_STREQ("D", ls_std::STLUtils::getListElementAt(statesChildren, 3)->getAttributes().front()->getValue().c_str());

    ASSERT_STREQ("state", ls_std::STLUtils::getListElementAt(statesChildren, 4)->getName().c_str());
    ASSERT_STREQ("id", ls_std::STLUtils::getListElementAt(statesChildren, 4)->getAttributes().front()->getName().c_str());
    ASSERT_STREQ("E", ls_std::STLUtils::getListElementAt(statesChildren, 4)->getAttributes().front()->getValue().c_str());

    //TODO: current state

    // memory

    memoryChildren = ls_std::STLUtils::getListElementAt(children, 2)->getChildren();
    ASSERT_EQ(3, memoryChildren.size());

    ASSERT_STREQ("location", ls_std::STLUtils::getListElementAt(memoryChildren, 0)->getName().c_str());
    ASSERT_STREQ("location", ls_std::STLUtils::getListElementAt(memoryChildren, 1)->getName().c_str());
    ASSERT_STREQ("location", ls_std::STLUtils::getListElementAt(memoryChildren, 2)->getName().c_str());
  }

  TEST_F(XMLReaderTest, getDocument)
  {
    std::string xmlPath = TestHelper::getResourcesFolderLocation() + "state_machine_test.xml";
    ls_std::XMLReader xmlReader {std::make_shared<ls_std::XMLDocument>(), xmlPath};

    ASSERT_TRUE(xmlReader.getDocument() != nullptr);
  }

  TEST_F(XMLReaderTest, setFile)
  {
    std::string xmlPath = TestHelper::getResourcesFolderLocation() + "state_machine_test.xml";
    ls_std::XMLReader xmlReader {std::make_shared<ls_std::XMLDocument>(), xmlPath};
    ls_std::File xmlFile {xmlPath};
    xmlReader.setFile(xmlFile);

    ASSERT_TRUE(true);
  }
}
