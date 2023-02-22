/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-13
* Changed:         2023-02-22
*
* */

#include <gtest/gtest.h>
#include <ls-std-core-test.hpp>
#include <ls-std/ls-std-core.hpp>

using ls::std::core::ConditionalFunctionExecutor;
using std::make_shared;
using std::shared_ptr;
using test::core::MathOddValidator;
using testing::Test;

namespace
{
  class ConditionalFunctionExecutorTest : public Test
  {
    protected:

      ConditionalFunctionExecutorTest() = default;
      ~ConditionalFunctionExecutorTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(ConditionalFunctionExecutorTest, execute)
  {
    shared_ptr<MathOddValidator> validator = make_shared<MathOddValidator>();
    int inputNumber = 3;
    ConditionalFunctionExecutor{true}.execute([validator, inputNumber] { validator->validate(inputNumber); });

    ASSERT_TRUE(validator->isOdd());
  }

  TEST_F(ConditionalFunctionExecutorTest, execute_no_execution)
  {
    shared_ptr<MathOddValidator> validator = make_shared<MathOddValidator>();
    int inputNumber = 3;
    ConditionalFunctionExecutor{false}.execute([validator, inputNumber] { validator->validate(inputNumber); });

    ASSERT_FALSE(validator->isOdd());
  }
}
