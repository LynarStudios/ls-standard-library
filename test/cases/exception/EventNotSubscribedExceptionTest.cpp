/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-05-27
 * Changed:         2021-05-27
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>

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
    EXPECT_THROW({
                   try
                   {
                     throw ls_std::EventNotSubscribedException{};
                   }
                   catch (const ls_std::EventNotSubscribedException &_exception)
                   {
                     EXPECT_STREQ("EventNotSubscribedException thrown - event was not subscribed!", _exception.what());
                     throw;
                   }
                 }, ls_std::EventNotSubscribedException);
  }
}
