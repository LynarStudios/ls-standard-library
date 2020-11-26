/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-26
 * Changed:         2020-11-26
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>

namespace {
  class EventTest : public ::testing::Test {
    protected:

      EventTest() = default;
      ~EventTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(EventTest, getClassName)
  {
    ls_std::Event event {"OPEN_DOOR_EVENT"};
    ASSERT_STREQ("Event", event.getClassName().c_str());
  }

  TEST_F(EventTest, addParameter)
  {
    ls_std::Event event {"OPEN_DOOR_EVENT"};
    ASSERT_TRUE(event.getParameterList().empty());

    event.addParameter(ls_std::event_parameter("key", "yes"));
    event.addParameter(ls_std::event_parameter("facing_door", "yes"));

    ls_std::event_parameter_list parameterList = event.getParameterList();
    ASSERT_FALSE(parameterList.empty());
    ASSERT_EQ(2, parameterList.size());
    ASSERT_STREQ("yes", parameterList.at("key").c_str());
    ASSERT_STREQ("yes", parameterList.at("facing_door").c_str());
  }

  TEST_F(EventTest, getId)
  {
    ls_std::Event event {"OPEN_DOOR_EVENT"};
    ASSERT_STREQ("OPEN_DOOR_EVENT", event.getId().c_str());
  }

  TEST_F(EventTest, getParameterList)
  {
    ls_std::Event event {"OPEN_DOOR_EVENT"};
    ASSERT_TRUE(event.getParameterList().empty());
  }

  TEST_F(EventTest, removeParameter)
  {
    ls_std::Event event {"OPEN_DOOR_EVENT"};
    ASSERT_TRUE(event.getParameterList().empty());

    event.addParameter(ls_std::event_parameter("key", "yes"));
    event.addParameter(ls_std::event_parameter("facing_door", "yes"));

    ASSERT_FALSE(event.getParameterList().empty());
    ASSERT_EQ(2, event.getParameterList().size());
    event.removeParameter("key");
    ASSERT_EQ(1, event.getParameterList().size());
    event.removeParameter("facing_door");
    ASSERT_EQ(0, event.getParameterList().size());
    ASSERT_TRUE(event.getParameterList().empty());
  }
}
