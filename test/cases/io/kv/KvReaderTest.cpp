/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-25
 * Changed:         2021-05-02
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>
#include <TestHelper.hpp>

namespace
{
  class KvReaderTest : public ::testing::Test
  {
    protected:

      KvReaderTest() = default;
      ~KvReaderTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(KvReaderTest, getDocument)
  {
    std::string kvPath = TestHelper::getResourcesFolderLocation() + "server_settings.kv";
    ls_std::KvReader reader{std::make_shared<ls_std::KvDocument>(), kvPath};

    ASSERT_TRUE(reader.getDocument() != nullptr);
  }

  TEST_F(KvReaderTest, read)
  {
    std::string kvPath = TestHelper::getResourcesFolderLocation() + "server_settings.kv";
    std::shared_ptr<ls_std::KvDocument> document = std::make_shared<ls_std::KvDocument>();
    ls_std::KvReader reader{document, kvPath};

    reader.read();
    ASSERT_EQ(3, document->getPairs().size());
    ASSERT_TRUE(document->hasPair("port"));
    ASSERT_TRUE(document->hasPair("host"));
    ASSERT_TRUE(document->hasPair("service-name"));

    ASSERT_STREQ("8080", document->getPairs().at("port").getValue().c_str());
    ASSERT_STREQ("localhost", document->getPairs().at("host").getValue().c_str());
    ASSERT_STREQ("deamon", document->getPairs().at("service-name").getValue().c_str());
  }

  TEST_F(KvReaderTest, setDocument)
  {
    std::string kvPath = TestHelper::getResourcesFolderLocation() + "server_settings.kv";
    std::shared_ptr<ls_std::KvDocument> document1 = std::make_shared<ls_std::KvDocument>();
    std::shared_ptr<ls_std::KvDocument> document2 = std::make_shared<ls_std::KvDocument>();

    ls_std::KvReader reader{document1, kvPath};
    ASSERT_TRUE(reader.getDocument() == document1);

    reader.setDocument(document2);
    ASSERT_TRUE(reader.getDocument() == document2);
  }
}
