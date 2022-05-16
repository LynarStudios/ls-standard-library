/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-09
 * Changed:         2022-05-15
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std_core.hpp>
#include <ls_std/ls_std_logic.hpp>
#include <ls_std_logic_test.hpp>

namespace
{
  class StateMachineTest : public ::testing::Test
  {
    protected:

      StateMachineTest() = default;
      ~StateMachineTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(StateMachineTest, getClassName)
  {
    ls::std::logic::StateMachine stateMachine {"machine"};
    ASSERT_STREQ("StateMachine", stateMachine.getClassName().c_str());
  }

  TEST_F(StateMachineTest, constructor_empty_name)
  {
    EXPECT_THROW({
                   try
                   {
                     ls::std::logic::StateMachine stateMachine {""};
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }

  TEST_F(StateMachineTest, addState)
  {
    ls::std::logic::StateMachine stateMachine{"test_machine"};
    ASSERT_TRUE(stateMachine.addState(std::make_shared<ls::std::logic::State>("A")));
  }

  TEST_F(StateMachineTest, addState_state_already_exists)
  {
    ls::std::logic::StateMachine stateMachine{"test_machine"};
    ASSERT_TRUE(stateMachine.addState(std::make_shared<ls::std::logic::State>("A")));
    ASSERT_FALSE(stateMachine.addState(std::make_shared<ls::std::logic::State>("A")));
  }

  TEST_F(StateMachineTest, addState_no_reference)
  {
    EXPECT_THROW({
                   try
                   {
                     ls::std::logic::StateMachine stateMachine{"test_machine"};
                     stateMachine.addState(nullptr);
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }

  TEST_F(StateMachineTest, getCurrentState)
  {
    ls::std::logic::StateMachine stateMachine{"test_machine"};
    ASSERT_TRUE(stateMachine.addState(std::make_shared<ls::std::logic::State>("A")));

    ASSERT_TRUE(stateMachine.getCurrentState() == nullptr);
  }

  TEST_F(StateMachineTest, getMemory)
  {
    ls::std::logic::StateMachine stateMachine {"machine"};
    ASSERT_TRUE(stateMachine.getMemory().empty());
  }

  TEST_F(StateMachineTest, getName)
  {
    ls::std::logic::StateMachine stateMachine{"test_machine"};
    ASSERT_STREQ("test_machine", stateMachine.getName().c_str());
  }

  TEST_F(StateMachineTest, getStates)
  {
    ls::std::logic::StateMachine stateMachine {"machine"};
    ASSERT_TRUE(stateMachine.getStates().empty());
  }

  TEST_F(StateMachineTest, hasState)
  {
    ls::std::logic::StateMachine stateMachine = ls_std_logic_test::TestDataFactory::createStateMachine();

    ASSERT_TRUE(stateMachine.hasState("A"));
    ASSERT_TRUE(stateMachine.hasState("B"));
    ASSERT_TRUE(stateMachine.hasState("C"));
    ASSERT_TRUE(stateMachine.hasState("D"));
    ASSERT_TRUE(stateMachine.hasState("E"));
  }

  TEST_F(StateMachineTest, hasState_no_state_available)
  {
    ls::std::logic::StateMachine stateMachine {"machine"};
    ASSERT_FALSE(stateMachine.hasState("F"));
  }

  TEST_F(StateMachineTest, proceed)
  {
    ls::std::logic::StateMachine stateMachine = ls_std_logic_test::TestDataFactory::createStateMachine();
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

  TEST_F(StateMachineTest, setMemory_no_memory)
  {
    ls::std::logic::StateMachine stateMachine{"test_machine"};
    std::vector<ls::std::core::type::state_id> memory{};

    EXPECT_THROW({
                   try
                   {
                     stateMachine.setMemory(memory);
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }

  TEST_F(StateMachineTest, setName)
  {
    ls::std::logic::StateMachine stateMachine{"test_machine"};
    ASSERT_STREQ("test_machine", stateMachine.getName().c_str());

    stateMachine.setName("bla");
    ASSERT_STREQ("bla", stateMachine.getName().c_str());
  }

  TEST_F(StateMachineTest, setName_empty_name)
  {
    EXPECT_THROW({
                   try
                   {
                     ls::std::logic::StateMachine stateMachine {"machine"};
                     stateMachine.setName("");
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }

  TEST_F(StateMachineTest, setStartState)
  {
    ls::std::logic::StateMachine stateMachine{"test_machine"};
    ASSERT_TRUE(stateMachine.getCurrentState() == nullptr);
    stateMachine.addState(std::make_shared<ls::std::logic::State>("A"));

    ASSERT_TRUE(stateMachine.setStartState("A"));
    ASSERT_FALSE(stateMachine.getCurrentState() == nullptr);
  }

  TEST_F(StateMachineTest, setStartState_state_does_not_exist)
  {
    ls::std::logic::StateMachine stateMachine{"test_machine"};
    ASSERT_FALSE(stateMachine.setStartState("A"));
  }

  TEST_F(StateMachineTest, setStartState_empty_id)
  {
    ls::std::logic::StateMachine stateMachine{"test_machine"};

    EXPECT_THROW({
                   try
                   {
                     stateMachine.setStartState("");
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }
}
