/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-08
* Changed:         2023-02-22
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
  class SectionPairRowTest : public ::testing::Test
  {
    protected:

      SectionPairRowTest() = default;
      ~SectionPairRowTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(SectionPairRowTest, constructor_empty_key)
  {
    EXPECT_THROW(
        {
          try
          {
            SectionPairRow row("", SectionPairRowEnumType::SECTION_PAIR_ROW_SINGLE_VALUE);
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(SectionPairRowTest, constructor_invalid_key)
  {
    EXPECT_THROW(
        {
          try
          {
            SectionPairRow row("-tmp-key", SectionPairRowEnumType::SECTION_PAIR_ROW_SINGLE_VALUE);
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(SectionPairRowTest, getClassName)
  {
    ASSERT_STREQ("SectionPairRow", SectionPairRow("tmp-key", SectionPairRowEnumType::SECTION_PAIR_ROW_LIST_VALUE).getClassName().c_str());
  }

  TEST_F(SectionPairRowTest, getKey)
  {
    ls::std::io::section_pair_identifier key = "tmp-key";

    SectionPairRow row(key, SectionPairRowEnumType::SECTION_PAIR_ROW_SINGLE_VALUE);
    ASSERT_STREQ(key.c_str(), row.getKey().c_str());
  }

  TEST_F(SectionPairRowTest, getValue)
  {
    SectionPairRow row("hobbies", SectionPairRowEnumType::SECTION_PAIR_ROW_LIST_VALUE);
    shared_ptr<SectionPairRowValue> value = row.getValue();

    ASSERT_TRUE(value != nullptr);
    ASSERT_EQ(SectionPairRowEnumType::SECTION_PAIR_ROW_LIST_VALUE, value->getType());
  }

  TEST_F(SectionPairRowTest, isSingleValue)
  {
    ASSERT_TRUE(SectionPairRow("tmp-key", SectionPairRowEnumType::SECTION_PAIR_ROW_SINGLE_VALUE).isSingleValue());
  }

  TEST_F(SectionPairRowTest, isList)
  {
    ASSERT_FALSE(SectionPairRow("tmp-key", SectionPairRowEnumType::SECTION_PAIR_ROW_SINGLE_VALUE).isList());
  }

  TEST_F(SectionPairRowTest, marshal_single_value)
  {
    shared_ptr<SectionPairRow> row = make_shared<SectionPairRow>("favourite-color", SectionPairRowEnumType::SECTION_PAIR_ROW_SINGLE_VALUE);
    shared_ptr<SectionPairRowSingleValue> singleValue = dynamic_pointer_cast<SectionPairRowSingleValue>(row->getValue());
    singleValue->set("blue");
    byte_field expected = "favourite-color=blue" + NewLine::get();
    byte_field actual = row->marshal();

    ASSERT_STREQ(expected.c_str(), actual.c_str());
  }

  TEST_F(SectionPairRowTest, marshal_list_value)
  {
    shared_ptr<SectionPairRow> row = make_shared<SectionPairRow>("favourite-colors", SectionPairRowEnumType::SECTION_PAIR_ROW_LIST_VALUE);
    shared_ptr<SectionPairRowListValue> listValue = dynamic_pointer_cast<SectionPairRowListValue>(row->getValue());
    listValue->add("blue");
    listValue->add("red");
    listValue->add("purple");

    string expected = "favourite-colors:" + NewLine::get() + "  blue" + NewLine::get() + "  red" + NewLine::get() + "  purple" + NewLine::get();

    ASSERT_STREQ(expected.c_str(), row->marshal().c_str());
  }

  TEST_F(SectionPairRowTest, setKey)
  {
    SectionPairRow row("hobbies", SectionPairRowEnumType::SECTION_PAIR_ROW_LIST_VALUE);
    row.setKey("colors");

    ASSERT_STREQ("colors", row.getKey().c_str());
  }

  TEST_F(SectionPairRowTest, setKey_empty_key)
  {
    SectionPairRow row("tmp-key", SectionPairRowEnumType::SECTION_PAIR_ROW_SINGLE_VALUE);

    EXPECT_THROW(
        {
          try
          {
            row.setKey("");
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(SectionPairRowTest, setKey_invalid_key)
  {
    SectionPairRow row("tmp-key", SectionPairRowEnumType::SECTION_PAIR_ROW_SINGLE_VALUE);

    EXPECT_THROW(
        {
          try
          {
            row.setKey("=33");
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(SectionPairRowTest, unmarshal_single_value)
  {
    shared_ptr<SectionPairRow> row = make_shared<SectionPairRow>("tmp-key", SectionPairRowEnumType::SECTION_PAIR_ROW_SINGLE_VALUE);
    shared_ptr<SectionPairRowSingleValue> singleValue = dynamic_pointer_cast<SectionPairRowSingleValue>(row->getValue());

    row->unmarshal("favourite-color=blue");

    ASSERT_STREQ("favourite-color", row->getKey().c_str());
    ASSERT_STREQ("blue", singleValue->get().c_str());
  }

  TEST_F(SectionPairRowTest, unmarshal_list_value)
  {
    shared_ptr<SectionPairRow> row = make_shared<SectionPairRow>("tmp-key", SectionPairRowEnumType::SECTION_PAIR_ROW_LIST_VALUE);
    shared_ptr<SectionPairRowListValue> listValue = dynamic_pointer_cast<SectionPairRowListValue>(row->getValue());

    string data = "favourite-colors:" + NewLine::get() + "  blue" + NewLine::get() + "  red" + NewLine::get() + "  purple" + NewLine::get();
    row->unmarshal(data);

    ASSERT_STREQ("favourite-colors", row->getKey().c_str());
    ASSERT_STREQ("blue", listValue->get(0).c_str());
    ASSERT_STREQ("red", listValue->get(1).c_str());
    ASSERT_STREQ("purple", listValue->get(2).c_str());
    ASSERT_EQ(3, listValue->getSize());
  }
}
