/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-03-15
* Changed:         2023-03-15
*
* */

#ifndef LS_STD_MOCK_POSIX_CLOCK_HPP
#define LS_STD_MOCK_POSIX_CLOCK_HPP

#include <gmock/gmock.h>
#include <ls-std/time/system-time/IPosixClock.hpp>

namespace test::time
{
  class MockPosixClock : public ls::std::time::IPosixClock
  {
    public:

      MockPosixClock();
      ~MockPosixClock() noexcept override;

      MOCK_METHOD(bool, setTime, (uint32_t _timeStamp), (override));
  };
}

#endif
