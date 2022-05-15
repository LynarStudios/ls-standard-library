/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-20
 * Changed:         2022-05-15
 *
 * */

#include <gtest/gtest.h>
#include <ls_std_io_test.hpp>
#include <ls_std/ls_std_core.hpp>
#include <ls_std/ls_std_io.hpp>

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
    std::string path = ls_std_io_test::TestHelper::getResourcesFolderLocation() + "not_existing.txt";
    ls::std::io::File file{path};

    EXPECT_THROW({
                   try
                   {
                     ls::std::io::FileOutputStream outputStream{file};
                   }
                   catch (const ls::std::core::FileNotFoundException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::FileNotFoundException);
  }

  TEST_F(FileOutputStreamTest, write)
  {
    std::string path = ls_std_io_test::TestHelper::getResourcesFolderLocation() + "tmp_output_stream.txt";
    ls::std::io::File file{path};
    file.createNewFile();
    ASSERT_TRUE(file.exists());

    ls::std::io::FileOutputStream outputStream{file};
    ASSERT_TRUE(outputStream.write("Hello! "));
    ASSERT_TRUE(outputStream.write("How are you?"));
    outputStream.close();

    file.remove();
    ASSERT_FALSE(file.exists());
  }

  TEST_F(FileOutputStreamTest, write_with_another_appending_stream)
  {
    std::string path = ls_std_io_test::TestHelper::getResourcesFolderLocation() + "tmp_output_stream.txt";
    ls::std::io::File file{path};
    file.createNewFile();
    ASSERT_TRUE(file.exists());

    ls::std::io::FileOutputStream outputStream{file};
    ASSERT_TRUE(outputStream.write("Hello! "));
    ASSERT_TRUE(outputStream.write("How are you?"));
    outputStream.close();

    ls::std::io::FileOutputStream newOutputStream{file, true};
    ASSERT_TRUE(newOutputStream.write(" I'm fine! "));
    ASSERT_TRUE(newOutputStream.write("Thank you!"));
    newOutputStream.close();

    // validation

    ls::std::io::FileReader reader{file};
    ::std::string content{reader.read()};

    ASSERT_TRUE(content.find("Hello! How are you? I'm fine! Thank you!") != ::std::string::npos);

    file.remove();
    ASSERT_FALSE(file.exists());
  }

  TEST_F(FileOutputStreamTest, write_no_permission_to_write)
  {
    #if defined(unix) || defined(__APPLE__)
    ls::std::io::File file{ls_std_io_test::TestHelper::getResourcesFolderLocation() + "no_writable.txt"};
    #endif
    #ifdef _WIN32
    ls::std::io::File file{ls_std_io_test::TestHelper::getResourcesFolderLocation() + "no_writable_windows.txt"};
    #endif

    ls::std::io::FileOutputStream outputStream{file};

    EXPECT_THROW({
                   try
                   {
                     outputStream.write("something");
                   }
                   catch (const ls::std::core::FileOperationException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::FileOperationException);
  }
}
