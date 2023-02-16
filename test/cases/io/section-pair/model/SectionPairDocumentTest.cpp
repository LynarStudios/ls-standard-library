/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-15
* Changed:         2023-02-16
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
  class SectionPairDocumentTest : public ::testing::Test
  {
    protected:

      SectionPairDocumentTest() = default;
      ~SectionPairDocumentTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
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

  TEST_F(SectionPairDocumentTest, get)
  {
    shared_ptr<SectionPairDocument> document = make_shared<SectionPairDocument>();
    document->add(make_shared<SectionPairSection>("general"));

    ASSERT_TRUE(document->get(0) != nullptr);
  }

  TEST_F(SectionPairDocumentTest, get_out_of_bounds)
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
}
