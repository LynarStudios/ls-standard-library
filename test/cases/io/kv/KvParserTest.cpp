/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-25
 * Changed:         2023-02-04
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
  class KvParserTest : public ::testing::Test
  {
    protected:

      KvParserTest() = default;
      ~KvParserTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(KvParserTest, constructor_no_document_reference)
  {
    EXPECT_THROW(
        {
          try
          {
            KvParser parser{nullptr};
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(KvParserTest, getDocument)
  {
    KvParser parser{make_shared<KvDocument>()};
    ASSERT_TRUE(parser.getDocument() != nullptr);
  }

  TEST_F(KvParserTest, parse)
  {
    shared_ptr<KvDocument> document = make_shared<KvDocument>();
    KvParser parser{document};
    byte_field data = "# starting comment\n\nport=8080; # some comment\nhost=localhost;\nservice-name=deamon;";
    parser.parse(data);

    ASSERT_EQ(3, document->getPairs().size());
    ASSERT_TRUE(document->hasPair("port"));
    ASSERT_TRUE(document->hasPair("host"));
    ASSERT_TRUE(document->hasPair("service-name"));

    ASSERT_STREQ("8080", document->getPairs().at("port").getValue().c_str());
    ASSERT_STREQ("localhost", document->getPairs().at("host").getValue().c_str());
    ASSERT_STREQ("deamon", document->getPairs().at("service-name").getValue().c_str());
  }

  TEST_F(KvParserTest, setDocument)
  {
    // preparation

    shared_ptr<KvDocument> document = make_shared<KvDocument>();
    KvParser parser{document};

    // set and check

    shared_ptr<KvDocument> newDocument = make_shared<KvDocument>();
    parser.setDocument(newDocument);
    ASSERT_TRUE(parser.getDocument() == newDocument);
  }

  TEST_F(KvParserTest, setDocument_no_reference)
  {
    shared_ptr<KvDocument> document = make_shared<KvDocument>();
    KvParser parser{document};

    EXPECT_THROW(
        {
          try
          {
            parser.setDocument(nullptr);
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }
}
