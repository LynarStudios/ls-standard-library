/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-14
 * Changed:         2020-09-14
 *
 * */

#include <gtest/gtest.h>
#include <json.hpp>

namespace {
  class JSONTest : public ::testing::Test {
    protected:

      JSONTest() = default;
      ~JSONTest() override = default;

      void SetUp() override {}
      void TearDown() override {}
  };

  TEST_F(JSONTest, simpleSerialization)
  {
    nlohmann::json jsonObject {};
    jsonObject["value"] = 1989;

    ASSERT_STREQ(R"({"value":1989})", jsonObject.dump().c_str());
  }
}
