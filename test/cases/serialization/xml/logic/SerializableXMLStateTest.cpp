/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-20
 * Changed:         2020-09-20
 *
 * *//*


#include <gtest/gtest.h>
#include "../../../../../source/serialization/xml/logic/SerializableXMLState.hpp"
#include "../../../../../source/boxing/String.hpp"

namespace {
  class SerializableXMLStateTest : public ::testing::Test {
    protected:

      SerializableXMLStateTest() = default;
      ~SerializableXMLStateTest() override = default;

      void SetUp() override {}
      void TearDown() override {}
  };

  // implementation

  TEST_F(SerializableXMLStateTest, marshal)
  {
    std::shared_ptr<ls_std::State> stateA = std::make_shared<ls_std::State>("A");
    stateA->addStateConnection(std::make_shared<ls_std::StateConnection>("AB", "B"));
    stateA->addStateConnection(std::make_shared<ls_std::StateConnection>("AC", "C"));
    ls_std::SerializableXMLState serializable {stateA};

    std::string data = serializable.marshal();
    ASSERT_TRUE(!data.empty());
  }

  TEST_F(SerializableXMLStateTest, unmarshal)
  {
    ls_std::SerializableXMLState serializable {std::make_shared<ls_std::State>("A")};
    std::string xmlText = R"(
      <state id="B">
        <connections>
          <connection connectionId="BC" id="C" condition="true"/>
          <connection connectionId="BD" id="D" condition="true"/>
        </connections>
      </state>)";

    serializable.unmarshal(xmlText);
    ASSERT_STREQ("B", serializable.getValue()->getId().c_str());
    auto connections = serializable.getValue()->getConnectedStates();

    ASSERT_EQ(2, connections.size());
    ASSERT_TRUE(connections.at("BC") != nullptr);
    ASSERT_TRUE(connections.at("BC")->isPassable());
    ASSERT_STREQ("BC", connections.at("BC")->getConnectionId().c_str());
    ASSERT_STREQ("C", connections.at("BC")->getStateId().c_str());

    ASSERT_TRUE(connections.at("BD") != nullptr);
    ASSERT_TRUE(connections.at("BD")->isPassable());
    ASSERT_STREQ("BD", connections.at("BD")->getConnectionId().c_str());
    ASSERT_STREQ("D", connections.at("BD")->getStateId().c_str());
  }

  // additional functionality

  TEST_F(SerializableXMLStateTest, getValue)
  {
    std::shared_ptr<ls_std::State> x = std::make_shared<ls_std::State>("A");
    ls_std::SerializableXMLState serializable {x};

    ASSERT_STREQ("A", serializable.getValue()->getId().c_str());
  }

  TEST_F(SerializableXMLStateTest, setValue)
  {
    ls_std::SerializableXMLState serializable {std::make_shared<ls_std::State>("A")};
    ASSERT_STREQ("A", serializable.getValue()->getId().c_str());

    serializable.setValue(std::make_shared<ls_std::State>("C"));
    ASSERT_STREQ("C", serializable.getValue()->getId().c_str());
  }
}
*/
