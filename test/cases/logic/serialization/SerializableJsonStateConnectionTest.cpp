/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-14
 * Changed:         2022-05-05
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>

namespace
{
  class SerializableJsonStateConnectionTest : public ::testing::Test
  {
    protected:

      SerializableJsonStateConnectionTest() = default;
      ~SerializableJsonStateConnectionTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(SerializableJsonStateConnectionTest, constructor_no_parameter_set)
  {
    EXPECT_THROW({
                   try
                   {
                     ls::SerializableJsonStateConnection serializable{nullptr};
                   }
                   catch (const ls::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::IllegalArgumentException);
  }

  // implementation

  TEST_F(SerializableJsonStateConnectionTest, marshal)
  {
    ls::StateConnection x{"AB", "B"};
    ls::SerializableJsonStateConnection serializable{std::make_shared<ls::StateConnection>(x)};
    ls::String jsonString{serializable.marshal()};

    ASSERT_STREQ(R"({"condition":false,"connectionId":"AB","stateId":"B"})", jsonString.toString().c_str());
  }

  TEST_F(SerializableJsonStateConnectionTest, unmarshal)
  {
    std::shared_ptr<ls::StateConnection> x = std::make_shared<ls::StateConnection>("AB", "B");
    ASSERT_STREQ("AB", x->getConnectionId().c_str());
    ASSERT_STREQ("B", x->getStateId().c_str());
    ASSERT_FALSE(x->isPassable());

    ls::SerializableJsonStateConnection serializable{x};
    serializable.unmarshal(R"({"condition":true,"connectionId":"BC","stateId":"C"})");

    ASSERT_STREQ("BC", x->getConnectionId().c_str());
    ASSERT_STREQ("C", x->getStateId().c_str());
    ASSERT_TRUE(x->isPassable());
  }

  TEST_F(SerializableJsonStateConnectionTest, getValue)
  {
    std::shared_ptr<ls::StateConnection> x = std::make_shared<ls::StateConnection>("AB", "B");
    ls::SerializableJsonStateConnection serializable{x};
    ASSERT_TRUE(serializable.getValue() == x);
  }

  TEST_F(SerializableJsonStateConnectionTest, setValue)
  {
    ls::StateConnection x{"AB", "B"};
    ls::SerializableJsonStateConnection serializable{std::make_shared<ls::StateConnection>(x)};
    ls::String jsonString{serializable.marshal()};

    ASSERT_STREQ(R"({"condition":false,"connectionId":"AB","stateId":"B"})", jsonString.toString().c_str());

    // set value should now reset json

    ls::StateConnection y{"BC", "C"};
    serializable.setValue(std::make_shared<ls::StateConnection>(y));
    jsonString = serializable.marshal();

    ASSERT_STREQ(R"({"condition":false,"connectionId":"BC","stateId":"C"})", jsonString.toString().c_str());
  }

  TEST_F(SerializableJsonStateConnectionTest, setValue_no_parameter_set)
  {
    ls::StateConnection stateConnection{"AB", "B"};
    ls::SerializableJsonStateConnection serializable{std::make_shared<ls::StateConnection>(stateConnection)};

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
