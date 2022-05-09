/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2022-05-09
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>
#include <TestHelper.hpp>

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
    std::string path = TestHelper::getResourcesFolderLocation() + "not_existing_file.txt";
    ls::File file{path};

    EXPECT_THROW({
                   try
                   {
                     ls::FileWriter writer{file};
                   }
                   catch (const ls::std::core::FileNotFoundException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::FileNotFoundException);
  }

  TEST_F(FileWriterTest, reset)
  {
    std::string path = TestHelper::getResourcesFolderLocation() + "tmp_file_writer_test.txt";
    ls::File file{path};
    file.createNewFile();
    ls::FileWriter writer{file};
    ASSERT_TRUE(writer.write("Testing something!\n"));

    // reset

    path = TestHelper::getResourcesFolderLocation() + "tmp_file_writer_test2.txt";
    ls::File anotherFile{path};
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
    std::string path = TestHelper::getResourcesFolderLocation() + "tmp_file_writer_test.txt";
    ls::File file{path};

    ASSERT_FALSE(file.exists());
    file.createNewFile();
    ASSERT_TRUE(file.exists());

    ls::FileWriter writer{file};
    ASSERT_TRUE(writer.write("Testing something!\n"));

    file.remove();
    ASSERT_FALSE(file.exists());
  }
}
