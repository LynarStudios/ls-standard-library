/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-05-27
 * Changed:         2023-02-22
 *
 * */

#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>
#include <string>

using namespace ls::std::core;

namespace
{
  class EventNotSubscribedExceptionTest : public ::testing::Test
  {
    protected:

      EventNotSubscribedExceptionTest() = default;
      ~EventNotSubscribedExceptionTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(EventNotSubscribedExceptionTest, constructor)
  {
    EXPECT_THROW(
        {
          try
          {
            throw EventNotSubscribedException{};
          }
          catch (const EventNotSubscribedException &_exception)
          {
            ::std::string actual = _exception.what();
            ::std::string expected = _exception.getName() + " thrown - event was not subscribed!";

            EXPECT_STREQ(expected.c_str(), actual.c_str());
            throw;
          }
        },
        EventNotSubscribedException);
  }

  TEST_F(EventNotSubscribedExceptionTest, constructor_dedicated_message)
  {
    EXPECT_THROW(
        {
          try
          {
            throw EventNotSubscribedException{"id: OPEN_DOOR"};
          }
          catch (const EventNotSubscribedException &_exception)
          {
            ::std::string actual = _exception.what();
            ::std::string expected = _exception.getName() + " thrown - id: OPEN_DOOR";

            EXPECT_STREQ(expected.c_str(), actual.c_str());
            throw;
          }
        },
        EventNotSubscribedException);
  }

  TEST_F(EventNotSubscribedExceptionTest, getName)
  {
    ASSERT_STREQ("EventNotSubscribedException", EventNotSubscribedException{}.getName().c_str());
  }
}
