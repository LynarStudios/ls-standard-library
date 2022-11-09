/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-05-27
 * Changed:         2022-11-09
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std_core.hpp>

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
    EXPECT_THROW({
                   try
                   {
                     throw EventNotHandledException{};
                   }
                   catch (const EventNotHandledException &_exception)
                   {
                     EXPECT_STREQ("EventNotHandledException thrown - event was not handled - nothing happened!", _exception.what());
                     throw;
                   }
                 }, EventNotHandledException);
  }
}
