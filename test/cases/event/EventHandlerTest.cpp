/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2023-02-04
 *
 * */

#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>
#include <ls-std/ls-std-event.hpp>

using namespace ls::std::core;
using namespace ls::std::event;

namespace
{
  class EventHandlerTest : public ::testing::Test
  {
    protected:

      EventHandlerTest() = default;
      ~EventHandlerTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
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
