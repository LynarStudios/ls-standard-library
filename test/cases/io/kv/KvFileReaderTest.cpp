/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-25
 * Changed:         2022-05-05
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>
#include <TestHelper.hpp>

namespace
{
  class KvFileReaderTest : public ::testing::Test
  {
    protected:

      KvFileReaderTest() = default;
      ~KvFileReaderTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}

      static std::shared_ptr<ls::KvFileReader> createTestKVFileReader()
      {
        std::string kvPath = TestHelper::getResourcesFolderLocation() + "server_settings.kv";
        std::shared_ptr<ls::KvDocument> document = std::make_shared<ls::KvDocument>();

        return std::make_shared<ls::KvFileReader>(document, kvPath);
      }
  };

  TEST_F(KvFileReaderTest, constructor_no_document_reference)
  {
    EXPECT_THROW({
                   try
                   {
                     std::string kvPath = TestHelper::getResourcesFolderLocation() + "server_settings.kv";
                     ls::KvFileReader reader = ls::KvFileReader(nullptr, kvPath);
                   }
                   catch (const ls::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::IllegalArgumentException);
  }

  TEST_F(KvFileReaderTest, constructor_invalid_file_path)
  {
    EXPECT_THROW({
                   try
                   {
                     ls::KvFileReader reader = ls::KvFileReader(std::make_shared<ls::KvDocument>(), "invalid_path");
                   }
                   catch (const ls::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::IllegalArgumentException);
  }

  TEST_F(KvFileReaderTest, getDocument)
  {
    const std::shared_ptr<ls::KvFileReader> &reader = createTestKVFileReader();
    ASSERT_TRUE(reader->getDocument() != nullptr);
  }

  TEST_F(KvFileReaderTest, read)
  {
    // preparation

    const std::shared_ptr<ls::KvFileReader> &reader = createTestKVFileReader();

    // read file and check

    reader->read();
    const std::shared_ptr<ls::KvDocument> &document = reader->getDocument();

    ASSERT_EQ(3, document->getPairs().size());
    ASSERT_TRUE(document->hasPair("port"));
    ASSERT_TRUE(document->hasPair("host"));
    ASSERT_TRUE(document->hasPair("service-name"));

    ASSERT_STREQ("8080", document->getPairs().at("port").getValue().c_str());
    ASSERT_STREQ("localhost", document->getPairs().at("host").getValue().c_str());
    ASSERT_STREQ("deamon", document->getPairs().at("service-name").getValue().c_str());
  }

  TEST_F(KvFileReaderTest, setFile_no_existing_file)
  {
    const std::shared_ptr<ls::KvFileReader> &reader = createTestKVFileReader();

    EXPECT_THROW({
                   try
                   {
                     reader->setFile(ls::File{"invalid_path"});
                   }
                   catch (const ls::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::IllegalArgumentException);
  }

  TEST_F(KvFileReaderTest, setDocument)
  {
    // preparation

    const std::shared_ptr<ls::KvFileReader> &reader = createTestKVFileReader();

    // set new document and check

    std::shared_ptr<ls::KvDocument> newDocument = std::make_shared<ls::KvDocument>();
    reader->setDocument(newDocument);
    ASSERT_TRUE(reader->getDocument() == newDocument);
  }

  TEST_F(KvFileReaderTest, setDocument_no_reference)
  {
    const std::shared_ptr<ls::KvFileReader> &reader = createTestKVFileReader();

    EXPECT_THROW({
                   try
                   {
                     reader->setDocument(nullptr);
                   }
                   catch (const ls::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::IllegalArgumentException);
  }
}
