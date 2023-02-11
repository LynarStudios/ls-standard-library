/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-10
* Changed:         2023-02-11
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
  class SectionPairRowValueArgumentEvaluatorTest : public ::testing::Test
  {
    protected:

      SectionPairRowValueArgumentEvaluatorTest() = default;
      ~SectionPairRowValueArgumentEvaluatorTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(SectionPairRowValueArgumentEvaluatorTest, evaluate)
  {
    EXPECT_THROW(
        {
          try
          {
            SectionPairRowValueArgumentEvaluator("=33", "section pair value contains invalid characters!").evaluate();
          }
          catch (const IllegalArgumentException &_exception)
          {
            ::std::string message = _exception.what();
            ASSERT_STREQ("IllegalArgumentException thrown - section pair value contains invalid characters!", message.c_str());
            throw;
          }
        },
        IllegalArgumentException);
  }
}
