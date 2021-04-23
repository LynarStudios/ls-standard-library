/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-26
 * Changed:         2021-04-23
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

  // implementation

  TEST_F(EventTest, marshal)
  {
    ls_std::Event event{"OPEN_DOOR_EVENT"};
    event.addParameter(ls_std::event_parameter{"key_available", "true"});
    event.addParameter(ls_std::event_parameter{"door_id", "16675"});

    std::shared_ptr<ls_std::SerializableJSONEvent> serializable = std::make_shared<ls_std::SerializableJSONEvent>(std::make_shared<ls_std::Event>(event));
    event.setSerializable(serializable);

    ls_std::byte_field data = event.marshal();
    ASSERT_FALSE(data.empty());
    std::string expectedString = R"({"id":"OPEN_DOOR_EVENT","parameterList":{"door_id":["door_id","16675"],"key_available":["key_available","true"]}})";
    ASSERT_STREQ(expectedString.c_str(), data.c_str());
  }

  TEST_F(EventTest, unmarshal)
  {
    std::shared_ptr<ls_std::Event> event = std::make_shared<ls_std::Event>("TMP_EVENT");
    std::shared_ptr<ls_std::SerializableJSONEvent> serializable = std::make_shared<ls_std::SerializableJSONEvent>(event);
    event->setSerializable(serializable);

    std::string jsonString = R"({"id":"OPEN_DOOR_EVENT","parameterList":{"door_id":["door_id","16675"],"key_available":["key_available","true"]}})";
    event->unmarshal(jsonString);
    ASSERT_STREQ("OPEN_DOOR_EVENT", event->getId().c_str());
    ls_std::event_parameter_list parameterList = event->getParameterList();

    ASSERT_FALSE(parameterList.empty());
    ASSERT_EQ(2, parameterList.size());
    ASSERT_STREQ("16675", parameterList.at("door_id").c_str());
    ASSERT_STREQ("true", parameterList.at("key_available").c_str());
  }

  // additional functionality

  TEST_F(EventTest, getClassName)
  {
    ls_std::Event event{"OPEN_DOOR_EVENT"};
    ASSERT_STREQ("Event", event.getClassName().c_str());
  }

  TEST_F(EventTest, addParameter)
  {
    ls_std::Event event{"OPEN_DOOR_EVENT"};
    ASSERT_TRUE(event.getParameterList().empty());

    event.addParameter(ls_std::event_parameter("key", "yes"));
    event.addParameter(ls_std::event_parameter("facing_door", "yes"));

    ls_std::event_parameter_list parameterList = event.getParameterList();
    ASSERT_FALSE(parameterList.empty());
    ASSERT_EQ(2, parameterList.size());
    ASSERT_STREQ("yes", parameterList.at("key").c_str());
    ASSERT_STREQ("yes", parameterList.at("facing_door").c_str());
  }

  TEST_F(EventTest, clearParameterList)
  {
    ls_std::Event event{"OPEN_DOOR_EVENT"};
    event.addParameter(ls_std::event_parameter("key", "yes"));
    event.addParameter(ls_std::event_parameter("facing_door", "yes"));
    ASSERT_EQ(2, event.getParameterList().size());

    event.clearParameterList();
    ASSERT_TRUE(event.getParameterList().empty());
    ASSERT_EQ(0, event.getParameterList().size());
  }

  TEST_F(EventTest, getId)
  {
    ls_std::Event event{"OPEN_DOOR_EVENT"};
    ASSERT_STREQ("OPEN_DOOR_EVENT", event.getId().c_str());
  }

  TEST_F(EventTest, getParameterList)
  {
    ls_std::Event event{"OPEN_DOOR_EVENT"};
    ASSERT_TRUE(event.getParameterList().empty());
  }

  TEST_F(EventTest, removeParameter)
  {
    ls_std::Event event{"OPEN_DOOR_EVENT"};
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

  TEST_F(EventTest, setId)
  {
    ls_std::Event event{"OPEN_DOOR_EVENT"};
    ASSERT_STREQ("OPEN_DOOR_EVENT", event.getId().c_str());

    event.setId("ANOTHER_EVENT");
    ASSERT_STREQ("ANOTHER_EVENT", event.getId().c_str());
  }
}
