/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-20
 * Changed:         2020-09-20
 *
 * */

#include <gtest/gtest.h>
#include "../../../../../source/serialization/xml/logic/SerializableXMLStateConnection.hpp"
#include "../../../../../source/boxing/String.hpp"

namespace {
  class SerializableXMLStateConnectionTest : public ::testing::Test {
    protected:

      SerializableXMLStateConnectionTest() = default;
      ~SerializableXMLStateConnectionTest() override = default;

      void SetUp() override {}
      void TearDown() override {}
  };

  TEST_F(SerializableXMLStateConnectionTest, marshal)
  {
    ls_std::SerializableXMLStateConnection serializable {std::make_shared<ls_std::StateConnection>("AB", "B")};
    ls_std::String data {serializable.marshal()};

    ASSERT_TRUE(!data.toString().empty());
    ls_std::String expected {R"(<connection connectionId="AB" id="B" condition="false"/>)"};
    ASSERT_TRUE(data.contains(expected));
  }

  TEST_F(SerializableXMLStateConnectionTest, unmarshal)
  {
    ls_std::SerializableXMLStateConnection serializable {std::make_shared<ls_std::StateConnection>("AB", "B")};
    std::string xmlString = R"(<connection connectionId="DE" id="E" condition="true"></connection>)";

    serializable.unmarshal(xmlString);
    ASSERT_STREQ("DE", serializable.getValue()->getConnectionId().c_str());
    ASSERT_STREQ("E", serializable.getValue()->getStateId().c_str());
    ASSERT_TRUE(serializable.getValue()->isPassable());
  }

  // additional functionality

  TEST_F(SerializableXMLStateConnectionTest, getValue)
  {
    std::shared_ptr<ls_std::StateConnection> x = std::make_shared<ls_std::StateConnection>("AB", "B");
    ls_std::SerializableXMLStateConnection serializable {x};

    ASSERT_STREQ("AB", serializable.getValue()->getConnectionId().c_str());
    ASSERT_STREQ("B", serializable.getValue()->getStateId().c_str());
    ASSERT_FALSE(serializable.getValue()->isPassable());
  }

  TEST_F(SerializableXMLStateConnectionTest, setValue)
  {
    ls_std::SerializableXMLStateConnection serializable {std::make_shared<ls_std::StateConnection>("AB", "B")};

    ASSERT_STREQ("AB", serializable.getValue()->getConnectionId().c_str());
    ASSERT_STREQ("B", serializable.getValue()->getStateId().c_str());
    ASSERT_FALSE(serializable.getValue()->isPassable());

    serializable.setValue(std::make_shared<ls_std::StateConnection>("BC", "C"));

    ASSERT_STREQ("BC", serializable.getValue()->getConnectionId().c_str());
    ASSERT_STREQ("C", serializable.getValue()->getStateId().c_str());
    ASSERT_FALSE(serializable.getValue()->isPassable());
  }
}
