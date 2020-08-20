/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-20
 * Changed:         2020-08-20
 *
 * */

#include <gtest/gtest.h>
#include "../../../source/io/File.hpp"
#include "../../TestHelper.hpp"
#include "../../../source/io/FileOutputStream.hpp"

namespace {
  class FileOutputStreamTest : public ::testing::Test {
    protected:

      FileOutputStreamTest() = default;
      ~FileOutputStreamTest() override = default;

      void SetUp() override {}
      void TearDown() override {}
  };

  TEST_F(FileOutputStreamTest, write)
  {
    std::string path = TestHelper::getResourcesFolderLocation() + "tmp_output_stream.txt";
    ls_std::File file {path};
    file.createNewFile();
    ASSERT_TRUE(file.exists());

    ls_std::FileOutputStream outputStream {file};
    ASSERT_TRUE(outputStream.write("Hello! "));
    ASSERT_TRUE(outputStream.write("How are you?"));
    outputStream.close();

    file.remove();
    ASSERT_FALSE(file.exists());
  }
}
