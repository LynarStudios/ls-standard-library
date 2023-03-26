/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-18
 * Changed:         2023-03-25
 *
 * */

#include <classes/TestHelper.hpp>
#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>
#include <ls-std/ls-std-io.hpp>

using ls::std::core::FileNotFoundException;
using ls::std::core::FileOperationException;
using ls::std::core::type::byte_field;
using ls::std::io::File;
using ls::std::io::FileReader;
using ls::std::io::NewLine;
using ls::std::test::TestHelper;
using std::string;
using testing::Test;

namespace
{
  class FileReaderTest : public Test
  {
    public:

      FileReaderTest() = default;
      ~FileReaderTest() override = default;
  };

  TEST_F(FileReaderTest, constructor_file_does_not_exist)
  {
    File file{TestHelper::getResourcesFolderLocation() + "does-not-exist.txt"};

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
    File file{TestHelper::getResourcesFolderLocation() + "lost-readable-file.txt"};
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
