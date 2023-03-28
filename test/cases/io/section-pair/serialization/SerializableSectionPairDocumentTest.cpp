/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-16
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
using ls::std::io::SectionPairDocument;
using ls::std::io::SectionPairRowListValue;
using ls::std::io::SectionPairRowSingleValue;
using ls::std::io::SectionPairSection;
using ls::std::io::SerializableSectionPairDocument;
using ls::std::io::SerializableSectionPairParameter;
using std::dynamic_pointer_cast;
using std::make_shared;
using std::shared_ptr;
using std::string;
using test::io::SectionPairDocumentProvider;
using testing::Test;
using testing::TestWithParam;
using testing::Values;

namespace
{
  class SerializableSectionPairDocumentTest : public Test
  {
    public:

      SerializableSectionPairDocumentTest() = default;
      ~SerializableSectionPairDocumentTest() override = default;
  };

  class SerializableSectionPairDocumentTest_LineBreakTest : public TestWithParam<string>
  {
    public:

      SerializableSectionPairDocumentTest_LineBreakTest() = default;
      ~SerializableSectionPairDocumentTest_LineBreakTest() override = default;
  };

  TEST_F(SerializableSectionPairDocumentTest, constructor_no_value)
  {
    SerializableSectionPairParameter parameter{};

    EXPECT_THROW(
        {
          try
          {
            SerializableSectionPairDocument serializable = SerializableSectionPairDocument(parameter);
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(SerializableSectionPairDocumentTest, getClassName)
  {
    SerializableSectionPairParameter parameter{};
    parameter.setValue(make_shared<SectionPairDocument>());

    ASSERT_STREQ("SerializableSectionPairDocument", SerializableSectionPairDocument{parameter}.getClassName().c_str());
  }

  TEST_F(SerializableSectionPairDocumentTest, getValue)
  {
    SerializableSectionPairParameter parameter{};
    parameter.setValue(make_shared<SectionPairDocument>());
    SerializableSectionPairDocument serializable(parameter);

    ASSERT_TRUE(serializable.getValue() != nullptr);
  }

  TEST_P(SerializableSectionPairDocumentTest_LineBreakTest, marshal)
  {
    string newLine = GetParam();
    SerializableSectionPairParameter parameter{};
    parameter.setValue(SectionPairDocumentProvider::createDocument());
    parameter.setNewLine(newLine);
    SerializableSectionPairDocument serializable(parameter);
    byte_field expected = SectionPairDocumentProvider::createSerializedDocument(newLine);

    ASSERT_STREQ(expected.c_str(), serializable.marshal().c_str());
  }

  TEST_P(SerializableSectionPairDocumentTest_LineBreakTest, unmarshal)
  {
    string newLine = GetParam();
    SerializableSectionPairParameter parameter{};
    parameter.setValue(make_shared<SectionPairDocument>());
    parameter.setNewLine(newLine);
    SerializableSectionPairDocument serializable(parameter);
    serializable.unmarshal(SectionPairDocumentProvider::createSerializedDocument(newLine));
    shared_ptr<SectionPairDocument> document = dynamic_pointer_cast<SectionPairDocument>(serializable.getValue());

    ASSERT_EQ(2, document->getAmountOfSections());

    // check general section

    shared_ptr<SectionPairSection> general = document->get(0);
    ASSERT_STREQ("general", general->getSectionId().c_str());
    ASSERT_EQ(3, general->getRowAmount());

    ASSERT_STREQ("name", general->get(0)->getKey().c_str());
    ASSERT_STREQ("Sandra", dynamic_pointer_cast<SectionPairRowSingleValue>(general->get(0)->getValue())->get().c_str());

    ASSERT_STREQ("age", general->get(1)->getKey().c_str());
    ASSERT_STREQ("24", dynamic_pointer_cast<SectionPairRowSingleValue>(general->get(1)->getValue())->get().c_str());

    ASSERT_STREQ("hobbies", general->get(2)->getKey().c_str());
    shared_ptr<SectionPairRowListValue> hobbies = dynamic_pointer_cast<SectionPairRowListValue>(general->get(2)->getValue());
    ASSERT_EQ(3, hobbies->getSize());
    ASSERT_STREQ("swimming", hobbies->get(0).c_str());
    ASSERT_STREQ("cycling", hobbies->get(1).c_str());
    ASSERT_STREQ("singing", hobbies->get(2).c_str());

    // check physical section

    shared_ptr<SectionPairSection> physical = document->get(1);
    ASSERT_STREQ("physical", physical->getSectionId().c_str());
    ASSERT_EQ(3, physical->getRowAmount());

    ASSERT_STREQ("eye-color", physical->get(0)->getKey().c_str());
    ASSERT_STREQ("blue", dynamic_pointer_cast<SectionPairRowSingleValue>(physical->get(0)->getValue())->get().c_str());

    ASSERT_STREQ("hair-color", physical->get(1)->getKey().c_str());
    ASSERT_STREQ("red", dynamic_pointer_cast<SectionPairRowSingleValue>(physical->get(1)->getValue())->get().c_str());

    ASSERT_STREQ("height", physical->get(2)->getKey().c_str());
    ASSERT_STREQ("167", dynamic_pointer_cast<SectionPairRowSingleValue>(physical->get(2)->getValue())->get().c_str());
  }

  INSTANTIATE_TEST_SUITE_P(LineBreakTest, SerializableSectionPairDocumentTest_LineBreakTest, Values(NewLine::getUnixNewLine(), NewLine::getWindowsNewLine()));
}
