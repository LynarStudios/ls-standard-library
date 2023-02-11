/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-11
* Changed:         2023-02-11
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
    EXPECT_THROW(
        {
          try
          {
            SerializableSectionPairRowListValue serializable(nullptr);
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(SerializableSectionPairRowListValueTest, getValue)
  {
    shared_ptr<SectionPairRowListValue> value = make_shared<SectionPairRowListValue>();
    SerializableSectionPairRowListValue serializable(value);

    ASSERT_TRUE(value == serializable.getValue());
  }

  TEST_F(SerializableSectionPairRowListValueTest, marshal)
  {
    shared_ptr<SectionPairRowListValue> value = make_shared<SectionPairRowListValue>();
    value->add("Drumming");
    value->add("Reading");
    value->add("Coding");
    SerializableSectionPairRowListValue serializable(value);

    ::std::string expected = "  Drumming" + NewLine::get() + "  Reading" + NewLine::get() + "  Coding" + NewLine::get();

    ASSERT_STREQ(expected.c_str(), serializable.marshal().c_str());
  }

  TEST_F(SerializableSectionPairRowListValueTest, unmarshal)
  {
    shared_ptr<SectionPairRowListValue> value = make_shared<SectionPairRowListValue>();
    SerializableSectionPairRowListValue serializable(value);
    ::std::string serializedListValue = "  Drumming" + NewLine::get() + "  Reading" + NewLine::get() + "  Coding" + NewLine::get();
    serializable.unmarshal(serializedListValue);

    ASSERT_EQ(3, value->getSize());
    ASSERT_STREQ("Drumming", value->get(0).c_str());
    ASSERT_STREQ("Reading", value->get(1).c_str());
    ASSERT_STREQ("Coding", value->get(2).c_str());
  }

  TEST_F(SerializableSectionPairRowListValueTest, unmarshal_empty_string)
  {
    SerializableSectionPairRowListValue serializable(make_shared<SectionPairRowListValue>());

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
