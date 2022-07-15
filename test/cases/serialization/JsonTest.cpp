/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-14
 * Changed:         2022-07-15
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/core/types/Types.hpp>

namespace
{
  class JsonTest : public ::testing::Test
  {
    protected:

      JsonTest() = default;
      ~JsonTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(JsonTest, simpleSerialization)
  {
    ls::std::core::type::json jsonObject{};
    jsonObject["value"] = 1989;

    ASSERT_STREQ(R"({"value":1989})", jsonObject.dump().c_str());
  }
}
