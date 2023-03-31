/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-03-15
* Changed:         2023-03-31
*
* */

#ifndef LS_STD_MOCK_POSIX_CLOCK_HPP
#define LS_STD_MOCK_POSIX_CLOCK_HPP

#include <gmock/gmock.h>
#include <ls-std/time/common/DateParameter.hpp>
#include <ls-std/time/system-time/IClock.hpp>

namespace test::time
{
  class MockPosixClock : public ls::std::time::IClock
  {
    public:

      MockPosixClock();
      ~MockPosixClock() noexcept override;

      MOCK_METHOD(bool, setTime, (const ls::std::time::DateParameter &_dateParameter), (override));
  };
}

#endif
