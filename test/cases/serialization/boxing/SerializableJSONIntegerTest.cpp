/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-21
 * Changed:         2020-09-04
 *
 * */

#include <gtest/gtest.h>
#include "../../../../source/boxing/Integer.hpp"
#include "../../../../source/serialization/boxing/SerializableJSONInteger.hpp"

namespace {
  class SerializableJSONIntegerTest : public ::testing::Test {
    protected:

      SerializableJSONIntegerTest() = default;
      ~SerializableJSONIntegerTest() override = default;

      void SetUp() override {}
      void TearDown() override {}
  };

  TEST_F(SerializableJSONIntegerTest, marshal)
  {
    ls_std::Integer x {3};
    ls_std::SerializableJSONInteger serializable {std::make_shared<ls_std::Integer>(x)};
    ls_std::byte_field content = serializable.marshal();

    ASSERT_STREQ(R"({"value":3})", content.c_str());
  }

  TEST_F(SerializableJSONIntegerTest, unmarshal)
  {
    std::shared_ptr<ls_std::Integer> x = std::make_shared<ls_std::Integer>(13);
    ASSERT_EQ(13, *x);

    ls_std::SerializableJSONInteger serializable {x};
    serializable.unmarshal(R"({"value":1989})");

    ASSERT_EQ(1989, *x);
  }
}
