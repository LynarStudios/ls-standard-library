/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-04-25
 * Changed:         2021-05-02
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>

namespace
{
  class SerializableJsonLongFactoryTest : public ::testing::Test
  {
    protected:

      SerializableJsonLongFactoryTest() = default;
      ~SerializableJsonLongFactoryTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(SerializableJsonLongFactoryTest, build)
  {
    std::shared_ptr<ls_std::Long> value = std::dynamic_pointer_cast<ls_std::Long>(ls_std::SerializableJsonLongFactory{}.build());
    ASSERT_TRUE(value != nullptr);
    ASSERT_STREQ("Long", value->getClassName().c_str());
  }
}
