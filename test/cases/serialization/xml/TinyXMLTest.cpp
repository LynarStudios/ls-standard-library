/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-20
 * Changed:         2020-09-20
 *
 * */

#include <gtest/gtest.h>
#include <tinyxml2.h>
#include "../../../../source/io/File.hpp"
#include "../../../TestHelper.hpp"
#include "../../../../source/io/FileReader.hpp"
#include "../../../../source/boxing/String.hpp"

namespace {
  class TinyXMLTest : public ::testing::Test {
    protected:

      TinyXMLTest() = default;
      ~TinyXMLTest() override = default;

      void SetUp() override {}
      void TearDown() override {}
  };

  TEST_F(TinyXMLTest, readDocument)
  {
    ls_std::File xmlFile {TestHelper::getResourcesFolderLocation() + "/state_machine_test.xml"};
    ls_std::FileReader reader {xmlFile};

    tinyxml2::XMLDocument document {};
    ls_std::String data {reader.read()};
    document.Parse(data.getByteData().data());

    tinyxml2::XMLNode* root = document.RootElement();

    ASSERT_TRUE(root != nullptr);
    ASSERT_STREQ("stateMachine", root->Value());
    ASSERT_TRUE(root->ToElement()->FindAttribute("name") != nullptr);
    ASSERT_STREQ("test_machine", root->ToElement()->FindAttribute("name")->Value());

    tinyxml2::XMLNode* statesNode = root->FirstChildElement("states");
    ASSERT_TRUE(statesNode != nullptr);

    tinyxml2::XMLNode* stateNode = statesNode->FirstChildElement("state");
    ASSERT_TRUE(stateNode != nullptr);
    int amount = 1;

    while(stateNode != nullptr) {
      stateNode = stateNode->NextSibling();

      if(stateNode != nullptr) {
        amount++;
      }
    }

    ASSERT_EQ(5, amount);
  }

  TEST_F(TinyXMLTest, readText)
  {
    tinyxml2::XMLDocument document {};
    ls_std::String data {R"(<connection connectionId="AB" condition="false" id="B"></connection>)"};
    document.Parse(data.getByteData().data());

    tinyxml2::XMLNode* root = document.RootElement();
    ASSERT_TRUE(root != nullptr);

    const tinyxml2::XMLAttribute *connectionIdAttribute = root->ToElement()->FindAttribute("connectionId");
    ASSERT_TRUE(connectionIdAttribute != nullptr);
    ASSERT_STREQ("connectionId", connectionIdAttribute->Name());
    ASSERT_STREQ("AB", connectionIdAttribute->Value());

    const tinyxml2::XMLAttribute *conditionAttribute = root->ToElement()->FindAttribute("condition");
    ASSERT_TRUE(conditionAttribute != nullptr);
    ASSERT_STREQ("condition", conditionAttribute->Name());
    ASSERT_STREQ("false", conditionAttribute->Value());

    const tinyxml2::XMLAttribute *idAttribute = root->ToElement()->FindAttribute("id");
    ASSERT_TRUE(idAttribute != nullptr);
    ASSERT_STREQ("id", idAttribute->Name());
    ASSERT_STREQ("B", idAttribute->Value());
  }
}
