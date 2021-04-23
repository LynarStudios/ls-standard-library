/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-21
 * Changed:         2021-04-23
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>

namespace
{
  class SerializableJSONIntegerTest : public ::testing::Test
  {
    protected:

      SerializableJSONIntegerTest() = default;
      ~SerializableJSONIntegerTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(SerializableJSONIntegerTest, marshal)
  {
    ls_std::Integer x{3};
    ls_std::SerializableJSONInteger serializable{std::make_shared<ls_std::Integer>(x)};
    ls_std::byte_field content = serializable.marshal();

    ASSERT_STREQ(R"({"value":3})", content.c_str());
  }

  TEST_F(SerializableJSONIntegerTest, unmarshal)
  {
    std::shared_ptr<ls_std::Integer> x = std::make_shared<ls_std::Integer>(13);
    ASSERT_EQ(13, *x);

    ls_std::SerializableJSONInteger serializable{x};
    serializable.unmarshal(R"({"value":1989})");

    ASSERT_EQ(1989, *x);
  }

  TEST_F(SerializableJSONIntegerTest, getValue)
  {
    std::shared_ptr<ls_std::Integer> x = std::make_shared<ls_std::Integer>(13);
    ls_std::SerializableJSONInteger serializable{x};
    ASSERT_TRUE(serializable.getValue() == x);
  }

  TEST_F(SerializableJSONIntegerTest, setValue)
  {
    std::shared_ptr<ls_std::Integer> x = std::make_shared<ls_std::Integer>(13);
    ls_std::SerializableJSONInteger serializable{x};
    ASSERT_TRUE(serializable.getValue() == x);

    x = std::make_shared<ls_std::Integer>(25);
    serializable.setValue(x);
    ASSERT_TRUE(serializable.getValue() == x);
  }
}
