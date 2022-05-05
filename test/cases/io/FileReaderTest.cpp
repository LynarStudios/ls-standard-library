/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-18
 * Changed:         2022-05-05
 *
 * */

#include <gtest/gtest.h>
#include <TestHelper.hpp>
#include <ls_std/ls_std.hpp>

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
    ls::File file{TestHelper::getResourcesFolderLocation() + "does_not_exist.txt"};

    EXPECT_THROW({
                   try
                   {
                     ls::FileReader reader{file};
                   }
                   catch (const ls::FileNotFoundException &_exception)
                   {
                     throw;
                   }
                 }, ls::FileNotFoundException);
  }

  TEST_F(FileReaderTest, read)
  {
    ls::File file{TestHelper::getResourcesFolderLocation() + "simple.txt"};
    ls::FileReader reader{file};
    std::string expectedUnix = "Hello!" + ls::NewLine::getUnixNewLine();
    std::string expectedWindows = "Hello!" + ls::NewLine::getWindowsNewLine();

    ls::byte_field content = reader.read();
    ASSERT_TRUE(content == expectedUnix || content == expectedWindows);
  }

  TEST_F(FileReaderTest, read_file_gets_lost_in_between)
  {
    ls::File file{TestHelper::getResourcesFolderLocation() + "lost_readable_file.txt"};
    file.createNewFile();
    ls::FileReader reader{file};
    file.remove();

    EXPECT_THROW({
                   try
                   {
                     ls::byte_field content = reader.read();
                   }
                   catch (const ls::FileOperationException &_exception)
                   {
                     throw;
                   }
                 }, ls::FileOperationException);
  }

  TEST_F(FileReaderTest, reset)
  {
    ls::File file{TestHelper::getResourcesFolderLocation() + "simple.txt"};
    ls::FileReader reader{file};
    std::string expectedUnix = "Hello!" + ls::NewLine::getUnixNewLine();
    std::string expectedWindows = "Hello!" + ls::NewLine::getWindowsNewLine();

    ls::byte_field content = reader.read();
    ASSERT_TRUE(content == expectedUnix || content == expectedWindows);

    ls::File anotherFile{TestHelper::getResourcesFolderLocation() + "list_test/bla.txt"};
    reader.reset(anotherFile);
    expectedUnix = "nothing to say!" + ls::NewLine::getUnixNewLine();
    expectedWindows = "nothing to say!" + ls::NewLine::getWindowsNewLine();

    content = reader.read();
    ASSERT_TRUE(content == expectedUnix || content == expectedWindows);
  }
}
