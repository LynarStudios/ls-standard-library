/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-05-01
 * Changed:         2023-02-07
 *
 * */

#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>
#include <string>

using namespace ls::std::core;

namespace
{
  class IncompleteJsonExceptionTest : public ::testing::Test
  {
    protected:

      IncompleteJsonExceptionTest() = default;
      ~IncompleteJsonExceptionTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(IncompleteJsonExceptionTest, constructor)
  {
    EXPECT_THROW(
        {
          try
          {
            throw IncompleteJsonException{};
          }
          catch (const IncompleteJsonException &_exception)
          {
            ::std::string message = _exception.what();
            EXPECT_STREQ("IncompleteJsonException thrown - this JSON string is incomplete.", message.c_str());
            throw;
          }
        },
        IncompleteJsonException);
  }

  TEST_F(IncompleteJsonExceptionTest, constructor_dedicated_message)
  {
    EXPECT_THROW(
        {
          try
          {
            throw IncompleteJsonException{R"(incomplete: {"name":"})"};
          }
          catch (const IncompleteJsonException &_exception)
          {
            ::std::string message = _exception.what();
            EXPECT_STREQ(R"(IncompleteJsonException thrown - incomplete: {"name":"})", message.c_str());
            throw;
          }
        },
        IncompleteJsonException);
  }
}
