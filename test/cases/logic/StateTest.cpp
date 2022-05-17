/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-05
 * Changed:         2022-05-15
 *
 * */

#include <gtest/gtest.h>
#include <memory>
#include <ls_std/ls_std_core.hpp>
#include <ls_std/ls_std_logic.hpp>

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

  TEST_F(StateTest, getClassName)
  {
    ls::std::logic::State state{"A"};
    ASSERT_STREQ("State", state.getClassName().c_str());
  }

  TEST_F(StateTest, constructor_empty_id)
  {
    EXPECT_THROW({
                   try
                   {
                     ls::std::logic::State state = ls::std::logic::State("");
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }

  // additional functionality

  TEST_F(StateTest, addStateConnection_v1)
  {
    ls::std::logic::State stateA{"A"};
    ls::std::logic::State stateB{"B"};

    ASSERT_TRUE(stateA.addStateConnection("AB", std::make_shared<ls::std::logic::State>(stateB)));
  }

  TEST_F(StateTest, addStateConnection_v1_connection_already_exists)
  {
    ls::std::logic::State stateA{"A"};
    ls::std::logic::State stateB{"B"};

    ASSERT_TRUE(stateA.addStateConnection("AB", std::make_shared<ls::std::logic::State>(stateB)));
    ASSERT_FALSE(stateA.addStateConnection("AB", std::make_shared<ls::std::logic::State>(stateB)));
  }

  TEST_F(StateTest, addStateConnection_v1_empty_connection_id)
  {
    ls::std::logic::State state{"A"};

    EXPECT_THROW({
                   try
                   {
                     state.addStateConnection("", std::make_shared<ls::std::logic::State>("B"));
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }

  TEST_F(StateTest, addStateConnection_v1_no_reference)
  {
    ls::std::logic::State state{"A"};

    EXPECT_THROW({
                   try
                   {
                     state.addStateConnection("AB", nullptr);
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }

  TEST_F(StateTest, addStateConnection_v2)
  {
    ls::std::logic::State stateA{"A"};
    ls::std::logic::State stateB{"B"};

    ASSERT_TRUE(stateA.addStateConnection(std::make_shared<ls::std::logic::StateConnection>("AB", stateB.getId())));
  }

  TEST_F(StateTest, addStateConnection_v2_no_reference)
  {
    ls::std::logic::State stateA{"A"};

    EXPECT_THROW({
                   try
                   {
                     stateA.addStateConnection(nullptr);
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }

  TEST_F(StateTest, clearConnections)
  {
    ls::std::logic::State stateA{"A"};
    stateA.addStateConnection(std::make_shared<ls::std::logic::StateConnection>("AB", "B"));
    stateA.addStateConnection(std::make_shared<ls::std::logic::StateConnection>("AC", "C"));

    ASSERT_FALSE(stateA.getConnectedStates().empty());
    stateA.clearConnections();
    ASSERT_TRUE(stateA.getConnectedStates().empty());
  }

  TEST_F(StateTest, getConnectedStates)
  {
    ls::std::logic::State stateA{"A"};
    ASSERT_TRUE(stateA.getConnectedStates().empty());
  }

  TEST_F(StateTest, getId)
  {
    ls::std::logic::State stateA{"A"};
    ASSERT_STREQ("A", stateA.getId().c_str());
  }

  TEST_F(StateTest, setId)
  {
    ls::std::logic::State stateA{"A"};
    ASSERT_STREQ("A", stateA.getId().c_str());

    stateA.setId("B");
    ASSERT_STREQ("B", stateA.getId().c_str());
  }

  TEST_F(StateTest, setId_empty_id)
  {
    ls::std::logic::State stateA{"A"};

    EXPECT_THROW({
                   try
                   {
                     stateA.setId("");
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }

  TEST_F(StateTest, hasConnection)
  {
    ls::std::logic::State stateA{"A"};
    ls::std::logic::State stateB{"B"};
    ls::std::logic::State stateC{"C"};

    ASSERT_TRUE(stateA.addStateConnection("AB", std::make_shared<ls::std::logic::State>(stateB)));
    ASSERT_TRUE(stateA.hasConnection("AB"));
    ASSERT_TRUE(stateA.addStateConnection("AC", std::make_shared<ls::std::logic::State>(stateC)));
    ASSERT_TRUE(stateA.hasConnection("AC"));
  }

  TEST_F(StateTest, hasConnection_no_connections_available)
  {
    ls::std::logic::State stateA{"A"};
    ASSERT_FALSE(stateA.hasConnection("AB"));
  }
}
