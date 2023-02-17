/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-14
* Changed:         2023-02-17
*
* */

#include <gtest/gtest.h>
#include <ls-std-io-test.hpp>
#include <ls-std/ls-std-core.hpp>
#include <ls-std/ls-std-io.hpp>
#include <memory>

using namespace ls::std::core;
using namespace ls::std::core::type;
using namespace ls::std::io;
using namespace ::std;
using namespace test::io;

namespace
{
  class SerializableSectionPairSectionTest : public ::testing::Test
  {
    protected:

      SerializableSectionPairSectionTest() = default;
      ~SerializableSectionPairSectionTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(SerializableSectionPairSectionTest, constructor_no_reference)
  {
    EXPECT_THROW(
        {
          try
          {
            SerializableSectionPairSection serializable(nullptr);
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(SerializableSectionPairSectionTest, getClassName)
  {
    ASSERT_STREQ("SerializableSectionPairSection", SerializableSectionPairSection{make_shared<SectionPairSection>("general")}.getClassName().c_str());
  }

  TEST_F(SerializableSectionPairSectionTest, getValue)
  {
    SerializableSectionPairSection serializable{make_shared<SectionPairSection>("general")};
    ASSERT_TRUE(serializable.getValue() != nullptr);
  }

  TEST_F(SerializableSectionPairSectionTest, marshal_sandra)
  {
    shared_ptr<SectionPairSection> section = SectionPairSectionProvider::createSectionWithSandraExample();
    SerializableSectionPairSection serializable{section};
    byte_field expected = SectionPairSectionProvider::createSerializedSectionWithSandraExample();
    byte_field actual = serializable.marshal();

    ASSERT_STREQ(expected.c_str(), actual.c_str());
  }

  TEST_F(SerializableSectionPairSectionTest, marshal_tom)
  {
    shared_ptr<SectionPairSection> section = SectionPairSectionProvider::createSectionWithTomExample();
    SerializableSectionPairSection serializable{section};
    byte_field expected = SectionPairSectionProvider::createSerializedSectionWithTomExample();
    byte_field actual = serializable.marshal();

    ASSERT_STREQ(expected.c_str(), actual.c_str());
  }

  TEST_F(SerializableSectionPairSectionTest, unmarshal_sandra)
  {
    shared_ptr<SectionPairSection> section = make_shared<SectionPairSection>("tmp-id");
    SerializableSectionPairSection serializable{section};
    serializable.unmarshal(SectionPairSectionProvider::createSerializedSectionWithSandraExample());

    ASSERT_STREQ("general", section->getSectionId().c_str());
    ASSERT_EQ(3, section->getRowAmount());
    ASSERT_STREQ("name", section->get(0)->getKey().c_str());
    ASSERT_STREQ("Sandra", dynamic_pointer_cast<SectionPairRowSingleValue>(section->get(0)->getValue())->get().c_str());

    ASSERT_STREQ("age", section->get(1)->getKey().c_str());
    ASSERT_STREQ("24", dynamic_pointer_cast<SectionPairRowSingleValue>(section->get(1)->getValue())->get().c_str());

    ASSERT_STREQ("hobbies", section->get(2)->getKey().c_str());
    shared_ptr<SectionPairRowListValue> listRow = dynamic_pointer_cast<SectionPairRowListValue>(section->get(2)->getValue());
    ASSERT_EQ(3, listRow->getSize());
    ASSERT_STREQ("swimming", listRow->get(0).c_str());
    ASSERT_STREQ("cycling", listRow->get(1).c_str());
    ASSERT_STREQ("singing", listRow->get(2).c_str());
  }

  TEST_F(SerializableSectionPairSectionTest, unmarshal_tom)
  {
    shared_ptr<SectionPairSection> section = make_shared<SectionPairSection>("tmp-id");
    SerializableSectionPairSection serializable{section};
    serializable.unmarshal(SectionPairSectionProvider::createSerializedSectionWithTomExample());

    ASSERT_STREQ("general", section->getSectionId().c_str());
    ASSERT_EQ(3, section->getRowAmount());
    ASSERT_STREQ("name", section->get(0)->getKey().c_str());
    ASSERT_STREQ("Tom", dynamic_pointer_cast<SectionPairRowSingleValue>(section->get(0)->getValue())->get().c_str());
    ASSERT_STREQ("jobs", section->get(1)->getKey().c_str());
    shared_ptr<SectionPairRowListValue> listRow = dynamic_pointer_cast<SectionPairRowListValue>(section->get(1)->getValue());
    ASSERT_EQ(2, listRow->getSize());
    ASSERT_STREQ("Farmer", listRow->get(0).c_str());
    ASSERT_STREQ("Bounty Hunter", listRow->get(1).c_str());
    ASSERT_STREQ("age", section->get(2)->getKey().c_str());
    ASSERT_STREQ("33", dynamic_pointer_cast<SectionPairRowSingleValue>(section->get(2)->getValue())->get().c_str());
  }
}
