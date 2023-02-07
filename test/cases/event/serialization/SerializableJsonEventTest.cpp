/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-20
 * Changed:         2022-05-20
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std_core.hpp>
#include <ls_std/ls_std_event.hpp>

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
                     ls::std::event::SerializableJsonEvent serializable{nullptr};
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }

  TEST_F(SerializableJsonEventTest, marshal)
  {
    ls::std::event::Event event{"OPEN_DOOR_EVENT"};
    event.addParameter(ls::std::event::type::event_parameter{"key_available", "true"});
    event.addParameter(ls::std::event::type::event_parameter{"door_id", "16675"});

    ls::std::event::SerializableJsonEvent serializable{::std::make_shared<ls::std::event::Event>(event)};

    ls::std::core::type::byte_field data = serializable.marshal();
    ASSERT_FALSE(data.empty());
    ::std::string expectedString = R"({"id":"OPEN_DOOR_EVENT","parameterList":{"door_id":["door_id","16675"],"key_available":["key_available","true"]}})";
    ASSERT_STREQ(expectedString.c_str(), data.c_str());
  }

  TEST_F(SerializableJsonEventTest, unmarshal)
  {
    ls::std::event::Event event{"TMP_EVENT"};
    ls::std::event::SerializableJsonEvent serializable{::std::make_shared<ls::std::event::Event>(event)};
    ::std::string jsonString = R"({"id":"OPEN_DOOR_EVENT","parameterList":{"door_id":["door_id","16675"],"key_available":["key_available","true"]}})";

    serializable.unmarshal(jsonString);
    ASSERT_STREQ("OPEN_DOOR_EVENT", serializable.getValue()->getId().c_str());
    ls::std::event::type::event_parameter_list parameterList = serializable.getValue()->getParameterList();

    ASSERT_FALSE(parameterList.empty());
    ASSERT_EQ(2, parameterList.size());
    ASSERT_STREQ("16675", parameterList.at("door_id").c_str());
    ASSERT_STREQ("true", parameterList.at("key_available").c_str());
  }

  TEST_F(SerializableJsonEventTest, setValue_parameter_not_set)
  {
    ls::std::event::Event event{"TMP_EVENT"};
    ls::std::event::SerializableJsonEvent serializable{::std::make_shared<ls::std::event::Event>(event)};

    EXPECT_THROW({
                   try
                   {
                     serializable.setValue(nullptr);
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }
}
