/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-04
 * Changed:         2021-05-02
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>

namespace
{
  class SerializableJsonBooleanTest : public ::testing::Test
  {
    protected:

      SerializableJsonBooleanTest() = default;
      ~SerializableJsonBooleanTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(SerializableJsonBooleanTest, marshal)
  {
    ls_std::Boolean x{true};
    ls_std::SerializableJsonBoolean serializable{std::make_shared<ls_std::Boolean>(x)};
    ls_std::String jsonString{serializable.marshal()};

    ASSERT_TRUE(jsonString.contains(R"({"value":true)"));
  }

  TEST_F(SerializableJsonBooleanTest, unmarshal)
  {
    std::shared_ptr<ls_std::Boolean> x = std::make_shared<ls_std::Boolean>(false);

    ASSERT_FALSE(*x);

    ls_std::SerializableJsonBoolean serializable{x};
    serializable.unmarshal(R"({"value":true})");

    ASSERT_TRUE(*x);
  }

  TEST_F(SerializableJsonBooleanTest, getValue)
  {
    std::shared_ptr<ls_std::Boolean> x = std::make_shared<ls_std::Boolean>(false);
    ls_std::SerializableJsonBoolean serializable{x};

    ASSERT_TRUE(serializable.getValue() == x);
  }

  TEST_F(SerializableJsonBooleanTest, setValue)
  {
    std::shared_ptr<ls_std::Boolean> x = std::make_shared<ls_std::Boolean>(false);
    ls_std::SerializableJsonBoolean serializable{x};
    ASSERT_TRUE(serializable.getValue() == x);

    x = std::make_shared<ls_std::Boolean>(true);
    serializable.setValue(x);
    ASSERT_TRUE(serializable.getValue() == x);
  }
}
