/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-25
 * Changed:         2023-03-25
 *
 * */

#include <gtest/gtest.h>
#include <ls-std-io-test.hpp>
#include <ls-std/ls-std-core.hpp>
#include <ls-std/ls-std-io.hpp>

using ls::std::core::IllegalArgumentException;
using ls::std::io::XmlAttribute;
using ls::std::io::XmlNode;
using std::make_shared;
using std::shared_ptr;
using std::string;
using test::io::TestDataFactory;
using testing::Test;

namespace
{
  class XmlNodeTest : public Test
  {
    public:

      XmlNodeTest() = default;
      ~XmlNodeTest() override = default;
  };

  TEST_F(XmlNodeTest, addAttributeAfter)
  {
    XmlNode dialogNode{"dialog"};
    shared_ptr<XmlAttribute> currentAttribute{};
    dialogNode.addAttributeToEnd(make_shared<XmlAttribute>("events"));
    dialogNode.addAttributeToEnd(make_shared<XmlAttribute>("assets"));

    currentAttribute = *next(dialogNode.getAttributes().begin(), 0);
    ASSERT_STREQ("events", currentAttribute->getName().c_str());
    currentAttribute = *next(dialogNode.getAttributes().begin(), 1);
    ASSERT_STREQ("assets", currentAttribute->getName().c_str());

    // add id after events

    ASSERT_TRUE(dialogNode.addAttributeAfter(make_shared<XmlAttribute>("id"), "events"));
    currentAttribute = *next(dialogNode.getAttributes().begin(), 0);
    ASSERT_STREQ("events", currentAttribute->getName().c_str());
    currentAttribute = *next(dialogNode.getAttributes().begin(), 1);
    ASSERT_STREQ("id", currentAttribute->getName().c_str());
    currentAttribute = *next(dialogNode.getAttributes().begin(), 2);
    ASSERT_STREQ("assets", currentAttribute->getName().c_str());

    // add tasks after assets

    ASSERT_TRUE(dialogNode.addAttributeAfter(make_shared<XmlAttribute>("tasks"), "assets"));
    currentAttribute = *next(dialogNode.getAttributes().begin(), 0);
    ASSERT_STREQ("events", currentAttribute->getName().c_str());
    currentAttribute = *next(dialogNode.getAttributes().begin(), 1);
    ASSERT_STREQ("id", currentAttribute->getName().c_str());
    currentAttribute = *next(dialogNode.getAttributes().begin(), 2);
    ASSERT_STREQ("assets", currentAttribute->getName().c_str());
    currentAttribute = *next(dialogNode.getAttributes().begin(), 3);
    ASSERT_STREQ("tasks", currentAttribute->getName().c_str());
  }

  TEST_F(XmlNodeTest, addAttributeAfter_name_not_found)
  {
    XmlNode dialogNode{"dialog"};
    ASSERT_FALSE(dialogNode.addAttributeAfter(make_shared<XmlAttribute>("id"), "events"));
  }

  TEST_F(XmlNodeTest, addAttributeAfter_no_reference)
  {
    XmlNode dialogNode{"dialog"};

    EXPECT_THROW(
        {
          try
          {
            dialogNode.addAttributeAfter(nullptr, "assets");
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(XmlNodeTest, addAttributeAfter_empty_name)
  {
    XmlNode dialogNode{"dialog"};

    EXPECT_THROW(
        {
          try
          {
            dialogNode.addAttributeAfter(make_shared<XmlAttribute>("id"), "");
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(XmlNodeTest, addAttributeBefore)
  {
    XmlNode dialogNode{"dialog"};
    shared_ptr<XmlAttribute> currentAttribute{};
    dialogNode.addAttributeToEnd(make_shared<XmlAttribute>("events"));
    dialogNode.addAttributeToEnd(make_shared<XmlAttribute>("assets"));

    currentAttribute = *next(dialogNode.getAttributes().begin(), 0);
    ASSERT_STREQ("events", currentAttribute->getName().c_str());
    currentAttribute = *next(dialogNode.getAttributes().begin(), 1);
    ASSERT_STREQ("assets", currentAttribute->getName().c_str());

    // add id before events

    ASSERT_TRUE(dialogNode.addAttributeBefore(make_shared<XmlAttribute>("id"), "events"));
    currentAttribute = *next(dialogNode.getAttributes().begin(), 0);
    ASSERT_STREQ("id", currentAttribute->getName().c_str());
    currentAttribute = *next(dialogNode.getAttributes().begin(), 1);
    ASSERT_STREQ("events", currentAttribute->getName().c_str());
    currentAttribute = *next(dialogNode.getAttributes().begin(), 2);
    ASSERT_STREQ("assets", currentAttribute->getName().c_str());

    // add tasks before assets

    ASSERT_TRUE(dialogNode.addAttributeBefore(make_shared<XmlAttribute>("tasks"), "assets"));
    currentAttribute = *next(dialogNode.getAttributes().begin(), 0);
    ASSERT_STREQ("id", currentAttribute->getName().c_str());
    currentAttribute = *next(dialogNode.getAttributes().begin(), 1);
    ASSERT_STREQ("events", currentAttribute->getName().c_str());
    currentAttribute = *next(dialogNode.getAttributes().begin(), 2);
    ASSERT_STREQ("tasks", currentAttribute->getName().c_str());
    currentAttribute = *next(dialogNode.getAttributes().begin(), 3);
    ASSERT_STREQ("assets", currentAttribute->getName().c_str());
  }

  TEST_F(XmlNodeTest, addAttributeBefore_name_not_found)
  {
    XmlNode dialogNode{"dialog"};
    ASSERT_FALSE(dialogNode.addAttributeBefore(make_shared<XmlAttribute>("tasks"), "assets"));
  }

  TEST_F(XmlNodeTest, addAttributeBefore_no_reference)
  {
    XmlNode dialogNode{"dialog"};

    EXPECT_THROW(
        {
          try
          {
            dialogNode.addAttributeBefore(nullptr, "assets");
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(XmlNodeTest, addAttributeBefore_empty_name)
  {
    XmlNode dialogNode{"dialog"};

    EXPECT_THROW(
        {
          try
          {
            dialogNode.addAttributeBefore(make_shared<XmlAttribute>("id"), "");
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(XmlNodeTest, addAttributeToBeginning)
  {
    XmlNode dialogNode{"dialog"};
    shared_ptr<XmlAttribute> currentAttribute{};

    dialogNode.addAttributeToBeginning(make_shared<XmlAttribute>("id"));
    ASSERT_EQ(1, dialogNode.getAttributes().size());
    currentAttribute = *next(dialogNode.getAttributes().begin(), 0);
    ASSERT_STREQ("id", currentAttribute->getName().c_str());

    dialogNode.addAttributeToBeginning(make_shared<XmlAttribute>("assets"));
    ASSERT_EQ(2, dialogNode.getAttributes().size());
    currentAttribute = *next(dialogNode.getAttributes().begin(), 0);
    ASSERT_STREQ("assets", currentAttribute->getName().c_str());
    currentAttribute = *next(dialogNode.getAttributes().begin(), 1);
    ASSERT_STREQ("id", currentAttribute->getName().c_str());

    dialogNode.addAttributeToBeginning(make_shared<XmlAttribute>("events"));
    ASSERT_EQ(3, dialogNode.getAttributes().size());
    currentAttribute = *next(dialogNode.getAttributes().begin(), 0);
    ASSERT_STREQ("events", currentAttribute->getName().c_str());
    currentAttribute = *next(dialogNode.getAttributes().begin(), 1);
    ASSERT_STREQ("assets", currentAttribute->getName().c_str());
    currentAttribute = *next(dialogNode.getAttributes().begin(), 2);
    ASSERT_STREQ("id", currentAttribute->getName().c_str());
  }

  TEST_F(XmlNodeTest, addAttributeToBeginning_no_reference)
  {
    XmlNode dialogNode{"dialog"};

    EXPECT_THROW(
        {
          try
          {
            dialogNode.addAttributeToBeginning(nullptr);
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(XmlNodeTest, addAttributeToEnd)
  {
    XmlNode dialogNode{"dialog"};
    shared_ptr<XmlAttribute> currentAttribute{};

    dialogNode.addAttributeToEnd(make_shared<XmlAttribute>("id"));
    ASSERT_EQ(1, dialogNode.getAttributes().size());
    currentAttribute = *next(dialogNode.getAttributes().begin(), 0);
    ASSERT_STREQ("id", currentAttribute->getName().c_str());

    dialogNode.addAttributeToEnd(make_shared<XmlAttribute>("assets"));
    ASSERT_EQ(2, dialogNode.getAttributes().size());
    currentAttribute = *next(dialogNode.getAttributes().begin(), 0);
    ASSERT_STREQ("id", currentAttribute->getName().c_str());
    currentAttribute = *next(dialogNode.getAttributes().begin(), 1);
    ASSERT_STREQ("assets", currentAttribute->getName().c_str());

    dialogNode.addAttributeToEnd(make_shared<XmlAttribute>("events"));
    ASSERT_EQ(3, dialogNode.getAttributes().size());
    currentAttribute = *next(dialogNode.getAttributes().begin(), 0);
    ASSERT_STREQ("id", currentAttribute->getName().c_str());
    currentAttribute = *next(dialogNode.getAttributes().begin(), 1);
    ASSERT_STREQ("assets", currentAttribute->getName().c_str());
    currentAttribute = *next(dialogNode.getAttributes().begin(), 2);
    ASSERT_STREQ("events", currentAttribute->getName().c_str());
  }

  TEST_F(XmlNodeTest, addAttributeToEnd_no_reference)
  {
    XmlNode dialogNode{"dialog"};

    EXPECT_THROW(
        {
          try
          {
            dialogNode.addAttributeToEnd(nullptr);
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(XmlNodeTest, addChildAfter)
  {
    XmlNode dialogsNode{"dialogs"};
    shared_ptr<XmlNode> currentNode{};
    shared_ptr<XmlNode> dialogNodeA = make_shared<XmlNode>("dialogNodeA");
    shared_ptr<XmlNode> dialogNodeB = make_shared<XmlNode>("dialogNodeB");
    shared_ptr<XmlNode> dialogNodeC = make_shared<XmlNode>("dialogNodeC");
    shared_ptr<XmlNode> dialogNodeD = make_shared<XmlNode>("dialogNodeD");

    ASSERT_TRUE(dialogsNode.addChildToEnd(dialogNodeB));
    ASSERT_TRUE(dialogsNode.addChildToEnd(dialogNodeC));
    ASSERT_EQ(2, dialogsNode.getChildren().size());
    currentNode = *next(dialogsNode.getChildren().begin(), 0);
    ASSERT_STREQ("dialogNodeB", currentNode->getName().c_str());
    currentNode = *next(dialogsNode.getChildren().begin(), 1);
    ASSERT_STREQ("dialogNodeC", currentNode->getName().c_str());

    // add A after B

    ASSERT_TRUE(dialogsNode.addChildAfter(dialogNodeA, dialogNodeB));

    currentNode = *next(dialogsNode.getChildren().begin(), 0);
    ASSERT_STREQ("dialogNodeB", currentNode->getName().c_str());
    currentNode = *next(dialogsNode.getChildren().begin(), 1);
    ASSERT_STREQ("dialogNodeA", currentNode->getName().c_str());
    currentNode = *next(dialogsNode.getChildren().begin(), 2);
    ASSERT_STREQ("dialogNodeC", currentNode->getName().c_str());

    // add D after C

    ASSERT_TRUE(dialogsNode.addChildAfter(dialogNodeD, dialogNodeC));

    currentNode = *next(dialogsNode.getChildren().begin(), 0);
    ASSERT_STREQ("dialogNodeB", currentNode->getName().c_str());
    currentNode = *next(dialogsNode.getChildren().begin(), 1);
    ASSERT_STREQ("dialogNodeA", currentNode->getName().c_str());
    currentNode = *next(dialogsNode.getChildren().begin(), 2);
    ASSERT_STREQ("dialogNodeC", currentNode->getName().c_str());
    currentNode = *next(dialogsNode.getChildren().begin(), 3);
    ASSERT_STREQ("dialogNodeD", currentNode->getName().c_str());
  }

  TEST_F(XmlNodeTest, addChildAfter_no_search_node_available)
  {
    XmlNode dialogsNode{"dialogs"};
    shared_ptr<XmlNode> newChild = make_shared<XmlNode>("newChild");
    shared_ptr<XmlNode> searchNode = make_shared<XmlNode>("searchNode");

    ASSERT_FALSE(dialogsNode.addChildAfter(newChild, searchNode));
  }

  TEST_F(XmlNodeTest, addChildAfter_no_child_reference)
  {
    XmlNode dialogNode{"dialog"};

    EXPECT_THROW(
        {
          try
          {
            dialogNode.addChildAfter(nullptr, make_shared<XmlNode>("children"));
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(XmlNodeTest, addChildAfter_no_search_reference)
  {
    XmlNode dialogNode{"dialog"};

    EXPECT_THROW(
        {
          try
          {
            dialogNode.addChildAfter(make_shared<XmlNode>("newChild"), nullptr);
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(XmlNodeTest, addChildBefore)
  {
    XmlNode dialogsNode{"dialogs"};
    shared_ptr<XmlNode> currentNode{};
    shared_ptr<XmlNode> dialogNodeA = make_shared<XmlNode>("dialogNodeA");
    shared_ptr<XmlNode> dialogNodeB = make_shared<XmlNode>("dialogNodeB");
    shared_ptr<XmlNode> dialogNodeC = make_shared<XmlNode>("dialogNodeC");
    shared_ptr<XmlNode> dialogNodeD = make_shared<XmlNode>("dialogNodeD");

    ASSERT_TRUE(dialogsNode.addChildToEnd(dialogNodeB));
    ASSERT_TRUE(dialogsNode.addChildToEnd(dialogNodeC));
    ASSERT_EQ(2, dialogsNode.getChildren().size());
    currentNode = *next(dialogsNode.getChildren().begin(), 0);
    ASSERT_STREQ("dialogNodeB", currentNode->getName().c_str());
    currentNode = *next(dialogsNode.getChildren().begin(), 1);
    ASSERT_STREQ("dialogNodeC", currentNode->getName().c_str());

    // add A before C

    ASSERT_TRUE(dialogsNode.addChildBefore(dialogNodeA, dialogNodeC));

    currentNode = *next(dialogsNode.getChildren().begin(), 0);
    ASSERT_STREQ("dialogNodeB", currentNode->getName().c_str());
    currentNode = *next(dialogsNode.getChildren().begin(), 1);
    ASSERT_STREQ("dialogNodeA", currentNode->getName().c_str());
    currentNode = *next(dialogsNode.getChildren().begin(), 2);
    ASSERT_STREQ("dialogNodeC", currentNode->getName().c_str());

    // add D before B

    ASSERT_TRUE(dialogsNode.addChildBefore(dialogNodeD, dialogNodeB));

    currentNode = *next(dialogsNode.getChildren().begin(), 0);
    ASSERT_STREQ("dialogNodeD", currentNode->getName().c_str());
    currentNode = *next(dialogsNode.getChildren().begin(), 1);
    ASSERT_STREQ("dialogNodeB", currentNode->getName().c_str());
    currentNode = *next(dialogsNode.getChildren().begin(), 2);
    ASSERT_STREQ("dialogNodeA", currentNode->getName().c_str());
    currentNode = *next(dialogsNode.getChildren().begin(), 3);
    ASSERT_STREQ("dialogNodeC", currentNode->getName().c_str());
  }

  TEST_F(XmlNodeTest, addChildBefore_no_search_node_available)
  {
    XmlNode dialogsNode{"dialogs"};
    shared_ptr<XmlNode> newChild = make_shared<XmlNode>("newChild");
    shared_ptr<XmlNode> searchNode = make_shared<XmlNode>("searchNode");

    ASSERT_FALSE(dialogsNode.addChildBefore(newChild, searchNode));
  }

  TEST_F(XmlNodeTest, addChildBefore_no_child_reference)
  {
    XmlNode dialogNode{"dialog"};

    EXPECT_THROW(
        {
          try
          {
            dialogNode.addChildBefore(nullptr, make_shared<XmlNode>("children"));
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(XmlNodeTest, addChildBefore_no_search_reference)
  {
    XmlNode dialogNode{"dialog"};

    EXPECT_THROW(
        {
          try
          {
            dialogNode.addChildBefore(make_shared<XmlNode>("newChild"), nullptr);
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(XmlNodeTest, addChildToBeginning)
  {
    XmlNode dialogsNode{"dialogs"};
    shared_ptr<XmlNode> currentNode{};

    XmlNode dialogNodeA{"dialogNodeA"};
    XmlNode dialogNodeB{"dialogNodeB"};
    XmlNode dialogNodeC{"dialogNodeC"};

    ASSERT_TRUE(dialogsNode.getChildren().empty());
    ASSERT_EQ(0, dialogsNode.getChildren().size());

    // adding C

    ASSERT_TRUE(dialogsNode.addChildToBeginning(make_shared<XmlNode>(dialogNodeC)));
    ASSERT_TRUE(!dialogsNode.getChildren().empty());
    ASSERT_EQ(1, dialogsNode.getChildren().size());

    currentNode = *next(dialogsNode.getChildren().begin(), 0);
    ASSERT_STREQ("dialogNodeC", currentNode->getName().c_str());

    // adding B

    ASSERT_TRUE(dialogsNode.addChildToBeginning(make_shared<XmlNode>(dialogNodeB)));
    ASSERT_EQ(2, dialogsNode.getChildren().size());
    currentNode = *next(dialogsNode.getChildren().begin(), 0);
    ASSERT_STREQ("dialogNodeB", currentNode->getName().c_str());
    currentNode = *next(dialogsNode.getChildren().begin(), 1);
    ASSERT_STREQ("dialogNodeC", currentNode->getName().c_str());

    // adding A

    ASSERT_TRUE(dialogsNode.addChildToBeginning(make_shared<XmlNode>(dialogNodeA)));
    ASSERT_EQ(3, dialogsNode.getChildren().size());
    currentNode = *next(dialogsNode.getChildren().begin(), 0);
    ASSERT_STREQ("dialogNodeA", currentNode->getName().c_str());
    currentNode = *next(dialogsNode.getChildren().begin(), 1);
    ASSERT_STREQ("dialogNodeB", currentNode->getName().c_str());
    currentNode = *next(dialogsNode.getChildren().begin(), 2);
    ASSERT_STREQ("dialogNodeC", currentNode->getName().c_str());
  }

  TEST_F(XmlNodeTest, addChildToBeginning_no_child_reference)
  {
    XmlNode dialogNode{"dialog"};

    EXPECT_THROW(
        {
          try
          {
            dialogNode.addChildToBeginning(nullptr);
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(XmlNodeTest, addChildToEnd)
  {
    XmlNode dialogsNode{"dialogs"};
    shared_ptr<XmlNode> currentNode{};

    XmlNode dialogNodeA{"dialogNodeA"};
    XmlNode dialogNodeB{"dialogNodeB"};
    XmlNode dialogNodeC{"dialogNodeC"};

    ASSERT_TRUE(dialogsNode.getChildren().empty());
    ASSERT_EQ(0, dialogsNode.getChildren().size());

    // adding C

    ASSERT_TRUE(dialogsNode.addChildToEnd(make_shared<XmlNode>(dialogNodeC)));
    ASSERT_TRUE(!dialogsNode.getChildren().empty());
    ASSERT_EQ(1, dialogsNode.getChildren().size());

    currentNode = *next(dialogsNode.getChildren().begin(), 0);
    ASSERT_STREQ("dialogNodeC", currentNode->getName().c_str());

    // adding B

    ASSERT_TRUE(dialogsNode.addChildToEnd(make_shared<XmlNode>(dialogNodeB)));
    ASSERT_EQ(2, dialogsNode.getChildren().size());
    currentNode = *next(dialogsNode.getChildren().begin(), 0);
    ASSERT_STREQ("dialogNodeC", currentNode->getName().c_str());
    currentNode = *next(dialogsNode.getChildren().begin(), 1);
    ASSERT_STREQ("dialogNodeB", currentNode->getName().c_str());

    // adding A

    ASSERT_TRUE(dialogsNode.addChildToEnd(make_shared<XmlNode>(dialogNodeA)));
    ASSERT_EQ(3, dialogsNode.getChildren().size());
    currentNode = *next(dialogsNode.getChildren().begin(), 0);
    ASSERT_STREQ("dialogNodeC", currentNode->getName().c_str());
    currentNode = *next(dialogsNode.getChildren().begin(), 1);
    ASSERT_STREQ("dialogNodeB", currentNode->getName().c_str());
    currentNode = *next(dialogsNode.getChildren().begin(), 2);
    ASSERT_STREQ("dialogNodeA", currentNode->getName().c_str());
  }

  TEST_F(XmlNodeTest, addChildToEnd_no_child_reference)
  {
    XmlNode dialogNode{"dialog"};

    EXPECT_THROW(
        {
          try
          {
            dialogNode.addChildToEnd(nullptr);
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(XmlNodeTest, clearValue)
  {
    XmlNode dialogNode{"dialog"};
    dialogNode.setValue("Something");
    ASSERT_STREQ("Something", dialogNode.getValue().c_str());

    dialogNode.clearValue();
    ASSERT_TRUE(dialogNode.getValue().empty());
    ASSERT_STREQ("", dialogNode.getValue().c_str());
  }

  TEST_F(XmlNodeTest, getAttributes)
  {
    XmlNode dialogNode{"dialog"};
    ASSERT_TRUE(dialogNode.getAttributes().empty());
  }

  TEST_F(XmlNodeTest, getChildren)
  {
    XmlNode dialogNode{"dialog"};
    ASSERT_TRUE(dialogNode.getChildren().empty());
  }

  TEST_F(XmlNodeTest, getChildrenV2)
  {
    XmlNode dialogsNode{"dialogs"};
    XmlNode dialogNode{"dialog"};
    XmlNode otherNode{"something"};

    // preparation

    ASSERT_TRUE(dialogsNode.addChildToEnd(make_shared<XmlNode>(dialogNode)));
    ASSERT_TRUE(dialogsNode.addChildToEnd(make_shared<XmlNode>(otherNode)));
    ASSERT_TRUE(dialogsNode.addChildToEnd(make_shared<XmlNode>(otherNode)));
    ASSERT_TRUE(dialogsNode.addChildToEnd(make_shared<XmlNode>(dialogNode)));
    ASSERT_TRUE(dialogsNode.addChildToEnd(make_shared<XmlNode>(otherNode)));

    // check

    ASSERT_TRUE(!dialogsNode.getChildren().empty());
    ASSERT_EQ(5, dialogsNode.getChildren().size());
    ASSERT_EQ(2, dialogsNode.getChildren("dialog").size());
    ASSERT_EQ(3, dialogsNode.getChildren("something").size());
  }

  TEST_F(XmlNodeTest, getName)
  {
    XmlNode dialogNode{"dialog"};
    ASSERT_STREQ("dialog", dialogNode.getName().c_str());
  }

  TEST_F(XmlNodeTest, getValue)
  {
    XmlNode dialogNode{"dialog"};
    ASSERT_TRUE(dialogNode.getValue().empty());
  }

  TEST_F(XmlNodeTest, hasAttribute)
  {
    XmlNode dialogNode{"dialogNode"};
    dialogNode.addAttributeToEnd(make_shared<XmlAttribute>("id"));
    dialogNode.addAttributeToEnd(make_shared<XmlAttribute>("events"));
    dialogNode.addAttributeToEnd(make_shared<XmlAttribute>("assets"));

    ASSERT_TRUE(dialogNode.hasAttribute("id"));
    ASSERT_TRUE(dialogNode.hasAttribute("events"));
    ASSERT_TRUE(dialogNode.hasAttribute("assets"));
  }

  TEST_F(XmlNodeTest, hasAttribute_attribute_not_available)
  {
    XmlNode dialogNode{"dialogNode"};
    ASSERT_FALSE(dialogNode.hasAttribute("fields"));
  }

  TEST_F(XmlNodeTest, hasAttribute_empty_name)
  {
    XmlNode dialogNode{"dialogNode"};

    EXPECT_THROW(
        {
          try
          {
            bool hasAttribute = dialogNode.hasAttribute("");
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(XmlNodeTest, hasChild)
  {
    XmlNode dialogsNode{"dialogsNode"};
    dialogsNode.addChildToEnd(make_shared<XmlNode>("dialogA"));
    dialogsNode.addChildToEnd(make_shared<XmlNode>("dialogB"));
    dialogsNode.addChildToEnd(make_shared<XmlNode>("dialogC"));

    ASSERT_TRUE(dialogsNode.hasChild("dialogA"));
    ASSERT_TRUE(dialogsNode.hasChild("dialogB"));
    ASSERT_TRUE(dialogsNode.hasChild("dialogC"));
  }

  TEST_F(XmlNodeTest, hasChild_child_not_available)
  {
    XmlNode dialogsNode{"dialogsNode"};
    ASSERT_FALSE(dialogsNode.hasChild("dialogD"));
  }

  TEST_F(XmlNodeTest, hasChild_empty_name)
  {
    XmlNode dialogNode{"dialogNode"};

    EXPECT_THROW(
        {
          try
          {
            bool hasChild = dialogNode.hasChild("");
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(XmlNodeTest, hasChildV2)
  {
    XmlNode dialogsNode{"dialogsNode"};
    shared_ptr<XmlNode> searchNode = make_shared<XmlNode>("dialogB");
    dialogsNode.addChildToEnd(make_shared<XmlNode>("dialogA"));
    dialogsNode.addChildToEnd(searchNode);
    dialogsNode.addChildToEnd(make_shared<XmlNode>("dialogC"));

    ASSERT_TRUE(dialogsNode.hasChild(searchNode));
  }

  TEST_F(XmlNodeTest, hasChildV2_child_not_available)
  {
    XmlNode dialogsNode{"dialogsNode"};
    shared_ptr<XmlNode> searchNode = make_shared<XmlNode>("dialogB");

    ASSERT_FALSE(dialogsNode.hasChild(searchNode));
  }

  TEST_F(XmlNodeTest, hasChildV2_no_child_reference)
  {
    XmlNode dialogNode{"dialog"};
    shared_ptr<XmlNode> searchNode{};

    EXPECT_THROW(
        {
          try
          {
            bool hasChild = dialogNode.hasChild(searchNode);
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(XmlNodeTest, removeFirstAttribute)
  {
    XmlNode dialogNode{"dialog"};
    shared_ptr<XmlAttribute> currentAttribute{};
    dialogNode.addAttributeToEnd(make_shared<XmlAttribute>("id"));
    dialogNode.addAttributeToEnd(make_shared<XmlAttribute>("events"));
    dialogNode.addAttributeToEnd(make_shared<XmlAttribute>("assets"));

    ASSERT_TRUE(!dialogNode.getAttributes().empty());
    ASSERT_EQ(3, dialogNode.getAttributes().size());

    ASSERT_TRUE(dialogNode.removeFirstAttribute());
    ASSERT_EQ(2, dialogNode.getAttributes().size());

    currentAttribute = *next(dialogNode.getAttributes().begin(), 0);
    ASSERT_STREQ("events", currentAttribute->getName().c_str());
    currentAttribute = *next(dialogNode.getAttributes().begin(), 1);
    ASSERT_STREQ("assets", currentAttribute->getName().c_str());
  }

  TEST_F(XmlNodeTest, removeFirstAttribute_no_attributes_available)
  {
    XmlNode dialogNode{"dialog"};
    ASSERT_FALSE(dialogNode.removeFirstAttribute());
  }

  TEST_F(XmlNodeTest, removeLastAttribute)
  {
    XmlNode dialogNode{"dialog"};
    shared_ptr<XmlAttribute> currentAttribute{};
    dialogNode.addAttributeToEnd(make_shared<XmlAttribute>("id"));
    dialogNode.addAttributeToEnd(make_shared<XmlAttribute>("events"));
    dialogNode.addAttributeToEnd(make_shared<XmlAttribute>("assets"));

    ASSERT_TRUE(!dialogNode.getAttributes().empty());
    ASSERT_EQ(3, dialogNode.getAttributes().size());

    ASSERT_TRUE(dialogNode.removeLastAttribute());
    ASSERT_EQ(2, dialogNode.getAttributes().size());

    currentAttribute = *next(dialogNode.getAttributes().begin(), 0);
    ASSERT_STREQ("id", currentAttribute->getName().c_str());
    currentAttribute = *next(dialogNode.getAttributes().begin(), 1);
    ASSERT_STREQ("events", currentAttribute->getName().c_str());
  }

  TEST_F(XmlNodeTest, removeLastAttribute_no_attributes_available)
  {
    XmlNode dialogNode{"dialog"};
    ASSERT_FALSE(dialogNode.removeLastAttribute());
  }

  TEST_F(XmlNodeTest, removeFirstChild)
  {
    XmlNode dialogsNode{"dialogs"};
    shared_ptr<XmlNode> currentNode{};

    // preparation

    ASSERT_TRUE(dialogsNode.addChildToEnd(make_shared<XmlNode>("dialogA")));
    ASSERT_TRUE(dialogsNode.addChildToEnd(make_shared<XmlNode>("dialogB")));
    ASSERT_TRUE(dialogsNode.addChildToEnd(make_shared<XmlNode>("dialogC")));
    ASSERT_TRUE(dialogsNode.addChildToEnd(make_shared<XmlNode>("additionalInfo")));
    ASSERT_TRUE(dialogsNode.addChildToEnd(make_shared<XmlNode>("event")));

    ASSERT_EQ(5, dialogsNode.getChildren().size());
    currentNode = *next(dialogsNode.getChildren().begin(), 0);
    ASSERT_STREQ("dialogA", currentNode->getName().c_str());
    currentNode = *next(dialogsNode.getChildren().begin(), 1);
    ASSERT_STREQ("dialogB", currentNode->getName().c_str());
    currentNode = *next(dialogsNode.getChildren().begin(), 2);
    ASSERT_STREQ("dialogC", currentNode->getName().c_str());
    currentNode = *next(dialogsNode.getChildren().begin(), 3);
    ASSERT_STREQ("additionalInfo", currentNode->getName().c_str());
    currentNode = *next(dialogsNode.getChildren().begin(), 4);
    ASSERT_STREQ("event", currentNode->getName().c_str());

    // check

    ASSERT_TRUE(dialogsNode.removeFirstChild());
    currentNode = *next(dialogsNode.getChildren().begin(), 0);
    ASSERT_STREQ("dialogB", currentNode->getName().c_str());
    currentNode = *next(dialogsNode.getChildren().begin(), 1);
    ASSERT_STREQ("dialogC", currentNode->getName().c_str());
    currentNode = *next(dialogsNode.getChildren().begin(), 2);
    ASSERT_STREQ("additionalInfo", currentNode->getName().c_str());
    currentNode = *next(dialogsNode.getChildren().begin(), 3);
    ASSERT_STREQ("event", currentNode->getName().c_str());
  }

  TEST_F(XmlNodeTest, removeFirstChild_no_children_available)
  {
    XmlNode dialogsNode{"dialogs"};
    ASSERT_FALSE(dialogsNode.removeFirstChild());
  }

  TEST_F(XmlNodeTest, removeLastChild)
  {
    XmlNode dialogsNode{"dialogs"};
    shared_ptr<XmlNode> currentNode{};

    // preparation

    ASSERT_TRUE(dialogsNode.addChildToEnd(make_shared<XmlNode>("dialogA")));
    ASSERT_TRUE(dialogsNode.addChildToEnd(make_shared<XmlNode>("dialogB")));
    ASSERT_TRUE(dialogsNode.addChildToEnd(make_shared<XmlNode>("dialogC")));
    ASSERT_TRUE(dialogsNode.addChildToEnd(make_shared<XmlNode>("additionalInfo")));
    ASSERT_TRUE(dialogsNode.addChildToEnd(make_shared<XmlNode>("event")));

    ASSERT_EQ(5, dialogsNode.getChildren().size());
    currentNode = *next(dialogsNode.getChildren().begin(), 0);
    ASSERT_STREQ("dialogA", currentNode->getName().c_str());
    currentNode = *next(dialogsNode.getChildren().begin(), 1);
    ASSERT_STREQ("dialogB", currentNode->getName().c_str());
    currentNode = *next(dialogsNode.getChildren().begin(), 2);
    ASSERT_STREQ("dialogC", currentNode->getName().c_str());
    currentNode = *next(dialogsNode.getChildren().begin(), 3);
    ASSERT_STREQ("additionalInfo", currentNode->getName().c_str());
    currentNode = *next(dialogsNode.getChildren().begin(), 4);
    ASSERT_STREQ("event", currentNode->getName().c_str());

    // check

    ASSERT_TRUE(dialogsNode.removeLastChild());
    currentNode = *next(dialogsNode.getChildren().begin(), 0);
    ASSERT_STREQ("dialogA", currentNode->getName().c_str());
    currentNode = *next(dialogsNode.getChildren().begin(), 1);
    ASSERT_STREQ("dialogB", currentNode->getName().c_str());
    currentNode = *next(dialogsNode.getChildren().begin(), 2);
    ASSERT_STREQ("dialogC", currentNode->getName().c_str());
    currentNode = *next(dialogsNode.getChildren().begin(), 3);
    ASSERT_STREQ("additionalInfo", currentNode->getName().c_str());
  }

  TEST_F(XmlNodeTest, removeLastChild_no_children_available)
  {
    XmlNode dialogsNode{"dialogs"};
    ASSERT_FALSE(dialogsNode.removeLastChild());
  }

  TEST_F(XmlNodeTest, setName)
  {
    XmlNode dialogNode{"dialog"};
    dialogNode.setName("dialog2");

    ASSERT_STREQ("dialog2", dialogNode.getName().c_str());
  }

  TEST_F(XmlNodeTest, setName_empty_name)
  {
    XmlNode dialogNode{"dialog"};

    EXPECT_THROW(
        {
          try
          {
            dialogNode.setName("");
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(XmlNodeTest, setValue)
  {
    XmlNode dialogNode{"dialog"};
    dialogNode.setValue("Something written");

    ASSERT_STREQ("Something written", dialogNode.getValue().c_str());
  }

  TEST_F(XmlNodeTest, setValue_empty_value)
  {
    XmlNode dialogNode{"dialog"};

    EXPECT_THROW(
        {
          try
          {
            dialogNode.setValue("");
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(XmlNodeTest, toXml)
  {
    auto root = TestDataFactory::createXmlContent();
    string xmlContent = root->toXml();

    ASSERT_TRUE(!xmlContent.empty());
  }

  TEST_F(XmlNodeTest, toXml_no_value)
  {
    shared_ptr<XmlNode> singleLineElement = make_shared<XmlNode>("info");
    shared_ptr<XmlAttribute> attribute = make_shared<XmlAttribute>("id");
    attribute->setValue("important");
    singleLineElement->addAttributeToEnd(attribute);

    string xmlContent{singleLineElement->toXml()};
    string expectedXmlString = R"(<info id="important" />)";

    ASSERT_TRUE(xmlContent.find(expectedXmlString) != string::npos);
  }
}
