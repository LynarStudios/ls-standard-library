/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-18
 * Changed:         2020-08-19
 *
 * */

#include <gtest/gtest.h>
#include "../../../source/io/FileReader.hpp"
#include "../../TestHelper.hpp"
#include "../../../source/io/NewLine.hpp"

namespace {
  class FileReaderTest : public ::testing::Test {
    protected:

      FileReaderTest() = default;
      ~FileReaderTest() override = default;

      void SetUp() override {}
      void TearDown() override {}
  };

  TEST_F(FileReaderTest, read)
  {
    ls_std::File file {TestHelper::getResourcesFolderLocation() + "simple.txt"};
    ls_std::FileReader reader {file};
    std::string expected = "Hello!" + ls_std::NewLine::get();

    ls_std::byte* data = reader.read();
    std::string content {data, (size_t) file.getSize()};
    ASSERT_STREQ(expected.c_str(), content.c_str());
  }

  TEST_F(FileReaderTest, reset)
  {
    ls_std::File file {TestHelper::getResourcesFolderLocation() + "simple.txt"};
    ls_std::FileReader reader {file};
    std::string expected = "Hello!" + ls_std::NewLine::get();

    ls_std::byte* data = reader.read();
    std::string content {data, (size_t) file.getSize()};
    ASSERT_STREQ(expected.c_str(), content.c_str());

    ls_std::File anotherFile {TestHelper::getResourcesFolderLocation() + "list_test/bla.txt"};
    reader.reset(anotherFile);
    expected = "nothing to say!" + ls_std::NewLine::get();

    data = reader.read();
    content = {data, (size_t) anotherFile.getSize()};
    ASSERT_STREQ(expected.c_str(), content.c_str());
  }
}
