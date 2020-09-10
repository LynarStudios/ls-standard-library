/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-09
 * Changed:         2020-09-10
 *
 * */

#include <gtest/gtest.h>
#include "../../../source/logic/StateMachine.hpp"

namespace {
  class StateMachineTest : public ::testing::Test {
    protected:

      StateMachineTest() = default;
      ~StateMachineTest() override = default;

      void SetUp() override {}
      void TearDown() override {}

      static ls_std::StateMachine _createStateMachine() {
        ls_std::StateMachine stateMachine {"test_machine"};

        std::shared_ptr<ls_std::State> stateA = std::make_shared<ls_std::State>("A");
        std::shared_ptr<ls_std::State> stateB = std::make_shared<ls_std::State>("B");
        std::shared_ptr<ls_std::State> stateC = std::make_shared<ls_std::State>("C");
        std::shared_ptr<ls_std::State> stateD = std::make_shared<ls_std::State>("D");
        std::shared_ptr<ls_std::State> stateE = std::make_shared<ls_std::State>("E");

        // add states

        stateMachine.addState(stateA);
        stateMachine.addState(stateB);
        stateMachine.addState(stateC);
        stateMachine.addState(stateD);
        stateMachine.addState(stateE);

        // add connections / see state_machine_test.png

        stateA->addStateConnection("AB", stateB);
        stateB->addStateConnection("BC", stateC);
        stateB->addStateConnection("BD", stateD);
        stateC->addStateConnection("CB", stateB);
        stateC->addStateConnection("CE", stateE);
        stateD->addStateConnection("DE", stateE);

        return stateMachine;
      }
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

  TEST_F(StateMachineTest, getName)
  {
    ls_std::StateMachine stateMachine {"test_machine"};
    ASSERT_STREQ("test_machine", stateMachine.getName().c_str());
  }

  TEST_F(StateMachineTest, proceed)
  {
    ls_std::StateMachine stateMachine = _createStateMachine();
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

  TEST_F(StateMachineTest, setStartState)
  {
    ls_std::StateMachine stateMachine {"test_machine"};
    ASSERT_FALSE(stateMachine.getCurrentState() != nullptr);

    ASSERT_TRUE(stateMachine.addState(std::make_shared<ls_std::State>("A")));
    ASSERT_TRUE(stateMachine.setStartState("A"));
    ASSERT_TRUE(stateMachine.getCurrentState() != nullptr);
  }
}
