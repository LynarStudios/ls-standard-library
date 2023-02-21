/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-21
* Changed:         2023-02-21
*
* */

#include <gtest/gtest.h>
#include <ls-std/ls-std-io.hpp>
#include <string>

using namespace ls::std::core;
using namespace ls::std::io;
using namespace ::std;

namespace
{
  class SectionPairFileExtensionValidatorTest : public ::testing::Test
  {
    protected:

      SectionPairFileExtensionValidatorTest() = default;
      ~SectionPairFileExtensionValidatorTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  class SectionPairFileExtensionValidatorTest_ValidExtensionTest : public ::testing::TestWithParam<string>
  {
    protected:

      SectionPairFileExtensionValidatorTest_ValidExtensionTest() = default;
      ~SectionPairFileExtensionValidatorTest_ValidExtensionTest() override = default;
  };

  class SectionPairFileExtensionValidatorTest_NotValidExtensionTest : public ::testing::TestWithParam<string>
  {
    protected:

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

  INSTANTIATE_TEST_SUITE_P(ValidExtensionTest, SectionPairFileExtensionValidatorTest_ValidExtensionTest, ::testing::Values("server-settings.txt", "settings.sp", "/var/log/settings.txt"));
  INSTANTIATE_TEST_SUITE_P(NotValidExtensionTest, SectionPairFileExtensionValidatorTest_NotValidExtensionTest, ::testing::Values("server-settings.json", "settings.html", "/var/log/settings"));
}
