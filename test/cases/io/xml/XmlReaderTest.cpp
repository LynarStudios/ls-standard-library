/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-10-10
 * Changed:         2023-02-22
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
using namespace ::testing;

namespace
{
  class XmlReaderTest : public Test
  {
    protected:

      XmlReaderTest() = default;
      ~XmlReaderTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(XmlReaderTest, read)
  {
    string xmlPath = TestHelper::getResourcesFolderLocation() + "state-machine-test.xml";
    XmlReader xmlReader{make_shared<XmlDocument>(), xmlPath};

    ASSERT_TRUE(!xmlReader.read().empty());
  }

  TEST_F(XmlReaderTest, getDocument)
  {
    string xmlPath = TestHelper::getResourcesFolderLocation() + "state-machine-test.xml";
    XmlReader xmlReader{make_shared<XmlDocument>(), xmlPath};

    ASSERT_TRUE(xmlReader.getDocument() != nullptr);
  }

  TEST_F(XmlReaderTest, setDocument)
  {
    string xmlPath = TestHelper::getResourcesFolderLocation() + "state-machine-test.xml";
    shared_ptr<XmlDocument> document = make_shared<XmlDocument>();
    XmlReader xmlReader{document, xmlPath};
    ASSERT_TRUE(xmlReader.getDocument() == document);

    document = make_shared<XmlDocument>();
    xmlReader.setDocument(document);
    ASSERT_TRUE(xmlReader.getDocument() == document);
  }

  TEST_F(XmlReaderTest, setDocument_no_reference)
  {
    string xmlPath = TestHelper::getResourcesFolderLocation() + "state-machine-test.xml";
    shared_ptr<XmlDocument> document = make_shared<XmlDocument>();
    XmlReader xmlReader{document, xmlPath};

    EXPECT_THROW(
        {
          try
          {
            xmlReader.setDocument(nullptr);
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(XmlReaderTest, setFile)
  {
    string xmlPath = TestHelper::getResourcesFolderLocation() + "state-machine-test.xml";
    XmlReader xmlReader{make_shared<XmlDocument>(), xmlPath};
    File xmlFile{xmlPath};
    xmlReader.setFile(xmlFile);

    ASSERT_TRUE(true);
  }

  TEST_F(XmlReaderTest, setFile_does_not_exist)
  {
    string xmlPath = TestHelper::getResourcesFolderLocation() + "state-machine-test.xml";
    XmlReader xmlReader{make_shared<XmlDocument>(), xmlPath};
    File xmlFile{xmlPath};

    EXPECT_THROW(
        {
          try
          {
            xmlReader.setFile(File{""});
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }
}
