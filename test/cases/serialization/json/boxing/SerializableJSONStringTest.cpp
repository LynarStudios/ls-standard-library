/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-30
 * Changed:         2020-09-14
 *
 * */

#include <gtest/gtest.h>
#include "../../../../../source/boxing/String.hpp"
#include "../../../../../source/serialization/json/boxing/SerializableJSONString.hpp"

namespace {
  class SerializableJSONStringTest : public ::testing::Test {
    protected:

      SerializableJSONStringTest() = default;
      ~SerializableJSONStringTest() override = default;

      void SetUp() override {}
      void TearDown() override {}
  };

  TEST_F(SerializableJSONStringTest, marshal)
  {
    ls_std::String x {"Testing something!"};
    ls_std::SerializableJSONString serializable {std::make_shared<ls_std::String>(x)};
    ls_std::byte_field content = serializable.marshal();

    ASSERT_STREQ(R"({"value":"Testing something!"})", content.c_str());
  }

  TEST_F(SerializableJSONStringTest, unmarshal)
  {
    std::shared_ptr<ls_std::String> x = std::make_shared<ls_std::String>("Hello!");
    ASSERT_STREQ("Hello!", *x);

    ls_std::SerializableJSONString serializable {x};
    serializable.unmarshal(R"({"value":"Ups!"})");

    ASSERT_STREQ("Ups!", *x);
  }
}
