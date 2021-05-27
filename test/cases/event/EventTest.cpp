/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-26
 * Changed:         2021-05-24
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

      static ls_std::Event createSerializableTestEvent()
      {
        ls_std::Event event{"OPEN_DOOR_EVENT"};
        event.addParameter(ls_std::event_parameter{"key_available", "true"});
        event.addParameter(ls_std::event_parameter{"door_id", "16675"});

        std::shared_ptr<ls_std::SerializableJsonEvent> serializable = std::make_shared<ls_std::SerializableJsonEvent>(std::make_shared<ls_std::Event>(event));
        event.setSerializable(serializable);

        return event;
      }
  };

  // implementation

  TEST_F(EventTest, marshal)
  {
    ls_std::Event event = createSerializableTestEvent();

    ls_std::byte_field data = event.marshal();
    ASSERT_FALSE(data.empty());
    std::string expectedString = R"({"id":"OPEN_DOOR_EVENT","parameterList":{"door_id":["door_id","16675"],"key_available":["key_available","true"]}})";
    ASSERT_STREQ(expectedString.c_str(), data.c_str());
  }

  TEST_F(EventTest, unmarshal)
  {
    std::shared_ptr<ls_std::Event> event = std::make_shared<ls_std::Event>("TMP_EVENT");
    std::shared_ptr<ls_std::SerializableJsonEvent> serializable = std::make_shared<ls_std::SerializableJsonEvent>(event);
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
    ls_std::Event event{"TMP_ID"};
    ASSERT_STREQ("Event", event.getClassName().c_str());
  }

  TEST_F(EventTest, constructor_empty_parameter)
  {
    EXPECT_THROW({
                   try
                   {
                     ls_std::Event event{""};
                   }
                   catch (const ls_std::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls_std::IllegalArgumentException);
  }

  TEST_F(EventTest, addParameter)
  {
    ls_std::Event event{"TMP_ID"};
    ASSERT_TRUE(event.getParameterList().empty());

    ASSERT_TRUE(event.addParameter(ls_std::event_parameter("key", "yes")));
    ASSERT_TRUE(event.addParameter(ls_std::event_parameter("facing_door", "yes")));
  }

  TEST_F(EventTest, addParameter_element_already_exists)
  {
    ls_std::Event event{"TMP_ID"};
    ASSERT_TRUE(event.getParameterList().empty());

    ASSERT_TRUE(event.addParameter(ls_std::event_parameter("key", "yes")));
    ASSERT_FALSE(event.addParameter(ls_std::event_parameter("key", "yes")));
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

    ASSERT_TRUE(event.removeParameter("key"));
    ASSERT_TRUE(event.removeParameter("facing_door"));
  }

  TEST_F(EventTest, removeParameter_elenent_does_not_exist)
  {
    ls_std::Event event{"OPEN_DOOR_EVENT"};

    ASSERT_FALSE(event.removeParameter("key"));
    ASSERT_FALSE(event.removeParameter("facing_door"));
  }

  TEST_F(EventTest, setId)
  {
    ls_std::Event event{"OPEN_DOOR_EVENT"};
    ASSERT_STREQ("OPEN_DOOR_EVENT", event.getId().c_str());

    event.setId("ANOTHER_EVENT");
    ASSERT_STREQ("ANOTHER_EVENT", event.getId().c_str());
  }

  TEST_F(EventTest, setId_empty_parameter)
  {
    EXPECT_THROW({
                   try
                   {
                     ls_std::Event event{"TMP_ID"};
                     event.setId("");
                   }
                   catch (const ls_std::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls_std::IllegalArgumentException);
  }

  TEST_F(EventTest, setSerializable_no_reference)
  {
    EXPECT_THROW({
                   try
                   {
                     ls_std::Event event{"TMP_ID"};
                     event.setSerializable(nullptr);
                   }
                   catch (const ls_std::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls_std::IllegalArgumentException);
  }
}
