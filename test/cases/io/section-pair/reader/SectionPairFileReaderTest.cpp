/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-21
* Changed:         2023-02-21
*
* */

#include <gtest/gtest.h>
#include <ls-std-io-test.hpp>
#include <ls-std/ls-std-core.hpp>
#include <ls-std/ls-std-io.hpp>
#include <memory>

using namespace ls::std::core;
using namespace ls::std::io;
using namespace ::std;
using namespace test::io;
using namespace ::testing;

namespace
{
  class SectionPairFileReaderTest : public ::testing::Test
  {
    protected:

      SectionPairFileReaderTest() = default;
      ~SectionPairFileReaderTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}

      static SectionPairFileReaderParameter createMockParameter(bool _fileExists)
      {
        SectionPairFileReaderParameter parameter{};
        parameter.setFileExistenceEvaluator(make_shared<MockFileExistenceEvaluator>(_fileExists));
        parameter.setReader(make_shared<MockFileReader>());

        return parameter;
      }

      static string getMockSectionPairFileContent()
      {
        return "# section-pair document\n"
               "\n"
               "[general]\n"
               "\n"
               "ports:\n"
               "  9090\n"
               "  8001\n"
               "  1989\n"
               "host=localhost\n";
      }
  };

  TEST_F(SectionPairFileReaderTest, constructor_file_does_not_exist)
  {
    EXPECT_THROW(
        {
          try
          {
            SectionPairFileReader reader{SectionPairFileReaderTest::createMockParameter(false)};
          }
          catch (const FileNotFoundException &_exception)
          {
            throw;
          }
        },
        FileNotFoundException);
  }

  TEST_F(SectionPairFileReaderTest, getClassName)
  {
    ASSERT_STREQ("SectionPairFileReader", SectionPairFileReader{SectionPairFileReaderTest::createMockParameter(true)}.getClassName().c_str());
  }

  TEST_F(SectionPairFileReaderTest, getDocument)
  {
    SectionPairFileReader reader{SectionPairFileReaderTest::createMockParameter(true)};
    ASSERT_FALSE(reader.getDocument() == nullptr);
  }

  TEST_F(SectionPairFileReaderTest, read)
  {
    SectionPairFileReaderParameter parameter = SectionPairFileReaderTest::createMockParameter(true);
    SectionPairFileReader reader{parameter};
    shared_ptr<MockFileReader> mockFileReader = dynamic_pointer_cast<MockFileReader>(parameter.getReader());

    EXPECT_CALL(*mockFileReader, read()).Times(AtLeast(1));
    ON_CALL(*mockFileReader, read()).WillByDefault(Return(SectionPairFileReaderTest::getMockSectionPairFileContent()));

    reader.read();

    ASSERT_TRUE(!reader.getDocument()->getSectionList().empty());
    ASSERT_STREQ("general", reader.getDocument()->get(0)->getSectionId().c_str());
    ASSERT_EQ(2, reader.getDocument()->get(0)->getRowAmount());
  }
}
