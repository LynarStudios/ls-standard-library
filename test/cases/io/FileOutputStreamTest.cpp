/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-20
 * Changed:         2023-03-25
 *
 * */

#include <classes/TestHelper.hpp>
#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>
#include <ls-std/ls-std-io.hpp>

using ls::std::core::FileNotFoundException;
using ls::std::core::FileOperationException;
using ls::std::io::File;
using ls::std::io::FileOutputStream;
using ls::std::io::FileReader;
using ls::std::test::TestHelper;
using std::string;
using testing::Test;

namespace
{
  class FileOutputStreamTest : public Test
  {
    public:

      FileOutputStreamTest() = default;
      ~FileOutputStreamTest() override = default;
  };

  TEST_F(FileOutputStreamTest, constructor_file_does_not_exist)
  {
    string path = TestHelper::getResourcesFolderLocation() + "not-existing.txt";
    File file{path};

    EXPECT_THROW(
        {
          try
          {
            FileOutputStream outputStream{file};
          }
          catch (const FileNotFoundException &_exception)
          {
            throw;
          }
        },
        FileNotFoundException);
  }

  TEST_F(FileOutputStreamTest, write)
  {
    string path = TestHelper::getResourcesFolderLocation() + "tmp-output-stream.txt";
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
    string path = TestHelper::getResourcesFolderLocation() + "tmp-output-stream.txt";
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
    File file{TestHelper::getResourcesFolderLocation() + "no-writable.txt"};
#endif
#ifdef _WIN32
    File file{TestHelper::getResourcesFolderLocation() + "no-writable-windows.txt"};
#endif

    FileOutputStream outputStream{file};

    EXPECT_THROW(
        {
          try
          {
            outputStream.write("something");
          }
          catch (const FileOperationException &_exception)
          {
            throw;
          }
        },
        FileOperationException);
  }
}
