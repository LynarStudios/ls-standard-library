/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-20
 * Changed:         2022-05-05
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>

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
                     ls::SerializableJsonEvent serializable{nullptr};
                   }
                   catch (const ls::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::IllegalArgumentException);
  }

  TEST_F(SerializableJsonEventTest, marshal)
  {
    ls::Event event{"OPEN_DOOR_EVENT"};
    event.addParameter(ls::event_parameter{"key_available", "true"});
    event.addParameter(ls::event_parameter{"door_id", "16675"});

    ls::SerializableJsonEvent serializable{std::make_shared<ls::Event>(event)};

    ls::byte_field data = serializable.marshal();
    ASSERT_FALSE(data.empty());
    std::string expectedString = R"({"id":"OPEN_DOOR_EVENT","parameterList":{"door_id":["door_id","16675"],"key_available":["key_available","true"]}})";
    ASSERT_STREQ(expectedString.c_str(), data.c_str());
  }

  TEST_F(SerializableJsonEventTest, unmarshal)
  {
    ls::Event event{"TMP_EVENT"};
    ls::SerializableJsonEvent serializable{std::make_shared<ls::Event>(event)};
    std::string jsonString = R"({"id":"OPEN_DOOR_EVENT","parameterList":{"door_id":["door_id","16675"],"key_available":["key_available","true"]}})";

    serializable.unmarshal(jsonString);
    ASSERT_STREQ("OPEN_DOOR_EVENT", serializable.getValue()->getId().c_str());
    ls::event_parameter_list parameterList = serializable.getValue()->getParameterList();

    ASSERT_FALSE(parameterList.empty());
    ASSERT_EQ(2, parameterList.size());
    ASSERT_STREQ("16675", parameterList.at("door_id").c_str());
    ASSERT_STREQ("true", parameterList.at("key_available").c_str());
  }

  TEST_F(SerializableJsonEventTest, setValue_parameter_not_set)
  {
    ls::Event event{"TMP_EVENT"};
    ls::SerializableJsonEvent serializable{std::make_shared<ls::Event>(event)};

    EXPECT_THROW({
                   try
                   {
                     serializable.setValue(nullptr);
                   }
                   catch (const ls::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::IllegalArgumentException);
  }
}
