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
using namespace ::testing;
using namespace ::std;

namespace
{
  class EventNotHandledExceptionTest : public Test
  {
    protected:

      EventNotHandledExceptionTest() = default;
      ~EventNotHandledExceptionTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(EventNotHandledExceptionTest, constructor)
  {
    EXPECT_THROW(
        {
          try
          {
            throw EventNotHandledException{};
          }
          catch (const EventNotHandledException &_exception)
          {
            string actual = _exception.what();
            string expected = _exception.getName() + " thrown - event was not handled - nothing happened!";

            EXPECT_STREQ(expected.c_str(), actual.c_str());
            throw;
          }
        },
        EventNotHandledException);
  }

  TEST_F(EventNotHandledExceptionTest, constructor_dedicated_message)
  {
    EXPECT_THROW(
        {
          try
          {
            throw EventNotHandledException{"id: OPEN_DOOR"};
          }
          catch (const EventNotHandledException &_exception)
          {
            string actual = _exception.what();
            string expected = _exception.getName() + " thrown - id: OPEN_DOOR";

            EXPECT_STREQ(expected.c_str(), actual.c_str());
            throw;
          }
        },
        EventNotHandledException);
  }

  TEST_F(EventNotHandledExceptionTest, getName)
  {
    ASSERT_STREQ("EventNotHandledException", EventNotHandledException{}.getName().c_str());
  }
}
