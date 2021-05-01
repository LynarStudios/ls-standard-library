/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-04-25
 * Changed:         2021-05-01
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>

namespace
{
  class SerializableJSONIntegerFactoryTest : public ::testing::Test
  {
    protected:

      SerializableJSONIntegerFactoryTest() = default;
      ~SerializableJSONIntegerFactoryTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(SerializableJSONIntegerFactoryTest, build)
  {
    std::shared_ptr<ls_std::Integer> value = std::dynamic_pointer_cast<ls_std::Integer>(ls_std::SerializableJSONIntegerFactory{}.build());
    ASSERT_TRUE(value != nullptr);
    ASSERT_STREQ("Integer", value->getClassName().c_str());
  }
}
