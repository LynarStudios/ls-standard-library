/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2022-05-14
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std_core.hpp>
#include <ls_std/ls_std_event.hpp>

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
    EXPECT_THROW({
                   try
                   {
                     ls::std::event::EventHandler eventHandler{""};
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }

  TEST_F(EventHandlerTest, getId)
  {
    ls::std::event::EventHandler eventHandler{"EventId"};
    ASSERT_STREQ("EventId", eventHandler.getId().c_str());
  }
}
