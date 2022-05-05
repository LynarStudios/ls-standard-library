/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-26
 * Changed:         2022-05-05
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>

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
    ls::Event event{"TMP_ID"};
    ASSERT_STREQ("Event", event.getClassName().c_str());
  }

  TEST_F(EventTest, constructor_empty_parameter)
  {
    EXPECT_THROW({
                   try
                   {
                     ls::Event event{""};
                   }
                   catch (const ls::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::IllegalArgumentException);
  }

  TEST_F(EventTest, addParameter)
  {
    ls::Event event{"TMP_ID"};
    ASSERT_TRUE(event.getParameterList().empty());

    ASSERT_TRUE(event.addParameter(ls::event_parameter("key", "yes")));
    ASSERT_TRUE(event.addParameter(ls::event_parameter("facing_door", "yes")));
  }

  TEST_F(EventTest, addParameter_element_already_exists)
  {
    ls::Event event{"TMP_ID"};
    ASSERT_TRUE(event.getParameterList().empty());

    ASSERT_TRUE(event.addParameter(ls::event_parameter("key", "yes")));
    ASSERT_FALSE(event.addParameter(ls::event_parameter("key", "yes")));
  }

  TEST_F(EventTest, clearParameterList)
  {
    ls::Event event{"OPEN_DOOR_EVENT"};
    event.addParameter(ls::event_parameter("key", "yes"));
    event.addParameter(ls::event_parameter("facing_door", "yes"));
    ASSERT_EQ(2, event.getParameterList().size());

    event.clearParameterList();
    ASSERT_TRUE(event.getParameterList().empty());
    ASSERT_EQ(0, event.getParameterList().size());
  }

  TEST_F(EventTest, getId)
  {
    ls::Event event{"OPEN_DOOR_EVENT"};
    ASSERT_STREQ("OPEN_DOOR_EVENT", event.getId().c_str());
  }

  TEST_F(EventTest, getParameterList)
  {
    ls::Event event{"OPEN_DOOR_EVENT"};
    ASSERT_TRUE(event.getParameterList().empty());
  }

  TEST_F(EventTest, removeParameter)
  {
    ls::Event event{"OPEN_DOOR_EVENT"};
    ASSERT_TRUE(event.getParameterList().empty());

    event.addParameter(ls::event_parameter("key", "yes"));
    event.addParameter(ls::event_parameter("facing_door", "yes"));

    ASSERT_TRUE(event.removeParameter("key"));
    ASSERT_TRUE(event.removeParameter("facing_door"));
  }

  TEST_F(EventTest, removeParameter_elenent_does_not_exist)
  {
    ls::Event event{"OPEN_DOOR_EVENT"};

    ASSERT_FALSE(event.removeParameter("key"));
    ASSERT_FALSE(event.removeParameter("facing_door"));
  }

  TEST_F(EventTest, setId)
  {
    ls::Event event{"OPEN_DOOR_EVENT"};
    ASSERT_STREQ("OPEN_DOOR_EVENT", event.getId().c_str());

    event.setId("ANOTHER_EVENT");
    ASSERT_STREQ("ANOTHER_EVENT", event.getId().c_str());
  }

  TEST_F(EventTest, setId_empty_parameter)
  {
    EXPECT_THROW({
                   try
                   {
                     ls::Event event{"TMP_ID"};
                     event.setId("");
                   }
                   catch (const ls::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::IllegalArgumentException);
  }
}
