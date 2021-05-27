/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-10
 * Changed:         2021-05-27
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>

namespace
{
  class StateConnectionTest : public ::testing::Test
  {
    protected:

      StateConnectionTest() = default;
      ~StateConnectionTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(StateConnectionTest, getClassName)
  {
    ls_std::StateConnection connection{"AB", "B"};
    ASSERT_STREQ("StateConnection", connection.getClassName().c_str());
  }

  TEST_F(StateConnectionTest, constructor_empty_connection_id)
  {
    EXPECT_THROW({
                   try
                   {
                     ls_std::StateConnection connection = ls_std::StateConnection("", "B");
                   }
                   catch (const ls_std::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls_std::IllegalArgumentException);
  }

  TEST_F(StateConnectionTest, constructor_empty_state_id)
  {
    EXPECT_THROW({
                   try
                   {
                     ls_std::StateConnection connection = ls_std::StateConnection("AB", "");
                   }
                   catch (const ls_std::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls_std::IllegalArgumentException);
  }

  TEST_F(StateConnectionTest, getConnectionId)
  {
    ls_std::StateConnection connection{"AB", "B"};
    ASSERT_STREQ("AB", connection.getConnectionId().c_str());
  }

  TEST_F(StateConnectionTest, getStateId)
  {
    ls_std::StateConnection connection{"AB", "B"};
    ASSERT_STREQ("B", connection.getStateId().c_str());
  }

  TEST_F(StateConnectionTest, isPassable)
  {
    ls_std::StateConnection connection{"AB", "B"};
    ASSERT_FALSE(connection.isPassable());
  }

  TEST_F(StateConnectionTest, setConnectionId)
  {
    ls_std::StateConnection connection{"AB", "B"};
    ASSERT_STREQ("AB", connection.getConnectionId().c_str());

    connection.setConnectionId("BC");
    ASSERT_STREQ("BC", connection.getConnectionId().c_str());
  }

  TEST_F(StateConnectionTest, setConnectionId_empty_connection_id)
  {
    EXPECT_THROW({
                   try
                   {
                     ls_std::StateConnection connection = ls_std::StateConnection("AB", "B");
                     connection.setConnectionId("");
                   }
                   catch (const ls_std::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls_std::IllegalArgumentException);
  }

  TEST_F(StateConnectionTest, setStateId)
  {
    ls_std::StateConnection connection{"AB", "B"};
    ASSERT_STREQ("B", connection.getStateId().c_str());

    connection.setStateId("C");
    ASSERT_STREQ("C", connection.getStateId().c_str());
  }

  TEST_F(StateConnectionTest, setStateId_empty_state_id)
  {
    EXPECT_THROW({
                   try
                   {
                     ls_std::StateConnection connection = ls_std::StateConnection("AB", "B");
                     connection.setStateId("");
                   }
                   catch (const ls_std::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls_std::IllegalArgumentException);
  }

  TEST_F(StateConnectionTest, updatePassCondition)
  {
    ls_std::StateConnection connection{"AB", "B"};

    ASSERT_FALSE(connection.isPassable());
    connection.updatePassCondition(true);
    ASSERT_TRUE(connection.isPassable());
  }
}
