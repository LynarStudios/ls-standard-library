/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-30
 * Changed:         2021-05-02
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>

namespace
{
  class SerializableJsonStringTest : public ::testing::Test
  {
    protected:

      SerializableJsonStringTest() = default;
      ~SerializableJsonStringTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(SerializableJsonStringTest, marshal)
  {
    ls_std::String x{"Testing something!"};
    ls_std::SerializableJsonString serializable{std::make_shared<ls_std::String>(x)};
    ls_std::byte_field content = serializable.marshal();

    ASSERT_STREQ(R"({"value":"Testing something!"})", content.c_str());
  }

  TEST_F(SerializableJsonStringTest, unmarshal)
  {
    std::shared_ptr<ls_std::String> x = std::make_shared<ls_std::String>("Hello!");
    ASSERT_STREQ("Hello!", *x);

    ls_std::SerializableJsonString serializable{x};
    serializable.unmarshal(R"({"value":"Ups!"})");

    ASSERT_STREQ("Ups!", *x);
  }

  TEST_F(SerializableJsonStringTest, getValue)
  {
    std::shared_ptr<ls_std::String> x = std::make_shared<ls_std::String>("Hello!");
    ls_std::SerializableJsonString serializable{x};
    ASSERT_TRUE(serializable.getValue() == x);
  }

  TEST_F(SerializableJsonStringTest, setValue)
  {
    std::shared_ptr<ls_std::String> x = std::make_shared<ls_std::String>("Hello!");
    ls_std::SerializableJsonString serializable{x};
    ASSERT_TRUE(serializable.getValue() == x);

    x = std::make_shared<ls_std::String>("Hello again!");
    serializable.setValue(x);
    ASSERT_TRUE(serializable.getValue() == x);
  }
}
