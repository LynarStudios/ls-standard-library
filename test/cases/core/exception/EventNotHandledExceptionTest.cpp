/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-05-27
 * Changed:         2022-05-13
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std_core.hpp>

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
                     throw ls::std::core::EventNotHandledException{};
                   }
                   catch (const ls::std::core::EventNotHandledException &_exception)
                   {
                     EXPECT_STREQ("EventNotHandledException thrown - event was not handled - nothing happened!", _exception.what());
                     throw;
                   }
                 }, ls::std::core::EventNotHandledException);
  }
}
