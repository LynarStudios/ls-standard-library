/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-10
* Changed:         2023-02-12
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
  class SectionPairRowListValueTest : public ::testing::Test
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

  TEST_F(SectionPairRowListValueTest, getClassName)
  {
    ASSERT_STREQ("SectionPairRowListValue", SectionPairRowListValue{}.getClassName().c_str());
  }

  TEST_F(SectionPairRowListValueTest, get_no_elements)
  {
    SectionPairRowListValue list{};

    EXPECT_THROW(
        {
          try
          {
            ls::std::io::section_pair_row_value value = list.get(0);
          }
          catch (const IndexOutOfBoundsException &_exception)
          {
            throw;
          }
        },
        IndexOutOfBoundsException);
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
    ASSERT_EQ(ls::std::io::SECTION_PAIR_ROW_LIST_VALUE, list.getType());
  }

  TEST_F(SectionPairRowListValueTest, marshal)
  {
    shared_ptr<SectionPairRowListValue> value = make_shared<SectionPairRowListValue>();
    value->setSerializable(make_shared<SerializableSectionPairRowListValue>(value));
    value->add("Drumming");
    value->add("Reading");
    value->add("Coding");

    ::std::string expected = "  Drumming" + NewLine::get() + "  Reading" + NewLine::get() + "  Coding" + NewLine::get();

    ASSERT_STREQ(expected.c_str(), value->marshal().c_str());
  }

  TEST_F(SectionPairRowListValueTest, marshal_no_serializable)
  {
    SectionPairRowListValue list{};

    EXPECT_THROW(
        {
          try
          {
            byte_field data = list.marshal();
          }
          catch (const NullPointerException &_exception)
          {
            throw;
          }
        },
        NullPointerException);
  }

  TEST_F(SectionPairRowListValueTest, setSerializable_no_reference)
  {
    SectionPairRowListValue list{};

    EXPECT_THROW(
        {
          try
          {
            list.setSerializable(nullptr);
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(SectionPairRowListValueTest, unmarshal)
  {
    shared_ptr<SectionPairRowListValue> value = make_shared<SectionPairRowListValue>();
    value->setSerializable(make_shared<SerializableSectionPairRowListValue>(value));
    ::std::string serializedListValue = "  Drumming" + NewLine::get() + "  Reading" + NewLine::get() + "  Coding" + NewLine::get();
    value->unmarshal(serializedListValue);

    ASSERT_EQ(3, value->getSize());
    ASSERT_STREQ("Drumming", value->get(0).c_str());
    ASSERT_STREQ("Reading", value->get(1).c_str());
    ASSERT_STREQ("Coding", value->get(2).c_str());
  }

  TEST_F(SectionPairRowListValueTest, unmarshal_no_serializable)
  {
    SectionPairRowListValue list{};

    EXPECT_THROW(
        {
          try
          {
            list.unmarshal("  Blue\nYellow\n");
          }
          catch (const NullPointerException &_exception)
          {
            throw;
          }
        },
        NullPointerException);
  }
}
