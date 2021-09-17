/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-10-10
 * Changed:         2021-09-17
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
    ls_std::XmlReader xmlReader{std::make_shared<ls_std::XmlDocument>(), xmlPath};

    ASSERT_TRUE(!xmlReader.read().empty());
  }

  TEST_F(XmlReaderTest, getDocument)
  {
    std::string xmlPath = TestHelper::getResourcesFolderLocation() + "state_machine_test.xml";
    ls_std::XmlReader xmlReader{std::make_shared<ls_std::XmlDocument>(), xmlPath};

    ASSERT_TRUE(xmlReader.getDocument() != nullptr);
  }

  TEST_F(XmlReaderTest, setDocument)
  {
    std::string xmlPath = TestHelper::getResourcesFolderLocation() + "state_machine_test.xml";
    std::shared_ptr<ls_std::XmlDocument> document = std::make_shared<ls_std::XmlDocument>();
    ls_std::XmlReader xmlReader{document, xmlPath};
    ASSERT_TRUE(xmlReader.getDocument() == document);

    document = std::make_shared<ls_std::XmlDocument>();
    xmlReader.setDocument(document);
    ASSERT_TRUE(xmlReader.getDocument() == document);
  }

  TEST_F(XmlReaderTest, setDocument_no_reference)
  {
    std::string xmlPath = TestHelper::getResourcesFolderLocation() + "state_machine_test.xml";
    std::shared_ptr<ls_std::XmlDocument> document = std::make_shared<ls_std::XmlDocument>();
    ls_std::XmlReader xmlReader{document, xmlPath};

    EXPECT_THROW({
                   try
                   {
                     xmlReader.setDocument(nullptr);
                   }
                   catch (const ls_std::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls_std::IllegalArgumentException);
  }

  TEST_F(XmlReaderTest, setFile)
  {
    std::string xmlPath = TestHelper::getResourcesFolderLocation() + "state_machine_test.xml";
    ls_std::XmlReader xmlReader{std::make_shared<ls_std::XmlDocument>(), xmlPath};
    ls_std::File xmlFile{xmlPath};
    xmlReader.setFile(xmlFile);

    ASSERT_TRUE(true);
  }

  TEST_F(XmlReaderTest, setFile_does_not_exist)
  {
    std::string xmlPath = TestHelper::getResourcesFolderLocation() + "state_machine_test.xml";
    ls_std::XmlReader xmlReader{std::make_shared<ls_std::XmlDocument>(), xmlPath};
    ls_std::File xmlFile{xmlPath};

    EXPECT_THROW({
                   try
                   {
                     xmlReader.setFile(ls_std::File{""});
                   }
                   catch (const ls_std::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls_std::IllegalArgumentException);
  }
}
