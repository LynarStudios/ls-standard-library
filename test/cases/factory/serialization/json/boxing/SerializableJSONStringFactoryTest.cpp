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
  class SerializableJSONStringFactoryTest : public ::testing::Test
  {
    protected:

      SerializableJSONStringFactoryTest() = default;
      ~SerializableJSONStringFactoryTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(SerializableJSONStringFactoryTest, build)
  {
    std::shared_ptr<ls_std::String> value = std::dynamic_pointer_cast<ls_std::String>(ls_std::SerializableJSONStringFactory{}.build());
    ASSERT_TRUE(value != nullptr);
    ASSERT_STREQ("String", value->getClassName().c_str());
  }
}
