/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-11
* Changed:         2023-02-22
*
* */

#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>
#include <ls-std/ls-std-io.hpp>
#include <memory>

using namespace ls::std::core;
using namespace ls::std::core::type;
using namespace ls::std::io;
using namespace ::std;
using namespace ::testing;

namespace
{
  class SerializableSectionPairRowSingleValueTest : public Test
  {
    protected:

      SerializableSectionPairRowSingleValueTest() = default;
      ~SerializableSectionPairRowSingleValueTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  class SerializableSectionPairRowSingleValueTest_LineBreakTest : public ::testing::TestWithParam<string>
  {
    protected:

      SerializableSectionPairRowSingleValueTest_LineBreakTest() = default;
      ~SerializableSectionPairRowSingleValueTest_LineBreakTest() override = default;
  };

  TEST_F(SerializableSectionPairRowSingleValueTest, constructor_no_reference)
  {
    SerializableSectionPairParameter parameter{};

    EXPECT_THROW(
        {
          try
          {
            SerializableSectionPairRowSingleValue serializable(parameter);
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(SerializableSectionPairRowSingleValueTest, getClassName)
  {
    SerializableSectionPairParameter parameter{};
    parameter.setValue(make_shared<SectionPairRowSingleValue>("empty"));

    ASSERT_STREQ("SerializableSectionPairRowSingleValue", SerializableSectionPairRowSingleValue{parameter}.getClassName().c_str());
  }

  TEST_F(SerializableSectionPairRowSingleValueTest, getValue)
  {
    SerializableSectionPairParameter parameter{};
    shared_ptr<SectionPairRowSingleValue> value = make_shared<SectionPairRowSingleValue>("empty");
    parameter.setValue(value);
    SerializableSectionPairRowSingleValue serializable(parameter);

    ASSERT_TRUE(value == serializable.getValue());
  }

  TEST_P(SerializableSectionPairRowSingleValueTest_LineBreakTest, marshal)
  {
    string newLine = GetParam();
    SerializableSectionPairParameter parameter{};
    parameter.setValue(make_shared<SectionPairRowSingleValue>("empty"));
    parameter.setNewLine(newLine);
    SerializableSectionPairRowSingleValue serializable(parameter);

    byte_field expected = "empty" + newLine;
    byte_field actual = serializable.marshal();

    ASSERT_STREQ(expected.c_str(), actual.c_str());
  }

  TEST_F(SerializableSectionPairRowSingleValueTest, unmarshal)
  {
    SerializableSectionPairParameter parameter{};
    parameter.setValue(make_shared<SectionPairRowSingleValue>("empty"));
    SerializableSectionPairRowSingleValue serializable(parameter);
    serializable.unmarshal("blue");

    ASSERT_STREQ("blue", dynamic_pointer_cast<SectionPairRowSingleValue>(parameter.getValue())->get().c_str());
  }

  TEST_F(SerializableSectionPairRowSingleValueTest, unmarshal_empty_string)
  {
    SerializableSectionPairParameter parameter{};
    parameter.setValue(make_shared<SectionPairRowSingleValue>("empty"));
    SerializableSectionPairRowSingleValue serializable(parameter);

    EXPECT_THROW(
        {
          try
          {
            serializable.unmarshal("");
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  INSTANTIATE_TEST_SUITE_P(LineBreakTest, SerializableSectionPairRowSingleValueTest_LineBreakTest, Values(NewLine::getUnixNewLine(), NewLine::getWindowsNewLine()));
}
