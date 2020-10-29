/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-15
 * Changed:         2020-10-29
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>

namespace {
  class SerializableJSONStateTest : public ::testing::Test {
    protected:

      SerializableJSONStateTest() = default;
      ~SerializableJSONStateTest() override = default;

      void SetUp() override {}
      void TearDown() override {}
  };

  TEST_F(SerializableJSONStateTest, marshal)
  {
    std::shared_ptr<ls_std::State> x = std::make_shared<ls_std::State>("A");
    x->addStateConnection(std::make_shared<ls_std::StateConnection>("AB", "B"));
    x->addStateConnection(std::make_shared<ls_std::StateConnection>("AC", "C"));

    ls_std::SerializableJSONState serializable {x};
    ls_std::byte_field jsonString = serializable.marshal();

    ASSERT_TRUE(!jsonString.empty());
    std::string expectedJSONString = R"({"connectedStates":{"AB":{"condition":false,"connectionId":"AB","stateId":"B"},"AC":{"condition":false,"connectionId":"AC","stateId":"C"}},"id":"A"})";
    ASSERT_STREQ(expectedJSONString.c_str(), jsonString.c_str());
  }

  TEST_F(SerializableJSONStateTest, unmarshal)
  {
    std::shared_ptr<ls_std::State> x = std::make_shared<ls_std::State>("A");
    ls_std::SerializableJSONState serializable {x};

    // before

    ASSERT_STREQ("A", x->getId().c_str());
    ASSERT_TRUE(x->getConnectedStates().empty());

    // after

    std::string jsonString = R"({"id":"A","connectedStates":{"AB":{"condition":false,"connectionId":"AB","stateId":"B"}}})";
    serializable.unmarshal(jsonString);

    ASSERT_STREQ("A", x->getId().c_str());
    ASSERT_EQ(1, x->getConnectedStates().size());
    ASSERT_STREQ("AB", x->getConnectedStates().at("AB")->getConnectionId().c_str());
    ASSERT_FALSE(x->getConnectedStates().at("AB")->isPassable());
    ASSERT_STREQ("B", x->getConnectedStates().at("AB")->getStateId().c_str());
  }

  TEST_F(SerializableJSONStateTest, setValue)
  {
    std::shared_ptr<ls_std::State> x = std::make_shared<ls_std::State>("A");
    x->addStateConnection(std::make_shared<ls_std::StateConnection>("AB", "B"));
    x->addStateConnection(std::make_shared<ls_std::StateConnection>("AC", "C"));

    ls_std::SerializableJSONState serializable {x};
    ls_std::byte_field jsonString = serializable.marshal();

    std::string expectedJSONString = R"({"connectedStates":{"AB":{"condition":false,"connectionId":"AB","stateId":"B"},"AC":{"condition":false,"connectionId":"AC","stateId":"C"}},"id":"A"})";
    ASSERT_STREQ(expectedJSONString.c_str(), jsonString.c_str());

    // setValue should now clear json

    std::shared_ptr<ls_std::State> y = std::make_shared<ls_std::State>("B");
    serializable.setValue(y);
    jsonString = serializable.marshal();

    ASSERT_STREQ(R"({"id":"B"})", jsonString.c_str());
  }
}
