/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-18
 * Changed:         2021-09-17
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
    ls_std::File file{TestHelper::getResourcesFolderLocation() + "does_not_exist.txt"};

    EXPECT_THROW({
                   try
                   {
                     ls_std::FileReader reader{file};
                   }
                   catch (const ls_std::FileNotFoundException &_exception)
                   {
                     throw;
                   }
                 }, ls_std::FileNotFoundException);
  }

  TEST_F(FileReaderTest, read)
  {
    ls_std::File file{TestHelper::getResourcesFolderLocation() + "simple.txt"};
    ls_std::FileReader reader{file};
    std::string expectedUnix = "Hello!" + ls_std::NewLine::getUnixNewLine();
    std::string expectedWindows = "Hello!" + ls_std::NewLine::getWindowsNewLine();

    ls_std::byte_field content = reader.read();
    ASSERT_TRUE(content == expectedUnix || content == expectedWindows);
  }

  TEST_F(FileReaderTest, read_file_gets_lost_in_between)
  {
    ls_std::File file{TestHelper::getResourcesFolderLocation() + "lost_readable_file.txt"};
    file.createNewFile();
    ls_std::FileReader reader{file};
    file.remove();

    EXPECT_THROW({
                   try
                   {
                     ls_std::byte_field content = reader.read();
                   }
                   catch (const ls_std::FileOperationException &_exception)
                   {
                     throw;
                   }
                 }, ls_std::FileOperationException);
  }

  TEST_F(FileReaderTest, reset)
  {
    ls_std::File file{TestHelper::getResourcesFolderLocation() + "simple.txt"};
    ls_std::FileReader reader{file};
    std::string expectedUnix = "Hello!" + ls_std::NewLine::getUnixNewLine();
    std::string expectedWindows = "Hello!" + ls_std::NewLine::getWindowsNewLine();

    ls_std::byte_field content = reader.read();
    ASSERT_TRUE(content == expectedUnix || content == expectedWindows);

    ls_std::File anotherFile{TestHelper::getResourcesFolderLocation() + "list_test/bla.txt"};
    reader.reset(anotherFile);
    expectedUnix = "nothing to say!" + ls_std::NewLine::getUnixNewLine();
    expectedWindows = "nothing to say!" + ls_std::NewLine::getWindowsNewLine();

    content = reader.read();
    ASSERT_TRUE(content == expectedUnix || content == expectedWindows);
  }
}
