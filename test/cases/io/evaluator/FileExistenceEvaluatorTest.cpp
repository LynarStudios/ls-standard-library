/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-21
* Changed:         2023-02-21
*
* */

#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>
#include <ls-std/ls-std-io.hpp>
#include <string>

using namespace ls::std::core;
using namespace ls::std::io;
using namespace ::std;

namespace
{
  class FileExistenceEvaluatorTest : public ::testing::TestWithParam<string>
  {
    protected:

      FileExistenceEvaluatorTest() = default;
      ~FileExistenceEvaluatorTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_P(FileExistenceEvaluatorTest, evaluate)
  {
    EXPECT_THROW(
        {
          try
          {
            FileExistenceEvaluator{GetParam()}.evaluate();
          }
          catch (const FileNotFoundException &_exception)
          {
            string actual = _exception.what();
            string expected = "FileNotFoundException thrown - \"" + GetParam() + "\" does not exist!";
            ;

            ASSERT_STREQ(expected.c_str(), actual.c_str());
            throw;
          }
        },
        FileNotFoundException);
  }

  INSTANTIATE_TEST_SUITE_P(FileExistenceEvaluatorTest, FileExistenceEvaluatorTest, ::testing::Values("var/log/log.txt", ".test"));
}
