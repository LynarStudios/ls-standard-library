/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-11
* Changed:         2023-02-17
*
* */

#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>
#include <ls-std/ls-std-io.hpp>
#include <memory>

using namespace ls::std::core;
using namespace ls::std::io;
using namespace ::std;

namespace
{
  class SerializableSectionPairRowListValueTest : public ::testing::Test
  {
    protected:

      SerializableSectionPairRowListValueTest() = default;
      ~SerializableSectionPairRowListValueTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
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

  TEST_F(SerializableSectionPairRowListValueTest, marshal_with_unix_new_line)
  {
    SerializableSectionPairParameter parameter{};
    shared_ptr<SectionPairRowListValue> value = make_shared<SectionPairRowListValue>();
    value->add("Drumming");
    value->add("Reading");
    value->add("Coding");
    parameter.setValue(value);
    SerializableSectionPairRowListValue serializable(parameter);
    string newLine = NewLine::getUnixNewLine();

    string expected = "  Drumming" + newLine + "  Reading" + newLine + "  Coding" + newLine;

    ASSERT_STREQ(expected.c_str(), serializable.marshal().c_str());
  }

  TEST_F(SerializableSectionPairRowListValueTest, marshal_with_windows_new_line)
  {
    SerializableSectionPairParameter parameter{};
    shared_ptr<SectionPairRowListValue> value = make_shared<SectionPairRowListValue>();
    value->add("Drumming");
    value->add("Reading");
    value->add("Coding");
    parameter.setValue(value);
    string newLine = NewLine::getWindowsNewLine();
    parameter.setNewLine(newLine);
    SerializableSectionPairRowListValue serializable(parameter);

    string expected = "  Drumming" + newLine + "  Reading" + newLine + "  Coding" + newLine;
    string actual = serializable.marshal();

    ASSERT_STREQ(expected.c_str(), actual.c_str());
  }

  TEST_F(SerializableSectionPairRowListValueTest, unmarshal_with_unix_new_line)
  {
    SerializableSectionPairParameter parameter{};
    shared_ptr<SectionPairRowListValue> value = make_shared<SectionPairRowListValue>();
    parameter.setValue(value);
    SerializableSectionPairRowListValue serializable(parameter);
    string newLine = NewLine::getUnixNewLine();
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
}
