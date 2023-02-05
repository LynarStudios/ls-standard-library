/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-25
 * Changed:         2023-02-05
 *
 * */

#include <classes/TestHelper.hpp>
#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>
#include <ls-std/ls-std-io.hpp>

using namespace ls::std::core;
using namespace ls::std::io;
using namespace ::std;
using namespace ls::std::test;

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

      static shared_ptr<KvFileReader> createTestKVFileReader()
      {
        string kvPath = TestHelper::getResourcesFolderLocation() + "server-settings.kv";
        shared_ptr<KvDocument> document = make_shared<KvDocument>();

        return make_shared<KvFileReader>(document, kvPath);
      }
  };

  TEST_F(KvFileReaderTest, constructor_no_document_reference)
  {
    EXPECT_THROW(
        {
          try
          {
            string kvPath = TestHelper::getResourcesFolderLocation() + "server-settings.kv";
            KvFileReader reader = KvFileReader(nullptr, kvPath);
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(KvFileReaderTest, constructor_invalid_file_path)
  {
    EXPECT_THROW(
        {
          try
          {
            KvFileReader reader = KvFileReader(make_shared<KvDocument>(), "invalid_path");
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(KvFileReaderTest, getDocument)
  {
    const shared_ptr<KvFileReader> &reader = createTestKVFileReader();
    ASSERT_TRUE(reader->getDocument() != nullptr);
  }

  TEST_F(KvFileReaderTest, read)
  {
    // preparation

    const shared_ptr<KvFileReader> &reader = createTestKVFileReader();

    // read file and check

    reader->read();
    const shared_ptr<KvDocument> &document = reader->getDocument();

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
    const shared_ptr<KvFileReader> &reader = createTestKVFileReader();

    EXPECT_THROW(
        {
          try
          {
            reader->setFile(File{"invalid_path"});
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(KvFileReaderTest, setDocument)
  {
    // preparation

    const shared_ptr<KvFileReader> &reader = createTestKVFileReader();

    // set new document and check

    shared_ptr<KvDocument> newDocument = make_shared<KvDocument>();
    reader->setDocument(newDocument);
    ASSERT_TRUE(reader->getDocument() == newDocument);
  }

  TEST_F(KvFileReaderTest, setDocument_no_reference)
  {
    const shared_ptr<KvFileReader> &reader = createTestKVFileReader();

    EXPECT_THROW(
        {
          try
          {
            reader->setDocument(nullptr);
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }
}
