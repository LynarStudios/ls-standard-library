/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-25
 * Changed:         2020-12-25
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>

namespace {
  class KVPairTest : public ::testing::Test {
    protected:

      KVPairTest() = default;
      ~KVPairTest() override = default;

      void SetUp() override {}
      void TearDown() override {}
  };

  TEST_F(KVPairTest, getKey)
  {
    ls_std::KVPair pair {"port", "13088"};
    ASSERT_STREQ("port", pair.getKey().c_str());
  }

  TEST_F(KVPairTest, getValue)
  {
    ls_std::KVPair pair {"port", "13088"};
    ASSERT_STREQ("13088", pair.getValue().c_str());
  }

  TEST_F(KVPairTest, setValue)
  {
    ls_std::KVPair pair {"port", "13088"};
    ASSERT_STREQ("13088", pair.getValue().c_str());

    pair.setValue("8080");
    ASSERT_STREQ("8080", pair.getValue().c_str());
  }
}
