/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-15
* Changed:         2023-03-25
*
* */

#include <gtest/gtest.h>
#include <ls-std-io-test.hpp>
#include <ls-std/ls-std-core.hpp>
#include <ls-std/ls-std-io.hpp>
#include <memory>

using ls::std::core::IllegalArgumentException;
using ls::std::core::IndexOutOfBoundsException;
using ls::std::core::type::byte_field;
using ls::std::io::NewLine;
using ls::std::io::SectionPairDocument;
using ls::std::io::SectionPairRowListValue;
using ls::std::io::SectionPairRowSingleValue;
using ls::std::io::SectionPairSection;
using std::dynamic_pointer_cast;
using std::make_shared;
using std::shared_ptr;
using test::io::SectionPairDocumentProvider;
using testing::Test;

namespace
{
  class SectionPairDocumentTest : public Test
  {
    public:

      SectionPairDocumentTest() = default;
      ~SectionPairDocumentTest() override = default;
  };

  TEST_F(SectionPairDocumentTest, add)
  {
    shared_ptr<SectionPairDocument> document = make_shared<SectionPairDocument>();

    ASSERT_TRUE(document->getSectionList().empty());
    document->add(make_shared<SectionPairSection>("general"));
    ASSERT_EQ(1, document->getAmountOfSections());
  }

  TEST_F(SectionPairDocumentTest, add_section_id_already_exists)
  {
    shared_ptr<SectionPairDocument> document = make_shared<SectionPairDocument>();
    document->add(make_shared<SectionPairSection>("general"));

    EXPECT_THROW(
        {
          try
          {
            document->add(make_shared<SectionPairSection>("general"));
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(SectionPairDocumentTest, clear)
  {
    shared_ptr<SectionPairDocument> document = make_shared<SectionPairDocument>();
    document->add(make_shared<SectionPairSection>("general"));

    ASSERT_EQ(1, document->getAmountOfSections());
    document->clear();
    ASSERT_TRUE(document->getSectionList().empty());
  }

  TEST_F(SectionPairDocumentTest, get_by_index)
  {
    shared_ptr<SectionPairDocument> document = make_shared<SectionPairDocument>();
    document->add(make_shared<SectionPairSection>("general"));

    ASSERT_TRUE(document->get(0) != nullptr);
  }

  TEST_F(SectionPairDocumentTest, get_by_section_id)
  {
    shared_ptr<SectionPairDocument> document = make_shared<SectionPairDocument>();
    document->add(make_shared<SectionPairSection>("general"));

    ASSERT_TRUE(document->get("general") != nullptr);
  }

  TEST_F(SectionPairDocumentTest, get_by_section_id_not_found)
  {
    shared_ptr<SectionPairDocument> document = make_shared<SectionPairDocument>();
    document->add(make_shared<SectionPairSection>("general"));

    ASSERT_TRUE(document->get("about") == nullptr);
  }

  TEST_F(SectionPairDocumentTest, get_by_index_out_of_bounds)
  {
    shared_ptr<SectionPairDocument> document = make_shared<SectionPairDocument>();

    EXPECT_THROW(
        {
          try
          {
            shared_ptr<SectionPairSection> section = document->get(0);
          }
          catch (const IndexOutOfBoundsException &_exception)
          {
            throw;
          }
        },
        IndexOutOfBoundsException);
  }

  TEST_F(SectionPairDocumentTest, getAmountOfSections)
  {
    shared_ptr<SectionPairDocument> document = make_shared<SectionPairDocument>();
    document->add(make_shared<SectionPairSection>("general"));

    ASSERT_EQ(1, document->getAmountOfSections());
  }

  TEST_F(SectionPairDocumentTest, getClassName)
  {
    shared_ptr<SectionPairDocument> document = make_shared<SectionPairDocument>();
    ASSERT_STREQ("SectionPairDocument", document->getClassName().c_str());
  }

  TEST_F(SectionPairDocumentTest, getHeader)
  {
    shared_ptr<SectionPairDocument> document = make_shared<SectionPairDocument>();
    ASSERT_STREQ("# section-pair document", document->getHeader().c_str());
  }

  TEST_F(SectionPairDocumentTest, getSectionList)
  {
    shared_ptr<SectionPairDocument> document = make_shared<SectionPairDocument>();
    ASSERT_TRUE(document->getSectionList().empty());
  }

  TEST_F(SectionPairDocumentTest, hasSection)
  {
    shared_ptr<SectionPairDocument> document = make_shared<SectionPairDocument>();
    document->add(make_shared<SectionPairSection>("general"));

    ASSERT_TRUE(document->hasSection("general"));
  }

  TEST_F(SectionPairDocumentTest, hasSection_not_found)
  {
    shared_ptr<SectionPairDocument> document = make_shared<SectionPairDocument>();
    document->add(make_shared<SectionPairSection>("general"));

    ASSERT_FALSE(document->hasSection("about"));
  }

  TEST_F(SectionPairDocumentTest, marshal)
  {
    shared_ptr<SectionPairDocument> document = SectionPairDocumentProvider::createDocument();
    byte_field expected = SectionPairDocumentProvider::createSerializedDocument(NewLine::get());

    ASSERT_STREQ(expected.c_str(), document->marshal().c_str());
  }

  TEST_F(SectionPairDocumentTest, unmarshal)
  {
    shared_ptr<SectionPairDocument> document = make_shared<SectionPairDocument>();
    document->unmarshal(SectionPairDocumentProvider::createSerializedDocument(NewLine::get()));

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
}
