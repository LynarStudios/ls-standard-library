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
using namespace ls::std::core::type;
using namespace ls::std::io;
using namespace ::std;

namespace
{
  class SerializableSectionPairRowSingleValueTest : public ::testing::Test
  {
    protected:

      SerializableSectionPairRowSingleValueTest() = default;
      ~SerializableSectionPairRowSingleValueTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(SerializableSectionPairRowSingleValueTest, constructor_no_reference)
  {
    EXPECT_THROW(
        {
          try
          {
            SerializableSectionPairRowSingleValue serializable(nullptr);
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
    ASSERT_STREQ("SerializableSectionPairRowSingleValue", SerializableSectionPairRowSingleValue{make_shared<SectionPairRowSingleValue>("empty")}.getClassName().c_str());
  }

  TEST_F(SerializableSectionPairRowSingleValueTest, getValue)
  {
    shared_ptr<SectionPairRowSingleValue> value = make_shared<SectionPairRowSingleValue>("empty");
    SerializableSectionPairRowSingleValue serializable(value);

    ASSERT_TRUE(value == serializable.getValue());
  }

  TEST_F(SerializableSectionPairRowSingleValueTest, marshal)
  {
    SerializableSectionPairRowSingleValue serializable(make_shared<SectionPairRowSingleValue>("empty"));
    byte_field expected = "empty" + NewLine::get();
    byte_field actual = serializable.marshal();

    ASSERT_STREQ(expected.c_str(), actual.c_str());
  }

  TEST_F(SerializableSectionPairRowSingleValueTest, unmarshal)
  {
    shared_ptr<SectionPairRowSingleValue> value = make_shared<SectionPairRowSingleValue>("empty");
    SerializableSectionPairRowSingleValue serializable(value);
    serializable.unmarshal("blue");

    ASSERT_STREQ("blue", value->get().c_str());
  }

  TEST_F(SerializableSectionPairRowSingleValueTest, unmarshal_empty_string)
  {
    SerializableSectionPairRowSingleValue serializable(make_shared<SectionPairRowSingleValue>("empty"));

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
