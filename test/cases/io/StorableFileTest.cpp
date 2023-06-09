/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-19
 * Changed:         2023-03-25
 *
 * */

#include <classes/TestHelper.hpp>
#include <gtest/gtest.h>
#include <ls-std/ls-std-io.hpp>

using ls::std::core::type::byte_field;
using ls::std::io::File;
using ls::std::io::NewLine;
using ls::std::io::StorableFile;
using ls::std::test::TestHelper;
using std::string;
using testing::Test;

namespace
{
  class StorableFileTest : public Test
  {
    public:

      StorableFileTest() = default;
      ~StorableFileTest() override = default;

      string fileLocation = TestHelper::getResourcesFolderLocation() + "simple.txt";
  };

  TEST_F(StorableFileTest, getFile)
  {
    StorableFile storableFile{this->fileLocation};
    ASSERT_STREQ(this->fileLocation.c_str(), storableFile.getFile()->getAbsoluteFilePath().c_str());
  }

  TEST_F(StorableFileTest, load)
  {
    StorableFile storableFile{this->fileLocation};
    byte_field content = storableFile.load();

    string expectedUnix = "Hello!" + NewLine::getUnixNewLine();
    string expectedWindows = "Hello!" + NewLine::getWindowsNewLine();

    ASSERT_TRUE(content == expectedUnix || content == expectedWindows);
  }

  TEST_F(StorableFileTest, reset)
  {
    StorableFile storableFile{this->fileLocation};
    byte_field content = storableFile.load();

    string expectedUnix = "Hello!" + NewLine::getUnixNewLine();
    string expectedWindows = "Hello!" + NewLine::getWindowsNewLine();

    ASSERT_TRUE(content == expectedUnix || content == expectedWindows);

    // reset

    string anotherFileLocation = TestHelper::getResourcesFolderLocation() + "list-test/bla.txt";
    storableFile.reset(anotherFileLocation);
    content = storableFile.load();

    expectedUnix = "nothing to say!" + NewLine::getUnixNewLine();
    expectedWindows = "nothing to say!" + NewLine::getWindowsNewLine();

    ASSERT_TRUE(content == expectedUnix || content == expectedWindows);
  }

  TEST_F(StorableFileTest, save)
  {
    string path = TestHelper::getResourcesFolderLocation() + "tmp-storable-file.txt";
    File file{path};
    file.createNewFile();

    StorableFile storableFile{path};
    byte_field textUnix = "Testing save method!" + NewLine::getUnixNewLine();
    byte_field textWindows = "Testing save method!" + NewLine::getWindowsNewLine();

    storableFile.save(textUnix);
    byte_field content = storableFile.load();
    ASSERT_TRUE(content == textUnix || content == textWindows);

    file.remove();
  }
}
