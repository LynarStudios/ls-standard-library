/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-21
* Changed:         2023-02-21
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

namespace
{
  class SectionPairFileReaderIT : public ::testing::Test
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

  TEST_F(SectionPairFileReaderIT, constructor_file_does_not_exist)
  {
    EXPECT_THROW(
        {
          try
          {
            SectionPairFileReader reader{SectionPairFileReaderParameter{}};
          }
          catch (const FileNotFoundException &_exception)
          {
            throw;
          }
        },
        FileNotFoundException);
  }

  TEST_F(SectionPairFileReaderIT, getClassName)
  {
    SectionPairFileReaderParameter parameter{};
    parameter.setFilePath(SectionPairFileReaderIT::getSectionPairFileLocation());

    ASSERT_STREQ("SectionPairFileReader", SectionPairFileReader{parameter}.getClassName().c_str());
  }

  TEST_F(SectionPairFileReaderIT, getDocument)
  {
    SectionPairFileReaderParameter parameter{};
    parameter.setFilePath(SectionPairFileReaderIT::getSectionPairFileLocation());
    SectionPairFileReader reader{parameter};

    ASSERT_FALSE(reader.getDocument() == nullptr);
  }

  TEST_F(SectionPairFileReaderIT, read)
  {
    SectionPairFileReaderParameter parameter{};
    parameter.setFilePath(SectionPairFileReaderIT::getSectionPairFileLocation());
    SectionPairFileReader reader{parameter};
    reader.read();

    ASSERT_TRUE(!reader.getDocument()->getSectionList().empty());
    ASSERT_STREQ("general", reader.getDocument()->get(0)->getSectionId().c_str());
    ASSERT_EQ(2, reader.getDocument()->get(0)->getRowAmount());
  }
}
