/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2020-08-17
 *
 * */

#include <gtest/gtest.h>
#include "../../../source/io/File.hpp"
#include "../../../source/io/FileWriter.hpp"
#include "../../TestHelper.hpp"

namespace {
  class FileWriterTest : public ::testing::Test {
    protected:

      FileWriterTest() = default;
      ~FileWriterTest() override = default;

      void SetUp() override {}
      void TearDown() override {}
  };

  TEST_F(FileWriterTest, write)
  {
    std::string path = TestHelper::getResourcesFolderLocation() + "tmp_file_writer_test.txt";
    ls_std::File file {path};

    ASSERT_FALSE(file.exists());
    file.createNewFile();
    ASSERT_TRUE(file.exists());

    ls_std::FileWriter writer {file};
    ASSERT_TRUE(writer.write("Testing something!\n"));

    file.remove();
    ASSERT_FALSE(file.exists());
  }
}
