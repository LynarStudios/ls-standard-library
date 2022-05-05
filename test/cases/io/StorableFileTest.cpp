/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-19
 * Changed:         2022-05-05
 *
 * */

#include <gtest/gtest.h>
#include <TestHelper.hpp>
#include <ls_std/ls_std.hpp>

namespace
{
  class StorableFileTest : public ::testing::Test
  {
    protected:

      StorableFileTest() = default;
      ~StorableFileTest() override = default;

      std::string fileLocation = TestHelper::getResourcesFolderLocation() + "simple.txt";

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(StorableFileTest, getFile)
  {
    ls::StorableFile storableFile{this->fileLocation};
    ASSERT_STREQ(this->fileLocation.c_str(), storableFile.getFile()->getAbsoluteFilePath().c_str());
  }

  TEST_F(StorableFileTest, load)
  {
    ls::StorableFile storableFile{this->fileLocation};
    ls::byte_field content = storableFile.load();

    std::string expectedUnix = "Hello!" + ls::NewLine::getUnixNewLine();
    std::string expectedWindows = "Hello!" + ls::NewLine::getWindowsNewLine();

    ASSERT_TRUE(content == expectedUnix || content == expectedWindows);
  }

  TEST_F(StorableFileTest, reset)
  {
    ls::StorableFile storableFile{this->fileLocation};
    ls::byte_field content = storableFile.load();

    std::string expectedUnix = "Hello!" + ls::NewLine::getUnixNewLine();
    std::string expectedWindows = "Hello!" + ls::NewLine::getWindowsNewLine();

    ASSERT_TRUE(content == expectedUnix || content == expectedWindows);

    // reset

    std::string anotherFileLocation = TestHelper::getResourcesFolderLocation() + "list_test/bla.txt";
    storableFile.reset(anotherFileLocation);
    content = storableFile.load();

    expectedUnix = "nothing to say!" + ls::NewLine::getUnixNewLine();
    expectedWindows = "nothing to say!" + ls::NewLine::getWindowsNewLine();

    ASSERT_TRUE(content == expectedUnix || content == expectedWindows);
  }

  TEST_F(StorableFileTest, save)
  {
    std::string path = TestHelper::getResourcesFolderLocation() + "tmp_storable_file.txt";
    ls::File file{path};
    file.createNewFile();

    ls::StorableFile storableFile{path};
    ls::byte_field textUnix = "Testing save method!" + ls::NewLine::getUnixNewLine();
    ls::byte_field textWindows = "Testing save method!" + ls::NewLine::getWindowsNewLine();

    storableFile.save(textUnix);
    ls::byte_field content = storableFile.load();
    ASSERT_TRUE(content == textUnix || content == textWindows);

    file.remove();
  }
}
