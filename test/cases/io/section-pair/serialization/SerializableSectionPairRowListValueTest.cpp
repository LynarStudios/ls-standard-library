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
using namespace ls::std::io;
using namespace ::std;
using namespace ::testing;

namespace
{
  class SerializableSectionPairRowListValueTest : public Test
  {
    protected:

      SerializableSectionPairRowListValueTest() = default;
      ~SerializableSectionPairRowListValueTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  class SerializableSectionPairRowListValueTest_LineBreakTest : public TestWithParam<string>
  {
    protected:

      SerializableSectionPairRowListValueTest_LineBreakTest() = default;
      ~SerializableSectionPairRowListValueTest_LineBreakTest() override = default;
  };

  TEST_F(SerializableSectionPairRowListValueTest, constructor_no_reference)
  {
    SerializableSectionPairParameter parameter{};

    EXPECT_THROW(
        {
          try
          {
            SerializableSectionPairRowListValue serializable(parameter);
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(SerializableSectionPairRowListValueTest, getClassName)
  {
    SerializableSectionPairParameter parameter{};
    parameter.setValue(make_shared<SectionPairRowListValue>());

    ASSERT_STREQ("SerializableSectionPairRowListValue", SerializableSectionPairRowListValue{parameter}.getClassName().c_str());
  }

  TEST_F(SerializableSectionPairRowListValueTest, getValue)
  {
    SerializableSectionPairParameter parameter{};
    shared_ptr<SectionPairRowListValue> value = make_shared<SectionPairRowListValue>();
    parameter.setValue(value);
    SerializableSectionPairRowListValue serializable(parameter);

    ASSERT_TRUE(value == serializable.getValue());
  }

  TEST_P(SerializableSectionPairRowListValueTest_LineBreakTest, marshal)
  {
    SerializableSectionPairParameter parameter{};
    shared_ptr<SectionPairRowListValue> value = make_shared<SectionPairRowListValue>();
    value->add("Drumming");
    value->add("Reading");
    value->add("Coding");
    parameter.setValue(value);
    string newLine = GetParam();
    parameter.setNewLine(newLine);
    SerializableSectionPairRowListValue serializable(parameter);

    string expected = "  Drumming" + newLine + "  Reading" + newLine + "  Coding" + newLine;

    ASSERT_STREQ(expected.c_str(), serializable.marshal().c_str());
  }

  TEST_P(SerializableSectionPairRowListValueTest_LineBreakTest, unmarshal)
  {
    SerializableSectionPairParameter parameter{};
    shared_ptr<SectionPairRowListValue> value = make_shared<SectionPairRowListValue>();
    parameter.setValue(value);
    string newLine = GetParam();
    parameter.setNewLine(newLine);
    SerializableSectionPairRowListValue serializable(parameter);
    string serializedListValue = "  Drumming" + newLine + "  Reading" + newLine + "  Coding" + newLine;
    serializable.unmarshal(serializedListValue);

    ASSERT_EQ(3, value->getSize());
    ASSERT_STREQ("Drumming", value->get(0).c_str());
    ASSERT_STREQ("Reading", value->get(1).c_str());
    ASSERT_STREQ("Coding", value->get(2).c_str());
  }

  TEST_F(SerializableSectionPairRowListValueTest, unmarshal_empty_string)
  {
    SerializableSectionPairParameter parameter{};
    parameter.setValue(make_shared<SectionPairRowListValue>());
    SerializableSectionPairRowListValue serializable(parameter);

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

  INSTANTIATE_TEST_SUITE_P(LineBreakTest, SerializableSectionPairRowListValueTest_LineBreakTest, Values(NewLine::getUnixNewLine(), NewLine::getWindowsNewLine()));
}
