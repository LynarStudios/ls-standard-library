/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-18
 * Changed:         2020-10-29
 *
 * */

#include <gtest/gtest.h>
#include "../../TestHelper.hpp"
#include <ls_std/ls_std.hpp>

namespace {
  class FileReaderTest : public ::testing::Test {
    protected:

      FileReaderTest() = default;
      ~FileReaderTest() override = default;

      void SetUp() override {}
      void TearDown() override {}
  };

  TEST_F(FileReaderTest, read)
  {
    ls_std::File file {TestHelper::getResourcesFolderLocation() + "simple.txt"};
    ls_std::FileReader reader {file};
    std::string expectedUnix = "Hello!" + ls_std::NewLine::getUnixNewLine();
    std::string expectedWindows = "Hello!" + ls_std::NewLine::getWindowsNewLine();

    ls_std::byte_field content = reader.read();
    ASSERT_TRUE(content == expectedUnix || content == expectedWindows);
  }

  TEST_F(FileReaderTest, reset)
  {
    ls_std::File file {TestHelper::getResourcesFolderLocation() + "simple.txt"};
    ls_std::FileReader reader {file};
    std::string expectedUnix = "Hello!" + ls_std::NewLine::getUnixNewLine();
    std::string expectedWindows = "Hello!" + ls_std::NewLine::getWindowsNewLine();

    ls_std::byte_field content = reader.read();
    ASSERT_TRUE(content == expectedUnix || content == expectedWindows);

    ls_std::File anotherFile {TestHelper::getResourcesFolderLocation() + "list_test/bla.txt"};
    reader.reset(anotherFile);
    expectedUnix = "nothing to say!" + ls_std::NewLine::getUnixNewLine();
    expectedWindows = "nothing to say!" + ls_std::NewLine::getWindowsNewLine();

    content = reader.read();
    ASSERT_TRUE(content == expectedUnix || content == expectedWindows);
  }
}
