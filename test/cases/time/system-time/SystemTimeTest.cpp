/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-03-15
* Changed:         2023-03-15
*
* */

#include <cstdint>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <ls-std-time-test.hpp>
#include <ls-std/ls-std-core.hpp>
#include <ls-std/ls-std-time.hpp>
#include <memory>

using ls::std::core::IllegalArgumentException;
using ls::std::time::SystemTime;
using ls::std::time::SystemTimeParameter;
using std::make_shared;
using std::shared_ptr;
using test::time::MockPosixClock;
using testing::AtLeast;
using testing::Return;
using testing::Test;

namespace
{
  class SystemTimeTest : public Test
  {
    public:

      SystemTimeTest() = default;
      ~SystemTimeTest() override = default;
  };

  TEST_F(SystemTimeTest, constructor)
  {
    EXPECT_THROW(
        {
          try
          {
            SystemTime systemTime{nullptr};
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(SystemTimeTest, getClassName)
  {
    ASSERT_STREQ("SystemTime", SystemTime{}.getClassName().c_str());
  }

  TEST_F(SystemTimeTest, setTime)
  {
    shared_ptr<SystemTimeParameter> parameter = make_shared<SystemTimeParameter>();
    shared_ptr<MockPosixClock> posixClock = make_shared<MockPosixClock>();
    parameter->setPosixClock(posixClock);
    uint32_t birthday = 612694333;

    EXPECT_CALL(*posixClock, setTime(birthday)).Times(AtLeast(1));
    ON_CALL(*posixClock, setTime(birthday)).WillByDefault(Return(true));

    ASSERT_TRUE(SystemTime{parameter}.set(birthday));
  }
}
