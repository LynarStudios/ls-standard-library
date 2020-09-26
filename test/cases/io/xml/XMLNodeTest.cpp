/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-25
 * Changed:         2020-09-26
 *
 * */

#include <gtest/gtest.h>
#include "../../../../source/io/xml/XMLNode.hpp"
#include "../../../TestDataFactory.hpp"

namespace {
  class XMLNodeTest : public ::testing::Test {
    protected:

      XMLNodeTest() = default;
      ~XMLNodeTest() override = default;

      void SetUp() override {}
      void TearDown() override {}
  };

  TEST_F(XMLNodeTest, addAttributeAfter)
  {
    ls_std::XMLNode dialogNode {"dialog"};
    std::shared_ptr<ls_std::XMLAttribute> currentAttribute {};
    dialogNode.addAttributeToEnd(std::make_shared<ls_std::XMLAttribute>("events"));
    dialogNode.addAttributeToEnd(std::make_shared<ls_std::XMLAttribute>("assets"));

    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 0);
    ASSERT_STREQ("events", currentAttribute->getName().c_str());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 1);
    ASSERT_STREQ("assets", currentAttribute->getName().c_str());

    // add id after events

    ASSERT_TRUE(dialogNode.addAttributeAfter(std::make_shared<ls_std::XMLAttribute>("id"), "events"));
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 0);
    ASSERT_STREQ("events", currentAttribute->getName().c_str());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 1);
    ASSERT_STREQ("id", currentAttribute->getName().c_str());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 2);
    ASSERT_STREQ("assets", currentAttribute->getName().c_str());

    // add tasks after assets

    ASSERT_TRUE(dialogNode.addAttributeAfter(std::make_shared<ls_std::XMLAttribute>("tasks"), "assets"));
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 0);
    ASSERT_STREQ("events", currentAttribute->getName().c_str());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 1);
    ASSERT_STREQ("id", currentAttribute->getName().c_str());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 2);
    ASSERT_STREQ("assets", currentAttribute->getName().c_str());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 3);
    ASSERT_STREQ("tasks", currentAttribute->getName().c_str());
  }

  TEST_F(XMLNodeTest, addAttributeAfterNegative)
  {
    ls_std::XMLNode dialogNode {"dialog"};
    dialogNode.addAttributeToEnd(std::make_shared<ls_std::XMLAttribute>("events"));

    ASSERT_FALSE(dialogNode.addAttributeAfter(std::make_shared<ls_std::XMLAttribute>("id"), "assets"));
  }

  TEST_F(XMLNodeTest, addAttributeBefore)
  {
    ls_std::XMLNode dialogNode {"dialog"};
    std::shared_ptr<ls_std::XMLAttribute> currentAttribute {};
    dialogNode.addAttributeToEnd(std::make_shared<ls_std::XMLAttribute>("events"));
    dialogNode.addAttributeToEnd(std::make_shared<ls_std::XMLAttribute>("assets"));

    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 0);
    ASSERT_STREQ("events", currentAttribute->getName().c_str());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 1);
    ASSERT_STREQ("assets", currentAttribute->getName().c_str());

    // add id before events

    ASSERT_TRUE(dialogNode.addAttributeBefore(std::make_shared<ls_std::XMLAttribute>("id"), "events"));
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 0);
    ASSERT_STREQ("id", currentAttribute->getName().c_str());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 1);
    ASSERT_STREQ("events", currentAttribute->getName().c_str());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 2);
    ASSERT_STREQ("assets", currentAttribute->getName().c_str());

    // add tasks before assets

    ASSERT_TRUE(dialogNode.addAttributeBefore(std::make_shared<ls_std::XMLAttribute>("tasks"), "assets"));
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 0);
    ASSERT_STREQ("id", currentAttribute->getName().c_str());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 1);
    ASSERT_STREQ("events", currentAttribute->getName().c_str());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 2);
    ASSERT_STREQ("tasks", currentAttribute->getName().c_str());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 3);
    ASSERT_STREQ("assets", currentAttribute->getName().c_str());
  }

  TEST_F(XMLNodeTest, addAttributeBeforeNegative)
  {
    ls_std::XMLNode dialogNode {"dialog"};
    dialogNode.addAttributeToEnd(std::make_shared<ls_std::XMLAttribute>("events"));

    ASSERT_FALSE(dialogNode.addAttributeBefore(std::make_shared<ls_std::XMLAttribute>("id"), "assets"));
  }

  TEST_F(XMLNodeTest, addAttributeToBeginning)
  {
    ls_std::XMLNode dialogNode {"dialog"};
    std::shared_ptr<ls_std::XMLAttribute> currentAttribute {};

    dialogNode.addAttributeToBeginning(std::make_shared<ls_std::XMLAttribute>("id"));
    ASSERT_EQ(1, dialogNode.getAttributes().size());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 0);
    ASSERT_STREQ("id", currentAttribute->getName().c_str());

    dialogNode.addAttributeToBeginning(std::make_shared<ls_std::XMLAttribute>("assets"));
    ASSERT_EQ(2, dialogNode.getAttributes().size());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 0);
    ASSERT_STREQ("assets", currentAttribute->getName().c_str());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 1);
    ASSERT_STREQ("id", currentAttribute->getName().c_str());

    dialogNode.addAttributeToBeginning(std::make_shared<ls_std::XMLAttribute>("events"));
    ASSERT_EQ(3, dialogNode.getAttributes().size());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 0);
    ASSERT_STREQ("events", currentAttribute->getName().c_str());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 1);
    ASSERT_STREQ("assets", currentAttribute->getName().c_str());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 2);
    ASSERT_STREQ("id", currentAttribute->getName().c_str());
  }

  TEST_F(XMLNodeTest, addAttributeToEnd)
  {
    ls_std::XMLNode dialogNode {"dialog"};
    std::shared_ptr<ls_std::XMLAttribute> currentAttribute {};

    dialogNode.addAttributeToEnd(std::make_shared<ls_std::XMLAttribute>("id"));
    ASSERT_EQ(1, dialogNode.getAttributes().size());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 0);
    ASSERT_STREQ("id", currentAttribute->getName().c_str());

    dialogNode.addAttributeToEnd(std::make_shared<ls_std::XMLAttribute>("assets"));
    ASSERT_EQ(2, dialogNode.getAttributes().size());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 0);
    ASSERT_STREQ("id", currentAttribute->getName().c_str());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 1);
    ASSERT_STREQ("assets", currentAttribute->getName().c_str());

    dialogNode.addAttributeToEnd(std::make_shared<ls_std::XMLAttribute>("events"));
    ASSERT_EQ(3, dialogNode.getAttributes().size());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 0);
    ASSERT_STREQ("id", currentAttribute->getName().c_str());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 1);
    ASSERT_STREQ("assets", currentAttribute->getName().c_str());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 2);
    ASSERT_STREQ("events", currentAttribute->getName().c_str());
  }

  TEST_F(XMLNodeTest, addChildAfter)
  {
    ls_std::XMLNode dialogsNode {"dialogs"};
    std::shared_ptr<ls_std::XMLNode> currentNode {};
    std::shared_ptr<ls_std::XMLNode> dialogNodeA = std::make_shared<ls_std::XMLNode>("dialogNodeA");
    std::shared_ptr<ls_std::XMLNode> dialogNodeB = std::make_shared<ls_std::XMLNode>("dialogNodeB");
    std::shared_ptr<ls_std::XMLNode> dialogNodeC = std::make_shared<ls_std::XMLNode>("dialogNodeC");
    std::shared_ptr<ls_std::XMLNode> dialogNodeD = std::make_shared<ls_std::XMLNode>("dialogNodeD");

    ASSERT_TRUE(dialogsNode.addChildToEnd(dialogNodeB));
    ASSERT_TRUE(dialogsNode.addChildToEnd(dialogNodeC));
    ASSERT_EQ(2, dialogsNode.getChildren().size());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 0);
    ASSERT_STREQ("dialogNodeB", currentNode->getName().c_str());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 1);
    ASSERT_STREQ("dialogNodeC", currentNode->getName().c_str());

    // add A after B

    ASSERT_TRUE(dialogsNode.addChildAfter(dialogNodeA, dialogNodeB));

    currentNode = *std::next(dialogsNode.getChildren().begin(), 0);
    ASSERT_STREQ("dialogNodeB", currentNode->getName().c_str());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 1);
    ASSERT_STREQ("dialogNodeA", currentNode->getName().c_str());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 2);
    ASSERT_STREQ("dialogNodeC", currentNode->getName().c_str());

    // add D after C

    ASSERT_TRUE(dialogsNode.addChildAfter(dialogNodeD, dialogNodeC));

    currentNode = *std::next(dialogsNode.getChildren().begin(), 0);
    ASSERT_STREQ("dialogNodeB", currentNode->getName().c_str());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 1);
    ASSERT_STREQ("dialogNodeA", currentNode->getName().c_str());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 2);
    ASSERT_STREQ("dialogNodeC", currentNode->getName().c_str());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 3);
    ASSERT_STREQ("dialogNodeD", currentNode->getName().c_str());
  }

  TEST_F(XMLNodeTest, addChildAfterNegative)
  {
    ls_std::XMLNode dialogsNode {"dialogs"};
    std::shared_ptr<ls_std::XMLNode> dialogNodeA = std::make_shared<ls_std::XMLNode>("dialogNodeA");
    std::shared_ptr<ls_std::XMLNode> dialogNodeB = std::make_shared<ls_std::XMLNode>("dialogNodeB");

    ASSERT_FALSE(dialogsNode.addChildAfter(dialogNodeA, dialogNodeB));
  }

  TEST_F(XMLNodeTest, addChildBefore)
  {
    ls_std::XMLNode dialogsNode {"dialogs"};
    std::shared_ptr<ls_std::XMLNode> currentNode {};
    std::shared_ptr<ls_std::XMLNode> dialogNodeA = std::make_shared<ls_std::XMLNode>("dialogNodeA");
    std::shared_ptr<ls_std::XMLNode> dialogNodeB = std::make_shared<ls_std::XMLNode>("dialogNodeB");
    std::shared_ptr<ls_std::XMLNode> dialogNodeC = std::make_shared<ls_std::XMLNode>("dialogNodeC");
    std::shared_ptr<ls_std::XMLNode> dialogNodeD = std::make_shared<ls_std::XMLNode>("dialogNodeD");

    ASSERT_TRUE(dialogsNode.addChildToEnd(dialogNodeB));
    ASSERT_TRUE(dialogsNode.addChildToEnd(dialogNodeC));
    ASSERT_EQ(2, dialogsNode.getChildren().size());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 0);
    ASSERT_STREQ("dialogNodeB", currentNode->getName().c_str());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 1);
    ASSERT_STREQ("dialogNodeC", currentNode->getName().c_str());

    // add A before C

    ASSERT_TRUE(dialogsNode.addChildBefore(dialogNodeA, dialogNodeC));

    currentNode = *std::next(dialogsNode.getChildren().begin(), 0);
    ASSERT_STREQ("dialogNodeB", currentNode->getName().c_str());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 1);
    ASSERT_STREQ("dialogNodeA", currentNode->getName().c_str());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 2);
    ASSERT_STREQ("dialogNodeC", currentNode->getName().c_str());

    // add D before B

    ASSERT_TRUE(dialogsNode.addChildBefore(dialogNodeD, dialogNodeB));

    currentNode = *std::next(dialogsNode.getChildren().begin(), 0);
    ASSERT_STREQ("dialogNodeD", currentNode->getName().c_str());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 1);
    ASSERT_STREQ("dialogNodeB", currentNode->getName().c_str());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 2);
    ASSERT_STREQ("dialogNodeA", currentNode->getName().c_str());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 3);
    ASSERT_STREQ("dialogNodeC", currentNode->getName().c_str());
  }

  TEST_F(XMLNodeTest, addChildToBeginning)
  {
    ls_std::XMLNode dialogsNode {"dialogs"};
    std::shared_ptr<ls_std::XMLNode> currentNode {};

    ls_std::XMLNode dialogNodeA {"dialogNodeA"};
    ls_std::XMLNode dialogNodeB {"dialogNodeB"};
    ls_std::XMLNode dialogNodeC {"dialogNodeC"};

    ASSERT_TRUE(dialogsNode.getChildren().empty());
    ASSERT_EQ(0, dialogsNode.getChildren().size());

    // adding C

    ASSERT_TRUE(dialogsNode.addChildToBeginning(std::make_shared<ls_std::XMLNode>(dialogNodeC)));
    ASSERT_TRUE(!dialogsNode.getChildren().empty());
    ASSERT_EQ(1, dialogsNode.getChildren().size());

    currentNode = *std::next(dialogsNode.getChildren().begin(), 0);
    ASSERT_STREQ("dialogNodeC", currentNode->getName().c_str());

    // adding B

    ASSERT_TRUE(dialogsNode.addChildToBeginning(std::make_shared<ls_std::XMLNode>(dialogNodeB)));
    ASSERT_EQ(2, dialogsNode.getChildren().size());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 0);
    ASSERT_STREQ("dialogNodeB", currentNode->getName().c_str());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 1);
    ASSERT_STREQ("dialogNodeC", currentNode->getName().c_str());

    // adding A

    ASSERT_TRUE(dialogsNode.addChildToBeginning(std::make_shared<ls_std::XMLNode>(dialogNodeA)));
    ASSERT_EQ(3, dialogsNode.getChildren().size());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 0);
    ASSERT_STREQ("dialogNodeA", currentNode->getName().c_str());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 1);
    ASSERT_STREQ("dialogNodeB", currentNode->getName().c_str());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 2);
    ASSERT_STREQ("dialogNodeC", currentNode->getName().c_str());
  }

  TEST_F(XMLNodeTest, addChildToEnd)
  {
    ls_std::XMLNode dialogsNode {"dialogs"};
    std::shared_ptr<ls_std::XMLNode> currentNode {};

    ls_std::XMLNode dialogNodeA {"dialogNodeA"};
    ls_std::XMLNode dialogNodeB {"dialogNodeB"};
    ls_std::XMLNode dialogNodeC {"dialogNodeC"};

    ASSERT_TRUE(dialogsNode.getChildren().empty());
    ASSERT_EQ(0, dialogsNode.getChildren().size());

    // adding C

    ASSERT_TRUE(dialogsNode.addChildToEnd(std::make_shared<ls_std::XMLNode>(dialogNodeC)));
    ASSERT_TRUE(!dialogsNode.getChildren().empty());
    ASSERT_EQ(1, dialogsNode.getChildren().size());

    currentNode = *std::next(dialogsNode.getChildren().begin(), 0);
    ASSERT_STREQ("dialogNodeC", currentNode->getName().c_str());

    // adding B

    ASSERT_TRUE(dialogsNode.addChildToEnd(std::make_shared<ls_std::XMLNode>(dialogNodeB)));
    ASSERT_EQ(2, dialogsNode.getChildren().size());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 0);
    ASSERT_STREQ("dialogNodeC", currentNode->getName().c_str());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 1);
    ASSERT_STREQ("dialogNodeB", currentNode->getName().c_str());

    // adding A

    ASSERT_TRUE(dialogsNode.addChildToEnd(std::make_shared<ls_std::XMLNode>(dialogNodeA)));
    ASSERT_EQ(3, dialogsNode.getChildren().size());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 0);
    ASSERT_STREQ("dialogNodeC", currentNode->getName().c_str());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 1);
    ASSERT_STREQ("dialogNodeB", currentNode->getName().c_str());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 2);
    ASSERT_STREQ("dialogNodeA", currentNode->getName().c_str());
  }

  TEST_F(XMLNodeTest, clearValue)
  {
    ls_std::XMLNode dialogNode {"dialog"};
    dialogNode.setValue("Something");
    ASSERT_STREQ("Something", dialogNode.getValue().c_str());

    dialogNode.clearValue();
    ASSERT_TRUE(dialogNode.getValue().empty());
    ASSERT_STREQ("", dialogNode.getValue().c_str());
  }

  TEST_F(XMLNodeTest, getAttributes)
  {
    ls_std::XMLNode dialogNode {"dialog"};
    ASSERT_TRUE(dialogNode.getAttributes().empty());
  }

  TEST_F(XMLNodeTest, getChildren)
  {
    ls_std::XMLNode dialogNode {"dialog"};
    ASSERT_TRUE(dialogNode.getChildren().empty());
  }

  TEST_F(XMLNodeTest, getChildrenV2)
  {
    ls_std::XMLNode dialogsNode {"dialogs"};
    ls_std::XMLNode dialogNode {"dialog"};
    ls_std::XMLNode otherNode {"something"};

    // preparation

    ASSERT_TRUE(dialogsNode.addChildToEnd(std::make_shared<ls_std::XMLNode>(dialogNode)));
    ASSERT_TRUE(dialogsNode.addChildToEnd(std::make_shared<ls_std::XMLNode>(otherNode)));
    ASSERT_TRUE(dialogsNode.addChildToEnd(std::make_shared<ls_std::XMLNode>(otherNode)));
    ASSERT_TRUE(dialogsNode.addChildToEnd(std::make_shared<ls_std::XMLNode>(dialogNode)));
    ASSERT_TRUE(dialogsNode.addChildToEnd(std::make_shared<ls_std::XMLNode>(otherNode)));

    // check

    ASSERT_TRUE(!dialogsNode.getChildren().empty());
    ASSERT_EQ(5, dialogsNode.getChildren().size());
    ASSERT_EQ(2, dialogsNode.getChildren("dialog").size());
    ASSERT_EQ(3, dialogsNode.getChildren("something").size());
  }

  TEST_F(XMLNodeTest, getName)
  {
    ls_std::XMLNode dialogNode {"dialog"};
    ASSERT_STREQ("dialog", dialogNode.getName().c_str());
  }

  TEST_F(XMLNodeTest, getValue)
  {
    ls_std::XMLNode dialogNode {"dialog"};
    ASSERT_TRUE(dialogNode.getValue().empty());
  }

  TEST_F(XMLNodeTest, hasAttribute)
  {
    ls_std::XMLNode dialogNode {"dialogNode"};
    dialogNode.addAttributeToEnd(std::make_shared<ls_std::XMLAttribute>("id"));
    dialogNode.addAttributeToEnd(std::make_shared<ls_std::XMLAttribute>("events"));
    dialogNode.addAttributeToEnd(std::make_shared<ls_std::XMLAttribute>("assets"));

    ASSERT_TRUE(dialogNode.hasAttribute("id"));
    ASSERT_TRUE(dialogNode.hasAttribute("events"));
    ASSERT_TRUE(dialogNode.hasAttribute("assets"));
  }

  TEST_F(XMLNodeTest, hasAttributeNegative)
  {
    ls_std::XMLNode dialogNode {"dialogNode"};
    dialogNode.addAttributeToEnd(std::make_shared<ls_std::XMLAttribute>("id"));
    dialogNode.addAttributeToEnd(std::make_shared<ls_std::XMLAttribute>("events"));
    dialogNode.addAttributeToEnd(std::make_shared<ls_std::XMLAttribute>("assets"));

    ASSERT_FALSE(dialogNode.hasAttribute("fields"));
  }

  TEST_F(XMLNodeTest, hasChild)
  {
    ls_std::XMLNode dialogsNode {"dialogsNode"};
    dialogsNode.addChildToEnd(std::make_shared<ls_std::XMLNode>("dialogA"));
    dialogsNode.addChildToEnd(std::make_shared<ls_std::XMLNode>("dialogB"));
    dialogsNode.addChildToEnd(std::make_shared<ls_std::XMLNode>("dialogC"));

    ASSERT_TRUE(dialogsNode.hasChild("dialogA"));
    ASSERT_TRUE(dialogsNode.hasChild("dialogB"));
    ASSERT_TRUE(dialogsNode.hasChild("dialogC"));
  }

  TEST_F(XMLNodeTest, hasChildNegative)
  {
    ls_std::XMLNode dialogsNode {"dialogsNode"};
    dialogsNode.addChildToEnd(std::make_shared<ls_std::XMLNode>("dialogA"));
    dialogsNode.addChildToEnd(std::make_shared<ls_std::XMLNode>("dialogB"));
    dialogsNode.addChildToEnd(std::make_shared<ls_std::XMLNode>("dialogC"));

    ASSERT_FALSE(dialogsNode.hasChild("dialogD"));
    ASSERT_FALSE(dialogsNode.hasChild("dialogE"));
    ASSERT_FALSE(dialogsNode.hasChild("dialogF"));
  }

  TEST_F(XMLNodeTest, hasChildV2)
  {
    ls_std::XMLNode dialogsNode {"dialogsNode"};
    std::shared_ptr<ls_std::XMLNode> searchNode = std::make_shared<ls_std::XMLNode>("dialogB");
    dialogsNode.addChildToEnd(std::make_shared<ls_std::XMLNode>("dialogA"));
    dialogsNode.addChildToEnd(searchNode);
    dialogsNode.addChildToEnd(std::make_shared<ls_std::XMLNode>("dialogC"));

    ASSERT_TRUE(dialogsNode.hasChild(searchNode));
  }

  TEST_F(XMLNodeTest, hasChildV2Negative)
  {
    ls_std::XMLNode dialogsNode {"dialogsNode"};
    std::shared_ptr<ls_std::XMLNode> searchNode = std::make_shared<ls_std::XMLNode>("dialogB");
    dialogsNode.addChildToEnd(std::make_shared<ls_std::XMLNode>("dialogA"));
    dialogsNode.addChildToEnd(std::make_shared<ls_std::XMLNode>("dialogC"));

    ASSERT_FALSE(dialogsNode.hasChild(searchNode));
  }

  TEST_F(XMLNodeTest, removeFirstAttribute)
  {
    ls_std::XMLNode dialogNode {"dialog"};
    std::shared_ptr<ls_std::XMLAttribute> currentAttribute {};
    dialogNode.addAttributeToEnd(std::make_shared<ls_std::XMLAttribute>("id"));
    dialogNode.addAttributeToEnd(std::make_shared<ls_std::XMLAttribute>("events"));
    dialogNode.addAttributeToEnd(std::make_shared<ls_std::XMLAttribute>("assets"));

    ASSERT_TRUE(!dialogNode.getAttributes().empty());
    ASSERT_EQ(3, dialogNode.getAttributes().size());

    dialogNode.removeFirstAttribute();
    ASSERT_EQ(2, dialogNode.getAttributes().size());

    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 0);
    ASSERT_STREQ("events", currentAttribute->getName().c_str());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 1);
    ASSERT_STREQ("assets", currentAttribute->getName().c_str());
  }

  TEST_F(XMLNodeTest, removeFirstAttributeNegative)
  {
    ls_std::XMLNode dialogNode {"dialog"};
    ASSERT_TRUE(dialogNode.getAttributes().empty());

    dialogNode.removeFirstAttribute();
    ASSERT_TRUE(dialogNode.getAttributes().empty());
  }

  TEST_F(XMLNodeTest, removeLastAttribute)
  {
    ls_std::XMLNode dialogNode {"dialog"};
    std::shared_ptr<ls_std::XMLAttribute> currentAttribute {};
    dialogNode.addAttributeToEnd(std::make_shared<ls_std::XMLAttribute>("id"));
    dialogNode.addAttributeToEnd(std::make_shared<ls_std::XMLAttribute>("events"));
    dialogNode.addAttributeToEnd(std::make_shared<ls_std::XMLAttribute>("assets"));

    ASSERT_TRUE(!dialogNode.getAttributes().empty());
    ASSERT_EQ(3, dialogNode.getAttributes().size());

    dialogNode.removeLastAttribute();
    ASSERT_EQ(2, dialogNode.getAttributes().size());

    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 0);
    ASSERT_STREQ("id", currentAttribute->getName().c_str());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 1);
    ASSERT_STREQ("events", currentAttribute->getName().c_str());
  }

  TEST_F(XMLNodeTest, removeLastAttributeNegative)
  {
    ls_std::XMLNode dialogNode {"dialog"};
    ASSERT_TRUE(dialogNode.getAttributes().empty());

    dialogNode.removeLastAttribute();
    ASSERT_TRUE(dialogNode.getAttributes().empty());
  }

  TEST_F(XMLNodeTest, removeFirstChild)
  {
    ls_std::XMLNode dialogsNode {"dialogs"};
    std::shared_ptr<ls_std::XMLNode> currentNode {};

    // preparation

    ASSERT_TRUE(dialogsNode.addChildToEnd(std::make_shared<ls_std::XMLNode>("dialogA")));
    ASSERT_TRUE(dialogsNode.addChildToEnd(std::make_shared<ls_std::XMLNode>("dialogB")));
    ASSERT_TRUE(dialogsNode.addChildToEnd(std::make_shared<ls_std::XMLNode>("dialogC")));
    ASSERT_TRUE(dialogsNode.addChildToEnd(std::make_shared<ls_std::XMLNode>("additionalInfo")));
    ASSERT_TRUE(dialogsNode.addChildToEnd(std::make_shared<ls_std::XMLNode>("event")));

    ASSERT_EQ(5, dialogsNode.getChildren().size());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 0);
    ASSERT_STREQ("dialogA", currentNode->getName().c_str());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 1);
    ASSERT_STREQ("dialogB", currentNode->getName().c_str());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 2);
    ASSERT_STREQ("dialogC", currentNode->getName().c_str());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 3);
    ASSERT_STREQ("additionalInfo", currentNode->getName().c_str());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 4);
    ASSERT_STREQ("event", currentNode->getName().c_str());

    // check

    dialogsNode.removeFirstChild();
    currentNode = *std::next(dialogsNode.getChildren().begin(), 0);
    ASSERT_STREQ("dialogB", currentNode->getName().c_str());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 1);
    ASSERT_STREQ("dialogC", currentNode->getName().c_str());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 2);
    ASSERT_STREQ("additionalInfo", currentNode->getName().c_str());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 3);
    ASSERT_STREQ("event", currentNode->getName().c_str());
  }

  TEST_F(XMLNodeTest, removeFirstChildNegative)
  {
    ls_std::XMLNode dialogsNode {"dialogs"};
    ASSERT_TRUE(dialogsNode.getChildren().empty());

    dialogsNode.removeFirstChild();
    ASSERT_TRUE(dialogsNode.getChildren().empty());
  }

  TEST_F(XMLNodeTest, removeLastChild)
  {
    ls_std::XMLNode dialogsNode {"dialogs"};
    std::shared_ptr<ls_std::XMLNode> currentNode {};

    // preparation

    ASSERT_TRUE(dialogsNode.addChildToEnd(std::make_shared<ls_std::XMLNode>("dialogA")));
    ASSERT_TRUE(dialogsNode.addChildToEnd(std::make_shared<ls_std::XMLNode>("dialogB")));
    ASSERT_TRUE(dialogsNode.addChildToEnd(std::make_shared<ls_std::XMLNode>("dialogC")));
    ASSERT_TRUE(dialogsNode.addChildToEnd(std::make_shared<ls_std::XMLNode>("additionalInfo")));
    ASSERT_TRUE(dialogsNode.addChildToEnd(std::make_shared<ls_std::XMLNode>("event")));

    ASSERT_EQ(5, dialogsNode.getChildren().size());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 0);
    ASSERT_STREQ("dialogA", currentNode->getName().c_str());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 1);
    ASSERT_STREQ("dialogB", currentNode->getName().c_str());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 2);
    ASSERT_STREQ("dialogC", currentNode->getName().c_str());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 3);
    ASSERT_STREQ("additionalInfo", currentNode->getName().c_str());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 4);
    ASSERT_STREQ("event", currentNode->getName().c_str());

    // check

    dialogsNode.removeLastChild();
    currentNode = *std::next(dialogsNode.getChildren().begin(), 0);
    ASSERT_STREQ("dialogA", currentNode->getName().c_str());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 1);
    ASSERT_STREQ("dialogB", currentNode->getName().c_str());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 2);
    ASSERT_STREQ("dialogC", currentNode->getName().c_str());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 3);
    ASSERT_STREQ("additionalInfo", currentNode->getName().c_str());
  }

  TEST_F(XMLNodeTest, removeLastChildNegative)
  {
    ls_std::XMLNode dialogsNode {"dialogs"};
    ASSERT_TRUE(dialogsNode.getChildren().empty());

    dialogsNode.removeLastChild();
    ASSERT_TRUE(dialogsNode.getChildren().empty());
  }

  TEST_F(XMLNodeTest, setName)
  {
    ls_std::XMLNode dialogNode {"dialog"};
    dialogNode.setName("dialog2");

    ASSERT_STREQ("dialog2", dialogNode.getName().c_str());
  }

  TEST_F(XMLNodeTest, setValue)
  {
    ls_std::XMLNode dialogNode {"dialog"};
    dialogNode.setValue("Something written");

    ASSERT_STREQ("Something written", dialogNode.getValue().c_str());
  }

  TEST_F(XMLNodeTest, toXML)
  {
    auto root = ls_std_test::TestDataFactory::createXMLContent();
    std::string xmlContent = root->toXML();
    std::string expectedXMLContent = R"("<dialog name="dungeon_001"><dialogUnit id="001"><text>Hello!</text></dialogUnit><dialogUnit id="002"><text>Hello again!</text></dialogUnit></dialog>")";

    ASSERT_TRUE(!xmlContent.empty());
  }
}
