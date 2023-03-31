/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-03-15
* Changed:         2023-03-31
*
* */

#include <gtest/gtest.h>
#include <ls-std/ls-std-time.hpp>
#include <memory>

using ls::std::time::IClock;
using ls::std::time::PosixClock;
using ls::std::time::SystemTimeParameter;
using std::make_shared;
using std::shared_ptr;
using testing::Test;

namespace
{
  class SystemTimeParameterTest : public Test
  {
    public:

      SystemTimeParameterTest() = default;
      ~SystemTimeParameterTest() override = default;
  };

  TEST_F(SystemTimeParameterTest, getClock)
  {
    ASSERT_TRUE(SystemTimeParameter{}.getClock() == nullptr);
  }

  TEST_F(SystemTimeParameterTest, setClock)
  {
    SystemTimeParameter parameter{};
    shared_ptr<IClock> posixClock = make_shared<PosixClock>();
    parameter.setClock(posixClock);

    ASSERT_TRUE(parameter.getClock() == posixClock);
  }
}
