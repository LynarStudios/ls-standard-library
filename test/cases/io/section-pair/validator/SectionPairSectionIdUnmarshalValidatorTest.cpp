/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-14
* Changed:         2023-02-15
*
* */

#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>
#include <ls-std/ls-std-io.hpp>

using namespace ls::std::core;
using namespace ls::std::core::type;
using namespace ls::std::io;

namespace
{
  class SectionPairSectionIdUnmarshalValidatorTest : public ::testing::Test
  {
    protected:

      SectionPairSectionIdUnmarshalValidatorTest() = default;
      ~SectionPairSectionIdUnmarshalValidatorTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(SectionPairSectionIdUnmarshalValidatorTest, getClassName)
  {
    ASSERT_STREQ("SectionPairSectionIdUnmarshalValidator", SectionPairSectionIdUnmarshalValidator{"\n[general]\n"}.getClassName().c_str());
  }

  TEST_F(SectionPairSectionIdUnmarshalValidatorTest, isValid)
  {
    byte_field generalSection = NewLine::get() + "[general]" + NewLine::get();
    byte_field localServerSection = NewLine::get() + "[local-server]" + NewLine::get();

    ASSERT_TRUE(SectionPairSectionIdUnmarshalValidator{generalSection}.isValid());
    ASSERT_TRUE(SectionPairSectionIdUnmarshalValidator{localServerSection}.isValid());
  }

  TEST_F(SectionPairSectionIdUnmarshalValidatorTest, isValid_not_valid)
  {
    byte_field generalSection = "[general]" + NewLine::get();
    byte_field localServerSection = NewLine::get() + "[local-server]";
    byte_field position = NewLine::get() + "position" + NewLine::get();

    ASSERT_FALSE(SectionPairSectionIdUnmarshalValidator{generalSection}.isValid());
    ASSERT_FALSE(SectionPairSectionIdUnmarshalValidator{localServerSection}.isValid());
    ASSERT_FALSE(SectionPairSectionIdUnmarshalValidator{position}.isValid());
  }
}
