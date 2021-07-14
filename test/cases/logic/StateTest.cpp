/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-05
 * Changed:         2021-07-14
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
    ls_std::State state{"A"};
    ASSERT_STREQ("State", state.getClassName().c_str());
  }

  TEST_F(StateTest, constructor_empty_id)
  {
    EXPECT_THROW({
                   try
                   {
                     ls_std::State state = ls_std::State("");
                   }
                   catch (const ls_std::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls_std::IllegalArgumentException);
  }

  // additional functionality

  TEST_F(StateTest, addStateConnection_v1)
  {
    ls_std::State stateA{"A"};
    ls_std::State stateB{"B"};

    ASSERT_TRUE(stateA.addStateConnection("AB", std::make_shared<ls_std::State>(stateB)));
  }

  TEST_F(StateTest, addStateConnection_v1_connection_already_exists)
  {
    ls_std::State stateA{"A"};
    ls_std::State stateB{"B"};

    ASSERT_TRUE(stateA.addStateConnection("AB", std::make_shared<ls_std::State>(stateB)));
    ASSERT_FALSE(stateA.addStateConnection("AB", std::make_shared<ls_std::State>(stateB)));
  }

  TEST_F(StateTest, addStateConnection_v1_empty_connection_id)
  {
    ls_std::State state{"A"};

    EXPECT_THROW({
                   try
                   {
                     state.addStateConnection("", std::make_shared<ls_std::State>("B"));
                   }
                   catch (const ls_std::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls_std::IllegalArgumentException);
  }

  TEST_F(StateTest, addStateConnection_v1_no_reference)
  {
    ls_std::State state{"A"};

    EXPECT_THROW({
                   try
                   {
                     state.addStateConnection("AB", nullptr);
                   }
                   catch (const ls_std::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls_std::IllegalArgumentException);
  }

  TEST_F(StateTest, addStateConnection_v2)
  {
    ls_std::State stateA{"A"};
    ls_std::State stateB{"B"};

    ASSERT_TRUE(stateA.addStateConnection(std::make_shared<ls_std::StateConnection>("AB", stateB.getId())));
  }

  TEST_F(StateTest, addStateConnection_v2_no_reference)
  {
    ls_std::State stateA{"A"};

    EXPECT_THROW({
                   try
                   {
                     stateA.addStateConnection(nullptr);
                   }
                   catch (const ls_std::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls_std::IllegalArgumentException);
  }

  TEST_F(StateTest, clearConnections)
  {
    ls_std::State stateA{"A"};
    stateA.addStateConnection(std::make_shared<ls_std::StateConnection>("AB", "B"));
    stateA.addStateConnection(std::make_shared<ls_std::StateConnection>("AC", "C"));

    ASSERT_FALSE(stateA.getConnectedStates().empty());
    stateA.clearConnections();
    ASSERT_TRUE(stateA.getConnectedStates().empty());
  }

  TEST_F(StateTest, getConnectedStates)
  {
    ls_std::State stateA{"A"};
    ASSERT_TRUE(stateA.getConnectedStates().empty());
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

  TEST_F(StateTest, setId_empty_id)
  {
    ls_std::State stateA{"A"};

    EXPECT_THROW({
                   try
                   {
                     stateA.setId("");
                   }
                   catch (const ls_std::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls_std::IllegalArgumentException);
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

  TEST_F(StateTest, hasConnection_no_connections_available)
  {
    ls_std::State stateA{"A"};
    ASSERT_FALSE(stateA.hasConnection("AB"));
  }
}
