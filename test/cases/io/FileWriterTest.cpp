/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2023-02-05
 *
 * */

#include <classes/TestHelper.hpp>
#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>
#include <ls-std/ls-std-io.hpp>

using namespace ls::std::core;
using namespace ls::std::io;
using namespace ::std;
using namespace ls::std::test;

namespace
{
  class FileWriterTest : public ::testing::Test
  {
    protected:

      FileWriterTest() = default;
      ~FileWriterTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(FileWriterTest, constructor_file_does_not_exist)
  {
    string path = TestHelper::getResourcesFolderLocation() + "not_existing_file.txt";
    File file{path};

    EXPECT_THROW(
        {
          try
          {
            FileWriter writer{file};
          }
          catch (const FileNotFoundException &_exception)
          {
            throw;
          }
        },
        FileNotFoundException);
  }

  TEST_F(FileWriterTest, reset)
  {
    string path = TestHelper::getResourcesFolderLocation() + "tmp_file_writer_test.txt";
    File file{path};
    file.createNewFile();
    FileWriter writer{file};
    ASSERT_TRUE(writer.write("Testing something!\n"));

    // reset

    path = TestHelper::getResourcesFolderLocation() + "tmp_file_writer_test2.txt";
    File anotherFile{path};
    anotherFile.createNewFile();

    writer.reset(anotherFile);
    ASSERT_TRUE(writer.write("Testing something else!\n"));

    // remove

    file.remove();
    ASSERT_FALSE(file.exists());
    anotherFile.remove();
    ASSERT_FALSE(anotherFile.exists());
  }

  TEST_F(FileWriterTest, write)
  {
    string path = TestHelper::getResourcesFolderLocation() + "tmp_file_writer_test.txt";
    File file{path};

    ASSERT_FALSE(file.exists());
    file.createNewFile();
    ASSERT_TRUE(file.exists());

    FileWriter writer{file};
    ASSERT_TRUE(writer.write("Testing something!\n"));

    file.remove();
    ASSERT_FALSE(file.exists());
  }
}
