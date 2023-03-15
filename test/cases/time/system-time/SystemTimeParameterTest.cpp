/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-03-15
* Changed:         2023-03-15
*
* */

#include <gtest/gtest.h>
#include <ls-std/ls-std-time.hpp>
#include <memory>

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

  TEST_F(SystemTimeParameterTest, getPosixClock)
  {
    ASSERT_TRUE(SystemTimeParameter{}.getPosixClock() == nullptr);
  }

  TEST_F(SystemTimeParameterTest, setPosixClock)
  {
    SystemTimeParameter parameter{};
    shared_ptr<PosixClock> posixClock = make_shared<PosixClock>();
    parameter.setPosixClock(posixClock);

    ASSERT_TRUE(parameter.getPosixClock() == posixClock);
  }
}
