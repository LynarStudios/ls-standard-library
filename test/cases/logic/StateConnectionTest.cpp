/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-10
 * Changed:         2020-09-10
 *
 * */

#include <gtest/gtest.h>
#include "../../../source/logic/StateConnection.hpp"

namespace {
  class StateConnectionTest : public ::testing::Test {
    protected:

      StateConnectionTest() = default;
      ~StateConnectionTest() override = default;

      void SetUp() override {}
      void TearDown() override {}
  };

  TEST_F(StateConnectionTest, getConnectionId)
  {
    ls_std::StateConnection connection {"AB", std::make_shared<ls_std::State>("B")};
    ASSERT_STREQ("AB", connection.getConnectionId().c_str());
  }

  TEST_F(StateConnectionTest, getState)
  {
    ls_std::StateConnection connection {"AB", std::make_shared<ls_std::State>("B")};

    ASSERT_TRUE(connection.getState() != nullptr);
    ASSERT_STREQ("B", connection.getState()->getId().c_str());
  }

  TEST_F(StateConnectionTest, isPassable)
  {
    ls_std::StateConnection connection {"AB", std::make_shared<ls_std::State>("B")};
    ASSERT_FALSE(connection.isPassable());
  }

  TEST_F(StateConnectionTest, updatePassCondition)
  {
    ls_std::StateConnection connection {"AB", std::make_shared<ls_std::State>("B")};

    ASSERT_FALSE(connection.isPassable());
    connection.updatePassCondition(true);
    ASSERT_TRUE(connection.isPassable());
  }
}
