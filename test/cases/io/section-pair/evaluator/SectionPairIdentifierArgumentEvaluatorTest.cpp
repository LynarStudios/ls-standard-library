/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-09
* Changed:         2023-02-17
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
  class SectionPairIdentifierArgumentEvaluatorTest : public ::testing::Test
  {
    protected:

      SectionPairIdentifierArgumentEvaluatorTest() = default;
      ~SectionPairIdentifierArgumentEvaluatorTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(SectionPairIdentifierArgumentEvaluatorTest, getClassName)
  {
    shared_ptr<SectionPairIdentifierArgumentEvaluator> evaluator = make_shared<SectionPairIdentifierArgumentEvaluator>("_id", "not valid!");
    ASSERT_STREQ("SectionPairIdentifierArgumentEvaluator", evaluator->getClassName().c_str());
  }

  TEST_F(SectionPairIdentifierArgumentEvaluatorTest, evaluate)
  {
    EXPECT_THROW(
        {
          try
          {
            SectionPairIdentifierArgumentEvaluator("_color", "section pair identifier contains invalid characters!").evaluate();
          }
          catch (const IllegalArgumentException &_exception)
          {
            ::std::string message = _exception.what();
            ASSERT_STREQ("IllegalArgumentException thrown - section pair identifier contains invalid characters!", message.c_str());
            throw;
          }
        },
        IllegalArgumentException);
  }
}
