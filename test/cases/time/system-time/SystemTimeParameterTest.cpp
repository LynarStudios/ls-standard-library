/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-03-15
* Changed:         2023-04-01
*
* */

#include <gtest/gtest.h>
#include <ls-std/ls-std-time.hpp>
#include <memory>

using ls::std::time::IClock;
#if defined(unix) || defined(__APPLE__)
using ls::std::time::PosixClock;
#endif
using ls::std::time::SystemTimeParameter;
#ifdef _WIN32
using ls::std::time::WindowsClock;
#endif
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
    shared_ptr<IClock> clock{};

#if defined(unix) || defined(__APPLE__)
    clock = make_shared<PosixClock>();
#endif
#ifdef _WIN32
    clock = make_shared<WindowsClock>();
#endif

    parameter.setClock(clock);

    ASSERT_TRUE(parameter.getClock() == clock);
  }
}
