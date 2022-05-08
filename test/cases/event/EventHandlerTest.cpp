/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2022-05-08
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>

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
                   catch (const ls::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::IllegalArgumentException);
  }

  TEST_F(EventHandlerTest, getId)
  {
    ls::std::event::EventHandler eventHandler{"EventId"};
    ASSERT_STREQ("EventId", eventHandler.getId().c_str());
  }
}
