/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-26
 * Changed:         2021-05-02
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>

namespace
{
  class SerializableJsonLongTest : public ::testing::Test
  {
    protected:

      SerializableJsonLongTest() = default;
      ~SerializableJsonLongTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(SerializableJsonLongTest, marshal)
  {
    ls_std::Long x{(ls_std::long_type) 31983771009271};
    ls_std::SerializableJsonLong serializable{std::make_shared<ls_std::Long>(x)};
    ls_std::byte_field content = serializable.marshal();

    ASSERT_STREQ(R"({"value":31983771009271})", content.c_str());
  }

  TEST_F(SerializableJsonLongTest, unmarshal)
  {
    std::shared_ptr<ls_std::Long> x = std::make_shared<ls_std::Long>(31983771009271);
    ASSERT_EQ(31983771009271, *x);

    ls_std::SerializableJsonLong serializable{x};
    serializable.unmarshal(R"({"value":1989})");

    ASSERT_EQ(1989, *x);
  }

  TEST_F(SerializableJsonLongTest, getValue)
  {
    std::shared_ptr<ls_std::Long> x = std::make_shared<ls_std::Long>(31983771009271);
    ls_std::SerializableJsonLong serializable{x};
    ASSERT_TRUE(serializable.getValue() == x);
  }

  TEST_F(SerializableJsonLongTest, setValue)
  {
    std::shared_ptr<ls_std::Long> x = std::make_shared<ls_std::Long>(31983771009271);
    ls_std::SerializableJsonLong serializable{x};
    ASSERT_TRUE(serializable.getValue() == x);

    x = std::make_shared<ls_std::Long>(31983771009221);
    serializable.setValue(x);
    ASSERT_TRUE(serializable.getValue() == x);
  }
}
