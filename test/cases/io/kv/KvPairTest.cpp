/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-25
 * Changed:         2022-05-11
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>

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
                     ls::std::io::KvPair pair = ls::std::io::KvPair("", "1989");
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }

  TEST_F(KvPairTest, getKey)
  {
    ls::std::io::KvPair pair{"port", "13088"};
    ASSERT_STREQ("port", pair.getKey().c_str());
  }

  TEST_F(KvPairTest, getValue)
  {
    ls::std::io::KvPair pair{"port", "13088"};
    ASSERT_STREQ("13088", pair.getValue().c_str());
  }

  TEST_F(KvPairTest, setValue)
  {
    ls::std::io::KvPair pair{"port", "13088"};
    ASSERT_STREQ("13088", pair.getValue().c_str());

    pair.setValue("8080");
    ASSERT_STREQ("8080", pair.getValue().c_str());
  }
}
