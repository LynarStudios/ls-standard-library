/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-09
 * Changed:         2020-10-29
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>
#include "../../TestDataFactory.hpp"

namespace {
  class StateMachineTest : public ::testing::Test {
    protected:

      StateMachineTest() = default;
      ~StateMachineTest() override = default;

      void SetUp() override {}
      void TearDown() override {}
  };

  TEST_F(StateMachineTest, addStateConnection)
  {
    ls_std::StateMachine stateMachine {"test_machine"};
    ASSERT_TRUE(stateMachine.addState(std::make_shared<ls_std::State>("A")));
  }

  TEST_F(StateMachineTest, addStateConnectionNegative)
  {
    ls_std::StateMachine stateMachine {"test_machine"};
    ASSERT_TRUE(stateMachine.addState(std::make_shared<ls_std::State>("A")));
    ASSERT_FALSE(stateMachine.addState(std::make_shared<ls_std::State>("A")));
  }

  TEST_F(StateMachineTest, getCurrentState)
  {
    ls_std::StateMachine stateMachine {"test_machine"};
    ASSERT_TRUE(stateMachine.addState(std::make_shared<ls_std::State>("A")));

    ASSERT_TRUE(stateMachine.getCurrentState() == nullptr);
  }

  TEST_F(StateMachineTest, getMemory)
  {
    ls_std::StateMachine stateMachine = ls_std_test::TestDataFactory::createStateMachine();
    ASSERT_STREQ("test_machine", stateMachine.getName().c_str());
    ASSERT_EQ(0, stateMachine.getMemory().size());

    stateMachine.setStartState("A");
    ASSERT_EQ(1, stateMachine.getMemory().size());
    ASSERT_STREQ("A", stateMachine.getMemory().at(0).c_str());

    ASSERT_FALSE(stateMachine.proceed());
    ASSERT_EQ(1, stateMachine.getMemory().size());
    ASSERT_STREQ("A", stateMachine.getMemory().at(0).c_str());

    stateMachine.getCurrentState()->getConnectedStates().at("AB")->updatePassCondition(true);
    ASSERT_TRUE(stateMachine.proceed());
    ASSERT_EQ(2, stateMachine.getMemory().size());
    ASSERT_STREQ("A", stateMachine.getMemory().at(0).c_str());
    ASSERT_STREQ("B", stateMachine.getMemory().at(1).c_str());

    stateMachine.getCurrentState()->getConnectedStates().at("BC")->updatePassCondition(true);
    ASSERT_TRUE(stateMachine.proceed());
    ASSERT_EQ(3, stateMachine.getMemory().size());
    ASSERT_STREQ("A", stateMachine.getMemory().at(0).c_str());
    ASSERT_STREQ("B", stateMachine.getMemory().at(1).c_str());
    ASSERT_STREQ("C", stateMachine.getMemory().at(2).c_str());

    stateMachine.getCurrentState()->getConnectedStates().at("CB")->updatePassCondition(true);
    ASSERT_TRUE(stateMachine.proceed());
    ASSERT_EQ(4, stateMachine.getMemory().size());
    ASSERT_STREQ("A", stateMachine.getMemory().at(0).c_str());
    ASSERT_STREQ("B", stateMachine.getMemory().at(1).c_str());
    ASSERT_STREQ("C", stateMachine.getMemory().at(2).c_str());
    ASSERT_STREQ("B", stateMachine.getMemory().at(3).c_str());
  }

  TEST_F(StateMachineTest, getName)
  {
    ls_std::StateMachine stateMachine {"test_machine"};
    ASSERT_STREQ("test_machine", stateMachine.getName().c_str());
  }

  TEST_F(StateMachineTest, getStates)
  {
    ls_std::StateMachine stateMachine = ls_std_test::TestDataFactory::createStateMachine();

    ASSERT_TRUE(!stateMachine.getStates().empty());
    ASSERT_EQ(5, stateMachine.getStates().size());
  }

  TEST_F(StateMachineTest, hasState)
  {
    ls_std::StateMachine stateMachine = ls_std_test::TestDataFactory::createStateMachine();

    ASSERT_TRUE(stateMachine.hasState("A"));
    ASSERT_TRUE(stateMachine.hasState("B"));
    ASSERT_TRUE(stateMachine.hasState("C"));
    ASSERT_TRUE(stateMachine.hasState("D"));
    ASSERT_TRUE(stateMachine.hasState("E"));
  }

  TEST_F(StateMachineTest, hasStateNegative)
  {
    ls_std::StateMachine stateMachine = ls_std_test::TestDataFactory::createStateMachine();
    ASSERT_FALSE(stateMachine.hasState("F"));
  }

  TEST_F(StateMachineTest, proceed)
  {
    ls_std::StateMachine stateMachine = ls_std_test::TestDataFactory::createStateMachine();
    ASSERT_STREQ("test_machine", stateMachine.getName().c_str());
    ASSERT_TRUE(stateMachine.setStartState("A"));

    ASSERT_FALSE(stateMachine.proceed());

    // activate AB

    stateMachine.getCurrentState()->getConnectedStates().at("AB")->updatePassCondition(true);
    ASSERT_TRUE(stateMachine.proceed());
    ASSERT_STREQ("B", stateMachine.getCurrentState()->getId().c_str());

    // activate BC and BD

    stateMachine.getCurrentState()->getConnectedStates().at("BC")->updatePassCondition(true);
    stateMachine.getCurrentState()->getConnectedStates().at("BD")->updatePassCondition(true);
    ASSERT_FALSE(stateMachine.proceed());

    // BC only!

    stateMachine.getCurrentState()->getConnectedStates().at("BD")->updatePassCondition(false);
    ASSERT_TRUE(stateMachine.proceed());
    ASSERT_STREQ("C", stateMachine.getCurrentState()->getId().c_str());

    // activate CB

    stateMachine.getCurrentState()->getConnectedStates().at("CB")->updatePassCondition(true);
    ASSERT_TRUE(stateMachine.proceed());
    ASSERT_STREQ("B", stateMachine.getCurrentState()->getId().c_str());

    // BD only!

    stateMachine.getCurrentState()->getConnectedStates().at("BD")->updatePassCondition(true);
    stateMachine.getCurrentState()->getConnectedStates().at("BC")->updatePassCondition(false);
    ASSERT_TRUE(stateMachine.proceed());
    ASSERT_STREQ("D", stateMachine.getCurrentState()->getId().c_str());

    // activate DE

    stateMachine.getCurrentState()->getConnectedStates().at("DE")->updatePassCondition(true);
    ASSERT_TRUE(stateMachine.proceed());
    ASSERT_STREQ("E", stateMachine.getCurrentState()->getId().c_str());

    // end reached

    ASSERT_FALSE(stateMachine.proceed());
    ASSERT_STREQ("E", stateMachine.getCurrentState()->getId().c_str());
  }

  TEST_F(StateMachineTest, setMemory)
  {
    ls_std::StateMachine stateMachine {"test_machine"};
    ASSERT_TRUE(stateMachine.getMemory().empty());

    std::vector<ls_std::StateId> memory {"A", "B", "C"};
    stateMachine.setMemory(memory);

    ASSERT_FALSE(stateMachine.getMemory().empty());
    ASSERT_EQ(3, stateMachine.getMemory().size());
    ASSERT_STREQ("A", stateMachine.getMemory().at(0).c_str());
    ASSERT_STREQ("B", stateMachine.getMemory().at(1).c_str());
    ASSERT_STREQ("C", stateMachine.getMemory().at(2).c_str());
  }

  TEST_F(StateMachineTest, setName)
  {
    ls_std::StateMachine stateMachine {"test_machine"};
    ASSERT_STREQ("test_machine", stateMachine.getName().c_str());

    stateMachine.setName("bla");
    ASSERT_STREQ("bla", stateMachine.getName().c_str());
  }

  TEST_F(StateMachineTest, setStartState)
  {
    ls_std::StateMachine stateMachine {"test_machine"};
    ASSERT_FALSE(stateMachine.getCurrentState() != nullptr);

    ASSERT_TRUE(stateMachine.addState(std::make_shared<ls_std::State>("A")));
    ASSERT_TRUE(stateMachine.setStartState("A"));
    ASSERT_TRUE(stateMachine.getCurrentState() != nullptr);
  }
}
