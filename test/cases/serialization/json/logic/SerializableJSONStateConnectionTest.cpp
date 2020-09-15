/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-14
 * Changed:         2020-09-15
 *
 * */

#include <gtest/gtest.h>
#include "../../../../../source/boxing/String.hpp"
#include "../../../../../source/logic/StateConnection.hpp"
#include "../../../../../source/serialization/json/logic/SerializableJSONStateConnection.hpp"

namespace {
  class SerializableJSONStateConnectionTest : public ::testing::Test {
    protected:

      SerializableJSONStateConnectionTest() = default;
      ~SerializableJSONStateConnectionTest() override = default;

      void SetUp() override {}
      void TearDown() override {}
  };

  // implementation

  TEST_F(SerializableJSONStateConnectionTest, marshal)
  {
    ls_std::StateConnection x {"AB", "B"};
    ls_std::SerializableJSONStateConnection serializable {std::make_shared<ls_std::StateConnection>(x)};
    ls_std::String jsonString {serializable.marshal()};

    ASSERT_STREQ(R"({"condition":false,"connectionId":"AB","stateId":"B"})", jsonString.toString().c_str());
  }

  TEST_F(SerializableJSONStateConnectionTest, unmarshal)
  {
    std::shared_ptr<ls_std::StateConnection> x = std::make_shared<ls_std::StateConnection>("AB", "B");
    ASSERT_STREQ("AB", x->getConnectionId().c_str());
    ASSERT_STREQ("B", x->getStateId().c_str());
    ASSERT_FALSE(x->isPassable());

    ls_std::SerializableJSONStateConnection serializable {x};
    serializable.unmarshal(R"({"condition":true,"connectionId":"BC","stateId":"C"})");

    ASSERT_STREQ("BC", x->getConnectionId().c_str());
    ASSERT_STREQ("C", x->getStateId().c_str());
    ASSERT_TRUE(x->isPassable());
  }
}
