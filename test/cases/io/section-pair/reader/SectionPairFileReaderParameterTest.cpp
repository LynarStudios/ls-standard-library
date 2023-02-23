/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-21
* Changed:         2023-02-23
*
* */

#include <gtest/gtest.h>
#include <ls-std/ls-std-io.hpp>

using ls::std::io::FileExistenceEvaluator;
using ls::std::io::SectionPairDocument;
using ls::std::io::SectionPairFileReaderParameter;
using std::make_shared;
using testing::Test;

namespace
{
  class SectionPairFileReaderParameterTest : public Test
  {
    protected:

      SectionPairFileReaderParameterTest() = default;
      ~SectionPairFileReaderParameterTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(SectionPairFileReaderParameterTest, getDocument)
  {
    ASSERT_TRUE(SectionPairFileReaderParameter{}.getDocument() == nullptr);
  }

  TEST_F(SectionPairFileReaderParameterTest, getFileExistenceEvaluator)
  {
    ASSERT_TRUE(SectionPairFileReaderParameter{}.getFileExistenceEvaluator() == nullptr);
  }

  TEST_F(SectionPairFileReaderParameterTest, getFilePath)
  {
    ASSERT_TRUE(SectionPairFileReaderParameter{}.getFilePath().empty());
  }

  TEST_F(SectionPairFileReaderParameterTest, getReader)
  {
    ASSERT_TRUE(SectionPairFileReaderParameter{}.getReader() == nullptr);
  }

  TEST_F(SectionPairFileReaderParameterTest, setDocument)
  {
    SectionPairFileReaderParameter parameter{};
    parameter.setDocument(make_shared<SectionPairDocument>());

    ASSERT_FALSE(parameter.getDocument() == nullptr);
  }

  TEST_F(SectionPairFileReaderParameterTest, setFileExistenceEvaluator)
  {
    SectionPairFileReaderParameter parameter{};
    parameter.setFileExistenceEvaluator(make_shared<FileExistenceEvaluator>("/var/log/file.txt"));

    ASSERT_FALSE(parameter.getFileExistenceEvaluator() == nullptr);
  }

  TEST_F(SectionPairFileReaderParameterTest, setFilePath)
  {
    SectionPairFileReaderParameter parameter{};
    parameter.setFilePath("var/log/log.txt");

    ASSERT_FALSE(parameter.getFilePath().empty());
  }
}
