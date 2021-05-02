/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-17
 * Changed:         2021-05-02
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>
#include <TestDataFactory.hpp>
#include <TestHelper.hpp>

namespace
{
  class SerializableJsonStateMachineTest : public ::testing::Test
  {
    protected:

      SerializableJsonStateMachineTest() = default;
      ~SerializableJsonStateMachineTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  // implementation

  TEST_F(SerializableJsonStateMachineTest, marshal)
  {
    ls_std::StateMachine stateMachine = ls_std_test::TestDataFactory::createStateMachine();
    stateMachine.setStartState("A");
    stateMachine.setMemory({"A", "B", "C"});
    ls_std::SerializableJsonStateMachine serializable{std::make_shared<ls_std::StateMachine>(stateMachine)};

    std::string jsonString = serializable.marshal();
    ASSERT_TRUE(!jsonString.empty());

    ls_std::File file{TestHelper::getResourcesFolderLocation() + "/state_machine_test.json"};
    ls_std::FileReader reader{file};
    ls_std::String data{reader.read()};

    ASSERT_TRUE(data.contains(jsonString));
  }

  TEST_F(SerializableJsonStateMachineTest, unmarshal)
  {
    ls_std::File file{TestHelper::getResourcesFolderLocation() + "/state_machine_test.json"};
    ls_std::FileReader reader{file};
    std::shared_ptr<ls_std::StateMachine> x = std::make_shared<ls_std::StateMachine>("bla");
    ls_std::SerializableJsonStateMachine serializable{x};

    serializable.unmarshal(reader.read());

    ASSERT_STREQ("test_machine", x->getName().c_str());

    // check memory

    ASSERT_FALSE(x->getMemory().empty());
    ASSERT_EQ(3, x->getMemory().size());
    ASSERT_STREQ("A", x->getMemory().at(0).c_str());
    ASSERT_STREQ("B", x->getMemory().at(1).c_str());
    ASSERT_STREQ("C", x->getMemory().at(2).c_str());

    // check current state

    ASSERT_TRUE(x->getCurrentState() != nullptr);
    ASSERT_STREQ("A", x->getCurrentState()->getId().c_str());

    // check states

    ASSERT_TRUE(!x->getStates().empty());
    ASSERT_EQ(5, x->getStates().size());

    std::shared_ptr<ls_std::State> state = x->getStates().at("A");
    ASSERT_STREQ("A", state->getId().c_str());
    ASSERT_EQ(1, state->getConnectedStates().size());
    ASSERT_STREQ("AB", state->getConnectedStates().at("AB")->getConnectionId().c_str());

    state = x->getStates().at("B");
    ASSERT_STREQ("B", state->getId().c_str());
    ASSERT_EQ(2, state->getConnectedStates().size());
    ASSERT_STREQ("BC", state->getConnectedStates().at("BC")->getConnectionId().c_str());
    ASSERT_STREQ("BD", state->getConnectedStates().at("BD")->getConnectionId().c_str());

    state = x->getStates().at("C");
    ASSERT_STREQ("C", state->getId().c_str());
    ASSERT_EQ(2, state->getConnectedStates().size());
    ASSERT_STREQ("CB", state->getConnectedStates().at("CB")->getConnectionId().c_str());
    ASSERT_STREQ("CE", state->getConnectedStates().at("CE")->getConnectionId().c_str());

    state = x->getStates().at("D");
    ASSERT_STREQ("D", state->getId().c_str());
    ASSERT_EQ(1, state->getConnectedStates().size());
    ASSERT_STREQ("DE", state->getConnectedStates().at("DE")->getConnectionId().c_str());

    state = x->getStates().at("E");
    ASSERT_STREQ("E", state->getId().c_str());
    ASSERT_TRUE(state->getConnectedStates().empty());
  }

  TEST_F(SerializableJsonStateMachineTest, getValue)
  {
    std::shared_ptr<ls_std::StateMachine> x = std::make_shared<ls_std::StateMachine>("bla");
    ls_std::SerializableJsonStateMachine serializable{x};
    ASSERT_TRUE(serializable.getValue() == x);
  }

  TEST_F(SerializableJsonStateMachineTest, setValue)
  {
    std::shared_ptr<ls_std::StateMachine> x = std::make_shared<ls_std::StateMachine>("bla");
    ls_std::SerializableJsonStateMachine serializable{x};
    ASSERT_TRUE(serializable.getValue() == x);

    x = std::make_shared<ls_std::StateMachine>("bla2");
    serializable.setValue(x);
    ASSERT_TRUE(serializable.getValue() == x);
  }
}
