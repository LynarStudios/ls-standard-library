/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-04-24
 * Changed:         2021-05-02
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>

namespace
{
  class SerializableJsonDoubleFactoryTest : public ::testing::Test
  {
    protected:

      SerializableJsonDoubleFactoryTest() = default;
      ~SerializableJsonDoubleFactoryTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(SerializableJsonDoubleFactoryTest, build)
  {
    std::shared_ptr<ls_std::Double> value = std::dynamic_pointer_cast<ls_std::Double>(ls_std::SerializableJsonDoubleFactory{}.build());
    ASSERT_TRUE(value != nullptr);
    ASSERT_STREQ("Double", value->getClassName().c_str());
  }
}
