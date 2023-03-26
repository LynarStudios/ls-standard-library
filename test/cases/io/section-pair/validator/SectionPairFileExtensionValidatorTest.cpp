/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-21
* Changed:         2023-03-25
*
* */

#include <gtest/gtest.h>
#include <ls-std/ls-std-io.hpp>
#include <string>

using ls::std::io::SectionPairFileExtensionValidator;
using std::string;
using testing::Test;
using testing::TestWithParam;
using testing::Values;

namespace
{
  class SectionPairFileExtensionValidatorTest : public Test
  {
    public:

      SectionPairFileExtensionValidatorTest() = default;
      ~SectionPairFileExtensionValidatorTest() override = default;
  };

  class SectionPairFileExtensionValidatorTest_ValidExtensionTest : public TestWithParam<string>
  {
    public:

      SectionPairFileExtensionValidatorTest_ValidExtensionTest() = default;
      ~SectionPairFileExtensionValidatorTest_ValidExtensionTest() override = default;
  };

  class SectionPairFileExtensionValidatorTest_NotValidExtensionTest : public TestWithParam<string>
  {
    public:

      SectionPairFileExtensionValidatorTest_NotValidExtensionTest() = default;
      ~SectionPairFileExtensionValidatorTest_NotValidExtensionTest() override = default;
  };

  TEST_F(SectionPairFileExtensionValidatorTest, getClassName)
  {
    ASSERT_STREQ("SectionPairFileExtensionValidator", SectionPairFileExtensionValidator{"tmp.txt"}.getClassName().c_str());
  }

  TEST_P(SectionPairFileExtensionValidatorTest_ValidExtensionTest, isValid)
  {
    ASSERT_TRUE(SectionPairFileExtensionValidator{GetParam()}.isValid());
  }

  TEST_P(SectionPairFileExtensionValidatorTest_NotValidExtensionTest, isValid)
  {
    ASSERT_FALSE(SectionPairFileExtensionValidator{GetParam()}.isValid());
  }

  INSTANTIATE_TEST_SUITE_P(ValidExtensionTest, SectionPairFileExtensionValidatorTest_ValidExtensionTest, Values("server-settings.txt", "settings.sp", "/var/log/settings.txt"));
  INSTANTIATE_TEST_SUITE_P(NotValidExtensionTest, SectionPairFileExtensionValidatorTest_NotValidExtensionTest, Values("server-settings.json", "settings.html", "/var/log/settings"));
}
