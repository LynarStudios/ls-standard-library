/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-05-27
 * Changed:         2023-02-07
 *
 * */

#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>
#include <string>

using namespace ls::std::core;

namespace
{
  class EventNotHandledExceptionTest : public ::testing::Test
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
            ::std::string message = _exception.what();
            EXPECT_STREQ("EventNotHandledException thrown - event was not handled - nothing happened!", message.c_str());
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
            ::std::string message = _exception.what();
            EXPECT_STREQ("EventNotHandledException thrown - id: OPEN_DOOR", message.c_str());
            throw;
          }
        },
        EventNotHandledException);
  }
}
