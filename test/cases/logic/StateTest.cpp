/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-05
 * Changed:         2021-04-30
 *
 * */

#include <gtest/gtest.h>
#include <memory>
#include <ls_std/ls_std.hpp>

namespace
{
  class StateTest : public ::testing::Test
  {
    protected:

      StateTest() = default;
      ~StateTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  // implementation

  TEST_F(StateTest, marshal)
  {
    std::shared_ptr<ls_std::State> state = std::make_shared<ls_std::State>("A");
    std::shared_ptr<ls_std::ISerializable> serializable = std::make_shared<ls_std::SerializableJSONState>(state);
    state->setSerializable(serializable);

    ASSERT_FALSE(state->marshal().empty());
  }

  TEST_F(StateTest, marshal_noSerializableReference)
  {
    ls_std::State state{"A"};

    EXPECT_THROW({
                   try
                   {
                     state.marshal();
                   }
                   catch (const ls_std::NullPointerException &_exception)
                   {
                     throw;
                   }
                 }, ls_std::NullPointerException);
  }

  TEST_F(StateTest, unmarshal)
  {
    std::shared_ptr<ls_std::State> state = std::make_shared<ls_std::State>("TMP_ID");
    std::shared_ptr<ls_std::ISerializable> serializable = std::make_shared<ls_std::SerializableJSONState>(state);
    state->setSerializable(serializable);
    std::string jsonString = R"({"id":"A","connectedStates":{"AB":{"condition":false,"connectionId":"AB","stateId":"B"}}})";
    state->unmarshal(jsonString);

    ASSERT_STREQ("A", state->getId().c_str());
  }

  TEST_F(StateTest, unmarshal_noSerializableReference)
  {
    std::shared_ptr<ls_std::State> state = std::make_shared<ls_std::State>("TMP_ID");
    std::string jsonString = R"({"id":"A","connectedStates":{"AB":{"condition":false,"connectionId":"AB","stateId":"B"}}})";

    EXPECT_THROW({
                   try
                   {
                     state->unmarshal(jsonString);
                   }
                   catch (const ls_std::NullPointerException &_exception)
                   {
                     throw;
                   }
                 }, ls_std::NullPointerException);
  }

  // additional functionality

  TEST_F(StateTest, addStateConnection)
  {
    ls_std::State stateA{"A"};
    ls_std::State stateB{"B"};

    ASSERT_TRUE(stateA.addStateConnection("AB", std::make_shared<ls_std::State>(stateB)));
  }

  TEST_F(StateTest, addStateConnectionNegative)
  {
    ls_std::State stateA{"A"};
    ls_std::State stateB{"B"};

    ASSERT_TRUE(stateA.addStateConnection("AB", std::make_shared<ls_std::State>(stateB)));
    ASSERT_FALSE(stateA.addStateConnection("AB", std::make_shared<ls_std::State>(stateB)));
    ASSERT_FALSE(stateA.addStateConnection("XX", nullptr));
  }

  TEST_F(StateTest, addStateConnectionV2)
  {
    ls_std::State stateA{"A"};
    ls_std::State stateB{"B"};

    ASSERT_TRUE(stateA.addStateConnection(std::make_shared<ls_std::StateConnection>("AB", stateB.getId())));
  }

  TEST_F(StateTest, addStateConnectionV2Negative)
  {
    ls_std::State stateA{"A"};
    ASSERT_FALSE(stateA.addStateConnection(nullptr));
  }

  TEST_F(StateTest, clearConnections)
  {
    ls_std::State stateA{"A"};
    stateA.addStateConnection(std::make_shared<ls_std::StateConnection>("AB", "B"));
    stateA.addStateConnection(std::make_shared<ls_std::StateConnection>("AC", "C"));

    ASSERT_EQ(2, stateA.getConnectedStates().size());
    stateA.clearConnections();
    ASSERT_EQ(0, stateA.getConnectedStates().size());
    ASSERT_TRUE(stateA.getConnectedStates().empty());
  }

  TEST_F(StateTest, getConnectedStates)
  {
    ls_std::State stateA{"A"};
    ls_std::State stateB{"B"};

    ASSERT_TRUE(stateA.addStateConnection("AB", std::make_shared<ls_std::State>(stateB)));
    ASSERT_FALSE(stateA.getConnectedStates().empty());
    ASSERT_EQ(1, stateA.getConnectedStates().size());
  }

  TEST_F(StateTest, getConnectedStatesNegative)
  {
    ls_std::State stateA{"A"};

    ASSERT_TRUE(stateA.getConnectedStates().empty());
    ASSERT_EQ(0, stateA.getConnectedStates().size());
  }

  TEST_F(StateTest, getId)
  {
    ls_std::State stateA{"A"};
    ASSERT_STREQ("A", stateA.getId().c_str());
  }

  TEST_F(StateTest, setId)
  {
    ls_std::State stateA{"A"};
    ASSERT_STREQ("A", stateA.getId().c_str());

    stateA.setId("B");
    ASSERT_STREQ("B", stateA.getId().c_str());
  }

  TEST_F(StateTest, hasConnection)
  {
    ls_std::State stateA{"A"};
    ls_std::State stateB{"B"};
    ls_std::State stateC{"C"};

    ASSERT_TRUE(stateA.addStateConnection("AB", std::make_shared<ls_std::State>(stateB)));
    ASSERT_TRUE(stateA.hasConnection("AB"));
    ASSERT_TRUE(stateA.addStateConnection("AC", std::make_shared<ls_std::State>(stateC)));
    ASSERT_TRUE(stateA.hasConnection("AC"));
  }

  TEST_F(StateTest, hasConnectionNegative)
  {
    ls_std::State stateA{"A"};
    ASSERT_FALSE(stateA.hasConnection("AB"));
    ASSERT_FALSE(stateA.hasConnection("AC"));
  }

  TEST_F(StateTest, setSerializable_noSerializableReference)
  {
    ls_std::State state{"A"};
    std::shared_ptr<ls_std::ISerializable> serializable{};

    EXPECT_THROW({
                   try
                   {
                     state.setSerializable(serializable);
                   }
                   catch (const ls_std::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls_std::IllegalArgumentException);
  }
}
