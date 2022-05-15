/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-19
 * Changed:         2022-05-14
 *
 * */

#include <gtest/gtest.h>
#include <ls_std_io_test.hpp>
#include <ls_std/ls_std_io.hpp>

namespace
{
  class StorableFileTest : public ::testing::Test
  {
    protected:

      StorableFileTest() = default;
      ~StorableFileTest() override = default;

      std::string fileLocation = ls_std_io_test::TestHelper::getResourcesFolderLocation() + "simple.txt";

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(StorableFileTest, getFile)
  {
    ls::std::io::StorableFile storableFile{this->fileLocation};
    ASSERT_STREQ(this->fileLocation.c_str(), storableFile.getFile()->getAbsoluteFilePath().c_str());
  }

  TEST_F(StorableFileTest, load)
  {
    ls::std::io::StorableFile storableFile{this->fileLocation};
    ls::std::core::type::byte_field content = storableFile.load();

    std::string expectedUnix = "Hello!" + ls::std::io::NewLine::getUnixNewLine();
    std::string expectedWindows = "Hello!" + ls::std::io::NewLine::getWindowsNewLine();

    ASSERT_TRUE(content == expectedUnix || content == expectedWindows);
  }

  TEST_F(StorableFileTest, reset)
  {
    ls::std::io::StorableFile storableFile{this->fileLocation};
    ls::std::core::type::byte_field content = storableFile.load();

    std::string expectedUnix = "Hello!" + ls::std::io::NewLine::getUnixNewLine();
    std::string expectedWindows = "Hello!" + ls::std::io::NewLine::getWindowsNewLine();

    ASSERT_TRUE(content == expectedUnix || content == expectedWindows);

    // reset

    std::string anotherFileLocation = ls_std_io_test::TestHelper::getResourcesFolderLocation() + "list_test/bla.txt";
    storableFile.reset(anotherFileLocation);
    content = storableFile.load();

    expectedUnix = "nothing to say!" + ls::std::io::NewLine::getUnixNewLine();
    expectedWindows = "nothing to say!" + ls::std::io::NewLine::getWindowsNewLine();

    ASSERT_TRUE(content == expectedUnix || content == expectedWindows);
  }

  TEST_F(StorableFileTest, save)
  {
    std::string path = ls_std_io_test::TestHelper::getResourcesFolderLocation() + "tmp_storable_file.txt";
    ls::std::io::File file{path};
    file.createNewFile();

    ls::std::io::StorableFile storableFile{path};
    ls::std::core::type::byte_field textUnix = "Testing save method!" + ls::std::io::NewLine::getUnixNewLine();
    ls::std::core::type::byte_field textWindows = "Testing save method!" + ls::std::io::NewLine::getWindowsNewLine();

    storableFile.save(textUnix);
    ls::std::core::type::byte_field content = storableFile.load();
    ASSERT_TRUE(content == textUnix || content == textWindows);

    file.remove();
  }
}
