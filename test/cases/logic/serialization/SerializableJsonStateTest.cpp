/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-15
 * Changed:         2022-05-05
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>

namespace
{
  class SerializableJsonStateTest : public ::testing::Test
  {
    protected:

      SerializableJsonStateTest() = default;
      ~SerializableJsonStateTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(SerializableJsonStateTest, constructor_no_parameter_set)
  {
    EXPECT_THROW({
                   try
                   {
                     ls::SerializableJsonState serializable{nullptr};
                   }
                   catch (const ls::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::IllegalArgumentException);
  }

  TEST_F(SerializableJsonStateTest, marshal)
  {
    std::shared_ptr<ls::State> x = std::make_shared<ls::State>("A");
    x->addStateConnection(std::make_shared<ls::StateConnection>("AB", "B"));
    x->addStateConnection(std::make_shared<ls::StateConnection>("AC", "C"));

    ls::SerializableJsonState serializable{x};
    ls::byte_field jsonString = serializable.marshal();

    ASSERT_TRUE(!jsonString.empty());
    std::string expectedJson = R"({"connectedStates":{"AB":{"condition":false,"connectionId":"AB","stateId":"B"},"AC":{"condition":false,"connectionId":"AC","stateId":"C"}},"id":"A"})";
    ASSERT_STREQ(expectedJson.c_str(), jsonString.c_str());
  }

  TEST_F(SerializableJsonStateTest, unmarshal)
  {
    std::shared_ptr<ls::State> x = std::make_shared<ls::State>("A");
    ls::SerializableJsonState serializable{x};

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

  TEST_F(SerializableJsonStateTest, getValue)
  {
    std::shared_ptr<ls::State> x = std::make_shared<ls::State>("A");
    ls::SerializableJsonState serializable{x};
    ASSERT_TRUE(serializable.getValue() == x);
  }

  TEST_F(SerializableJsonStateTest, setValue)
  {
    std::shared_ptr<ls::State> x = std::make_shared<ls::State>("A");
    x->addStateConnection(std::make_shared<ls::StateConnection>("AB", "B"));
    x->addStateConnection(std::make_shared<ls::StateConnection>("AC", "C"));

    ls::SerializableJsonState serializable{x};
    ls::byte_field jsonString = serializable.marshal();

    std::string expectedJson = R"({"connectedStates":{"AB":{"condition":false,"connectionId":"AB","stateId":"B"},"AC":{"condition":false,"connectionId":"AC","stateId":"C"}},"id":"A"})";
    ASSERT_STREQ(expectedJson.c_str(), jsonString.c_str());

    // setValue should now clear json

    std::shared_ptr<ls::State> y = std::make_shared<ls::State>("B");
    serializable.setValue(y);
    jsonString = serializable.marshal();

    ASSERT_STREQ(R"({"id":"B"})", jsonString.c_str());
  }

  TEST_F(SerializableJsonStateTest, setValue_parameter_not_set)
  {
    std::shared_ptr<ls::State> state = std::make_shared<ls::State>("A");
    ls::SerializableJsonState serializable{state};

    EXPECT_THROW({
                   try
                   {
                     serializable.setValue(nullptr);
                   }
                   catch (const ls::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::IllegalArgumentException);
  }
}
