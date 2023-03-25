/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-21
* Changed:         2023-03-25
*
* */

#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>
#include <ls-std/ls-std-io.hpp>
#include <string>

using ls::std::core::FileNotFoundException;
using ls::std::io::FileExistenceEvaluator;
using std::string;
using testing::TestWithParam;
using testing::Values;

namespace
{
  class FileExistenceEvaluatorTest : public TestWithParam<string>
  {
    public:

      FileExistenceEvaluatorTest() = default;
      ~FileExistenceEvaluatorTest() override = default;
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
            string expected = _exception.getName() + " thrown - \"" + GetParam() + "\" does not exist!";
            ;

            ASSERT_STREQ(expected.c_str(), actual.c_str());
            throw;
          }
        },
        FileNotFoundException);
  }

  INSTANTIATE_TEST_SUITE_P(FileExistenceEvaluatorTest, FileExistenceEvaluatorTest, Values("var/log/log.txt", ".test"));
}
