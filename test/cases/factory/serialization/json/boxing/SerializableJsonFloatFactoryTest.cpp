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
  class SerializableJsonFloatFactoryTest : public ::testing::Test
  {
    protected:

      SerializableJsonFloatFactoryTest() = default;
      ~SerializableJsonFloatFactoryTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(SerializableJsonFloatFactoryTest, build)
  {
    std::shared_ptr<ls_std::Float> value = std::dynamic_pointer_cast<ls_std::Float>(ls_std::SerializableJsonFloatFactory{}.build());
    ASSERT_TRUE(value != nullptr);
    ASSERT_STREQ("Float", value->getClassName().c_str());
  }
}
