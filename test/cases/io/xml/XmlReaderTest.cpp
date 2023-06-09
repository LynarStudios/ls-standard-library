/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-10-10
 * Changed:         2023-03-25
 *
 * */

#include <classes/TestHelper.hpp>
#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>
#include <ls-std/ls-std-io.hpp>

using ls::std::core::IllegalArgumentException;
using ls::std::io::File;
using ls::std::io::XmlDocument;
using ls::std::io::XmlReader;
using ls::std::test::TestHelper;
using std::make_shared;
using std::shared_ptr;
using std::string;
using testing::Test;

namespace
{
  class XmlReaderTest : public Test
  {
    public:

      XmlReaderTest() = default;
      ~XmlReaderTest() override = default;
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
