/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-26
 * Changed:         2020-09-14
 *
 * */

#include <gtest/gtest.h>
#include "../../../../../source/boxing/Long.hpp"
#include "../../../../../source/serialization/json/boxing/SerializableJSONLong.hpp"

namespace {
  class SerializableJSONLongTest : public ::testing::Test {
    protected:

      SerializableJSONLongTest() = default;
      ~SerializableJSONLongTest() override = default;

      void SetUp() override {}
      void TearDown() override {}
  };

  TEST_F(SerializableJSONLongTest, marshal)
  {
    ls_std::Long x {(ls_std::long_type) 31983771009271};
    ls_std::SerializableJSONLong serializable {std::make_shared<ls_std::Long>(x)};
    ls_std::byte_field content = serializable.marshal();

    ASSERT_STREQ(R"({"value":31983771009271})", content.c_str());
  }

  TEST_F(SerializableJSONLongTest, unmarshal)
  {
    std::shared_ptr<ls_std::Long> x = std::make_shared<ls_std::Long>(31983771009271);
    ASSERT_EQ(31983771009271, *x);

    ls_std::SerializableJSONLong serializable {x};
    serializable.unmarshal(R"({"value":1989})");

    ASSERT_EQ(1989, *x);
  }
}