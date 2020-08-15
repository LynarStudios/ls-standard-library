/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-15
 * Changed:         2020-08-15
 *
 * */

#include <gtest/gtest.h>
#include "../../../source/io/File.hpp"
#include "../../TestHelper.hpp"

namespace {
  class FileTest : public ::testing::Test {
    protected:

      FileTest() = default;
      ~FileTest() override = default;

      std::string fileLocation = TestHelper::getResourcesFolderLocation() + "simple.txt";

      void SetUp() override {}
      void TearDown() override {}
  };

  // comparison operators

  TEST_F(FileTest, operatorEqual)
  {
    ls_std::File file {this->fileLocation};
    ls_std::File file2 {this->fileLocation};
    ls_std::File file3 {"/home/bla/text.txt"};
    ls_std::File file4 {"\\home/bla\\text.txt"};

    ASSERT_TRUE(file == file2);
    ASSERT_TRUE(file2 == file);
    ASSERT_TRUE(file3 == file4);
    ASSERT_TRUE(file4 == file3);
  }

  TEST_F(FileTest, operatorNotEqual)
  {
    ls_std::File file {this->fileLocation};
    ls_std::File file2 {TestHelper::getResourcesFolderLocation() + "app.exe"};

    ASSERT_TRUE(file != file2);
    ASSERT_TRUE(file2 != file);
  }

  // additional functionality

  TEST_F(FileTest, canExecute)
  {
    ls_std::File executableFile {TestHelper::getResourcesFolderLocation() + "app.exe"};
    ASSERT_TRUE(executableFile.canExecute());
  }

  TEST_F(FileTest, canExecuteNegative)
  {
    ls_std::File file {this->fileLocation};
    ASSERT_FALSE(file.canExecute());
  }

  TEST_F(FileTest, createAndRemove)
  {
    ls_std::File file {TestHelper::getResourcesFolderLocation() + "tmp.txt"};
    ASSERT_FALSE(file.exists());

    file.create();
    ASSERT_TRUE(file.exists());

    file.remove();
    ASSERT_FALSE(file.exists());
  }

  TEST_F(FileTest, exists)
  {
    ls_std::File file {this->fileLocation};
    ls_std::File directory {TestHelper::getResourcesFolderLocation()};

    ASSERT_TRUE(file.exists());
    ASSERT_TRUE(directory.exists());
  }

  TEST_F(FileTest, existsNegative)
  {
    ls_std::File file {TestHelper::getResourcesFolderLocation() + "bla.txt"};
    ASSERT_FALSE(file.exists());
  }

  TEST_F(FileTest, getAbsoluteFilePath)
  {
    ls_std::File file {this->fileLocation};
    ASSERT_STREQ(fileLocation.c_str(), file.getAbsoluteFilePath().c_str());
  }

  TEST_F(FileTest, getName)
  {
    ls_std::File file {this->fileLocation};
    ls_std::File executableFile {TestHelper::getResourcesFolderLocation() + "app.exe"};
    ls_std::File anotherFile {"bla.txt"};
    ls_std::File directory {TestHelper::getResourcesFolderLocation()};

    ASSERT_STREQ("simple.txt", file.getName().c_str());
    ASSERT_STREQ("app.exe", executableFile.getName().c_str());
    ASSERT_STREQ("bla.txt", anotherFile.getName().c_str());
    ASSERT_STREQ("resources", directory.getName().c_str());
  }

  TEST_F(FileTest, getSize)
  {
    ls_std::File file {this->fileLocation};
    ASSERT_EQ(8, file.getSize());
  }

  TEST_F(FileTest, isDirectory)
  {
    ls_std::File directory {TestHelper::getResourcesFolderLocation()};
    ASSERT_TRUE(directory.isDirectory());
  }

  TEST_F(FileTest, isDirectoryNegative)
  {
    ls_std::File file {this->fileLocation};
    ASSERT_FALSE(file.isDirectory());
  }

  TEST_F(FileTest, isFile)
  {
    ls_std::File file {this->fileLocation};
    ASSERT_TRUE(file.isFile());
  }

  TEST_F(FileTest, isFileNegative)
  {
    ls_std::File directory {TestHelper::getResourcesFolderLocation()};
    ASSERT_FALSE(directory.isFile());
  }

  TEST_F(FileTest, makeDirectory)
  {
    ls_std::File directory {TestHelper::getResourcesFolderLocation() + "testDir"};
    ASSERT_FALSE(directory.exists());

    directory.makeDirectory();
    ASSERT_TRUE(directory.exists());

    directory.remove();
    ASSERT_FALSE(directory.exists());
  }
}
