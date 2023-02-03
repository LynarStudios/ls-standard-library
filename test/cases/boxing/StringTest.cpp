/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-14
 * Changed:         2023-02-03
 *
 * */

#include <gtest/gtest.h>
#include <ls-std/ls-std-boxing.hpp>

using namespace ls::std::boxing;
using namespace ::std;

namespace
{
  class StringTest : public ::testing::Test
  {
    protected:

      StringTest() = default;
      ~StringTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  // assignment operators

  TEST_F(StringTest, operator_assignment)
  {
    String text{};
    text = "Hi!";

    ASSERT_STREQ("Hi!", text.toString().c_str());
  }

  // arithmetic operators

  TEST_F(StringTest, operator_add)
  {
    String greetings{"Hello! "};
    String question{"How are you? "};
    const string& answer = "I'm good by the way!";

    greetings = greetings + question + answer;

    ASSERT_STREQ("Hello! How are you? I'm good by the way!", greetings.toString().c_str());
  }

  TEST_F(StringTest, operator_minus)
  {
    String text{"abcdefghij"};
    text = text - 5;

    ASSERT_STREQ("abcde", text.toString().c_str());
  }

  // compound operators

  TEST_F(StringTest, operator_add_assign_with_reference)
  {
    String text{};
    String hello{"Hi!"};

    text += hello;
    ASSERT_STREQ("Hi!", text.toString().c_str());
  }

  TEST_F(StringTest, operator_add_assign_with_value)
  {
    String text{};

    text += "Hi!";
    ASSERT_STREQ("Hi!", text.toString().c_str());
  }

  // comparison operators

  TEST_F(StringTest, operator_equals_with_reference)
  {
    String text{"Hi!"};
    String hello{"Hi!"};

    ASSERT_TRUE(text == hello);
    ASSERT_TRUE(hello == text);
  }

  TEST_F(StringTest, operator_equals_with_value)
  {
    String hello{"Hi!"};
    ASSERT_TRUE(hello == "Hi!");
  }

  TEST_F(StringTest, operator_not_equals_with_reference)
  {
    String text{"Hi!"};
    String hello{"Hello!"};

    ASSERT_TRUE(text != hello);
  }

  TEST_F(StringTest, operator_not_equals_with_value)
  {
    String text{"Hi!"};
    ASSERT_TRUE(text != "Hello!");
  }

  // implementation

  TEST_F(StringTest, parse)
  {
    String text{};
    text.parse("Hello!");

    ASSERT_STREQ("Hello!", text.toString().c_str());
  }

  TEST_F(StringTest, toString)
  {
    String text{"Hello!"};
    ASSERT_STREQ("Hello!", text.toString().c_str());
  }

  // additional functionality

  TEST_F(StringTest, contains)
  {
    String text{};
    text = "Hey, I'm searching for the keyword 'cake'!";

    ASSERT_TRUE(text.contains("cake"));
  }

  TEST_F(StringTest, contains_does_not_contain_search_word)
  {
    String text{};
    text = "Hey, I'm searching for the keyword 'cake'!";

    ASSERT_FALSE(text.contains("butter"));
  }

  TEST_F(StringTest, endsWith)
  {
    String text{};
    text = "abcdef";

    ASSERT_TRUE(text.endsWith("ef"));
  }

  TEST_F(StringTest, endsWith_does_not_end_with_pattern)
  {
    String text{};
    text = "abcdef";

    ASSERT_FALSE(text.endsWith("efg"));
  }

  TEST_F(StringTest, equalsIgnoreCase)
  {
    String text{"Hello!"};
    String hello{"HeLLo!"};

    ASSERT_TRUE(text.equalsIgnoreCase(hello));
    ASSERT_TRUE(text.equalsIgnoreCase("HeLLO!"));
  }

  TEST_F(StringTest, getByteData)
  {
    String text{"Hallo!"};
    ASSERT_STREQ("Hallo!", text.getByteData().data());
  }

  TEST_F(StringTest, padLeft)
  {
    String text{"abcdef"};
    String anotherText{"ab"};
    String emptyText{};
    String longText{"This text is too long to fill!"};

    ASSERT_STREQ("    abcdef", text.padLeft(10, ' ').c_str());
    ASSERT_STREQ("        ab", anotherText.padLeft(10, ' ').c_str());
    ASSERT_STREQ("          ", emptyText.padLeft(10, ' ').c_str());
    ASSERT_STREQ("This text is too long to fill!", longText.padLeft(10, ' ').c_str());
  }

  TEST_F(StringTest, padRight)
  {
    String text{"abcdef"};
    String anotherText{"ab"};
    String emptyText{};
    String longText{"This text is too long to fill!"};

    ASSERT_STREQ("abcdef    ", text.padRight(10, ' ').c_str());
    ASSERT_STREQ("ab        ", anotherText.padRight(10, ' ').c_str());
    ASSERT_STREQ("          ", emptyText.padRight(10, ' ').c_str());
    ASSERT_STREQ("This text is too long to fill!", longText.padRight(10, ' ').c_str());
  }

  TEST_F(StringTest, reverse)
  {
    String text{};
    text = "abcdef";

    ASSERT_STREQ("fedcba", text.reverse().c_str());
    ASSERT_STREQ("abcdef", text); // verify, that original string didn't change
  }

  TEST_F(StringTest, startsWith)
  {
    String text{};
    text = "abcdef";

    ASSERT_TRUE(text.startsWith("abc"));
  }

  TEST_F(StringTest, startsWith_does_not_start_with_pattern)
  {
    String text{};
    text = "abcdef";

    ASSERT_FALSE(text.startsWith("bc"));
  }

  TEST_F(StringTest, toLowerCase)
  {
    String text{};
    text = "aBCdeFgHIJKLmn";

    ASSERT_STREQ("abcdefghijklmn", text.toLowerCase().c_str());
    ASSERT_STREQ("aBCdeFgHIJKLmn", text); // verify, that original String didn't change
  }

  TEST_F(StringTest, toUpperCase)
  {
    String text{};
    text = "aBCdeFgHIJKLmn";

    ASSERT_STREQ("ABCDEFGHIJKLMN", text.toUpperCase().c_str());
    ASSERT_STREQ("aBCdeFgHIJKLmn", text); // verify, that original String didn't change
  }
}
