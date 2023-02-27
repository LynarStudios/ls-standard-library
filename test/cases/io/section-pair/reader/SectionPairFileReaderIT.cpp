/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-21
* Changed:         2023-02-23
*
* */

#include <classes/TestHelper.hpp>
#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>
#include <ls-std/ls-std-io.hpp>
#include <string>

using ls::std::io::SectionPairDocument;
using ls::std::io::SectionPairFileReader;
using ls::std::io::SectionPairFileReaderParameter;
using ls::std::test::TestHelper;
using std::make_shared;
using std::shared_ptr;
using std::string;
using testing::Test;

namespace
{
  class SectionPairFileReaderIT : public Test
  {
    protected:

      SectionPairFileReaderIT() = default;
      ~SectionPairFileReaderIT() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}

      static string getSectionPairFileLocation()
      {
        return TestHelper::getResourcesFolderLocation() + "server-settings-unix.txt";
      }
  };

  TEST_F(SectionPairFileReaderIT, read)
  {
    SectionPairFileReaderParameter parameter{};
    shared_ptr<SectionPairDocument> document = make_shared<SectionPairDocument>();
    parameter.setDocument(document);
    parameter.setFilePath(SectionPairFileReaderIT::getSectionPairFileLocation());
    SectionPairFileReader reader{parameter};
    reader.read();

    ASSERT_TRUE(!reader.getDocument()->getSectionList().empty());
    ASSERT_STREQ("general", reader.getDocument()->get(0)->getSectionId().c_str());
    ASSERT_EQ(2, reader.getDocument()->get(0)->getRowAmount());
  }
}
