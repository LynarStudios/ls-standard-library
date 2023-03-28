/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2023-03-25
 *
 * */

#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>
#include <ls-std/ls-std-event.hpp>

using ls::std::core::IllegalArgumentException;
using ls::std::event::EventHandler;
using testing::Test;

namespace
{
  class EventHandlerTest : public Test
  {
    public:

      EventHandlerTest() = default;
      ~EventHandlerTest() override = default;
  };

  TEST_F(EventHandlerTest, constructor_empty_parameter)
  {
    EXPECT_THROW(
        {
          try
          {
            EventHandler eventHandler{""};
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(EventHandlerTest, getId)
  {
    EventHandler eventHandler{"EventId"};
    ASSERT_STREQ("EventId", eventHandler.getId().c_str());
  }
}
