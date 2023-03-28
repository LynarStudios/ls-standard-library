/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-21
* Changed:         2023-03-25
*
* */

#include <gtest/gtest.h>
#include <ls-std-io-test.hpp>
#include <ls-std/ls-std-core.hpp>
#include <ls-std/ls-std-io.hpp>
#include <memory>

using ls::std::core::FileNotFoundException;
using ls::std::core::IllegalArgumentException;
using ls::std::io::NewLine;
using ls::std::io::SectionPairDocument;
using ls::std::io::SectionPairFileReader;
using ls::std::io::SectionPairFileReaderParameter;
using std::dynamic_pointer_cast;
using std::make_shared;
using std::shared_ptr;
using std::string;
using test::io::MockFileExistenceEvaluator;
using test::io::MockFileReader;
using testing::AtLeast;
using testing::Return;
using testing::Test;
using testing::TestWithParam;
using testing::Values;

namespace
{
  class SectionPairFileReaderTest : public Test
  {
    public:

      SectionPairFileReaderTest() = default;
      ~SectionPairFileReaderTest() override = default;

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

      static SectionPairFileReaderParameter createMockParameter(bool _fileExists)
      {
        SectionPairFileReaderParameter parameter{};
        parameter.setFileExistenceEvaluator(make_shared<MockFileExistenceEvaluator>(_fileExists));
        parameter.setReader(make_shared<MockFileReader>());
        parameter.setDocument(make_shared<SectionPairDocument>());
        parameter.setFilePath("settings.txt");

        return parameter;
      }
  };

  class SectionPairFileReaderTest_NotValidFileExtension : public TestWithParam<string>
  {
    public:

      SectionPairFileReaderTest_NotValidFileExtension() = default;
      ~SectionPairFileReaderTest_NotValidFileExtension() override = default;
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

  TEST_P(SectionPairFileReaderTest_NotValidFileExtension, constructor_no_valid_file_extension)
  {
    SectionPairFileReaderParameter parameter = SectionPairFileReaderTest::createMockParameter(true);
    parameter.setFilePath(GetParam());

    EXPECT_THROW(
        {
          try
          {
            SectionPairFileReader reader{parameter};
          }
          catch (const IllegalArgumentException &_exception)
          {
            string message = _exception.what();
            string expected = _exception.getName() + " thrown - \"" + GetParam() + "\" does not have a valid section pair file extension (.txt or .sp)!";

            ASSERT_STREQ(expected.c_str(), message.c_str());
            throw;
          }
        },
        IllegalArgumentException);
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
    parameter.getDocument()->reserveNewLine(NewLine::getUnixNewLine());
    SectionPairFileReader reader{parameter};
    shared_ptr<MockFileReader> mockFileReader = dynamic_pointer_cast<MockFileReader>(parameter.getReader());

    EXPECT_CALL(*mockFileReader, read()).Times(AtLeast(1));
    ON_CALL(*mockFileReader, read()).WillByDefault(Return(SectionPairFileReaderTest::getMockSectionPairFileContent()));

    reader.read();

    ASSERT_TRUE(!reader.getDocument()->getSectionList().empty());
    ASSERT_STREQ("general", reader.getDocument()->get(0)->getSectionId().c_str());
    ASSERT_EQ(2, reader.getDocument()->get(0)->getRowAmount());
  }

  INSTANTIATE_TEST_SUITE_P(NotValidFileExtension, SectionPairFileReaderTest_NotValidFileExtension, Values("settings.json", "/var/log/document.html"));
}
