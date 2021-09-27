/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-25
 * Changed:         2021-07-15
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
                     ls_std::KvParser parser{nullptr};
                   }
                   catch (const ls_std::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls_std::IllegalArgumentException);
  }

  TEST_F(KvParserTest, getDocument)
  {
    ls_std::KvParser parser{std::make_shared<ls_std::KvDocument>()};
    ASSERT_TRUE(parser.getDocument() != nullptr);
  }

  TEST_F(KvParserTest, parse)
  {
    std::shared_ptr<ls_std::KvDocument> document = std::make_shared<ls_std::KvDocument>();
    ls_std::KvParser parser{document};
    ls_std::byte_field data = "# starting comment\n\nport=8080; # some comment\nhost=localhost;\nservice-name=deamon;";
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

    std::shared_ptr<ls_std::KvDocument> document = std::make_shared<ls_std::KvDocument>();
    ls_std::KvParser parser{document};

    // set and check

    std::shared_ptr<ls_std::KvDocument> newDocument = std::make_shared<ls_std::KvDocument>();
    parser.setDocument(newDocument);
    ASSERT_TRUE(parser.getDocument() == newDocument);
  }

  TEST_F(KvParserTest, setDocument_no_reference)
  {
    std::shared_ptr<ls_std::KvDocument> document = std::make_shared<ls_std::KvDocument>();
    ls_std::KvParser parser{document};

    EXPECT_THROW({
                   try
                   {
                     parser.setDocument(nullptr);
                   }
                   catch (const ls_std::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls_std::IllegalArgumentException);
  }
}
