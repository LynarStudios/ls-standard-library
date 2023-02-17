/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-14
* Changed:         2023-02-17
*
* */

#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>
#include <ls-std/ls-std-io.hpp>

using namespace ls::std::core;
using namespace ls::std::core::type;
using namespace ls::std::io;
using namespace ::std;

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
    ASSERT_STREQ("SectionPairSectionIdUnmarshalValidator", SectionPairSectionIdUnmarshalValidator("\n[general]\n", NewLine::get()).getClassName().c_str());
  }

  TEST_F(SectionPairSectionIdUnmarshalValidatorTest, isValid)
  {
    string newLine = NewLine::get();
    byte_field generalSection = newLine + "[general]" + newLine + newLine;
    byte_field localServerSection = newLine + "[local-server]" + newLine + newLine;

    ASSERT_TRUE(SectionPairSectionIdUnmarshalValidator(generalSection, newLine).isValid());
    ASSERT_TRUE(SectionPairSectionIdUnmarshalValidator(localServerSection, newLine).isValid());
  }

  TEST_F(SectionPairSectionIdUnmarshalValidatorTest, isValid_not_valid)
  {
    string newLine = NewLine::get();
    byte_field generalSection = newLine + "[general]" + newLine;
    byte_field localServerSection = newLine + "[local-server]";
    byte_field position = newLine + "position" + newLine;

    ASSERT_FALSE(SectionPairSectionIdUnmarshalValidator(generalSection, newLine).isValid());
    ASSERT_FALSE(SectionPairSectionIdUnmarshalValidator(localServerSection, newLine).isValid());
    ASSERT_FALSE(SectionPairSectionIdUnmarshalValidator(position, newLine).isValid());
  }
}
