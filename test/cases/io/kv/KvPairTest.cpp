/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-25
 * Changed:         2022-11-09
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std_core.hpp>
#include <ls_std/ls_std_io.hpp>

using namespace ls::std::core;
using namespace ls::std::io;

namespace
{
  class KvPairTest : public ::testing::Test
  {
    protected:

      KvPairTest() = default;

      ~KvPairTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(KvPairTest, constructor_with_empty_key)
  {
    EXPECT_THROW({
                   try
                   {
                     KvPair pair = KvPair("", "1989");
                   }
                   catch (const IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, IllegalArgumentException);
  }

  TEST_F(KvPairTest, getKey)
  {
    KvPair pair{"port", "13088"};
    ASSERT_STREQ("port", pair.getKey().c_str());
  }

  TEST_F(KvPairTest, getValue)
  {
    KvPair pair{"port", "13088"};
    ASSERT_STREQ("13088", pair.getValue().c_str());
  }

  TEST_F(KvPairTest, setValue)
  {
    KvPair pair{"port", "13088"};
    ASSERT_STREQ("13088", pair.getValue().c_str());

    pair.setValue("8080");
    ASSERT_STREQ("8080", pair.getValue().c_str());
  }
}
