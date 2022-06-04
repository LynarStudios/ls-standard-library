/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-14
 * Changed:         2022-05-05
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/lib/nlohmann_json/include/nlohmann/json.hpp>

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
    nlohmann::json jsonObject{};
    jsonObject["value"] = 1989;

    ASSERT_STREQ(R"({"value":1989})", jsonObject.dump().c_str());
  }
}
