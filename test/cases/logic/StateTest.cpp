/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-05
 * Changed:         2022-05-05
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

  TEST_F(StateTest, getClassName)
  {
    ls::State state{"A"};
    ASSERT_STREQ("State", state.getClassName().c_str());
  }

  TEST_F(StateTest, constructor_empty_id)
  {
    EXPECT_THROW({
                   try
                   {
                     ls::State state = ls::State("");
                   }
                   catch (const ls::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::IllegalArgumentException);
  }

  // additional functionality

  TEST_F(StateTest, addStateConnection_v1)
  {
    ls::State stateA{"A"};
    ls::State stateB{"B"};

    ASSERT_TRUE(stateA.addStateConnection("AB", std::make_shared<ls::State>(stateB)));
  }

  TEST_F(StateTest, addStateConnection_v1_connection_already_exists)
  {
    ls::State stateA{"A"};
    ls::State stateB{"B"};

    ASSERT_TRUE(stateA.addStateConnection("AB", std::make_shared<ls::State>(stateB)));
    ASSERT_FALSE(stateA.addStateConnection("AB", std::make_shared<ls::State>(stateB)));
  }

  TEST_F(StateTest, addStateConnection_v1_empty_connection_id)
  {
    ls::State state{"A"};

    EXPECT_THROW({
                   try
                   {
                     state.addStateConnection("", std::make_shared<ls::State>("B"));
                   }
                   catch (const ls::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::IllegalArgumentException);
  }

  TEST_F(StateTest, addStateConnection_v1_no_reference)
  {
    ls::State state{"A"};

    EXPECT_THROW({
                   try
                   {
                     state.addStateConnection("AB", nullptr);
                   }
                   catch (const ls::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::IllegalArgumentException);
  }

  TEST_F(StateTest, addStateConnection_v2)
  {
    ls::State stateA{"A"};
    ls::State stateB{"B"};

    ASSERT_TRUE(stateA.addStateConnection(std::make_shared<ls::StateConnection>("AB", stateB.getId())));
  }

  TEST_F(StateTest, addStateConnection_v2_no_reference)
  {
    ls::State stateA{"A"};

    EXPECT_THROW({
                   try
                   {
                     stateA.addStateConnection(nullptr);
                   }
                   catch (const ls::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::IllegalArgumentException);
  }

  TEST_F(StateTest, clearConnections)
  {
    ls::State stateA{"A"};
    stateA.addStateConnection(std::make_shared<ls::StateConnection>("AB", "B"));
    stateA.addStateConnection(std::make_shared<ls::StateConnection>("AC", "C"));

    ASSERT_FALSE(stateA.getConnectedStates().empty());
    stateA.clearConnections();
    ASSERT_TRUE(stateA.getConnectedStates().empty());
  }

  TEST_F(StateTest, getConnectedStates)
  {
    ls::State stateA{"A"};
    ASSERT_TRUE(stateA.getConnectedStates().empty());
  }

  TEST_F(StateTest, getId)
  {
    ls::State stateA{"A"};
    ASSERT_STREQ("A", stateA.getId().c_str());
  }

  TEST_F(StateTest, setId)
  {
    ls::State stateA{"A"};
    ASSERT_STREQ("A", stateA.getId().c_str());

    stateA.setId("B");
    ASSERT_STREQ("B", stateA.getId().c_str());
  }

  TEST_F(StateTest, setId_empty_id)
  {
    ls::State stateA{"A"};

    EXPECT_THROW({
                   try
                   {
                     stateA.setId("");
                   }
                   catch (const ls::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::IllegalArgumentException);
  }

  TEST_F(StateTest, hasConnection)
  {
    ls::State stateA{"A"};
    ls::State stateB{"B"};
    ls::State stateC{"C"};

    ASSERT_TRUE(stateA.addStateConnection("AB", std::make_shared<ls::State>(stateB)));
    ASSERT_TRUE(stateA.hasConnection("AB"));
    ASSERT_TRUE(stateA.addStateConnection("AC", std::make_shared<ls::State>(stateC)));
    ASSERT_TRUE(stateA.hasConnection("AC"));
  }

  TEST_F(StateTest, hasConnection_no_connections_available)
  {
    ls::State stateA{"A"};
    ASSERT_FALSE(stateA.hasConnection("AB"));
  }
}
