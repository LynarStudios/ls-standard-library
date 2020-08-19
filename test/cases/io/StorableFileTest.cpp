/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-19
 * Changed:         2020-08-19
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

  TEST_F(StorableFileTest, getContent)
  {
    ls_std::StorableFile storableFile {this->fileLocation};
    ASSERT_TRUE(storableFile.getContent().empty());
  }

  TEST_F(StorableFileTest, load)
  {
    ls_std::StorableFile storableFile {this->fileLocation};
    storableFile.load();
    std::string expectedUnix = "Hello!" + ls_std::NewLine::getUnixNewLine();
    std::string expectedWindows = "Hello!" + ls_std::NewLine::getWindowsNewLine();

    ASSERT_TRUE(storableFile.getContent() == expectedUnix || storableFile.getContent() == expectedWindows);
  }

  TEST_F(StorableFileTest, reset)
  {
    ls_std::StorableFile storableFile {this->fileLocation};
    storableFile.load();
    std::string expectedUnix = "Hello!" + ls_std::NewLine::getUnixNewLine();
    std::string expectedWindows = "Hello!" + ls_std::NewLine::getWindowsNewLine();

    ASSERT_TRUE(storableFile.getContent() == expectedUnix || storableFile.getContent() == expectedWindows);

    // reset

    std::string anotherFileLocation = TestHelper::getResourcesFolderLocation() + "list_test/bla.txt";
    storableFile.reset(anotherFileLocation);
    storableFile.load();
    expectedUnix = "nothing to say!" + ls_std::NewLine::getUnixNewLine();
    expectedWindows = "nothing to say!" + ls_std::NewLine::getWindowsNewLine();

    ASSERT_TRUE(storableFile.getContent() == expectedUnix || storableFile.getContent() == expectedWindows);
  }

  TEST_F(StorableFileTest, save)
  {
    std::string path = TestHelper::getResourcesFolderLocation() + "tmp_storable_file.txt";
    ls_std::File file {path};
    file.createNewFile();

    ls_std::StorableFile storableFile {path};
    std::string textUnix = "Testing save method!" + ls_std::NewLine::getUnixNewLine();
    std::string textWindows = "Testing save method!" + ls_std::NewLine::getWindowsNewLine();

    ASSERT_TRUE(storableFile.getContent().empty());
    storableFile.setContent(textUnix);
    ASSERT_TRUE(storableFile.getContent() == textUnix || storableFile.getContent() == textWindows);
    storableFile.save();
    storableFile.load();
    ASSERT_TRUE(storableFile.getContent() == textUnix || storableFile.getContent() == textWindows);

    file.remove();
  }

  TEST_F(StorableFileTest, setContent)
  {
    ls_std::StorableFile storableFile {this->fileLocation};
    storableFile.setContent("Testing!");

    ASSERT_STREQ("Testing!", storableFile.getContent().c_str());
  }
}