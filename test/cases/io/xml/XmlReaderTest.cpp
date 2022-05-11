/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-10-10
 * Changed:         2022-05-11
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>
#include <TestHelper.hpp>

namespace
{
  class XmlReaderTest : public ::testing::Test
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
    std::string xmlPath = TestHelper::getResourcesFolderLocation() + "state_machine_test.xml";
    ls::std::io::XmlReader xmlReader{std::make_shared<ls::std::io::XmlDocument>(), xmlPath};

    ASSERT_TRUE(!xmlReader.read().empty());
  }

  TEST_F(XmlReaderTest, getDocument)
  {
    std::string xmlPath = TestHelper::getResourcesFolderLocation() + "state_machine_test.xml";
    ls::std::io::XmlReader xmlReader{std::make_shared<ls::std::io::XmlDocument>(), xmlPath};

    ASSERT_TRUE(xmlReader.getDocument() != nullptr);
  }

  TEST_F(XmlReaderTest, setDocument)
  {
    std::string xmlPath = TestHelper::getResourcesFolderLocation() + "state_machine_test.xml";
    std::shared_ptr<ls::std::io::XmlDocument> document = std::make_shared<ls::std::io::XmlDocument>();
    ls::std::io::XmlReader xmlReader{document, xmlPath};
    ASSERT_TRUE(xmlReader.getDocument() == document);

    document = std::make_shared<ls::std::io::XmlDocument>();
    xmlReader.setDocument(document);
    ASSERT_TRUE(xmlReader.getDocument() == document);
  }

  TEST_F(XmlReaderTest, setDocument_no_reference)
  {
    std::string xmlPath = TestHelper::getResourcesFolderLocation() + "state_machine_test.xml";
    std::shared_ptr<ls::std::io::XmlDocument> document = std::make_shared<ls::std::io::XmlDocument>();
    ls::std::io::XmlReader xmlReader{document, xmlPath};

    EXPECT_THROW({
                   try
                   {
                     xmlReader.setDocument(nullptr);
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }

  TEST_F(XmlReaderTest, setFile)
  {
    std::string xmlPath = TestHelper::getResourcesFolderLocation() + "state_machine_test.xml";
    ls::std::io::XmlReader xmlReader{std::make_shared<ls::std::io::XmlDocument>(), xmlPath};
    ls::std::io::File xmlFile{xmlPath};
    xmlReader.setFile(xmlFile);

    ASSERT_TRUE(true);
  }

  TEST_F(XmlReaderTest, setFile_does_not_exist)
  {
    std::string xmlPath = TestHelper::getResourcesFolderLocation() + "state_machine_test.xml";
    ls::std::io::XmlReader xmlReader{std::make_shared<ls::std::io::XmlDocument>(), xmlPath};
    ls::std::io::File xmlFile{xmlPath};

    EXPECT_THROW({
                   try
                   {
                     xmlReader.setFile(ls::std::io::File{""});
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }
}
