/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-09
* Changed:         2023-02-09
*
* */

#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>
#include <ls-std/ls-std-io.hpp>

using namespace ls::std::core;
using namespace ls::std::io;
using namespace ::std;

namespace
{
  class SectionPairIdentifierValidatorTest : public ::testing::Test
  {
    protected:

      SectionPairIdentifierValidatorTest() = default;
      ~SectionPairIdentifierValidatorTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(SectionPairIdentifierValidatorTest, getClassName)
  {
    ASSERT_STREQ("SectionPairIdentifierValidator", SectionPairIdentifierValidator{"tmp-key"}.getClassName().c_str());
  }

  TEST_F(SectionPairIdentifierValidatorTest, isValid)
  {
    ASSERT_TRUE(SectionPairIdentifierValidator{"color"}.isValid());
    ASSERT_TRUE(SectionPairIdentifierValidator{"favourite-color"}.isValid());
    ASSERT_TRUE(SectionPairIdentifierValidator{"age"}.isValid());
    ASSERT_TRUE(SectionPairIdentifierValidator{"name"}.isValid());
  }

  TEST_F(SectionPairIdentifierValidatorTest, isValid_not_valid)
  {
    ASSERT_FALSE(SectionPairIdentifierValidator{"_color"}.isValid());
    ASSERT_FALSE(SectionPairIdentifierValidator{"8color"}.isValid());
    ASSERT_FALSE(SectionPairIdentifierValidator{"colOr"}.isValid());
    ASSERT_FALSE(SectionPairIdentifierValidator{"color:"}.isValid());
    ASSERT_FALSE(SectionPairIdentifierValidator{"-color"}.isValid());
    ASSERT_FALSE(SectionPairIdentifierValidator{"color-is-valid-but-too-long"}.isValid());
  }
}