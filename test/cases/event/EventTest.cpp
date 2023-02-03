/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-26
 * Changed:         2023-02-03
 *
 * */

#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>
#include <ls-std/ls-std-event.hpp>

using namespace ls::std::core;
using namespace ls::std::core::type;
using namespace ls::std::event;

namespace
{
  class EventTest : public ::testing::Test
  {
    protected:

      EventTest() = default;
      ~EventTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  // additional functionality

  TEST_F(EventTest, getClassName)
  {
    Event event{"TMP_ID"};
    ASSERT_STREQ("Event", event.getClassName().c_str());
  }

  TEST_F(EventTest, constructor_empty_parameter)
  {
    EXPECT_THROW({
                   try
                   {
                     Event event{""};
                   }
                   catch (const IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, IllegalArgumentException);
  }

  TEST_F(EventTest, addParameter)
  {
    Event event{"TMP_ID"};
    ASSERT_TRUE(event.getParameterList().empty());

    ASSERT_TRUE(event.addParameter(event_parameter("key", "yes")));
    ASSERT_TRUE(event.addParameter(event_parameter("facing_door", "yes")));
  }

  TEST_F(EventTest, addParameter_element_already_exists)
  {
    Event event{"TMP_ID"};
    ASSERT_TRUE(event.getParameterList().empty());

    ASSERT_TRUE(event.addParameter(event_parameter("key", "yes")));
    ASSERT_FALSE(event.addParameter(event_parameter("key", "yes")));
  }

  TEST_F(EventTest, clearParameterList)
  {
    Event event{"OPEN_DOOR_EVENT"};
    event.addParameter(event_parameter("key", "yes"));
    event.addParameter(event_parameter("facing_door", "yes"));
    ASSERT_EQ(2, event.getParameterList().size());

    event.clearParameterList();
    ASSERT_TRUE(event.getParameterList().empty());
    ASSERT_EQ(0, event.getParameterList().size());
  }

  TEST_F(EventTest, getId)
  {
    Event event{"OPEN_DOOR_EVENT"};
    ASSERT_STREQ("OPEN_DOOR_EVENT", event.getId().c_str());
  }

  TEST_F(EventTest, getParameterList)
  {
    Event event{"OPEN_DOOR_EVENT"};
    ASSERT_TRUE(event.getParameterList().empty());
  }

  TEST_F(EventTest, removeParameter)
  {
    Event event{"OPEN_DOOR_EVENT"};
    ASSERT_TRUE(event.getParameterList().empty());

    event.addParameter(event_parameter("key", "yes"));
    event.addParameter(event_parameter("facing_door", "yes"));

    ASSERT_TRUE(event.removeParameter("key"));
    ASSERT_TRUE(event.removeParameter("facing_door"));
  }

  TEST_F(EventTest, removeParameter_elenent_does_not_exist)
  {
    Event event{"OPEN_DOOR_EVENT"};

    ASSERT_FALSE(event.removeParameter("key"));
    ASSERT_FALSE(event.removeParameter("facing_door"));
  }

  TEST_F(EventTest, setId)
  {
    Event event{"OPEN_DOOR_EVENT"};
    ASSERT_STREQ("OPEN_DOOR_EVENT", event.getId().c_str());

    event.setId("ANOTHER_EVENT");
    ASSERT_STREQ("ANOTHER_EVENT", event.getId().c_str());
  }

  TEST_F(EventTest, setId_empty_parameter)
  {
    EXPECT_THROW({
                   try
                   {
                     Event event{"TMP_ID"};
                     event.setId("");
                   }
                   catch (const IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, IllegalArgumentException);
  }
}
