/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-20
 * Changed:         2022-11-09
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std_core.hpp>
#include <ls_std/ls_std_io.hpp>
#include "TestHelper.hpp"

using namespace ls::std::core;
using namespace ls::std::io;
using namespace ::std;
using namespace ls_std_test;

namespace
{
  class FileOutputStreamTest : public ::testing::Test
  {
    protected:

      FileOutputStreamTest() = default;
      ~FileOutputStreamTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(FileOutputStreamTest, constructor_file_does_not_exist)
  {
    string path = TestHelper::getResourcesFolderLocation() + "not_existing.txt";
    File file{path};

    EXPECT_THROW({
                   try
                   {
                     FileOutputStream outputStream{file};
                   }
                   catch (const FileNotFoundException &_exception)
                   {
                     throw;
                   }
                 }, FileNotFoundException);
  }

  TEST_F(FileOutputStreamTest, write)
  {
    string path = TestHelper::getResourcesFolderLocation() + "tmp_output_stream.txt";
    File file{path};
    file.createNewFile();
    ASSERT_TRUE(file.exists());

    FileOutputStream outputStream{file};
    ASSERT_TRUE(outputStream.write("Hello! "));
    ASSERT_TRUE(outputStream.write("How are you?"));
    outputStream.close();

    file.remove();
    ASSERT_FALSE(file.exists());
  }

  TEST_F(FileOutputStreamTest, write_with_another_appending_stream)
  {
    string path = TestHelper::getResourcesFolderLocation() + "tmp_output_stream.txt";
    File file{path};
    file.createNewFile();
    ASSERT_TRUE(file.exists());

    FileOutputStream outputStream{file};
    ASSERT_TRUE(outputStream.write("Hello! "));
    ASSERT_TRUE(outputStream.write("How are you?"));
    outputStream.close();

    FileOutputStream newOutputStream{file, true};
    ASSERT_TRUE(newOutputStream.write(" I'm fine! "));
    ASSERT_TRUE(newOutputStream.write("Thank you!"));
    newOutputStream.close();

    // validation

    FileReader reader{file};
    string content{reader.read()};

    ASSERT_TRUE(content.find("Hello! How are you? I'm fine! Thank you!") != string::npos);

    file.remove();
    ASSERT_FALSE(file.exists());
  }

  TEST_F(FileOutputStreamTest, write_no_permission_to_write)
  {
    #if defined(unix) || defined(__APPLE__)
    File file{TestHelper::getResourcesFolderLocation() + "no_writable.txt"};
    #endif
    #ifdef _WIN32
    File file{TestHelper::getResourcesFolderLocation() + "no_writable_windows.txt"};
    #endif

    FileOutputStream outputStream{file};

    EXPECT_THROW({
                   try
                   {
                     outputStream.write("something");
                   }
                   catch (const FileOperationException &_exception)
                   {
                     throw;
                   }
                 }, FileOperationException);
  }
}
