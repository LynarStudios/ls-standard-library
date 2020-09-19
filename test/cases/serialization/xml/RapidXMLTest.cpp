/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-19
 * Changed:         2020-09-19
 *
 * */

#include <gtest/gtest.h>
#include <rapidxml.hpp>
#include "../../../../source/io/File.hpp"
#include "../../../TestHelper.hpp"
#include "../../../../source/io/FileReader.hpp"
#include "../../../../source/boxing/String.hpp"

namespace {
  class XMLTest : public ::testing::Test {
    protected:

      XMLTest() = default;
      ~XMLTest() override = default;

      void SetUp() override {}
      void TearDown() override {}
  };

  TEST_F(XMLTest, readDocument)
  {
    rapidxml::xml_document<> document {};

    ls_std::File xmlFile {TestHelper::getResourcesFolderLocation() + "/state_machine_test.xml"};
    ls_std::FileReader reader {xmlFile};
    ls_std::byte_field data = reader.read();

    std::vector<ls_std::byte> byteData(data.begin(), data.end());
    byteData.push_back('\0');
    document.parse<0>(byteData.data());

    rapidxml::xml_node<>* parentNode = document.first_node("stateMachine");
    ASSERT_TRUE(parentNode != nullptr);
    ASSERT_STREQ("test_machine", parentNode->first_attribute("name")->value());

    rapidxml::xml_node<>* stateNodes = parentNode->first_node("states");
    ASSERT_TRUE(stateNodes != nullptr);

    int amount = 1;
    rapidxml::xml_node<>* stateNode = stateNodes->first_node("state");

    while(stateNode != nullptr) {
      stateNode = stateNode->next_sibling("state");

      if(stateNode != nullptr) {
        amount++;
      }
    }

    ASSERT_EQ(5, amount);
  }

  TEST_F(XMLTest, readText)
  {
    rapidxml::xml_document<> document {};
    ls_std::String data {R"(<connection id="test">\n</connection>)"}; // needs to have line break?
    document.parse<0>(data.getByteData().data());

    rapidxml::xml_node<>* connectionNode = document.first_node("connection");
    ASSERT_TRUE(connectionNode != nullptr);
    ASSERT_STREQ("test", connectionNode->first_attribute("id")->value());
  }
}
