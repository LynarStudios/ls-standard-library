/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-10-10
 * Changed:         2020-10-10
 *
 * */

#include <gtest/gtest.h>
#include "../../../../source/io/xml/XMLReader.hpp"
#include "../../../TestHelper.hpp"

namespace {
  class XMLReaderTest : public ::testing::Test {
    protected:

      XMLReaderTest() = default;
      ~XMLReaderTest() override = default;

      void SetUp() override {}
      void TearDown() override {}
  };

  TEST_F(XMLReaderTest, read)
  {
    std::string xmlPath = TestHelper::getResourcesFolderLocation() + "state_machine_test.xml";
    ls_std::XMLReader xmlReader {std::make_shared<ls_std::XMLDocument>(), xmlPath};

    ASSERT_TRUE(!xmlReader.read().empty());
  }

  TEST_F(XMLReaderTest, getDocument)
  {
    std::string xmlPath = TestHelper::getResourcesFolderLocation() + "state_machine_test.xml";
    ls_std::XMLReader xmlReader {std::make_shared<ls_std::XMLDocument>(), xmlPath};

    ASSERT_TRUE(xmlReader.getDocument() != nullptr);
  }

  TEST_F(XMLReaderTest, setFile)
  {
    std::string xmlPath = TestHelper::getResourcesFolderLocation() + "state_machine_test.xml";
    ls_std::XMLReader xmlReader {std::make_shared<ls_std::XMLDocument>(), xmlPath};
    ls_std::File xmlFile {xmlPath};
    xmlReader.setFile(xmlFile);

    ASSERT_TRUE(true);
  }
}
