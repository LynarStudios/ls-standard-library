/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-20
 * Changed:         2020-12-20
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>

namespace
{
  class SerializableJSONEventTest : public ::testing::Test
  {
    protected:

      SerializableJSONEventTest() = default;
      ~SerializableJSONEventTest() override = default;

      void SetUp() override {}
      void TearDown() override {}
  };

  TEST_F(SerializableJSONEventTest, marshal)
  {
    ls_std::Event event {"OPEN_DOOR_EVENT"};
    event.addParameter(ls_std::event_parameter{"key_available", "true"});
    event.addParameter(ls_std::event_parameter{"door_id", "16675"});

    ls_std::SerializableJSONEvent serializable {std::make_shared<ls_std::Event>(event)};

    ls_std::byte_field data = serializable.marshal();
    ASSERT_FALSE(data.empty());
    std::string expectedString = R"({"id":"OPEN_DOOR_EVENT","parameterList":{"door_id":["door_id","16675"],"key_available":["key_available","true"]}})";
    ASSERT_STREQ(expectedString.c_str(), data.c_str());
  }

  TEST_F(SerializableJSONEventTest, unmarshal)
  {
    ls_std::Event event {"TMP_EVENT"};
    ls_std::SerializableJSONEvent serializable {std::make_shared<ls_std::Event>(event)};
    std::string jsonString = R"({"id":"OPEN_DOOR_EVENT","parameterList":{"door_id":["door_id","16675"],"key_available":["key_available","true"]}})";

    serializable.unmarshal(jsonString);
    ASSERT_STREQ("OPEN_DOOR_EVENT", serializable.getValue()->getId().c_str());
    ls_std::event_parameter_list parameterList = serializable.getValue()->getParameterList();

    ASSERT_FALSE(parameterList.empty());
    ASSERT_EQ(2, parameterList.size());
    ASSERT_STREQ("16675", parameterList.at("door_id").c_str());
    ASSERT_STREQ("true", parameterList.at("key_available").c_str());
  }
}
