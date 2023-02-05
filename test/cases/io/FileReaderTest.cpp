/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-18
 * Changed:         2023-02-05
 *
 * */

#include <classes/TestHelper.hpp>
#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>
#include <ls-std/ls-std-io.hpp>

using namespace ls::std::core;
using namespace ls::std::core::type;
using namespace ls::std::io;
using namespace ls::std::test;
using namespace ::std;

namespace
{
  class FileReaderTest : public ::testing::Test
  {
    protected:

      FileReaderTest() = default;
      ~FileReaderTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(FileReaderTest, constructor_file_does_not_exist)
  {
    File file{TestHelper::getResourcesFolderLocation() + "does_not_exist.txt"};

    EXPECT_THROW(
        {
          try
          {
            FileReader reader{file};
          }
          catch (const FileNotFoundException &_exception)
          {
            throw;
          }
        },
        FileNotFoundException);
  }

  TEST_F(FileReaderTest, read)
  {
    File file{TestHelper::getResourcesFolderLocation() + "simple.txt"};
    FileReader reader{file};
    string expectedUnix = "Hello!" + NewLine::getUnixNewLine();
    string expectedWindows = "Hello!" + NewLine::getWindowsNewLine();

    byte_field content = reader.read();
    ASSERT_TRUE(content == expectedUnix || content == expectedWindows);
  }

  TEST_F(FileReaderTest, read_file_gets_lost_in_between)
  {
    File file{TestHelper::getResourcesFolderLocation() + "lost_readable_file.txt"};
    file.createNewFile();
    FileReader reader{file};
    file.remove();

    EXPECT_THROW(
        {
          try
          {
            byte_field content = reader.read();
          }
          catch (const FileOperationException &_exception)
          {
            throw;
          }
        },
        FileOperationException);
  }

  TEST_F(FileReaderTest, reset)
  {
    File file{TestHelper::getResourcesFolderLocation() + "simple.txt"};
    FileReader reader{file};
    string expectedUnix = "Hello!" + NewLine::getUnixNewLine();
    string expectedWindows = "Hello!" + NewLine::getWindowsNewLine();

    byte_field content = reader.read();
    ASSERT_TRUE(content == expectedUnix || content == expectedWindows);

    File anotherFile{TestHelper::getResourcesFolderLocation() + "list-test/bla.txt"};
    reader.reset(anotherFile);
    expectedUnix = "nothing to say!" + NewLine::getUnixNewLine();
    expectedWindows = "nothing to say!" + NewLine::getWindowsNewLine();

    content = reader.read();
    ASSERT_TRUE(content == expectedUnix || content == expectedWindows);
  }
}
