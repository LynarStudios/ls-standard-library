/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-18
 * Changed:         2022-05-11
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
    ls::std::io::File file{TestHelper::getResourcesFolderLocation() + "does_not_exist.txt"};

    EXPECT_THROW({
                   try
                   {
                     ls::std::io::FileReader reader{file};
                   }
                   catch (const ls::std::core::FileNotFoundException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::FileNotFoundException);
  }

  TEST_F(FileReaderTest, read)
  {
    ls::std::io::File file{TestHelper::getResourcesFolderLocation() + "simple.txt"};
    ls::std::io::FileReader reader{file};
    std::string expectedUnix = "Hello!" + ls::std::io::NewLine::getUnixNewLine();
    std::string expectedWindows = "Hello!" + ls::std::io::NewLine::getWindowsNewLine();

    ls::std::core::byte_field content = reader.read();
    ASSERT_TRUE(content == expectedUnix || content == expectedWindows);
  }

  TEST_F(FileReaderTest, read_file_gets_lost_in_between)
  {
    ls::std::io::File file{TestHelper::getResourcesFolderLocation() + "lost_readable_file.txt"};
    file.createNewFile();
    ls::std::io::FileReader reader{file};
    file.remove();

    EXPECT_THROW({
                   try
                   {
                     ls::std::core::byte_field content = reader.read();
                   }
                   catch (const ls::std::core::FileOperationException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::FileOperationException);
  }

  TEST_F(FileReaderTest, reset)
  {
    ls::std::io::File file{TestHelper::getResourcesFolderLocation() + "simple.txt"};
    ls::std::io::FileReader reader{file};
    std::string expectedUnix = "Hello!" + ls::std::io::NewLine::getUnixNewLine();
    std::string expectedWindows = "Hello!" + ls::std::io::NewLine::getWindowsNewLine();

    ls::std::core::byte_field content = reader.read();
    ASSERT_TRUE(content == expectedUnix || content == expectedWindows);

    ls::std::io::File anotherFile{TestHelper::getResourcesFolderLocation() + "list_test/bla.txt"};
    reader.reset(anotherFile);
    expectedUnix = "nothing to say!" + ls::std::io::NewLine::getUnixNewLine();
    expectedWindows = "nothing to say!" + ls::std::io::NewLine::getWindowsNewLine();

    content = reader.read();
    ASSERT_TRUE(content == expectedUnix || content == expectedWindows);
  }
}
