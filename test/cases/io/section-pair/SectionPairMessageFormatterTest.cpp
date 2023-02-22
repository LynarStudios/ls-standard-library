/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-22
* Changed:         2023-02-22
*
* */

#include <array>
#include <gtest/gtest.h>
#include <ls-std/ls-std-io.hpp>
#include <string>

using namespace ls::std::io;
using namespace ::std;

namespace
{
  class SectionPairMessageFormatterTest : public ::testing::TestWithParam<array<string, 2>>
  {
    protected:

      SectionPairMessageFormatterTest() = default;
      ~SectionPairMessageFormatterTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}

    public:

      static string getFormattedExampleMessage(const string &_replacementString)
      {
        string formattedMessage = _replacementString + "[general]" + _replacementString + _replacementString;
        formattedMessage += "name=Tina" + _replacementString;
        formattedMessage += "age=17" + _replacementString;
        formattedMessage += "birthday=25.01.2006" + _replacementString;

        return formattedMessage;
      }

      static string getOriginalExampleMessage(const string &_newLine)
      {
        string formattedMessage = _newLine + "[general]" + _newLine + _newLine;
        formattedMessage += "name=Tina" + _newLine;
        formattedMessage += "age=17" + _newLine;
        formattedMessage += "birthday=25.01.2006" + _newLine;

        return formattedMessage;
      }
  };

  TEST_P(SectionPairMessageFormatterTest, getFormattedMessage)
  {
    string expected = GetParam().at(0);
    string actual = SectionPairMessageFormatter::getFormattedMessage(GetParam().at(1));

    ASSERT_STREQ(expected.c_str(), actual.c_str());
  }

  INSTANTIATE_TEST_SUITE_P(ValidArgumentTest, SectionPairMessageFormatterTest, ::testing::Values(array<string, 2>{SectionPairMessageFormatterTest::getFormattedExampleMessage("{UNIX_LINE_BREAK}"), SectionPairMessageFormatterTest::getOriginalExampleMessage("\n")}, array<string, 2>{SectionPairMessageFormatterTest::getFormattedExampleMessage("{WINDOWS_LINE_BREAK}"), SectionPairMessageFormatterTest::getOriginalExampleMessage("\r\n")}));
}
