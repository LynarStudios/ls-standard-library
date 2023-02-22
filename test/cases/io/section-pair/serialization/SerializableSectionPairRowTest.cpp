/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-12
* Changed:         2023-02-22
*
* */

#include <array>
#include <gtest/gtest.h>
#include <ls-std-io-test.hpp>
#include <ls-std/ls-std-core.hpp>
#include <ls-std/ls-std-io.hpp>
#include <memory>

using namespace ls::std::core;
using namespace ls::std::core::interface_type;
using namespace ls::std::core::type;
using namespace ls::std::io;
using namespace ::std;
using namespace test::io;
using namespace ::testing;

namespace
{
  class SerializableSectionPairRowTest : public Test
  {
    protected:

      SerializableSectionPairRowTest() = default;
      ~SerializableSectionPairRowTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  class SerializableSectionPairRowTest_LineBreakTest : public TestWithParam<string>
  {
    protected:

      SerializableSectionPairRowTest_LineBreakTest() = default;
      ~SerializableSectionPairRowTest_LineBreakTest() override = default;
  };

  class SerializableSectionPairRowTest_IsValidSingleValueTest : public TestWithParam<array<string, 3>>
  {
    protected:

      SerializableSectionPairRowTest_IsValidSingleValueTest() = default;
      ~SerializableSectionPairRowTest_IsValidSingleValueTest() override = default;
  };

  class SerializableSectionPairRowTest_IsInvalidSingleValueTest : public TestWithParam<string>
  {
    protected:

      SerializableSectionPairRowTest_IsInvalidSingleValueTest() = default;
      ~SerializableSectionPairRowTest_IsInvalidSingleValueTest() override = default;
  };

  class SerializableSectionPairRowTest_IsInvalidListValueTest : public TestWithParam<string>
  {
    protected:

      SerializableSectionPairRowTest_IsInvalidListValueTest() = default;
      ~SerializableSectionPairRowTest_IsInvalidListValueTest() override = default;
  };

  TEST_F(SerializableSectionPairRowTest, constructor_no_reference)
  {
    SerializableSectionPairParameter parameter{};

    EXPECT_THROW(
        {
          try
          {
            SerializableSectionPairRow serializable(parameter);
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(SerializableSectionPairRowTest, getClassName)
  {
    SerializableSectionPairParameter parameter{};
    parameter.setValue(make_shared<SectionPairRow>("tmp-key", SectionPairRowEnumType::SECTION_PAIR_ROW_SINGLE_VALUE));

    ASSERT_STREQ("SerializableSectionPairRow", SerializableSectionPairRow{parameter}.getClassName().c_str());
  }

  TEST_F(SerializableSectionPairRowTest, getValue)
  {
    SerializableSectionPairParameter parameter{};
    parameter.setValue(make_shared<SectionPairRow>("tmp-key", SectionPairRowEnumType::SECTION_PAIR_ROW_SINGLE_VALUE));
    SerializableSectionPairRow serializable{parameter};

    ASSERT_TRUE(serializable.getValue() != nullptr);
  }

  TEST_P(SerializableSectionPairRowTest_LineBreakTest, marshal_single_value)
  {
    string newLine = GetParam();
    shared_ptr<SerializableSectionPairRow> serializable = SerializableSectionPairRowProvider::createSingleValueForMarshal(newLine);

    byte_field expected = "favourite-color=blue" + newLine;
    byte_field actual = serializable->marshal();

    ASSERT_STREQ(expected.c_str(), actual.c_str());
  }

  TEST_P(SerializableSectionPairRowTest_LineBreakTest, marshal_list_value)
  {
    string newLine = GetParam();
    shared_ptr<SerializableSectionPairRow> serializable = SerializableSectionPairRowProvider::createListValueForMarshal(newLine);

    string expected = "favourite-colors:" + newLine + "  blue" + newLine + "  red" + newLine + "  purple" + newLine;

    ASSERT_STREQ(expected.c_str(), serializable->marshal().c_str());
  }

  TEST_P(SerializableSectionPairRowTest_LineBreakTest, unmarshal_single_value)
  {
    shared_ptr<SerializableSectionPairRow> serializable = SerializableSectionPairRowProvider::createSingleValueForUnmarshal(GetParam());
    serializable->unmarshal("favourite-color=blue");
    shared_ptr<SectionPairRow> row = dynamic_pointer_cast<SectionPairRow>(serializable->getValue());

    ASSERT_STREQ("favourite-color", row->getKey().c_str());
    ASSERT_STREQ("blue", dynamic_pointer_cast<SectionPairRowSingleValue>(row->getValue())->get().c_str());
  }

  TEST_P(SerializableSectionPairRowTest_LineBreakTest, unmarshal_list_value)
  {
    string newLine = GetParam();
    shared_ptr<SerializableSectionPairRow> serializable = SerializableSectionPairRowProvider::createListValueForUnmarshal(newLine);

    string data = "favourite-colors:" + newLine + "  blue" + newLine + "  red" + newLine + "  purple" + newLine;
    serializable->unmarshal(data);
    shared_ptr<SectionPairRow> row = dynamic_pointer_cast<SectionPairRow>(serializable->getValue());

    ASSERT_STREQ("favourite-colors", row->getKey().c_str());
    ASSERT_EQ(3, dynamic_pointer_cast<SectionPairRowListValue>(row->getValue())->getSize());
    ASSERT_STREQ("blue", dynamic_pointer_cast<SectionPairRowListValue>(row->getValue())->get(0).c_str());
    ASSERT_STREQ("red", dynamic_pointer_cast<SectionPairRowListValue>(row->getValue())->get(1).c_str());
    ASSERT_STREQ("purple", dynamic_pointer_cast<SectionPairRowListValue>(row->getValue())->get(2).c_str());
  }

  TEST_P(SerializableSectionPairRowTest_IsValidSingleValueTest, unmarshal_single_value)
  {
    shared_ptr<SerializableSectionPairRow> serializable = SerializableSectionPairRowProvider::createSingleValueForUnmarshal(NewLine::getWindowsNewLine());
    serializable->unmarshal(GetParam().at(0));
    shared_ptr<SectionPairRow> row = dynamic_pointer_cast<SectionPairRow>(serializable->getValue());

    ASSERT_STREQ(GetParam().at(1).c_str(), row->getKey().c_str());
    ASSERT_STREQ(GetParam().at(2).c_str(), dynamic_pointer_cast<SectionPairRowSingleValue>(row->getValue())->get().c_str());
  }

  TEST_P(SerializableSectionPairRowTest_IsInvalidSingleValueTest, unmarshal_single_value)
  {
    shared_ptr<SerializableSectionPairRow> serializable = SerializableSectionPairRowProvider::createSingleValueForUnmarshal(NewLine::get());

    EXPECT_THROW(
        {
          try
          {
            serializable->unmarshal(GetParam());
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_P(SerializableSectionPairRowTest_IsInvalidListValueTest, unmarshal_list_value)
  {
    shared_ptr<SerializableSectionPairRow> serializable = SerializableSectionPairRowProvider::createListValueForUnmarshal(NewLine::get());

    EXPECT_THROW(
        {
          try
          {
            serializable->unmarshal(GetParam());
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  INSTANTIATE_TEST_SUITE_P(LineBreakTest, SerializableSectionPairRowTest_LineBreakTest, Values(NewLine::getUnixNewLine(), NewLine::getWindowsNewLine()));
  INSTANTIATE_TEST_SUITE_P(IsValidSingleValueTest, SerializableSectionPairRowTest_IsValidSingleValueTest, Values(array<string, 3>{"favourite-color=blue", "favourite-color", "blue"}, array<string, 3>{"hair-color=red" + NewLine::getWindowsNewLine(), "hair-color", "red"}));
  INSTANTIATE_TEST_SUITE_P(IsInvalidSingleValueTest, SerializableSectionPairRowTest_IsInvalidSingleValueTest, Values("favourite-color", "color="));
  INSTANTIATE_TEST_SUITE_P(IsInvalidListValueTest, SerializableSectionPairRowTest_IsInvalidListValueTest, Values("favourite-color:\n", "colors:\r\n  blue"));
}
