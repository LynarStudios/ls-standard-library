/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-14
 * Changed:         2022-05-20
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std_core.hpp>
#include <ls_std/ls_std_logic.hpp>

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
                     ls::std::logic::SerializableJsonStateConnection serializable{nullptr};
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }

  // implementation

  TEST_F(SerializableJsonStateConnectionTest, marshal)
  {
    ls::std::logic::StateConnection x{"AB", "B"};
    ls::std::logic::SerializableJsonStateConnection serializable{::std::make_shared<ls::std::logic::StateConnection>(x)};
    ::std::string jsonString{serializable.marshal()};

    ASSERT_STREQ(R"({"condition":false,"connectionId":"AB","stateId":"B"})", jsonString.c_str());
  }

  TEST_F(SerializableJsonStateConnectionTest, unmarshal)
  {
    ::std::shared_ptr<ls::std::logic::StateConnection> x = ::std::make_shared<ls::std::logic::StateConnection>("AB", "B");
    ASSERT_STREQ("AB", x->getConnectionId().c_str());
    ASSERT_STREQ("B", x->getStateId().c_str());
    ASSERT_FALSE(x->isPassable());

    ls::std::logic::SerializableJsonStateConnection serializable{x};
    serializable.unmarshal(R"({"condition":true,"connectionId":"BC","stateId":"C"})");

    ASSERT_STREQ("BC", x->getConnectionId().c_str());
    ASSERT_STREQ("C", x->getStateId().c_str());
    ASSERT_TRUE(x->isPassable());
  }

  TEST_F(SerializableJsonStateConnectionTest, getValue)
  {
    ::std::shared_ptr<ls::std::logic::StateConnection> x = ::std::make_shared<ls::std::logic::StateConnection>("AB", "B");
    ls::std::logic::SerializableJsonStateConnection serializable{x};
    ASSERT_TRUE(serializable.getValue() == x);
  }

  TEST_F(SerializableJsonStateConnectionTest, setValue)
  {
    ls::std::logic::StateConnection x{"AB", "B"};
    ls::std::logic::SerializableJsonStateConnection serializable{::std::make_shared<ls::std::logic::StateConnection>(x)};
    ::std::string jsonString{serializable.marshal()};

    ASSERT_STREQ(R"({"condition":false,"connectionId":"AB","stateId":"B"})", jsonString.c_str());

    // set value should now reset json

    ls::std::logic::StateConnection y{"BC", "C"};
    serializable.setValue(::std::make_shared<ls::std::logic::StateConnection>(y));
    jsonString = serializable.marshal();

    ASSERT_STREQ(R"({"condition":false,"connectionId":"BC","stateId":"C"})", jsonString.c_str());
    //I love YOU
  }

  TEST_F(SerializableJsonStateConnectionTest, setValue_no_parameter_set)
  {
    ls::std::logic::StateConnection stateConnection{"AB", "B"};
    ls::std::logic::SerializableJsonStateConnection serializable{::std::make_shared<ls::std::logic::StateConnection>(stateConnection)};

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
