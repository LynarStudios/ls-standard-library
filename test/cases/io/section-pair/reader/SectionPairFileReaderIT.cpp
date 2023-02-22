/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-21
* Changed:         2023-02-22
*
* */

#include <classes/TestHelper.hpp>
#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>
#include <ls-std/ls-std-io.hpp>
#include <string>

using namespace ls::std::core;
using namespace ls::std::io;
using namespace ::std;
using namespace ls::std::test;
using namespace ::testing;

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
