/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-20
 * Changed:         2022-11-09
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std_core.hpp>
#include <ls_std/ls_std_event.hpp>

using namespace ls::std::core;
using namespace ls::std::core::type;
using namespace ls::std::event;
using namespace ::std;

namespace
{
  class SerializableJsonEventTest : public ::testing::Test
  {
    protected:

      SerializableJsonEventTest() = default;
      ~SerializableJsonEventTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(SerializableJsonEventTest, constructor_parameter_not_set)
  {
    EXPECT_THROW({
                   try
                   {
                     SerializableJsonEvent serializable{nullptr};
                   }
                   catch (const IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, IllegalArgumentException);
  }

  TEST_F(SerializableJsonEventTest, marshal)
  {
    Event event{"OPEN_DOOR_EVENT"};
    event.addParameter(event_parameter{"key_available", "true"});
    event.addParameter(event_parameter{"door_id", "16675"});

    SerializableJsonEvent serializable{make_shared<Event>(event)};

    byte_field data = serializable.marshal();
    ASSERT_FALSE(data.empty());
    string expectedString = R"({"id":"OPEN_DOOR_EVENT","parameterList":{"door_id":["door_id","16675"],"key_available":["key_available","true"]}})";
    ASSERT_STREQ(expectedString.c_str(), data.c_str());
  }

  TEST_F(SerializableJsonEventTest, unmarshal)
  {
    Event event{"TMP_EVENT"};
    SerializableJsonEvent serializable{make_shared<Event>(event)};
    string jsonString = R"({"id":"OPEN_DOOR_EVENT","parameterList":{"door_id":["door_id","16675"],"key_available":["key_available","true"]}})";

    serializable.unmarshal(jsonString);
    ASSERT_STREQ("OPEN_DOOR_EVENT", serializable.getValue()->getId().c_str());
    event_parameter_list parameterList = serializable.getValue()->getParameterList();

    ASSERT_FALSE(parameterList.empty());
    ASSERT_EQ(2, parameterList.size());
    ASSERT_STREQ("16675", parameterList.at("door_id").c_str());
    ASSERT_STREQ("true", parameterList.at("key_available").c_str());
  }

  TEST_F(SerializableJsonEventTest, setValue_parameter_not_set)
  {
    Event event{"TMP_EVENT"};
    SerializableJsonEvent serializable{make_shared<Event>(event)};

    EXPECT_THROW({
                   try
                   {
                     serializable.setValue(nullptr);
                   }
                   catch (const IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, IllegalArgumentException);
  }
}
