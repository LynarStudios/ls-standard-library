/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-09
* Changed:         2023-04-13
*
* */

#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>
#include <ls-std/ls-std-io.hpp>
#include <string>

using ls::std::io::SectionPairIdentifierValidator;
using std::string;
using testing::Test;
using testing::TestWithParam;
using testing::Values;

namespace
{
  class SectionPairIdentifierValidatorTest : public Test
  {
    public:

      SectionPairIdentifierValidatorTest() = default;
      ~SectionPairIdentifierValidatorTest() override = default;
  };

  class SectionPairIdentifierValidatorTest_ValidArgumentTest : public TestWithParam<string>
  {
    public:

      SectionPairIdentifierValidatorTest_ValidArgumentTest() = default;
      ~SectionPairIdentifierValidatorTest_ValidArgumentTest() override = default;
  };

  class SectionPairIdentifierValidatorTest_InvalidArgumentTest : public TestWithParam<string>
  {
    public:

      SectionPairIdentifierValidatorTest_InvalidArgumentTest() = default;
      ~SectionPairIdentifierValidatorTest_InvalidArgumentTest() override = default;
  };

  TEST_F(SectionPairIdentifierValidatorTest, getClassName)
  {
    ASSERT_STREQ("SectionPairIdentifierValidator", SectionPairIdentifierValidator{"tmp-key"}.getClassName().c_str());
  }

  TEST_F(SectionPairIdentifierValidatorTest, getValidationRegex)
  {
    ASSERT_STREQ(R"([a-z]([a-z0-9-]){1,63})", SectionPairIdentifierValidator{"tmp-key"}.getValidationRegex().c_str());
  }

  TEST_P(SectionPairIdentifierValidatorTest_ValidArgumentTest, isValid)
  {
    ASSERT_TRUE(SectionPairIdentifierValidator{GetParam()}.isValid());
  }

  TEST_P(SectionPairIdentifierValidatorTest_InvalidArgumentTest, isValid_not_valid)
  {
    ASSERT_FALSE(SectionPairIdentifierValidator{GetParam()}.isValid());
  }

  INSTANTIATE_TEST_SUITE_P(ValidArgumentTest, SectionPairIdentifierValidatorTest_ValidArgumentTest, Values("color", "favourite-color", "age", "name"));
  INSTANTIATE_TEST_SUITE_P(InvalidArgumentTest, SectionPairIdentifierValidatorTest_InvalidArgumentTest, Values("_color", "8color", "colOr", "color:", "-color", "color-would-be-usually-valid-but-too-long-because-it-exceeds-64-characters"));
}
