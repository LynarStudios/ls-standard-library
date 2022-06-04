/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-25
 * Changed:         2022-05-20
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std_core.hpp>
#include <ls_std/ls_std_io.hpp>
#include "TestHelper.hpp"

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

      static std::shared_ptr<ls::std::io::KvFileReader> createTestKVFileReader()
      {
        ::std::string kvPath = ls_std_test::TestHelper::getResourcesFolderLocation() + "server_settings.kv";
        ::std::shared_ptr<ls::std::io::KvDocument> document = ::std::make_shared<ls::std::io::KvDocument>();

        return ::std::make_shared<ls::std::io::KvFileReader>(document, kvPath);
      }
  };

  TEST_F(KvFileReaderTest, constructor_no_document_reference)
  {
    EXPECT_THROW({
                   try
                   {
                     ::std::string kvPath = ls_std_test::TestHelper::getResourcesFolderLocation() + "server_settings.kv";
                     ls::std::io::KvFileReader reader = ls::std::io::KvFileReader(nullptr, kvPath);
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }

  TEST_F(KvFileReaderTest, constructor_invalid_file_path)
  {
    EXPECT_THROW({
                   try
                   {
                     ls::std::io::KvFileReader reader = ls::std::io::KvFileReader(::std::make_shared<ls::std::io::KvDocument>(), "invalid_path");
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }

  TEST_F(KvFileReaderTest, getDocument)
  {
    const ::std::shared_ptr<ls::std::io::KvFileReader> &reader = createTestKVFileReader();
    ASSERT_TRUE(reader->getDocument() != nullptr);
  }

  TEST_F(KvFileReaderTest, read)
  {
    // preparation

    const ::std::shared_ptr<ls::std::io::KvFileReader> &reader = createTestKVFileReader();

    // read file and check

    reader->read();
    const ::std::shared_ptr<ls::std::io::KvDocument> &document = reader->getDocument();

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
    const ::std::shared_ptr<ls::std::io::KvFileReader> &reader = createTestKVFileReader();

    EXPECT_THROW({
                   try
                   {
                     reader->setFile(ls::std::io::File{"invalid_path"});
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }

  TEST_F(KvFileReaderTest, setDocument)
  {
    // preparation

    const ::std::shared_ptr<ls::std::io::KvFileReader> &reader = createTestKVFileReader();

    // set new document and check

    ::std::shared_ptr<ls::std::io::KvDocument> newDocument = ::std::make_shared<ls::std::io::KvDocument>();
    reader->setDocument(newDocument);
    ASSERT_TRUE(reader->getDocument() == newDocument);
  }

  TEST_F(KvFileReaderTest, setDocument_no_reference)
  {
    const ::std::shared_ptr<ls::std::io::KvFileReader> &reader = createTestKVFileReader();

    EXPECT_THROW({
                   try
                   {
                     reader->setDocument(nullptr);
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }
}
