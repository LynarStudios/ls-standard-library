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

      static std::shared_ptr<ls_std::KvFileReader> createTestKVFileReader()
      {
        std::string kvPath = TestHelper::getResourcesFolderLocation() + "server_settings.kv";
        std::shared_ptr<ls_std::KvDocument> document = std::make_shared<ls_std::KvDocument>();

        return std::make_shared<ls_std::KvFileReader>(document, kvPath);
      }
  };

  TEST_F(KvFileReaderTest, constructor_no_document_reference)
  {
    EXPECT_THROW({
                   try
                   {
                     std::string kvPath = TestHelper::getResourcesFolderLocation() + "server_settings.kv";
                     ls_std::KvFileReader reader = ls_std::KvFileReader(nullptr, kvPath);
                   }
                   catch (const ls_std::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls_std::IllegalArgumentException);
  }

  TEST_F(KvFileReaderTest, constructor_invalid_file_path)
  {
    EXPECT_THROW({
                   try
                   {
                     ls_std::KvFileReader reader = ls_std::KvFileReader(std::make_shared<ls_std::KvDocument>(), "invalid_path");
                   }
                   catch (const ls_std::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls_std::IllegalArgumentException);
  }

  TEST_F(KvFileReaderTest, getDocument)
  {
    const std::shared_ptr<ls_std::KvFileReader> &reader = createTestKVFileReader();
    ASSERT_TRUE(reader->getDocument() != nullptr);
  }

  TEST_F(KvFileReaderTest, read)
  {
    // preparation

    const std::shared_ptr<ls_std::KvFileReader> &reader = createTestKVFileReader();

    // read file and check

    reader->read();
    const std::shared_ptr<ls_std::KvDocument> &document = reader->getDocument();

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
    const std::shared_ptr<ls_std::KvFileReader> &reader = createTestKVFileReader();

    EXPECT_THROW({
                   try
                   {
                     reader->setFile(ls_std::File{"invalid_path"});
                   }
                   catch (const ls_std::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls_std::IllegalArgumentException);
  }

  TEST_F(KvFileReaderTest, setDocument)
  {
    // preparation

    const std::shared_ptr<ls_std::KvFileReader> &reader = createTestKVFileReader();

    // set new document and check

    std::shared_ptr<ls_std::KvDocument> newDocument = std::make_shared<ls_std::KvDocument>();
    reader->setDocument(newDocument);
    ASSERT_TRUE(reader->getDocument() == newDocument);
  }

  TEST_F(KvFileReaderTest, setDocument_no_reference)
  {
    const std::shared_ptr<ls_std::KvFileReader> &reader = createTestKVFileReader();

    EXPECT_THROW({
                   try
                   {
                     reader->setDocument(nullptr);
                   }
                   catch (const ls_std::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls_std::IllegalArgumentException);
  }
}
