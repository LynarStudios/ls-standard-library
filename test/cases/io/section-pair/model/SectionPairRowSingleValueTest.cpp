/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-10
* Changed:         2023-03-25
*
* */

#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>
#include <ls-std/ls-std-io.hpp>

using ls::std::core::IllegalArgumentException;
using ls::std::core::type::byte_field;
using ls::std::io::NewLine;
using ls::std::io::SectionPairRowEnumType;
using ls::std::io::SectionPairRowSingleValue;
using std::make_shared;
using std::shared_ptr;
using testing::Test;

namespace
{
  class SectionPairRowSingleValueTest : public Test
  {
    public:

      SectionPairRowSingleValueTest() = default;
      ~SectionPairRowSingleValueTest() override = default;
  };

  TEST_F(SectionPairRowSingleValueTest, constructor_empty_value)
  {
    EXPECT_THROW(
        {
          try
          {
            SectionPairRowSingleValue value{""};
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(SectionPairRowSingleValueTest, constructor_invalid_value)
  {
    EXPECT_THROW(
        {
          try
          {
            SectionPairRowSingleValue value{"=33"};
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(SectionPairRowSingleValueTest, get)
  {
    SectionPairRowSingleValue value{"blue"};
    ASSERT_STREQ("blue", value.get().c_str());
  }

  TEST_F(SectionPairRowSingleValueTest, getClassName)
  {
    ASSERT_STREQ("SectionPairRowSingleValue", SectionPairRowSingleValue{"blue"}.getClassName().c_str());
  }

  TEST_F(SectionPairRowSingleValueTest, getType)
  {
    SectionPairRowSingleValue value{"blue"};
    ASSERT_EQ(SectionPairRowEnumType::SECTION_PAIR_ROW_SINGLE_VALUE, value.getType());
  }

  TEST_F(SectionPairRowSingleValueTest, marshal)
  {
    shared_ptr<SectionPairRowSingleValue> value = make_shared<SectionPairRowSingleValue>("empty");
    byte_field expected = "empty" + NewLine::get();
    byte_field actual = value->marshal();

    ASSERT_STREQ(expected.c_str(), actual.c_str());
  }

  TEST_F(SectionPairRowSingleValueTest, set_empty_value)
  {
    SectionPairRowSingleValue value{"empty"};

    EXPECT_THROW(
        {
          try
          {
            value.set("");
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(SectionPairRowSingleValueTest, set_invalid_value)
  {
    SectionPairRowSingleValue value{"empty"};

    EXPECT_THROW(
        {
          try
          {
            value.set("=33");
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(SectionPairRowSingleValueTest, unmarshal)
  {
    shared_ptr<SectionPairRowSingleValue> value = make_shared<SectionPairRowSingleValue>("empty");
    value->unmarshal("blue");

    ASSERT_STREQ("blue", value->get().c_str());
  }
}
