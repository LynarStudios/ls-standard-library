/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-25
 * Changed:         2020-12-25
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>

namespace {
  class KVParserTest : public ::testing::Test {
    protected:

      KVParserTest() = default;
      ~KVParserTest() override = default;

      void SetUp() override {}
      void TearDown() override {}
  };

  TEST_F(KVParserTest, getDocument)
  {
    ls_std::KVParser parser {std::make_shared<ls_std::KVDocument>()};
    ASSERT_TRUE(parser.getDocument() != nullptr);
  }

  TEST_F(KVParserTest, parse)
  {
    std::shared_ptr<ls_std::KVDocument> document = std::make_shared<ls_std::KVDocument>();
    ls_std::KVParser parser {document};
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

  TEST_F(KVParserTest, setDocument)
  {
    std::shared_ptr<ls_std::KVDocument> document1 = std::make_shared<ls_std::KVDocument>();
    std::shared_ptr<ls_std::KVDocument> document2 = std::make_shared<ls_std::KVDocument>();

    ls_std::KVParser parser {document1};
    ASSERT_TRUE(parser.getDocument() == document1);

    parser.setDocument(document2);
    ASSERT_TRUE(parser.getDocument() == document2);
  }
}
