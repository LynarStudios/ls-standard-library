/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-04-07
* Changed:         2023-04-10
*
* */

#include <gtest/gtest.h>
#include <ls-std/ls-std-core-jni.hpp>
#include <ls-std/ls-std-core.hpp>
#include <string>

using ls::std::core::IllegalArgumentException;
using ls::std::core::experimental::JniApi;
using std::string;
using testing::Test;

namespace
{
  class JniApiTest : public Test
  {
    public:

      JniApiTest() = default;
      ~JniApiTest() override = default;
  };

  TEST_F(JniApiTest, constructor)
  {
    EXPECT_THROW(
        {
          try
          {
            JniApi jniApi{nullptr};
          }
          catch (const IllegalArgumentException &_exception)
          {

            string expected = _exception.getName() + " thrown - Java environment is not being provided!";
            string actual = _exception.what();

            ASSERT_STREQ(expected.c_str(), actual.c_str());
            throw;
          }
        },
        IllegalArgumentException);
  }
}
