/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-20
 * Changed:         2021-09-17
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
    ls_std::File file{path};

    EXPECT_THROW({
                   try
                   {
                     ls_std::FileOutputStream outputStream{file};
                   }
                   catch (const ls_std::FileNotFoundException &_exception)
                   {
                     throw;
                   }
                 }, ls_std::FileNotFoundException);
  }

  TEST_F(FileOutputStreamTest, write)
  {
    std::string path = TestHelper::getResourcesFolderLocation() + "tmp_output_stream.txt";
    ls_std::File file{path};
    file.createNewFile();
    ASSERT_TRUE(file.exists());

    ls_std::FileOutputStream outputStream{file};
    ASSERT_TRUE(outputStream.write("Hello! "));
    ASSERT_TRUE(outputStream.write("How are you?"));
    outputStream.close();

    file.remove();
    ASSERT_FALSE(file.exists());
  }

  TEST_F(FileOutputStreamTest, write_with_another_appending_stream)
  {
    std::string path = TestHelper::getResourcesFolderLocation() + "tmp_output_stream.txt";
    ls_std::File file{path};
    file.createNewFile();
    ASSERT_TRUE(file.exists());

    ls_std::FileOutputStream outputStream{file};
    ASSERT_TRUE(outputStream.write("Hello! "));
    ASSERT_TRUE(outputStream.write("How are you?"));
    outputStream.close();

    ls_std::FileOutputStream newOutputStream{file, true};
    ASSERT_TRUE(newOutputStream.write(" I'm fine! "));
    ASSERT_TRUE(newOutputStream.write("Thank you!"));
    newOutputStream.close();

    // validation

    ls_std::FileReader reader{file};
    ls_std::String content{reader.read()};

    ASSERT_TRUE(content.contains("Hello! How are you? I'm fine! Thank you!"));

    file.remove();
    ASSERT_FALSE(file.exists());
  }

  TEST_F(FileOutputStreamTest, write_no_permission_to_write)
  {
    #if defined(unix) || defined(__APPLE__)
    ls_std::File file{TestHelper::getResourcesFolderLocation() + "no_writable.txt"};
    #endif
    #ifdef _WIN32
    ls_std::File file{TestHelper::getResourcesFolderLocation() + "no_writable_windows.txt"};
    #endif

    ls_std::FileOutputStream outputStream{file};

    EXPECT_THROW({
                   try
                   {
                     outputStream.write("something");
                   }
                   catch (const ls_std::FileOperationException &_exception)
                   {
                     throw;
                   }
                 }, ls_std::FileOperationException);
  }
}
