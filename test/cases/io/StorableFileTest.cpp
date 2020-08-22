/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-19
 * Changed:         2020-08-22
 *
 * */

#include <gtest/gtest.h>
#include "../../TestHelper.hpp"
#include "../../../source/io/StorableFile.hpp"
#include "../../../source/io/NewLine.hpp"

namespace {
  class StorableFileTest : public ::testing::Test {
    protected:

      StorableFileTest() = default;
      ~StorableFileTest() override = default;

      std::string fileLocation = TestHelper::getResourcesFolderLocation() + "simple.txt";

      void SetUp() override {}
      void TearDown() override {}
  };

  TEST_F(StorableFileTest, getFile)
  {
    ls_std::StorableFile storableFile {this->fileLocation};
    ASSERT_STREQ(this->fileLocation.c_str(), storableFile.getFile()->getAbsoluteFilePath().c_str());
  }

  TEST_F(StorableFileTest, load)
  {
    ls_std::StorableFile storableFile {this->fileLocation};
    std::string content = {storableFile.load(), (size_t) storableFile.getFile()->getSize()};

    std::string expectedUnix = "Hello!" + ls_std::NewLine::getUnixNewLine();
    std::string expectedWindows = "Hello!" + ls_std::NewLine::getWindowsNewLine();

    ASSERT_TRUE(content == expectedUnix || content == expectedWindows);
  }

  TEST_F(StorableFileTest, reset)
  {
    ls_std::StorableFile storableFile {this->fileLocation};
    std::string content = {storableFile.load(), (size_t) storableFile.getFile()->getSize()};

    std::string expectedUnix = "Hello!" + ls_std::NewLine::getUnixNewLine();
    std::string expectedWindows = "Hello!" + ls_std::NewLine::getWindowsNewLine();

    ASSERT_TRUE(content == expectedUnix || content == expectedWindows);

    // reset

    std::string anotherFileLocation = TestHelper::getResourcesFolderLocation() + "list_test/bla.txt";
    storableFile.reset(anotherFileLocation);
    content = {storableFile.load(), (size_t) storableFile.getFile()->getSize()};

    expectedUnix = "nothing to say!" + ls_std::NewLine::getUnixNewLine();
    expectedWindows = "nothing to say!" + ls_std::NewLine::getWindowsNewLine();

    ASSERT_TRUE(content == expectedUnix || content == expectedWindows);
  }

  TEST_F(StorableFileTest, save)
  {
    std::string path = TestHelper::getResourcesFolderLocation() + "tmp_storable_file.txt";
    ls_std::File file {path};
    file.createNewFile();

    ls_std::StorableFile storableFile {path};
    std::string textUnix = "Testing save method!" + ls_std::NewLine::getUnixNewLine();
    std::string textWindows = "Testing save method!" + ls_std::NewLine::getWindowsNewLine();

    storableFile.save((char*) textUnix.c_str());
    std::string content = storableFile.load();
    ASSERT_TRUE(content == textUnix || content == textWindows);

    file.remove();
  }
}