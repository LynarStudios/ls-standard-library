/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-20
 * Changed:         2022-05-06
 *
 * */

#include <gtest/gtest.h>
#include <TestHelper.hpp>
#include <ls_std/ls_std.hpp>

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
    std::string path = TestHelper::getResourcesFolderLocation() + "not_existing.txt";
    ls::File file{path};

    EXPECT_THROW({
                   try
                   {
                     ls::FileOutputStream outputStream{file};
                   }
                   catch (const ls::FileNotFoundException &_exception)
                   {
                     throw;
                   }
                 }, ls::FileNotFoundException);
  }

  TEST_F(FileOutputStreamTest, write)
  {
    std::string path = TestHelper::getResourcesFolderLocation() + "tmp_output_stream.txt";
    ls::File file{path};
    file.createNewFile();
    ASSERT_TRUE(file.exists());

    ls::FileOutputStream outputStream{file};
    ASSERT_TRUE(outputStream.write("Hello! "));
    ASSERT_TRUE(outputStream.write("How are you?"));
    outputStream.close();

    file.remove();
    ASSERT_FALSE(file.exists());
  }

  TEST_F(FileOutputStreamTest, write_with_another_appending_stream)
  {
    std::string path = TestHelper::getResourcesFolderLocation() + "tmp_output_stream.txt";
    ls::File file{path};
    file.createNewFile();
    ASSERT_TRUE(file.exists());

    ls::FileOutputStream outputStream{file};
    ASSERT_TRUE(outputStream.write("Hello! "));
    ASSERT_TRUE(outputStream.write("How are you?"));
    outputStream.close();

    ls::FileOutputStream newOutputStream{file, true};
    ASSERT_TRUE(newOutputStream.write(" I'm fine! "));
    ASSERT_TRUE(newOutputStream.write("Thank you!"));
    newOutputStream.close();

    // validation

    ls::FileReader reader{file};
    ls::std::boxing::String content{reader.read()};

    ASSERT_TRUE(content.contains("Hello! How are you? I'm fine! Thank you!"));

    file.remove();
    ASSERT_FALSE(file.exists());
  }

  TEST_F(FileOutputStreamTest, write_no_permission_to_write)
  {
    #if defined(unix) || defined(__APPLE__)
    ls::File file{TestHelper::getResourcesFolderLocation() + "no_writable.txt"};
    #endif
    #ifdef _WIN32
    ls::File file{TestHelper::getResourcesFolderLocation() + "no_writable_windows.txt"};
    #endif

    ls::FileOutputStream outputStream{file};

    EXPECT_THROW({
                   try
                   {
                     outputStream.write("something");
                   }
                   catch (const ls::FileOperationException &_exception)
                   {
                     throw;
                   }
                 }, ls::FileOperationException);
  }
}
