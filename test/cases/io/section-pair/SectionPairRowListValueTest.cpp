/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-10
* Changed:         2023-02-10
*
* */

#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>
#include <ls-std/ls-std-io.hpp>

using namespace ls::std::core;
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
}
