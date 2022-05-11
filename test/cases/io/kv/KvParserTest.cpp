/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-25
 * Changed:         2022-05-11
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>

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
    EXPECT_THROW({
                   try
                   {
                     ls::std::io::KvParser parser{nullptr};
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }

  TEST_F(KvParserTest, getDocument)
  {
    ls::std::io::KvParser parser{std::make_shared<ls::std::io::KvDocument>()};
    ASSERT_TRUE(parser.getDocument() != nullptr);
  }

  TEST_F(KvParserTest, parse)
  {
    std::shared_ptr<ls::std::io::KvDocument> document = std::make_shared<ls::std::io::KvDocument>();
    ls::std::io::KvParser parser{document};
    ls::std::core::byte_field data = "# starting comment\n\nport=8080; # some comment\nhost=localhost;\nservice-name=deamon;";
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

    std::shared_ptr<ls::std::io::KvDocument> document = std::make_shared<ls::std::io::KvDocument>();
    ls::std::io::KvParser parser{document};

    // set and check

    std::shared_ptr<ls::std::io::KvDocument> newDocument = std::make_shared<ls::std::io::KvDocument>();
    parser.setDocument(newDocument);
    ASSERT_TRUE(parser.getDocument() == newDocument);
  }

  TEST_F(KvParserTest, setDocument_no_reference)
  {
    std::shared_ptr<ls::std::io::KvDocument> document = std::make_shared<ls::std::io::KvDocument>();
    ls::std::io::KvParser parser{document};

    EXPECT_THROW({
                   try
                   {
                     parser.setDocument(nullptr);
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }
}
