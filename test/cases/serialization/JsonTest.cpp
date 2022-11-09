/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-14
 * Changed:         2022-11-09
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std_core.hpp>

using namespace ls::std::core::type;

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
    json jsonObject{};
    jsonObject["value"] = 1989;

    ASSERT_STREQ(R"({"value":1989})", jsonObject.dump().c_str());
  }
}
