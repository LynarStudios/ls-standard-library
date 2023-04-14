/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-14
 * Changed:         2023-03-25
 *
 * */

#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>

using ls::std::core::type::json;
using testing::Test;

namespace
{
  class JsonTest : public Test
  {
    public:

      JsonTest() = default;
      ~JsonTest() override = default;
  };

  TEST_F(JsonTest, simpleSerialization)
  {
    json jsonObject{};
    jsonObject["value"] = 1989;

    ASSERT_STREQ(R"({"value":1989})", jsonObject.dump().c_str());
  }
}
