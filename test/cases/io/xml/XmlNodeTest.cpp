/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-25
 * Changed:         2022-05-15
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std_core.hpp>
#include <ls_std/ls_std_io.hpp>
#include <ls_std_io_test.hpp>

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
    ls::std::io::XmlNode dialogNode{"dialog"};
    std::shared_ptr<ls::std::io::XmlAttribute> currentAttribute{};
    dialogNode.addAttributeToEnd(std::make_shared<ls::std::io::XmlAttribute>("events"));
    dialogNode.addAttributeToEnd(std::make_shared<ls::std::io::XmlAttribute>("assets"));

    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 0);
    ASSERT_STREQ("events", currentAttribute->getName().c_str());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 1);
    ASSERT_STREQ("assets", currentAttribute->getName().c_str());

    // add id after events

    ASSERT_TRUE(dialogNode.addAttributeAfter(std::make_shared<ls::std::io::XmlAttribute>("id"), "events"));
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 0);
    ASSERT_STREQ("events", currentAttribute->getName().c_str());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 1);
    ASSERT_STREQ("id", currentAttribute->getName().c_str());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 2);
    ASSERT_STREQ("assets", currentAttribute->getName().c_str());

    // add tasks after assets

    ASSERT_TRUE(dialogNode.addAttributeAfter(std::make_shared<ls::std::io::XmlAttribute>("tasks"), "assets"));
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 0);
    ASSERT_STREQ("events", currentAttribute->getName().c_str());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 1);
    ASSERT_STREQ("id", currentAttribute->getName().c_str());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 2);
    ASSERT_STREQ("assets", currentAttribute->getName().c_str());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 3);
    ASSERT_STREQ("tasks", currentAttribute->getName().c_str());
  }

  TEST_F(XmlNodeTest, addAttributeAfter_name_not_found)
  {
    ls::std::io::XmlNode dialogNode{"dialog"};
    ASSERT_FALSE(dialogNode.addAttributeAfter(std::make_shared<ls::std::io::XmlAttribute>("id"), "events"));
  }

  TEST_F(XmlNodeTest, addAttributeAfter_no_reference)
  {
    ls::std::io::XmlNode dialogNode{"dialog"};

    EXPECT_THROW({
                   try
                   {
                     dialogNode.addAttributeAfter(nullptr, "assets");
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }

  TEST_F(XmlNodeTest, addAttributeAfter_empty_name)
  {
    ls::std::io::XmlNode dialogNode{"dialog"};

    EXPECT_THROW({
                   try
                   {
                     dialogNode.addAttributeAfter(std::make_shared<ls::std::io::XmlAttribute>("id"), "");
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }

  TEST_F(XmlNodeTest, addAttributeBefore)
  {
    ls::std::io::XmlNode dialogNode{"dialog"};
    std::shared_ptr<ls::std::io::XmlAttribute> currentAttribute{};
    dialogNode.addAttributeToEnd(std::make_shared<ls::std::io::XmlAttribute>("events"));
    dialogNode.addAttributeToEnd(std::make_shared<ls::std::io::XmlAttribute>("assets"));

    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 0);
    ASSERT_STREQ("events", currentAttribute->getName().c_str());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 1);
    ASSERT_STREQ("assets", currentAttribute->getName().c_str());

    // add id before events

    ASSERT_TRUE(dialogNode.addAttributeBefore(std::make_shared<ls::std::io::XmlAttribute>("id"), "events"));
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 0);
    ASSERT_STREQ("id", currentAttribute->getName().c_str());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 1);
    ASSERT_STREQ("events", currentAttribute->getName().c_str());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 2);
    ASSERT_STREQ("assets", currentAttribute->getName().c_str());

    // add tasks before assets

    ASSERT_TRUE(dialogNode.addAttributeBefore(std::make_shared<ls::std::io::XmlAttribute>("tasks"), "assets"));
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 0);
    ASSERT_STREQ("id", currentAttribute->getName().c_str());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 1);
    ASSERT_STREQ("events", currentAttribute->getName().c_str());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 2);
    ASSERT_STREQ("tasks", currentAttribute->getName().c_str());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 3);
    ASSERT_STREQ("assets", currentAttribute->getName().c_str());
  }

  TEST_F(XmlNodeTest, addAttributeBefore_name_not_found)
  {
    ls::std::io::XmlNode dialogNode{"dialog"};
    ASSERT_FALSE(dialogNode.addAttributeBefore(std::make_shared<ls::std::io::XmlAttribute>("tasks"), "assets"));
  }

  TEST_F(XmlNodeTest, addAttributeBefore_no_reference)
  {
    ls::std::io::XmlNode dialogNode{"dialog"};

    EXPECT_THROW({
                   try
                   {
                     dialogNode.addAttributeBefore(nullptr, "assets");
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }

  TEST_F(XmlNodeTest, addAttributeBefore_empty_name)
  {
    ls::std::io::XmlNode dialogNode{"dialog"};

    EXPECT_THROW({
                   try
                   {
                     dialogNode.addAttributeBefore(std::make_shared<ls::std::io::XmlAttribute>("id"), "");
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }

  TEST_F(XmlNodeTest, addAttributeToBeginning)
  {
    ls::std::io::XmlNode dialogNode{"dialog"};
    std::shared_ptr<ls::std::io::XmlAttribute> currentAttribute{};

    dialogNode.addAttributeToBeginning(std::make_shared<ls::std::io::XmlAttribute>("id"));
    ASSERT_EQ(1, dialogNode.getAttributes().size());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 0);
    ASSERT_STREQ("id", currentAttribute->getName().c_str());

    dialogNode.addAttributeToBeginning(std::make_shared<ls::std::io::XmlAttribute>("assets"));
    ASSERT_EQ(2, dialogNode.getAttributes().size());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 0);
    ASSERT_STREQ("assets", currentAttribute->getName().c_str());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 1);
    ASSERT_STREQ("id", currentAttribute->getName().c_str());

    dialogNode.addAttributeToBeginning(std::make_shared<ls::std::io::XmlAttribute>("events"));
    ASSERT_EQ(3, dialogNode.getAttributes().size());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 0);
    ASSERT_STREQ("events", currentAttribute->getName().c_str());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 1);
    ASSERT_STREQ("assets", currentAttribute->getName().c_str());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 2);
    ASSERT_STREQ("id", currentAttribute->getName().c_str());
  }

  TEST_F(XmlNodeTest, addAttributeToBeginning_no_reference)
  {
    ls::std::io::XmlNode dialogNode{"dialog"};

    EXPECT_THROW({
                   try
                   {
                     dialogNode.addAttributeToBeginning(nullptr);
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }

  TEST_F(XmlNodeTest, addAttributeToEnd)
  {
    ls::std::io::XmlNode dialogNode{"dialog"};
    std::shared_ptr<ls::std::io::XmlAttribute> currentAttribute{};

    dialogNode.addAttributeToEnd(std::make_shared<ls::std::io::XmlAttribute>("id"));
    ASSERT_EQ(1, dialogNode.getAttributes().size());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 0);
    ASSERT_STREQ("id", currentAttribute->getName().c_str());

    dialogNode.addAttributeToEnd(std::make_shared<ls::std::io::XmlAttribute>("assets"));
    ASSERT_EQ(2, dialogNode.getAttributes().size());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 0);
    ASSERT_STREQ("id", currentAttribute->getName().c_str());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 1);
    ASSERT_STREQ("assets", currentAttribute->getName().c_str());

    dialogNode.addAttributeToEnd(std::make_shared<ls::std::io::XmlAttribute>("events"));
    ASSERT_EQ(3, dialogNode.getAttributes().size());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 0);
    ASSERT_STREQ("id", currentAttribute->getName().c_str());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 1);
    ASSERT_STREQ("assets", currentAttribute->getName().c_str());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 2);
    ASSERT_STREQ("events", currentAttribute->getName().c_str());
  }

  TEST_F(XmlNodeTest, addAttributeToEnd_no_reference)
  {
    ls::std::io::XmlNode dialogNode{"dialog"};

    EXPECT_THROW({
                   try
                   {
                     dialogNode.addAttributeToEnd(nullptr);
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }

  TEST_F(XmlNodeTest, addChildAfter)
  {
    ls::std::io::XmlNode dialogsNode{"dialogs"};
    std::shared_ptr<ls::std::io::XmlNode> currentNode{};
    std::shared_ptr<ls::std::io::XmlNode> dialogNodeA = std::make_shared<ls::std::io::XmlNode>("dialogNodeA");
    std::shared_ptr<ls::std::io::XmlNode> dialogNodeB = std::make_shared<ls::std::io::XmlNode>("dialogNodeB");
    std::shared_ptr<ls::std::io::XmlNode> dialogNodeC = std::make_shared<ls::std::io::XmlNode>("dialogNodeC");
    std::shared_ptr<ls::std::io::XmlNode> dialogNodeD = std::make_shared<ls::std::io::XmlNode>("dialogNodeD");

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

  TEST_F(XmlNodeTest, addChildAfter_no_search_node_available)
  {
    ls::std::io::XmlNode dialogsNode{"dialogs"};
    std::shared_ptr<ls::std::io::XmlNode> newChild = std::make_shared<ls::std::io::XmlNode>("newChild");
    std::shared_ptr<ls::std::io::XmlNode> searchNode = std::make_shared<ls::std::io::XmlNode>("searchNode");

    ASSERT_FALSE(dialogsNode.addChildAfter(newChild, searchNode));
  }

  TEST_F(XmlNodeTest, addChildAfter_no_child_reference)
  {
    ls::std::io::XmlNode dialogNode{"dialog"};

    EXPECT_THROW({
                   try
                   {
                     dialogNode.addChildAfter(nullptr, std::make_shared<ls::std::io::XmlNode>("children"));
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }

  TEST_F(XmlNodeTest, addChildAfter_no_search_reference)
  {
    ls::std::io::XmlNode dialogNode{"dialog"};

    EXPECT_THROW({
                   try
                   {
                     dialogNode.addChildAfter(std::make_shared<ls::std::io::XmlNode>("newChild"), nullptr);
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }

  TEST_F(XmlNodeTest, addChildBefore)
  {
    ls::std::io::XmlNode dialogsNode{"dialogs"};
    std::shared_ptr<ls::std::io::XmlNode> currentNode{};
    std::shared_ptr<ls::std::io::XmlNode> dialogNodeA = std::make_shared<ls::std::io::XmlNode>("dialogNodeA");
    std::shared_ptr<ls::std::io::XmlNode> dialogNodeB = std::make_shared<ls::std::io::XmlNode>("dialogNodeB");
    std::shared_ptr<ls::std::io::XmlNode> dialogNodeC = std::make_shared<ls::std::io::XmlNode>("dialogNodeC");
    std::shared_ptr<ls::std::io::XmlNode> dialogNodeD = std::make_shared<ls::std::io::XmlNode>("dialogNodeD");

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

  TEST_F(XmlNodeTest, addChildBefore_no_search_node_available)
  {
    ls::std::io::XmlNode dialogsNode{"dialogs"};
    std::shared_ptr<ls::std::io::XmlNode> newChild = std::make_shared<ls::std::io::XmlNode>("newChild");
    std::shared_ptr<ls::std::io::XmlNode> searchNode = std::make_shared<ls::std::io::XmlNode>("searchNode");

    ASSERT_FALSE(dialogsNode.addChildBefore(newChild, searchNode));
  }

  TEST_F(XmlNodeTest, addChildBefore_no_child_reference)
  {
    ls::std::io::XmlNode dialogNode{"dialog"};

    EXPECT_THROW({
                   try
                   {
                     dialogNode.addChildBefore(nullptr, std::make_shared<ls::std::io::XmlNode>("children"));
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }

  TEST_F(XmlNodeTest, addChildBefore_no_search_reference)
  {
    ls::std::io::XmlNode dialogNode{"dialog"};

    EXPECT_THROW({
                   try
                   {
                     dialogNode.addChildBefore(std::make_shared<ls::std::io::XmlNode>("newChild"), nullptr);
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }

  TEST_F(XmlNodeTest, addChildToBeginning)
  {
    ls::std::io::XmlNode dialogsNode{"dialogs"};
    std::shared_ptr<ls::std::io::XmlNode> currentNode{};

    ls::std::io::XmlNode dialogNodeA{"dialogNodeA"};
    ls::std::io::XmlNode dialogNodeB{"dialogNodeB"};
    ls::std::io::XmlNode dialogNodeC{"dialogNodeC"};

    ASSERT_TRUE(dialogsNode.getChildren().empty());
    ASSERT_EQ(0, dialogsNode.getChildren().size());

    // adding C

    ASSERT_TRUE(dialogsNode.addChildToBeginning(std::make_shared<ls::std::io::XmlNode>(dialogNodeC)));
    ASSERT_TRUE(!dialogsNode.getChildren().empty());
    ASSERT_EQ(1, dialogsNode.getChildren().size());

    currentNode = *std::next(dialogsNode.getChildren().begin(), 0);
    ASSERT_STREQ("dialogNodeC", currentNode->getName().c_str());

    // adding B

    ASSERT_TRUE(dialogsNode.addChildToBeginning(std::make_shared<ls::std::io::XmlNode>(dialogNodeB)));
    ASSERT_EQ(2, dialogsNode.getChildren().size());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 0);
    ASSERT_STREQ("dialogNodeB", currentNode->getName().c_str());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 1);
    ASSERT_STREQ("dialogNodeC", currentNode->getName().c_str());

    // adding A

    ASSERT_TRUE(dialogsNode.addChildToBeginning(std::make_shared<ls::std::io::XmlNode>(dialogNodeA)));
    ASSERT_EQ(3, dialogsNode.getChildren().size());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 0);
    ASSERT_STREQ("dialogNodeA", currentNode->getName().c_str());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 1);
    ASSERT_STREQ("dialogNodeB", currentNode->getName().c_str());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 2);
    ASSERT_STREQ("dialogNodeC", currentNode->getName().c_str());
  }

  TEST_F(XmlNodeTest, addChildToBeginning_no_child_reference)
  {
    ls::std::io::XmlNode dialogNode{"dialog"};

    EXPECT_THROW({
                   try
                   {
                     dialogNode.addChildToBeginning(nullptr);
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }

  TEST_F(XmlNodeTest, addChildToEnd)
  {
    ls::std::io::XmlNode dialogsNode{"dialogs"};
    std::shared_ptr<ls::std::io::XmlNode> currentNode{};

    ls::std::io::XmlNode dialogNodeA{"dialogNodeA"};
    ls::std::io::XmlNode dialogNodeB{"dialogNodeB"};
    ls::std::io::XmlNode dialogNodeC{"dialogNodeC"};

    ASSERT_TRUE(dialogsNode.getChildren().empty());
    ASSERT_EQ(0, dialogsNode.getChildren().size());

    // adding C

    ASSERT_TRUE(dialogsNode.addChildToEnd(std::make_shared<ls::std::io::XmlNode>(dialogNodeC)));
    ASSERT_TRUE(!dialogsNode.getChildren().empty());
    ASSERT_EQ(1, dialogsNode.getChildren().size());

    currentNode = *std::next(dialogsNode.getChildren().begin(), 0);
    ASSERT_STREQ("dialogNodeC", currentNode->getName().c_str());

    // adding B

    ASSERT_TRUE(dialogsNode.addChildToEnd(std::make_shared<ls::std::io::XmlNode>(dialogNodeB)));
    ASSERT_EQ(2, dialogsNode.getChildren().size());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 0);
    ASSERT_STREQ("dialogNodeC", currentNode->getName().c_str());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 1);
    ASSERT_STREQ("dialogNodeB", currentNode->getName().c_str());

    // adding A

    ASSERT_TRUE(dialogsNode.addChildToEnd(std::make_shared<ls::std::io::XmlNode>(dialogNodeA)));
    ASSERT_EQ(3, dialogsNode.getChildren().size());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 0);
    ASSERT_STREQ("dialogNodeC", currentNode->getName().c_str());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 1);
    ASSERT_STREQ("dialogNodeB", currentNode->getName().c_str());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 2);
    ASSERT_STREQ("dialogNodeA", currentNode->getName().c_str());
  }

  TEST_F(XmlNodeTest, addChildToEnd_no_child_reference)
  {
    ls::std::io::XmlNode dialogNode{"dialog"};

    EXPECT_THROW({
                   try
                   {
                     dialogNode.addChildToEnd(nullptr);
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }

  TEST_F(XmlNodeTest, clearValue)
  {
    ls::std::io::XmlNode dialogNode{"dialog"};
    dialogNode.setValue("Something");
    ASSERT_STREQ("Something", dialogNode.getValue().c_str());

    dialogNode.clearValue();
    ASSERT_TRUE(dialogNode.getValue().empty());
    ASSERT_STREQ("", dialogNode.getValue().c_str());
  }

  TEST_F(XmlNodeTest, getAttributes)
  {
    ls::std::io::XmlNode dialogNode{"dialog"};
    ASSERT_TRUE(dialogNode.getAttributes().empty());
  }

  TEST_F(XmlNodeTest, getChildren)
  {
    ls::std::io::XmlNode dialogNode{"dialog"};
    ASSERT_TRUE(dialogNode.getChildren().empty());
  }

  TEST_F(XmlNodeTest, getChildrenV2)
  {
    ls::std::io::XmlNode dialogsNode{"dialogs"};
    ls::std::io::XmlNode dialogNode{"dialog"};
    ls::std::io::XmlNode otherNode{"something"};

    // preparation

    ASSERT_TRUE(dialogsNode.addChildToEnd(std::make_shared<ls::std::io::XmlNode>(dialogNode)));
    ASSERT_TRUE(dialogsNode.addChildToEnd(std::make_shared<ls::std::io::XmlNode>(otherNode)));
    ASSERT_TRUE(dialogsNode.addChildToEnd(std::make_shared<ls::std::io::XmlNode>(otherNode)));
    ASSERT_TRUE(dialogsNode.addChildToEnd(std::make_shared<ls::std::io::XmlNode>(dialogNode)));
    ASSERT_TRUE(dialogsNode.addChildToEnd(std::make_shared<ls::std::io::XmlNode>(otherNode)));

    // check

    ASSERT_TRUE(!dialogsNode.getChildren().empty());
    ASSERT_EQ(5, dialogsNode.getChildren().size());
    ASSERT_EQ(2, dialogsNode.getChildren("dialog").size());
    ASSERT_EQ(3, dialogsNode.getChildren("something").size());
  }

  TEST_F(XmlNodeTest, getName)
  {
    ls::std::io::XmlNode dialogNode{"dialog"};
    ASSERT_STREQ("dialog", dialogNode.getName().c_str());
  }

  TEST_F(XmlNodeTest, getValue)
  {
    ls::std::io::XmlNode dialogNode{"dialog"};
    ASSERT_TRUE(dialogNode.getValue().empty());
  }

  TEST_F(XmlNodeTest, hasAttribute)
  {
    ls::std::io::XmlNode dialogNode{"dialogNode"};
    dialogNode.addAttributeToEnd(std::make_shared<ls::std::io::XmlAttribute>("id"));
    dialogNode.addAttributeToEnd(std::make_shared<ls::std::io::XmlAttribute>("events"));
    dialogNode.addAttributeToEnd(std::make_shared<ls::std::io::XmlAttribute>("assets"));

    ASSERT_TRUE(dialogNode.hasAttribute("id"));
    ASSERT_TRUE(dialogNode.hasAttribute("events"));
    ASSERT_TRUE(dialogNode.hasAttribute("assets"));
  }

  TEST_F(XmlNodeTest, hasAttribute_attribute_not_available)
  {
    ls::std::io::XmlNode dialogNode{"dialogNode"};
    ASSERT_FALSE(dialogNode.hasAttribute("fields"));
  }

  TEST_F(XmlNodeTest, hasAttribute_empty_name)
  {
    ls::std::io::XmlNode dialogNode{"dialogNode"};

    EXPECT_THROW({
                   try
                   {
                     dialogNode.hasAttribute("");
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }

  TEST_F(XmlNodeTest, hasChild)
  {
    ls::std::io::XmlNode dialogsNode{"dialogsNode"};
    dialogsNode.addChildToEnd(std::make_shared<ls::std::io::XmlNode>("dialogA"));
    dialogsNode.addChildToEnd(std::make_shared<ls::std::io::XmlNode>("dialogB"));
    dialogsNode.addChildToEnd(std::make_shared<ls::std::io::XmlNode>("dialogC"));

    ASSERT_TRUE(dialogsNode.hasChild("dialogA"));
    ASSERT_TRUE(dialogsNode.hasChild("dialogB"));
    ASSERT_TRUE(dialogsNode.hasChild("dialogC"));
  }

  TEST_F(XmlNodeTest, hasChild_child_not_available)
  {
    ls::std::io::XmlNode dialogsNode{"dialogsNode"};
    ASSERT_FALSE(dialogsNode.hasChild("dialogD"));
  }

  TEST_F(XmlNodeTest, hasChild_empty_name)
  {
    ls::std::io::XmlNode dialogNode{"dialogNode"};

    EXPECT_THROW({
                   try
                   {
                     dialogNode.hasChild("");
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }

  TEST_F(XmlNodeTest, hasChildV2)
  {
    ls::std::io::XmlNode dialogsNode{"dialogsNode"};
    std::shared_ptr<ls::std::io::XmlNode> searchNode = std::make_shared<ls::std::io::XmlNode>("dialogB");
    dialogsNode.addChildToEnd(std::make_shared<ls::std::io::XmlNode>("dialogA"));
    dialogsNode.addChildToEnd(searchNode);
    dialogsNode.addChildToEnd(std::make_shared<ls::std::io::XmlNode>("dialogC"));

    ASSERT_TRUE(dialogsNode.hasChild(searchNode));
  }

  TEST_F(XmlNodeTest, hasChildV2_child_not_available)
  {
    ls::std::io::XmlNode dialogsNode{"dialogsNode"};
    std::shared_ptr<ls::std::io::XmlNode> searchNode = std::make_shared<ls::std::io::XmlNode>("dialogB");

    ASSERT_FALSE(dialogsNode.hasChild(searchNode));
  }

  TEST_F(XmlNodeTest, hasChildV2_no_child_reference)
  {
    ls::std::io::XmlNode dialogNode{"dialog"};
    std::shared_ptr<ls::std::io::XmlNode> searchNode{};

    EXPECT_THROW({
                   try
                   {
                     dialogNode.hasChild(searchNode);
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }

  TEST_F(XmlNodeTest, removeFirstAttribute)
  {
    ls::std::io::XmlNode dialogNode{"dialog"};
    std::shared_ptr<ls::std::io::XmlAttribute> currentAttribute{};
    dialogNode.addAttributeToEnd(std::make_shared<ls::std::io::XmlAttribute>("id"));
    dialogNode.addAttributeToEnd(std::make_shared<ls::std::io::XmlAttribute>("events"));
    dialogNode.addAttributeToEnd(std::make_shared<ls::std::io::XmlAttribute>("assets"));

    ASSERT_TRUE(!dialogNode.getAttributes().empty());
    ASSERT_EQ(3, dialogNode.getAttributes().size());

    ASSERT_TRUE(dialogNode.removeFirstAttribute());
    ASSERT_EQ(2, dialogNode.getAttributes().size());

    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 0);
    ASSERT_STREQ("events", currentAttribute->getName().c_str());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 1);
    ASSERT_STREQ("assets", currentAttribute->getName().c_str());
  }

  TEST_F(XmlNodeTest, removeFirstAttribute_no_attributes_available)
  {
    ls::std::io::XmlNode dialogNode{"dialog"};
    ASSERT_FALSE(dialogNode.removeFirstAttribute());
  }

  TEST_F(XmlNodeTest, removeLastAttribute)
  {
    ls::std::io::XmlNode dialogNode{"dialog"};
    std::shared_ptr<ls::std::io::XmlAttribute> currentAttribute{};
    dialogNode.addAttributeToEnd(std::make_shared<ls::std::io::XmlAttribute>("id"));
    dialogNode.addAttributeToEnd(std::make_shared<ls::std::io::XmlAttribute>("events"));
    dialogNode.addAttributeToEnd(std::make_shared<ls::std::io::XmlAttribute>("assets"));

    ASSERT_TRUE(!dialogNode.getAttributes().empty());
    ASSERT_EQ(3, dialogNode.getAttributes().size());

    ASSERT_TRUE(dialogNode.removeLastAttribute());
    ASSERT_EQ(2, dialogNode.getAttributes().size());

    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 0);
    ASSERT_STREQ("id", currentAttribute->getName().c_str());
    currentAttribute = *std::next(dialogNode.getAttributes().begin(), 1);
    ASSERT_STREQ("events", currentAttribute->getName().c_str());
  }

  TEST_F(XmlNodeTest, removeLastAttribute_no_attributes_available)
  {
    ls::std::io::XmlNode dialogNode{"dialog"};
    ASSERT_FALSE(dialogNode.removeLastAttribute());
  }

  TEST_F(XmlNodeTest, removeFirstChild)
  {
    ls::std::io::XmlNode dialogsNode{"dialogs"};
    std::shared_ptr<ls::std::io::XmlNode> currentNode{};

    // preparation

    ASSERT_TRUE(dialogsNode.addChildToEnd(std::make_shared<ls::std::io::XmlNode>("dialogA")));
    ASSERT_TRUE(dialogsNode.addChildToEnd(std::make_shared<ls::std::io::XmlNode>("dialogB")));
    ASSERT_TRUE(dialogsNode.addChildToEnd(std::make_shared<ls::std::io::XmlNode>("dialogC")));
    ASSERT_TRUE(dialogsNode.addChildToEnd(std::make_shared<ls::std::io::XmlNode>("additionalInfo")));
    ASSERT_TRUE(dialogsNode.addChildToEnd(std::make_shared<ls::std::io::XmlNode>("event")));

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

    ASSERT_TRUE(dialogsNode.removeFirstChild());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 0);
    ASSERT_STREQ("dialogB", currentNode->getName().c_str());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 1);
    ASSERT_STREQ("dialogC", currentNode->getName().c_str());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 2);
    ASSERT_STREQ("additionalInfo", currentNode->getName().c_str());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 3);
    ASSERT_STREQ("event", currentNode->getName().c_str());
  }

  TEST_F(XmlNodeTest, removeFirstChild_no_children_available)
  {
    ls::std::io::XmlNode dialogsNode{"dialogs"};
    ASSERT_FALSE(dialogsNode.removeFirstChild());
  }

  TEST_F(XmlNodeTest, removeLastChild)
  {
    ls::std::io::XmlNode dialogsNode{"dialogs"};
    std::shared_ptr<ls::std::io::XmlNode> currentNode{};

    // preparation

    ASSERT_TRUE(dialogsNode.addChildToEnd(std::make_shared<ls::std::io::XmlNode>("dialogA")));
    ASSERT_TRUE(dialogsNode.addChildToEnd(std::make_shared<ls::std::io::XmlNode>("dialogB")));
    ASSERT_TRUE(dialogsNode.addChildToEnd(std::make_shared<ls::std::io::XmlNode>("dialogC")));
    ASSERT_TRUE(dialogsNode.addChildToEnd(std::make_shared<ls::std::io::XmlNode>("additionalInfo")));
    ASSERT_TRUE(dialogsNode.addChildToEnd(std::make_shared<ls::std::io::XmlNode>("event")));

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

    ASSERT_TRUE(dialogsNode.removeLastChild());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 0);
    ASSERT_STREQ("dialogA", currentNode->getName().c_str());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 1);
    ASSERT_STREQ("dialogB", currentNode->getName().c_str());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 2);
    ASSERT_STREQ("dialogC", currentNode->getName().c_str());
    currentNode = *std::next(dialogsNode.getChildren().begin(), 3);
    ASSERT_STREQ("additionalInfo", currentNode->getName().c_str());
  }

  TEST_F(XmlNodeTest, removeLastChild_no_children_available)
  {
    ls::std::io::XmlNode dialogsNode{"dialogs"};
    ASSERT_FALSE(dialogsNode.removeLastChild());
  }

  TEST_F(XmlNodeTest, setName)
  {
    ls::std::io::XmlNode dialogNode{"dialog"};
    dialogNode.setName("dialog2");

    ASSERT_STREQ("dialog2", dialogNode.getName().c_str());
  }

  TEST_F(XmlNodeTest, setName_empty_name)
  {
    ls::std::io::XmlNode dialogNode{"dialog"};

    EXPECT_THROW({
                   try
                   {
                     dialogNode.setName("");
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }

  TEST_F(XmlNodeTest, setValue)
  {
    ls::std::io::XmlNode dialogNode{"dialog"};
    dialogNode.setValue("Something written");

    ASSERT_STREQ("Something written", dialogNode.getValue().c_str());
  }

  TEST_F(XmlNodeTest, setValue_empty_value)
  {
    ls::std::io::XmlNode dialogNode{"dialog"};

    EXPECT_THROW({
                   try
                   {
                     dialogNode.setValue("");
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }

  TEST_F(XmlNodeTest, toXml)
  {
    auto root = ls_std_io_test::TestDataFactory::createXmlContent();
    std::string xmlContent = root->toXml();

    ASSERT_TRUE(!xmlContent.empty());
  }

  TEST_F(XmlNodeTest, toXml_no_value)
  {
    std::shared_ptr<ls::std::io::XmlNode> singleLineElement = std::make_shared<ls::std::io::XmlNode>("info");
    std::shared_ptr<ls::std::io::XmlAttribute> attribute = std::make_shared<ls::std::io::XmlAttribute>("id");
    attribute->setValue("important");
    singleLineElement->addAttributeToEnd(attribute);

    ::std::string xmlContent{singleLineElement->toXml()};
    ::std::string expectedXmlString = R"(<info id="important" />)";

    ASSERT_TRUE(xmlContent.find(expectedXmlString) != ::std::string::npos);
  }
}
