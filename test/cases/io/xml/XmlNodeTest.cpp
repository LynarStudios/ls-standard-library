/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-25
 * Changed:         2021-05-02
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>
#include <TestDataFactory.hpp>

namespace
{
  class XmlNodeTest : public ::testing::Test
  {
    protected:

      XmlNodeTest() = default;
      ~XmlNodeTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(XmlNodeTest, addAttributeAfter)
  {
    ls_std::XmlNode dialogNode{"dialog"};
    std::shared_ptr<ls_std::XmlAttribute> currentAttribute{};
    dialogNode.addAttributeToEnd(std::make_shared<ls_std::XmlAttribute>("events"));
    dialogNode.addAttributeToEnd(std::make_shared<ls_std::XmlAttribute>("assets"));

    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 0);
    ASSERT_STREQ("events", currentAttribute->getName().c_str());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 1);
    ASSERT_STREQ("assets", currentAttribute->getName().c_str());

    // add id after events

    ASSERT_TRUE(dialogNode.addAttributeAfter(std::make_shared<ls_std::XmlAttribute>("id"), "events"));
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 0);
    ASSERT_STREQ("events", currentAttribute->getName().c_str());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 1);
    ASSERT_STREQ("id", currentAttribute->getName().c_str());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 2);
    ASSERT_STREQ("assets", currentAttribute->getName().c_str());

    // add tasks after assets

    ASSERT_TRUE(dialogNode.addAttributeAfter(std::make_shared<ls_std::XmlAttribute>("tasks"), "assets"));
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 0);
    ASSERT_STREQ("events", currentAttribute->getName().c_str());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 1);
    ASSERT_STREQ("id", currentAttribute->getName().c_str());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 2);
    ASSERT_STREQ("assets", currentAttribute->getName().c_str());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 3);
    ASSERT_STREQ("tasks", currentAttribute->getName().c_str());
  }

  TEST_F(XmlNodeTest, addAttributeAfterNegative)
  {
    ls_std::XmlNode dialogNode{"dialog"};
    dialogNode.addAttributeToEnd(std::make_shared<ls_std::XmlAttribute>("events"));

    ASSERT_FALSE(dialogNode.addAttributeAfter(std::make_shared<ls_std::XmlAttribute>("id"), "assets"));
  }

  TEST_F(XmlNodeTest, addAttributeBefore)
  {
    ls_std::XmlNode dialogNode{"dialog"};
    std::shared_ptr<ls_std::XmlAttribute> currentAttribute{};
    dialogNode.addAttributeToEnd(std::make_shared<ls_std::XmlAttribute>("events"));
    dialogNode.addAttributeToEnd(std::make_shared<ls_std::XmlAttribute>("assets"));

    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 0);
    ASSERT_STREQ("events", currentAttribute->getName().c_str());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 1);
    ASSERT_STREQ("assets", currentAttribute->getName().c_str());

    // add id before events

    ASSERT_TRUE(dialogNode.addAttributeBefore(std::make_shared<ls_std::XmlAttribute>("id"), "events"));
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 0);
    ASSERT_STREQ("id", currentAttribute->getName().c_str());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 1);
    ASSERT_STREQ("events", currentAttribute->getName().c_str());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 2);
    ASSERT_STREQ("assets", currentAttribute->getName().c_str());

    // add tasks before assets

    ASSERT_TRUE(dialogNode.addAttributeBefore(std::make_shared<ls_std::XmlAttribute>("tasks"), "assets"));
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 0);
    ASSERT_STREQ("id", currentAttribute->getName().c_str());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 1);
    ASSERT_STREQ("events", currentAttribute->getName().c_str());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 2);
    ASSERT_STREQ("tasks", currentAttribute->getName().c_str());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 3);
    ASSERT_STREQ("assets", currentAttribute->getName().c_str());
  }

  TEST_F(XmlNodeTest, addAttributeBeforeNegative)
  {
    ls_std::XmlNode dialogNode{"dialog"};
    dialogNode.addAttributeToEnd(std::make_shared<ls_std::XmlAttribute>("events"));

    ASSERT_FALSE(dialogNode.addAttributeBefore(std::make_shared<ls_std::XmlAttribute>("id"), "assets"));
  }

  TEST_F(XmlNodeTest, addAttributeToBeginning)
  {
    ls_std::XmlNode dialogNode{"dialog"};
    std::shared_ptr<ls_std::XmlAttribute> currentAttribute{};

    dialogNode.addAttributeToBeginning(std::make_shared<ls_std::XmlAttribute>("id"));
    ASSERT_EQ(1, dialogNode.getAttributes().size());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 0);
    ASSERT_STREQ("id", currentAttribute->getName().c_str());

    dialogNode.addAttributeToBeginning(std::make_shared<ls_std::XmlAttribute>("assets"));
    ASSERT_EQ(2, dialogNode.getAttributes().size());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 0);
    ASSERT_STREQ("assets", currentAttribute->getName().c_str());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 1);
    ASSERT_STREQ("id", currentAttribute->getName().c_str());

    dialogNode.addAttributeToBeginning(std::make_shared<ls_std::XmlAttribute>("events"));
    ASSERT_EQ(3, dialogNode.getAttributes().size());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 0);
    ASSERT_STREQ("events", currentAttribute->getName().c_str());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 1);
    ASSERT_STREQ("assets", currentAttribute->getName().c_str());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 2);
    ASSERT_STREQ("id", currentAttribute->getName().c_str());
  }

  TEST_F(XmlNodeTest, addAttributeToEnd)
  {
    ls_std::XmlNode dialogNode{"dialog"};
    std::shared_ptr<ls_std::XmlAttribute> currentAttribute{};

    dialogNode.addAttributeToEnd(std::make_shared<ls_std::XmlAttribute>("id"));
    ASSERT_EQ(1, dialogNode.getAttributes().size());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 0);
    ASSERT_STREQ("id", currentAttribute->getName().c_str());

    dialogNode.addAttributeToEnd(std::make_shared<ls_std::XmlAttribute>("assets"));
    ASSERT_EQ(2, dialogNode.getAttributes().size());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 0);
    ASSERT_STREQ("id", currentAttribute->getName().c_str());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 1);
    ASSERT_STREQ("assets", currentAttribute->getName().c_str());

    dialogNode.addAttributeToEnd(std::make_shared<ls_std::XmlAttribute>("events"));
    ASSERT_EQ(3, dialogNode.getAttributes().size());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 0);
    ASSERT_STREQ("id", currentAttribute->getName().c_str());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 1);
    ASSERT_STREQ("assets", currentAttribute->getName().c_str());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 2);
    ASSERT_STREQ("events", currentAttribute->getName().c_str());
  }

  TEST_F(XmlNodeTest, addChildAfter)
  {
    ls_std::XmlNode dialogsNode{"dialogs"};
    std::shared_ptr<ls_std::XmlNode> currentNode{};
    std::shared_ptr<ls_std::XmlNode> dialogNodeA = std::make_shared<ls_std::XmlNode>("dialogNodeA");
    std::shared_ptr<ls_std::XmlNode> dialogNodeB = std::make_shared<ls_std::XmlNode>("dialogNodeB");
    std::shared_ptr<ls_std::XmlNode> dialogNodeC = std::make_shared<ls_std::XmlNode>("dialogNodeC");
    std::shared_ptr<ls_std::XmlNode> dialogNodeD = std::make_shared<ls_std::XmlNode>("dialogNodeD");

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

  TEST_F(XmlNodeTest, addChildAfterNegative)
  {
    ls_std::XmlNode dialogsNode{"dialogs"};
    std::shared_ptr<ls_std::XmlNode> dialogNodeA = std::make_shared<ls_std::XmlNode>("dialogNodeA");
    std::shared_ptr<ls_std::XmlNode> dialogNodeB = std::make_shared<ls_std::XmlNode>("dialogNodeB");

    ASSERT_FALSE(dialogsNode.addChildAfter(dialogNodeA, dialogNodeB));
  }

  TEST_F(XmlNodeTest, addChildBefore)
  {
    ls_std::XmlNode dialogsNode{"dialogs"};
    std::shared_ptr<ls_std::XmlNode> currentNode{};
    std::shared_ptr<ls_std::XmlNode> dialogNodeA = std::make_shared<ls_std::XmlNode>("dialogNodeA");
    std::shared_ptr<ls_std::XmlNode> dialogNodeB = std::make_shared<ls_std::XmlNode>("dialogNodeB");
    std::shared_ptr<ls_std::XmlNode> dialogNodeC = std::make_shared<ls_std::XmlNode>("dialogNodeC");
    std::shared_ptr<ls_std::XmlNode> dialogNodeD = std::make_shared<ls_std::XmlNode>("dialogNodeD");

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

  TEST_F(XmlNodeTest, addChildToBeginning)
  {
    ls_std::XmlNode dialogsNode{"dialogs"};
    std::shared_ptr<ls_std::XmlNode> currentNode{};

    ls_std::XmlNode dialogNodeA{"dialogNodeA"};
    ls_std::XmlNode dialogNodeB{"dialogNodeB"};
    ls_std::XmlNode dialogNodeC{"dialogNodeC"};

    ASSERT_TRUE(dialogsNode.getChildren().empty());
    ASSERT_EQ(0, dialogsNode.getChildren().size());

    // adding C

    ASSERT_TRUE(dialogsNode.addChildToBeginning(std::make_shared<ls_std::XmlNode>(dialogNodeC)));
    ASSERT_TRUE(!dialogsNode.getChildren().empty());
    ASSERT_EQ(1, dialogsNode.getChildren().size());

    currentNode = *std::next(dialogsNode.getChildren().begin(), 0);
    ASSERT_STREQ("dialogNodeC", currentNode->getName().c_str());

    // adding B

    ASSERT_TRUE(dialogsNode.addChildToBeginning(std::make_shared<ls_std::XmlNode>(dialogNodeB)));
    ASSERT_EQ(2, dialogsNode.getChildren().size());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 0);
    ASSERT_STREQ("dialogNodeB", currentNode->getName().c_str());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 1);
    ASSERT_STREQ("dialogNodeC", currentNode->getName().c_str());

    // adding A

    ASSERT_TRUE(dialogsNode.addChildToBeginning(std::make_shared<ls_std::XmlNode>(dialogNodeA)));
    ASSERT_EQ(3, dialogsNode.getChildren().size());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 0);
    ASSERT_STREQ("dialogNodeA", currentNode->getName().c_str());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 1);
    ASSERT_STREQ("dialogNodeB", currentNode->getName().c_str());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 2);
    ASSERT_STREQ("dialogNodeC", currentNode->getName().c_str());
  }

  TEST_F(XmlNodeTest, addChildToEnd)
  {
    ls_std::XmlNode dialogsNode{"dialogs"};
    std::shared_ptr<ls_std::XmlNode> currentNode{};

    ls_std::XmlNode dialogNodeA{"dialogNodeA"};
    ls_std::XmlNode dialogNodeB{"dialogNodeB"};
    ls_std::XmlNode dialogNodeC{"dialogNodeC"};

    ASSERT_TRUE(dialogsNode.getChildren().empty());
    ASSERT_EQ(0, dialogsNode.getChildren().size());

    // adding C

    ASSERT_TRUE(dialogsNode.addChildToEnd(std::make_shared<ls_std::XmlNode>(dialogNodeC)));
    ASSERT_TRUE(!dialogsNode.getChildren().empty());
    ASSERT_EQ(1, dialogsNode.getChildren().size());

    currentNode = *std::next(dialogsNode.getChildren().begin(), 0);
    ASSERT_STREQ("dialogNodeC", currentNode->getName().c_str());

    // adding B

    ASSERT_TRUE(dialogsNode.addChildToEnd(std::make_shared<ls_std::XmlNode>(dialogNodeB)));
    ASSERT_EQ(2, dialogsNode.getChildren().size());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 0);
    ASSERT_STREQ("dialogNodeC", currentNode->getName().c_str());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 1);
    ASSERT_STREQ("dialogNodeB", currentNode->getName().c_str());

    // adding A

    ASSERT_TRUE(dialogsNode.addChildToEnd(std::make_shared<ls_std::XmlNode>(dialogNodeA)));
    ASSERT_EQ(3, dialogsNode.getChildren().size());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 0);
    ASSERT_STREQ("dialogNodeC", currentNode->getName().c_str());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 1);
    ASSERT_STREQ("dialogNodeB", currentNode->getName().c_str());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 2);
    ASSERT_STREQ("dialogNodeA", currentNode->getName().c_str());
  }

  TEST_F(XmlNodeTest, clearValue)
  {
    ls_std::XmlNode dialogNode{"dialog"};
    dialogNode.setValue("Something");
    ASSERT_STREQ("Something", dialogNode.getValue().c_str());

    dialogNode.clearValue();
    ASSERT_TRUE(dialogNode.getValue().empty());
    ASSERT_STREQ("", dialogNode.getValue().c_str());
  }

  TEST_F(XmlNodeTest, getAttributes)
  {
    ls_std::XmlNode dialogNode{"dialog"};
    ASSERT_TRUE(dialogNode.getAttributes().empty());
  }

  TEST_F(XmlNodeTest, getChildren)
  {
    ls_std::XmlNode dialogNode{"dialog"};
    ASSERT_TRUE(dialogNode.getChildren().empty());
  }

  TEST_F(XmlNodeTest, getChildrenV2)
  {
    ls_std::XmlNode dialogsNode{"dialogs"};
    ls_std::XmlNode dialogNode{"dialog"};
    ls_std::XmlNode otherNode{"something"};

    // preparation

    ASSERT_TRUE(dialogsNode.addChildToEnd(std::make_shared<ls_std::XmlNode>(dialogNode)));
    ASSERT_TRUE(dialogsNode.addChildToEnd(std::make_shared<ls_std::XmlNode>(otherNode)));
    ASSERT_TRUE(dialogsNode.addChildToEnd(std::make_shared<ls_std::XmlNode>(otherNode)));
    ASSERT_TRUE(dialogsNode.addChildToEnd(std::make_shared<ls_std::XmlNode>(dialogNode)));
    ASSERT_TRUE(dialogsNode.addChildToEnd(std::make_shared<ls_std::XmlNode>(otherNode)));

    // check

    ASSERT_TRUE(!dialogsNode.getChildren().empty());
    ASSERT_EQ(5, dialogsNode.getChildren().size());
    ASSERT_EQ(2, dialogsNode.getChildren("dialog").size());
    ASSERT_EQ(3, dialogsNode.getChildren("something").size());
  }

  TEST_F(XmlNodeTest, getName)
  {
    ls_std::XmlNode dialogNode{"dialog"};
    ASSERT_STREQ("dialog", dialogNode.getName().c_str());
  }

  TEST_F(XmlNodeTest, getValue)
  {
    ls_std::XmlNode dialogNode{"dialog"};
    ASSERT_TRUE(dialogNode.getValue().empty());
  }

  TEST_F(XmlNodeTest, hasAttribute)
  {
    ls_std::XmlNode dialogNode{"dialogNode"};
    dialogNode.addAttributeToEnd(std::make_shared<ls_std::XmlAttribute>("id"));
    dialogNode.addAttributeToEnd(std::make_shared<ls_std::XmlAttribute>("events"));
    dialogNode.addAttributeToEnd(std::make_shared<ls_std::XmlAttribute>("assets"));

    ASSERT_TRUE(dialogNode.hasAttribute("id"));
    ASSERT_TRUE(dialogNode.hasAttribute("events"));
    ASSERT_TRUE(dialogNode.hasAttribute("assets"));
  }

  TEST_F(XmlNodeTest, hasAttributeNegative)
  {
    ls_std::XmlNode dialogNode{"dialogNode"};
    dialogNode.addAttributeToEnd(std::make_shared<ls_std::XmlAttribute>("id"));
    dialogNode.addAttributeToEnd(std::make_shared<ls_std::XmlAttribute>("events"));
    dialogNode.addAttributeToEnd(std::make_shared<ls_std::XmlAttribute>("assets"));

    ASSERT_FALSE(dialogNode.hasAttribute("fields"));
  }

  TEST_F(XmlNodeTest, hasChild)
  {
    ls_std::XmlNode dialogsNode{"dialogsNode"};
    dialogsNode.addChildToEnd(std::make_shared<ls_std::XmlNode>("dialogA"));
    dialogsNode.addChildToEnd(std::make_shared<ls_std::XmlNode>("dialogB"));
    dialogsNode.addChildToEnd(std::make_shared<ls_std::XmlNode>("dialogC"));

    ASSERT_TRUE(dialogsNode.hasChild("dialogA"));
    ASSERT_TRUE(dialogsNode.hasChild("dialogB"));
    ASSERT_TRUE(dialogsNode.hasChild("dialogC"));
  }

  TEST_F(XmlNodeTest, hasChildNegative)
  {
    ls_std::XmlNode dialogsNode{"dialogsNode"};
    dialogsNode.addChildToEnd(std::make_shared<ls_std::XmlNode>("dialogA"));
    dialogsNode.addChildToEnd(std::make_shared<ls_std::XmlNode>("dialogB"));
    dialogsNode.addChildToEnd(std::make_shared<ls_std::XmlNode>("dialogC"));

    ASSERT_FALSE(dialogsNode.hasChild("dialogD"));
    ASSERT_FALSE(dialogsNode.hasChild("dialogE"));
    ASSERT_FALSE(dialogsNode.hasChild("dialogF"));
  }

  TEST_F(XmlNodeTest, hasChildV2)
  {
    ls_std::XmlNode dialogsNode{"dialogsNode"};
    std::shared_ptr<ls_std::XmlNode> searchNode = std::make_shared<ls_std::XmlNode>("dialogB");
    dialogsNode.addChildToEnd(std::make_shared<ls_std::XmlNode>("dialogA"));
    dialogsNode.addChildToEnd(searchNode);
    dialogsNode.addChildToEnd(std::make_shared<ls_std::XmlNode>("dialogC"));

    ASSERT_TRUE(dialogsNode.hasChild(searchNode));
  }

  TEST_F(XmlNodeTest, hasChildV2Negative)
  {
    ls_std::XmlNode dialogsNode{"dialogsNode"};
    std::shared_ptr<ls_std::XmlNode> searchNode = std::make_shared<ls_std::XmlNode>("dialogB");
    dialogsNode.addChildToEnd(std::make_shared<ls_std::XmlNode>("dialogA"));
    dialogsNode.addChildToEnd(std::make_shared<ls_std::XmlNode>("dialogC"));

    ASSERT_FALSE(dialogsNode.hasChild(searchNode));
  }

  TEST_F(XmlNodeTest, removeFirstAttribute)
  {
    ls_std::XmlNode dialogNode{"dialog"};
    std::shared_ptr<ls_std::XmlAttribute> currentAttribute{};
    dialogNode.addAttributeToEnd(std::make_shared<ls_std::XmlAttribute>("id"));
    dialogNode.addAttributeToEnd(std::make_shared<ls_std::XmlAttribute>("events"));
    dialogNode.addAttributeToEnd(std::make_shared<ls_std::XmlAttribute>("assets"));

    ASSERT_TRUE(!dialogNode.getAttributes().empty());
    ASSERT_EQ(3, dialogNode.getAttributes().size());

    dialogNode.removeFirstAttribute();
    ASSERT_EQ(2, dialogNode.getAttributes().size());

    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 0);
    ASSERT_STREQ("events", currentAttribute->getName().c_str());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 1);
    ASSERT_STREQ("assets", currentAttribute->getName().c_str());
  }

  TEST_F(XmlNodeTest, removeFirstAttributeNegative)
  {
    ls_std::XmlNode dialogNode{"dialog"};
    ASSERT_TRUE(dialogNode.getAttributes().empty());

    dialogNode.removeFirstAttribute();
    ASSERT_TRUE(dialogNode.getAttributes().empty());
  }

  TEST_F(XmlNodeTest, removeLastAttribute)
  {
    ls_std::XmlNode dialogNode{"dialog"};
    std::shared_ptr<ls_std::XmlAttribute> currentAttribute{};
    dialogNode.addAttributeToEnd(std::make_shared<ls_std::XmlAttribute>("id"));
    dialogNode.addAttributeToEnd(std::make_shared<ls_std::XmlAttribute>("events"));
    dialogNode.addAttributeToEnd(std::make_shared<ls_std::XmlAttribute>("assets"));

    ASSERT_TRUE(!dialogNode.getAttributes().empty());
    ASSERT_EQ(3, dialogNode.getAttributes().size());

    dialogNode.removeLastAttribute();
    ASSERT_EQ(2, dialogNode.getAttributes().size());

    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 0);
    ASSERT_STREQ("id", currentAttribute->getName().c_str());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 1);
    ASSERT_STREQ("events", currentAttribute->getName().c_str());
  }

  TEST_F(XmlNodeTest, removeLastAttributeNegative)
  {
    ls_std::XmlNode dialogNode{"dialog"};
    ASSERT_TRUE(dialogNode.getAttributes().empty());

    dialogNode.removeLastAttribute();
    ASSERT_TRUE(dialogNode.getAttributes().empty());
  }

  TEST_F(XmlNodeTest, removeFirstChild)
  {
    ls_std::XmlNode dialogsNode{"dialogs"};
    std::shared_ptr<ls_std::XmlNode> currentNode{};

    // preparation

    ASSERT_TRUE(dialogsNode.addChildToEnd(std::make_shared<ls_std::XmlNode>("dialogA")));
    ASSERT_TRUE(dialogsNode.addChildToEnd(std::make_shared<ls_std::XmlNode>("dialogB")));
    ASSERT_TRUE(dialogsNode.addChildToEnd(std::make_shared<ls_std::XmlNode>("dialogC")));
    ASSERT_TRUE(dialogsNode.addChildToEnd(std::make_shared<ls_std::XmlNode>("additionalInfo")));
    ASSERT_TRUE(dialogsNode.addChildToEnd(std::make_shared<ls_std::XmlNode>("event")));

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

  TEST_F(XmlNodeTest, removeFirstChildNegative)
  {
    ls_std::XmlNode dialogsNode{"dialogs"};
    ASSERT_TRUE(dialogsNode.getChildren().empty());

    dialogsNode.removeFirstChild();
    ASSERT_TRUE(dialogsNode.getChildren().empty());
  }

  TEST_F(XmlNodeTest, removeLastChild)
  {
    ls_std::XmlNode dialogsNode{"dialogs"};
    std::shared_ptr<ls_std::XmlNode> currentNode{};

    // preparation

    ASSERT_TRUE(dialogsNode.addChildToEnd(std::make_shared<ls_std::XmlNode>("dialogA")));
    ASSERT_TRUE(dialogsNode.addChildToEnd(std::make_shared<ls_std::XmlNode>("dialogB")));
    ASSERT_TRUE(dialogsNode.addChildToEnd(std::make_shared<ls_std::XmlNode>("dialogC")));
    ASSERT_TRUE(dialogsNode.addChildToEnd(std::make_shared<ls_std::XmlNode>("additionalInfo")));
    ASSERT_TRUE(dialogsNode.addChildToEnd(std::make_shared<ls_std::XmlNode>("event")));

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

  TEST_F(XmlNodeTest, removeLastChildNegative)
  {
    ls_std::XmlNode dialogsNode{"dialogs"};
    ASSERT_TRUE(dialogsNode.getChildren().empty());

    dialogsNode.removeLastChild();
    ASSERT_TRUE(dialogsNode.getChildren().empty());
  }

  TEST_F(XmlNodeTest, setName)
  {
    ls_std::XmlNode dialogNode{"dialog"};
    dialogNode.setName("dialog2");

    ASSERT_STREQ("dialog2", dialogNode.getName().c_str());
  }

  TEST_F(XmlNodeTest, setValue)
  {
    ls_std::XmlNode dialogNode{"dialog"};
    dialogNode.setValue("Something written");

    ASSERT_STREQ("Something written", dialogNode.getValue().c_str());
  }

  TEST_F(XmlNodeTest, toXml)
  {
    auto root = ls_std_test::TestDataFactory::createXmlContent();
    std::string xmlContent = root->toXml();
    std::string expectedXmlString = R"("<dialog name="dungeon_001"><dialogUnit id="001"><text>Hello!</text></dialogUnit><dialogUnit id="002"><text>Hello again!</text></dialogUnit></dialog>")";

    ASSERT_TRUE(!xmlContent.empty());
  }
}
