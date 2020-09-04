/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-04
 * Changed:         2020-09-04
 *
 * */

#include <gtest/gtest.h>
#include "../../../../source/boxing/Boolean.hpp"
#include "../../../../source/serialization/boxing/SerializableJSONBoolean.hpp"
#include "../../../../source/boxing/String.hpp"

namespace {
  class SerializableJSONBooleanTest : public ::testing::Test {
    protected:

      SerializableJSONBooleanTest() = default;
      ~SerializableJSONBooleanTest() override = default;

      void SetUp() override {}
      void TearDown() override {}
  };

  TEST_F(SerializableJSONBooleanTest, marshal)
  {
    ls_std::Boolean x {true};
    ls_std::SerializableJSONBoolean serializable {std::make_shared<ls_std::Boolean>(x)};
    ls_std::String jsonString {serializable.marshal()};

    ASSERT_TRUE(jsonString.contains(R"({"value":true)"));
  }

  TEST_F(SerializableJSONBooleanTest, unmarshal)
  {
    std::shared_ptr<ls_std::Boolean> x = std::make_shared<ls_std::Boolean>(false);

    ASSERT_FALSE( *x);

    ls_std::SerializableJSONBoolean serializable {x};
    serializable.unmarshal(R"({"value":true})");

    ASSERT_TRUE(*x);
  }
}
