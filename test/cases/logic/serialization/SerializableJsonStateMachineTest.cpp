/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-17
 * Changed:         2022-05-20
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std_core.hpp>
#include <ls_std/ls_std_logic.hpp>
#include <ls_std_logic_test.hpp>
#include "TestHelper.hpp"

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

  TEST_F(SerializableJsonStateMachineTest, constructor_no_parameter_set)
  {
    EXPECT_THROW({
                   try
                   {
                     ls::std::logic::SerializableJsonStateMachine serializable{nullptr};
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }

  // implementation

  TEST_F(SerializableJsonStateMachineTest, marshal)
  {
    ls::std::logic::StateMachine stateMachine = ls_std_logic_test::TestDataFactory::createStateMachine();
    stateMachine.setStartState("A");
    stateMachine.setMemory({"A", "B", "C"});
    ls::std::logic::SerializableJsonStateMachine serializable{::std::make_shared<ls::std::logic::StateMachine>(stateMachine)};

    ::std::string jsonString = serializable.marshal();
    ASSERT_TRUE(!jsonString.empty());

    ::std::string path = ls_std_test::TestHelper::getResourcesFolderLocation() + "/state_machine_test.json";
    path = ls_std_test::TestHelper::normalize(path);
    ::std::string content = ls_std_test::TestHelper::readFile(path);

    ASSERT_TRUE(content.find(jsonString) != ::std::string::npos);
  }

  TEST_F(SerializableJsonStateMachineTest, unmarshal)
  {
    ::std::string path = ls_std_test::TestHelper::getResourcesFolderLocation() + "/state_machine_test.json";
    path = ls_std_test::TestHelper::normalize(path);

    ::std::shared_ptr<ls::std::logic::StateMachine> machine = ::std::make_shared<ls::std::logic::StateMachine>("bla");
    ls::std::logic::SerializableJsonStateMachine serializable{machine};

    serializable.unmarshal(ls_std_test::TestHelper::readFile(path));

    ASSERT_STREQ("test_machine", machine->getName().c_str());

    // check memory

    ASSERT_FALSE(machine->getMemory().empty());
    ASSERT_EQ(3, machine->getMemory().size());
    ASSERT_STREQ("A", machine->getMemory().at(0).c_str());
    ASSERT_STREQ("B", machine->getMemory().at(1).c_str());
    ASSERT_STREQ("C", machine->getMemory().at(2).c_str());

    // check current state

    ASSERT_TRUE(machine->getCurrentState() != nullptr);
    ASSERT_STREQ("A", machine->getCurrentState()->getId().c_str());

    // check states

    ASSERT_TRUE(!machine->getStates().empty());
    ASSERT_EQ(5, machine->getStates().size());

    ::std::shared_ptr<ls::std::logic::State> state = machine->getStates().at("A");
    ASSERT_STREQ("A", state->getId().c_str());
    ASSERT_EQ(1, state->getConnectedStates().size());
    ASSERT_STREQ("AB", state->getConnectedStates().at("AB")->getConnectionId().c_str());

    state = machine->getStates().at("B");
    ASSERT_STREQ("B", state->getId().c_str());
    ASSERT_EQ(2, state->getConnectedStates().size());
    ASSERT_STREQ("BC", state->getConnectedStates().at("BC")->getConnectionId().c_str());
    ASSERT_STREQ("BD", state->getConnectedStates().at("BD")->getConnectionId().c_str());

    state = machine->getStates().at("C");
    ASSERT_STREQ("C", state->getId().c_str());
    ASSERT_EQ(2, state->getConnectedStates().size());
    ASSERT_STREQ("CB", state->getConnectedStates().at("CB")->getConnectionId().c_str());
    ASSERT_STREQ("CE", state->getConnectedStates().at("CE")->getConnectionId().c_str());

    state = machine->getStates().at("D");
    ASSERT_STREQ("D", state->getId().c_str());
    ASSERT_EQ(1, state->getConnectedStates().size());
    ASSERT_STREQ("DE", state->getConnectedStates().at("DE")->getConnectionId().c_str());

    state = machine->getStates().at("E");
    ASSERT_STREQ("E", state->getId().c_str());
    ASSERT_TRUE(state->getConnectedStates().empty());
  }

  TEST_F(SerializableJsonStateMachineTest, getValue)
  {
    ::std::shared_ptr<ls::std::logic::StateMachine> x = ::std::make_shared<ls::std::logic::StateMachine>("bla");
    ls::std::logic::SerializableJsonStateMachine serializable{x};
    ASSERT_TRUE(serializable.getValue() == x);
  }

  TEST_F(SerializableJsonStateMachineTest, setValue)
  {
    ::std::shared_ptr<ls::std::logic::StateMachine> x = ::std::make_shared<ls::std::logic::StateMachine>("bla");
    ls::std::logic::SerializableJsonStateMachine serializable{x};
    ASSERT_TRUE(serializable.getValue() == x);

    x = ::std::make_shared<ls::std::logic::StateMachine>("bla2");
    serializable.setValue(x);
    ASSERT_TRUE(serializable.getValue() == x);
  }

  TEST_F(SerializableJsonStateMachineTest, setValue_no_parameter_set)
  {
    ::std::shared_ptr<ls::std::logic::StateMachine> stateMachine = ::std::make_shared<ls::std::logic::StateMachine>("bla");
    ls::std::logic::SerializableJsonStateMachine serializable{stateMachine};

    EXPECT_THROW({
                   try
                   {
                     serializable.setValue(nullptr);
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }
}
