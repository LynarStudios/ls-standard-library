/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2021-05-27
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>
#include <ls_std_test.hpp>

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
                     ls_std::EventHandler eventHandler{""};
                   }
                   catch (const ls_std::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls_std::IllegalArgumentException);
  }

  TEST_F(EventHandlerTest, getId)
  {
    ls_std::EventHandler eventHandler{"EventId"};
    ASSERT_STREQ("EventId", eventHandler.getId().c_str());
  }
}
