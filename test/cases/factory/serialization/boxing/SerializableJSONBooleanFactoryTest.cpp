/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-04-23
 * Changed:         2021-04-25
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>

namespace
{
  class SerializableJSONBooleanFactoryTest : public ::testing::Test
  {
    protected:

      SerializableJSONBooleanFactoryTest() = default;
      ~SerializableJSONBooleanFactoryTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(SerializableJSONBooleanFactoryTest, build)
  {
    std::shared_ptr<ls_std::Boolean> value = std::dynamic_pointer_cast<ls_std::Boolean>(ls_std::SerializableJSONBooleanFactory{}.build());
    ASSERT_TRUE(value != nullptr);
    ASSERT_STREQ("Boolean", value->getClassName().c_str());
  }
}
