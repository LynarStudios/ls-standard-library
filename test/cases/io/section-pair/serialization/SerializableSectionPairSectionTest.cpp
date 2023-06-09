/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-14
* Changed:         2023-03-25
*
* */

#include <gtest/gtest.h>
#include <ls-std-io-test.hpp>
#include <ls-std/ls-std-core.hpp>
#include <ls-std/ls-std-io.hpp>
#include <memory>

using ls::std::core::IllegalArgumentException;
using ls::std::core::type::byte_field;
using ls::std::io::NewLine;
using ls::std::io::SectionPairRowListValue;
using ls::std::io::SectionPairRowSingleValue;
using ls::std::io::SectionPairSection;
using ls::std::io::SerializableSectionPairParameter;
using ls::std::io::SerializableSectionPairSection;
using std::dynamic_pointer_cast;
using std::make_shared;
using std::shared_ptr;
using std::string;
using test::io::SectionPairSectionProvider;
using testing::Test;
using testing::TestWithParam;
using testing::Values;

namespace
{
  class SerializableSectionPairSectionTest : public Test
  {
    public:

      SerializableSectionPairSectionTest() = default;
      ~SerializableSectionPairSectionTest() override = default;
  };

  class SerializableSectionPairSectionTest_LineBreakTest : public TestWithParam<string>
  {
    public:

      SerializableSectionPairSectionTest_LineBreakTest() = default;
      ~SerializableSectionPairSectionTest_LineBreakTest() override = default;
  };

  TEST_F(SerializableSectionPairSectionTest, constructor_no_reference)
  {
    SerializableSectionPairParameter parameter{};

    EXPECT_THROW(
        {
          try
          {
            SerializableSectionPairSection serializable(parameter);
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(SerializableSectionPairSectionTest, getClassName)
  {
    SerializableSectionPairParameter parameter{};
    parameter.setValue(make_shared<SectionPairSection>("general"));

    ASSERT_STREQ("SerializableSectionPairSection", SerializableSectionPairSection{parameter}.getClassName().c_str());
  }

  TEST_F(SerializableSectionPairSectionTest, getValue)
  {
    SerializableSectionPairParameter parameter{};
    parameter.setValue(make_shared<SectionPairSection>("general"));
    SerializableSectionPairSection serializable{parameter};

    ASSERT_TRUE(serializable.getValue() != nullptr);
  }

  TEST_P(SerializableSectionPairSectionTest_LineBreakTest, marshal_sandra)
  {
    string newLine = GetParam();
    SerializableSectionPairParameter parameter{};
    parameter.setValue(SectionPairSectionProvider::createSectionWithSandraExample());
    parameter.setNewLine(newLine);
    SerializableSectionPairSection serializable{parameter};
    byte_field expected = SectionPairSectionProvider::createSerializedSectionWithSandraExample(newLine);
    byte_field actual = serializable.marshal();

    ASSERT_STREQ(expected.c_str(), actual.c_str());
  }

  TEST_P(SerializableSectionPairSectionTest_LineBreakTest, marshal_tom)
  {
    string newLine = GetParam();
    SerializableSectionPairParameter parameter{};
    parameter.setValue(SectionPairSectionProvider::createSectionWithTomExample());
    parameter.setNewLine(newLine);
    SerializableSectionPairSection serializable{parameter};
    byte_field expected = SectionPairSectionProvider::createSerializedSectionWithTomExample(newLine);
    byte_field actual = serializable.marshal();

    ASSERT_STREQ(expected.c_str(), actual.c_str());
  }

  TEST_P(SerializableSectionPairSectionTest_LineBreakTest, unmarshal_sandra)
  {
    string newLine = GetParam();
    SerializableSectionPairParameter parameter{};
    shared_ptr<SectionPairSection> section = make_shared<SectionPairSection>("tmp-id");
    parameter.setValue(section);
    parameter.setNewLine(newLine);
    SerializableSectionPairSection serializable{parameter};
    serializable.unmarshal(SectionPairSectionProvider::createSerializedSectionWithSandraExample(newLine));

    ASSERT_STREQ("general", section->getSectionId().c_str());
    ASSERT_EQ(3, section->getRowAmount());
    ASSERT_STREQ("name", section->get(0)->getKey().c_str());
    ASSERT_STREQ("Sandra", dynamic_pointer_cast<SectionPairRowSingleValue>(section->get(0)->getValue())->get().c_str());

    ASSERT_STREQ("age", section->get(1)->getKey().c_str());
    ASSERT_STREQ("24", dynamic_pointer_cast<SectionPairRowSingleValue>(section->get(1)->getValue())->get().c_str());

    ASSERT_STREQ("hobbies", section->get(2)->getKey().c_str());
    shared_ptr<SectionPairRowListValue> listRow = dynamic_pointer_cast<SectionPairRowListValue>(section->get(2)->getValue());
    ASSERT_EQ(3, listRow->getSize());
    ASSERT_STREQ("swimming", listRow->get(0).c_str());
    ASSERT_STREQ("cycling", listRow->get(1).c_str());
    ASSERT_STREQ("singing", listRow->get(2).c_str());
  }

  TEST_P(SerializableSectionPairSectionTest_LineBreakTest, unmarshal_tom)
  {
    string newLine = GetParam();
    SerializableSectionPairParameter parameter{};
    shared_ptr<SectionPairSection> section = make_shared<SectionPairSection>("tmp-id");
    parameter.setValue(section);
    parameter.setNewLine(newLine);
    SerializableSectionPairSection serializable{parameter};
    serializable.unmarshal(SectionPairSectionProvider::createSerializedSectionWithTomExample(newLine));

    ASSERT_STREQ("general", section->getSectionId().c_str());
    ASSERT_EQ(3, section->getRowAmount());
    ASSERT_STREQ("name", section->get(0)->getKey().c_str());
    ASSERT_STREQ("Tom", dynamic_pointer_cast<SectionPairRowSingleValue>(section->get(0)->getValue())->get().c_str());
    ASSERT_STREQ("jobs", section->get(1)->getKey().c_str());
    shared_ptr<SectionPairRowListValue> listRow = dynamic_pointer_cast<SectionPairRowListValue>(section->get(1)->getValue());
    ASSERT_EQ(2, listRow->getSize());
    ASSERT_STREQ("Farmer", listRow->get(0).c_str());
    ASSERT_STREQ("Bounty Hunter", listRow->get(1).c_str());
    ASSERT_STREQ("age", section->get(2)->getKey().c_str());
    ASSERT_STREQ("33", dynamic_pointer_cast<SectionPairRowSingleValue>(section->get(2)->getValue())->get().c_str());
  }

  TEST_F(SerializableSectionPairSectionTest, unmarshal_invalid_input)
  {
    SerializableSectionPairParameter parameter{};
    parameter.setValue(make_shared<SectionPairSection>("tmp-key"));
    SerializableSectionPairSection serializable(parameter);

    EXPECT_THROW(
        {
          try
          {
            serializable.unmarshal(R"(\n[general]\n\n)");
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  INSTANTIATE_TEST_SUITE_P(LineBreakTest, SerializableSectionPairSectionTest_LineBreakTest, Values(NewLine::getUnixNewLine(), NewLine::getWindowsNewLine()));
}
