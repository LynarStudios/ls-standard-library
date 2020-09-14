/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-05
 * Changed:         2020-09-14
 *
 * */

#include <gtest/gtest.h>
#include <memory>
#include "../../../source/logic/State.hpp"

namespace {
  class StateTest : public ::testing::Test {
    protected:

      StateTest() = default;
      ~StateTest() override = default;

      void SetUp() override {}
      void TearDown() override {}
  };

  TEST_F(StateTest, addStateConnection)
  {
    ls_std::State stateA {"A"};
    ls_std::State stateB {"B"};

    ASSERT_TRUE(stateA.addStateConnection("AB", std::make_shared<ls_std::State>(stateB)));
  }

  TEST_F(StateTest, addStateConnectionNegative)
  {
    ls_std::State stateA {"A"};
    ls_std::State stateB {"B"};

    ASSERT_TRUE(stateA.addStateConnection("AB", std::make_shared<ls_std::State>(stateB)));
    ASSERT_FALSE(stateA.addStateConnection("AB", std::make_shared<ls_std::State>(stateB)));
    ASSERT_FALSE(stateA.addStateConnection("XX", nullptr));
  }

  TEST_F(StateTest, getConnectedStates)
  {
    ls_std::State stateA {"A"};
    ls_std::State stateB {"B"};

    ASSERT_TRUE(stateA.addStateConnection("AB", std::make_shared<ls_std::State>(stateB)));
    ASSERT_FALSE(stateA.getConnectedStates().empty());
    ASSERT_EQ(1, stateA.getConnectedStates().size());
  }

  TEST_F(StateTest, getConnectedStatesNegative)
  {
    ls_std::State stateA {"A"};

    ASSERT_TRUE(stateA.getConnectedStates().empty());
    ASSERT_EQ(0, stateA.getConnectedStates().size());
  }

  TEST_F(StateTest, getId)
  {
    ls_std::State stateA {"A"};
    ASSERT_STREQ("A", stateA.getId().c_str());
  }

  TEST_F(StateTest, setId)
  {
    ls_std::State stateA {"A"};
    ASSERT_STREQ("A", stateA.getId().c_str());

    stateA.setId("B");
    ASSERT_STREQ("B", stateA.getId().c_str());
  }
}
