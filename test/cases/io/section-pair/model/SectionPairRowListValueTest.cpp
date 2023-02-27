/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-10
* Changed:         2023-02-23
*
* */

#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>
#include <ls-std/ls-std-io.hpp>

using ls::std::core::IllegalArgumentException;
using ls::std::core::IndexOutOfBoundsException;
using ls::std::io::NewLine;
using ls::std::io::section_pair_row_value;
using ls::std::io::SectionPairRowEnumType;
using ls::std::io::SectionPairRowListValue;
using std::make_shared;
using std::shared_ptr;
using std::string;
using testing::Test;

namespace
{
  class SectionPairRowListValueTest : public Test
  {
    protected:

      SectionPairRowListValueTest() = default;
      ~SectionPairRowListValueTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(SectionPairRowListValueTest, add)
  {
    SectionPairRowListValue list{};
    list.add("Music");

    ASSERT_TRUE(list.getSize() == 1);
    ASSERT_STREQ("Music", list.get(0).c_str());
  }

  TEST_F(SectionPairRowListValueTest, add_empty_value)
  {
    SectionPairRowListValue list{};

    EXPECT_THROW(
        {
          try
          {
            list.add("");
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(SectionPairRowListValueTest, add_invalid_value)
  {
    SectionPairRowListValue list{};

    EXPECT_THROW(
        {
          try
          {
            list.add("=33");
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(SectionPairRowListValueTest, clear)
  {
    SectionPairRowListValue list{};
    list.add("Music");

    ASSERT_EQ(1, list.getSize());
    list.clear();
    ASSERT_TRUE(list.getList().empty());
  }

  TEST_F(SectionPairRowListValueTest, get_no_elements)
  {
    SectionPairRowListValue list{};

    EXPECT_THROW(
        {
          try
          {
            section_pair_row_value value = list.get(0);
          }
          catch (const IndexOutOfBoundsException &_exception)
          {
            throw;
          }
        },
        IndexOutOfBoundsException);
  }

  TEST_F(SectionPairRowListValueTest, getClassName)
  {
    ASSERT_STREQ("SectionPairRowListValue", SectionPairRowListValue{}.getClassName().c_str());
  }

  TEST_F(SectionPairRowListValueTest, getList)
  {
    SectionPairRowListValue list{};
    ASSERT_TRUE(list.getList().empty());
  }

  TEST_F(SectionPairRowListValueTest, getSize)
  {
    SectionPairRowListValue list{};
    ASSERT_EQ(0, list.getSize());
  }

  TEST_F(SectionPairRowListValueTest, getType)
  {
    SectionPairRowListValue list{};
    ASSERT_EQ(SectionPairRowEnumType::SECTION_PAIR_ROW_LIST_VALUE, list.getType());
  }

  TEST_F(SectionPairRowListValueTest, marshal)
  {
    shared_ptr<SectionPairRowListValue> value = make_shared<SectionPairRowListValue>();
    value->add("Drumming");
    value->add("Reading");
    value->add("Coding");
    string newLine = NewLine::get();

    string expected = "  Drumming" + newLine + "  Reading" + newLine + "  Coding" + newLine;

    ASSERT_STREQ(expected.c_str(), value->marshal().c_str());
  }

  TEST_F(SectionPairRowListValueTest, unmarshal)
  {
    shared_ptr<SectionPairRowListValue> value = make_shared<SectionPairRowListValue>();
    string newLine = NewLine::get();
    string serializedListValue = "  Drumming" + newLine + "  Reading" + newLine + "  Coding" + newLine;
    value->unmarshal(serializedListValue);

    ASSERT_EQ(3, value->getSize());
    ASSERT_STREQ("Drumming", value->get(0).c_str());
    ASSERT_STREQ("Reading", value->get(1).c_str());
    ASSERT_STREQ("Coding", value->get(2).c_str());
  }
}
