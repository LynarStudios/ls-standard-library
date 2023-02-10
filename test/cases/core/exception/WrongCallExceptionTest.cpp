/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-10
* Changed:         2023-02-10
*
* */

#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>
#include <string>

using namespace ls::std::core;

namespace
{
 class WrongCallExceptionTest : public ::testing::Test
 {
   protected:

     WrongCallExceptionTest() = default;
     ~WrongCallExceptionTest() override = default;

     void SetUp() override
     {}

     void TearDown() override
     {}
 };

 TEST_F(WrongCallExceptionTest, constructor)
 {
   EXPECT_THROW(
       {
         try
         {
           throw WrongCallException{};
         }
         catch (const WrongCallException &_exception)
         {
           ::std::string message = _exception.what();
           EXPECT_STREQ("WrongCallException thrown - this function / method call is invalid!", message.c_str());
           throw;
         }
       },
       WrongCallException);
 }

 TEST_F(WrongCallExceptionTest, constructor_dedicated_message)
 {
   EXPECT_THROW(
       {
         try
         {
           throw WrongCallException{"method \"getValue()\" was called, although this is forbidden!"};
         }
         catch (const WrongCallException &_exception)
         {
           ::std::string message = _exception.what();
           EXPECT_STREQ("WrongCallException thrown - method \"getValue()\" was called, although this is forbidden!", message.c_str());
           throw;
         }
       },
       WrongCallException);
 }
}
