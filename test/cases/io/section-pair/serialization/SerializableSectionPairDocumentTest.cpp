/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-16
* Changed:         2023-02-16
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
  class SerializableSectionPairDocumentTest : public ::testing::Test
  {
    protected:

      SerializableSectionPairDocumentTest() = default;
      ~SerializableSectionPairDocumentTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(SerializableSectionPairDocumentTest, constructor_no_value)
  {
    EXPECT_THROW(
        {
          try
          {
            SerializableSectionPairDocument serializable = SerializableSectionPairDocument(nullptr);
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(SerializableSectionPairDocumentTest, getValue)
  {
    SerializableSectionPairDocument serializable(make_shared<SectionPairDocument>());
    ASSERT_TRUE(serializable.getValue() != nullptr);
  }

  TEST_F(SerializableSectionPairDocumentTest, marshal)
  {
    SerializableSectionPairDocument serializable(SectionPairDocumentProvider::createDocument());
    byte_field expected = SectionPairDocumentProvider::createSerializedDocument();

    ASSERT_STREQ(expected.c_str(), serializable.marshal().c_str());
  }

  TEST_F(SerializableSectionPairDocumentTest, unmarshal)
  {
    SerializableSectionPairDocument serializable(make_shared<SectionPairDocument>());
    serializable.unmarshal(SectionPairDocumentProvider::createSerializedDocument());

    shared_ptr<SectionPairDocument> expected = SectionPairDocumentProvider::createDocument();

    ASSERT_EQ(2, expected->getAmountOfSections());
  }
}
