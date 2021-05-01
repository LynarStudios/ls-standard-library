/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-14
 * Changed:         2021-04-23
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>
#include <TestHelper.hpp>

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

  TEST_F(StringTest, operatorAssignment)
  {
    ls_std::String text{};
    text = "Hi!";

    ASSERT_STREQ("Hi!", text.toString().c_str());
  }

  // arithmetic operators

  TEST_F(StringTest, operatorAdd)
  {
    ls_std::String text{"Hello! "};
    ls_std::String end{"How are you? "};
    text = text + end + "I'm good by the way!";

    ASSERT_STREQ("Hello! How are you? I'm good by the way!", text.toString().c_str());
  }

  TEST_F(StringTest, operatorHyphen)
  {
    ls_std::String text{"abcdefghij"};
    text = text - 5;

    ASSERT_STREQ("abcde", text.toString().c_str());
  }

  // compound operators

  TEST_F(StringTest, operatorAddEqual)
  {
    ls_std::String text{};
    ls_std::String hello{"Hi! "};
    ASSERT_STREQ("", text.toString().c_str());

    text += hello;
    ASSERT_STREQ("Hi! ", text.toString().c_str());

    text += "Bye!";
    ASSERT_STREQ("Hi! Bye!", text.toString().c_str());
  }

  // comparison operators

  TEST_F(StringTest, operatorEqual)
  {
    ls_std::String text{"Hi!"};
    ls_std::String hello{"Hi!"};

    ASSERT_TRUE(text == hello);
    ASSERT_TRUE(hello == text);
    ASSERT_TRUE(hello == std::string("Hi!"));
    ASSERT_TRUE(hello == "Hi!");
  }

  TEST_F(StringTest, operatorNotEqual)
  {
    ls_std::String text{"Hi!"};
    ls_std::String hello{"Hello!"};

    ASSERT_TRUE(text != hello);
    ASSERT_TRUE(hello != text);
    ASSERT_TRUE(text != std::string("Hello!"));
    ASSERT_TRUE(text != "Hello!");
  }

  // implementation

  TEST_F(StringTest, load)
  {
    // preparation

    std::shared_ptr<ls_std::String> x = std::make_shared<ls_std::String>();
    std::string path = TestHelper::getResourcesFolderLocation() + "tmp_storable_string.json";
    ls_std::File file{path};
    file.createNewFile();
    ls_std::FileWriter writer{file};
    writer.write(R"({"value":"Hello!"})");

    auto serializable = std::make_shared<ls_std::SerializableJSONString>(x);
    x->setSerializable(std::dynamic_pointer_cast<ls_std::ISerializable>(serializable));

    auto storable = std::make_shared<ls_std::StorableFile>(path);
    x->setStorable(std::dynamic_pointer_cast<ls_std::IStorable>(storable));

    // check

    x->load();
    ASSERT_STREQ("Hello!", *x);

    file.remove();
  }

  TEST_F(StringTest, marshal)
  {
    std::shared_ptr<ls_std::String> x = std::make_shared<ls_std::String>("Hello!");

    auto serializable = std::make_shared<ls_std::SerializableJSONString>(x);
    x->setSerializable(std::dynamic_pointer_cast<ls_std::ISerializable>(serializable));

    ASSERT_STREQ(R"({"value":"Hello!"})", x->marshal().c_str());

    *x = "Test!";
    ASSERT_STREQ(R"({"value":"Test!"})", x->marshal().c_str());
  }

  TEST_F(StringTest, parse)
  {
    ls_std::String text{};
    text.parse("Hello!");

    ASSERT_STREQ("Hello!", text.toString().c_str());
  }

  TEST_F(StringTest, toString)
  {
    ls_std::String text{"Hello!"};

    ASSERT_STREQ("Hello!", text.toString().c_str());
  }

  TEST_F(StringTest, unmarshal)
  {
    std::shared_ptr<ls_std::String> x = std::make_shared<ls_std::String>("Hello!");
    ASSERT_STREQ("Hello!", *x);

    auto serializable = std::make_shared<ls_std::SerializableJSONString>(x);
    x->setSerializable(std::dynamic_pointer_cast<ls_std::ISerializable>(serializable));

    x->unmarshal(R"({"value":"Test!"})");

    ASSERT_STREQ("Test!", *x);
  }

  // additional functionality

  TEST_F(StringTest, contains)
  {
    ls_std::String text{};
    text = "Hey, I'm searching for the keyword 'cake'!";

    ASSERT_TRUE(text.contains("cake"));
  }

  TEST_F(StringTest, containsNegative)
  {
    ls_std::String text{};
    text = "Hey, I'm searching for the keyword 'cake'!";

    ASSERT_FALSE(text.contains("butter"));
  }

  TEST_F(StringTest, endsWith)
  {
    ls_std::String text{};
    text = "abcdef";

    ASSERT_TRUE(text.endsWith("ef"));
  }

  TEST_F(StringTest, endsWithNegative)
  {
    ls_std::String text{};
    text = "abcdef";

    ASSERT_FALSE(text.endsWith("efg"));
  }

  TEST_F(StringTest, equalsIgnoreCase)
  {
    ls_std::String text{"Hello!"};
    ls_std::String hello{"HeLLo!"};

    ASSERT_TRUE(text.equalsIgnoreCase(hello));
    ASSERT_TRUE(text.equalsIgnoreCase("HeLLO!"));
  }

  TEST_F(StringTest, getByteData)
  {
    ls_std::String text{"Hallo!"};
    ASSERT_STREQ("Hallo!", text.getByteData().data());
  }

  TEST_F(StringTest, padLeft)
  {
    ls_std::String text{"abcdef"};
    ls_std::String anotherText{"ab"};
    ls_std::String emptyText{};
    ls_std::String longText{"This text is too long to fill!"};

    ASSERT_STREQ("    abcdef", text.padLeft(10, ' ').c_str());
    ASSERT_STREQ("        ab", anotherText.padLeft(10, ' ').c_str());
    ASSERT_STREQ("          ", emptyText.padLeft(10, ' ').c_str());
    ASSERT_STREQ("This text is too long to fill!", longText.padLeft(10, ' ').c_str());
  }

  TEST_F(StringTest, padRight)
  {
    ls_std::String text{"abcdef"};
    ls_std::String anotherText{"ab"};
    ls_std::String emptyText{};
    ls_std::String longText{"This text is too long to fill!"};

    ASSERT_STREQ("abcdef    ", text.padRight(10, ' ').c_str());
    ASSERT_STREQ("ab        ", anotherText.padRight(10, ' ').c_str());
    ASSERT_STREQ("          ", emptyText.padRight(10, ' ').c_str());
    ASSERT_STREQ("This text is too long to fill!", longText.padRight(10, ' ').c_str());
  }

  TEST_F(StringTest, reverse)
  {
    ls_std::String text{};
    text = "abcdef";

    ASSERT_STREQ("fedcba", text.reverse().c_str());
    ASSERT_STREQ("abcdef", text);
  }

  TEST_F(StringTest, startsWith)
  {
    ls_std::String text{};
    text = "abcdef";

    ASSERT_TRUE(text.startsWith("abc"));
  }

  TEST_F(StringTest, startsWithNegative)
  {
    ls_std::String text{};
    text = "abcdef";

    ASSERT_FALSE(text.startsWith("bc"));
  }

  TEST_F(StringTest, toLowerCase)
  {
    ls_std::String text{};
    text = "aBCdeFgHIJKLmn";

    ASSERT_STREQ("abcdefghijklmn", text.toLowerCase().c_str());
    ASSERT_STREQ("aBCdeFgHIJKLmn", text);
  }

  TEST_F(StringTest, toUpperCase)
  {
    ls_std::String text{};
    text = "aBCdeFgHIJKLmn";

    ASSERT_STREQ("ABCDEFGHIJKLMN", text.toUpperCase().c_str());
    ASSERT_STREQ("aBCdeFgHIJKLmn", text);
  }
}
