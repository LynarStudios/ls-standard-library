/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-04-30
 * Changed:         2021-05-01
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>

namespace
{
  class SerializableJSONEventFactoryTest : public ::testing::Test
  {
    protected:

      SerializableJSONEventFactoryTest() = default;
      ~SerializableJSONEventFactoryTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(SerializableJSONEventFactoryTest, build)
  {
    std::shared_ptr<ls_std::Event> value = std::dynamic_pointer_cast<ls_std::Event>(ls_std::SerializableJSONEventFactory{}.build());
    ASSERT_TRUE(value != nullptr);
    ASSERT_STREQ("Event", value->getClassName().c_str());
  }
}
