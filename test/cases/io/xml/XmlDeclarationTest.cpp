/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-29
 * Changed:         2021-07-16
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>

namespace
{
  class XmlDeclarationTest : public ::testing::Test
  {
    protected:

      XmlDeclarationTest() = default;
      ~XmlDeclarationTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(XmlDeclarationTest, constructor_empty_version)
  {
    EXPECT_THROW({
                   try
                   {
                     ls_std::XmlDeclaration declaration{""};
                   }
                   catch (const ls_std::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls_std::IllegalArgumentException);
  }

  TEST_F(XmlDeclarationTest, getEncoding)
  {
    ls_std::XmlDeclaration declaration{"1.0"};
    ASSERT_TRUE(declaration.getEncoding().empty());
  }

  TEST_F(XmlDeclarationTest, getStandalone)
  {
    ls_std::XmlDeclaration declaration{"1.0"};
    ASSERT_TRUE(declaration.getStandalone().empty());
  }

  TEST_F(XmlDeclarationTest, getVersion)
  {
    ls_std::XmlDeclaration declaration{"1.0"};
    ASSERT_STREQ("1.0", declaration.getVersion().c_str());
  }

  TEST_F(XmlDeclarationTest, setEncoding)
  {
    ls_std::XmlDeclaration declaration{"1.0"};

    ASSERT_TRUE(declaration.getEncoding().empty());

    declaration.setEncoding("iso-8859-1");
    ASSERT_STREQ("iso-8859-1", declaration.getEncoding().c_str());
  }

  TEST_F(XmlDeclarationTest, setEncoding_empty_encoding)
  {
    ls_std::XmlDeclaration declaration{"1.0"};

    EXPECT_THROW({
                   try
                   {
                     declaration.setEncoding("");
                   }
                   catch (const ls_std::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls_std::IllegalArgumentException);
  }

  TEST_F(XmlDeclarationTest, setStandalone)
  {
    ls_std::XmlDeclaration declaration{"1.0"};

    ASSERT_TRUE(declaration.getStandalone().empty());

    declaration.setStandalone("no");
    ASSERT_STREQ("no", declaration.getStandalone().c_str());
  }

  TEST_F(XmlDeclarationTest, setStandalone_empty_standalone)
  {
    ls_std::XmlDeclaration declaration{"1.0"};

    EXPECT_THROW({
                   try
                   {
                     declaration.setStandalone("");
                   }
                   catch (const ls_std::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls_std::IllegalArgumentException);
  }

  TEST_F(XmlDeclarationTest, setVersion)
  {
    ls_std::XmlDeclaration declaration{"1.0"};

    ASSERT_FALSE(declaration.getVersion().empty());
    ASSERT_STREQ("1.0", declaration.getVersion().c_str());

    declaration.setVersion("1.1");
    ASSERT_STREQ("1.1", declaration.getVersion().c_str());
  }

  TEST_F(XmlDeclarationTest, setVersion_empty_version)
  {
    ls_std::XmlDeclaration declaration{"1.0"};

    EXPECT_THROW({
                   try
                   {
                     declaration.setVersion("");
                   }
                   catch (const ls_std::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls_std::IllegalArgumentException);
  }

  TEST_F(XmlDeclarationTest, toXml)
  {
    ls_std::XmlDeclaration declaration{"1.0"};
    ASSERT_STREQ(R"(<?xml version="1.0" ?>)", declaration.toXml().c_str());

    declaration.setStandalone("yes");
    ASSERT_STREQ(R"(<?xml version="1.0" standalone="yes" ?>)", declaration.toXml().c_str());

    declaration.setEncoding("UTF-8");
    ASSERT_STREQ(R"(<?xml version="1.0" encoding="UTF-8" standalone="yes" ?>)", declaration.toXml().c_str());
  }
}
