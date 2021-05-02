/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-21
 * Changed:         2021-05-02
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>

namespace
{
  class SerializableJsonIntegerTest : public ::testing::Test
  {
    protected:

      SerializableJsonIntegerTest() = default;
      ~SerializableJsonIntegerTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(SerializableJsonIntegerTest, marshal)
  {
    ls_std::Integer x{3};
    ls_std::SerializableJsonInteger serializable{std::make_shared<ls_std::Integer>(x)};
    ls_std::byte_field content = serializable.marshal();

    ASSERT_STREQ(R"({"value":3})", content.c_str());
  }

  TEST_F(SerializableJsonIntegerTest, unmarshal)
  {
    std::shared_ptr<ls_std::Integer> x = std::make_shared<ls_std::Integer>(13);
    ASSERT_EQ(13, *x);

    ls_std::SerializableJsonInteger serializable{x};
    serializable.unmarshal(R"({"value":1989})");

    ASSERT_EQ(1989, *x);
  }

  TEST_F(SerializableJsonIntegerTest, getValue)
  {
    std::shared_ptr<ls_std::Integer> x = std::make_shared<ls_std::Integer>(13);
    ls_std::SerializableJsonInteger serializable{x};
    ASSERT_TRUE(serializable.getValue() == x);
  }

  TEST_F(SerializableJsonIntegerTest, setValue)
  {
    std::shared_ptr<ls_std::Integer> x = std::make_shared<ls_std::Integer>(13);
    ls_std::SerializableJsonInteger serializable{x};
    ASSERT_TRUE(serializable.getValue() == x);

    x = std::make_shared<ls_std::Integer>(25);
    serializable.setValue(x);
    ASSERT_TRUE(serializable.getValue() == x);
  }
}
