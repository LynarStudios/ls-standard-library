/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-15
 * Changed:         2023-02-23
 *
 * */

#include <classes/TestHelper.hpp>
#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>
#include <ls-std/ls-std-io.hpp>

using ls::std::core::FileOperationException;
using ls::std::io::File;
using ls::std::io::FilePathSeparator;
using ls::std::test::TestHelper;
using std::list;
using std::string;
using testing::Test;

namespace
{
  class FileTest : public Test
  {
    protected:

      FileTest() = default;
      ~FileTest() override = default;

      string fileLocation = TestHelper::getResourcesFolderLocation() + "simple.txt";

      void SetUp() override
      {}

      void TearDown() override
      {}

      static bool hasFileInDirectory(const list<string> &_fileNamesInDirectory, const string &_fileName)
      {
        return find(_fileNamesInDirectory.begin(), _fileNamesInDirectory.end(), _fileName) != _fileNamesInDirectory.end();
      }
  };

  // comparison operators

  TEST_F(FileTest, operator_equals)
  {
    File file{this->fileLocation};
    File file2{this->fileLocation};
    File file3{"/home/bla/text.txt"};
    File file4{"\\home/bla\\text.txt"};

    ASSERT_TRUE(file == file2);
    ASSERT_TRUE(file2 == file);
    ASSERT_TRUE(file3 == file4);
    ASSERT_TRUE(file4 == file3);
  }

  TEST_F(FileTest, operator_not_equals)
  {
    File file{this->fileLocation};
    File file2{TestHelper::getResourcesFolderLocation() + "app.exe"};

    ASSERT_TRUE(file != file2);
    ASSERT_TRUE(file2 != file);
  }

  // additional functionality

  TEST_F(FileTest, canExecute)
  {
#ifdef _WIN32
    File executableFile{TestHelper::getResourcesFolderLocation() + "app.exe"};
#endif
#if defined(unix) || defined(__APPLE__)
    File executableFile{TestHelper::getResourcesFolderLocation() + "app"};
#endif

    ASSERT_TRUE(executableFile.canExecute());
  }

  TEST_F(FileTest, canExecute_not_executable)
  {
    File file{this->fileLocation};
    ASSERT_FALSE(file.canExecute());
  }

  TEST_F(FileTest, canRead)
  {
    File readableFile{this->fileLocation};
    ASSERT_TRUE(readableFile.canRead());
  }

  TEST_F(FileTest, canRead_file_does_not_exist)
  {
    File file{""};

    EXPECT_THROW(
        {
          try
          {
            bool isReadable = file.canRead();
          }
          catch (const FileOperationException &_exception)
          {
            throw;
          }
        },
        FileOperationException);
  }

  TEST_F(FileTest, canWrite)
  {
    File readableFile{this->fileLocation};
    ASSERT_TRUE(readableFile.canWrite());
  }

  TEST_F(FileTest, canWrite_not_writable)
  {
#if defined(unix) || defined(__APPLE__)
    File noWritableFile{TestHelper::getResourcesFolderLocation() + "no-writable.txt"};
    ASSERT_FALSE(noWritableFile.canWrite());
#endif
#ifdef _WIN32
    File noWritableFile{TestHelper::getResourcesFolderLocation() + "no-writable-windows.txt"};
    ASSERT_FALSE(noWritableFile.canWrite());
#endif
  }

  TEST_F(FileTest, createNewFile)
  {
    File file{TestHelper::getResourcesFolderLocation() + "tmp.txt"};
    ASSERT_FALSE(file.exists());

    file.createNewFile();
    ASSERT_TRUE(file.exists());

    file.remove();
    ASSERT_FALSE(file.exists());
  }

  TEST_F(FileTest, createNewFile_file_does_already_exist)
  {
    File file{TestHelper::getResourcesFolderLocation() + "simple.txt"};

    EXPECT_THROW(
        {
          try
          {
            file.createNewFile();
          }
          catch (const FileOperationException &_exception)
          {
            throw;
          }
        },
        FileOperationException);
  }

  TEST_F(FileTest, exists)
  {
    File file{this->fileLocation};
    File directory{TestHelper::getResourcesFolderLocation()};

    ASSERT_TRUE(file.exists());
    ASSERT_TRUE(directory.exists());
  }

  TEST_F(FileTest, exists_does_not_exist)
  {
    File file{TestHelper::getResourcesFolderLocation() + "bla.txt"};
    ASSERT_FALSE(file.exists());
  }

  TEST_F(FileTest, getAbsoluteFilePath)
  {
    File file{this->fileLocation};
    ASSERT_STREQ(this->fileLocation.c_str(), file.getAbsoluteFilePath().c_str());
    string s = {FilePathSeparator::get()};

    string wrongFilePath = "home" + s + s + s + "user" + s + "bla" + s + s + "sub_folder";
    string expectedFilePath = "home" + s + "user" + s + "bla" + s + "sub_folder";
    File anotherFile{wrongFilePath};
    ASSERT_STREQ(expectedFilePath.c_str(), anotherFile.getAbsoluteFilePath().c_str());
  }

  TEST_F(FileTest, getName)
  {
    File file{this->fileLocation};
    File executableFile{TestHelper::getResourcesFolderLocation() + "app.exe"};
    File anotherFile{"bla.txt"};
    File directory{TestHelper::getResourcesFolderLocation()};

    ASSERT_STREQ("simple.txt", file.getName().c_str());
    ASSERT_STREQ("app.exe", executableFile.getName().c_str());
    ASSERT_STREQ("bla.txt", anotherFile.getName().c_str());
    ASSERT_STREQ("resources", directory.getName().c_str());
  }

  TEST_F(FileTest, getParent)
  {
    File file{this->fileLocation};
    ASSERT_STREQ(TestHelper::getResourcesFolderLocation().c_str(), file.getParent().c_str());
  }

  TEST_F(FileTest, getWorkingDirectory)
  {
    string workingDirectory = File::getWorkingDirectory();
    ASSERT_FALSE(workingDirectory.empty());
  }

  TEST_F(FileTest, getSize)
  {
    File file{this->fileLocation};
    size_t size = file.getSize();

    ASSERT_TRUE(size == 7 || size == 8); // different OS specific new lines
  }

  TEST_F(FileTest, isDirectory)
  {
    File directory{TestHelper::getResourcesFolderLocation()};
    ASSERT_TRUE(directory.isDirectory());
  }

  TEST_F(FileTest, isDirectory_is_a_file)
  {
    File file{this->fileLocation};
    ASSERT_FALSE(file.isDirectory());
  }

  TEST_F(FileTest, isFile)
  {
    const char separator = FilePathSeparator::get();

    File file{this->fileLocation};
    ASSERT_TRUE(file.isFile());

    File file2{TestHelper::getResourcesFolderLocation() + "list-test" + separator + "bla.txt"};
    ASSERT_TRUE(file2.isFile());
  }

  TEST_F(FileTest, isFile_is_a_directory)
  {
    File directory{TestHelper::getResourcesFolderLocation()};
    ASSERT_FALSE(directory.isFile());
  }

  TEST_F(FileTest, lastModified)
  {
    File file{this->fileLocation};
    ASSERT_TRUE(file.lastModified() > 1590000000);
  }

  TEST_F(FileTest, list)
  {
    File file{TestHelper::getResourcesFolderLocation() + "list-test"};
    list<string> filesInDirectory = file.list();
    string expectedFile{};
    const char separator = FilePathSeparator::get();

    auto filesIterator = filesInDirectory.begin();

    ASSERT_FALSE(filesInDirectory.empty());
    ASSERT_EQ(7, filesInDirectory.size());

    expectedFile = file.getAbsoluteFilePath() + separator + ".";
    ASSERT_TRUE(FileTest::hasFileInDirectory(filesInDirectory, expectedFile));
    expectedFile = file.getAbsoluteFilePath() + separator + "..";
    ASSERT_TRUE(FileTest::hasFileInDirectory(filesInDirectory, expectedFile));
    expectedFile = file.getAbsoluteFilePath() + separator + "another-file.txt";
    ASSERT_TRUE(FileTest::hasFileInDirectory(filesInDirectory, expectedFile));
    expectedFile = file.getAbsoluteFilePath() + separator + "bla.txt";
    ASSERT_TRUE(FileTest::hasFileInDirectory(filesInDirectory, expectedFile));
    expectedFile = file.getAbsoluteFilePath() + separator + "hello.txt";
    ASSERT_TRUE(FileTest::hasFileInDirectory(filesInDirectory, expectedFile));
    expectedFile = file.getAbsoluteFilePath() + separator + "list-test-sub";
    ASSERT_TRUE(FileTest::hasFileInDirectory(filesInDirectory, expectedFile));
    expectedFile = file.getAbsoluteFilePath() + separator + ".hidden-file.txt";
    ASSERT_TRUE(FileTest::hasFileInDirectory(filesInDirectory, expectedFile));
  }

  TEST_F(FileTest, listFiles)
  {
    File file{TestHelper::getResourcesFolderLocation() + "list-test"};
    list<string> filesInDirectory = file.listFiles();
    string expectedFile{};
    const char separator = FilePathSeparator::get();

    ASSERT_FALSE(filesInDirectory.empty());
    ASSERT_EQ(4, filesInDirectory.size());

    expectedFile = file.getAbsoluteFilePath() + separator + "another-file.txt";
    ASSERT_TRUE(FileTest::hasFileInDirectory(filesInDirectory, expectedFile));
    expectedFile = file.getAbsoluteFilePath() + separator + "bla.txt";
    ASSERT_TRUE(FileTest::hasFileInDirectory(filesInDirectory, expectedFile));
    expectedFile = file.getAbsoluteFilePath() + separator + "hello.txt";
    ASSERT_TRUE(FileTest::hasFileInDirectory(filesInDirectory, expectedFile));
    expectedFile = file.getAbsoluteFilePath() + separator + ".hidden-file.txt";
    ASSERT_TRUE(FileTest::hasFileInDirectory(filesInDirectory, expectedFile));
  }

  TEST_F(FileTest, makeDirectory)
  {
    File directory{TestHelper::getResourcesFolderLocation() + "testDir"};
    ASSERT_FALSE(directory.exists());

    directory.makeDirectory();
    ASSERT_TRUE(directory.exists());

    directory.remove();
    ASSERT_FALSE(directory.exists());
  }

  TEST_F(FileTest, makeDirectory_directory_already_exists)
  {
    File directory{TestHelper::getResourcesFolderLocation() + "list-test"};

    EXPECT_THROW(
        {
          try
          {
            directory.makeDirectory();
          }
          catch (const FileOperationException &_exception)
          {
            throw;
          }
        },
        FileOperationException);
  }

  TEST_F(FileTest, makeDirectories)
  {
    File directory{TestHelper::getResourcesFolderLocation() + "testDir/sub/tmp/bla"};
    ASSERT_FALSE(directory.exists());

    directory.makeDirectories();
    ASSERT_TRUE(directory.exists());

    // clean up

    directory.remove();
    directory = File(TestHelper::getResourcesFolderLocation() + "testDir/sub/tmp");
    directory.remove();
    directory = File(TestHelper::getResourcesFolderLocation() + "testDir/sub");
    directory.remove();
    directory = File(TestHelper::getResourcesFolderLocation() + "testDir");
    directory.remove();
  }

  TEST_F(FileTest, remove)
  {
    string fileName = TestHelper::getResourcesFolderLocation() + "removable-file.txt";
    File file{fileName};
    file.createNewFile();

    ASSERT_TRUE(file.exists());

    file.remove();
    ASSERT_FALSE(file.exists());
  }

  TEST_F(FileTest, renameTo)
  {
    string currentName = TestHelper::getResourcesFolderLocation() + "tmp-rename-to.txt";
    string newName = TestHelper::getResourcesFolderLocation() + "tmp-rename-to-better-name.txt";

    File file{currentName};
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
    File file{this->fileLocation};
    ASSERT_TRUE(file.exists());

    file.reset(TestHelper::getResourcesFolderLocation() + "list-test/hello.txt");
    ASSERT_TRUE(file.exists());
  }
}
