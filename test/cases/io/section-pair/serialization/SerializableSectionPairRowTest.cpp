/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-12
* Changed:         2023-02-12
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
  class SerializableSectionPairRowTest : public ::testing::Test
  {
    protected:

      SerializableSectionPairRowTest() = default;
      ~SerializableSectionPairRowTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(SerializableSectionPairRowTest, constructor_no_reference)
  {
    EXPECT_THROW(
        {
          try
          {
            SerializableSectionPairRow serializable(nullptr);
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(SerializableSectionPairRowTest, getValue)
  {
    SerializableSectionPairRow serializable{make_shared<SectionPairRow>("tmp-key", SectionPairRowEnumType::SECTION_PAIR_ROW_SINGLE_VALUE)};
    ASSERT_TRUE(serializable.getValue() != nullptr);
  }

  TEST_F(SerializableSectionPairRowTest, marshal_single_value)
  {
    shared_ptr<SectionPairRow> row = make_shared<SectionPairRow>("favourite-color", SectionPairRowEnumType::SECTION_PAIR_ROW_SINGLE_VALUE);
    shared_ptr<SectionPairRowSingleValue> singleValue = ::std::dynamic_pointer_cast<SectionPairRowSingleValue>(row->getValue());
    singleValue->set("blue");
    singleValue->setSerializable(make_shared<SerializableSectionPairRowSingleValue>(singleValue));
    SerializableSectionPairRow serializable{row};

    ASSERT_STREQ("favourite-color=blue", serializable.marshal().c_str());
  }

  TEST_F(SerializableSectionPairRowTest, marshal_list_value)
  {
    shared_ptr<SectionPairRow> row = make_shared<SectionPairRow>("favourite-colors", SectionPairRowEnumType::SECTION_PAIR_ROW_LIST_VALUE);
    shared_ptr<SectionPairRowListValue> listValue = ::std::dynamic_pointer_cast<SectionPairRowListValue>(row->getValue());
    listValue->add("blue");
    listValue->add("red");
    listValue->add("purple");
    listValue->setSerializable(make_shared<SerializableSectionPairRowListValue>(listValue));
    SerializableSectionPairRow serializable{row};

    string expected = "favourite-colors:" + NewLine::get() + "  blue" + NewLine::get() + "  red" + NewLine::get() + "  purple" + NewLine::get();

    ASSERT_STREQ(expected.c_str(), serializable.marshal().c_str());
  }

  TEST_F(SerializableSectionPairRowTest, unmarshal_single_value)
  {
    shared_ptr<SectionPairRow> row = make_shared<SectionPairRow>("tmp-key", SectionPairRowEnumType::SECTION_PAIR_ROW_SINGLE_VALUE);
    shared_ptr<SectionPairRowSingleValue> singleValue = ::std::dynamic_pointer_cast<SectionPairRowSingleValue>(row->getValue());
    singleValue->setSerializable(make_shared<SerializableSectionPairRowSingleValue>(singleValue));
    SerializableSectionPairRow serializable{row};

    serializable.unmarshal("favourite-color=blue");

    ASSERT_STREQ("favourite-color", row->getKey().c_str());
    ASSERT_STREQ("blue", singleValue->get().c_str());
  }

  TEST_F(SerializableSectionPairRowTest, unmarshal_list_value)
  {
    shared_ptr<SectionPairRow> row = make_shared<SectionPairRow>("tmp-key", SectionPairRowEnumType::SECTION_PAIR_ROW_LIST_VALUE);
    shared_ptr<SectionPairRowListValue> listValue = ::std::dynamic_pointer_cast<SectionPairRowListValue>(row->getValue());
    listValue->setSerializable(make_shared<SerializableSectionPairRowListValue>(listValue));
    SerializableSectionPairRow serializable{row};

    string data = "favourite-colors:" + NewLine::get() + "  blue" + NewLine::get() + "  red" + NewLine::get() + "  purple" + NewLine::get();
    serializable.unmarshal(data);

    ASSERT_STREQ("favourite-colors", row->getKey().c_str());
    ASSERT_EQ(3, listValue->getSize());
    ASSERT_STREQ("blue", listValue->get(0).c_str());
    ASSERT_STREQ("red", listValue->get(1).c_str());
    ASSERT_STREQ("purple", listValue->get(2).c_str());
  }
}
