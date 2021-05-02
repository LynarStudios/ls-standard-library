/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-04-23
 * Changed:         2021-05-02
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>

namespace
{
  class SerializableJsonBooleanFactoryTest : public ::testing::Test
  {
    protected:

      SerializableJsonBooleanFactoryTest() = default;
      ~SerializableJsonBooleanFactoryTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(SerializableJsonBooleanFactoryTest, build)
  {
    std::shared_ptr<ls_std::Boolean> value = std::dynamic_pointer_cast<ls_std::Boolean>(ls_std::SerializableJsonBooleanFactory{}.build());
    ASSERT_TRUE(value != nullptr);
    ASSERT_STREQ("Boolean", value->getClassName().c_str());
  }
}
