/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-15
 * Changed:         2022-05-05
 *
 * */

#include <gtest/gtest.h>
#include <TestHelper.hpp>
#include <ls_std/ls_std.hpp>

namespace
{
  class FileTest : public ::testing::Test
  {
    protected:

      FileTest() = default;
      ~FileTest() override = default;

      std::string fileLocation = TestHelper::getResourcesFolderLocation() + "simple.txt";

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  // comparison operators

  TEST_F(FileTest, operator_equals)
  {
    ls::File file{this->fileLocation};
    ls::File file2{this->fileLocation};
    ls::File file3{"/home/bla/text.txt"};
    ls::File file4{"\\home/bla\\text.txt"};

    ASSERT_TRUE(file == file2);
    ASSERT_TRUE(file2 == file);
    ASSERT_TRUE(file3 == file4);
    ASSERT_TRUE(file4 == file3);
  }

  TEST_F(FileTest, operator_not_equals)
  {
    ls::File file{this->fileLocation};
    ls::File file2{TestHelper::getResourcesFolderLocation() + "app.exe"};

    ASSERT_TRUE(file != file2);
    ASSERT_TRUE(file2 != file);
  }

  // additional functionality

  TEST_F(FileTest, canExecute)
  {
    #ifdef _WIN32
    ls::File executableFile{TestHelper::getResourcesFolderLocation() + "app.exe"};
    #endif
    #if defined(unix) || defined(__APPLE__)
    ls::File executableFile{TestHelper::getResourcesFolderLocation() + "app"};
    #endif

    ASSERT_TRUE(executableFile.canExecute());
  }

  TEST_F(FileTest, canExecute_not_executable)
  {
    ls::File file{this->fileLocation};
    ASSERT_FALSE(file.canExecute());
  }

  TEST_F(FileTest, canRead)
  {
    ls::File readableFile{this->fileLocation};
    ASSERT_TRUE(readableFile.canRead());
  }

  TEST_F(FileTest, canRead_file_does_not_exist)
  {
    ls::File file{""};

    EXPECT_THROW({
                   try
                   {
                     file.canRead();
                   }
                   catch (const ls::FileOperationException &_exception)
                   {
                     throw;
                   }
                 }, ls::FileOperationException);
  }

  TEST_F(FileTest, canWrite)
  {
    ls::File readableFile{this->fileLocation};
    ASSERT_TRUE(readableFile.canWrite());
  }

  TEST_F(FileTest, canWrite_not_writable)
  {
    #if defined(unix) || defined(__APPLE__)
    ls::File noWritableFile{TestHelper::getResourcesFolderLocation() + "no_writable.txt"};
    ASSERT_FALSE(noWritableFile.canWrite());
    #endif
    #ifdef _WIN32
    ls::File noWritableFile{TestHelper::getResourcesFolderLocation() + "no_writable_windows.txt"};
    ASSERT_FALSE(noWritableFile.canWrite());
    #endif
  }

  TEST_F(FileTest, createNewFile)
  {
    ls::File file{TestHelper::getResourcesFolderLocation() + "tmp.txt"};
    ASSERT_FALSE(file.exists());

    file.createNewFile();
    ASSERT_TRUE(file.exists());

    file.remove();
    ASSERT_FALSE(file.exists());
  }

  TEST_F(FileTest, createNewFile_file_does_already_exist)
  {
    ls::File file{TestHelper::getResourcesFolderLocation() + "simple.txt"};

    EXPECT_THROW({
                   try
                   {
                     file.createNewFile();
                   }
                   catch (const ls::FileOperationException &_exception)
                   {
                     throw;
                   }
                 }, ls::FileOperationException);
  }

  TEST_F(FileTest, exists)
  {
    ls::File file{this->fileLocation};
    ls::File directory{TestHelper::getResourcesFolderLocation()};

    ASSERT_TRUE(file.exists());
    ASSERT_TRUE(directory.exists());
  }

  TEST_F(FileTest, exists_does_not_exist)
  {
    ls::File file{TestHelper::getResourcesFolderLocation() + "bla.txt"};
    ASSERT_FALSE(file.exists());
  }

  TEST_F(FileTest, getAbsoluteFilePath)
  {
    ls::File file{this->fileLocation};
    ASSERT_STREQ(this->fileLocation.c_str(), file.getAbsoluteFilePath().c_str());
    std::string s = {ls::FilePathSeparator::get()};

    std::string wrongFilePath = "home" + s + s + s + "user" + s + "bla" + s + s + "sub_folder";
    std::string expectedFilePath = "home" + s + "user" + s + "bla" + s + "sub_folder";
    ls::File anotherFile{wrongFilePath};
    ASSERT_STREQ(expectedFilePath.c_str(), anotherFile.getAbsoluteFilePath().c_str());
  }

  TEST_F(FileTest, getName)
  {
    ls::File file{this->fileLocation};
    ls::File executableFile{TestHelper::getResourcesFolderLocation() + "app.exe"};
    ls::File anotherFile{"bla.txt"};
    ls::File directory{TestHelper::getResourcesFolderLocation()};

    ASSERT_STREQ("simple.txt", file.getName().c_str());
    ASSERT_STREQ("app.exe", executableFile.getName().c_str());
    ASSERT_STREQ("bla.txt", anotherFile.getName().c_str());
    ASSERT_STREQ("resources", directory.getName().c_str());
  }

  TEST_F(FileTest, getParent)
  {
    ls::File file{this->fileLocation};
    ASSERT_STREQ(TestHelper::getResourcesFolderLocation().c_str(), file.getParent().c_str());
  }

  TEST_F(FileTest, getWorkingDirectory)
  {
    std::string workingDirectory = ls::File::getWorkingDirectory();
    ASSERT_FALSE(workingDirectory.empty());
  }

  TEST_F(FileTest, getSize)
  {
    ls::File file{this->fileLocation};
    size_t size = file.getSize();

    ASSERT_TRUE(size == 7 || size == 8); // different OS specific new lines
  }

  TEST_F(FileTest, isDirectory)
  {
    ls::File directory{TestHelper::getResourcesFolderLocation()};
    ASSERT_TRUE(directory.isDirectory());
  }

  TEST_F(FileTest, isDirectory_is_a_file)
  {
    ls::File file{this->fileLocation};
    ASSERT_FALSE(file.isDirectory());
  }

  TEST_F(FileTest, isFile)
  {
    const char separator = ls::FilePathSeparator::get();

    ls::File file{this->fileLocation};
    ASSERT_TRUE(file.isFile());

    ls::File file2{TestHelper::getResourcesFolderLocation() + "list_test" + separator + "bla.txt"};
    ASSERT_TRUE(file2.isFile());
  }

  TEST_F(FileTest, isFile_is_a_directory)
  {
    ls::File directory{TestHelper::getResourcesFolderLocation()};
    ASSERT_FALSE(directory.isFile());
  }

  TEST_F(FileTest, lastModified)
  {
    ls::File file{this->fileLocation};
    ASSERT_TRUE(file.lastModified() > 1590000000);
  }

  TEST_F(FileTest, list)
  {
    ls::File file{TestHelper::getResourcesFolderLocation() + "list_test"};
    std::list<std::string> filesInDirectory = file.list();
    std::string expectedFile{};
    const char separator = ls::FilePathSeparator::get();

    auto filesIterator = filesInDirectory.begin();

    ASSERT_FALSE(filesInDirectory.empty());
    ASSERT_EQ(7, filesInDirectory.size());

    expectedFile = file.getAbsoluteFilePath() + separator + ".";
    ASSERT_TRUE((ls::STLUtils::contains(filesInDirectory, expectedFile)));
    expectedFile = file.getAbsoluteFilePath() + separator + "..";
    ASSERT_TRUE((ls::STLUtils::contains(filesInDirectory, expectedFile)));
    expectedFile = file.getAbsoluteFilePath() + separator + "another_file.txt";
    ASSERT_TRUE((ls::STLUtils::contains(filesInDirectory, expectedFile)));
    expectedFile = file.getAbsoluteFilePath() + separator + "bla.txt";
    ASSERT_TRUE((ls::STLUtils::contains(filesInDirectory, expectedFile)));
    expectedFile = file.getAbsoluteFilePath() + separator + "hello.txt";
    ASSERT_TRUE((ls::STLUtils::contains(filesInDirectory, expectedFile)));
    expectedFile = file.getAbsoluteFilePath() + separator + "list_test_sub";
    ASSERT_TRUE((ls::STLUtils::contains(filesInDirectory, expectedFile)));
    expectedFile = file.getAbsoluteFilePath() + separator + ".hidden_file.txt";
    ASSERT_TRUE((ls::STLUtils::contains(filesInDirectory, expectedFile)));
  }

  TEST_F(FileTest, listFiles)
  {
    ls::File file{TestHelper::getResourcesFolderLocation() + "list_test"};
    std::list<std::string> filesInDirectory = file.listFiles();
    std::string expectedFile{};
    const char separator = ls::FilePathSeparator::get();

    ASSERT_FALSE(filesInDirectory.empty());
    ASSERT_EQ(4, filesInDirectory.size());

    expectedFile = file.getAbsoluteFilePath() + separator + "another_file.txt";
    ASSERT_TRUE((ls::STLUtils::contains(filesInDirectory, expectedFile)));
    expectedFile = file.getAbsoluteFilePath() + separator + "bla.txt";
    ASSERT_TRUE((ls::STLUtils::contains(filesInDirectory, expectedFile)));
    expectedFile = file.getAbsoluteFilePath() + separator + "hello.txt";
    ASSERT_TRUE((ls::STLUtils::contains(filesInDirectory, expectedFile)));
    expectedFile = file.getAbsoluteFilePath() + separator + ".hidden_file.txt";
    ASSERT_TRUE((ls::STLUtils::contains(filesInDirectory, expectedFile)));
  }

  TEST_F(FileTest, makeDirectory)
  {
    ls::File directory{TestHelper::getResourcesFolderLocation() + "testDir"};
    ASSERT_FALSE(directory.exists());

    directory.makeDirectory();
    ASSERT_TRUE(directory.exists());

    directory.remove();
    ASSERT_FALSE(directory.exists());
  }

  TEST_F(FileTest, makeDirectory_directory_already_exists)
  {
    ls::File directory{TestHelper::getResourcesFolderLocation() + "list_test"};

    EXPECT_THROW({
                   try
                   {
                     directory.makeDirectory();
                   }
                   catch (const ls::FileOperationException &_exception)
                   {
                     throw;
                   }
                 }, ls::FileOperationException);
  }

  TEST_F(FileTest, makeDirectories)
  {
    ls::File directory{TestHelper::getResourcesFolderLocation() + "testDir/sub/tmp/bla"};
    ASSERT_FALSE(directory.exists());

    directory.makeDirectories();
    ASSERT_TRUE(directory.exists());

    // clean up

    directory.remove();
    directory = ls::File(TestHelper::getResourcesFolderLocation() + "testDir/sub/tmp");
    directory.remove();
    directory = ls::File(TestHelper::getResourcesFolderLocation() + "testDir/sub");
    directory.remove();
    directory = ls::File(TestHelper::getResourcesFolderLocation() + "testDir");
    directory.remove();
  }

  TEST_F(FileTest, remove)
  {
    std::string fileName = TestHelper::getResourcesFolderLocation() + "removable_file.txt";
    ls::File file{fileName};
    file.createNewFile();

    ASSERT_TRUE(file.exists());

    file.remove();
    ASSERT_FALSE(file.exists());
  }

  TEST_F(FileTest, renameTo)
  {
    std::string currentName = TestHelper::getResourcesFolderLocation() + "tmp_rename_to.txt";
    std::string newName = TestHelper::getResourcesFolderLocation() + "tmp_rename_to_better_name.txt";

    ls::File file{currentName};
    file.createNewFile();

    ASSERT_TRUE(file.exists());
    ASSERT_STREQ(currentName.c_str(), file.getAbsoluteFilePath().c_str());

    file.renameTo(newName);
    ASSERT_TRUE(file.exists());
    ASSERT_STREQ(newName.c_str(), file.getAbsoluteFilePath().c_str());

    file.remove();
  }

  TEST_F(FileTest, reset)
  {
    ls::File file{this->fileLocation};
    ASSERT_TRUE(file.exists());

    file.reset(TestHelper::getResourcesFolderLocation() + "list_test/hello.txt");
    ASSERT_TRUE(file.exists());
  }
}
